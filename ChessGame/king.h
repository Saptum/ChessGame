#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
	King(Color color) : Piece(color) {}
	char GetSymbol() const override { return (color == Color::White) ? 'K' : 'k'; }
	bool IsValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif
