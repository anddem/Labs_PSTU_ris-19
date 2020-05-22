#include "Graph.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

struct vertCoord //��������� ��������� ������ �����
{
  int x, y;
};

vertCoord* vertC; //������ �����

int WinW, WinH, //����� � ������ ���� OpenGL
    R, //������ ���������� ��� �������
  direction = 10, //�������� ����� �����
  KommiRezult = -1, //��������� ���������� ���� ������������
  COL; //���������� ������

bool* Mouse_Vert; //������ ��� �������� ���������� ������� ������ �������

Graph::Graph()
{
  this->InsertMatrix();

  vertC = new vertCoord[COL];
}

Graph::~Graph()
{
  for (int i = 0; i < COL; i++) delete[] adjMatrix[i];
  delete[] adjMatrix;

  delete[] Mouse_Vert;
  delete[] vertC;
}

void Graph::InsertMatrix()
{
  setlocale(LC_ALL, "rus");

  std::cout << "������� ���������� ������: "; std::cin >> COL;

  std::cout << "������� �������� ������: ";
  for (int i = 0; i < COL; i++)
  {
    std::string temp;
    std::cin >> temp;
    vertList.push_back(temp);
  }

  adjMatrix = new int* [COL];

  Mouse_Vert = new bool [COL];
  for (int i = 0; i < COL; i++)
  {
    adjMatrix[i] = new int[COL];
    for (int j = 0; j < COL; j++)
    {
      if (i == j) adjMatrix[i][j] = -1;
      else
      {
        std::cout << "������� ��� ����� " << vertList[i] << " => " << vertList[j] << ": ";
        std::cin >> adjMatrix[i][j];
      }
    }
    Mouse_Vert[i] = false;
  }

  return;
}

void Graph::PrintMatrix(int** matrix)
{
  for (int i = 0; i < COL; i++)
  {
    std::cout << std::setw(2) << vertList[i] << ' ';
    for (int j = 0; j < COL; j++)
    {
      if (matrix[i][j] == -1) std::cout << " * ";
      else std::cout << std::setw(2) << matrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  return;
}

void Graph::RedRows(int** map) //�������� �����
{
  for (int i = 0; i < COL; i++) //������ �� �������
  {
    int min = INT32_MAX; //������� ��� ������ ������ ����������� ������

    for (int j = 0; j < COL; j++) //������ �� ������� ������
    {
      if ((map[i][j] < min) && (map[i][j] >= 0)) //���� ���� ������ �������� � �� �������� ���� � ��� �� �����
        min = map[i][j]; //��������� ������� ������
    }

    for (int j = 0; j < COL; j++) //�������� ������
      if (map[i][j] != -1) //���� �� ���� � ��� �� �����
        map[i][j] -= min; //�������� �������
  }

  return;
}

void Graph::RedCols(int** map) //�������� ��������
{
  for (int j = 0; j < COL; j++) //������ �� ��������
  {
    int min = INT32_MAX; //������� ��� ������� ������� ����������� ������

    for (int i = 0; i < COL; i++) //������ �� ������� �������
    {
      if ((map[i][j] < min) && (map[i][j] >= 0)) //���� ������ ������ �������� � �� �������� ���� � ��� �� �����
        min = map[i][j]; //��������� �������
    }

    for (int i = 0; i < COL; i++) //�������� �������
      if (map[i][j] != -1) //���� �� ���� � ��� �� �����
        map[i][j] -= min; //�������� �������
  }

  return;
}

int Graph::ZeroRows(int** map, int row, int nCheck) //������ ����� � ������
{
  int min = INT32_MAX; // ������� ���������� ������������ ��������
  
  for (int j = 0; j < COL; j++) // �������� ������ ������� � �������� ������
    if (j != nCheck) // ���������� ������� �� ������� � ���������
      if ((map[row][j] < min) && (map[row][j] >= 0)) // ���� �������
        min = map[row][j]; // ��������� �������� ����������

  return min; // ���������� ����������� ��������
}

int Graph::ZeroCols(int** map, int nCheck, int col) //������ ����� � �������
{
  int min = INT32_MAX; //�������

  for (int i = 0; i < COL; i++) //�������� ��� ������ � �������
    if (i != nCheck) //������ �� ������� � ��������
      if ((map[i][col] < min) && (map[i][col] >= 0)) //����� ��������
        min = map[i][col];

  return min;
}

Edge Graph::ClearMap(int** map)
{
  Edge temp;

  int max = -1, k, l; //������������ ��������� ����, ��� ���������� � ������� ���������

  for (int i = 0; i < COL; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      if (map[i][j] == 0)
      {
        int tSum = this->ZeroRows(map, i, j) + this->ZeroCols(map, i, j);
        if (tSum > max)
        {
          max = tSum;
          k = i;
          l = j;
        }
      }
    }
  }

  map[k][l] = -1;
  for (int i = 0; i < COL; i++)
  {
    map[i][l] = -1;
    map[k][i] = -1;
  }
  map[l][k] = -1;

  temp.from = k;
  temp.dest = l;

  return temp;
}

void Graph::Kommi()
{
  int col = COL;
  int** map = new int* [col];
  for (int i = 0; i < col; i++)
    map[i] = new int[col];

  for (int i = 0; i < col; i++)
    for (int j = 0; j < col; j++)
      map[i][j] = adjMatrix[i][j];

  int i = 0;
  while (i != col - 2) //�������� ����
  {
    RedRows(map);
    std::cout << i + 1 << ". �������� �����\n";
    PrintMatrix(map);

    RedCols(map);
    std::cout << i + 1 << ". �������� ��������\n";
    PrintMatrix(map);

    rez.push_back(ClearMap(map));

    std::cout << i + 1 << ". ����� �������\n";
    PrintMatrix(map);

    i++;
  }

  for (int i = 1; i < rez.size(); i++)
  {
    for (int j = i; j < rez.size(); j++)
      if (rez[i].from == rez[j].dest) std::swap(rez[i], rez[j]);
  }
  for (int i = 0; i < rez.size(); i++)
    std::cout << vertList[rez[i].from] << "=>" << vertList[rez[i].dest] << '\n';


  int a = adjMatrix[rez[0].from][rez[0].dest]; // ���������� ������� �����

  for (int i = 1; i < rez.size(); i++) // �������� �� ������� ��������
    a += adjMatrix[rez[i].from][rez[i].dest]; /* �������� ���������� i-���� ����� */

  for (int i = 0; i < rez.size() - 1; i++) // �������� �� ������� ��������
    if (rez[i].dest != rez[i + 1].from) // ���� ���� �����, �� ���������� �� ������� � �� � ������� ������ 0
      a += adjMatrix[rez[i].dest][rez[i + 1].from]; // ������� ���������� ����� ������� 

  std::cout << "����������: " << a << '\n';

  KommiRezult = a;

  for (int i = 0; i < col; i++) delete[] map[i];
  delete[] map;

  return;
}

std::string Graph::getPath() //����� ���� ������������ (��� ������ � OpenGL)
{
  std::string path = "";

  path += vertList[rez[0].from] + " > " + vertList[rez[0].dest];

  for (int i = 1; i < rez.size(); i++)
  {
    if (rez[i - 1].dest != rez[i].from)
    {
      path += " > " + vertList[rez[i].from];
    }

    path += " > " + vertList[rez[i].dest];
  }

  if (rez[0].from != rez[rez.size()-1].dest)
  path += " > " + vertList[rez[0].from];

  return path;
}

void Graph::DrawGraph()
{
  int n = vertList.size();
  for (int i = 0; i < n; i++)
  {
    setCoord(i, n);
  }
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i+1; j < n; j++)
    {
      if (adjMatrix[i][j] > 0)
      {
        drawLine(adjMatrix[i][j], vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y, direction);
        direction = -direction;
      }
      if (adjMatrix[j][i] > 0)
      {
        drawLine(adjMatrix[j][i], vertC[j].x, vertC[j].y, vertC[i].x, vertC[i].y, direction);
        direction = -direction;
      }
    }
  }
  if (KommiRezult == -1) this->Kommi();
  glColor3f(0, 0, 0);
  drawRezult(std::to_string(KommiRezult), this->getPath());
  drawVertex(vertList);

  drawMatrix(adjMatrix, vertList);
  return;
}

void setCoord(int i, int n) //��������� ���������
{
  int R_;
  int x0 = WinW / 2; //����������
  int y0 = WinH / 2; //������ ����
  if (WinW > WinH)
  {
    R = 4 * (WinH / 13) / n;
    R_ = WinH / 2 - R - 10;
  }
  else {
    R = 5 * (WinW / 13) / n;
    R_ = WinW / 2 - R - 10;
  }
  float theta = 2.0f * 3.1415926f * float(i) / float(n);
  float y1 = R_ * cos(theta) + y0;
  float x1 = R_ * sin(theta) + x0;

  vertC[i].x = x1;
  vertC[i].y = y1;

  return;
}

void drawMatrix(int** matrix, std::vector<std::string> vertList)
{
  glColor3f(0, 0, 0);
  int x = 35, y = WinH - 25;
  for (int i = 0; i < vertList.size(); i++)
  {
    drawText(vertList[i] + " ", x, y);
    x += (vertList[i].length() + 1) * 10;
  }

  for (int i = 0; i < COL; i++)
  {
    x = 10; y -= 15;
    drawText(vertList[i] + " ", x, y);
    x = 35;
    for (int j = 0; j < COL; j++)
    {
      std::string tmp;
      if (matrix[i][j] == -1) tmp = "  *";
      else
      {
        if (std::to_string(matrix[i][j]).length() == 2)
          tmp = " " + std::to_string(matrix[i][j]);
        else
          tmp = "  " + std::to_string(matrix[i][j]);
      }
      drawText(tmp, x, y);
      x += tmp.length() * 10;
    }
  }
}

void drawCircle(int x, int y, int R, bool is_active)
{
  if (is_active) glColor3f(0.25, 0.5, 1.0);
  else glColor3f(1.0, 1.0, 1.0);
  
  float x1, y1;
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    float theta = 2.0f * 3.1415926f * float(i) / float(360);
    y1 = R * cos(theta) + y;
    x1 = R * sin(theta) + x;;
    glVertex2f(x1, y1);
  }
  glEnd();

  if (is_active) glColor3f(0.0, 0.392, 0.0);
  else glColor3f(0, 0, 0);
  float x2, y2;
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i++)
  {
    float theta = 2.0f * 3.1415926f * float(i) / float(360);
    y2 = R * cos(theta) + y;
    x2 = R * sin(theta) + x;
    glVertex2f(x2, y2);
  }
  glEnd();
}

void drawText(std::string text, int x, int y)
{
  GLvoid* font = GLUT_BITMAP_HELVETICA_18;
  glRasterPos2i(x - 5, y - 5);
  for (int j = 0; j < text.length(); j++)
    glutBitmapCharacter(font, text[j]);

  return;
}

void drawPath(int fromx, int fromy, int tox, int toy, int R)
{
  glColor3f(0.25, 0.5, 1.0);
  float x1, y1;
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    float theta = 2.0f * 3.1415926f * float(i) / float(360);
    y1 = R * cos(theta) + fromy;
    x1 = R * sin(theta) + fromx;
    glVertex2f(x1, y1);
  }
  glEnd();

  glColor3f(0.0, 0.392, 0.0);
  float x2, y2;
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i++)
  {
    float theta = 2.0f * 3.1415926f * float(i) / float(360);
    y2 = R * cos(theta) + fromy;
    x2 = R * sin(theta) + fromx;
    glVertex2f(x2, y2);
  }
  glEnd();

  glColor3f(1.0, 0.5, 0.0);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++)
  {
    float theta = 2.0f * 3.1415926f * float(i) / float(360);
    y1 = R * cos(theta) + toy;
    x1 = R * sin(theta) + tox;
    glVertex2f(x1, y1);
  }
  glEnd();

  glColor3f(0.0, 0.392, 0.0);
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 360; i++)
  {
    float theta = 2.0f * 3.1415926f * float(i) / float(360);
    y2 = R * cos(theta) + toy;
    x2 = R * sin(theta) + tox;
    glVertex2f(x2, y2);
  }
  glEnd();
}

void drawVertex(std::vector<std::string> vertList)
{
  for (int i = 0; i < vertList.size(); i++)
  {
    drawCircle(vertC[i].x, vertC[i].y, R, Mouse_Vert[i]);
    drawText(vertList[i], vertC[i].x, vertC[i].y);
  }

  return;
}

void drawLine(int weight, int x0, int y0, int x1, int y1, int dir) //����� ��������������� ���������� ����
{
  if (dir > 0) glColor3f(.25f, .50f, .75f);
  else glColor3f(.75f, .50f, .25f);

  dir *= 2.5;

  float tempX = (x0 + x1) / 2 + dir,
        tempY = (y0 + y1) / 2 + dir;

  glBegin(GL_LINE_STRIP);
  glVertex2i(x0, y0);
  glVertex2i((x0 + tempX + dir) / 2, (y0 + tempY + dir) / 2);
  glVertex2i(tempX + dir/2,tempY + dir/2);
  glVertex2i((x1 + tempX + dir) / 2, (y1 + tempY + dir) / 2);
  glVertex2i(x1, y1);
  glEnd();
  drawText(std::to_string(weight), (x1 + tempX + dir) / 2, (y1 + tempY + dir) / 2);

  
  float vx = (x1 + tempX + dir) / 2 - x1;
  float vy = (y1 + tempY + dir) / 2 - y1;
  float s = 1.0f / sqrt(vx * vx + vy * vy);
  vx *= s;
  vy *= s;
  x1 = x1 + R * vx;
  y1 = y1 + R * vy;

  glBegin(GL_TRIANGLES);
  glVertex2f(x1, y1);
  glVertex2f(x1 + 10 * (vx + vy), y1 + 10 * (vy - vx));
  glVertex2f(x1 + 10 * (vx - vy), y1 + 10 * (vy + vx));
  glEnd();

  return;
}

void drawRezult(std::string text, std::string path)
{
  GLvoid* font = GLUT_BITMAP_HELVETICA_18;
  int x = WinW - path.length() * 10;
  std::string temp = "Rezult: ";
  temp += text;
  glRasterPos2i(x, WinH - 35);
  for (int i = 0; i < temp.length(); i++)
    glutBitmapCharacter(font, temp[i]);
  
  glRasterPos2i(x, WinH - 70);
  for (int i = 0; i < path.length(); i++)
    glutBitmapCharacter(font, path[i]);

  return;
}

int checkCircle(int x, int y)
{
  for (int i = 0; i <COL; i++)
    if (pow(x - vertC[i].x, 2) + pow(y - vertC[i].y, 2) <= pow(R, 2))
      return i;
  return -1;
}