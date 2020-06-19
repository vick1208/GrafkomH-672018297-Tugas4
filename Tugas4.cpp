#include <iostream>
#include <GL/freeglut.h>
#include <math.h>
float x, y,p,q;
float speed1 = 5.0f;
float speed2 = 0.8f;
float speed3a = 1.0f;
float speed3b = 1.0f;
bool atas = true;
bool kan = true;
bool ac = true;

void disp() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(150.0f, 150.0f+y);
    glVertex2f(50.0f+x, 150.0f);
    glVertex2f(50.0f+p,50.0f+q);
    glEnd();
    glutSwapBuffers();

}
void timer1(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 30, timer1, 0);
    if (y < 148.0f && atas) {
        y += speed1;
    }
    else {
        atas = false;
    }
    if (y > -148.0f && !atas) {
        y -= speed1;
    }
    else {
        atas = true;
    }
}
void timer2(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 30, timer2, 0);
    if (x < 248.0f && kan) {
        x += speed2;
    }
    else {
        kan = false;
    }
    if (x > -48.0f && !kan) {
        x -= speed2;
    }
    else
    {
        kan = true;
    }
}
void timer3(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 30, timer3, 0);
    if (p < 248.0f && ac) {
        p += speed3a;
    }
    else
    {
        ac = false;
    }
    if (p > -48.0f && !ac) {
        p -= speed3a;
    }
    else
    {
        ac = true;
    }
    if (q > - 48.0f && !ac) {
        q -= speed3b;
    }
    else if (q < 248.0f && ac) {
        q += speed3b;
    }
}
void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0f, 300.0f, 0.0f, 300.0f);
}
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Tugas Tween");
    glutDisplayFunc(disp);
    init();
    glutTimerFunc(0, timer1, 0);
    glutTimerFunc(0, timer2, 0);
    glutTimerFunc(0, timer3, 0);
    glutMainLoop();
    return 0;
}
