cmake_minimum_required(VERSION 3.0)

project(OpenGLApplication)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(OpenGLApplication main.cpp)

target_link_libraries(OpenGLApplication
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)
