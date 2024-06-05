#ifndef APPLICATION_H
#define APPLICATION_H

#include "Renderer.h"
#include <string>

namespace Genesis {

struct ApplicationSpecifications {
  int Width = 300;
  int Height = Width / 16 * 10;
  int Scale = 3.0f;
  std::string Title = "Genesis";
};

class Application {
public:
  explicit Application(
      const ApplicationSpecifications &spec = ApplicationSpecifications{});

  ~Application();

  void Run();

  static Application &Get();
  static Renderer &GetRenderer();

private:
  ApplicationSpecifications m_specifications;
  Renderer m_Renderer;

  void OnUpdate();
};

} // namespace Genesis

#endif //APPLICATION_H
