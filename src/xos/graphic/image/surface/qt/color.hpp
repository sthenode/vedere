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
///   File: color.hpp
///
/// Author: $author$
///   Date: 6/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_QT_COLOR_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_QT_COLOR_HPP

#include "xos/graphic/image/surface/qt/shape.hpp"
#include "xos/graphic/image/surface/qt/pixel.hpp"
#include "xos/graphic/image/surface/shape/color.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: colort
///////////////////////////////////////////////////////////////////////
template
<class TQShape = shape,
 class TQImageInterface = area_interface,
 class TQPixelInterface = pixel_interface,
 class TQPixel = pixel,
 class TColor = surface::shape::colort
 <TQShape, TQImageInterface, TQPixelInterface, TQPixel>,
 class TImplements = TQPixelInterface, class TExtends = TColor>

class _EXPORT_CLASS colort: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TQImageInterface tQImageInterface;
    typedef TColor tColor;

    colort
    (tQImageInterface& surfaceQImage,
     tSize r = 0, tSize g = 0, tSize b = 0, tSize width = 1, tSize height = 1)
    : extends(surfaceQImage, r,g,b, width,height) {
    }
    virtual ~colort() {
    }

    virtual eError fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        context_interface& gc = this->surfaceQImage().surfaceQContext();
        const pixel_interface& color = this->color();
        tSize r = this->red(), g = this->green(), b = this->blue();
        w = w+this->width()-1; h = h+this->height()-1;
        gc.fill_rectangle(x,y, w,h, color);
        return error;
    }

    virtual operator const QColor&() const {
        return this->color();
    }
};
typedef colort<> color;

} /// namespace qt
} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_QT_COLOR_HPP 
