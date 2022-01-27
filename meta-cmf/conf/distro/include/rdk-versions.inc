#
# root location of Generic RDK components
RDK_GENERIC_ROOT_SVN ?= "svn5.teamccp.com/svn/rdk/components/generic"
RDK_GIT ?= "gerrit.teamccp.com"
RDK_GIT_PROTOCOL ?= "https"
RDK_RELEASE ?= "rdkv-2021q4-dunfell"
RDK_GENERIC_ROOT_GIT ?= "git://${RDK_GIT}/rdk/components/generic"
RDK_COMPONENTS_ROOT_GIT ?= "git://${RDK_GIT}/rdk/components"
RDKB_COMPONENTS_ROOT_GIT ?= "git://${RDK_GIT}/rdk/rdkb/components"
RDKB_CCSP_ROOT_GIT ?= "git://${RDK_GIT}/rdk/rdkb/components/opensource/ccsp"
RDK_GIT_BRANCH ?= "rdkv-2021q4-dunfell"
CCSP_GIT_BRANCH ?= "rdkv-2021q4-dunfell"
PROJECT_BRANCH ?= "default"

CMF_GIT_ROOT ?= "git://code.rdkcentral.com/r"
CMF_GITHUB_ROOT ?= "git://github.com/rdkcentral"
CMF_GIT_PROTOCOL ?= "https"
CMF_RDK_COMPONENTS_ROOT_GIT ?= "${CMF_GIT_ROOT}/rdk/components"
CMF_RDKB_COMPONENTS_ROOT_GIT ?= "${CMF_GIT_ROOT}/rdkb/components"
CMF_RDKB_CCSP_ROOT_GIT ?= "${CMF_RDKB_COMPONENTS_ROOT_GIT}/opensource/ccsp"

CMF_GIT_BRANCH ?= "rdkv-2021q4-dunfell"
CMF_GIT_MASTER_BRANCH ?= "rdkv-2021q4-dunfell"
CMF_GITHUB_MAIN_BRANCH ?= "rdkv-2021q4-dunfell"
CMF_GITHUB_MASTER_BRANCH ?= "rdkv-2021q4-dunfell"
PROJECT_BRANCH = "${@d.getVar("CMF_GIT_BRANCH").replace('/','-')}"
RELEASE_VERSION = "${@time.strftime("4.%m.%d.%y",time.gmtime())}"