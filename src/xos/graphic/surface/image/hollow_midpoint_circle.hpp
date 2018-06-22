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
///   File: hollow_midpoint_circle.hpp
///
/// Author: $author$
///   Date: 6/22/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_HOLLOW_MIDPOINT_CIRCLE_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_HOLLOW_MIDPOINT_CIRCLE_HPP

#include "xos/graphic/surface/image/midpoint_circle.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace image {

class _EXPORT_CLASS hollow_midpoint_circle;
///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_circlet
///////////////////////////////////////////////////////////////////////
template
<class TMidpointCircle = midpoint_circle,
 class TImageInterfaceBase = image::interface_base,
 class TImage = TImageInterfaceBase,
 class TPixel = TImageInterfaceBase,
 class TExtends = TMidpointCircle>

class _EXPORT_CLASS hollow_midpoint_circlet: public TExtends {
public:
    typedef TExtends extends;

    typedef TMidpointCircle tMidpointCircle;
    typedef TImageInterfaceBase tImageInterfaceBase;
    typedef TImage tImage;
    typedef TPixel tPixel;

    hollow_midpoint_circlet(tImage& image)
    : extends(image),
      m_x1(0),m_y1(0),m_w1(0),
      m_x2(0),m_y2(0),m_w2(0),
      m_x3(0),m_y3(0),m_w3(0),
      m_x4(0),m_y4(0),m_w4(0),
      m_x11(0),m_y11(0),m_w11(0),
      m_x12(0),m_y12(0),m_w12(0),
      m_x13(0),m_y13(0),m_w13(0),
      m_x14(0),m_y14(0),m_w14(0) {
    }
    virtual ~hollow_midpoint_circlet() {
    }

    virtual void circle_plot
    (TPixel &pixel, tInt r,
     tInt cx,tInt cy, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
    }
    virtual void circle_plot
    (TPixel &pixel, tInt r, tInt cx,tInt cy,
     tInt x,tInt y, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        if (o != e_CIRCLE_OCTANT_ALL) {
            if ((o & e_CIRCLE_OCTANT_1) == e_CIRCLE_OCTANT_1) {
                circle_hollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, r-x);
            }
            if ((o & e_CIRCLE_OCTANT_2) == e_CIRCLE_OCTANT_2) {
                circle_hollow(pixel, m_x11,m_y11,m_w11, cx+y+1, cy - x, r-y);
            }
            if ((o & e_CIRCLE_OCTANT_3) == e_CIRCLE_OCTANT_3) {
                circle_hollow(pixel, m_x12,m_y12,m_w12, cx+y+1, cy + x, r-y);
            }
            if ((o & e_CIRCLE_OCTANT_4) == e_CIRCLE_OCTANT_4) {
                circle_hollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, r-x);
            }
            if ((o & e_CIRCLE_OCTANT_5) == e_CIRCLE_OCTANT_5) {
                circle_hollow(pixel, m_x3,m_y3,m_w3, cx-r, cy + y, r-x);
            }
            if ((o & e_CIRCLE_OCTANT_6) == e_CIRCLE_OCTANT_6) {
                circle_hollow(pixel, m_x13,m_y13,m_w13, cx-r, cy + x, r-y);
            }
            if ((o & e_CIRCLE_OCTANT_7) == e_CIRCLE_OCTANT_7) {
                circle_hollow(pixel, m_x14,m_y14,m_w14, cx-r, cy - x, r-y);
            }
            if ((o & e_CIRCLE_OCTANT_8) == e_CIRCLE_OCTANT_8) {
                circle_hollow(pixel, m_x4,m_y4,m_w4, cx-r, cy - y, r-x);
            }
        } else {
            circle_hollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, r-x);
            circle_hollow(pixel, m_x11,m_y11,m_w11, cx+y+1, cy - x, r-y);

            circle_hollow(pixel, m_x12,m_y12,m_w12, cx+y+1, cy + x, r-y);
            circle_hollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, r-x);

            circle_hollow(pixel, m_x3,m_y3,m_w3, cx-r, cy + y, r-x);
            circle_hollow(pixel, m_x13,m_y13,m_w13, cx-r, cy + x, r-y);

            circle_hollow(pixel, m_x14,m_y14,m_w14, cx-r, cy - x, r-y);
            circle_hollow(pixel, m_x4,m_y4,m_w4, cx-r, cy - y, r-x);
        }
    }
    virtual void circle_hollow
    (tPixel &pixel, tInt& xQ,tInt& yQ, tInt& wQ, tInt x,tInt y, tInt w) {
        if ((0 < wQ) && (yQ != y)) {
            this->fill(pixel, xQ,yQ, wQ,1);
        }
        xQ = x;
        yQ = y;
        wQ = w;
    }
    virtual void circle_start() {
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
        m_x11 = (m_y11 = (m_w11 = 0));
        m_x12 = (m_y12 = (m_w12 = 0));
        m_x13 = (m_y13 = (m_w13 = 0));
        m_x14 = (m_y14 = (m_w14 = 0));
    }
    virtual void circle_finish(tPixel &pixel) {
        if ((0 < m_w1)) {
            this->fill(pixel, m_x1,m_y1, m_w1,1);
        }
        if ((0 < m_w11)) {
            this->fill(pixel, m_x11,m_y11, m_w11,1);
        }
        if ((0 < m_w2)) {
            this->fill(pixel, m_x2,m_y2, m_w2,1);
        }
        if ((0 < m_w12)) {
            this->fill(pixel, m_x12,m_y12, m_w12,1);
        }
        if ((0 < m_w3)) {
            this->fill(pixel, m_x3,m_y3, m_w3,1);
        }
        if ((0 < m_w13)) {
            this->fill(pixel, m_x13,m_y13, m_w13,1);
        }
        if ((0 < m_w4)) {
            this->fill(pixel, m_x4,m_y4, m_w4,1);
        }
        if ((0 < m_w14)) {
            this->fill(pixel, m_x14,m_y14, m_w14,1);
        }
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
        m_x11 = (m_y11 = (m_w11 = 0));
        m_x12 = (m_y12 = (m_w12 = 0));
        m_x13 = (m_y13 = (m_w13 = 0));
        m_x14 = (m_y14 = (m_w14 = 0));
    }

protected:
    tInt m_x1,m_y1,m_w1;
    tInt m_x2,m_y2,m_w2;
    tInt m_x3,m_y3,m_w3;
    tInt m_x4,m_y4,m_w4;
    tInt m_x11,m_y11,m_w11;
    tInt m_x12,m_y12,m_w12;
    tInt m_x13,m_y13,m_w13;
    tInt m_x14,m_y14,m_w14;
};

typedef hollow_midpoint_circlet<> hollow_midpoint_circle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_circle
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS hollow_midpoint_circle: public hollow_midpoint_circle_extends {
public:
    typedef hollow_midpoint_circle_extends extends;

    hollow_midpoint_circle(tImageInterfaceBase& image): extends(image) {
    }
    virtual ~hollow_midpoint_circle() {
    }

    virtual void plot_circle
    (tImageInterfaceBase &pixel, tInt cx,tInt cy,
     tInt r, eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        circle_start();
        midpoint_circle_drawt
        <extends, tImageInterfaceBase, tInt>(*this, pixel, cx,cy,r, o);
        circle_finish(pixel);
    }
};

} /// namespace image
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_HOLLOW_MIDPOINT_CIRCLE_HPP 
