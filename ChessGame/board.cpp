#include "board.h"
#include <iostream>

Board::Board() {
	squares.resize(8, std::vector<Piece*>(8, nullptr));
}

void Board::Initialize() {
	//squares[0][0] = new Rook(Color::WHITE);
}

void Board::Display() const{
	for (int row = 0; row < 8; ++row){

	}
}