#include <GL/freeglut.h>
#include <GL/glu.h>

int windowWidth = 800;
int windowHeight = 600;

float rotationAngleX = 0.0f;
float rotationAngleY = 0.0f;
float zoom = 1.0f;
int prevMouseX = 0;
int prevMouseY = 0;
bool isMouseDragging = false;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f);
    glScalef(zoom, zoom, zoom);

    glutWireCube(2.0);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isMouseDragging = true;
            prevMouseX = x;
            prevMouseY = y;
        } else if (state == GLUT_UP) {
            isMouseDragging = false;
        }
    }
}

void motion(int x, int y) {
    if (isMouseDragging) {
        rotationAngleY += (x - prevMouseX) * 0.5;
        rotationAngleX += (y - prevMouseY) * 0.5;
        prevMouseX = x;
        prevMouseY = y;
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    if (key == '+') {
        zoom *= 1.1;
    } else if (key == '-') {
        zoom /= 1.1;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Rotating Cube Application");
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
