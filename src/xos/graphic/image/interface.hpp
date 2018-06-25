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
///   File: interface.hpp
///
/// Author: $author$
///   Date: 6/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_INTERFACE_HPP
#define _XOS_GRAPHIC_IMAGE_INTERFACE_HPP

#include "xos/graphic/image/base/interface.hpp"

namespace xos {
namespace graphic {
namespace image {

///////////////////////////////////////////////////////////////////////
///  Class: interfacet
///////////////////////////////////////////////////////////////////////
template <class TImplements = base::interface>

class _EXPORT_CLASS interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef interfacet tImageInterface;

    virtual eError plot(tImageInterface& image, tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        tImageInterface* prevImage = select_image(&image);
        error = plot(x,y);
        select_as_image(prevImage);
        return error;
    }
    virtual eError fill
    (tImageInterface& image, tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        tImageInterface* prevImage = select_image(&image);
        error = fill(x,y, w,h);
        select_as_image(prevImage);
        return error;
    }

    virtual eError plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError draw(tOffset x, tOffset y, tOffset x2, tOffset y2) {
        eError error = e_ERROR_NONE;
        return error;
    }

    virtual eError draw_circle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError fill_circle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError hollow_circle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }

    virtual eError draw_ellipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError fill_ellipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError hollow_ellipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }

    virtual tImageInterface* create_color
    (tSize r, tSize g, tSize b, tSize a = 0, tSize w = 1, tSize h = 1) {
        tImageInterface* image = 0;
        return image;
    }
    virtual eError destroy(tImageInterface& image) {
        eError error = e_ERROR_NONE;
        return error;
    }

    virtual tImageInterface* select_as_image(tImageInterface* image) {
        tImageInterface* prevImage = 0;
        if (image) {
            prevImage = image->select_as_image();
        } else {
            prevImage = set_image(image);
        }
        return prevImage;
    }
    virtual tImageInterface* select_as_image() {
        tImageInterface* prevImage = this->image();
        return prevImage;
    }

    virtual tImageInterface* set_as_image(tImageInterface* image) {
        tImageInterface* prevImage = 0;
        if (image) {
            prevImage = image->set_as_image();
        } else {
            prevImage = this->image();
        }
        return prevImage;
    }
    virtual tImageInterface* set_as_image() {
        tImageInterface* prevImage = this->image();
        return prevImage;
    }

    virtual tImageInterface* select_image(tImageInterface* image) {
        tImageInterface* prevImage = this->image();
        set_image(image);
        return prevImage;
    }
    virtual tImageInterface* set_image(tImageInterface* image) {
        tImageInterface* prevImage = 0;
        return prevImage;
    }
    virtual tImageInterface* image() const {
        tImageInterface* image = 0;
        return image;
    }
};
typedef interfacet<> interface;

} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_INTERFACE_HPP 
