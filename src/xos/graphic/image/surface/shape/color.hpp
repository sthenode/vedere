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
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_SHAPE_COLOR_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_SHAPE_COLOR_HPP

#include "xos/graphic/image/surface/shape/extend.hpp"
#include "xos/graphic/image/surface/pixel/extend.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {
namespace shape {

///////////////////////////////////////////////////////////////////////
///  Class: colort
///////////////////////////////////////////////////////////////////////
template
<class TShape = extend,
 class TSurfaceInterface = surface::area::interface,
 class TPixelInterface = pixel::interface,
 class TPixel = pixel::extend,
 class TImplements = TPixelInterface, class TExtends = TShape>

class _EXPORT_CLASS colort: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TShape tShape;
    typedef image::base::interface tImageBaseInterface;
    typedef TSurfaceInterface tSurfaceInterface;
    typedef TPixelInterface tPixelInterface;
    typedef TPixel tPixel;

    colort
    (tSurfaceInterface& surface,
     tSize r = 0, tSize g = 0, tSize b = 0, tSize width = 1, tSize height = 1)
    : extends(surface),
      surface_(surface),
      r_(r), g_(g), b_(b), a_(0),
      width_(width), height_(height),
      color_(r,g,b) {
    }
    colort(const colort& copy, tSize width, tSize height)
    : extends(copy.surface_),
      surface_(copy.surface_),
      r_(copy.r_), g_(copy.g_), b_(copy.b_), 
      a_(copy.a_), width_(width), height_(height),
      color_(copy.color_) {
    }
    colort(const colort& copy)
    : extends(copy.surface_),
      surface_(copy.surface_),
      r_(copy.r_), g_(copy.g_), b_(copy.b_),
      a_(copy.a_), width_(copy.width_), height_(copy.height_),
      color_(copy.color_) {
    }
    virtual ~colort() {
    }

    virtual eError Fill
    (tImageBaseInterface& image, tOffset x,tOffset y, tSize w,tSize h) {
        eError error = e_ERROR_NONE;
        tImageBaseInterface& this_image = this->surface_;
        if (!(&image != &this_image)) {
            this->fill(x,y, w,h);
        }
        return error;
    }
    virtual eError Plot
    (tImageBaseInterface& image, tOffset x,tOffset y) {
        eError error = e_ERROR_NONE;
        tImageBaseInterface& this_image = this->surface_;
        if (!(&image != &this_image)) {
            this->fill(x,y, 1,1);
        }
        return error;
    }

    virtual eError fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError plot(tOffset x, tOffset y) {
        eError error = fill(x,y, 1,1);
        return error;
    }

    virtual tSize red() const { return r_; }
    virtual tSize green() const { return g_; }
    virtual tSize blue() const { return b_; }
    virtual tSize alpha() const { return a_; }

    virtual tSize width() const { return width_; }
    virtual tSize height() const { return height_; }

    virtual tPixelInterface& color() const {
        return (tPixelInterface&)color_;
    }

protected:
    tSurfaceInterface& surface_;
    tSize r_, g_, b_, a_;
    tSize width_, height_;
    tPixel color_;
};
typedef colort<> color;


} /// namespace shape
} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_SHAPE_COLOR_HPP 
