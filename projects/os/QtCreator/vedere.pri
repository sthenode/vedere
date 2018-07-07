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
# Os QtCreator .pri file for vedere
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
VEDERE_OS = macosx
} else {
VEDERE_OS = linux
}

#CONFIG += c++11
#CONFIG += c++0x

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${VEDERE_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# nadir
NADIR_THIRDPARTY_PKG_MAKE_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_MAKE_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PKG_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PKG_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PRJ_BLD = $${OTHER_BLD}/$${NADIR_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_BLD}/lib
#NADIR_LIB = $${NADIR_PKG_BLD}/lib
NADIR_LIB = $${NADIR_PRJ_BLD}/lib
#NADIR_LIB = $${VEDERE_LIB}

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_NAME} \
-l$${NADIR_NAME} \

########################################################################
# crono
CRONO_THIRDPARTY_PKG_MAKE_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_MAKE_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PKG_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PKG_BLD = $${OTHER_BLD}/$${CRONO_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PRJ_BLD = $${OTHER_BLD}/$${CRONO_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_BLD}/lib
#CRONO_LIB = $${CRONO_PKG_BLD}/lib
CRONO_LIB = $${CRONO_PRJ_BLD}/lib
#CRONO_LIB = $${VEDERE_LIB}

# crono LIBS
#
crono_LIBS += \
-L$${CRONO_LIB}/lib$${CRONO_NAME} \
-l$${CRONO_NAME} \

########################################################################
# fila
FILA_THIRDPARTY_PKG_MAKE_BLD = $${FILA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_MAKE_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PKG_BLD = $${FILA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PKG_BLD = $${OTHER_BLD}/$${FILA_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PRJ_BLD = $${OTHER_BLD}/$${FILA_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
#FILA_LIB = $${FILA_THIRDPARTY_PKG_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PKG_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_BLD}/lib
#FILA_LIB = $${FILA_PKG_BLD}/lib
FILA_LIB = $${FILA_PRJ_BLD}/lib
#FILA_LIB = $${VEDERE_LIB}

# fila LIBS
#
fila_LIBS += \
-L$${FILA_LIB}/lib$${FILA_NAME} \
-l$${FILA_NAME} \

########################################################################
# rete
RETE_THIRDPARTY_PKG_MAKE_BLD = $${RETE_THIRDPARTY_PKG}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
RETE_THIRDPARTY_PRJ_MAKE_BLD = $${RETE_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
RETE_THIRDPARTY_PKG_BLD = $${RETE_THIRDPARTY_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
RETE_THIRDPARTY_PRJ_BLD = $${RETE_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
RETE_PKG_BLD = $${OTHER_BLD}/$${RETE_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
RETE_PRJ_BLD = $${OTHER_BLD}/$${RETE_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
#RETE_LIB = $${RETE_THIRDPARTY_PKG_MAKE_BLD}/lib
#RETE_LIB = $${RETE_THIRDPARTY_PRJ_MAKE_BLD}/lib
#RETE_LIB = $${RETE_THIRDPARTY_PKG_BLD}/lib
#RETE_LIB = $${RETE_THIRDPARTY_PRJ_BLD}/lib
#RETE_LIB = $${RETE_PKG_BLD}/lib
RETE_LIB = $${RETE_PRJ_BLD}/lib
#RETE_LIB = $${VEDERE_LIB}

# rete LIBS
#
rete_LIBS += \
-L$${RETE_LIB}/lib$${RETE_NAME} \
-l$${RETE_NAME} \

########################################################################
# forma
FORMA_THIRDPARTY_PKG_MAKE_BLD = $${FORMA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
FORMA_THIRDPARTY_PRJ_MAKE_BLD = $${FORMA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
FORMA_THIRDPARTY_PKG_BLD = $${FORMA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
FORMA_THIRDPARTY_PRJ_BLD = $${FORMA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
FORMA_PKG_BLD = $${OTHER_BLD}/$${FORMA_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
FORMA_PRJ_BLD = $${OTHER_BLD}/$${FORMA_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
#FORMA_LIB = $${FORMA_THIRDPARTY_PKG_MAKE_BLD}/lib
#FORMA_LIB = $${FORMA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#FORMA_LIB = $${FORMA_THIRDPARTY_PKG_BLD}/lib
#FORMA_LIB = $${FORMA_THIRDPARTY_PRJ_BLD}/lib
#FORMA_LIB = $${FORMA_PKG_BLD}/lib
FORMA_LIB = $${FORMA_PRJ_BLD}/lib
#FORMA_LIB = $${VEDERE_LIB}

# forma LIBS
#
forma_LIBS += \
-L$${FORMA_LIB}/lib$${FORMA_NAME} \
-l$${FORMA_NAME} \

########################################################################
# lamna
LAMNA_THIRDPARTY_PKG_MAKE_BLD = $${LAMNA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
LAMNA_THIRDPARTY_PRJ_MAKE_BLD = $${LAMNA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
LAMNA_THIRDPARTY_PKG_BLD = $${LAMNA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
LAMNA_THIRDPARTY_PRJ_BLD = $${LAMNA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
LAMNA_PKG_BLD = $${OTHER_BLD}/$${LAMNA_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
LAMNA_PRJ_BLD = $${OTHER_BLD}/$${LAMNA_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
#LAMNA_LIB = $${LAMNA_THIRDPARTY_PKG_MAKE_BLD}/lib
#LAMNA_LIB = $${LAMNA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#LAMNA_LIB = $${LAMNA_THIRDPARTY_PKG_BLD}/lib
#LAMNA_LIB = $${LAMNA_THIRDPARTY_PRJ_BLD}/lib
#LAMNA_LIB = $${LAMNA_PKG_BLD}/lib
LAMNA_LIB = $${LAMNA_PRJ_BLD}/lib
#LAMNA_LIB = $${VEDERE_LIB}

# lamna LIBS
#
lamna_LIBS += \
-L$${LAMNA_LIB}/lib$${LAMNA_NAME} \
-l$${LAMNA_NAME} \

########################################################################
# plena
PLENA_THIRDPARTY_PKG_MAKE_BLD = $${PLENA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
PLENA_THIRDPARTY_PRJ_MAKE_BLD = $${PLENA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
PLENA_THIRDPARTY_PKG_BLD = $${PLENA_THIRDPARTY_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
PLENA_THIRDPARTY_PRJ_BLD = $${PLENA_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
PLENA_PKG_BLD = $${OTHER_BLD}/$${PLENA_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
PLENA_PRJ_BLD = $${OTHER_BLD}/$${PLENA_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
#PLENA_LIB = $${PLENA_THIRDPARTY_PKG_MAKE_BLD}/lib
#PLENA_LIB = $${PLENA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#PLENA_LIB = $${PLENA_THIRDPARTY_PKG_BLD}/lib
#PLENA_LIB = $${PLENA_THIRDPARTY_PRJ_BLD}/lib
#PLENA_LIB = $${PLENA_PKG_BLD}/lib
PLENA_LIB = $${PLENA_PRJ_BLD}/lib
#PLENA_LIB = $${VEDERE_LIB}

# plena LIBS
#
plena_LIBS += \
-L$${PLENA_LIB}/lib$${PLENA_NAME} \
-l$${PLENA_NAME} \

########################################################################
# qtere
QTERE_THIRDPARTY_PKG_MAKE_BLD = $${QTERE_THIRDPARTY_PKG}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
QTERE_THIRDPARTY_PRJ_MAKE_BLD = $${QTERE_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/$${BUILD_CONFIG}
QTERE_THIRDPARTY_PKG_BLD = $${QTERE_THIRDPARTY_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
QTERE_THIRDPARTY_PRJ_BLD = $${QTERE_THIRDPARTY_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
QTERE_PKG_BLD = $${OTHER_BLD}/$${QTERE_PKG}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
QTERE_PRJ_BLD = $${OTHER_BLD}/$${QTERE_PRJ}/build/$${VEDERE_OS}/QtCreator/$${BUILD_CONFIG}
#QTERE_LIB = $${QTERE_THIRDPARTY_PKG_MAKE_BLD}/lib
#QTERE_LIB = $${QTERE_THIRDPARTY_PRJ_MAKE_BLD}/lib
#QTERE_LIB = $${QTERE_THIRDPARTY_PKG_BLD}/lib
#QTERE_LIB = $${QTERE_THIRDPARTY_PRJ_BLD}/lib
#QTERE_LIB = $${QTERE_PKG_BLD}/lib
QTERE_LIB = $${QTERE_PRJ_BLD}/lib
#QTERE_LIB = $${VEDERE_LIB}

# qtere LIBS
#
qtere_LIBS += \
-L$${QTERE_LIB}/lib$${QTERE_NAME} \
-l$${QTERE_NAME} \

########################################################################
# vedere

# vedere INCLUDEPATH
#
vedere_INCLUDEPATH += \

# vedere DEFINES
#
vedere_DEFINES += \

# vedere LIBS
#
vedere_LIBS += \
$${plena_LIBS} \
$${lamna_LIBS} \
$${forma_LIBS} \
$${rete_LIBS} \
$${fila_LIBS} \
$${crono_LIBS} \
$${nadir_LIBS} \
$${rostra_LIBS} \
$${build_vedere_LIBS} \
-lpthread \
-ldl \

contains(VEDERE_OS,linux) {
vedere_LIBS += \
-lrt
} else {
}

