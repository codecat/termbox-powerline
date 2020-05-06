#include "powerline.h"

namespace __powerline
{
	static int startx;
	static int x;
	static int y;
	static tb_chr left;
	static tb_chr right;
	static tb_color bg;
	static tb_color bgdef;
}

static int __tb_padding(int x, int y, int n, tb_color fg, tb_color bg)
{
	for (int i = 0; i < n; i++) {
		tb_char(x + i, y, fg, bg, ' ');
	}
	return n;
}

static void __tb_powerline_separator(tb_color fg = TB_DEFAULT, tb_color bg = __powerline::bgdef)
{
	if (__powerline::left != 0) {
		tb_char(__powerline::x - 1, __powerline::y, bg, __powerline::bgdef, __powerline::left);
		__powerline::left = 0;
		return;
	}

	if (__powerline::right != 0) {
		if (__powerline::bg == bg && __powerline::right == TB_POWERLINE_DEFAULT_RIGHT) {
			__powerline::bg = fg & ~(TB_BOLD | TB_UNDERLINE | TB_REVERSE);
			__powerline::right = TB_POWERLINE_DEFAULT_MID;
		}

		tb_char(__powerline::x, __powerline::y, __powerline::bg, bg, __powerline::right);
		__powerline::x++;
	}
}

void tb_powerline_begin(int x, int y, tb_color bgdef, tb_chr left)
{
	__powerline::startx = x;
	__powerline::x = x;
	__powerline::y = y;
	__powerline::bgdef = bgdef;
	__powerline::left = left;
	__powerline::right = 0;
}

int tb_powerline_section(const char* str, tb_color bg, tb_color fg, int padding, tb_chr right)
{
	__tb_powerline_separator(fg, bg);

	int startx = __powerline::x;
	__powerline::x += __tb_padding(__powerline::x, __powerline::y, padding, fg, bg);
	__powerline::x += tb_string(__powerline::x, __powerline::y, fg, bg, str);
	__powerline::x += __tb_padding(__powerline::x, __powerline::y, padding, fg, bg);

	__powerline::right = right;
	__powerline::bg = bg;
	return __powerline::x - startx + 1;
}

int tb_powerline_end()
{
	__tb_powerline_separator();
	return __powerline::x - __powerline::startx;
}
