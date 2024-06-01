#pragma once
#include <GL/glut.h>

namespace Basic {
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
