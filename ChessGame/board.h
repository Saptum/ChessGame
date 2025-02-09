#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "piece.h"


class Board {
public:
	Board();// Конструктор класса
	void Display() const;// Метод для отображения доски
	bool MovePiece(int startX, int startY, int endX, int endY);


	// Запрещаем копирование
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;

	// Разрешаем перемещение
	Board(Board&&) noexcept = default;
	Board& operator=(Board&&) noexcept = default;

	

private:
	std::vector<std::vector<std::unique_ptr<Piece>>> squares;// Двумерный вектор для хранения состояния доски

};
#endif