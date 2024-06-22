#include <CGLab.hpp>
#include <iostream>

namespace BresenhamLine {
    using Point2D = Basic::Point2D;
    Point2D from, to;

    auto getCords() {
        Point2D from{}, to{};
        std::println(std::cout, "Enter the x and y cordinates for the starting point :");
        std::cin >> from.x >> from.y;
        std::println(std::cout, "Enter the x and y cordinates for the ending point :");
        std::cin >> to.x >> to.y;
        return std::pair(from, to);
    }

    void drawLine() {
        Point2D delta = to - from;
        int err = delta.x - delta.y;
        int sx = (from.x < to.x) ? 1 : -1;
        int sy = (from.y < to.y) ? 1 : -1;

        glClear(GL_COLOR_BUFFER_BIT);

        Point2D cur = from;

        while (true) {
            glBegin(GL_POINTS);
            glColor3f(1.0f, 0.6f, 0.2f);
            glVertex2i(cur.x, cur.y);
            glEnd();

            if (cur == to) {
                break;
            }

            int e = 2 * err;
            if (e > -delta.y) {
                err -= delta.y;
                cur.x += sx;
            }
            if (e < delta.x) {
                err += delta.x;
                cur.y += sy;
            }
        }

        glFlush();
    };

    int execute(int argc, char **argv) {
        auto [_from, _to]{getCords()};
        from = _from;
        to = _to;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(100, 100);
        glutInitWindowSize(800, 600);
        glutCreateWindow("Bresenham's Line Algorithm");

        glClearColor(0.0, 0.0, 0.0, 1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 800, 0, 600);

        glutDisplayFunc(drawLine);

        glutMainLoop();
        return 0;
    }
} // namespace BresenhamLine
