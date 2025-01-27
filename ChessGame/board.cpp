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
    const char blackSquare = ' # ';// Символ для черной клетки
    const char whiteSquare = ' '; // Символ для белой клетки


    std::cout << " a b c d e f g h\n";// Метки столбцов
    std::cout << "+-----------------+\n"; // Верхняя рамка
    for (int row=0;row<8;++row)
    {
        std::cout << 8 - row << " | ";// Метки строк и левая рамка
        for (int col =0;col <8 ;++col)
        { 
            // Определение цвета клетки
            bool isBlack = (row + col) % 2 == 0;
            if (squares[row][col] != ' ')
            {
                // Если на клетке есть фигура, отображаем ее
                std::cout << squares[row][col] << ' ';
            }
            else
            {
                // Иначе отображаем цвет клетки
                std::cout << (isBlack ? blackSquare : whiteSquare) << ' ';
            }
            //std::cout << squares[row][col] << ' ';
        }
        std::cout<< " | " << 8 - row << '\n';// Правая рамка и метка строки
    }
    std::cout << " +-----------------+\n"; // Нижняя рамка
    std::cout << " a b c d e f g h\n";// Метки столбцов
}




