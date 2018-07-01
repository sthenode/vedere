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
///   Date: 6/28/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_SHAPE_INTERFACE_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_SHAPE_INTERFACE_HPP

#include "xos/graphic/image/shape/interface.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {
namespace shape {

///////////////////////////////////////////////////////////////////////
///  Class: interfacet
///////////////////////////////////////////////////////////////////////
template <class TImplements = image::shape::interface>

class _EXPORT_CLASS interfacet: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef interfacet<> interface;

} /// namespace shape
} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_SHAPE_INTERFACE_HPP 
