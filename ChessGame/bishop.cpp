#include "bishop.h"

bool Bishop::IsValidMove(int startX, int startY, int endX, int endY) const
{
	return (startX == endX || startY == endY);
}
