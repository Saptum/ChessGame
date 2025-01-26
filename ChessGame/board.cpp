#include "board.h"

Board::Board()
{
	// Инициализация доски: создание 8 строк по 8 столбцов
	squares = std::vector<std::vector<char>>(8, std::vector<char>(8, ' '));


	// Расстановка фигур на доске
	const std::string initialSetup[8] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
	};

    for (int row=0;row <8;++row)
    {
	    for (int col =0;col < 8;++col)
	    {
            squares[row][col] = initialSetup[row][col];
	    }
    }
}

void Board::Display() const
{
    std::cout << " a b c d e f g h\n";// Метки столбцов
    for (int row=0;row<8;++row)
    {
        std::cout << 8 - row << ' ';// Метки строк
        for (int col =0;col <8 ;++col)
        {
            std::cout << squares[row][col] << ' ';
        }
        std::cout << 8 - row << '\n';
    }
    std::cout << " a b c d e f g h\n";// Метки столбцов
}




