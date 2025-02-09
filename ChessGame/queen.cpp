#include "queen.h"

bool Queen::IsValidMove(int startX, int startY, int endX, int endY) const
{
	return (startX == endX || startY == endY);
}
