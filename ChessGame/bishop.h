#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
	Bishop(Color color) : Piece(color) {}
	char GetSymbol() const override { return (color == Color::White) ? 'B' : 'b'; }
	bool IsValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif
