#include "board.h"
#include <iostream>
#include <string>

int main()
{
    Board chessBoard;  // Создание объекта шахматной доски (без копирования, поскольку копирующий конструктор удалён)
    std::string move;

    while (true)
    {
        chessBoard.Display(); // Отображение доски
        std::cout << "Enter a move (e.g. e2e4) or 'exit' to exit: ";
        std::cin >> move;

        if (move == "exit")
        {
            break;
        }

        if (move.length() == 4)
        {
            // Преобразование ввода в координаты (с учетом, что a-h и 1-8)
            int startX = move[0] - 'a';
            int startY = 8 - (move[1] - '0');
            int endX = move[2] - 'a';
            int endY = 8 - (move[3] - '0');

            if (!chessBoard.MovePiece(startX, startY, endX, endY))
            {
                std::cout << "Illegal move. Try again.\n";
            }
        }
        else
        {
            std::cout << "Invalid input format. Try again.\n";
        }
    }

    return 0;
}
