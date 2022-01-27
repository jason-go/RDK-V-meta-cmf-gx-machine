#RDEPENDS_packagegroup-rdk-generic-mediaclient += "virtual/wifi-hal"

RDEPENDS_packagegroup-rdk-generic-mediaclient_remove = "rdkbrowser"
RDEPENDS_packagegroup-rdk-generic-mediaclient_remove = "rdkbrowser-webserver"

RDEPENDS_packagegroup-rdk-generic-mediaclient_remove = "${@bb.utils.contains('DISTRO_FEATURES', 'ipclient', 'tr69agent', '', d)}"
