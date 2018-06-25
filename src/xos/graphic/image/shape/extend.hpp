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
///   Date: 6/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SHAPE_EXTEND_HPP
#define _XOS_GRAPHIC_IMAGE_SHAPE_EXTEND_HPP

#include "xos/graphic/image/shape/interface.hpp"
#include "xos/graphic/image/shape/item.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace shape {

///////////////////////////////////////////////////////////////////////
///  Class: extendt
///////////////////////////////////////////////////////////////////////
template
<class TImageInterface = image::interface, class TItem = shape::item,
 class TImplements = shape::interface, class TExtends = xos::base>

class _EXPORT_CLASS extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TItem tItem;
    typedef TImageInterface tImageInterface;

    extendt
    (tImageInterface& image,
     tSize width = 0, tSize height = 0,
     tImageInterface* selected_image = 0)
     : image_(image), selected_image_(selected_image),
       m_width(width), m_height(height) {
    }
    virtual ~extendt() {
    }

    virtual tImageInterface* select_as_image() {
        tImageInterface* prevImage = 0;
        prevImage = image_.select_image(this);
        return prevImage;
    }
    virtual tImageInterface* set_as_image() {
        tImageInterface* prevImage = 0;
        prevImage = image_.set_image(this);
        return prevImage;
    }

    virtual tImageInterface* set_image(tImageInterface* image) {
        tImageInterface* prevImage = this->image();
        selected_image_ = image;
        return prevImage;
    }
    virtual tImageInterface* image() const {
        tImageInterface* image = 0;
        image = selected_image_;
        return image;
    }

    virtual eError set_size(tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        m_width = width;
        m_height = height;
        error = this->on_set_size(width, height);
        return error;
    }

    virtual tSize width() const {
        return m_width;
    }
    virtual tSize height() const {
        return m_height;
    }

protected:
    tItem item_;
    tImageInterface& image_;
    tImageInterface* selected_image_;
    tSize m_width, m_height;
};
typedef extendt<> extend;

} /// namespace shape
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SHAPE_EXTEND_HPP 
