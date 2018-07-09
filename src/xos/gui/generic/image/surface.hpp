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
///   File: surface.hpp
///
/// Author: $author$
///   Date: 7/8/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_GENERIC_IMAGE_SURFACE_HPP
#define _XOS_GUI_GENERIC_IMAGE_SURFACE_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace gui {
namespace generic {
namespace image {

typedef pointer_t surface_t;

inline byte_t* surface_get_data(surface_t& surface) {
    return 0;
}
inline size_t surface_get_stride(surface_t& surface) {
    return 0;
}
inline size_t surface_mark_dirty(surface_t& surface) {
    return 0;
}
inline size_t surface_flush(surface_t& surface) {
    return 0;
}
inline size_t surface_destroy(surface_t& surface) {
    return 0;
}

} /// namespace image
} /// namespace generic
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_GENERIC_IMAGE_SURFACE_HPP 
