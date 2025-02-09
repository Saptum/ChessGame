#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
	Knight(Color color) : Piece(color) {}
	char GetSymbol() const override { return (color == Color::White) ? 'K' : 'k'; }
	bool IsValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif
