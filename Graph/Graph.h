#ifndef GRAPH_H
#define GRAPH_H

#include "glfunc.h"

struct Edge //Структура ребра
{
  int from; //Начальная точка
  int dest; //Конечная точка
};

class Graph
{
private:
  std::vector<Edge> rez; //Вектор рёбер пути
  std::vector<std::string> vertList; //Вектор вершин
  int** adjMatrix; //Матрица смежности

public:
  Graph(); //Конструктор
  ~Graph(); //Деструктор

  void InsertMatrix(); //Ввод матрицы с клавиатуры

  void PrintMatrix(int** matrix); //Печать матрицы

  void RedRows(int** map); //Редукция строк
  void RedCols(int** map); //Редукция столбцов

  int ZeroRows(int** map, int row, int nCheck); //Оценка нулей в строках
  int ZeroCols(int** map, int nCheck, int col); //Оценка нулей в столбцах

  Edge ClearMap(int** map); //Удаление строки и столбца с наиболльшим нулём

  void Kommi(); //Сам алгоритм

  std::string getPath(); //Вернёт строку вида (Вершина1 > ... > ВершинаN > Вершина1)

  void DrawGraph(); //Нарисует граф
};

#endif