RPIFW_DATE ?= "20210527"
SRCREV ?= "1eb8921ae7158249894f89e8bb6c4bfb04ec7377"
RPIFW_SRC_URI ?= "https://media.githubusercontent.com/media/jason-go/RDK-V-meta-gx/master/${SRCREV}.tar.gz;downloadfilename=gx-firmware-${SRCREV}.tar.gz"
RPIFW_S ?= "${WORKDIR}/firmware-${SRCREV}"

SRC_URI = "${RPIFW_SRC_URI}"
SRC_URI[sha256sum] = "a7768538343701530b891b4acc6a2cde506754c1216589e59a435d1924f2f234"

PV = "${RPIFW_DATE}"
