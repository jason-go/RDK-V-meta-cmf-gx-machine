# Base this image on core-image-minimal
include recipes-core/images/core-image-minimal.bb

# Include modules in rootfs
IMAGE_INSTALL += " \
	kernel-modules \
	"

SPLASH = "psplash-gx"

IMAGE_FEATURES += "ssh-server-dropbear splash"

do_image_prepend() {
    bb.warn("The image 'rpi-basic-image' is deprecated, please use 'core-image-base' instead")
}
