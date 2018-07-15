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
///   File: renderer.hpp
///
/// Author: $author$
///   Date: 7/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_RENDERER_HPP
#define _XOS_APP_GUI_VEDERE_RENDERER_HPP

#include "xos/app/gui/vedere/renderer_extend.hpp"

namespace xos {
namespace app {
namespace gui {
namespace vedere {

enum renderer_image_format_t {
    IMAGE_RENDERER_IMAGE_FORMAT_NONE
};
enum renderer_image_aspect_t {
    IMAGE_RENDERER_IMAGE_ASPECT_IGNORE,
    IMAGE_RENDERER_IMAGE_ASPECT_KEEP
};
enum renderer_image_transform_t {
    IMAGE_RENDERER_IMAGE_TRANSFORM_NONE,
    IMAGE_RENDERER_IMAGE_TRANSFORM_FAST,
    IMAGE_RENDERER_IMAGE_TRANSFORM_SMOOTH
};

typedef vedere::image::renderert
<renderer_image_format_t, IMAGE_RENDERER_IMAGE_FORMAT_NONE,
 renderer_image_aspect_t, IMAGE_RENDERER_IMAGE_ASPECT_IGNORE,
 renderer_image_transform_t, IMAGE_RENDERER_IMAGE_TRANSFORM_NONE>
image_renderer_implements;

typedef vedere::image::renderer_extendt
<image_renderer_implements> image_renderer;

typedef implement_base renderer_implements;
typedef base renderer_extends;
typedef renderer_extendt
<renderer_image_format_t, IMAGE_RENDERER_IMAGE_FORMAT_NONE,
 image_renderer, renderer_implements, renderer_extends> renderer;

} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_RENDERER_HPP 
