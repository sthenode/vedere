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
///   File: main.hpp
///
/// Author: $author$
///   Date: 7/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_MAIN_HPP
#define _XOS_APP_GUI_VEDERE_MAIN_HPP

#include "xos/app/gui/vedere/main_opt.hpp"
#include "xos/app/gui/vedere/image/format.hpp"
#include "xos/app/gui/vedere/image/transform.hpp"
#include "xos/fs/path.hpp"

#define XOS_APP_GUI_VEDERE_MAIN_WINDOW_WIDTH 500
#define XOS_APP_GUI_VEDERE_MAIN_WINDOW_HEIGHT 250

namespace xos {
namespace app {
namespace gui {
namespace vedere {

///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_opt::implements, class TExtends = main_opt>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    
    maint()
    : main_window_width_(XOS_APP_GUI_VEDERE_MAIN_WINDOW_WIDTH),
      main_window_height_(XOS_APP_GUI_VEDERE_MAIN_WINDOW_HEIGHT),
      image_width_(0), image_height_(0), image_depth_(0),
      image_format_(image::format_none),
      image_transform_(image::transform_none) {
    }
    virtual ~maint() {
    }

protected:
    virtual int on_image_format_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* to = optarg;
        if ((to) && (to[0])) {
            LOG_DEBUG("set image_format = \"" << to << "\"...");
            if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_RAW_OPTARG_C))
                || (!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_RAW_OPTARG_S))) {
                LOG_DEBUG("set_image_format(image::format_raw)...");
                set_image_format(image::format_raw);
            } else {
                if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_JPEG_OPTARG_C))
                    || (!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_JPEG_OPTARG_S))) {
                    LOG_DEBUG("set_image_format(image::format_jpeg)...");
                    set_image_format(image::format_jpeg);
                } else {
                    if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_TIFF_OPTARG_C))
                        || (!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_TIFF_OPTARG_S))) {
                        LOG_DEBUG("set_image_format(image::format_tiff)...");
                        set_image_format(image::format_tiff);
                    } else {
                        if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_PNG_OPTARG_C))
                            || (!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_PNG_OPTARG_S))) {
                            LOG_DEBUG("set_image_format(image::format_pmg)...");
                            set_image_format(image::format_png);
                        } else {
                            if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_GIF_OPTARG_C))
                                || (!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_GIF_OPTARG_S))) {
                                LOG_DEBUG("set_image_format(image::format_gif)...");
                                set_image_format(image::format_gif);
                            } else {
                                if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_BMP_OPTARG_C))
                                    || (!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_BMP_OPTARG_S))) {
                                    LOG_DEBUG("set_image_format(image::format_bmp)...");
                                    set_image_format(image::format_bmp);
                                } else {
                                    if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_DNG_OPTARG_C))
                                        || (!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_DNG_OPTARG_S))) {
                                        LOG_DEBUG("set_image_format(image::format_dng)...");
                                        set_image_format(image::format_dng);
                                    } else {
                                        err = this->on_invalid_option_arg
                                        (optval, optarg, optname, optind, argc, argv, env);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return err;
    }
    virtual int on_image_transform_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* to = optarg;
        if ((to) && (to[0])) {
            LOG_DEBUG("set image_transform = \"" << to << "\"...");
            if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_FAST_OPTARG_C))
                || (!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_FAST_OPTARG_S))) {
                LOG_DEBUG("set_image_transform(image::transform_fast)...");
                set_image_transform(image::transform_fast);
            } else {
                if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_SMOOTH_OPTARG_C))
                    || (!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_SMOOTH_OPTARG_S))) {
                    LOG_DEBUG("set_image_transform(image::transform_smooth)...");
                    set_image_transform(image::transform_smooth);
                } else {
                    err = this->on_invalid_option_arg
                    (optval, optarg, optname, optind, argc, argv, env);
                }
            }
        }
        return err;
    }
    virtual int on_image_width_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* to = optarg;
        if ((to) && (to[0])) {
            LOG_DEBUG("set image_width = \"" << to << "\"...");
            image_width_ = chars_t::to_unsigned(to);
        }
        return err;
    }
    virtual int on_image_height_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* to = optarg;
        if ((to) && (to[0])) {
            LOG_DEBUG("set image_height = \"" << to << "\"...");
            image_height_ = chars_t::to_unsigned(to);
        }
        return err;
    }
    virtual int on_image_depth_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* to = optarg;
        if ((to) && (to[0])) {
            LOG_DEBUG("set image_depth = \"" << to << "\"...");
            image_depth_ = chars_t::to_unsigned(to);
        }
        return err;
    }

    virtual int on_file_argument_image_format
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        fs::path path(arg);
        const char* to = path.file_extension().chars();
        if ((to) && (to[0])) {
            if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_DNG_OPTARG_S))) {
                LOG_DEBUG("set_image_format(image::format_dng)...");
                set_image_format(image::format_dng);
            } else {
                if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_PNG_OPTARG_S))) {
                    LOG_DEBUG("set_image_format(image::format_png)...");
                    set_image_format(image::format_png);
                } else {
                    if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_JPEG_OPTARG_S))) {
                        LOG_DEBUG("set_image_format(image::format_jpeg)...");
                        set_image_format(image::format_jpeg);
                    } else {
                        if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_TIFF_OPTARG_S))) {
                            LOG_DEBUG("set_image_format(image::format_tiff)...");
                            set_image_format(image::format_tiff);
                        } else {
                            if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_GIF_OPTARG_S))) {
                                LOG_DEBUG("set_image_format(image::format_gif)...");
                                set_image_format(image::format_gif);
                            } else {
                                if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_BMP_OPTARG_S))) {
                                    LOG_DEBUG("set_image_format(image::format_bmp)...");
                                    set_image_format(image::format_bmp);
                                } else {
                                    if ((!chars_t::compare(to, XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_RAW_OPTARG_S))) {
                                        LOG_DEBUG("set_image_format(image::format_raw)...");
                                        set_image_format(image::format_raw);
                                    } else {
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    virtual int on_file_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* to = arg;
        if ((to) && (to[0])) {
            image::format_t format = image_format();
            LOG_DEBUG("set image_file = \"" << to << "\"...");
            image_file_.assign(to);
            if (image::format_none == (format)) {
                err = on_file_argument_image_format(arg, argind, argc, argv, env);
            }
        }
        return err;
    }

    virtual size_t set_image_width(size_t to) {
        image_width_ = to;
        return image_width_;
    }
    virtual size_t image_width() const {
        return image_width_;
    }

    virtual size_t set_image_height(size_t to) {
        image_height_ = to;
        return image_height_;
    }
    virtual size_t image_height() const {
        return image_height_;
    }

    virtual size_t set_image_depth(size_t to) {
        image_depth_ = to;
        return image_depth_;
    }
    virtual size_t image_depth() const {
        return image_depth_;
    }

    virtual image::format_t set_image_format(image::format_t to) {
        image_format_ = to;
        return image_format_;
    }
    virtual image::format_t image_format() const {
        return image_format_;
    }

    virtual image::transform_t set_image_transform(image::transform_t to) {
        image_transform_ = to;
        return image_transform_;
    }
    virtual image::transform_t image_transform() const {
        return image_transform_;
    }

    virtual const char_t* set_image_file(const char_t* to) {
        image_file_.assign(to);
        return image_file();
    }
    virtual const char_t* image_file() const {
        return image_file_.chars();
    }
    
    virtual size_t main_window_width() const {
        return main_window_width_;
    }
    virtual size_t main_window_height() const {
        return main_window_height_;
    }

protected:
    size_t main_window_width_, main_window_height_,
           image_width_, image_height_, image_depth_;
    image::format_t image_format_;
    image::transform_t image_transform_;
    string_t image_file_;
};
typedef maint<> main;

} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_MAIN_HPP 
