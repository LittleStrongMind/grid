#ifndef GRID_WINDOW_H
#define GRID_WINDOW_H

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Grid {

    namespace Helpers {

        class Window {

            public:

                Window(int width, int height, const char* title);
                ~Window();

                GLFWwindow* getGLFWwindow();

                int getWidth();
                int getHeight();

                int isWindowFlaggedForClosing();

        private:

                GLFWwindow *m_window;
                const char* m_title;

                int m_width;
                int m_height;

                void initGLFW();
                void initGLAD();
                void initWindow();

                void onResizeCallback();
                void onCloseCallback();

        };


    }

}



#endif //GRID_WINDOW_H
