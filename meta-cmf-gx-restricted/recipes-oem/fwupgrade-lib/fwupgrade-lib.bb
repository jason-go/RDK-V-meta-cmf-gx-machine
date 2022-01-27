SUMMARY = "create fwupgrade-lib library"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=19a2b3c39737289f92c7991b16599360" 

CFLAGS_prepend += " -I${PKG_CONFIG_SYSROOT_DIR}${includedir}/rdk/mfrlib "

RDEPENDS_${PN} = "bash"

SRC_URI = "git://github.com/jason-go/RDK-V-fwupgrade-lib;protocol=https;branch=master"
SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git"

inherit pkgconfig cmake coverity

do_install() {
   install -d ${D}${includedir}/rdk/mfrlib/
   install -m 644 ${S}/mfr-utility/*.h ${D}${includedir}/rdk/mfrlib/

   install -d ${D}${base_libdir}/rdk
   install -m 0755 ${S}/mfr-utility/write_kernel_rootfs.sh ${D}${base_libdir}/rdk
   install -m 0755 ${S}/mfr-utility/memory_partition.sh ${D}${base_libdir}/rdk

   install -d ${D}${libdir}
   install -m 755 ${B}/fwupgrade-lib/libfwupgrade-lib.so.1 ${D}${libdir}
   ln -s libfwupgrade-lib.so.1 ${D}${libdir}/libfwupgrade.so
   install -D -m 0644 ${S}/fwupgrade-lib/fwupgrade.pc  ${D}${libdir}/pkgconfig/fwupgrade.pc
}

FILES_${PN} += "${libdir}/libfwupgrade.so"
FILES_${PN} += "${libdir}/pkgconfig/fwupgrade.pc"
FILES_${PN} += "${base_libdir}/rdk/*"

PROVIDES = "virtual/mfrfwlib"
RPROVIDES_${PN} = "virtual/mfrfwlib"
