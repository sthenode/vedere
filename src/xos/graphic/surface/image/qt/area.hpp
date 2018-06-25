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
///   File: area.hpp
///
/// Author: $author$
///   Date: 6/23/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_QT_AREA_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_QT_AREA_HPP

#include "xos/graphic/surface/image/qt/context.hpp"
#include "xos/graphic/surface/image/extend.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace image {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: area_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = context_interface,
 class TImplements = image::interface>

class _EXPORT_CLASS area_interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TContextInterface tContextInterface;

    virtual tContextInterface& context() const = 0;
};
typedef area_interfacet<> area_interface;

///////////////////////////////////////////////////////////////////////
///  Class: areat
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = context_interface,
 class TImplements = area_interface, class TExtends = image::extend>

class _EXPORT_CLASS areat: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef implements tAreaInterface;
    typedef TContextInterface tContextInterface;

    areat(tContextInterface& context, tAreaInterface* area = 0)
    : extends(context, area), context_(context) {
    }
    virtual ~areat() {
    }

    virtual tContextInterface& context() const {
        return (tContextInterface&)context_;
    }

protected:
    tContextInterface& context_;
};
typedef areat<> area;

} /// namespace qt
} /// namespace image
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_QT_AREA_HPP 
