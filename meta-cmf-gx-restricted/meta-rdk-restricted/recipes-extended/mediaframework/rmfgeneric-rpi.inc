# ============================================================================
# RDK MANAGEMENT, LLC CONFIDENTIAL AND PROPRIETARY
# ============================================================================
# This file (and its contents) are the intellectual property of RDK Management, LLC.
# It may not be used, copied, distributed or otherwise disclosed in whole or in
# part without the express written permission of RDK Management, LLC.
# ============================================================================
# Copyright (c) 2016 RDK Management, LLC. All rights reserved.
# ============================================================================

EXTRA_OECONF += "--disable-xfs"

EXTRA_OECONF_remove_hybrid = "--enable-ippvsource"
EXTRA_OECONF_remove_hybrid = "--enable-vodsource"
EXTRA_OECONF_remove_hybrid = "--enable-diagnostics"

PACKAGECONFIG[qam] = "--enable-emulator-qam,,virtual/sectionfilter-hal"

PACKAGECONFIG_append_hybrid = " qam"
PACKAGECONFIG_remove_hybrid = "podmgr"

PACKAGECONFIG ??= ""
