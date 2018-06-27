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
///   File: midpoint_ellipse.hpp
///
/// Author: $author$
///   Date: 6/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_MIDPOINT_ELLIPSE_HPP
#define _XOS_GRAPHIC_IMAGE_MIDPOINT_ELLIPSE_HPP

#include "xos/graphic/image/midpoint_circle.hpp"

namespace xos {
namespace graphic {
namespace image {

typedef unsigned int eEllipseQuadrant;
enum {
    e_ELLIPSE_QUADRANT_ALL = e_CIRCLE_QUADRANT_ALL,

    e_ELLIPSE_QUADRANT_1 = e_CIRCLE_QUADRANT_1,
    e_ELLIPSE_QUADRANT_2 = e_CIRCLE_QUADRANT_2,
    e_ELLIPSE_QUADRANT_3 = e_CIRCLE_QUADRANT_3,
    e_ELLIPSE_QUADRANT_4 = e_CIRCLE_QUADRANT_4,
};

///////////////////////////////////////////////////////////////////////
/// Function: midpoint_ellipse_drawt
///////////////////////////////////////////////////////////////////////
template<class TImage, class TPixel, class TInt>

void midpoint_ellipse_drawt
(TImage &image, TPixel &pixel,
 TInt cx, TInt cy, TInt a, TInt b, eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
    TInt x = 0, y = 0, a2 = 0, b2 = 0, S = 0, T = 0;

    if ((1 == a) && (1 == b)) {
        image.plot(pixel, cx,cy);
    }
    else if ((1 == a) && (1 < b)) {
            image.fill(pixel, cx,cy-b+1, 1,b+b-1);
    }
    else if ((1 < a) && (1 == b)) {
            image.fill(pixel, cx-a+1,cy, a+a-1,1);
    }
    else if ((0 < --a) && (0 < --b)) {
        a2 = a*a;
        b2 = b*b;
        x = 0;
        y = b;
        S = a2*(1-2*b) + 2*b2;
        T = b2 - 2*a2*(2*b-1);

        image.ellipse_plot(pixel, a,b, cx,cy, x,y, q);

        do {
            if (S<0) {
                S += 2*b2*(2*x+3);
                T += 4*b2*(x+1);
                x++;
            }
            else if (T<0) {
                S += 2*b2*(2*x+3) - 4*a2*(y-1);
                T += 4*b2*(x+1) - 2*a2*(2*y-3);
                x++;
                y--;
            }
            else {
                S -= 4*a2*(y-1);
                T -= 2*a2*(2*y-3);
                y--;
            }

            image.ellipse_plot(pixel, a,b, cx,cy, x,y, q);
        } while (y>0);
    }
}

class _EXPORT_CLASS midpoint_ellipse;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_ellipset
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = base::extend,
 class TImageBaseInterface = base::interface,
 class TImage = TImageBaseInterface,
 class TPixel = TImageBaseInterface,
 class TExtends = TImageBase>

class _EXPORT_CLASS midpoint_ellipset: public TExtends {
public:
    typedef TExtends extends;

    typedef TImageBase tImageBase;
    typedef TImageBaseInterface tImageBaseInterface;
    typedef TImage tImage;
    typedef TPixel tPixel;

    midpoint_ellipset(tImage& image): extends(image) {
    }
    virtual ~midpoint_ellipset() {
    }

    virtual void ellipse_plot
    (tPixel &pixel, tInt a,tInt b, tInt cx,tInt cy, tInt x,tInt y,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        if (q != e_ELLIPSE_QUADRANT_ALL) {
            if (q & e_ELLIPSE_QUADRANT_1) {
                this->plot(pixel, cx + x, cy - y);
            }
            if (q & e_ELLIPSE_QUADRANT_2) {
                this->plot(pixel, cx + x, cy + y);
            }
            if (q & e_ELLIPSE_QUADRANT_3) {
                this->plot(pixel, cx - x, cy + y);
            }
            if (q & e_ELLIPSE_QUADRANT_4) {
                this->plot(pixel, cx - x, cy - y);
            }
        }
        else {
            this->plot(pixel, cx + x, cy + y);
            this->plot(pixel, cx - x, cy - y);
            this->plot(pixel, cx + x, cy - y);
            this->plot(pixel, cx - x, cy + y);
        }
    }
};

typedef midpoint_ellipset<> midpoint_ellipse_extends;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_ellipse
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS midpoint_ellipse: public midpoint_ellipse_extends {
public:
    typedef midpoint_ellipse_extends extends;

    midpoint_ellipse(tImage& image): extends(image) {
    }
    virtual ~midpoint_ellipse() {
    }

    virtual void plot_ellipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        midpoint_ellipse_drawt
        <extends, tPixel, tInt>(*this, pixel, cx,cy, a,b, q);
    }
};

class _EXPORT_CLASS filled_midpoint_ellipse;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_ellipset
///////////////////////////////////////////////////////////////////////
template
<class TMidpointEllipse = midpoint_ellipse,
 class TImageBaseInterface = base::interface,
 class TImage = TImageBaseInterface,
 class TPixel = TImageBaseInterface,
 class TExtends = TMidpointEllipse>

class _EXPORT_CLASS filled_midpoint_ellipset: public TExtends {
public:
    typedef TExtends extends;

    typedef TMidpointEllipse tMidpointEllipse;
    typedef TImageBaseInterface tImageBaseInterface;
    typedef TImage tImage;
    typedef TPixel tPixel;

    filled_midpoint_ellipset(tImage& image): extends(image) {
    }
    virtual ~filled_midpoint_ellipset() {
    }

    virtual void ellipse_plot
    (tPixel &pixel, tInt a,tInt b, tInt cx,tInt cy, tInt x,tInt y,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        if (q != e_ELLIPSE_QUADRANT_ALL) {
            if (q & e_ELLIPSE_QUADRANT_1) {
                this->fill(pixel, cx, cy - y, x+1, 1);
            }
            if (q & e_ELLIPSE_QUADRANT_2) {
                this->fill(pixel, cx, cy + y, x+1, 1);
            }
            if (q & e_ELLIPSE_QUADRANT_3) {
                this->fill(pixel, cx - x, cy + y, x+1, 1);
            }
            if (q & e_ELLIPSE_QUADRANT_4) {
                this->fill(pixel, cx - x, cy - y, x+1, 1);
            }
        } else {
            this->fill(pixel, cx - x, cy + y, x+x+1, 1);
            this->fill(pixel, cx - x, cy - y, x+x+1, 1);
        }
    }
};

typedef filled_midpoint_ellipset<> filled_midpoint_ellipse_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_ellipse
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_midpoint_ellipse: public filled_midpoint_ellipse_extends {
public:
    typedef filled_midpoint_ellipse_extends extends;

    filled_midpoint_ellipse(tImage& image): extends(image) {
    }
    virtual ~filled_midpoint_ellipse() {
    }

    virtual void plot_ellipse
    (tPixel &pixel, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        midpoint_ellipse_drawt
        <extends, tPixel, tInt>(*this, pixel, cx,cy, a,b, q);
    }
};

} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_MIDPOINT_ELLIPSE_HPP 
