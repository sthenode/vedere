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
///   Date: 7/12/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_WINDOW_HPP
#define _XOS_APP_GUI_VEDERE_WINDOW_HPP

#include "xos/mt/std/queue.hpp"
#include "xos/app/gui/vedere/window_extend.hpp"

namespace xos {
namespace app {
namespace gui {
namespace vedere {

///////////////////////////////////////////////////////////////////////
///  Class: windowt
///////////////////////////////////////////////////////////////////////
template <class TExtends>
class _EXPORT_CLASS windowt: public TExtends {
public:
    typedef TExtends extends;

    typedef typename extends::message_type_t message_type_t;
    typedef typename extends::message_data_t message_data_t;
    typedef typename extends::message_t message_t;
    typedef mt::std::queuet<message_t> message_queue_t;

    windowt() {
    }
    virtual ~windowt() {
    }

    virtual bool post_message(message_type_t type, message_data_t data) {
        message_t message(type, data);
        LOG_DEBUG("message_queue_.enqueue(message_t message(type = " << type << ",...))...");
        if ((message_queue_.enqueue(message))) {
            LOG_DEBUG("...message_queue_.enqueue(message_t message(type = " << type << ",...))");
            return true;
        } else {
            LOG_ERROR("...failed on message_queue_.enqueue(message_t message(type = " << type << ",...))");
        }
        return false;
    }

protected:
    message_queue_t message_queue_;
};

} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_WINDOW_HPP 
