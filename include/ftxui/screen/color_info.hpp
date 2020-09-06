#ifndef FTXUI_SCREEN_COLOR_INFO_HPP
#define FTXUI_SCREEN_COLOR_INFO_HPP

#include <ftxui/screen/color.hpp>

namespace ftxui {

struct ColorInfo {
  const char* name;
  uint8_t index;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t hue;
  uint8_t saturation;
  uint8_t value;
};

ColorInfo GetColorInfo(Color::Palette256 index);

}  // namespace ftxui

#endif /* end of include guard: FTXUI_SCREEN_COLOR_INFO_HPP */
