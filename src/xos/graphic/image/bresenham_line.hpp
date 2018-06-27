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
///   File: bresenham_line.hpp
///
/// Author: $author$
///   Date: 6/26/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_BRESENHAM_LINE_HPP
#define _XOS_GRAPHIC_IMAGE_BRESENHAM_LINE_HPP

#include "xos/graphic/image/base/extend.hpp"

namespace xos {
namespace graphic {
namespace image {

///////////////////////////////////////////////////////////////////////
/// Function: bresenham_line_drawt
///////////////////////////////////////////////////////////////////////
template <class TImage, class TPixel, class TInt>

void bresenham_line_drawt
(TImage &image, TPixel &pixel, TInt x1, TInt y1, TInt x2, TInt y2) {
    TInt dx = 0, dy = 0, i1 = 0, i2 = 0, d = 0, x = 0, y = 0;

    x = x1;
    y = y1;

    if (0 > (dx = x2-x1))
        dx = -dx;

    if (0 > (dy = y2-y1))
        dy = -dy;

    if (dx < dy)
    {
        d = 2*dx-dy;
        i1 = 2*dx;
        i2 = 2*(dx - dy);

        image.plot(pixel, x, y);

        if (y1 > y2)
        {
            if (x1 > x2)
            {
                while ((((--y) >= y2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        --x;
                    }
                    image.plot(pixel, x, y);
                }
            }
            else
            {
                while ((((--y) >= y2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        x++;
                    }
                    image.plot(pixel, x, y);
                }
            }
        }
        else
        {
            if (x1 > x2)
            {
                while ((((++y) <= y2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        --x;
                    }
                    image.plot(pixel, x, y);
                }
            }
            else
            {
                while ((((++y) <= y2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        x++;
                    }
                    image.plot(pixel, x, y);
                }
            }
        }
    }
    else
    {
        d = 2*dy-dx;
        i1 = 2*dy;
        i2 = 2*(dy - dx);

        image.plot(pixel, x, y);

        if (x1 > x2)
        {
            if (y1 > y2)
            {
                while ((((--x) >= x2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        --y;
                    }
                    image.plot(pixel, x, y);
                }
            }
            else
            {
                while ((((--x) >= x2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        y++;
                    }
                    image.plot(pixel, x, y);
                }
            }
        }
        else
        {
            if (y1 > y2)
            {
                while ((((++x) <= x2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        --y;
                    }
                    image.plot(pixel, x, y);
                }
            }
            else
            {
                while ((((++x) <= x2)))
                {
                    if (d < 0)
                        d += i1;
                    else
                    {
                        d += i2;
                        y++;
                    }
                    image.plot(pixel, x, y);
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////
///  Class: bresenham_linet
///////////////////////////////////////////////////////////////////////
template
<class TImageBase = base::extend,
 class TImageBaseInterface = base::interface,
 class TImage = TImageBaseInterface,
 class TPixel = TImageBaseInterface,
 class TExtends = TImageBase>

class _EXPORT_CLASS bresenham_linet: public TExtends {
public:
    typedef TExtends extends;

    typedef TImageBaseInterface tImageBaseInterface;
    typedef TImageBase tImageBase;
    typedef TImage tImage;
    typedef TPixel tPixel;

    bresenham_linet(tImageBaseInterface& image): extends(image) {
    }
    virtual ~bresenham_linet() {
    }
};

} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_BRESENHAM_LINE_HPP 
