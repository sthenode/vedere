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
///   File: window_main.hpp
///
/// Author: $author$
///   Date: 7/10/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_GENERIC_WINDOW_MAIN_HPP
#define _XOS_GUI_GENERIC_WINDOW_MAIN_HPP

#include "xos/gui/generic/main_window.hpp"
#include "xos/gui/generic/main.hpp"

namespace xos {
namespace gui {
namespace generic {

///////////////////////////////////////////////////////////////////////
///  Class: window_maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = main::implements, class TExtends = main>
class _EXPORT_CLASS window_maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    window_maint(): main_window_(0) {
    }
    virtual ~window_maint() {
    }
private:
    window_maint(const window_maint &copy): main_window_(0) {
    }

protected:
    virtual int create_main_window
    (generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_create_main_window
    (generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_create_main_window
    (generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    virtual int destroy_main_window
    (generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_destroy_main_window
    (generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_destroy_main_window
    (generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    virtual int before_event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;

        LOG_DEBUG("before_create_main_window(main_window_, argc, argv, env)...");
        if (!(err = before_create_main_window(main_window_, argc, argv, env))) {

            LOG_DEBUG("create_main_window(main_window_, argc, argv, env)...");
            if (!(err = create_main_window(main_window_, argc, argv, env))) {

                LOG_DEBUG("after_create_main_window(main_window_, argc, argv, env)...");
                if ((err = after_create_main_window(main_window_, argc, argv, env))) {
                    int err2 = 0;

                    LOG_ERROR("...failed on after_create_main_window(main_window_, argc, argv, env)");
                    LOG_DEBUG("before_destroy_main_window(main_window_, argc, argv, env)...");
                    if ((err2 = before_destroy_main_window(main_window_, argc, argv, env))) {
                        LOG_ERROR("...failed on before_destroy_main_window(main_window_, argc, argv, env)");
                    }
                    LOG_DEBUG("destroy_main_window(main_window_, argc, argv, env)...");
                    if ((err2 = destroy_main_window(main_window_, argc, argv, env))) {
                        LOG_ERROR("...failed on destroy_main_window(main_window_, argc, argv, env)");
                    }                        
                    LOG_DEBUG("after_destroy_main_window(main_window_, argc, argv, env)...");
                    if ((err2 = after_destroy_main_window(main_window_, argc, argv, env))) {
                        LOG_ERROR("...failed on after_destroy_main_window(main_window_, argc, argv, env)");
                    }
                }
            } else {
                LOG_ERROR("...failed on create_main_window(main_window_, argc, argv, env)");
            }
        } else {
            LOG_ERROR("...failed on before_create_main_window(main_window_, argc, argv, env)");
        }
        return err;
    }
    virtual int after_event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0, err2 = 0;

        LOG_DEBUG("before_destroy_main_window(main_window_, argc, argv, env)...");
        if ((err = before_destroy_main_window(main_window_, argc, argv, env))) {
            LOG_ERROR("...failed on before_destroy_main_window(main_window_, argc, argv, env)");
        }
        LOG_DEBUG("destroy_main_window(main_window_, argc, argv, env)...");
        if ((err2 = destroy_main_window(main_window_, argc, argv, env))) {
            LOG_ERROR("...failed on destroy_main_window(main_window_, argc, argv, env)");
            if (!err) err = err2;
        }                        
        LOG_DEBUG("after_destroy_main_window(main_window_, argc, argv, env)...");
        if ((err2 = after_destroy_main_window(main_window_, argc, argv, env))) {
            LOG_ERROR("...failed on after_destroy_main_window(main_window_, argc, argv, env)");
            if (!err) err = err2;
        }
        return err;
    }
    
protected:
    generic::main_window* main_window_;
};
typedef window_maint<> window_main;

} /// namespace generic
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_GENERIC_WINDOW_MAIN_HPP 
