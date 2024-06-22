#include <CGLab.hpp>

namespace Transformations3D {

    constexpr int width = 800;
    constexpr int height = 600;
    GLfloat rotationX = 0.0f;
    GLfloat rotationZ = 0.0f;
    GLfloat rotationY = 0.0f;
    GLfloat scale = 1.0f;

    void drawCube() {
        glBegin(GL_QUADS);

        // Front face
        glColor3f(.8f, .2f, .2f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);

        // Back face
        glColor3f(0.4f, 1.0f, 0.4f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);

        // Top face
        glColor3f(0.2f, 0.4f, 0.9f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);

        // Bottom face
        glColor3f(1.0f, 0.6f, 0.3f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glVertex3f(-0.5f, -0.5f, 0.5f);

        // Right face
        glColor3f(0.9f, 0.7f, .8f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);

        // Left face
        glColor3f(0.2f, .8f, .9f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);

        glEnd();
    }

    void display() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0.0f, 0.0f, -3.0f);
        glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
        glRotatef(rotationZ, 0.0f, 0.0f, 1.0f);
        glScalef(scale, scale, scale);

        drawCube();

        glutSwapBuffers();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
        case 'x':
            rotationX += 5.0f;
            break;
        case 'X':
            rotationX -= 5.0f;
            break;
        case 'y':
            rotationY += 5.0f;
            break;
        case 'Y':
            rotationY -= 5.0f;
            break;
        case 'z':
            rotationZ += 5.0f;
            break;
        case 'Z':
            rotationZ -= 5.0f;
            break;
        case '+':
            scale += 0.1f;
            break;
        case '-':
            if (scale > 0.1f)
                scale -= 0.1f;
            break;
        case 27:
            exit(0);
            break;
        }

        glutPostRedisplay();
    }

    void initializeOpenGL(int argc, char **argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(width, height);
        glutCreateWindow("3D Transformations");

        glEnable(GL_DEPTH_TEST);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (float)width / (float)height, 1.0f, 100.0f);

        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
    }

    int execute(int argc, char **argv) {
        initializeOpenGL(argc, argv);
        glutMainLoop();
        return 0;
    }
} // namespace Transformations3D
