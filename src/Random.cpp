#include "Random.h"

namespace Genesis {
std::mt19937 Random::s_RandomEngine;
std::uniform_int_distribution<std::mt19937::result_type> Random::s_Distribution;

void Random::Init() {
  s_RandomEngine.seed(std::random_device()());
}

uint32_t Random::UInt() {
  return s_Distribution(s_RandomEngine);
}

uint32_t Random::UInt(const uint32_t min, const uint32_t max) {
  return min + s_Distribution(s_RandomEngine) % (max - min + 1);
}

float Random::Float() {
  return static_cast<float>(s_Distribution(s_RandomEngine)) / static_cast<float>(std::mt19937::max());
}

Vector2 Random::Vec2() {
  return {Float(), Float()};
}

Vector2 Random::Vec2(const float min, const float max) {
  return {Float() * (max - min) + min, Float() * (max - min) + min};
}

Vector2 Random::Vec2(const float minX, const float maxX, const float minY, const float maxY) {
  return {Float() * (maxX - minX) + minX, Float() * (maxY - minY) + minY};
}

} // Genesis