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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 7/5/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_VEDERE_MAIN_OPT_HPP
#define _XOS_APP_GUI_VEDERE_MAIN_OPT_HPP

#include "xos/gui/main.hpp"

#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPT "image-format"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTARG_RESULT 0
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_RAW_OPTARG_C "r"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_RAW_OPTARG_S "raw"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_DNG_OPTARG_C "d"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_DNG_OPTARG_S "dng"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_JPEG_OPTARG_C "j"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_JPEG_OPTARG_S "jpeg"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_TIFF_OPTARG_C "t"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_TIFF_OPTARG_S "tiff"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_GIF_OPTARG_C "g"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_GIF_OPTARG_S "gif"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_PNG_OPTARG_C "p"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_PNG_OPTARG_S "png"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_BMP_OPTARG_C "b"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_BMP_OPTARG_S "bmp"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTARG \
    "{" "(" XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_RAW_OPTARG_C ")" \
            XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_RAW_OPTARG_S " | " \
        "(" XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_DNG_OPTARG_C ")" \
            XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_DNG_OPTARG_S " | " \
        "(" XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_PNG_OPTARG_C ")" \
            XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_PNG_OPTARG_S " | " \
        "(" XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_JPEG_OPTARG_C ")" \
            XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_JPEG_OPTARG_S " | " \
        "(" XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_TIFF_OPTARG_C ")" \
            XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_TIFF_OPTARG_S " | " \
        "(" XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_GIF_OPTARG_C ")" \
            XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_GIF_OPTARG_S " | " \
        "(" XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_BMP_OPTARG_C ")" \
            XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_BMP_OPTARG_S "}"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTUSE ""
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTVAL_S "t:"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTVAL_C 't'
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTION \
   {XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTARG_REQUIRED, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTARG_RESULT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTVAL_C}, \

#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPT "image-transform"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTARG_RESULT 0
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_FAST_OPTARG_C "f"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_FAST_OPTARG_S "fast"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_SMOOTH_OPTARG_C "s"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_SMOOTH_OPTARG_S "smooth"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTARG \
    "{" "(" XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_FAST_OPTARG_C ")" \
            XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_FAST_OPTARG_S " | " \
        "(" XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_SMOOTH_OPTARG_C ")" \
            XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_SMOOTH_OPTARG_S "}"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTUSE ""
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTVAL_S "m:"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTVAL_C 'm'
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTION \
   {XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTARG_REQUIRED, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTARG_RESULT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTVAL_C}, \

#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPT "image-width"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTARG_RESULT 0
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTARG "number"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTUSE "Image width in pixels"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTVAL_S "x:"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTVAL_C 'x'
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTION \
   {XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTARG_REQUIRED, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTARG_RESULT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTVAL_C}, \

#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPT "image-height"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTARG_RESULT 0
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTARG "number"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTUSE "Image height in pixels"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTVAL_S "y:"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTVAL_C 'y'
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTION \
   {XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTARG_REQUIRED, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTARG_RESULT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTVAL_C}, \

#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPT "image-depth"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTARG_RESULT 0
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTARG "number"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTUSE "Image depth in bits"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTVAL_S "z:"
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTVAL_C 'z'
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTION \
   {XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTARG_REQUIRED, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTARG_RESULT, \
    XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTVAL_C}, \

#define XOS_APP_GUI_VEDERE_MAIN_OPTIONS_CHARS \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTVAL_S \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTVAL_S \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTVAL_S \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTVAL_S \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTVAL_S \
   CRONO_CONSOLE_MAIN_OPTIONS_CHARS

#define XOS_APP_GUI_VEDERE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTION \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTION \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTION \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTION \
   XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTION \
   CRONO_CONSOLE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_GUI_VEDERE_MAIN_ARGS "[imagefile]"
#define XOS_APP_GUI_VEDERE_MAIN_ARGV "[imagefile] Image filename",
#define XOS_APP_GUI_VEDERE_MAIN_IMAGE_FILE_ARG 0

namespace xos {
namespace app {
namespace gui {
namespace vedere {

///////////////////////////////////////////////////////////////////////
///  Class: main_optt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = xos::gui::main::implements, class TExtends = xos::gui::main>

class _EXPORT_CLASS main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    main_optt() {
    }
    virtual ~main_optt() {
    }

protected:
    virtual int on_image_format_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_image_transform_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_image_width_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_image_height_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_image_depth_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }

    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTVAL_C:
            err = on_image_format_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTVAL_C:
            err = on_image_transform_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTVAL_C:
            err = on_image_width_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTVAL_C:
            err = on_image_height_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTVAL_C:
            err = on_image_depth_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTVAL_C:
            optarg = XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTARG;
            chars = XOS_APP_GUI_VEDERE_MAIN_IMAGE_FORMAT_OPTUSE;
            break;
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTVAL_C:
            optarg = XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTARG;
            chars = XOS_APP_GUI_VEDERE_MAIN_IMAGE_TRANSFORM_OPTUSE;
            break;
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTVAL_C:
            optarg = XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTARG;
            chars = XOS_APP_GUI_VEDERE_MAIN_IMAGE_WIDTH_OPTUSE;
            break;
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTVAL_C:
            optarg = XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTARG;
            chars = XOS_APP_GUI_VEDERE_MAIN_IMAGE_HEIGHT_OPTUSE;
            break;
        case XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTVAL_C:
            optarg = XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTARG;
            chars = XOS_APP_GUI_VEDERE_MAIN_IMAGE_DEPTH_OPTUSE;
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = XOS_APP_GUI_VEDERE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_GUI_VEDERE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    virtual int on_file_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!argind) {
            err = on_file_argument(arg, argind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* arguments(const char_t**& argv) const {
        static const char_t* _args = XOS_APP_GUI_VEDERE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_GUI_VEDERE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
};
typedef main_optt<> main_opt;

} /// namespace vedere
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_VEDERE_MAIN_OPT_HPP 
