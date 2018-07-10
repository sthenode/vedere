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

#include "xos/gui/generic/main_window.hpp"

namespace xos {
namespace app {
namespace gui {
namespace generic {
namespace vedere {

///////////////////////////////////////////////////////////////////////
///  Class: main_windowt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = xos::gui::generic::main_window::implements, 
 class TExtends = xos::gui::generic::main_window>

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
};
typedef main_windowt<> main_window;

} /// namespace vedere
} /// namespace generic
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_GENERIC_VEDERE_MAIN_WINDOW_HPP 
