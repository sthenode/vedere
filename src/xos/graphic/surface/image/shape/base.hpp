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
///   File: base.hpp
///
/// Author: $author$
///   Date: 6/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_BASE_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_BASE_HPP

#include "xos/graphic/surface/image/interface.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace image {
namespace shape {

///////////////////////////////////////////////////////////////////////
///  Class: baset
///////////////////////////////////////////////////////////////////////
template
<class TImageInterface = image::interface,
 class TImplements = xos::implement_base, class TExtends = xos::base>

class _EXPORT_CLASS baset: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TImageInterface tImageInterface;

    baset(tImageInterface& image): image_(image) {
    }
    virtual ~baset() {
    }

    virtual eError plot(tImageInterface& image, tOffset x, tOffset y) {
        eError error = image.plot(x,y);
        return error;
    }
    virtual eError fill
    (tImageInterface& image, tOffset x, tOffset y, tSize w, tSize h) {
        eError error = image.fill(x,y, w,h);
        return error;
    }

    virtual eError plot(tOffset x, tOffset y) {
        eError error = image_.plot(x,y);
        return error;
    }
    virtual eError fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = image_.fill(x,y, w,h);
        return error;
    }

protected:
    tImageInterface& image_;
};
typedef baset<> base;

} /// namespace shape
} /// namespace image
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_BASE_HPP 
