#include "board.h"
#include "piece.h"
#include "Pawn.cpp"

Board::Board()
{
	// Инициализация доски: создание 8 строк по 8 столбцов
    squares.resize(8, std::vector<std::unique_ptr<Piece>>(8, nullptr));


	// Расстановка фигур на доске
	/*
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
	*/
    // Инициализация фигур на доске
    for (int i = 0; i < 8; ++i) {
        squares[1][i] = std::make_unique<Pawn>(Color::White);
    	squares[6][i] = std::make_unique<Pawn>(Color::Black);
    }
    // Добавьте инициализацию остальных фигур

}

void Board::Display() const
{
    //const char blackSquare = ' # ';// Символ для черной клетки
    //const char whiteSquare = ' '; // Символ для белой клетки


    std::cout << "  a b c d e f g h\n";// Метки столбцов
    std::cout << " +-----------------+\n"; // Верхняя рамка
    for (int row=0;row<8;++row)
    {
        std::cout << 8 - row << " | ";// Метки строк и левая рамка
        for (int col =0;col <8 ;++col)
        { 
            if (squares[row][col])
            {
                // Если на клетке есть фигура, отображаем ее
                std::cout << squares[row][col]->GetSymbol() << ' ';
            }
            else
            {
                bool isBlack = (row + col) % 2 == 0;
                std::cout << (isBlack ? '#' : ' ') << ' ';
            }
           
        }
        std::cout<< " | " << 8 - row << '\n';// Правая рамка и метка строки
    }
    std::cout << " +-----------------+\n"; // Нижняя рамка
    std::cout << "  a b c d e f g h\n";// Метки столбцов
}


bool Board::MovePiece(int startX, int startY, int endX, int endY)
{
	if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 || endX < 0 || endX >= 8 || endY < 0 || endY >= 8)
	{
        return false;// Координаты вне диапазона
	}

    auto& piece = squares[startY][startX];
    if (!piece) {
        return false; // Нет фигуры в начальной позиции
    }

	if (piece->IsValidMove(startX,startY,endX,endY))
	{
        squares[endY][endX] = std::move(piece);
        squares[startY][startX] = nullptr;
        return true;
	}

    return false;// Недопустимый ход
}



