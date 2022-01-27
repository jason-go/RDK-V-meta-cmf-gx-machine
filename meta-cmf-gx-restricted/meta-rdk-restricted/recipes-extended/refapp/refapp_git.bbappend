FILESEXTRAPATHS_prepend := "${THISDIR}/files:"


SRC_URI_append = " \
 file://xfinity-remote-support-in-refapp.patch \
 file://rdk-browser2-support.patch \
 "
