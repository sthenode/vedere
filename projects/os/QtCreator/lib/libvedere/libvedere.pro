########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: libvedere.pro
#
# Author: $author$
#   Date: 5/30/2018
#
# QtCreator .pro file for vedere library libvedere
########################################################################
include(../../../../../build/QtCreator/vedere.pri)
include(../../../../QtCreator/vedere.pri)
include(../../vedere.pri)
include(../../../../QtCreator/lib/libvedere/libvedere.pri)

TARGET = $${libvedere_TARGET}
TEMPLATE = $${libvedere_TEMPLATE}
CONFIG += $${libvedere_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libvedere_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libvedere_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libvedere_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
SOURCES += \
$${libvedere_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libvedere_HEADERS} \

# SOURCES
#
SOURCES += \
$${libvedere_SOURCES} \
$${OBJECTIVE_SOURCES} \

########################################################################


