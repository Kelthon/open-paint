#include <omp.h>
#include <time.h>
#include <string>
#include <iostream>
#include <GL/glut.h>

#include "App.h"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float triangle[] = {200, 260, 80, 40, 320, 40};
    float colors [] = {0, 0, 1, 0, 1, 0, 1, 0, 0};
    glBegin(GL_TRIANGLES);
        for(unsigned int i = 0, j = 0; i < 6; i=i+2, j=j+3)
        {
            glColor3f(colors[j], colors[j+1], colors[j+2]);
            glVertex2f(triangle[i], triangle[i+1]);
        }

        glVertex2f(40, 20);

        glVertex2f(160, 20);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    App app = App("Open Paint", 800, 600);
    app.setDisplayFunction(display);
    app.run(argc, argv);

    return 0;
}
