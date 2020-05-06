/*
Termbox Powerline

MIT License

Copyright (c) 2020 Melissa Geels

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// Example usage:
//
//  tb_powerline_begin(0, 0);
//  tb_powerline_section("\uE708", TB_RED);
//  tb_powerline_section("Github");
//  tb_powerline_end();
//
// This will render a powerline with 2 sections, a red one with the Github icon on it, and a white
// one with the text "Github".
//
// Note: This library works best with termbox2 from tomas on github: github.com/tomas/termbox

#pragma once

#include <termbox.h>

#define TB_POWERLINE_DEFAULT_BGDEF TB_DEFAULT

#define TB_POWERLINE_DEFAULT_SECTION_BG TB_WHITE
#define TB_POWERLINE_DEFAULT_SECTION_FG TB_DARKER_GRAY
#define TB_POWERLINE_DEFAULT_SECTION_PADDING 1

#define TB_POWERLINE_DEFAULT_LEFT  L'\uE0B2'
#define TB_POWERLINE_DEFAULT_MID   L'\uE0B1'
#define TB_POWERLINE_DEFAULT_RIGHT L'\uE0B0'

// Begins powerline rendering. Call this before you begin doing calls to `tb_powerline_section`.
//
// - `x` is the X position where the powerline will render at. The start position is considered as
//   the position where the padding begins.
// - `y` is the Y position where the powerline will render at.
// - `bgdef` is the default background to use that is behind the powerline glyphs.
// - `left` is the character to place left of the sections (at x - 1).
void tb_powerline_begin(int x, int y,
	tb_color bgdef = TB_POWERLINE_DEFAULT_BGDEF,
	tb_chr left = TB_POWERLINE_DEFAULT_LEFT
);

// Renders a section of the powerline. Call this after calling `tb_powerline_begin`, and before
// calling `tb_powerline_end`.
//
// - `str` is the text that the section will contain.
// - `bg` is the background color of the section itself.
// - `fg` is the color of the text in section.
// - `padding` is the amount of whitespace on the left and right side of the text.
// - `right` is the character to place on the right side of this section.
//
// Returns the number of characters that the section is wide, including the right glyph, but
// excluding the left glyph at the very start of the powerline.
int tb_powerline_section(const char* str,
	tb_color bg = TB_POWERLINE_DEFAULT_SECTION_BG,
	tb_color fg = TB_POWERLINE_DEFAULT_SECTION_FG,
	int padding = TB_POWERLINE_DEFAULT_SECTION_PADDING,
	tb_chr right = TB_POWERLINE_DEFAULT_RIGHT
);

// Finalizes the powerline. Call this when you're done with all of your `tb_powerline_section`
// calls. This will make sure that the final section's right glyph is rendered.
//
// Returns the number of characters that the powerline is wide, minus the left glyph at the very
// start of the powerline, so that if you place the cursor at X + L, you get the character
// immediately after the final section's right glyph.
int tb_powerline_end();
