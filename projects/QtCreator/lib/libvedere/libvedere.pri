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
#   File: libvedere.pri
#
# Author: $author$
#   Date: 5/30/2018
#
# QtCreator .pri file for vedere library libvedere
########################################################################

########################################################################
# libvedere

# libvedere TARGET
#
libvedere_TARGET = vedere
libvedere_TEMPLATE = lib
libvedere_CONFIG += staticlib

# libvedere INCLUDEPATH
#
libvedere_INCLUDEPATH += \
$${vedere_INCLUDEPATH} \

# libvedere DEFINES
#
libvedere_DEFINES += \
$${vedere_DEFINES} \

########################################################################
# libvedere OBJECTIVE_HEADERS
#
#libvedere_OBJECTIVE_HEADERS += \
#$${VEDERE_SRC}/vedere/base/Base.hh \

# libvedere OBJECTIVE_SOURCES
#
#libvedere_OBJECTIVE_SOURCES += \
#$${VEDERE_SRC}/vedere/base/Base.mm \

########################################################################
# libvedere HEADERS
#
libvedere_HEADERS += \
$${VEDERE_SRC}/xos/lib/vedere/version.hpp \

# libvedere SOURCES
#
libvedere_SOURCES += \
$${VEDERE_SRC}/xos/lib/vedere/version.cpp \

########################################################################



