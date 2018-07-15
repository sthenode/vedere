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
#ifndef _XOS_GUI_GENERIC_WINDOW_HPP
#define _XOS_GUI_GENERIC_WINDOW_HPP

#include "xos/base/created.hpp"
#include "xos/base/to_string.hpp"

namespace xos {
namespace gui {
namespace generic {

typedef pointer_t window_t;
typedef struct window_struct {
    ssize_t x,y;
    size_t width,height;
    window_struct(ssize_t x, ssize_t y, size_t width, size_t height) {
        this->x = x; this->y = y; this->width = width; this->height = height;
    }
} window_struct_t;

inline window_t window_create(ssize_t x, ssize_t y, size_t width, size_t height) {
    window_struct_t* window_struct = 0;
    if ((window_struct = new window_struct_t(x,y, width,height))) {
        return (window_t)window_struct;
    }
    return 0;
}
inline bool window_destroy(window_t window) {
    window_struct_t* window_struct = 0;
    if ((window) && (window_struct = (window_struct_t*)window)) {
        delete window_struct;
        return true;
    }
    return false;
}
inline bool window_size(window_t window, size_t& width, size_t& height) {
    window_struct_t* window_struct = 0;
    if ((window) && (window_struct = (window_struct_t*)window)) {
        width = window_struct->width;
        height = window_struct->height;
        return true;
    }
    return false;
}

typedef window_t window_attached_t;
typedef creatort<implement_base> window_creator;
typedef attachert<window_attached_t, int, 0, window_creator> window_attacher;
typedef attachedt<window_attached_t, int, 0, window_attacher, base> window_attached;
typedef createdt<window_attached_t, int, 0, window_attacher, window_attached> window_created;
typedef window_attacher windowt_implements;
typedef window_created windowt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: windowt
///////////////////////////////////////////////////////////////////////
template <class TImplements = windowt_implements, class TExtends = windowt_extends>
class _EXPORT_CLASS windowt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename extends::attached_t attached_t;
    typedef typename extends::unattached_t unattached_t;
    enum { unattached = extends::unattached };
    
    windowt(attached_t detached, bool is_created): extends(detached, is_created) {
    }
    windowt(attached_t detached): extends(detached) {
    }
    windowt(const windowt &copy) {
    }
    windowt() {
    }
    virtual ~windowt() {
    }

    virtual bool create
    (ssize_t x, ssize_t y, size_t width, size_t height) {
        attached_t detached = (attached_t)(unattached);
        if (((attached_t)(unattached) != (detached = this->create_attached(x,y, width,height)))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual attached_t create_attached
    (ssize_t x, ssize_t y, size_t width, size_t height) {
        attached_t detached = (attached_t)(unattached);
        if ((this->destroyed())) {
            if (((attached_t)(unattached) != (detached = create_detached(x,y, width,height)))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t create_detached
    (ssize_t x, ssize_t y, size_t width, size_t height) const {
        attached_t detached = (attached_t)(unattached);
        LOG_DEBUG("window_create(x = " << x << ",y = " << y << ", width = " << width << ",height = " << height << ")...");
        if ((attached_t)(unattached) != (detached = window_create(x,y, width,height))) {
            LOG_DEBUG("..." << pointer_to_string(detached) << " = window_create(x = " << x << ",y = " << y << ", width = " << width << ",height = " << height << ")");
        } else {
            LOG_DEBUG("...failed on window_create(x = " << x << ",y = " << y << ", width = " << width << ",height = " << height << ")...");
        }
        return detached;
    }
    virtual bool destroy_detached(attached_t detached) const {
        if ((attached_t)(unattached) != (detached)) {
            LOG_DEBUG("window_destroy(" << pointer_to_string(detached) << ")...");
            if ((window_destroy(detached))) {
                return true;
            } else {
                LOG_ERROR("...failed on window_destroy(" << pointer_to_string(detached) << ")");
            }
        }
        return false;
    }
    
    virtual bool size(size_t& width, size_t& height) {
        attached_t detached = (attached_t)(unattached);
        if ((detached = this->attached_to())) {
            if ((window_size(detached, width, height))) {
                return true;
            }
        }
        return false;
    }
};
typedef windowt<> window;

} /// namespace generic
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_GENERIC_WINDOW_HPP 
