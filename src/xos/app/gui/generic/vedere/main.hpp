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
#ifndef _XOS_APP_GUI_GENERIC_VEDERE_MAIN_HPP
#define _XOS_APP_GUI_GENERIC_VEDERE_MAIN_HPP

#include "xos/app/gui/generic/vedere/main_window.hpp"
#include "xos/gui/generic/window_main.hpp"

namespace xos {
namespace app {
namespace gui {
namespace generic {
namespace vedere {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = xos::gui::generic::window_main::implements, 
 class TExtends = xos::gui::generic::window_main>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    maint(): main_window_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy): main_window_(0) {
    }
    
protected:
    virtual int after_create_main_window
    (xos::gui::generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((main_window_) && (main_window_ == main_window)) {
        } else {
            err = 1;
        }
        return err;
    }
    virtual int before_destroy_main_window
    (xos::gui::generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((main_window_) && (main_window_ == main_window)) {
        } else {
            err = 1;
        }
        return err;
    }

    virtual int create_main_window
    (xos::gui::generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((main_window_ = new vedere::main_window())) {
            main_window = main_window_;
        } else {
            err = 1;
        }
        return err;
    }    
    virtual int destroy_main_window
    (xos::gui::generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((main_window_) && (main_window_ == main_window)) {
            delete main_window_;
            main_window = main_window_ = 0;
        } else {
            err = 1;
        }
        return err;
    }    

protected:
    vedere::main_window* main_window_;
};
typedef maint<> main;

} /// namespace vedere
} /// namespace generic
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_GENERIC_VEDERE_MAIN_HPP 
