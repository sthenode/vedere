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
///   File: image_format.hpp
///
/// Author: $author$
///   Date: 7/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_IMAGE_FORMAT_HPP
#define _XOS_APP_GUI_VEDERE_IMAGE_FORMAT_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace app {
namespace gui {
namespace vedere {
namespace image {

enum format_t {
    format_none,
    format_raw,
    format_dng,
    format_png,
    format_jpeg,
    format_tiff,
    format_gif,
    format_bmp,

    next_format,
    first_format = format_raw,
    last_format = (next_format - 1),
    formats = (last_format - first_format + 1)
};

} /// namespace image
} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_IMAGE_FORMAT_HPP 
