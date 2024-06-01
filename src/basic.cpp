#include <CGLab.hpp>
#include <iostream>
#include <string>

namespace Basic {

    void drawRectangle() {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);

        glColor3f(1.0, 0.6, 0.4);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);

        glEnd();

        glFlush();
    }

    void drawTringle() {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex2f(0, 0.5);
        glColor3f(0, 1, 0);
        glVertex2f(-0.5, -0.5);
        glColor3f(0, 0, 1);
        glVertex2f(0.5, -0.5);
        glEnd();

        glFlush();
    }

    void emptyDisplay() {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }

    void init() {
        glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    }

    int execute(int argc, char **argv) {
        void (*callback)();
        std::string title{};

    choiceloop:
        std::println(std::cout, "Enter the program to be executed :\n1. Empty Screen\n2. Triangle\n3. Rectangle");
        int choice{0};
        std::cin >> choice;
        switch (choice) {
        case 1:
            title = "Empty Screen";
            callback = emptyDisplay;
            break;
        case 2:
            title = "Triangle";
            callback = drawTringle;
            break;
        case 3:
            title = "Rectangle";
            callback = drawTringle;
            callback = drawRectangle;
            break;
        default:
            std::println(std::cout, "invaild choice!");
            goto choiceloop;
        }

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        glutCreateWindow(title.c_str());
        init();
        glutDisplayFunc(callback);
        glutMainLoop();
        return 0;
    }
} // namespace Basic
