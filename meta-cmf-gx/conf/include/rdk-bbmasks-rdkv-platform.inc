BBMASK .= "|meta-rdk/recipes-common/rdk-oss-ssa/"
BBMASK .= "|meta-rdk/recipes-support/base64"

BBMASK .= "|openembedded-core/meta/recipes-multimedia/gstreamer/gstreamer1.0-plugins-ugly_1.8.3.bb"
BBMASK_append_morty .= "|meta-gx/recipes-multimedia/gstreamer/gstreamer1.0-omx*"

BBMASK .= "|meta-cmf-gx/recipes-extended/rms/"
BBMASK .= "|meta-cmf-gx/recipes-extended/tdkb/"
BBMASK .= "|meta-cmf-gx/recipes-extended/tdkc/"
BBMASK .= "|meta-cmf-gx/recipes-multimedia/cvr/"
BBMASK .= "|meta-cmf-gx/recipes-multimedia/mediastreamer/"

# this bbappend holds old revision and checksum values which is not applicable for dunfell builds
# as meta-gx has the latest revision and it's checksum values
BBMASK_append_dunfell = "|meta-cmf-gx/recipes-bsp/bootfiles/bcm2835-bootfiles.bbappend"
BBMASK_append_morty .= "|meta-cmf-gx/recipes-bsp/u-boot/"
