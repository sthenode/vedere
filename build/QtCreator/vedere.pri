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
#   Date: 5/30/2018
#
# build QtCreator .pri file for vedere
########################################################################
HOME_UNAME = $$system(uname)

contains(HOME_UNAME,Darwin) {
HOME = /Users/jboyd
} else {
HOME = /home/jboyd
}

########################################################################
# libjpeg
#
# pkg-config --cflags --libs libjpeg
#

# build libjpeg INCLUDEPATH
#
build_libjpeg_INCLUDEPATH += \
$${HOME}/build/jpeg/include \

# build libjpeg DEFINES
#
build_libjpeg_DEFINES += \

# build libjpeg LIBS
#
build_libjpeg_LIBS += \
-L$${HOME}/build/jpeg/lib \
-ljpeg \

########################################################################
# libpng
#
# pkg-config --cflags --libs libpng
#

# build libpng INCLUDEPATH
#
build_libpng_INCLUDEPATH += \
$${HOME}/build/libpng/include \

# build libpng DEFINES
#
build_libpng_DEFINES += \

# build libpng LIBS
#
build_libpng_LIBS += \
-L${HOME}/build/libpng/lib \
-lpng \

########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#

# build rostra INCLUDEPATH
#
build_rostra_INCLUDEPATH += \

# build rostra DEFINES
#
build_rostra_DEFINES += \

# build rostra LIBS
#
build_rostra_LIBS += \

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

# build nadir INCLUDEPATH
#
build_nadir_INCLUDEPATH += \

# build nadir DEFINES
#
build_nadir_DEFINES += \

# build nadir LIBS
#
build_nadir_LIBS += \

########################################################################
# arbora
#
# pkg-config --cflags --libs arbora
#

# build arbora INCLUDEPATH
#
build_arbora_INCLUDEPATH += \

# build arbora DEFINES
#
build_arbora_DEFINES += \

# build arbora LIBS
#
build_arbora_LIBS += \

########################################################################
# archa
#
# pkg-config --cflags --libs archa
#

# build archa INCLUDEPATH
#
build_archa_INCLUDEPATH += \

# build archa DEFINES
#
build_archa_DEFINES += \

# build archa LIBS
#
build_archa_LIBS += \

########################################################################
# crono
#
# pkg-config --cflags --libs crono
#

# build crono INCLUDEPATH
#
build_crono_INCLUDEPATH += \

# build crono DEFINES
#
build_crono_DEFINES += \

# build crono LIBS
#
build_crono_LIBS += \

########################################################################
# fila
#
# pkg-config --cflags --libs fila
#

# build fila INCLUDEPATH
#
build_fila_INCLUDEPATH += \

# build fila DEFINES
#
build_fila_DEFINES += \

# build fila LIBS
#
build_fila_LIBS += \

########################################################################
# rete
#
# pkg-config --cflags --libs rete
#

# build rete INCLUDEPATH
#
build_rete_INCLUDEPATH += \

# build rete DEFINES
#
build_rete_DEFINES += \

# build rete LIBS
#
build_rete_LIBS += \

########################################################################
# forma
#
# pkg-config --cflags --libs forma
#

# build forma INCLUDEPATH
#
build_forma_INCLUDEPATH += \
$${HOME}/build/libpng/include \

# build forma DEFINES
#
build_forma_DEFINES += \

# build forma LIBS
#
build_forma_LIBS += \
-L$${HOME}/build/libpng/lib \
-lpng \

########################################################################
# lamna
#
# pkg-config --cflags --libs lamna
#

# build lamna INCLUDEPATH
#
build_lamna_INCLUDEPATH += \

# build lamna DEFINES
#
build_lamna_DEFINES += \

# build lamna LIBS
#
build_lamna_LIBS += \

########################################################################
# plena
#
# pkg-config --cflags --libs plena
#

# build plena INCLUDEPATH
#
build_plena_INCLUDEPATH += \

# build plena DEFINES
#
build_plena_DEFINES += \

# build plena LIBS
#
build_plena_LIBS += \

########################################################################
# qtere
#
# pkg-config --cflags --libs qtere
#

# build qtere INCLUDEPATH
#
build_qtere_INCLUDEPATH += \

# build qtere DEFINES
#
build_qtere_DEFINES += \

# build qtere LIBS
#
build_qtere_LIBS += \

########################################################################
# vedere

# build vedere INCLUDEPATH
#
build_vedere_INCLUDEPATH += \
$${build_plena_INCLUDEPATH} \
$${build_lamna_INCLUDEPATH} \
$${build_forma_INCLUDEPATH} \
$${build_rete_INCLUDEPATH} \
$${build_fila_INCLUDEPATH} \
$${build_crono_INCLUDEPATH} \
$${build_archa_INCLUDEPATH} \
$${build_arbora_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \
$${build_rostra_INCLUDEPATH} \
$${build_libpng_INCLUDEPATH} \
$${build_libjpeg_INCLUDEPATH} \


# build vedere DEFINES
#
build_vedere_DEFINES += \
$${build_rostra_DEFINES} \
$${build_nadir_DEFINES} \
$${build_arbora_DEFINES} \
$${build_archa_DEFINES} \
$${build_crono_DEFINES} \
$${build_fila_DEFINES} \
$${build_rete_DEFINES} \
$${build_forma_DEFINES} \
$${build_lamna_DEFINES} \
$${build_plena_DEFINES} \
$${build_libpng_DEFINES} \
$${build_libjpeg_DEFINES} \


# build vedere LIBS
#
build_vedere_LIBS += \
$${build_plena_LIBS} \
$${build_lamna_LIBS} \
$${build_forma_LIBS} \
$${build_rete_LIBS} \
$${build_fila_LIBS} \
$${build_crono_LIBS} \
$${build_archa_LIBS} \
$${build_arbora_LIBS} \
$${build_nadir_LIBS} \
$${build_rostra_LIBS} \
$${build_libpng_LIBS} \
$${build_libjpeg_LIBS} \


