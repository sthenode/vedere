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
///   File: filled_ellipse.hpp
///
/// Author: $author$
///   Date: 6/30/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_SHAPE_FILLED_ELLIPSE_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_SHAPE_FILLED_ELLIPSE_HPP

#include "xos/graphic/image/surface/shape/extend.hpp"
#include "xos/graphic/image/shape/midpoint_ellipse.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {
namespace shape {

///////////////////////////////////////////////////////////////////////
///  Class: filled_ellipset
///////////////////////////////////////////////////////////////////////
template
<class TShapeInterface = shape::interface,
 class TImageInterface = area::interface,
 class TExtends = shape::extend>

class _EXPORT_CLASS filled_ellipset: public TExtends {
public:
    typedef TExtends extends;

    typedef TShapeInterface tShapeInterface;
    typedef TImageInterface tImageInterface;

    filled_ellipset
    (tImageInterface& image, tShapeInterface& color, tSize rx, tSize ry)
    : extends(image, rx,ry), ellipse_(image), color_(color), rx_(rx), ry_(ry) {
    }
    virtual ~filled_ellipset() {
    }

    virtual eError fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        if ((0 < w) && (0 < h) && (0 < rx_) && (0 < ry_)) {
            ellipse_.plot_ellipse(color_, x,y, rx_,ry_, e_ELLIPSE_QUADRANT_4);
            ellipse_.plot_ellipse(color_, x,y+h-1, rx_,ry_, e_ELLIPSE_QUADRANT_3);
            if ((2 < w)) {
                color_.fill(this->surface_, x+1,y-ry_+1, w-2,ry_);
                color_.fill(this->surface_, x+1,y+h-1, w-2,ry_);
            }
            if ((2 < h)) {
                color_.fill(this->surface_, x-rx_+1,y+1, w+rx_+rx_-2,h-2);
            }
            ellipse_.plot_ellipse(color_, x+w-1,y, rx_,ry_, e_ELLIPSE_QUADRANT_1);
            ellipse_.plot_ellipse(color_, x+w-1,y+h-1, rx_,ry_, e_ELLIPSE_QUADRANT_2);
        }
        return error;
    }
    virtual eError plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        ellipse_.plot_ellipse(color_, x,y, rx_,ry_);
        return error;
    }

protected:
    image::shape::filled_midpoint_ellipse ellipse_;
    tShapeInterface& color_;
    tSize rx_, ry_;
};
typedef filled_ellipset<> filled_ellipse;

} /// namespace shape
} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_SHAPE_FILLED_ELLIPSE_HPP 
