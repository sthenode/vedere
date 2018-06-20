///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: base.hpp
///
/// Author: $author$
///   Date: 6/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_BASE_HPP
#define _XOS_GRAPHIC_SURFACE_BASE_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace graphic {
namespace surface {

typedef int tInt;
typedef size_t tSize;
typedef ssize_t tLength;
typedef ssize_t tOffset;

typedef int eError;
enum {
    e_ERROR_NONE = 0,
    e_ERROR_FAILED,
};

typedef unsigned int eOctant;
enum {
    e_OCTANT_NONE = 0,

    e_OCTANT_1 = (1 << 0),
    e_OCTANT_2 = (1 << 1),

    e_OCTANT_3 = (1 << 2),
    e_OCTANT_4 = (1 << 3),

    e_OCTANT_5 = (1 << 4),
    e_OCTANT_6 = (1 << 5),

    e_OCTANT_7 = (1 << 6),
    e_OCTANT_8 = (1 << 7),

    e_OCTANT_FIRST = (e_OCTANT_1),
    e_OCTANT_LAST = (e_OCTANT_8),
    e_OCTANT_NEXT = (e_OCTANT_LAST << 1),
    e_OCTANT_ALL  = (e_OCTANT_NEXT - 1),
    e_OCTANT_BITS = 1
};

typedef unsigned int eQuadrant;
enum {
    e_QUADRANT_ALL = e_OCTANT_ALL,

    e_QUADRANT_1 = (e_OCTANT_1 | e_OCTANT_2),
    e_QUADRANT_2 = (e_OCTANT_3 | e_OCTANT_4),
    e_QUADRANT_3 = (e_OCTANT_5 | e_OCTANT_6),
    e_QUADRANT_4 = (e_OCTANT_7 | e_OCTANT_8),

    e_QUADRANT_TOP_RIGHT    = (e_QUADRANT_1),
    e_QUADRANT_BOTTOM_RIGHT = (e_QUADRANT_2),
    e_QUADRANT_BOTTOM_LEFT  = (e_QUADRANT_3),
    e_QUADRANT_TOP_LEFT     = (e_QUADRANT_4),

    e_QUADRANT_FIRST = e_QUADRANT_1,
    e_QUADRANT_LAST = e_QUADRANT_4,
    e_QUADRANT_BITS = 2
};

} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_BASE_HPP 
