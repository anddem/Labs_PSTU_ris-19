#ifndef GLFUNC_H
#define GLFUNC_H

#include <string>
#include <GL/glut.h>
#include <cmath>
#include <vector>

struct Edge; //Прототип структуры ребра

void setCoord(int i, int n); //Установка координат,,,
void drawCircle(int x, int y, int R, bool is_active); //Отрисовка окружности
void drawText(std::string text, int x, int y); //Текст в заданных координатах
void drawVertex(std::vector<std::string> vertList); //Отрисовка вершин
void drawLine(int weight, int x0, int y0, int x1, int y1, int dir);
void drawRezult(std::string text, std::string path); //Вывод результата Коммивояжера

void drawMatrix(int** matrix, std::vector<std::string> vertList);

int checkCircle(int x, int y);


#endif