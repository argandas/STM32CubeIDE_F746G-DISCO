/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/ApplicationFontProvider.hpp>
#include <touchgfx/InternalFlashFont.hpp>

#ifndef NO_USING_NAMESPACE_TOUCHGFX
using namespace touchgfx;
#endif

extern touchgfx::InternalFlashFont& getFont_Asap_Regular_80_4bpp();
extern touchgfx::InternalFlashFont& getFont_Asap_Regular_27_4bpp();
extern touchgfx::InternalFlashFont& getFont_Asap_Regular_15_4bpp();
extern touchgfx::InternalFlashFont& getFont_arial_15_4bpp();

touchgfx::Font* ApplicationFontProvider::getFont(touchgfx::FontId fontId)
{
    switch (fontId)
    {
    case Typography::DEFAULT:
        return &(getFont_Asap_Regular_80_4bpp());
    case Typography::BUTTONDOWN:
        return &(getFont_Asap_Regular_27_4bpp());
    case Typography::LABEL:
        return &(getFont_Asap_Regular_15_4bpp());
    case Typography::IP_ADDRESS:
        return &(getFont_arial_15_4bpp());
    default:
        return 0;
    }
}
