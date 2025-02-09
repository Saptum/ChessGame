#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color color) : Piece(color){}
	char GetSymbol() const override { return (color == Color::White) ? 'P' : 'p'; }
	bool IsValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif
