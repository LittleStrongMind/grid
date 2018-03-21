
#                       /$$       /$$
#                      |__/      | $$
#    /$$$$$$   /$$$$$$  /$$  /$$$$$$$
#   /$$__  $$ /$$__  $$| $$ /$$__  $$
#  | $$  \ $$| $$  \__/| $$| $$  | $$
#  | $$  | $$| $$      | $$| $$  | $$
#  |  $$$$$$$| $$      | $$|  $$$$$$$
#   \____  $$|__/      |__/ \_______/
#   /$$  \ $$
#  |  $$$$$$/
#   \______/


CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(grid)

LIST(APPEND CMAKE_CXX_FLAGS "--std=c++11")

FIND_PACKAGE(OpenGL REQUIRED)

SET(EXECUTABLE_OUTPUT_PATH "bin/")


# GLFW ------------------------------------------------

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

ADD_SUBDIRECTORY(external/glfw)


# ASSIMP ----------------------------------------------

option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)

ADD_SUBDIRECTORY(external/assimp)


# BULLET ----------------------------------------------

option(BUILD_BULLET2_DEMOS OFF)
option(BUILD_CPU_DEMOS OFF)
option(BUILD_EXTRAS OFF)
option(BUILD_OPENGL3_DEMOS OFF)
option(BUILD_UNIT_TESTS OFF)

ADD_SUBDIRECTORY(external/bullet)


# INCLUDES --------------------------------------------

INCLUDE_DIRECTORIES(
    include/
    external/assimp/include
    external/bullet/src
    external/glad/include
    external/glfw/include
    external/glm
    external/stb
)


# FILES -----------------------------------------------

FILE(GLOB VENDORS_FILES external/glad/src/glad.c)
FILE(GLOB_RECURSE SOURCE_FILES src/*.cpp)
FILE(GLOB_RECURSE HEADERS_FILES include/*.h)
FILE(GLOB SHADERS_FILES
    shaders/*.comp
    shaders/*.frag
    shaders/*.geom
    shaders/*.vert
)


# LIBS ------------------------------------------------

SET(ALL_LIBS
    ${OPENGL_LIBRARY}
    assimp
    glfw
    ${GLFW_LIBRARIES}
    ${GLAD_LIBRARIES}
    BulletDynamics BulletCollision LinearMath
)



ADD_DEFINITIONS(
    -DGLFW_INCLUDE_NONE
)

ADD_EXECUTABLE(
	${PROJECT_NAME}
	${SOURCE_FILES}
    ${HEADERS_FILES}
    ${SHADERS_FILES}
    ${VENDORS_FILES}
        src/core/Engine.cpp include/core/Engine.h src/core/Renderer.cpp include/core/Renderer.h src/EventHandler.cpp include/EventHandler.h)

TARGET_LINK_LIBRARIES(
	${PROJECT_NAME}
	${ALL_LIBS}
)