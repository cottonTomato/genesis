#include "Renderer.h"
#include <raylib.h>

namespace Genesis {

Renderer::Renderer(int width, int height) : m_Width(width), m_Height(height) {
  m_ImageBuffer = new uint32_t[width * height];
  m_Image = GenImageColor(width, height, GetColor(0xffff00ff));
  m_Texture = LoadTextureFromImage(m_Image);
}

Renderer::~Renderer() { delete[] m_ImageBuffer; }

const Texture2D &Renderer::GetTexture() const { return m_Texture; }

} // namespace Genesis
