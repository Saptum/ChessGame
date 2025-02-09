#ifndef ROOK_H
#define ROOK_H

#include "piece.h"


class Rook : public Piece
{
public:
	Rook(Color color) : Piece(color) {}
	char GetSymbol() const override { return (color == Color::White) ? 'R' : 'r'; }
	bool IsValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif

