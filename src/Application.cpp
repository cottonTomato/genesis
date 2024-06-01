#include "Application.h"
#include "Renderer.h"
#include <raylib.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

namespace Genesis {

static Application *s_Instance = nullptr;

Application::Application(const ApplicationSpecifications &spec)
    : m_specifications(spec), m_Renderer(spec.Width, spec.Height) {
  s_Instance = this;
}

Application::~Application() { s_Instance = nullptr; }

void Application::Run() {
  InitWindow(m_specifications.Width * m_specifications.Scale,
             m_specifications.Height * m_specifications.Scale,
             m_specifications.Title.c_str());

#if defined(PLATFORM_WEB)
  emscripten_set_main_loop([&]() { this->OnUpdate(); }, 0, 1);
#else
  SetTargetFPS(60);
  SetExitKey(0); // Disable Exit Key

  while (!WindowShouldClose()) { // Detect Window Close or Exit Key
    this->OnUpdate();
  }
#endif

  CloseWindow();
}

void Application::OnUpdate() {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
  DrawTexture(m_Renderer.GetTexture(), 0, 0, WHITE);

  EndDrawing();
}

Application &Application::Get() { return *s_Instance; }

Renderer &Application::GetRenderer() { return Application::Get().m_Renderer; }

} // namespace Genesis
