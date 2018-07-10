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
#   File: vedere.pri
#
# Author: $author$
#   Date: 7/5/2018
#
# QtCreator .pri file for vedere executable vedere
########################################################################

########################################################################
# vedere

# vedere_exe TARGET
#
vedere_exe_TARGET = vedere

# vedere_exe INCLUDEPATH
#
vedere_exe_INCLUDEPATH += \
$${vedere_INCLUDEPATH} \

# vedere_exe DEFINES
#
vedere_exe_DEFINES += \
$${vedere_DEFINES} \

########################################################################
# vedere_exe OBJECTIVE_HEADERS
#
#vedere_exe_OBJECTIVE_HEADERS += \
#$${VEDERE_SRC}/vedere/base/Base.hh \

# vedere_exe OBJECTIVE_SOURCES
#
#vedere_exe_OBJECTIVE_SOURCES += \
#$${VEDERE_SRC}/vedere/base/Base.mm \

########################################################################
# vedere_exe HEADERS
#
vedere_exe_HEADERS += \
$${NADIR_SRC}/xos/console/main.hpp \
$${NADIR_SRC}/xos/console/getopt/main_opt.hpp \
$${NADIR_SRC}/xos/console/getopt/main.hpp \
$${FILA_SRC}/xos/console/main_main.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/rectangle.hpp \
$${VEDERE_SRC}/xos/gui/generic/main.hpp \
$${VEDERE_SRC}/xos/gui/generic/main_window.hpp \
$${VEDERE_SRC}/xos/gui/generic/window_main.hpp \
$${VEDERE_SRC}/xos/gui/generic/image/format.hpp \
$${VEDERE_SRC}/xos/gui/generic/image/aspect.hpp \
$${VEDERE_SRC}/xos/gui/generic/image/transform.hpp \
$${VEDERE_SRC}/xos/app/gui/vedere/image/renderer.hpp \
$${VEDERE_SRC}/xos/app/gui/vedere/image/format.hpp \
$${VEDERE_SRC}/xos/app/gui/vedere/image/transform.hpp \
$${VEDERE_SRC}/xos/app/gui/generic/vedere/image/renderer.hpp \
$${VEDERE_SRC}/xos/app/gui/vedere/main_window_extend.hpp \
$${VEDERE_SRC}/xos/app/gui/vedere/main_window.hpp \
$${VEDERE_SRC}/xos/app/gui/vedere/main_opt.hpp \
$${VEDERE_SRC}/xos/app/gui/vedere/main.hpp \
$${VEDERE_SRC}/xos/app/gui/generic/vedere/image/renderer.hpp \
$${VEDERE_SRC}/xos/app/gui/generic/vedere/main_window.hpp \
$${VEDERE_SRC}/xos/app/gui/generic/vedere/main.hpp \

# vedere_exe SOURCES
#
vedere_exe_SOURCES += \
$${FILA_SRC}/xos/console/main_main.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/rectangle.cpp \
$${VEDERE_SRC}/xos/gui/generic/image/format.cpp \
$${VEDERE_SRC}/xos/gui/generic/image/aspect.cpp \
$${VEDERE_SRC}/xos/gui/generic/image/transform.cpp \
$${VEDERE_SRC}/xos/gui/generic/window_main.cpp \
$${VEDERE_SRC}/xos/app/gui/vedere/main_window_extend.cpp \
$${VEDERE_SRC}/xos/app/gui/vedere/main_opt.cpp \
$${VEDERE_SRC}/xos/app/gui/generic/vedere/image/renderer.cpp \
$${VEDERE_SRC}/xos/app/gui/generic/vedere/main_window.cpp \
$${VEDERE_SRC}/xos/app/gui/generic/vedere/main.cpp \

########################################################################
# vedere_exe FRAMEWORKS
#
vedere_exe_FRAMEWORKS += \
$${vedere_FRAMEWORKS} \

# vedere_exe LIBS
#
vedere_exe_LIBS += \
$${vedere_LIBS} \


