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
///   File: window_extend.hpp
///
/// Author: $author$
///   Date: 7/12/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_WINDOW_EXTEND_HPP
#define _XOS_APP_GUI_VEDERE_WINDOW_EXTEND_HPP

#include "xos/io/logger.hpp"

namespace xos {
namespace app {
namespace gui {
namespace vedere {

///////////////////////////////////////////////////////////////////////
///  Class: window_extendt
///////////////////////////////////////////////////////////////////////
template <class TExtends>// = base>
class _EXPORT_CLASS window_extendt: public TExtends {
public:
    typedef TExtends extends;

    enum message_type_t {
        message_type_none,
        message_type_switch_render
    };
    typedef void* message_data_t;
    
    class _EXPORT_CLASS message_t {
    public:
        message_t(message_type_t type, message_data_t data): type_(type), data_(data) {}
        message_t(const message_t& copy): type_(copy.type_), data_(copy.data_) {}
        message_t(): type_(message_type_none), data_(0) {}
        virtual ~message_t() {}
    public:
        message_type_t type_;
        message_data_t data_;
    };

    window_extendt() {
    }
    virtual ~window_extendt() {
    }

    virtual void switch_render() {
    }

    virtual bool post_message(message_type_t type, message_data_t data) {
        LOG_DEBUG("post_message(message_type_t type = " << type << ",...)...");
        return false;
    }

protected:
    virtual void on_message(message_type_t type, message_data_t data) {
        switch (type) {
        case message_type_switch_render:
            LOG_DEBUG("...on_message(message_type_t type = message_type_switch_render,...)");
            switch_render();
            break;
        default:
            LOG_DEBUG("...on_message(message_type_t type = " << type << ",...)");
            break;
        }
    }
};
//typedef window_extendt<> window_extend;

} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_WINDOW_EXTEND_HPP 
