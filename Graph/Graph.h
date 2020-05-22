#ifndef GRAPH_H
#define GRAPH_H

#include "glfunc.h"

struct Edge //��������� �����
{
  int from; //��������� �����
  int dest; //�������� �����
};

class Graph
{
private:
  std::vector<Edge> rez; //������ ���� ����
  std::vector<std::string> vertList; //������ ������
  int** adjMatrix; //������� ���������

public:
  Graph(); //�����������
  ~Graph(); //����������

  void InsertMatrix(); //���� ������� � ����������

  void PrintMatrix(int** matrix); //������ �������

  void RedRows(int** map); //�������� �����
  void RedCols(int** map); //�������� ��������

  int ZeroRows(int** map, int row, int nCheck); //������ ����� � �������
  int ZeroCols(int** map, int nCheck, int col); //������ ����� � ��������

  Edge ClearMap(int** map); //�������� ������ � ������� � ����������� ����

  void Kommi(); //��� ��������

  std::string getPath(); //����� ������ ���� (�������1 > ... > �������N > �������1)

  void DrawGraph(); //�������� ����
};

#endif