# Termbox Powerline
A simple module for rendering in the [Powerline](https://github.com/powerline/powerline)-style in
[Termbox](https://github.com/tomas/termbox).

<p align="center">
  <img src="https://github.com/codecat/termbox-powerline/blob/master/Screenshot.png?raw=true"/>
</p>

## Usage
Simply add [`src/powerline.cpp`](/src/powerline.cpp) and [`src/powerline.h`](/src/powerline.h) to
your build and include the header file wherever you need to use it. Then just use the simple API.
Here is an example:

```cpp
// Begin the powerline at 0, 0
tb_powerline_begin(0, 0);

// Create a section with a Github icon and color it red
tb_powerline_section("\uE708", TB_RED);

// Create a section with the text "Termbox"
tb_powerline_section("Termbox");

// Create a section with the text "Powerline", color it red, and make the text bold
tb_powerline_section("Powerline", TB_BLUE, TB_DARKER_GRAY | TB_BOLD);

// Create more sections
tb_powerline_section("Section 1");
tb_powerline_section("Section 2");
tb_powerline_section("Section 3");

// Finish rendering the powerline
tb_powerline_end();
```

## Fonts
You can find great pre-patched fonts at [Nerd Fonts](https://www.nerdfonts.com/). Just install one
and configure it into your terminal and you're good to go.

## Termbox2
This library has been used in combination with [Termbox2](https://github.com/tomas/termbox), a fork
of the original Termbox.
