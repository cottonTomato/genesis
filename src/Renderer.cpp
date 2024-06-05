#include "Renderer.h"

#include "Random.h"
#include <raylib.h>

namespace Genesis {

Renderer::Renderer(const int width, const int height)
    : m_Width(width), m_Height(height),
      m_ImageBuffer(new uint32_t[width * height]) {}

Renderer::~Renderer() { delete[] m_ImageBuffer; }

void Renderer::Init() {
  m_Image = GenImageColor(m_Width, m_Height, GetColor(0xff00ffff));
  m_Texture = LoadTextureFromImage(m_Image);
}

void Renderer::ClearRandom() {
  for (int i = 0; i < m_Width * m_Height; i++) {
    uint random = Random::UInt();
    random |= 0xff << 24;
    m_ImageBuffer[i] = random;
  }

  RefreshTexture();
}

void Renderer::RefreshTexture() {
  UpdateTexture(m_Texture, m_ImageBuffer);
}


const Texture2D &Renderer::GetTexture() const { return m_Texture; }

} // namespace Genesis
