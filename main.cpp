#include <omp.h>
#include <time.h>
#include <string>
#include <iostream>
#include <GL/glut.h>

#include "App.h"
#include "Vertex2D.h"
#include "Utils.h"

#define APPWIDTH 800
#define APPHEIGHT 600
#define APPNAME "Open Paint"
#define SELECTION_TOLERANCE 2.5

using namespace std;

int mousePosition[2] = {0, 0};

void mouseSelection(int x, int y)
{
    int a = mousePosition[0];
    int b = mousePosition[1];

    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Area
    glBegin(GL_QUADS);
        glColor4f(0, 0.41, .84, 0.1);
        glVertex2f(a, b);
        glVertex2f(a, y);
        glVertex2f(x, y);
        glVertex2f(x, b);
    glEnd();

    glDisable(GL_BLEND);

    //Border
    glBegin(GL_LINE_LOOP);
        glVertex2f(a, b);
        glVertex2f(a, y);

        glVertex2f(a, y);
        glVertex2f(x, y);

        glVertex2f(x, y);
        glVertex2f(x, b);
    glEnd();

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

//                //future: Add point
//                 glBegin(GL_QUADS);
//                    glColor4f(100, 100, 100, 50);
//                    glVertex2f(x - SELECTION_TOLERANCE, y - SELECTION_TOLERANCE);
//                    glVertex2f(x + SELECTION_TOLERANCE, y - SELECTION_TOLERANCE);
//                    glVertex2f(x + SELECTION_TOLERANCE, y + SELECTION_TOLERANCE);
//                    glVertex2f(x - SELECTION_TOLERANCE, y + SELECTION_TOLERANCE);
//                glEnd();
//                glutSwapBuffers();
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

    glEnd();

    glutSwapBuffers();
}


float * sum(float * M, float * N)
{
    float P[9];

    for(int element = 0; element < 9; element++)
    {
        P[element] = M[element] + N[element];
    }

}

float * mult(float * M, float * N)
{
    float P[9];
    int i, j, k;
    char *number, *rowNumber, *columnNumber;

    for(int l = 0; l < 9; l++) P[l] = 0;

    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            number = const_cast<char *>(fstring<int>("%d%d", row, column).c_str());
            i = convertToInt(number, 2, 3);

            for(int element = 0; element < 3; element++)
            {
                rowNumber = const_cast<char *>(fstring<int>("%d%d", row, element).c_str());
                columnNumber = const_cast<char *>(fstring<int>("%d%d", element, column).c_str());

                j = convertToInt(rowNumber, 2, 3);
                k = convertToInt(columnNumber, 2, 3);

                P[i] += M[j] * N[k];
            }
        }
    }

    return P;
}

int main(int argc, char** argv)
{
//    App app = App(APPNAME, APPWIDTH, APPHEIGHT);
//    app.setMouseFunction(mouse);
//    app.setMouseMotionFunction(mouseSelection);
//    app.setDisplayFunction(display);
//    app.setKeyboardFunction(keyboard);
//    app.run(argc, argv);

    float a[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    float b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    mult(a, b);
    sum(a, b);
    return 0;
}
