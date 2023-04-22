#include <omp.h>
#include <time.h>
#include <string>
#include <iostream>
#include <GL/glut.h>

#include "App.h"
#include "Vertex2D.h"

#define APPNAME "Open Paint"
#define APPWIDTH 800
#define APPHEIGHT 600
#define SELECTION_TOLERANCE 2.5


using namespace std;

int mousePosition[2] = {0, 0};

void mouseSelection(int x, int y)
{
    int a = mousePosition[0];
    int b = mousePosition[1];

    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBegin(GL_QUADS);
        glColor4f(100, 100, 100, 50);
        glVertex2f(a, b);
        glVertex2f(a, y);
        glVertex2f(x, y);
        glVertex2f(x, b);
    glEnd();
    glDisable(GL_BLEND);
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
                mousePosition[0] = x;
                mousePosition[1] = y;

                cout << x << " " << y << '\n';

                //future: Add point
                 glBegin(GL_QUADS);
                    glColor4f(100, 100, 100, 50);
                    glVertex2f(x - SELECTION_TOLERANCE, y - SELECTION_TOLERANCE);
                    glVertex2f(x + SELECTION_TOLERANCE, y - SELECTION_TOLERANCE);
                    glVertex2f(x + SELECTION_TOLERANCE, y + SELECTION_TOLERANCE);
                    glVertex2f(x - SELECTION_TOLERANCE, y + SELECTION_TOLERANCE);
                glEnd();
                glutSwapBuffers();
            }
            break;

        case GLUT_MIDDLE_BUTTON:
            break;

        case GLUT_RIGHT_BUTTON:
            break;

        default:
            break;
    }
}

void keyboard(unsigned char key, int x, int y)
{

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(100, 100, 100);
        glVertex2f(-10, -10);
        glVertex2f(10, -10);
        glVertex2f(10, 10);
        glVertex2f(-10, 10);

        glColor3f(100, 0, 0);
        glVertex2f(-10, APPHEIGHT-10);
        glVertex2f(10, APPHEIGHT-10);
        glVertex2f(10, APPHEIGHT+10);
        glVertex2f(-10, APPHEIGHT+10);

        glColor3f(0, 100, 0);
        glVertex2f(APPWIDTH-10, -10);
        glVertex2f(APPWIDTH+10, -10);
        glVertex2f(APPWIDTH+10, 10);
        glVertex2f(APPWIDTH-10, 10);

        glColor3f(0, 0, 100);
        glVertex2f(APPWIDTH-10, APPHEIGHT-10);
        glVertex2f(APPWIDTH+10, APPHEIGHT-10);
        glVertex2f(APPWIDTH+10, APPHEIGHT+10);
        glVertex2f(APPWIDTH-10, APPHEIGHT+10);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    App app = App(APPNAME, APPWIDTH, APPHEIGHT);
    app.setMouseFunction(mouse);
    app.setMouseMotionFunction(mouseSelection);
    app.setDisplayFunction(display);
    app.setKeyboardFunction(keyboard);
    app.run(argc, argv);

    return 0;
}
