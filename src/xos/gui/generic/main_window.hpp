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
#ifndef _XOS_GUI_GENERIC_MAIN_WINDOW_HPP
#define _XOS_GUI_GENERIC_MAIN_WINDOW_HPP

#include "xos/gui/generic/window.hpp"

namespace xos {
namespace gui {
namespace generic {

///////////////////////////////////////////////////////////////////////
///  Class: main_windowt
///////////////////////////////////////////////////////////////////////
template <class TImplements = window::implements, class TExtends = window>
class _EXPORT_CLASS main_windowt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    main_windowt() {
    }
    virtual ~main_windowt() {
    }
private:
    main_windowt(const main_windowt &copy) {
    }

public:
    virtual int after_create(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int before_destroy(int argc, char** argv, char** env) {
        int err = 0;
        return err;
    }
};
typedef main_windowt<> main_window;

} /// namespace generic
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_GENERIC_MAIN_WINDOW_HPP 
