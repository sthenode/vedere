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
#ifndef _XOS_GRAPHIC_IMAGE_SHAPE_MIDPOINT_ELLIPSE_HPP
#define _XOS_GRAPHIC_IMAGE_SHAPE_MIDPOINT_ELLIPSE_HPP

#include "xos/graphic/image/hollow_midpoint_ellipse.hpp"
#include "xos/graphic/image/midpoint_ellipse.hpp"
#include "xos/graphic/image/base/image.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace shape {

typedef image::midpoint_ellipset
<base::image, image::interface> midpoint_ellipse_extends;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_ellipse
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS midpoint_ellipse: public midpoint_ellipse_extends {
public:
    typedef midpoint_ellipse_extends extends;

    midpoint_ellipse(tImageInterface& image): extends(image) {
    }

    virtual void plot_ellipse
    (tImageInterface& image, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        midpoint_ellipse_drawt<extends, tPixel, tInt>(*this, image, cx,cy, a,b, q);
    }
    virtual void plot_circle
    (tImageInterface& image, tInt cx,tInt cy, tInt r,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        plot_ellipse(image, cx,cy, r,r, q);
    }
};

typedef image::filled_midpoint_ellipset
<midpoint_ellipse, image::interface> filled_midpoint_ellipse_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_ellipse
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_midpoint_ellipse
: public filled_midpoint_ellipse_extends {
public:
    typedef filled_midpoint_ellipse_extends extends;

    filled_midpoint_ellipse(tImageInterface& image): extends(image) {
    }

    virtual void plot_ellipse
    (tImageInterface& image, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        midpoint_ellipse_drawt<extends, tPixel, tInt>(*this, image, cx,cy, a,b, q);
    }
    virtual void plot_circle
    (tImageInterface& image, tInt cx,tInt cy, tInt r,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        plot_ellipse(image, cx,cy, r,r, q);
    }
};

typedef image::hollow_midpoint_ellipset
<midpoint_ellipse, image::interface> hollow_midpoint_ellipse_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_ellipse
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS hollow_midpoint_ellipse
: public hollow_midpoint_ellipse_extends {
public:
    typedef hollow_midpoint_ellipse_extends extends;

    hollow_midpoint_ellipse(tImageInterface& image): extends(image) {
    }

    virtual void plot_ellipse
    (tImageInterface& image, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        ellipse_start();
        midpoint_ellipse_drawt<extends, tPixel, tInt>(*this, image, cx,cy, a,b, q);
        ellipse_finish(image);
    }
    virtual void plot_circle
    (tImageInterface& image, tInt cx,tInt cy, tInt r,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        plot_ellipse(image, cx,cy, r,r, q);
    }
};

} /// namespace shape
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SHAPE_MIDPOINT_ELLIPSE_HPP 
