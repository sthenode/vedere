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
///   File: main.hpp
///
/// Author: $author$
///   Date: 7/10/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_GENERIC_MAIN_HPP
#define _XOS_GUI_GENERIC_MAIN_HPP

#include "xos/gui/main.hpp"

namespace xos {
namespace gui {
namespace generic {

typedef pointer_t window_message_t;

inline size_t get_window_message(window_message_t& window_message) {
    return 0;
}
inline size_t peek_window_message(window_message_t& window_message) {
    return 0;
}
inline size_t post_window_message(window_message_t window_message) {
    return 0;
}
inline size_t send_window_message(window_message_t window_message) {
    return 0;
}
inline size_t dispatch_window_message(window_message_t window_message) {
    return 0;
}

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = gui::main::implements, class TExtends = gui::main>
class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
    }

protected:
    virtual int event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool done = false;
        window_message_t window_message;

        do {
            LOG_DEBUG("get_window_message(window_message)...");
            if ((get_window_message(window_message))) {

                LOG_DEBUG("dispatch_window_message(window_message)...");
                if ((dispatch_window_message(window_message))) {
                    continue;
                } else {
                    LOG_ERROR("...failed on dispatch_window_message(window_message)");
                }
            } else {
                LOG_ERROR("...failed on get_window_message(window_message)");
            }
            done = true;
        } while (!done);
        return err;
    }
};
typedef maint<> main;

} /// namespace generic
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_GENERIC_MAIN_HPP 
