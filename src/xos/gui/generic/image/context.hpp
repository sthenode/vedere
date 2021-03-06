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
///   File: context.hpp
///
/// Author: $author$
///   Date: 7/8/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_GENERIC_IMAGE_CONTEXT_HPP
#define _XOS_GUI_GENERIC_IMAGE_CONTEXT_HPP

#include "xos/gui/generic/image/format.hpp"
#include "xos/gui/generic/image/surface.hpp"

namespace xos {
namespace gui {
namespace generic {
namespace image {

typedef pointer_t context_t;

inline surface_t context_surface_create
(context_t& context, format_t format, size_t with, size_t height) {
    return 0;
}
inline size_t context_save(context_t& context) {
    return 0;
}
inline size_t context_restore(context_t& context) {
    return 0;
}
inline size_t context_translate(context_t& context, size_t x, size_t y) {
    return 0;
}
inline size_t context_scale(context_t& context, double x, double y) {
    return 0;
}
inline size_t context_paint_surface
(context_t& context, surface_t& surface, size_t x, size_t y) {
    return 0;
}

} /// namespace image
} /// namespace generic
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_GENERIC_IMAGE_CONTEXT_HPP 
