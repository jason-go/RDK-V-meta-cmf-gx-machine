RPITOOLS_DATE ?= "20200803"
SRCREV ?= "0c39cb5b5ac9851312a38c54f5aea770d976de7a"
RPITOOLS_SRC_URI ?= "https://media.githubusercontent.com/media/jason-go/RDK-V-meta-gx/master/${SRCREV}.tar.gz;downloadfilename=gx-tools-${SRCREV}.tar.gz"
RPITOOLS_S ?= "${WORKDIR}/tools-${SRCREV}"

SRC_URI = "${RPITOOLS_SRC_URI}"
SRC_URI[sha256sum] = "32922a61b8dd2ba5ca3b5cf9d0f5daf723e2915eb481adc547c7fb76052ecfc5"

PV = "${RPITOOLS_DATE}"
