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
///   File: item.hpp
///
/// Author: $author$
///   Date: 6/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SHAPE_ITEM_HPP
#define _XOS_GRAPHIC_IMAGE_SHAPE_ITEM_HPP

#include "xos/graphic/image/shape/interface.hpp"
#include "xos/base/linked/item.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace shape {

class _EXPORT_CLASS item;
typedef linked::itemt<item> item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: item
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS item: public item_extends {
public:
    typedef item_extends extends;

    item(interface& shape): shape_(shape) {
    }
    virtual ~item() {
    }

    virtual interface& shape() const {
        return (interface&)shape_;
    }

protected:
    interface& shape_;
};

} /// namespace shape
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SHAPE_ITEM_HPP 
