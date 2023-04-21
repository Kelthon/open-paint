#include <GL/glut.h>
#include <string>
#include "App.h"

App::App() {}
App::~App() {}

App::App(std::string title, unsigned int width, unsigned int height)
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
    gluOrtho2D(0, width, 0, height);
}

void App::run(int argc, char **argv)
{
    init(argc, argv);
    glutDisplayFunc(this->displayFunction);
    glutMainLoop();
}

void App::setSize(unsigned int width, unsigned int height)
{
    this->width = width;
    this->height = height;
}


void App::setTitle(std::string title)
{
    this->title = const_cast<char *>(title.c_str());
}

void App::setDisplayFunction(callback displayFunction)
{
    this->displayFunction = displayFunction;
}
