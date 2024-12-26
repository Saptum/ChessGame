#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "piece.h"

class Board {
public:
	Board();
	void Initialize();
	void Display() const;

private:
	std::vector<std::vector<Piece*>> squares;

};
#endif