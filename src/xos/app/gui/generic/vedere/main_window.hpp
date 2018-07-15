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
///   Date: 7/10/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_GENERIC_VEDERE_MAIN_WINDOW_HPP
#define _XOS_APP_GUI_GENERIC_VEDERE_MAIN_WINDOW_HPP

#include "xos/app/gui/generic/vedere/window.hpp"
#include "xos/app/gui/vedere/main_window.hpp"
#include "xos/gui/generic/main_window.hpp"

namespace xos {
namespace app {
namespace gui {
namespace generic {
namespace vedere {

typedef app::gui::vedere::main_windowt
<app::gui::vedere::main_window_extendt
 <xos::gui::generic::main_window> > main_window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_window
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main_window: public main_window_extends {
public:
    typedef main_window_extends extends;

    main_window() {
    }
    virtual ~main_window() {
    }
private:
    main_window(const main_windowt &copy) {
    }

public:
    virtual bool init
    (size_t image_width, size_t image_height, size_t image_depth, 
     const char_t* image_file, gui::vedere::image::format_t image_format) {
        size_t width = 0, height = 0;
        
        if ((this->size(width, height))) {
            if ((window_.create(0,0, width,height))) {
                LOG_DEBUG("this->load_image(image_width, image_height, image_depth, image_file, image_format)...");
                if (!(this->load_image(image_width, image_height, image_depth, image_file, image_format))) {
                    LOG_ERROR("...failed on this->load_image(image_width, image_height, image_depth, image_file, image_format)");
                    window_.destroy();
                }
            }
        }
        return true;
    }

protected:
    using extends::load_image;
    virtual void* load_image
    (io::byte_reader& reader, size_t size, size_t width, size_t height) {
        return window_.load_image(reader, size, width, height);
    }
    virtual void* set_image
    (byte_t* bytes, size_t size, size_t width, size_t height) {
        return window_.set_image(bytes, size, width, height);
    }

protected:
    window window_;
};

} /// namespace vedere
} /// namespace generic
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_GENERIC_VEDERE_MAIN_WINDOW_HPP 
