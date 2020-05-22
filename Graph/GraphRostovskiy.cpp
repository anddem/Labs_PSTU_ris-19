#include "Graph.h"

Graph graph;

extern int WinW, WinH, COL;
extern bool* Mouse_Vert;
int CursorX, CursorY;

using namespace std;

void mouseMove(int x, int y)
{
  y = WinH - y;
  CursorX = x;
  CursorY = y;
  int i = checkCircle(x, y);
  if (i != -1)
    Mouse_Vert[i] = true;
  else
    for (int j = 0; j < COL; j++)
      Mouse_Vert[j] = false;
  glutPostRedisplay();
}

void reshape(int w, int h)
{
  WinW = w;
  WinH = h;
  glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
  glutPostRedisplay();
}

void display()
{
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, WinW, 0, WinH); //ставим начало координат в левый нижний угол
  glViewport(0, 0, WinW, WinH);
  glClearColor(0.5, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  graph.DrawGraph();

  glutSwapBuffers();
}

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(900, 720);
  glutCreateWindow("Graph");
  WinW = glutGet(GLUT_WINDOW_WIDTH);
  WinH = glutGet(GLUT_WINDOW_HEIGHT);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutPassiveMotionFunc(mouseMove);
  glutMainLoop();

  return 0;
}

/*

  *  4  5  7  5  8
  8  *  5  6  6 10
  3  5  *  9  6  1
  3  5  6  *  2  3
  6  2  3  8  * 12
 15 10 13 12 11  *
 






 4 5 7 5 8 8 5 6 6 10 3 5 9 6 1 3 5 6 2 3 6 2 3 8 12 15 10 13 12 11

*/