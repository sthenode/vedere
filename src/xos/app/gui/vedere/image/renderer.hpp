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
///   Date: 7/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_IMAGE_RENDERER_HPP
#define _XOS_APP_GUI_VEDERE_IMAGE_RENDERER_HPP

#include "xos/graphic/image/surface/rectangle.hpp"

#define XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_MIN_WIDTH  100
#define XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_MIN_HEIGHT 100
#define XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_OFFSET_X   10
#define XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_OFFSET_Y   10
#define XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_RATIO      4
#define XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_RATIO_TO   1

namespace xos {
namespace app {
namespace gui {
namespace vedere {
namespace image {

///////////////////////////////////////////////////////////////////////
///  Class: image_renderert
///////////////////////////////////////////////////////////////////////
template
<typename TImageFormat, TImageFormat VImageFormatNone,
 typename TAspectRatioMode, TAspectRatioMode VAspectRatioModeNone,
 typename TTransformationMode, TTransformationMode VTransformationModeNone,
 class TImplements = implement_base>

class _EXPORT_CLASS image_renderert: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TImageFormat image_format_t;
    typedef TAspectRatioMode aspect_ratio_mode_t;
    typedef TTransformationMode transformation_mode_t;
    static const image_format_t image_format_none = VImageFormatNone;
    static const aspect_ratio_mode_t aspect_ratio_mode_none = VAspectRatioModeNone;
    static const transformation_mode_t transformation_mode_none = VTransformationModeNone;

    virtual bool initialize() {
        return true;
    }
    virtual bool realize() {
        return true;
    }
    virtual bool resize(size_t width, size_t height) {
        return true;
    }

    virtual bool render
    (const void* image, size_t image_width, size_t image_height,
     const void* in_image, size_t in_image_width, size_t in_image_height) {
        graphic::image::surface::size_t size(image_width, image_height),
                                 to_size(this->width(), this->height());
        graphic::image::surface::rectangle_t r(size, to_size);

        if ((render
             (image, image_width,image_height,
              r.size.width,r.size.height, r.origin.x,r.origin.y,
              image_format(), aspect_ratio_mode(), transformation_mode()))) {

            if ((this->width() >= this->in_min_width())
                && (this->height() >= this->in_min_height())) {
                int x = r.origin.x + r.size.width - this->in_offset_x();
                int y = r.origin.y + r.size.height - this->in_offset_y();
                int width = (r.size.width*this->in_ratio_to())/this->in_ratio();
                int height = (r.size.height*this->in_ratio_to())/this->in_ratio();
                graphic::image::surface::size_t in_size(in_image_width, in_image_height),
                                         to_in_size(width, height);
                graphic::image::surface::rectangle_t in_r(in_size, to_in_size);

                if ((render
                     (in_image, in_image_width,in_image_height,
                      in_r.size.width,in_r.size.height,
                      x-in_r.size.width,y-in_r.size.height, image_format(),
                      aspect_ratio_mode(), transformation_mode()))) {
                    return true;
                }
            }
            return true;
        }
        return false;
    }
    virtual bool render
    (const void* image, size_t image_width, size_t image_height) {
        graphic::image::surface::size_t size(image_width, image_height),
                                 to_size(this->width(), this->height());
        graphic::image::surface::rectangle_t r(size, to_size);
        if ((render
             (image, image_width,image_height,
              r.size.width,r.size.height, r.origin.x,r.origin.y, image_format(),
              aspect_ratio_mode(), transformation_mode()))) {
            return true;
        }
        return false;
    }
    virtual bool render_stretched
    (const void* image, size_t image_width, size_t image_height) {
        if ((render
             (image, image_width,image_height,
              this->width(),this->height(), 0,0, image_format(),
              aspect_ratio_mode_streached(), transformation_mode()))) {
            return true;
        }
        return false;
    }
    virtual bool render_raw
    (const void* image, size_t image_width, size_t image_height) {
        if ((render
             (image, image_width,image_height,
              image_width,image_height, 0,0, image_format(),
              aspect_ratio_mode_raw(), transformation_mode()))) {
            return true;
        }
        return false;
    }

    virtual bool render
    (const void* image, size_t image_width, size_t image_height,
     size_t width, size_t height, size_t x, size_t y, image_format_t image_format,
     aspect_ratio_mode_t aspect_ratio_mode, transformation_mode_t transformation_mode) {
        return false;
    }

    virtual image_format_t image_format() const {
        return image_format_none;
    }

    virtual aspect_ratio_mode_t aspect_ratio_mode() const {
        return aspect_ratio_mode_none;
    }
    virtual aspect_ratio_mode_t aspect_ratio_mode_streached() const {
        return aspect_ratio_mode_none;
    }
    virtual aspect_ratio_mode_t aspect_ratio_mode_raw() const {
        return aspect_ratio_mode_none;
    }

    virtual bool transform_smooth(bool on = true) {
        return false;
    }
    virtual transformation_mode_t transformation_mode() const {
        return transformation_mode_none;
    }

    virtual size_t width() const {
        return 0;
    }
    virtual size_t height() const {
        return 0;
    }
    virtual size_t in_min_width() const {
        return XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_MIN_WIDTH;
    }
    virtual size_t in_min_height() const {
        return XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_MIN_HEIGHT;
    }
    virtual size_t in_offset_x() const {
        return XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_OFFSET_X;
    }
    virtual size_t in_offset_y() const {
        return XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_OFFSET_Y;
    }
    virtual size_t in_ratio() const {
        return XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_RATIO;
    }
    virtual size_t in_ratio_to() const {
        return XOS_APP_GUI_VEDERE_IMAGE_RENDERER_IN_RATIO_TO;
    }
};

} /// namespace image
} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_IMAGE_RENDERER_HPP 
