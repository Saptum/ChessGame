#include "pawn.h"

bool Pawn::IsValidMove(int startX, int startY, int endX, int endY) const
{
    int direction = (color == Color::White) ? 1 : -1;
    return (startX == endX && endY == startY + direction);
}
 