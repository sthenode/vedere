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
///   File: main_window_extend.hpp
///
/// Author: $author$
///   Date: 7/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_MAIN_WINDOW_EXTEND_HPP
#define _XOS_APP_GUI_VEDERE_MAIN_WINDOW_EXTEND_HPP

#include "xos/app/gui/vedere/image/format.hpp"
#include "xos/io/crt/file/reader.hpp"

namespace xos {
namespace app {
namespace gui {
namespace vedere {

///////////////////////////////////////////////////////////////////////
///  Class: main_window_extendt
///////////////////////////////////////////////////////////////////////
template <class TExtends>
class _EXPORT_CLASS main_window_extendt: public TExtends {
public:
    typedef TExtends extends;

    main_window_extendt() {
    }
    virtual ~main_window_extendt() {
    }

    virtual bool load_image
    (size_t width, size_t height, size_t depth, 
     const char_t* file, image::format_t format) {
        bool success = false;

        if ((file) && (file[0])) {
            io::crt::file::byte_reader in;
            
            if ((in.open(file))) {
                success = load_image(width, height, depth, in, format);
                in.close();
            }
        }
        return success;
    }
    virtual bool load_image
    (size_t width, size_t height, size_t depth, 
     io::byte_reader& in, image::format_t format) {
        bool success = false;
        switch (format) {
        case image::format_raw:
            success = load_image(in, width, height, depth);
            break;
        case image::format_dng:
            success = load_dng_image(in);
            break;
        case image::format_png:
            success = load_png_image(in);
            break;
        case image::format_jpeg:
            success = load_jpeg_image(in);
            break;
        case image::format_tiff:
            success = load_tiff_image(in);
            break;
        case image::format_gif:
            success = load_gif_image(in);
            break;
        case image::format_bmp:
            success = load_bmp_image(in);
            break;
        default:
            LOG_ERROR("...unexpected format = " << format << "");
            break;
        }
        return success;
    }

    virtual bool load_dng_image(io::byte_reader& in) {
        return false;
    }
    virtual bool load_png_image(io::byte_reader& in) {
        return false;
    }
    virtual bool load_jpeg_image(io::byte_reader& in) {
        return false;
    }
    virtual bool load_tiff_image(io::byte_reader& in) {
        return false;
    }
    virtual bool load_gif_image(io::byte_reader& in) {
        return false;
    }
    virtual bool load_bmp_image(io::byte_reader& in) {
        return false;
    }

    virtual bool load_image(graphic::image::format::pixel::bytes::reader& in) {
        size_t image_width = 0, image_height = 0, image_depth = 0, image_size = 0;
        byte_t* bytes = 0;

        if ((bytes = in.detach_image(image_width, image_height, image_depth, image_size))) {
            
            LOG_DEBUG("set_image(bytes, image_size = " << image_size << ", image_width = " << image_width << ", image_height = " << image_height << ")...");
            if ((set_image(bytes, image_size, image_width, image_height))) {
                return true;
            } else {
                LOG_DEBUG("failed on set_image(bytes, image_size = " << image_size << ", image_width = " << image_width << ", image_height = " << image_height << ")");

                LOG_DEBUG("delete[] bytes...");
                delete[] bytes;
                LOG_DEBUG("...delete[] bytes");
            }
        }
        return false;
    }

    virtual void* load_image
    (io::byte_reader& in, size_t size, size_t width, size_t height) {
        return 0;
    }
    virtual void* set_image
    (byte_t* bytes, size_t size, size_t width, size_t height) {
        return 0;
    }
};

} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_MAIN_WINDOW_EXTEND_HPP 
