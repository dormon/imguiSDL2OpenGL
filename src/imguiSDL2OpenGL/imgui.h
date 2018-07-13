#pragma once

#include<memory>
#include<imguiSDL2OpenGL/imguisdl2opengl_export.h>
#include <imguiDormon/imgui.h>

struct SDL_Window;
typedef union SDL_Event SDL_Event;

namespace imguiSDL2OpenGL{
  class Imgui;
  class ImguiImpl;
}

class IMGUISDL2OPENGL_EXPORT imguiSDL2OpenGL::Imgui{
  public:
    Imgui(SDL_Window*window);
    ~Imgui();
    void newFrame(SDL_Window*window);
    void render(SDL_Window*window,void*context);
    bool processEvent(SDL_Event const* event);
  protected:
    friend class ImguiImpl;
    std::unique_ptr<ImguiImpl>impl;
};

