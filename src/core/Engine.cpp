#include <iostream>
#include <cstdio>
#include <cerrno>

#include "core/Engine.h"

using namespace Grid::Core;
using std::perror;



Engine::Engine() {

    // todo : Load the window size and name from a JSON config.
    m_window   = new (std::nothrow) Helpers::Window(800, 600, "grid");

    if (m_window == nullptr) {
        perror("new Helpers::Window failed.");
        exit errno;
    }

    m_renderer = new (std::nothrow) Core::Renderer(m_window);

    if (m_renderer == nullptr) {
        perror("new Helpers::Renderer failed.");
        exit errno;
    }
}

Engine::~Engine() {
    delete m_window;
    delete m_renderer;
}

int Engine::start() {

    m_renderer->render();

    return 0;
}