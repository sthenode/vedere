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
///   File: renderer_extend.hpp
///
/// Author: $author$
///   Date: 7/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_RENDERER_EXTEND_HPP
#define _XOS_APP_GUI_VEDERE_RENDERER_EXTEND_HPP

#include "xos/app/gui/vedere/image/renderer.hpp"
#include "xos/base/to_string.hpp"
#include "xos/io/reader.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace app {
namespace gui {
namespace vedere {

///////////////////////////////////////////////////////////////////////
///  Class: renderer_extendt
///////////////////////////////////////////////////////////////////////
template
<typename TImageFormat, TImageFormat VImageFormatNone, class TImageRenderer,
 class TImplements = implement_base, class TExtends = base>

class _EXPORT_CLASS renderer_extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef renderer_extendt derives;

    typedef TImageFormat image_format_t;
    typedef TImageRenderer image_renderer_t;
    typedef bool (derives::*render_t)();
    static const image_format_t image_format_none = VImageFormatNone;

    renderer_extendt()
    : render_(0), image_(0), image_size_(0),
      image_width_(0), image_height_(0),
      image_format_(image_format_none) {
    }
    virtual ~renderer_extendt() {
    }

    virtual bool render() {
        if ((render_) && (render_ != &derives::render)) {
            return (this->*render_)();
        } else {
            image_renderer_t* renderer = 0;
            if ((image_) && (renderer = image_renderer(image_format()))) {
                if ((renderer->render(image_, image_width_, image_height_))) {
                    return renderer->realize();
                }
            }
        }
        return false;
    }
    virtual bool render_in() {
        image_renderer_t* renderer = 0;
        if ((image_) && (renderer = image_renderer(image_format()))) {
            if ((renderer->render
                 (image_, image_width_, image_height_,
                  image_, image_width_, image_height_))) {
                return renderer->realize();
            }
        }
        return false;
    }
    virtual bool render_stretched() {
        image_renderer_t* renderer = 0;
        if ((image_) && (renderer = image_renderer(image_format()))) {
            if ((renderer->render_stretched(image_, image_width_, image_height_))) {
                return renderer->realize();
            }
        }
        return false;
    }
    virtual bool render_raw() {
        image_renderer_t* renderer = 0;
        if ((image_) && (renderer = image_renderer(image_format()))) {
            if ((renderer->render_raw(image_, image_width_, image_height_))) {
                return renderer->realize();
            }
        }
        return false;
    }
    virtual void switch_render() {
        if ((render_ != &derives::render_stretched)) {
            if ((render_ != &derives::render_in)) {
                if ((render_ != &derives::render_raw)) {
                    render_ = &derives::render_in;
                } else {
                    render_ = &derives::render;
                }
            } else {
                render_ = &derives::render_stretched;
            }
        } else {
            render_ = &derives::render_raw;
        }
    }

    virtual bool transform_smooth(bool on = true) {
        image_renderer_t* renderer = 0;
        if ((renderer = image_renderer(image_format()))) {
            return renderer->transform_smooth(on);
        }
        return false;
    }

    virtual void* load_image
    (io::byte_reader& reader, size_t size, size_t width, size_t height) {
        const image_format_t& format = image_format();
        return load_image(reader, size, width, height, format);
    }
    virtual void* load_image
    (io::byte_reader& reader, size_t size,
     size_t width, size_t height, const image_format_t& format) {
        free_image();
        if (0 < (size)) {
            byte_t* bytes = 0;
            LOG_DEBUG("new byte_t[size = " << size << "]...");
            if ((bytes = new byte_t[size])) {
                LOG_DEBUG("..." << pointer_to_string(bytes) << " = new byte_t[size = " << size << "]...");
                if (size == (reader.read(bytes, size))) {
                    image_ = bytes;
                    image_size_ = size;
                    image_width_ = width;
                    image_height_ = height;
                    if (&format != &image_format_) {
                        image_format_ = format;
                    }
                    return image_;
                } else {
                    LOG_ERROR("...failed on (size == (reader.read(bytes, size)))");
                }
                LOG_DEBUG("delete[] " << pointer_to_string(bytes) << "...")
                delete[] bytes;
                LOG_DEBUG("...delete[] " << pointer_to_string(bytes))
            } else {
                LOG_ERROR("...failed on new byte_t[size = " << size << "]...");
            }
        }
        return 0;
    }

    virtual void* set_image
    (byte_t* bytes, size_t size, size_t width, size_t height) {
        const image_format_t& format = image_format();
        return set_image(bytes, size, width, height, format);
    }
    virtual void* set_image
    (byte_t* bytes, size_t size,
     size_t width, size_t height, const image_format_t& format) {
        free_image();
        if ((bytes) && (0 < (size))) {
            image_ = bytes;
            image_size_ = size;
            image_width_ = width;
            image_height_ = height;
            if (&format != &image_format_) {
                image_format_ = format;
            }
            return image_;
        }
        return 0;
    }
    virtual void free_image() {
        byte_t* bytes = 0;
        if ((bytes = ((byte_t*)image_))) {
            LOG_DEBUG("delete[] " << pointer_to_string(bytes) << "...");
            delete[] bytes;
            LOG_DEBUG("...delete[] " << pointer_to_string(bytes))
            image_ = 0;
            image_size_ = image_width_ = image_height_ = 0;
        }
    }

    virtual image_renderer_t* image_renderer(const image_format_t& image_format) const {
        return 0;
    }
    virtual const image_format_t& image_format() const {
        return image_format_;
    }

    virtual const void* image(size_t& size, size_t& width, size_t& height) const {
        size = image_size_;
        width = image_width_;
        height = image_height_;
        return image_;
    }

protected:
    render_t render_;
    void* image_;
    size_t image_size_, image_width_, image_height_;
    image_format_t image_format_;
};

} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_RENDERER_EXTEND_HPP 
