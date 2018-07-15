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
///   File: renderer.hpp
///
/// Author: $author$
///   Date: 7/14/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_GENERIC_VEDERE_RENDERER_HPP
#define _XOS_APP_GUI_GENERIC_VEDERE_RENDERER_HPP

#include "xos/app/gui/generic/vedere/image/renderer.hpp"
#include "xos/app/gui/vedere/renderer_extend.hpp"

namespace xos {
namespace app {
namespace gui {
namespace generic {
namespace vedere {

typedef implement_base renderer_implements;
typedef gui::vedere::renderer_extendt
<image::renderer::image_format_t,
 image::renderer::image_format_none, image::renderer> renderer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: renderer
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS renderer
: virtual public renderer_implements, public renderer_extends {
public:
    typedef renderer_implements implements;
    typedef renderer_extends extends;

    renderer() {
    }
    virtual ~renderer() {
    }

    virtual bool init(xos::gui::generic::image::context_t context, size_t width, size_t height) {
        return image_renderer_.init(context, width,height);
    }
    virtual bool finish() {
        return image_renderer_.finish();
    }

    virtual bool resize(size_t width, size_t height) {
        return image_renderer_.resize(width, height);
    }

    virtual image_renderer_t* image_renderer(const image_format_t& image_format) const {
        if (!(image_format != image_renderer_.image_format())) {
            return ((image_renderer_t*)&image_renderer_);
        }
        return 0;
    }

protected:
    image_renderer_t image_renderer_;
};

} /// namespace vedere
} /// namespace generic
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_GENERIC_VEDERE_RENDERER_HPP 
