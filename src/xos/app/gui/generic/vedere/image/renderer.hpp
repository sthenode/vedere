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
///   Date: 7/8/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_GENERIC_VEDERE_IMAGE_RENDERER_HPP
#define _XOS_APP_GUI_GENERIC_VEDERE_IMAGE_RENDERER_HPP

#include "xos/app/gui/vedere/image/renderer.hpp"
#include "xos/gui/generic/image/format.hpp"
#include "xos/gui/generic/image/aspect.hpp"
#include "xos/gui/generic/image/transform.hpp"
#include "xos/gui/generic/image/surface.hpp"
#include "xos/gui/generic/image/context.hpp"
#include "xos/base/to_string.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace app {
namespace gui {
namespace generic {
namespace vedere {
namespace image {

typedef gui::vedere::image::renderert
<xos::gui::generic::image::format_t, xos::gui::generic::image::FORMAT_ARGB32,
 xos::gui::generic::image::aspect_t, xos::gui::generic::image::ASPECT_IGNORE,
 xos::gui::generic::image::transform_t, xos::gui::generic::image::TRANSFORM_NONE> renderer_implements;

typedef gui::vedere::image::renderer_extendt<renderer_implements> renderer_extends;

///////////////////////////////////////////////////////////////////////
///  Class: renderer
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS renderer
: virtual public renderer_implements, public renderer_extends {
public:
    typedef renderer_implements implements;
    typedef renderer_extends extends;

    renderer(xos::gui::generic::image::context_t* context = 0): context_(context) {
    }
    virtual ~renderer() {
    }
    
    virtual bool init
    (xos::gui::generic::image::context_t* context, size_t width, size_t height) {
        context_ = context;
        width_ = width;
        height_ = height;
        return true;
    }
    virtual bool finish() {
        context_ = 0;
        return true;
    }

    virtual bool render
    (const void* image, size_t image_width, size_t image_height,
     size_t width, size_t height, size_t x, size_t y, xos::gui::generic::image::format_t format,
     xos::gui::generic::image::aspect_t aspect, xos::gui::generic::image::transform_t transform) {
        return false;
    }

    virtual xos::gui::generic::image::surface_t* image_copy_data
    (xos::gui::generic::image::surface_t* surface, unsigned char* surface_data,
     const unsigned char* image, xos::gui::generic::image::format_t image_format,
     size_t image_width, size_t image_height, size_t surface_stride) const {
        if (xos::gui::generic::image::FORMAT_ARGB32 == (image_format)) {
            return image_copy_data_argb32
            (surface, surface_data, image,
             image_width, image_height, surface_stride);
        } else {
            LOG_ERROR("...invalid image_format = " << image_format << "");
        }
        return 0;
    }
    virtual xos::gui::generic::image::surface_t* image_copy_data_argb32
    (xos::gui::generic::image::surface_t* surface, unsigned char* surface_data,
     const unsigned char* image, size_t image_width, size_t image_height, size_t surface_stride) const {
        if ((surface) && (surface_data) && (surface_stride)
            && (image) && (image_width) && (image_height)) {
            size_t row_size = (image_width * sizeof(uint32_t));

            for (size_t row = 0; row < image_height; ++row) {
                LOG_DEBUG("::memcpy(surface_data = " << pointer_to_string(surface_data) << ", image = " << pointer_to_string(image) << ", row_size = " << row_size << ")...");
                surface_data += surface_stride;
                image += row_size;
            }
            return surface;
        }
        return 0;
    }

protected:
    xos::gui::generic::image::context_t* context_;
};

} /// namespace image
} /// namespace vedere
} /// namespace generic
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_GENERIC_VEDERE_IMAGE_RENDERER_HPP 
