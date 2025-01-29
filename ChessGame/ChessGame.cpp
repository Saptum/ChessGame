


#include "board.h"

int main()
{
    Board chessBoard;// Создание объекта шахматной доски
    std::string move;
    while (true)
    {
	    chessBoard.Display();// Отображение доски
        std::cout << "Введите ход (например, e2e4) или 'exit' для выхода: ";
        std::cin >> move;
	    if (move == "exit")
	    {
		    break;
	    }
	    if (move.length() == 4)
	    {
            int startX = move[0] - 'a';
            int startY = 8 - (move[1] - '0');
            int endX = move[2] - 'a';
            int endY = 8 - (move[3] - '0');
            if (!chessBoard.MovePiece(startX, startY, endX, endY)) {
                std::cout << "Недопустимый ход. Попробуйте снова.\n";
            }
	    }
	    else
	    {
            std::cout << "Неверный формат ввода. Попробуйте снова.\n";
	    }
    }
    
    return 0;
}

