

#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <memory>

enum class Color { White, Black  };

class Piece
{
public:

	Piece(Color color) : color(color) {}
	virtual ~Piece() = default;
	Color GetColor() const { return color; }
	virtual char GetSymbol() const = 0;
	virtual bool IsValidMove(int startX, int startY, int endX, int endY) const = 0;

protected:
	Color color;
};

#endif