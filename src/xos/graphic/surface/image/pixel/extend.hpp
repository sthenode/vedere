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
///   File: extend.hpp
///
/// Author: $author$
///   Date: 6/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_PIXEL_EXTEND_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_PIXEL_EXTEND_HPP

#include "xos/graphic/surface/image/pixel/interface.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace image {
namespace pixel {

///////////////////////////////////////////////////////////////////////
///  Class: extendt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = pixel::interface, class TExtends = xos::base>

class _EXPORT_CLASS extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    extendt(tSize r, tSize g, tSize b, tSize a) {
    }
    extendt(tSize r, tSize g, tSize b) {
    }
    extendt() {
    }
    virtual ~extendt() {
    }
};
typedef extendt<> extend;

} /// namespace pixel
} /// namespace image
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_PIXEL_EXTEND_HPP 
