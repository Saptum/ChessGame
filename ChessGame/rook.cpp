#include "piece.h"

class Rook : public Piece
{
public:
	Rook(Color color) : Piece(color) {}

	char GetSymbol() const override
	{

	}

	bool IsValidMove(int startX, int startY, int endX, int endY) const override
	{

	}
};