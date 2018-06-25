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
///   Date: 6/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_COLOR_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_COLOR_HPP

#include "xos/graphic/surface/image/shape/extend.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace image {
namespace shape {

///////////////////////////////////////////////////////////////////////
///  Class: colort
///////////////////////////////////////////////////////////////////////
template
<class TShape = shape,
 class TImageInterface = image_interface,
 class TPixelInterface = pixel_interface,
 class TPixel = pixel,
 class TImplements = TPixelInterface, class TExtends = TShape>

class _EXPORT_CLASS colort: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TShape tShape;
    typedef image_base_interface tImageBaseInterface;
    typedef TImageInterface tImageInterface;
    typedef TPixelInterface tPixelInterface;
    typedef TPixel tPixel;

    colort
    (tImageInterface& surface_image,
     tSize r = 0, tSize g = 0, tSize b = 0, tSize width = 1, tSize height = 1)
    : extends(surface_image),
      m_surface_image(surface_image),
      m_r(r), m_g(g), m_b(b),
      m_width(width), m_height(height),
      m_color(r,g,b) {
    }
    colort(const colort& copy, tSize width, tSize height)
    : extends(copy.m_surface_image),
      m_surface_image(copy.m_surface_image),
      m_r(copy.m_r), m_g(copy.m_g), m_b(copy.m_b),
      m_width(width), m_height(height),
      m_color(copy.m_color) {
    }
    colort(const colort& copy)
    : extends(copy.m_surface_image),
      m_surface_image(copy.m_surface_image),
      m_r(copy.m_r), m_g(copy.m_g), m_b(copy.m_b),
      m_width(copy.m_width), m_height(copy.m_height),
      m_color(copy.m_color) {
    }
    virtual ~colort() {
    }

    virtual eError Fill
    (tImageBaseInterface& image, tOffset x,tOffset y, tSize w,tSize h) {
        eError error = e_ERROR_NONE;
        tImageBaseInterface& this_image = this->surface_image_;
        if (!(&image != &this_image)) {
            this->fill(x,y, w,h);
        }
        return error;
    }
    virtual eError Plot
    (tImageBaseInterface& image, tOffset x,tOffset y) {
        eError error = e_ERROR_NONE;
        tImageBaseInterface& this_image = this->surface_image_;
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

    virtual tSize red() const { return m_r; }
    virtual tSize green() const { return m_g; }
    virtual tSize blue() const { return m_b; }

    virtual tSize width() const { return m_width; }
    virtual tSize height() const { return m_height; }

    virtual tPixelInterface& color() const {
        return (tPixelInterface&)m_color;
    }

protected:
    tImageInterface& m_surface_image;
    tSize m_r, m_g, m_b;
    tSize m_width, m_height;
    tPixel m_color;
};
typedef colort<> color;

} /// namespace shape
} /// namespace image
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_COLOR_HPP 
