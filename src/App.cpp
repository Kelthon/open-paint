#include <GL/glut.h>
#include <string>
#include "App.h"

App::~App() {}

App::App(std::string title, size_t width, size_t height)
{
    this->setTitle(title);
    this->setSize(width, height);
}

void App::init(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow(title);
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, width, height, 0);
}

void App::run(int argc, char **argv)
{
    init(argc, argv);

    glutMouseFunc(this->mouseFunction);
    glutMotionFunc(this->mouseMotionFunction);
    glutDisplayFunc(this->displayFunction);
    glutKeyboardFunc(this->keyboardFunction);

    glutMainLoop();
}

void App::setSize(size_t width, size_t height)
{
    this->width = width;
    this->height = height;
}

void App::setTitle(std::string title)
{
    this->title = const_cast<char *>(title.c_str());
}

void App::setDisplayFunction(Callback displayFunction)
{
    this->displayFunction = displayFunction;
}

void App::setMouseFunction(MouseCallback mouseFunction)
{
    this->mouseFunction = mouseFunction;
}

void App::setMouseMotionFunction(MouseMotionCallback mouseMotion)
{
    this->mouseMotionFunction = mouseMotion;
}

void App::setKeyboardFunction(KeyboardCallback keyboardFunction)
{
    this->keyboardFunction = keyboardFunction;
}
