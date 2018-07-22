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
# QtCreator .pri file for vedere
########################################################################

OTHER_PKG = ../../../../../../..
OTHER_PRJ = ../../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/src/$${THIRDPARTY_NAME}

########################################################################
# rostra
ROSTRA_VERSION_MAJOR = 0
ROSTRA_VERSION_MINOR = 0
ROSTRA_VERSION_RELEASE = 0
ROSTRA_VERSION = $${ROSTRA_VERSION_MAJOR}.$${ROSTRA_VERSION_MINOR}.$${ROSTRA_VERSION_RELEASE}
ROSTRA_NAME = rostra
ROSTRA_GROUP = $${ROSTRA_NAME}
ROSTRA_SOURCE = src
ROSTRA_DIR = $${ROSTRA_GROUP}/$${ROSTRA_NAME}-$${ROSTRA_VERSION}
ROSTRA_PKG_DIR = $${ROSTRA_NAME}
ROSTRA_HOME_BUILD = $${HOME}/build/$${ROSTRA_NAME}
ROSTRA_HOME_BUILD_INCLUDE = $${ROSTRA_HOME_BUILD}/include
ROSTRA_HOME_BUILD_LIB = $${ROSTRA_HOME_BUILD}/lib
ROSTRA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ROSTRA_PKG_DIR}
ROSTRA_THIRDPARTY_SRC_GROUP = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_NAME = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ROSTRA_THIRDPARTY_SRC_GROUP}/$${ROSTRA_THIRDPARTY_SRC_NAME} 
ROSTRA_PKG = $${OTHER_PKG}/$${ROSTRA_PKG_DIR}
ROSTRA_PRJ = $${OTHER_PRJ}/$${ROSTRA_PKG_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_SRC_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PKG}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PRJ}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_PKG}/$${ROSTRA_SOURCE}
ROSTRA_SRC = $${ROSTRA_PRJ}/$${ROSTRA_SOURCE}

# rostra INCLUDEPATH
#
#rostra_INCLUDEPATH += \
#$${ROSTRA_HOME_BUILD_INCLUDE} \

rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

# rostra DEFINES
#
rostra_DEFINES += \

########################################################################
# nadir
NADIR_VERSION_MAJOR = 0
NADIR_VERSION_MINOR = 0
NADIR_VERSION_RELEASE = 0
NADIR_VERSION = $${NADIR_VERSION_MAJOR}.$${NADIR_VERSION_MINOR}.$${NADIR_VERSION_RELEASE}
NADIR_NAME = nadir
NADIR_GROUP = $${NADIR_NAME}
NADIR_SOURCE = src
NADIR_DIR = $${NADIR_GROUP}/$${NADIR_NAME}-$${NADIR_VERSION}
NADIR_PKG_DIR = $${NADIR_NAME}
NADIR_HOME_BUILD = $${HOME}/build/$${NADIR_NAME}
NADIR_HOME_BUILD_INCLUDE = $${NADIR_HOME_BUILD}/include
NADIR_HOME_BUILD_LIB = $${NADIR_HOME_BUILD}/lib
NADIR_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${NADIR_DIR}
NADIR_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${NADIR_DIR}
NADIR_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${NADIR_PKG_DIR}
NADIR_THIRDPARTY_SRC_GROUP = $${NADIR_NAME}
NADIR_THIRDPARTY_SRC_NAME = $${NADIR_NAME}
NADIR_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${NADIR_THIRDPARTY_SRC_GROUP}/$${NADIR_THIRDPARTY_SRC_NAME} 
NADIR_PKG = $${OTHER_PKG}/$${NADIR_PKG_DIR}
NADIR_PRJ = $${OTHER_PRJ}/$${NADIR_PKG_DIR}
#NADIR_SRC = $${NADIR_THIRDPARTY_SRC_DIR}
#NADIR_SRC = $${NADIR_THIRDPARTY_PKG}/$${NADIR_SOURCE}
#NADIR_SRC = $${NADIR_THIRDPARTY_PRJ}/$${NADIR_SOURCE}
#NADIR_SRC = $${NADIR_PKG}/$${NADIR_SOURCE}
NADIR_SRC = $${NADIR_PRJ}/$${NADIR_SOURCE}

# nadir INCLUDEPATH
#
#nadir_INCLUDEPATH += \
#$${NADIR_HOME_BUILD_INCLUDE} \

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

# nadir DEFINES
#
nadir_DEFINES += \

########################################################################
# arbora
ARBORA_VERSION_MAJOR = 0
ARBORA_VERSION_MINOR = 0
ARBORA_VERSION_RELEASE = 0
ARBORA_VERSION = $${ARBORA_VERSION_MAJOR}.$${ARBORA_VERSION_MINOR}.$${ARBORA_VERSION_RELEASE}
ARBORA_NAME = arbora
ARBORA_GROUP = $${ARBORA_NAME}
ARBORA_SOURCE = src
ARBORA_DIR = $${ARBORA_GROUP}/$${ARBORA_NAME}-$${ARBORA_VERSION}
ARBORA_PKG_DIR = $${ARBORA_NAME}
ARBORA_HOME_BUILD = $${HOME}/build/$${ARBORA_NAME}
ARBORA_HOME_BUILD_INCLUDE = $${ARBORA_HOME_BUILD}/include
ARBORA_HOME_BUILD_LIB = $${ARBORA_HOME_BUILD}/lib
ARBORA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ARBORA_DIR}
ARBORA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ARBORA_DIR}
ARBORA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ARBORA_PKG_DIR}
ARBORA_THIRDPARTY_SRC_GROUP = $${ARBORA_NAME}
ARBORA_THIRDPARTY_SRC_NAME = $${ARBORA_NAME}
ARBORA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ARBORA_THIRDPARTY_SRC_GROUP}/$${ARBORA_THIRDPARTY_SRC_NAME} 
ARBORA_PKG = $${OTHER_PKG}/$${ARBORA_PKG_DIR}
ARBORA_PRJ = $${OTHER_PRJ}/$${ARBORA_PKG_DIR}
#ARBORA_SRC = $${ARBORA_THIRDPARTY_SRC_DIR}
#ARBORA_SRC = $${ARBORA_THIRDPARTY_PKG}/$${ARBORA_SOURCE}
#ARBORA_SRC = $${ARBORA_THIRDPARTY_PRJ}/$${ARBORA_SOURCE}
#ARBORA_SRC = $${ARBORA_PKG}/$${ARBORA_SOURCE}
ARBORA_SRC = $${ARBORA_PRJ}/$${ARBORA_SOURCE}

# arbora INCLUDEPATH
#
#arbora_INCLUDEPATH += \
#$${ARBORA_HOME_BUILD_INCLUDE} \

arbora_INCLUDEPATH += \
$${ARBORA_SRC} \

# arbora DEFINES
#
arbora_DEFINES += \

########################################################################
# archa
ARCHA_VERSION_MAJOR = 0
ARCHA_VERSION_MINOR = 0
ARCHA_VERSION_RELEASE = 0
ARCHA_VERSION = $${ARCHA_VERSION_MAJOR}.$${ARCHA_VERSION_MINOR}.$${ARCHA_VERSION_RELEASE}
ARCHA_NAME = archa
ARCHA_GROUP = $${ARCHA_NAME}
ARCHA_SOURCE = src
ARCHA_DIR = $${ARCHA_GROUP}/$${ARCHA_NAME}-$${ARCHA_VERSION}
ARCHA_PKG_DIR = $${ARCHA_NAME}
ARCHA_HOME_BUILD = $${HOME}/build/$${ARCHA_NAME}
ARCHA_HOME_BUILD_INCLUDE = $${ARCHA_HOME_BUILD}/include
ARCHA_HOME_BUILD_LIB = $${ARCHA_HOME_BUILD}/lib
ARCHA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ARCHA_DIR}
ARCHA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ARCHA_DIR}
ARCHA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ARCHA_PKG_DIR}
ARCHA_THIRDPARTY_SRC_GROUP = $${ARCHA_NAME}
ARCHA_THIRDPARTY_SRC_NAME = $${ARCHA_NAME}
ARCHA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ARCHA_THIRDPARTY_SRC_GROUP}/$${ARCHA_THIRDPARTY_SRC_NAME} 
ARCHA_PKG = $${OTHER_PKG}/$${ARCHA_PKG_DIR}
ARCHA_PRJ = $${OTHER_PRJ}/$${ARCHA_PKG_DIR}
#ARCHA_SRC = $${ARCHA_THIRDPARTY_SRC_DIR}
#ARCHA_SRC = $${ARCHA_THIRDPARTY_PKG}/$${ARCHA_SOURCE}
#ARCHA_SRC = $${ARCHA_THIRDPARTY_PRJ}/$${ARCHA_SOURCE}
#ARCHA_SRC = $${ARCHA_PKG}/$${ARCHA_SOURCE}
ARCHA_SRC = $${ARCHA_PRJ}/$${ARCHA_SOURCE}

# archa INCLUDEPATH
#
#archa_INCLUDEPATH += \
#$${ARCHA_HOME_BUILD_INCLUDE} \

archa_INCLUDEPATH += \
$${ARCHA_SRC} \

# archa DEFINES
#
archa_DEFINES += \

########################################################################
# crono
CRONO_VERSION_MAJOR = 0
CRONO_VERSION_MINOR = 0
CRONO_VERSION_RELEASE = 0
CRONO_VERSION = $${CRONO_VERSION_MAJOR}.$${CRONO_VERSION_MINOR}.$${CRONO_VERSION_RELEASE}
CRONO_NAME = crono
CRONO_GROUP = $${CRONO_NAME}
CRONO_SOURCE = src
CRONO_DIR = $${CRONO_GROUP}/$${CRONO_NAME}-$${CRONO_VERSION}
CRONO_PKG_DIR = $${CRONO_NAME}
CRONO_HOME_BUILD = $${HOME}/build/$${CRONO_NAME}
CRONO_HOME_BUILD_INCLUDE = $${CRONO_HOME_BUILD}/include
CRONO_HOME_BUILD_LIB = $${CRONO_HOME_BUILD}/lib
CRONO_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${CRONO_DIR}
CRONO_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${CRONO_DIR}
CRONO_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${CRONO_PKG_DIR}
CRONO_THIRDPARTY_SRC_GROUP = $${CRONO_NAME}
CRONO_THIRDPARTY_SRC_NAME = $${CRONO_NAME}
CRONO_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${CRONO_THIRDPARTY_SRC_GROUP}/$${CRONO_THIRDPARTY_SRC_NAME} 
CRONO_PKG = $${OTHER_PKG}/$${CRONO_PKG_DIR}
CRONO_PRJ = $${OTHER_PRJ}/$${CRONO_PKG_DIR}
#CRONO_SRC = $${CRONO_THIRDPARTY_SRC_DIR}
#CRONO_SRC = $${CRONO_THIRDPARTY_PKG}/$${CRONO_SOURCE}
#CRONO_SRC = $${CRONO_THIRDPARTY_PRJ}/$${CRONO_SOURCE}
#CRONO_SRC = $${CRONO_PKG}/$${CRONO_SOURCE}
CRONO_SRC = $${CRONO_PRJ}/$${CRONO_SOURCE}

# crono INCLUDEPATH
#
#crono_INCLUDEPATH += \
#$${CRONO_HOME_BUILD_INCLUDE} \

crono_INCLUDEPATH += \
$${CRONO_SRC} \

# crono DEFINES
#
crono_DEFINES += \

########################################################################
# fila
FILA_VERSION_MAJOR = 0
FILA_VERSION_MINOR = 0
FILA_VERSION_RELEASE = 0
FILA_VERSION = $${FILA_VERSION_MAJOR}.$${FILA_VERSION_MINOR}.$${FILA_VERSION_RELEASE}
FILA_NAME = fila
FILA_GROUP = $${FILA_NAME}
FILA_SOURCE = src
FILA_DIR = $${FILA_GROUP}/$${FILA_NAME}-$${FILA_VERSION}
FILA_PKG_DIR = $${FILA_NAME}
FILA_HOME_BUILD = $${HOME}/build/$${FILA_NAME}
FILA_HOME_BUILD_INCLUDE = $${FILA_HOME_BUILD}/include
FILA_HOME_BUILD_LIB = $${FILA_HOME_BUILD}/lib
FILA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${FILA_DIR}
FILA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${FILA_DIR}
FILA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${FILA_PKG_DIR}
FILA_THIRDPARTY_SRC_GROUP = $${FILA_NAME}
FILA_THIRDPARTY_SRC_NAME = $${FILA_NAME}
FILA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${FILA_THIRDPARTY_SRC_GROUP}/$${FILA_THIRDPARTY_SRC_NAME} 
FILA_PKG = $${OTHER_PKG}/$${FILA_PKG_DIR}
FILA_PRJ = $${OTHER_PRJ}/$${FILA_PKG_DIR}
#FILA_SRC = $${FILA_THIRDPARTY_SRC_DIR}
#FILA_SRC = $${FILA_THIRDPARTY_PKG}/$${FILA_SOURCE}
#FILA_SRC = $${FILA_THIRDPARTY_PRJ}/$${FILA_SOURCE}
#FILA_SRC = $${FILA_PKG}/$${FILA_SOURCE}
FILA_SRC = $${FILA_PRJ}/$${FILA_SOURCE}

# fila INCLUDEPATH
#
#fila_INCLUDEPATH += \
#$${FILA_HOME_BUILD_INCLUDE} \

fila_INCLUDEPATH += \
$${FILA_SRC} \

# fila DEFINES
#
fila_DEFINES += \

########################################################################
# rete
RETE_VERSION_MAJOR = 0
RETE_VERSION_MINOR = 0
RETE_VERSION_RELEASE = 0
RETE_VERSION = $${RETE_VERSION_MAJOR}.$${RETE_VERSION_MINOR}.$${RETE_VERSION_RELEASE}
RETE_NAME = rete
RETE_GROUP = $${RETE_NAME}
RETE_SOURCE = src
RETE_DIR = $${RETE_GROUP}/$${RETE_NAME}-$${RETE_VERSION}
RETE_PKG_DIR = $${RETE_NAME}
RETE_HOME_BUILD = $${HOME}/build/$${RETE_NAME}
RETE_HOME_BUILD_INCLUDE = $${RETE_HOME_BUILD}/include
RETE_HOME_BUILD_LIB = $${RETE_HOME_BUILD}/lib
RETE_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${RETE_DIR}
RETE_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${RETE_DIR}
RETE_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${RETE_PKG_DIR}
RETE_THIRDPARTY_SRC_GROUP = $${RETE_NAME}
RETE_THIRDPARTY_SRC_NAME = $${RETE_NAME}
RETE_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${RETE_THIRDPARTY_SRC_GROUP}/$${RETE_THIRDPARTY_SRC_NAME} 
RETE_PKG = $${OTHER_PKG}/$${RETE_PKG_DIR}
RETE_PRJ = $${OTHER_PRJ}/$${RETE_PKG_DIR}
#RETE_SRC = $${RETE_THIRDPARTY_SRC_DIR}
#RETE_SRC = $${RETE_THIRDPARTY_PKG}/$${RETE_SOURCE}
#RETE_SRC = $${RETE_THIRDPARTY_PRJ}/$${RETE_SOURCE}
#RETE_SRC = $${RETE_PKG}/$${RETE_SOURCE}
RETE_SRC = $${RETE_PRJ}/$${RETE_SOURCE}

# rete INCLUDEPATH
#
#rete_INCLUDEPATH += \
#$${RETE_HOME_BUILD_INCLUDE} \

rete_INCLUDEPATH += \
$${RETE_SRC} \

# rete DEFINES
#
rete_DEFINES += \

########################################################################
# forma
FORMA_VERSION_MAJOR = 0
FORMA_VERSION_MINOR = 0
FORMA_VERSION_RELEASE = 0
FORMA_VERSION = $${FORMA_VERSION_MAJOR}.$${FORMA_VERSION_MINOR}.$${FORMA_VERSION_RELEASE}
FORMA_NAME = forma
FORMA_GROUP = $${FORMA_NAME}
FORMA_SOURCE = src
FORMA_DIR = $${FORMA_GROUP}/$${FORMA_NAME}-$${FORMA_VERSION}
FORMA_PKG_DIR = $${FORMA_NAME}
FORMA_HOME_BUILD = $${HOME}/build/$${FORMA_NAME}
FORMA_HOME_BUILD_INCLUDE = $${FORMA_HOME_BUILD}/include
FORMA_HOME_BUILD_LIB = $${FORMA_HOME_BUILD}/lib
FORMA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${FORMA_DIR}
FORMA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${FORMA_DIR}
FORMA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${FORMA_PKG_DIR}
FORMA_THIRDPARTY_SRC_GROUP = $${FORMA_NAME}
FORMA_THIRDPARTY_SRC_NAME = $${FORMA_NAME}
FORMA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${FORMA_THIRDPARTY_SRC_GROUP}/$${FORMA_THIRDPARTY_SRC_NAME} 
FORMA_PKG = $${OTHER_PKG}/$${FORMA_PKG_DIR}
FORMA_PRJ = $${OTHER_PRJ}/$${FORMA_PKG_DIR}
#FORMA_SRC = $${FORMA_THIRDPARTY_SRC_DIR}
#FORMA_SRC = $${FORMA_THIRDPARTY_PKG}/$${FORMA_SOURCE}
#FORMA_SRC = $${FORMA_THIRDPARTY_PRJ}/$${FORMA_SOURCE}
#FORMA_SRC = $${FORMA_PKG}/$${FORMA_SOURCE}
FORMA_SRC = $${FORMA_PRJ}/$${FORMA_SOURCE}

# forma INCLUDEPATH
#
#forma_INCLUDEPATH += \
#$${FORMA_HOME_BUILD_INCLUDE} \

forma_INCLUDEPATH += \
$${FORMA_SRC} \

# forma DEFINES
#
forma_DEFINES += \

########################################################################
# lamna
LAMNA_VERSION_MAJOR = 0
LAMNA_VERSION_MINOR = 0
LAMNA_VERSION_RELEASE = 0
LAMNA_VERSION = $${LAMNA_VERSION_MAJOR}.$${LAMNA_VERSION_MINOR}.$${LAMNA_VERSION_RELEASE}
LAMNA_NAME = lamna
LAMNA_GROUP = $${LAMNA_NAME}
LAMNA_SOURCE = src
LAMNA_DIR = $${LAMNA_GROUP}/$${LAMNA_NAME}-$${LAMNA_VERSION}
LAMNA_PKG_DIR = $${LAMNA_NAME}
LAMNA_HOME_BUILD = $${HOME}/build/$${LAMNA_NAME}
LAMNA_HOME_BUILD_INCLUDE = $${LAMNA_HOME_BUILD}/include
LAMNA_HOME_BUILD_LIB = $${LAMNA_HOME_BUILD}/lib
LAMNA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${LAMNA_DIR}
LAMNA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${LAMNA_DIR}
LAMNA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${LAMNA_PKG_DIR}
LAMNA_THIRDPARTY_SRC_GROUP = $${LAMNA_NAME}
LAMNA_THIRDPARTY_SRC_NAME = $${LAMNA_NAME}
LAMNA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${LAMNA_THIRDPARTY_SRC_GROUP}/$${LAMNA_THIRDPARTY_SRC_NAME} 
LAMNA_PKG = $${OTHER_PKG}/$${LAMNA_PKG_DIR}
LAMNA_PRJ = $${OTHER_PRJ}/$${LAMNA_PKG_DIR}
#LAMNA_SRC = $${LAMNA_THIRDPARTY_SRC_DIR}
#LAMNA_SRC = $${LAMNA_THIRDPARTY_PKG}/$${LAMNA_SOURCE}
#LAMNA_SRC = $${LAMNA_THIRDPARTY_PRJ}/$${LAMNA_SOURCE}
#LAMNA_SRC = $${LAMNA_PKG}/$${LAMNA_SOURCE}
LAMNA_SRC = $${LAMNA_PRJ}/$${LAMNA_SOURCE}

# lamna INCLUDEPATH
#
#lamna_INCLUDEPATH += \
#$${LAMNA_HOME_BUILD_INCLUDE} \

lamna_INCLUDEPATH += \
$${LAMNA_SRC} \

# lamna DEFINES
#
lamna_DEFINES += \

########################################################################
# plena
PLENA_VERSION_MAJOR = 0
PLENA_VERSION_MINOR = 0
PLENA_VERSION_RELEASE = 0
PLENA_VERSION = $${PLENA_VERSION_MAJOR}.$${PLENA_VERSION_MINOR}.$${PLENA_VERSION_RELEASE}
PLENA_NAME = plena
PLENA_GROUP = $${PLENA_NAME}
PLENA_SOURCE = src
PLENA_DIR = $${PLENA_GROUP}/$${PLENA_NAME}-$${PLENA_VERSION}
PLENA_PKG_DIR = $${PLENA_NAME}
PLENA_HOME_BUILD = $${HOME}/build/$${PLENA_NAME}
PLENA_HOME_BUILD_INCLUDE = $${PLENA_HOME_BUILD}/include
PLENA_HOME_BUILD_LIB = $${PLENA_HOME_BUILD}/lib
PLENA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${PLENA_DIR}
PLENA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${PLENA_DIR}
PLENA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${PLENA_PKG_DIR}
PLENA_THIRDPARTY_SRC_GROUP = $${PLENA_NAME}
PLENA_THIRDPARTY_SRC_NAME = $${PLENA_NAME}
PLENA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${PLENA_THIRDPARTY_SRC_GROUP}/$${PLENA_THIRDPARTY_SRC_NAME} 
PLENA_PKG = $${OTHER_PKG}/$${PLENA_PKG_DIR}
PLENA_PRJ = $${OTHER_PRJ}/$${PLENA_PKG_DIR}
#PLENA_SRC = $${PLENA_THIRDPARTY_SRC_DIR}
#PLENA_SRC = $${PLENA_THIRDPARTY_PKG}/$${PLENA_SOURCE}
#PLENA_SRC = $${PLENA_THIRDPARTY_PRJ}/$${PLENA_SOURCE}
#PLENA_SRC = $${PLENA_PKG}/$${PLENA_SOURCE}
PLENA_SRC = $${PLENA_PRJ}/$${PLENA_SOURCE}

# plena INCLUDEPATH
#
#plena_INCLUDEPATH += \
#$${PLENA_HOME_BUILD_INCLUDE} \

plena_INCLUDEPATH += \
$${PLENA_SRC} \

# plena DEFINES
#
plena_DEFINES += \

########################################################################
# qtere
QTERE_VERSION_MAJOR = 0
QTERE_VERSION_MINOR = 0
QTERE_VERSION_RELEASE = 0
QTERE_VERSION = $${QTERE_VERSION_MAJOR}.$${QTERE_VERSION_MINOR}.$${QTERE_VERSION_RELEASE}
QTERE_NAME = qtere
QTERE_GROUP = $${QTERE_NAME}
QTERE_SOURCE = src
QTERE_DIR = $${QTERE_GROUP}/$${QTERE_NAME}-$${QTERE_VERSION}
QTERE_PKG_DIR = $${QTERE_NAME}
QTERE_HOME_BUILD = $${HOME}/build/$${QTERE_NAME}
QTERE_HOME_BUILD_INCLUDE = $${QTERE_HOME_BUILD}/include
QTERE_HOME_BUILD_LIB = $${QTERE_HOME_BUILD}/lib
QTERE_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${QTERE_DIR}
QTERE_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${QTERE_DIR}
QTERE_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${QTERE_PKG_DIR}
QTERE_THIRDPARTY_SRC_GROUP = $${QTERE_NAME}
QTERE_THIRDPARTY_SRC_NAME = $${QTERE_NAME}
QTERE_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${QTERE_THIRDPARTY_SRC_GROUP}/$${QTERE_THIRDPARTY_SRC_NAME} 
QTERE_PKG = $${OTHER_PKG}/$${QTERE_PKG_DIR}
QTERE_PRJ = $${OTHER_PRJ}/$${QTERE_PKG_DIR}
#QTERE_SRC = $${QTERE_THIRDPARTY_SRC_DIR}
#QTERE_SRC = $${QTERE_THIRDPARTY_PKG}/$${QTERE_SOURCE}
#QTERE_SRC = $${QTERE_THIRDPARTY_PRJ}/$${QTERE_SOURCE}
#QTERE_SRC = $${QTERE_PKG}/$${QTERE_SOURCE}
QTERE_SRC = $${QTERE_PRJ}/$${QTERE_SOURCE}

# qtere INCLUDEPATH
#
#qtere_INCLUDEPATH += \
#$${QTERE_HOME_BUILD_INCLUDE} \

qtere_INCLUDEPATH += \
$${QTERE_SRC} \

# qtere DEFINES
#
qtere_DEFINES += \


########################################################################
# vedere
FRAMEWORK_NAME = vedere
FRAMEWORK_SOURCE = src

VEDERE_PKG = ../../../../..
VEDERE_BLD = ../..

VEDERE_PRJ = $${VEDERE_PKG}
VEDERE_BIN = $${VEDERE_BLD}/bin
VEDERE_LIB = $${VEDERE_BLD}/lib
VEDERE_SRC = $${VEDERE_PKG}/$${FRAMEWORK_SOURCE}

# vedere BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
vedere_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
vedere_DEFINES += RELEASE_BUILD
}

# vedere INCLUDEPATH
#
vedere_INCLUDEPATH += \
$${VEDERE_SRC} \
$${qtere_INCLUDEPATH} \
$${plena_INCLUDEPATH} \
$${lamna_INCLUDEPATH} \
$${forma_INCLUDEPATH} \
$${rete_INCLUDEPATH} \
$${fila_INCLUDEPATH} \
$${crono_INCLUDEPATH} \
$${archa_INCLUDEPATH} \
$${arbora_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${rostra_INCLUDEPATH} \
$${build_vedere_INCLUDEPATH} \

# vedere DEFINES
#
vedere_DEFINES += \
$${rostra_DEFINES} \
$${nadir_DEFINES} \
$${arbora_DEFINES} \
$${archa_DEFINES} \
$${crono_DEFINES} \
$${fila_DEFINES} \
$${rete_DEFINES} \
$${forma_DEFINES} \
$${lamna_DEFINES} \
$${plena_DEFINES} \
$${qtere_DEFINES} \
$${build_vedere_DEFINES} \

# vedere LIBS
#
vedere_LIBS += \
-L$${VEDERE_LIB}/lib$${FRAMEWORK_NAME} \
-l$${FRAMEWORK_NAME} \


