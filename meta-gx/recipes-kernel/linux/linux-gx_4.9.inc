FILESEXTRAPATHS_prepend := "${THISDIR}/linux-gx:"

KMETA = "kernel-meta"

SRC_URI = " \
    git://github.com/jason-go/RDK-V-linux-4.9.y.git;branch=main \
    git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=${LINUX_RPI_KMETA_BRANCH};destsuffix=${KMETA} \
    "
SRC_URI_remove = "file://rpi-kernel-misc.cfg"

require linux-gx.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"
