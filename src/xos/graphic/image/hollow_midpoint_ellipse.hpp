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
///   File: hollow_midpoint_ellipse.hpp
///
/// Author: $author$
///   Date: 6/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_HOLLOW_MIDPOINT_ELLIPSE_HPP
#define _XOS_GRAPHIC_IMAGE_HOLLOW_MIDPOINT_ELLIPSE_HPP

#include "xos/graphic/image/midpoint_ellipse.hpp"

namespace xos {
namespace graphic {
namespace image {

class _EXPORT_CLASS hollow_midpoint_ellipse;
///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_ellipset
///////////////////////////////////////////////////////////////////////
template
<class TMidpointEllipse = midpoint_ellipse,
 class TImageBaseInterface = base::interface,
 class TImage = TImageBaseInterface,
 class TPixel = TImageBaseInterface,
 class TExtends = TMidpointEllipse>

class _EXPORT_CLASS hollow_midpoint_ellipset: public TExtends {
public:
    typedef TExtends extends;

    typedef TMidpointEllipse tMidpointEllipse;
    typedef TImageBaseInterface tImageBaseInterface;
    typedef TImage tImage;
    typedef TPixel tPixel;

    hollow_midpoint_ellipset(tImage& image)
    : extends(image),
      m_x1(0),m_y1(0),m_w1(0),
      m_x2(0),m_y2(0),m_w2(0),
      m_x3(0),m_y3(0),m_w3(0),
      m_x4(0),m_y4(0),m_w4(0) {
    }
    virtual ~hollow_midpoint_ellipset() {
    }

    virtual void ellipse_plot
    (tPixel &pixel, tInt a,tInt b, tInt cx,tInt cy, tInt x,tInt y,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        if (q != e_ELLIPSE_QUADRANT_ALL) {
            if (q & e_ELLIPSE_QUADRANT_1) {
                ellipse_hollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, a-x);
            }
            if (q & e_ELLIPSE_QUADRANT_2) {
                ellipse_hollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, a-x);
            }
            if (q & e_ELLIPSE_QUADRANT_3) {
                ellipse_hollow(pixel, m_x3,m_y3,m_w3, cx-a, cy + y, a-x);
            }
            if (q & e_ELLIPSE_QUADRANT_4) {
                ellipse_hollow(pixel, m_x4,m_y4,m_w4, cx-a, cy - y, a-x);
            }
        } else {
            ellipse_hollow(pixel, m_x1,m_y1,m_w1, cx+x+1, cy - y, a-x);
            ellipse_hollow(pixel, m_x2,m_y2,m_w2, cx+x+1, cy + y, a-x);
            ellipse_hollow(pixel, m_x3,m_y3,m_w3, cx-a, cy + y, a-x);
            ellipse_hollow(pixel, m_x4,m_y4,m_w4, cx-a, cy - y, a-x);
        }
    }
    virtual void ellipse_hollow
    (tPixel &pixel, tInt& xQ,tInt& yQ, tInt& wQ, tInt x,tInt y, tInt w) {
        if ((0 < wQ) && (yQ != y)) {
            this->fill(pixel, xQ,yQ, wQ,1);
        }
        xQ = x;
        yQ = y;
        wQ = w;
    }
    virtual void ellipse_start() {
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
    }
    virtual void ellipse_finish(tPixel &pixel) {
        if ((0 < m_w1)) {
            this->fill(pixel, m_x1,m_y1, m_w1,1);
        }
        if ((0 < m_w2)) {
            this->fill(pixel, m_x2,m_y2, m_w2,1);
        }
        if ((0 < m_w3)) {
            this->fill(pixel, m_x3,m_y3, m_w3,1);
        }
        if ((0 < m_w4)) {
            this->fill(pixel, m_x4,m_y4, m_w4,1);
        }
        m_x1 = (m_y1 = (m_w1 = 0));
        m_x2 = (m_y2 = (m_w2 = 0));
        m_x3 = (m_y3 = (m_w3 = 0));
        m_x4 = (m_y4 = (m_w4 = 0));
    }

protected:
    tInt m_x1,m_y1,m_w1;
    tInt m_x2,m_y2,m_w2;
    tInt m_x3,m_y3,m_w3;
    tInt m_x4,m_y4,m_w4;
};

typedef hollow_midpoint_ellipset<> hollow_midpoint_ellipse_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_ellipse
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS hollow_midpoint_ellipse: public hollow_midpoint_ellipse_extends {
public:
    typedef hollow_midpoint_ellipse_extends extends;

    hollow_midpoint_ellipse(tImage& image): extends(image) {
    }
    virtual ~hollow_midpoint_ellipse() {
    }

    virtual void plot_ellipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        ellipse_start();
        midpoint_ellipse_drawt<extends, tPixel, tInt>(*this, pixel, cx,cy, a,b, q);
        ellipse_finish(pixel);
    }
};

} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_HOLLOW_MIDPOINT_ELLIPSE_HPP 
