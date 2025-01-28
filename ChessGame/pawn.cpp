#include "piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color color) : Piece(color) {}

	char GetSymbol() const override
	{
		
	}

	bool IsValidMove(int startX, int startY, int endX, int endY) const override
	{
		
	}
};
 