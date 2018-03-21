#ifndef GRID_ENGINE_H
#define GRID_ENGINE_H

#include "helpers/Window.h"
#include "core/Renderer.h"

using namespace Grid;

namespace Grid {

    namespace Core {

        class Engine {

        public:

            Engine();
            ~Engine();

            int start();

        private:

            Helpers::Window *m_window   = nullptr;
            Core::Renderer  *m_renderer = nullptr;

        };

    }

}





#endif //GRID_ENGINE_H
