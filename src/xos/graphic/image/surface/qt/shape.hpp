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
///   File: shape.hpp
///
/// Author: $author$
///   Date: 6/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_QT_SHAPE_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_QT_SHAPE_HPP

#include "xos/graphic/image/surface/qt/area.hpp"
#include "xos/graphic/image/surface/shape/extend.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: shapet
///////////////////////////////////////////////////////////////////////
template
<class TQImageInterface = area_interface,
 class TImplements = shape::interface, class TExtends = shape::extend>

class _EXPORT_CLASS shapet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TQImageInterface tQImageInterface;

    shapet(tQImageInterface& image)
    : extends(image), image_(image) {
    }
    virtual ~shapet() {
    }

    virtual tQImageInterface& surfaceQImage() const {
        return (tQImageInterface&)image_;
    }

protected:
    tQImageInterface& image_;
};
typedef shapet<> shape;

} /// namespace qt
} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_QT_SHAPE_HPP 
