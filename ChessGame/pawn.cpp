#include "piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color color) : Piece(color) {}

	char GetSymbol() const override
	{
		return (color == Color::White) ? 'P' : 'p';
	}

	bool IsValidMove(int startX, int startY, int endX, int endY) const override
	{
		// Реализация проверки корректности хода для пешки
		int direction = (color == Color::White) ? 1 : -1;
		if (startX == endX && startY == endY + direction)
		{
			return true; // Обычный ход вперед
		}
		// Добавьте дополнительные проверки для взятия, первого хода и т.д.
		return false;

	}
};
 