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
///   File: midpoint_circle.hpp
///
/// Author: $author$
///   Date: 6/22/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_MIDPOINT_CIRCLE_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_MIDPOINT_CIRCLE_HPP

#include "xos/graphic/surface/image/base.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace image {

typedef unsigned int eCircleOctant;
enum {
    e_CIRCLE_OCTANT_NONE = 0,

    e_CIRCLE_OCTANT_1 = (1 << 0),
    e_CIRCLE_OCTANT_2 = (1 << 1),
    e_CIRCLE_OCTANT_3 = (1 << 2),
    e_CIRCLE_OCTANT_4 = (1 << 3),
    e_CIRCLE_OCTANT_5 = (1 << 4),
    e_CIRCLE_OCTANT_6 = (1 << 5),
    e_CIRCLE_OCTANT_7 = (1 << 6),
    e_CIRCLE_OCTANT_8 = (1 << 7),

    e_CIRCLE_OCTANT_NEXT = (e_CIRCLE_OCTANT_8 << 1),
    e_CIRCLE_OCTANT_ALL  = (e_CIRCLE_OCTANT_NEXT-1)
};

typedef eCircleOctant eCircleQuadrant;
enum {
    e_CIRCLE_QUADRANT_ALL = e_CIRCLE_OCTANT_ALL,

    e_CIRCLE_QUADRANT_1 = (e_CIRCLE_OCTANT_1|e_CIRCLE_OCTANT_2),
    e_CIRCLE_QUADRANT_2 = (e_CIRCLE_OCTANT_3|e_CIRCLE_OCTANT_4),
    e_CIRCLE_QUADRANT_3 = (e_CIRCLE_OCTANT_5|e_CIRCLE_OCTANT_6),
    e_CIRCLE_QUADRANT_4 = (e_CIRCLE_OCTANT_7|e_CIRCLE_OCTANT_8),
};

///////////////////////////////////////////////////////////////////////
///  Function: midpoint_circle_drawt
///////////////////////////////////////////////////////////////////////
template
<class TImage, class TPixel, class TInt>

void midpoint_circle_drawt
(TImage &image, TPixel &pixel, 
 TInt cx, TInt cy, TInt r, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
    TInt x = 0, y = 0, d = 0;

    if (1 == r) {
        image.circle_plot(pixel, r, cx,cy, o);
    } else if (0 < (y = --r)) {
        d = 1-r;
        for (x = 0; x < y; x++) {
            image.circle_plot(pixel, r, cx,cy, x,y, o);
            if (d<0) {
                d += 2*x+3;
            } else {
                d += 2*(x-y)+5;
                --y;
            }
        }
        image.circle_plot(pixel, r, cx,cy, x,y, o);
    }
}

class _EXPORT_CLASS midpoint_circle;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_circlet
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = image::base,
 class TImageInterfaceBase = image::interface_base,
 class TImage = TImageInterfaceBase,
 class TPixel = TImageInterfaceBase,
 class TExtends = TImageBase>

class _EXPORT_CLASS midpoint_circlet: public TExtends {
public:
    typedef TExtends extends;

    typedef TImageInterfaceBase tImageInterfaceBase;
    typedef TImageBase tImageBase;
    typedef TImage tImage;
    typedef TPixel tPixel;

    midpoint_circlet(tImageInterfaceBase& image): extends(image) {
    }
    virtual ~midpoint_circlet() {
    }

    virtual void circle_plot
    (TPixel &pixel, tInt r,
     tInt cx,tInt cy, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        this->plot(pixel, cx, cy);
    }
    virtual void circle_plot
    (TPixel &pixel, tInt r, tInt cx,tInt cy,
     tInt x,tInt y, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        if (o != e_CIRCLE_OCTANT_ALL) {
            if (o & e_CIRCLE_OCTANT_8) this->plot(pixel, cx-x, cy-y);
            if (o & e_CIRCLE_OCTANT_1) this->plot(pixel, cx+x, cy-y);

            if (o & e_CIRCLE_OCTANT_7) this->plot(pixel, cx-y, cy-x);
            if (o & e_CIRCLE_OCTANT_2) this->plot(pixel, cx+y, cy-x);

            if (o & e_CIRCLE_OCTANT_6) this->plot(pixel, cx-y, cy+x);
            if (o & e_CIRCLE_OCTANT_3) this->plot(pixel, cx+y, cy+x);

            if (o & e_CIRCLE_OCTANT_5) this->plot(pixel, cx-x, cy+y);
            if (o & e_CIRCLE_OCTANT_4) this->plot(pixel, cx+x, cy+y);
        } else {
            this->plot(pixel, cx-x, cy-y);
            this->plot(pixel, cx+x, cy-y);

            this->plot(pixel, cx-y, cy-x);
            this->plot(pixel, cx+y, cy-x);

            this->plot(pixel, cx-y, cy+x);
            this->plot(pixel, cx+y, cy+x);

            this->plot(pixel, cx-x, cy+y);
            this->plot(pixel, cx+x, cy+y);
        }
    }
};

typedef midpoint_circlet<> midpoint_circle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_circle
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS midpoint_circle: public midpoint_circle_extends {
public:
    typedef midpoint_circle_extends extends;

    midpoint_circle(tImageInterfaceBase& image): extends(image) {
    }
    virtual ~midpoint_circle() {
    }

    virtual void plot_circle
    (tImageInterfaceBase &pixel, tInt cx,tInt cy,
     tInt r, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        midpoint_circle_drawt
        <extends, tImageInterfaceBase, tInt>(*this, pixel, cx,cy,r, o);
    }
};

class _EXPORT_CLASS filled_midpoint_circle;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_circlet
///////////////////////////////////////////////////////////////////////
template
<class TMidpointCircle = midpoint_circle,
 class TImageInterfaceBase = image::interface_base,
 class TImage = TImageInterfaceBase,
 class TPixel = TImageInterfaceBase,
 class TExtends = TMidpointCircle>

class _EXPORT_CLASS filled_midpoint_circlet: public TExtends {
public:
    typedef TExtends extends;

    typedef TMidpointCircle tMidpointCircle;
    typedef TImageInterfaceBase tImageInterfaceBase;
    typedef TImage tImage;
    typedef TPixel tPixel;

    filled_midpoint_circlet(tImageInterfaceBase& image): extends(image) {
    }
    virtual ~filled_midpoint_circlet() {
    }

    virtual void circle_plot
    (TPixel &pixel, tInt r,
     tInt cx,tInt cy, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        this->plot(pixel, cx, cy);
    }
    virtual void circle_plot
    (TPixel &pixel, tInt r, tInt cx,tInt cy,
     tInt x,tInt y, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        if (o != e_CIRCLE_OCTANT_ALL) {
            if ((o & e_CIRCLE_QUADRANT_4) == e_CIRCLE_QUADRANT_4) {
                this->fill(pixel, cx-x, cy-y, x+1, 1);
                this->fill(pixel, cx-y, cy-x, y+1, 1);
            }
            if ((o & e_CIRCLE_QUADRANT_1) == e_CIRCLE_QUADRANT_1) {
                this->fill(pixel, cx, cy-y, x+1, 1);
                this->fill(pixel, cx, cy-x, y+1, 1);
            }
            if ((o & e_CIRCLE_QUADRANT_3) == e_CIRCLE_QUADRANT_3) {
                this->fill(pixel, cx-y, cy+x, y+1, 1);
                this->fill(pixel, cx-x, cy+y, x+1, 1);
            }
            if ((o & e_CIRCLE_QUADRANT_2) == e_CIRCLE_QUADRANT_2) {
                this->fill(pixel, cx, cy+x, y+1, 1);
                this->fill(pixel, cx, cy+y, x+1, 1);
            }
        } else {
            if (1 > x) {
                this->plot(pixel, cx, cy-y);
            } else {
                this->fill(pixel, cx-x, cy-y, x+x+1, 1);
            }

            if (1 > y) {
                this->plot(pixel, cx, cy-x);
            } else {
                this->fill(pixel, cx-y, cy-x, y+y+1, 1);
            }

            if (1 > y) {
                this->plot(pixel, cx, cy+x);
            } else {
                this->fill(pixel, cx-y, cy+x, y+y+1, 1);
            }

            if (1 > x) {
                this->plot(pixel, cx, cy+y);
            } else {
                this->fill(pixel, cx-x, cy+y, x+x+1, 1);
            }
        }
    }
};

typedef filled_midpoint_circlet<> filled_midpoint_circle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_circle
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_midpoint_circle: public filled_midpoint_circle_extends {
public:
    typedef filled_midpoint_circle_extends extends;

    filled_midpoint_circle(tImageInterfaceBase& image): extends(image) {
    }
    virtual ~filled_midpoint_circle() {
    }

    virtual void plot_circle
    (tImageInterfaceBase &pixel, tInt cx,tInt cy,
     tInt r, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        midpoint_circle_drawt
        <extends, tImageInterfaceBase, tInt>(*this, pixel, cx,cy,r, o);
    }
};

} /// namespace image
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_MIDPOINT_CIRCLE_HPP 
