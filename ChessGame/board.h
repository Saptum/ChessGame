#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "piece.h"
//using namespace std;


class Board {
public:
	Board();// Конструктор класса
	void Display() const;// Метод для отображения доски


private:
	std::vector<std::vector<char>> squares;// Двумерный вектор для хранения состояния доски

};
#endif