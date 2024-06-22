#pragma once
#include <GL/glut.h>

namespace Basic {
    struct Point2D {
        int x;
        int y;
        Point2D() : x{0}, y{0} {}
        Point2D(int x, int y) : x{x}, y{y} {}
        Point2D operator-(Point2D dif) { return Point2D(abs((*this).x - dif.x), abs((*this).y - dif.y)); }
        bool operator==(Point2D target) { return ((*this).x == target.x && (*this).y == target.y); }
    };
    int execute(int argc, char *argv[]);
    void drawTringle();
    void drawRectangle();
    void emptyDisplay();
} // namespace Basic

namespace BresenhamLine {
    int execute(int argc, char *argv[]);
}

namespace Transformations2D {
    int execute(int argc, char *argv[]);
}

namespace Transformations3D {
    int execute(int argc, char *argv[]);
}

namespace Impl2DTransforms {
    int execute(int argc, char *argv[]);
}
