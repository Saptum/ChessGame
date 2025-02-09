#include "rook.h"

	bool Rook::IsValidMove(int startX, int startY, int endX, int endY) const
	{
		// Ладья ходит по горизонтали или вертикали
		return (startX == endX || startY == endY);
	}
 