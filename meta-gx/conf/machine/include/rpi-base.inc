include conf/machine/include/rpi-default-settings.inc
include conf/machine/include/rpi-default-versions.inc
include conf/machine/include/rpi-default-providers.inc

SOC_FAMILY = "rpi"
include conf/machine/include/soc-family.inc

IMAGE_FSTYPES ?= "tar.bz2 ext3 wic.bz2 wic.bmap"
WKS_FILE ?= "sdimage-gx.wks"

XSERVER = " \
    xserver-xorg \
    ${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "xserver-xorg-extension-glx", "", d)} \
    ${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "xf86-video-modesetting", "xf86-video-fbdev", d)} \
    "

RPI_KERNEL_DEVICETREE ?= " \
    sirius_generic.dtb \
    "

KERNEL_DEVICETREE ?= " \
    ${RPI_KERNEL_DEVICETREE} \
    "

# By default:
#
# * When u-boot is disabled use the "Image" format which can be directly loaded
#   by the rpi firmware.
#
# * When u-boot is enabled use the "uImage" format and the "bootm" command
#   within u-boot to load the kernel.
KERNEL_BOOTCMD ??= "bootm"
KERNEL_IMAGETYPE_UBOOT ??= "uImage"
KERNEL_IMAGETYPE_DIRECT ??= "zImage"
KERNEL_IMAGETYPE ?= "${@bb.utils.contains('RPI_USE_U_BOOT', '1', \
        '${KERNEL_IMAGETYPE_UBOOT}', '${KERNEL_IMAGETYPE_DIRECT}', d)}"

MACHINE_FEATURES += "apm usbhost keyboard vfat ext2 screen touchscreen alsa bluetooth wifi sdio ${@bb.utils.contains('DISABLE_VC4GRAPHICS', '1', '', 'vc4graphics', d)}"

# Raspberry Pi has no hardware clock
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

MACHINE_EXTRA_RRECOMMENDS += "kernel-modules udev-rules-rpi"
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "${@oe.utils.conditional('ENABLE_I2C', '1', 'kernel-module-i2c-dev kernel-module-i2c-bcm2708', '', d)}"
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "${@oe.utils.conditional('ENABLE_IR', '1', 'kernel-module-gpio-ir kernel-module-gpio-ir-tx', '', d)}"

SERIAL_CONSOLES_CHECK ??= "${SERIAL_CONSOLES}"

# The name of the deploy directory for raspberry pi boot files.
# This variable is referred to by recipes fetching / generating the files.
BOOTFILES_DIR_NAME ?= "bootfiles"

# Set Raspberrypi splash image
SPLASH = "psplash-gx"

def make_dtb_boot_files(d):
    # Generate IMAGE_BOOT_FILES entries for device tree files listed in
    # KERNEL_DEVICETREE.
    alldtbs = d.getVar('KERNEL_DEVICETREE')
    imgtyp = d.getVar('KERNEL_IMAGETYPE')

    def transform(dtb):
        base = os.path.basename(dtb)
        if dtb.endswith('dtb'):
            # eg: whatever/bcm2708-rpi-b.dtb has:
            #     DEPLOYDIR file: bcm2708-rpi-b.dtb
            #     destination: bcm2708-rpi-b.dtb
            return base
        elif dtb.endswith('dtbo'):
            # overlay dtb:
            # eg: overlays/hifiberry-amp.dtbo has:
            #     DEPLOYDIR file: hifiberry-amp.dtbo
            #     destination: overlays/hifiberry-amp.dtbo
            return '{};{}'.format(base, dtb)

    return ' '.join([transform(dtb) for dtb in alldtbs.split(' ') if dtb])


IMAGE_BOOT_FILES ?= "${BOOTFILES_DIR_NAME}/* \
                 ${@make_dtb_boot_files(d)} \
                 ${@bb.utils.contains('RPI_USE_U_BOOT', '1', \
                    '${KERNEL_IMAGETYPE} u-boot.bin;${SDIMG_KERNELIMAGE} boot.scr', \
                    '${KERNEL_IMAGETYPE};${SDIMG_KERNELIMAGE}', d)} \
                 "
do_image_wic[depends] += " \
    bootfiles:do_deploy \
    ${@bb.utils.contains('RPI_USE_U_BOOT', '1', 'u-boot:do_deploy', '',d)} \
    "

do_image_wic[recrdeps] = "do_build"

# The kernel image is installed into the FAT32 boot partition and does not need
# to also be installed into the rootfs.
RDEPENDS_${KERNEL_PACKAGE_NAME}-base = ""
