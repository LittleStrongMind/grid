#ifndef GRID_RENDERER_H
#define GRID_RENDERER_H

#include "helpers/Window.h"

namespace Grid {

    namespace Core {

        class Renderer {

            public:

                Renderer(Helpers::Window *rendering_window);
                ~Renderer();

                void render();

            private:

                Helpers::Window *m_rendering_window = nullptr;

        };

    }

}



#endif //GRID_RENDERER_H
