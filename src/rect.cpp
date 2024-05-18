#pragma once
#include <GL/glut.h>

void display() {
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
