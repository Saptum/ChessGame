#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
	Queen(Color color) : Piece(color) {}
	char GetSymbol() const override { return (color == Color::White) ? 'Q' : 'q'; }
	bool IsValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif
