/*
 * Inspired by the original bootlogo by Shawn Sijnstra
 * z80 assembly version: https://github.com/sijnstra/agon-projects/tree/main/bootlogo
 * Licensed under the MIT License
 *
 * This implementation in C was created by CoffeeMuse (2025)
 * and is also released under the MIT License.
 *
 * While not a direct port, this version borrows core ideas,
 * logic structures, and design elements from the original.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <mos_api.h>
#include <agon/vdp_vdu.h>

#define LOGO_FONT_START 200
#define LOGO_FONT_COUNT 39
#define COLOR_SWATCH_CHAR 238
#define COLOR_COUNT 32

// Custom font bitmaps for characters 200..238
static const uint8_t logo_font_data[LOGO_FONT_COUNT][8] = {
    {7, 15, 31, 31, 31, 31, 31, 63},
    {192, 224, 240, 240, 240, 240, 240, 248},
    {63, 63, 31, 15, 15, 15, 7, 7},
    {248, 248, 240, 224, 224, 224, 192, 192},
    {0, 1, 7, 15, 31, 63, 127, 127},
    {7, 199, 199, 195, 227, 225, 240, 240},
    {192, 195, 195, 135, 135, 15, 15, 31},
    {0, 0, 224, 240, 248, 252, 252, 254},
    {0, 0, 1, 1, 3, 3, 7, 7},
    {255, 255, 255, 255, 255, 255, 255, 255},
    {248, 248, 248, 240, 224, 225, 193, 195},
    {63, 63, 127, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 223, 223},
    {0, 0, 128, 128, 128, 192, 192, 192},
    {7, 7, 15, 15, 15, 15, 15, 31},
    {255, 247, 231, 231, 231, 199, 135, 130},
    {199, 135, 135, 143, 15, 15, 31, 31},
    {207, 207, 207, 199, 199, 195, 129, 1},
    {224, 224, 224, 240, 240, 240, 240, 240},
    {31, 31, 31, 31, 15, 15, 15, 31},
    {128, 128, 128, 129, 143, 135, 143},
    {31, 63, 15, 0, 128, 224, 224, 195},
    {252, 240, 128, 0, 3, 7, 35, 243},
    {1, 1, 1, 129, 193, 225, 241, 241},
    {240, 240, 240, 240, 240, 240, 240, 240},
    {31, 31, 3, 3, 3, 3, 7, 15},
    {223, 255, 255, 255, 255, 255, 254, 254},
    {199, 135, 135, 7, 15, 15, 31, 31},
    {241, 241, 241, 248, 248, 248, 248, 248},
    {253, 255, 255, 255, 255, 255, 255, 127},
    {240, 248, 248, 224, 224, 224, 240, 248},
    {31, 63, 63, 63, 31, 31, 15, 0},
    {254, 252, 252, 252, 248, 248, 224, 0},
    {31, 60, 32, 0, 0, 0, 0, 0},
    {120, 28, 12, 12, 0, 0, 0, 0},
    {127, 127, 127, 127, 127, 63, 15, 0},
    {248, 252, 252, 252, 252, 248, 240, 0},
    {255, 254, 252, 248, 240, 224, 192, 128},
    {255, 255, 255, 255, 255, 255, 255, 255}

};

int main(int argc, char *argv[])
{

    // redfine characters
    for (uint8_t i = 0; i < LOGO_FONT_COUNT; i++)
    {
        vdp_redefine_character(
            LOGO_FONT_START + i,
            logo_font_data[i][0],
            logo_font_data[i][1],
            logo_font_data[i][2],
            logo_font_data[i][3],
            logo_font_data[i][4],
            logo_font_data[i][5],
            logo_font_data[i][6],
            logo_font_data[i][7]);
    }

    // Print logo lines
    putch(' ');
    putch(' ');
    putch(200);
    putch(201);
    printf("  Agon Light 2 with Zilog eZ80 CPU\r\n");

    putch(' ');
    putch(' ');
    putch(202);
    putch(203);
    mos_puts("  CoffeeMuse's c port\r\n", 0, '\0');

    putch(' ');
    putch(204);
    putch(205);
    putch(206);
    putch(207);
    mos_puts("\r\n", 0, '\0');

    putch(208);
    putch(209);
    putch(210);
    putch(211);
    putch(212);
    putch(213);
    mos_puts("\r\n", 0, '\0');

    putch(214);
    putch(215);
    putch(216);
    putch(209);
    putch(217);
    putch(218);
    // printf(" Screen Mode: %d\r\n",getsysvar_scrMode());   /* pending implementation */
    // Note: getsysvar_scrMode() is not implemented in the current API.
    printf(" Screen Mode: [missing getsysvar_scrMode()]\r\n");

    putch(219);
    putch(220);
    putch(221);
    putch(222);
    putch(223);
    putch(224);
    printf("        Text: %d x %d\r\n", getsysvar_scrCols(), getsysvar_scrRows());

    putch(225);
    putch(226);
    putch(227);
    putch(228);
    putch(229);
    putch(230);
    printf("    Graphics: %d x %d\r\n", getsysvar_scrwidth(), getsysvar_scrheight());

    putch(231);
    putch(232);
    putch(233);
    putch(234);
    putch(235);
    putch(236);
    printf("     Colours: %d\r\n", getsysvar_scrColours());

    bool show_colors = (argc <= 1);
    if (show_colors)
    {
        for (uint8_t c = 0; c < COLOR_COUNT; c++)
        {
            vdp_set_text_colour(c);
            putch(COLOR_SWATCH_CHAR);
        }
        putch('\r');
        putch('\n');
    }

    // Swap buffers / reset font
    putch(23);
    putch(0);
    putch(0xC3);
    putch(23);
    putch(0);
    putch(0xC3);

    return 0;
}