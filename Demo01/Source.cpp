#include <stdio.h>
#include <glut.h>
#include <math.h>
#include <time.h>
#include <string.h>

/* Rotating 3D system with sphere and line
*/
double PI = 3.1415926535897932384626433832795;
float XWinSize = 1000, YWinSize = 700;
float size = 300;
float XLeft = -20, XRight = 20, YDown = -20, YUp = 20, ZNear = -20, ZFar = 20;
float xx0 = 3, yy0 = 6, zz0 = -4,
xe = 4, ye = 3, ze = 5,
dx = xe - xx0, dy = ye - yy0, dz = ze - zz0,
x, y, z, t = 0;
float alfa = 0;
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	glRotatef(30, 1, 1, 1);
	glRotatef(alfa, 0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(XLeft, 0, 0);
	glVertex3f(XRight, 0, 0);
	glVertex3f(0, YUp, 0);
	glVertex3f(0, YDown, 0);
	glVertex3f(0, 0, ZNear);
	glVertex3f(0, 0, ZFar);

	glColor3f(0.5, 1.0, 1.0);
//	glVertex3f(xx0, yy0, zz0);
	glVertex3f(0, 0, 0);
	//glVertex3f(xx0 + t * dx, yy0 + t * dy, zz0 + t * dz);
//	glVertex3f(xe, ye, ze);
	glVertex3f(xe, ye+t*dy, ze+t*dz);
	glEnd();
//	glRotatef(alfa * 20, 1, 1, 1);
	glRotatef(alfa/20, 1, 1, 1);
	glTranslatef(xx0 + t * dx, yy0 + t * dy, zz0 + t * dz);

	glColor3f(0.5, 0.5, 1.0);
	glutWireSphere(2, 10, 10);


	/*glRotatef(30, 1, 1, 1);
	glBegin(GL_LINES);
	glVertex3f(3, 0, 0);
	glVertex3f(-3, 0, 0);

	glVertex3f(0, 3, 0);
	glVertex3f(0, -3, 0);
	glVertex3f(0, 0, 3);
	glVertex3f(0, 0, -3);

	glEnd();*/
	glutSwapBuffers();
	glFlush();
}
void initial(void) {
	glClearColor(0.3, 0.0, 0.3, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(XLeft, XRight, YDown, YUp, ZNear, ZFar);


	glMatrixMode(GL_MODELVIEW);
}
void idle() {
	if (t < 1)
		t += 0.01;
	else
		t = 0;

	if (alfa < 360)
		alfa += 0.1;
	else
		alfa = 0;
	glutPostRedisplay();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(XWinSize, YWinSize);
	glutCreateWindow("First");
	initial();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}