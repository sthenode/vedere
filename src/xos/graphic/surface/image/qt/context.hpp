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
///   File: context.hpp
///
/// Author: $author$
///   Date: 6/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_QT_CONTEXT_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_QT_CONTEXT_HPP

#include "xos/graphic/surface/image/qt/pixel.hpp"
#include "xos/graphic/surface/image/context/extend.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace image {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: context_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TQPixelInterface = pixel_interface,
 class TImplements = context::interface>

class _EXPORT_CLASS context_interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TQPixelInterface tQPixelInterface;

    virtual eError fill_rectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tQPixelInterface& color) {
        eError error = e_ERROR_NONE;
        return error;
    }
};
typedef context_interfacet<> context_interface;

///////////////////////////////////////////////////////////////////////
///  Class: contextt
///////////////////////////////////////////////////////////////////////
template
<class TQPixelInterface = pixel_interface,
 class TImplements = context_interface, class TExtends = context::extend>

class _EXPORT_CLASS contextt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TQPixelInterface tQPixelInterface;

    contextt(QPaintDevice* device): qPainter_(device) {
    }
    virtual ~contextt() {
    }

    virtual eError fill_rectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tQPixelInterface& color) {
        eError error = e_ERROR_NONE;
        const QColor& qColor = color;
        const QRect rect(x,y, width,height);
        qPainter_.fillRect(rect, color);
        return error;
    }

protected:
    QPainter qPainter_;
};
typedef contextt<> context;

} /// namespace qt
} /// namespace image
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_QT_CONTEXT_HPP 
