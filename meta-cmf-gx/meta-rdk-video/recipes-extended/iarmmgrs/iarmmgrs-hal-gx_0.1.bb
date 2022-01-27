DESCRIPTION = "iarmmgrs-hal ir: irmgr-hal impelmented ; pwrmgr-hal Emulation"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=b1e01b26bacfc2232046c90a330332b3"

PROVIDES = "virtual/iarmmgrs-hal"

SRCREV = "${AUTOREV}"
SRC_URI = "git://github.com/jason-go/RDK-V-iarmmgrs;protocol=https;branch=master"

S = "${WORKDIR}/git"

DEPENDS="iarmmgrs-hal-headers"

inherit autotools coverity

EXTRA_OECONF += "--enable-dsleep"

