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
///   Date: 5/30/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_MAIN_HPP
#define _XOS_GUI_MAIN_HPP

#include "xos/console/getopt/main.hpp"

namespace xos {
namespace gui {

typedef console::getopt::main::implements maint_implements;
typedef console::getopt::main maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = maint_implements, class TExtends = maint_extends>
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
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;

        LOG_DEBUG("before_event_loop(argc, argv, env)...");
        if (!(err = before_event_loop(argc, argv, env))) {
            int err2 = 0;

            LOG_DEBUG("event_loop(argc, argv, env)...");
            err = event_loop(argc, argv, env);

            LOG_DEBUG("after_event_loop(argc, argv, env)...");
            if ((err2 = after_event_loop(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }

    virtual int event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
};
typedef maint<> main;

} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_MAIN_HPP 
