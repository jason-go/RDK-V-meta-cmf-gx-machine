DESCRIPTION = "This repository contains the source code for the ARM side \
libraries used on Raspberry Pi. These typically are installed in /opt/vc/lib \
and includes source for the ARM side code to interface to: EGL, mmal, GLESv2,\
vcos, openmaxil, vchiq_arm, bcm_host, WFC, OpenVG."
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://LICENCE;md5=0448d6488ef8cc380632b1569ee6d196"

PROVIDES += "${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "", "virtual/libgles2 virtual/egl", d)}"
PROVIDES += "virtual/libomxil"

RPROVIDES_${PN} += "${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "", "libgles2 egl libegl libegl1 libglesv2-2", d)}"
COMPATIBLE_MACHINE = "^rpi$"

SRCREV = "c923553204d20e44a50a5645d4cec2858256ff0b"

# Use the date of the above commit as the package version. Update this when
# SRCREV is changed.
PV = "20200624"

SRC_URI = "git://github.com/jason-go/RDK-V-userland.git;protocol=https;branch=master"

S = "${WORKDIR}/git"
SRC_URI[sha256sum] = "21f6ed8ce952d01856df411da47f46a2f99b3cc3896233fc74d5eb0b97a6b232"

inherit cmake pkgconfig

ASNEEDED = ""

EXTRA_OECMAKE = "-DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS='-Wl,--no-as-needed' \
                 -DVMCS_INSTALL_PREFIX=${exec_prefix} \
"

EXTRA_OECMAKE_append_aarch64 = " -DARM64=ON "


PACKAGECONFIG ?= "${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'wayland', '', d)}"

PACKAGECONFIG[wayland] = "-DBUILD_WAYLAND=TRUE -DWAYLAND_SCANNER_EXECUTABLE:FILEPATH=${STAGING_BINDIR_NATIVE}/wayland-scanner,,wayland-native wayland"

CFLAGS_append = " -fPIC"

do_install_append () {
	for f in `find ${D}${includedir}/interface/vcos/ -name "*.h"`; do
		sed -i 's/include "vcos_platform.h"/include "pthreads\/vcos_platform.h"/g' ${f}
		sed -i 's/include "vcos_futex_mutex.h"/include "pthreads\/vcos_futex_mutex.h"/g' ${f}
		sed -i 's/include "vcos_platform_types.h"/include "pthreads\/vcos_platform_types.h"/g' ${f}
	done
        rm -rf ${D}${prefix}${sysconfdir}
	if [ "${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "1", "0", d)}" = "1" ]; then
		rm -rf ${D}${libdir}/libEGL*
		rm -rf ${D}${libdir}/libGLES*
		rm -rf ${D}${libdir}/libwayland-*
		rm -rf ${D}${libdir}/pkgconfig/egl.pc ${D}${libdir}/pkgconfig/glesv2.pc \
			${D}${libdir}/pkgconfig/wayland-egl.pc
		rm -rf ${D}${includedir}/EGL ${D}${includedir}/GLES* ${D}${includedir}/KHR
        else
                ln -sf brcmglesv2.pc ${D}${libdir}/pkgconfig/glesv2.pc
                ln -sf brcmegl.pc ${D}${libdir}/pkgconfig/egl.pc
                ln -sf brcmvg.pc ${D}${libdir}/pkgconfig/vg.pc
	fi
}

# Shared libs from userland package  build aren't versioned, so we need
# to force the .so files into the runtime package (and keep them
# out of -dev package).
FILES_SOLIBSDEV = ""
INSANE_SKIP_${PN} += "dev-so"

FILES_${PN} += " \
    ${libdir}/*.so \
    ${libdir}/plugins"
FILES_${PN}-dev += "${includedir} \
                   ${prefix}/src"
FILES_${PN}-doc += "${datadir}/install"
FILES_${PN}-dbg += "${libdir}/plugins/.debug"

RDEPENDS_${PN} += "bash"
RDEPENDS_${PN} += "${@bb.utils.contains("MACHINE_FEATURES", "vc4graphics", "libegl-mesa", "", d)}"
