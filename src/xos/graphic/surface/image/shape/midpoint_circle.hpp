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
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_MIDPOINT_CIRCLE_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_MIDPOINT_CIRCLE_HPP

#include "xos/graphic/surface/image/shape/base.hpp"
#include "xos/graphic/surface/image/midpoint_circle.hpp"
#include "xos/graphic/surface/image/hollow_midpoint_circle.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace image {
namespace shape {

typedef image::midpoint_circlet
<shape::base, image::interface> midpoint_circle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_circle
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS midpoint_circle: public midpoint_circle_extends {
public:
    typedef midpoint_circle_extends extends;

    midpoint_circle(tImageInterface& image): extends(image) {
    }

    virtual void plot_circle
    (tImageInterface &image, tInt cx,tInt cy, tInt r,
     eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        midpoint_circle_drawt<extends, tPixel, tInt>(*this, image, cx,cy,r, o);
    }
};

typedef image::filled_midpoint_circlet
<shape::base, image::interface> filled_midpoint_circle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_circle
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_midpoint_circle
: public filled_midpoint_circle_extends {
public:
    typedef filled_midpoint_circle_extends extends;

    filled_midpoint_circle(tImageInterface& image): extends(image) {
    }

    virtual void plot_circle
    (tImageInterface &image, tInt cx,tInt cy, tInt r,
     eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        midpoint_circle_drawt<extends, tPixel, tInt>(*this, image, cx,cy,r, o);
    }
};

typedef image::hollow_midpoint_circlet
<shape::base, image::interface> hollow_midpoint_circle_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_circle
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS hollow_midpoint_circle
: public hollow_midpoint_circle_extends {
public:
    typedef hollow_midpoint_circle_extends extends;

    hollow_midpoint_circle(tImageInterface& image): extends(image) {
    }

    virtual void plot_circle
    (tImageInterface &image, tInt cx,tInt cy, tInt r,
     eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        circle_start();
        midpoint_circle_drawt<extends, tPixel, tInt>(*this, image, cx,cy,r, o);
        circle_finish(image);
    }
};

} /// namespace shape
} /// namespace image
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_SHAPE_MIDPOINT_CIRCLE_HPP 
