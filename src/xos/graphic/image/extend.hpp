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
///   File: extend.hpp
///
/// Author: $author$
///   Date: 6/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_EXTEND_HPP
#define _XOS_GRAPHIC_IMAGE_EXTEND_HPP

#include "xos/graphic/image/interface.hpp"
#include "xos/graphic/image/shape/bresenham_line.hpp"
#include "xos/graphic/image/shape/midpoint_circle.hpp"
#include "xos/graphic/image/shape/midpoint_ellipse.hpp"

namespace xos {
namespace graphic {
namespace image {

///////////////////////////////////////////////////////////////////////
///  Class: extendt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = interface, class TExtends = xos::base>

class _EXPORT_CLASS extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef implements tImageInterface;

    extendt(tImageInterface* image = 0): image_(image) {
    }
    virtual ~extendt() {
    }

    virtual eError plot(tImageInterface& image, tOffset x, tOffset y) {
        eError error = image.plot(x,y);
        return error;
    }
    virtual eError fill
    (tImageInterface& image, tOffset x, tOffset y, tSize w, tSize h) {
        eError error = image.fill(x,y, w,h);
        return error;
    }

    virtual eError plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            error = image->plot(x, y);
        }
        return error;
    }
    virtual eError fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            error = image->fill(x,y, w,h);
        }
        return error;
    }
    virtual eError draw(tOffset x, tOffset y, tOffset x2, tOffset y2) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            shape::bresenham_line line(*image);
            line.draw_line(*image, x,y, x2,y2);
        }
        return error;
    }

    virtual eError draw_circle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            shape::midpoint_circle circle(*image);
            circle.plot_circle(*image, x,y, r, o);
        }
        return error;
    }
    virtual eError fill_circle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            shape::filled_midpoint_circle circle(*image);
            circle.plot_circle(*image, x,y, r, o);
        }
        return error;
    }
    virtual eError hollow_circle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            shape::hollow_midpoint_circle circle(*image);
            circle.plot_circle(*image, x,y, r, o);
        }
        return error;
    }

    virtual eError draw_ellipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            shape::midpoint_ellipse ellipse(*image);
            ellipse.plot_ellipse(*image, x,y, w,h, q);
        }
        return error;
    }
    virtual eError fill_ellipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            shape::filled_midpoint_ellipse ellipse(*image);
            ellipse.plot_ellipse(*image, x,y, w,h, q);
        }
        return error;
    }
    virtual eError hollow_ellipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            shape::hollow_midpoint_ellipse ellipse(*image);
            ellipse.plot_ellipse(*image, x,y, w,h, q);
        }
        return error;
    }

    virtual tImageInterface* set_image(tImageInterface* image) {
        tImageInterface* prevImage = image_;
        image_ = image;
        return prevImage;
    }
    virtual tImageInterface* image() const {
        tImageInterface* image = image_;
        return image;
    }

protected:
    tImageInterface* image_;
};
typedef extendt<> extend;

} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_EXTEND_HPP 
