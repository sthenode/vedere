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
///   Date: 6/27/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SURFACE_PIXEL_INTERFACE_HPP
#define _XOS_GRAPHIC_IMAGE_SURFACE_PIXEL_INTERFACE_HPP

#include "xos/graphic/image/interface.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace surface {
namespace pixel {

///////////////////////////////////////////////////////////////////////
///  Class: interfacet
///////////////////////////////////////////////////////////////////////
template <class TImplements = implement_base>

class _EXPORT_CLASS interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    virtual byte_t rgb_axis_to_byte(tSize x) const {
        byte_t to = ((byte_t)x);
        return to;
    }
    virtual float rgb_axis_to_float(tSize x) const {
        float to = ((float)(x % rgb_axis_size()))/((float)(rgb_axis_size()));
        return to;
    }
    virtual double rgb_axis_to_double(tSize x) const {
        double to = ((double)(x % rgb_axis_size()))/((double)(rgb_axis_size()));
        return to;
    }
    virtual tSize rgb_axis_size() const {
        return vRGBAxisSize;
    }

    virtual tSize red() const {
        return 0;
    }
    virtual tSize green() const {
        return 0;
    }
    virtual tSize blue() const {
        return 0;
    }
    virtual tSize alpha() const {
        return 0;
    }
};
typedef interfacet<> interface;

} /// namespace pixel
} /// namespace surface
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SURFACE_PIXEL_INTERFACE_HPP 
