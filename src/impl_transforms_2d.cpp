#include <CGLab.hpp>
#include <cmath>
#include <numbers>

namespace Impl2DTransforms {

    struct Point2D {
        float x;
        float y;

        Point2D() : x{0}, y{0} {}
        Point2D(float x, float y) : x{x}, y{y} {}

        Point2D operator-(Point2D dif) { return Point2D(x - dif.x, y - dif.y); }
        Point2D operator+(Point2D point) { return Point2D{x + point.x, y + point.y}; };
        bool operator==(Point2D target) { return (x == target.x && y == target.y); }
        Point2D operator*(Point2D point) { return {x * point.x, y * point.y}; }
    };

    Point2D rect[4]{{0.25, 0.25}, {-0.25, 0.25}, {-0.25, -0.25}, {0.25, -0.25}};

    void scale(float sx, float sy) {
        for (int i{}; i < 4; i++) {
            rect[i] = rect[i] * Point2D{sx, sy};
        }
    }

    void rotate(float deg) {
        // find the centroid of the square
        Point2D centroid = Point2D{(rect[0].x + rect[1].x + rect[2].x + rect[3].x) / 4,
                                   (rect[0].y + rect[1].y + rect[2].y + rect[3].y) / 4};

        float rad = deg * (std::numbers::pi / 180.0);

        // rotate along the centroid
        for (int i{}; i < 4; i++) {
            Point2D interm = rect[i] - centroid;
            rect[i].x = (interm.x * std::cos(rad) - interm.y * std::sin(rad)) + centroid.x;
            rect[i].y = (interm.x * std::sin(rad) + interm.y * std::cos(rad)) + centroid.y;
        }
    }

    void translate(float tx, float ty) {
        for (int i{}; i < 4; i++) {
            rect[i] = rect[i] + Point2D{tx, ty};
        }
    }

    void drawRectangle() {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glColor3f(0.8, 0.2, 0.2);
        for (auto point : rect) {
            glVertex2f(point.x, point.y);
        }
        glEnd();
        glFlush();
    }

    void keyboard(unsigned char key, int _x, int _y) {
        switch (key) {
        case 'w':
            translate(0.0, 0.05);
            break;
        case 's':
            translate(0.0, -0.05);
            break;
        case 'a':
            translate(-0.05, 0.0);
            break;
        case 'd':
            translate(0.05, 0.0);
            break;
        case 'r':
            rotate(10);
            break;
        case 'R':
            rotate(-10);
            break;
        case '+':
        case '=':
            scale(1.05, 1.05);
            break;
        case '-':
            scale(0.95, 0.95);
            break;
        case 27:
            exit(0);
            break;
        }

        glutPostRedisplay();
    }

    void init() {
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("2D Transformations with OpenGL");

        glClearColor(0.0, 0.0, 0.0, 1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    }

    int execute(int argc, char **argv) {
        glutInit(&argc, argv);

        init();

        glutDisplayFunc(drawRectangle);
        glutKeyboardFunc(keyboard);

        glutMainLoop();
        return 0;
    }
} // namespace Impl2DTransforms
