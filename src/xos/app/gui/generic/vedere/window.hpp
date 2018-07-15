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
///   File: window.hpp
///
/// Author: $author$
///   Date: 7/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_GENERIC_VEDERE_WINDOW_HPP
#define _XOS_APP_GUI_GENERIC_VEDERE_WINDOW_HPP

#include "xos/app/gui/vedere/window.hpp"
#include "xos/app/gui/generic/vedere/renderer.hpp"
#include "xos/gui/generic/window.hpp"

namespace xos {
namespace app {
namespace gui {
namespace generic {
namespace vedere {

typedef gui::vedere::windowt
<gui::vedere::window_extendt
 <xos::gui::generic::window> > window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: window
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS window: public window_extends {
public:
    typedef window_extends extends;

    window() {
    }
    virtual ~window() {
    }

    virtual void switch_render() {
        renderer_.switch_render();
    }

    virtual void* load_image
    (io::byte_reader& reader, size_t size, size_t width, size_t height) {
        return renderer_.load_image(reader, size, width, height);
    }
    virtual void* set_image
    (byte_t* bytes, size_t size, size_t width, size_t height) {
        return renderer_.set_image(bytes, size, width, height);
    }

protected:
    virtual bool got_message(message_type_t& type, message_data_t& data) {
        message_t message;
        if ((message_queue_.try_dequeue(message))) {
            type = message.type_;
            data = message.data_;
            return true;
        }
        return false;
    }

protected:
    renderer renderer_;
};
    
} /// namespace vedere
} /// namespace generic
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_GENERIC_VEDERE_WINDOW_HPP 
