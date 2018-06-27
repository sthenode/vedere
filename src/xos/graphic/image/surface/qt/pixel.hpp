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
///   File: pixel.hpp
///
/// Author: $author$
///   Date: 6/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_QT_PIXEL_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_QT_PIXEL_HPP

#include "xos/graphic/image/surface/pixel/extend.hpp"
#include "xos/gui/qt/Qt.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: pixel_interfacet
///////////////////////////////////////////////////////////////////////
template <class TImplements = pixel::interface>

class _EXPORT_CLASS pixel_interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual operator const QColor&() const = 0;
};
typedef pixel_interfacet<> pixel_interface;

///////////////////////////////////////////////////////////////////////
///  Class: pixelt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = pixel_interface, class TExtends = pixel::extend>

class _EXPORT_CLASS pixelt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    pixelt(int r, int g, int b, int a): extends(r,g,b,a), qColor_(r,g,b,a) {
    }
    pixelt(int r, int g, int b): extends(r,g,b), qColor_(r,g,b) {
    }
    pixelt(): qColor_(0,0,0) {
    }
    virtual ~pixelt() {
    }

    virtual operator const QColor&() const {
        return qColor_;
    }

protected:
    QColor qColor_;
};
typedef pixelt<> pixel;

} /// namespace qt
} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_QT_PIXEL_HPP 
