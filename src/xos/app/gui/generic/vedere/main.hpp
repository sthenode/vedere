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
#include "xos/app/gui/vedere/main.hpp"
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
 class TExtends = gui::vedere::maint
 <TImplements, gui::vedere::main_optt
  <TImplements, xos::gui::generic::window_main> > >

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
    virtual int after_create_main_window
    (xos::gui::generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((main_window) && (&main_window_ == main_window)) {
            if (!(main_window_.init(this->image_width(), this->image_height(), this->image_depth(), this->image_file(), this->image_format()))) {
                err = 1;
            }
        } else {
            err = 1;
        }
        return err;
    }
    virtual int before_destroy_main_window
    (xos::gui::generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((main_window) && (&main_window_ == main_window)) {
        } else {
            err = 1;
        }
        return err;
    }

    virtual int create_main_window
    (xos::gui::generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((main_window_.create(0,0, this->main_window_width(),this->main_window_height()))) {
            if (!(err = main_window_.after_create(argc, argv, env))) {
                main_window = &main_window_;
            } else {
                main_window_.destroy();
            }
        } else {
            err = 1;
        }
        return err;
    }    
    virtual int destroy_main_window
    (xos::gui::generic::main_window*& main_window, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((main_window) && (&main_window_ == main_window)) {
            err = main_window_.before_destroy(argc, argv, env);
            if (!(main_window_.destroy())) {
                if (!err) err = 1;
            }
            main_window = 0;
        } else {
            err = 1;
        }
        return err;
    }    

protected:
    vedere::main_window main_window_;
};
typedef maint<> main;

} /// namespace vedere
} /// namespace generic
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_GENERIC_VEDERE_MAIN_HPP 
