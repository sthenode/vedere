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
///   File: main_window.hpp
///
/// Author: $author$
///   Date: 7/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_MAIN_WINDOW_HPP
#define _XOS_APP_GUI_VEDERE_MAIN_WINDOW_HPP

#include "xos/app/gui/vedere/main_window_extend.hpp"
#include "xos/app/gui/vedere/image/format.hpp"
#include "xos/graphic/image/format/png/libpng/pixel/bgra_reader.hpp"
#include "xos/graphic/image/format/jpeg/libjpeg/pixel/bgra_reader.hpp"
#include "xos/graphic/image/format/gif/giflib/pixel/bgra_reader.hpp"

namespace xos {
namespace app {
namespace gui {
namespace vedere {

///////////////////////////////////////////////////////////////////////
///  Class: main_windowt
///////////////////////////////////////////////////////////////////////
template <class TExtends>
class _EXPORT_CLASS main_windowt: public TExtends {
public:
    typedef TExtends extends;
    typedef main_windowt derives;

    main_windowt() {
    }
    virtual ~main_windowt() {
    }

    virtual bool load_dng_image(io::byte_reader& reader) {
        return false;
    }
    virtual bool load_png_image(io::byte_reader& reader) {
        graphic::image::format::png::libpng::pixel::bgra_reader bgra_reader(reader);
        if ((bgra_reader.read())) {
            if ((this->load_image(bgra_reader))) {
                return true;
            }
        }
        return false;
    }
    virtual bool load_jpeg_image(io::byte_reader& reader) {
        return false;
    }
    virtual bool load_tiff_image(io::byte_reader& reader) {
        return false;
    }
    virtual bool load_gif_image(io::byte_reader& reader) {
        return false;
    }
    virtual bool load_bmp_image(io::byte_reader& reader) {
        return false;
    }

    virtual bool load_dng_image(FILE* file) {
        return false;
    }
    virtual bool load_png_image(FILE* file) {
        return load_png_image_file(file);
    }
    virtual bool load_jpeg_image(FILE* file) {
        return load_jpeg_image_file(file);
    }
    virtual bool load_tiff_image(FILE* file) {
        return false;
    }
    virtual bool load_gif_image(FILE* file) {
        return false;
    }
    virtual bool load_bmp_image(FILE* file) {
        return false;
    }
    
    virtual bool load_dng_image(const char* filename) {
        return false;
    }
    virtual bool load_png_image(const char* filename) {
        return load_image_filename(&derives::load_png_image_file, filename);
    }
    virtual bool load_jpeg_image(const char* filename) {
        return load_image_filename(&derives::load_jpeg_image_file, filename);
    }
    virtual bool load_tiff_image(const char* filename) {
        return false;
    }
    virtual bool load_gif_image(const char* filename) {
        graphic::image::format::gif::giflib::pixel::bgra_reader bgra_reader;
        if ((bgra_reader.read(filename))) {
            if ((this->load_image(bgra_reader))) {
                return true;
            }
        }
        return false;
    }
    virtual bool load_bmp_image(const char* filename) {
        return false;
    }

protected:
    virtual bool load_png_image_file(FILE* file) {
        graphic::image::format::png::libpng::pixel::bgra_reader bgra_reader(file);
        if ((bgra_reader.read())) {
            if ((this->load_image(bgra_reader))) {
                return true;
            }
        }
        return false;
    }
    virtual bool load_jpeg_image_file(FILE* file) {
        graphic::image::format::jpeg::libjpeg::pixel::bgra_reader bgra_reader(file);
        if ((bgra_reader.read())) {
            if ((this->load_image(bgra_reader))) {
                return true;
            }
        }
        return false;
    }

protected:
    virtual bool load_image_filename
    (bool (derives::*load_image_file)(FILE* file), const char* filename) {
        bool success = false;

        if ((load_image_file) && (filename) && (filename[0])) {
            io::crt::file::byte_reader reader;
            
            if ((reader.open(filename))) {
                FILE* file = 0;
                if ((file = reader.attached_to())) {
                    success = (this->*load_image_file)(file);
                }
                reader.close();
            }
        } else {
            LOG_ERROR("...failed on ((load_image_file) && (filename) && (filename[0]))");
        }
        return success;
    }
};

} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_MAIN_WINDOW_HPP 
