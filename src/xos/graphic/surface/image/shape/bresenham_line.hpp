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
///   File: bresenham_line.hpp
///
/// Author: $author$
///   Date: 6/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_BRESENHAM_LINE_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_BRESENHAM_LINE_HPP

#include "xos/graphic/surface/image/shape/base.hpp"
#include "xos/graphic/surface/image/bresenham_line.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace image {
namespace shape {

typedef image::bresenham_linet
<shape::base, image::interface> bresenham_line_extends;
///////////////////////////////////////////////////////////////////////
///  Class: bresenham_line
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS bresenham_line: public bresenham_line_extends {
public:
    typedef bresenham_line_extends extends;

    bresenham_line(tImageInterface& image): extends(image) {
    }
    virtual ~bresenham_line() {
    }

    virtual void draw_line
    (tImageInterface &image, tInt x1,tInt y1, tInt x2,tInt y2) {
        bresenham_line_drawt<extends, tPixel, tInt>(*this, image, x1,y1, x2,y2);
    }
    virtual void draw_triangle
    (tImageInterface &image, tInt x1,tInt y1, tInt x2,tInt y2, tInt x3,tInt y3) {
        bresenham_line_drawt<extends, tPixel, tInt>(*this, image, x1,y1, x2,y2);
        bresenham_line_drawt<extends, tPixel, tInt>(*this, image, x2,y2, x3,y3);
        bresenham_line_drawt<extends, tPixel, tInt>(*this, image, x3,y3, x1,y1);
    }
};

} /// namespace shape
} /// namespace image
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_BRESENHAM_LINE_HPP 
