#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

void draw () {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    //paredes esquerda
    glColor3ub(230, 214, 163);
    glBegin(GL_QUADS);
        glVertex2f(-30, 10);
        glVertex2f(-30, -10);
        glVertex2f(-10, -10);
        glVertex2f(-10, 10);
    glEnd();

    //paredes direita
    glColor3ub(207, 188, 128);
    glBegin(GL_QUADS);
        glVertex2f(-10, 10);
        glVertex2f(-10, -10);
        glVertex2f(15, -10);
        glVertex2f(15, 10);
    glEnd();

    //telhado esquerda
    glColor3ub(74, 52, 35);
    glBegin(GL_TRIANGLES);
        glVertex2f(-30, 10);
        glVertex2f(-10, 10);
        glVertex2f(-20, 20);
    glEnd();

    //janela
    glColor3ub(68, 200, 227);
    glBegin(GL_QUADS);
        glVertex2f(-5, 5);
        glVertex2f(-5, -5);
        glVertex2f(10, -5);
        glVertex2f(10, 5);
    glEnd();

    glColor3ub(79, 89, 87);
    glBegin(GL_LINES);
        glVertex2f(2.5, 5);
        glVertex2f(2.5, -5);
    glEnd();

    glColor3ub(79, 89, 87);
    glBegin(GL_LINES);
        glVertex2f(-5, 0);
        glVertex2f(10, 0);
    glEnd();

    //telhado direita
    glColor3ub(54, 36, 23);
    glBegin(GL_QUADS);
        glVertex2f(-20, 20);
        glVertex2f(-10, 10);
        glVertex2f(15, 10);
        glVertex2f(5, 20);
    glEnd();

    //porta
    glColor3ub(54, 36, 23);
    glBegin(GL_QUADS);
        glVertex2f(-24, 2);
        glVertex2f(-24, -10);
        glVertex2f(-16, -10);
        glVertex2f(-16, 2);
    glEnd();

    //tronco
    glColor3ub(74, 52, 35);
    glBegin(GL_QUADS);
        glVertex2f(30, 10);
        glVertex2f(30, -10);
        glVertex2f(35, -10);
        glVertex2f(35, 10);
    glEnd();

    //folhas
    const static int radius = 10;
    const static int vertex = 40;
    glColor3ub(52, 105, 45);
    glBegin(GL_POLYGON);
    for (int i = 0; i < vertex; i++) {
        float tetha = i * 2 * M_PI / vertex;
        glVertex2i(33 + cos(tetha) * radius, 15 + sin(tetha) * radius);
    }
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void windowSize (int w, int h) {
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h)
        gluOrtho2D(-40.0f, 40.f, -40.0f*h/w, 40.0f*h/w);
    else
        gluOrtho2D(-40.0f*w/h, 40.f*w/h, -40.0f, 40.0f);
}

void init () {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0, 0, 0, 1);
}

void keyboardInterrupt(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Casa 2D");

    glutDisplayFunc(draw);
    glutReshapeFunc(windowSize);
    glutKeyboardFunc(keyboardInterrupt);

    init();
    glutMainLoop();

    return 0;
}