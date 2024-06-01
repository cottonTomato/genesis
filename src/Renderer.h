#ifndef RENDERER_H_
#define RENDERER_H_

#include <raylib.h>
#include <cstdint>

namespace Genesis {

class Renderer {
public:
  Renderer(int width, int height);

  ~Renderer();

  [[nodiscard]] const Texture2D &GetTexture() const;

private:
  int m_Width = 0;
  int m_Height = 0;

  uint32_t *m_ImageBuffer = nullptr;
  Image m_Image;
  Texture2D m_Texture;
};

} // namespace Genesis

#endif // RENDERER_H_
