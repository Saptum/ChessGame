#include  "king.h"

bool King::IsValidMove(int startX, int startY, int endX, int endY) const
{
	return (startX == endX || startY == endY);
}
