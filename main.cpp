#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -4.0, 25.0, 4.0);
    glRectf(-4.0, -25.0, 4.0, 25.0);


    glColor3f(0.0, 0.0, 1.0);
    glutSolidTorus(1.00, 6.4, 10, 100);
    glPopMatrix();

    glFlush(); // Force all used commands to execute
}


void spinDisplay_right1(void)
{
    spin = -.60;
    glutPostRedisplay();
    glRotatef(spin, 0.0, 0.0, 1.0);
}


void init(void)
{
    glClearColor (1.0, 0.0, 0.0, 0.0);
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

int a=0;
void my_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 's':
    {
        if(a==0)
        {
            glutIdleFunc(spinDisplay_right1);
            a=1;
        }

        else
        {
            glutIdleFunc(NULL);
            a=0;
        }
    }
    case 'h':
    {


        glRotatef(-10, 0.0, 0.0, 1.0);
        break;
    }
    case 'l':
        glRotatef(3, 0.0, 0.0, 1.0);
        break;

    default:
        break;
    }
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);                          //To initialize GLUT library
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (300, 300);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("ID-20181004010 [ABIR]");
    init();


    glutDisplayFunc(display);
    glutKeyboardFunc(my_keyboard);

    glutMainLoop();
    return 0;
}
