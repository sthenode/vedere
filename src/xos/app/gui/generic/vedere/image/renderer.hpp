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

    renderer(xos::gui::generic::image::context_t context = 0): context_(context) {
    }
    virtual ~renderer() {
    }
    
    virtual bool init
    (xos::gui::generic::image::context_t context, size_t width, size_t height) {
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
        if ((context_) && (image)) {
            xos::gui::generic::image::surface_t surface = 0;

            if ((surface = image_create_from_data
                 (context_, (const byte_t*)image, format, width, height))) {
                xos::gui::generic::image::context_save(context_);
                switch(aspect) {
                case xos::gui::generic::image::ASPECT_IGNORE: {
                    double scale_x = (((double)width)/((double)image_width)),
                           scale_y = (((double)height)/((double)image_height));
                    xos::gui::generic::image::context_translate(context_, x,y);
                    xos::gui::generic::image::context_scale(context_, scale_x,scale_y);
                    break; }
                }
                xos::gui::generic::image::context_paint_surface(context_, surface, 0,0);
                xos::gui::generic::image::context_restore(context_);
                xos::gui::generic::image::surface_destroy(surface);
                return true;
            }
        }
        return false;
    }

    virtual xos::gui::generic::image::surface_t image_create_from_data
    (xos::gui::generic::image::context_t context, 
     const byte_t* image, xos::gui::generic::image::format_t image_format, 
     size_t image_width, size_t image_height) const {
        if ((context) && (image) && (image_width) && (image_height)) {
            xos::gui::generic::image::surface_t surface = 0;

            if ((surface = xos::gui::generic::image::context_surface_create
                 (context, image_format, image_width, image_height))) {
                byte_t* surface_data = 0;

                xos::gui::generic::image::surface_flush(surface);
                if ((surface_data = xos::gui::generic::image::surface_get_data(surface))) {
                    size_t surface_stride = xos::gui::generic::image::surface_get_stride(surface);

                    if (0 < (surface_stride)) {
                        xos::gui::generic::image::surface_mark_dirty(surface);
                        if ((image_copy_data
                             (surface, surface_data, image, image_format,
                              image_width, image_height, surface_stride))) {
                            xos::gui::generic::image::surface_flush(surface);
                            return surface;
                        }
                    }
                }
                xos::gui::generic::image::surface_destroy(surface);
            }
        }
        return 0;
    }

    virtual xos::gui::generic::image::surface_t image_copy_data
    (xos::gui::generic::image::surface_t surface, unsigned char* surface_data,
     const byte_t* image, xos::gui::generic::image::format_t image_format,
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
    virtual xos::gui::generic::image::surface_t image_copy_data_argb32
    (xos::gui::generic::image::surface_t surface, unsigned char* surface_data,
     const byte_t* image, size_t image_width, size_t image_height, size_t surface_stride) const {
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
    xos::gui::generic::image::context_t context_;
};

} /// namespace image
} /// namespace vedere
} /// namespace generic
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_GENERIC_VEDERE_IMAGE_RENDERER_HPP 
