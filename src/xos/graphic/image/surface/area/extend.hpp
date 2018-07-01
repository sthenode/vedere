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
///   Date: 6/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_AREA_EXTEND_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_AREA_EXTEND_HPP

#include "xos/graphic/image/surface/area/interface.hpp"
#include "xos/graphic/image/extend.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {
namespace area {

///////////////////////////////////////////////////////////////////////
///  Class: extendt
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = context::interface,
 class TImplements = interface, class TExtends = image::extend>

class _EXPORT_CLASS extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TContextInterface tContextInterface;
    typedef implements tImageInterface;

    extendt(tContextInterface& context, tImageInterface* image)
    : extends(image), context_(context) {
    }
    extendt(tContextInterface& context): context_(context) {
    }
    virtual ~extendt() {
    }

    virtual tContextInterface& context_interface() const {
        return (tContextInterface&)context_;
    }

protected:
    tContextInterface& context_;
};
typedef extendt<> extend;

} /// namespace area
} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_AREA_EXTEND_HPP 
