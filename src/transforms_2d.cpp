#include <CGLab.hpp>

namespace Transformations2D {

    int windowWidth = 800;
    int windowHeight = 600;
    float rectWidth = 200.0f;
    float rectHeight = 100.0f;
    float rectPositionX = (windowWidth - rectWidth) / 2.0f;
    float rectPositionY = (windowHeight - rectHeight) / 2.0f;
    float rotationAngle = 0.0f;
    float scaleFactor = 1.0f;

    void drawRectangle(float x, float y, float width, float height) {
        glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(rectPositionX, rectPositionY, 0.0f);
        glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
        glScalef(scaleFactor, scaleFactor, 1.0f);

        glColor3f(0.4f, 0.1f, 0.8f);
        drawRectangle(0.0f, 0.0f, rectWidth, rectHeight);

        glFlush();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
        case 't':
            rectPositionX += 10.0f;
            break;
        case 'r':
            rotationAngle += 10.0f;
            break;
        case 's':
            scaleFactor *= 1.1f;
            break;
        case 'u':
            rectPositionX = (windowWidth - rectWidth) / 2.0f;
            rectPositionY = (windowHeight - rectHeight) / 2.0f;
            rotationAngle = 0.0f;
            scaleFactor = 1.0f;
            break;
        case 'T':
            rectPositionX -= 10.0f;
            break;
        case 'R':
            rotationAngle -= 10.0f;
            break;
        case 'S':
            scaleFactor /= 1.1f;
            break;
        case 27:
            exit(0);
            break;
        }

        glutPostRedisplay();
    }

    int execute(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(windowWidth, windowHeight);
        glutCreateWindow("Geometric Operations in 2D");

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, windowWidth, 0, windowHeight);

        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);

        glutMainLoop();
        return 0;
    }
} // namespace Transformations2D
