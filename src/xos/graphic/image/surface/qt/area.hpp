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
///   Date: 6/29/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_QT_AREA_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_QT_AREA_HPP

#include "xos/graphic/image/surface/qt/context.hpp"
#include "xos/graphic/image/surface/area/extend.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: area_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TQContextInterface = context_interface,
 class TImplements = surface::area::interface>

class _EXPORT_CLASS area_interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TQContextInterface tQContextInterface;

    virtual tQContextInterface& surfaceQContext() const = 0;
};
typedef area_interfacet<> area_interface;

///////////////////////////////////////////////////////////////////////
///  Class: areat
///////////////////////////////////////////////////////////////////////
template
<class TQContextInterface = context_interface,
 class TImplements = area_interface, class TExtends = surface::area::extend>

class _EXPORT_CLASS areat: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef implements tQImageInterface;
    typedef TQContextInterface tQContextInterface;

    areat(tQContextInterface& context, tQImageInterface* image = 0)
    : extends(context, image), context_(context) {
    }
    virtual ~areat() {
    }

    virtual tQContextInterface& surfaceQContext() const {
        return (tQContextInterface&)context_;
    }

protected:
    tQContextInterface& context_;
};
typedef areat<> area;

} /// namespace qt
} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_QT_AREA_HPP 
