#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Renderer.h"
#include <string>

namespace Genesis {

struct ApplicationSpecifications {
  int AspectRatio = 16 / 10;
  int Width = 300;
  int Height = Width / AspectRatio;
  int Scale = 3;
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

#endif // APPLICATION_H_
