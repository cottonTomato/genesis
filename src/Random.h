#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <raylib.h>

namespace Genesis {

class Random {
public:
  static void Init();
  static uint32_t UInt();
  static uint32_t UInt(uint32_t min, uint32_t max);
  static float Float();
  static Vector2 Vec2();
  static Vector2 Vec2(float min, float max);
  static Vector2 Vec2(float minX, float maxX, float minY, float maxY);

private:
  static std::mt19937 s_RandomEngine;
  static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;
};

} // Genesis

#endif //RANDOM_H
