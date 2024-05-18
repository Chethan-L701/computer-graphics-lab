#include <GL/glut.h>

// #include "./empty_display.cpp"
// #include "./triangle.cpp"
#include "./rect.cpp"

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(1200, 600);
  glutCreateWindow("Computer Graphics using OpenGL");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
