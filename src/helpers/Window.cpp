#include "helpers/Window.h"

using namespace Grid::Helpers;

Window::Window(int width, int height, const char* title) {

    m_window = nullptr;
    m_title  = title;
    m_height = height;
    m_width  = width;

    this->initGLFW();
    this->initWindow();
    this->initGLAD();
    this->onResizeCallback();

}

Window::~Window(){
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

GLFWwindow* Window::getGLFWwindow() {
    return m_window;
}

int Window::getWidth() {
    return m_width;
}

int Window::getHeight() {
    return m_height;
}

/**
 * Initialize the GLAD library.
 */
void Window::initGLAD() {

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        perror("Failed to initialize GLAD: ");
        exit(errno);
    }

}

/**
 * Initialize the GLFW library.
 */
void Window::initGLFW() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

}

/**
 * Initialize the GLFW window and attach the OpenGL
 * context.
 */
void Window::initWindow() {

    m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

    if (!m_window) {
        perror("An error occurred while trying to create the GLFW window: ");
        glfwTerminate();
        exit(errno);
    }

    glfwMakeContextCurrent(m_window);
}

/**
 * Return the closing flag of the glfw window.
 * If the window has not closing request it returns false,
 * else if returns true.
 *
 * @return GLFW window closing flag.
 */
int Window::isWindowFlaggedForClosing() {

    return glfwWindowShouldClose(m_window);
}

void Window::onResizeCallback() {
    glfwGetFramebufferSize(m_window, &m_width, &m_height);
    glViewport(0, 0, m_width, m_height);
}