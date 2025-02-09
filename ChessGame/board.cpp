#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"  
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <iostream>
#include <utility> // для std::move

Board::Board()
{
    // Инициализация доски: создание 8 строк
    squares.resize(8);
    // Для каждой строки создаём 8 столбцов (каждый элемент по умолчанию — пустой std::unique_ptr)
    for (auto& row : squares)
    {
        row.resize(8);
    }

    // Установка пешек
    for (int i = 0; i < 8; ++i) {
        squares[1][i] = std::make_unique<Pawn>(Color::White);
        squares[6][i] = std::make_unique<Pawn>(Color::Black);
    }

    // Установка остальных фигур
    squares[0][0] = std::make_unique<Rook>(Color::White);
    squares[0][7] = std::make_unique<Rook>(Color::White);
    squares[7][0] = std::make_unique<Rook>(Color::Black);
    squares[7][7] = std::make_unique<Rook>(Color::Black);

    squares[0][1] = std::make_unique<Knight>(Color::White);
    squares[0][6] = std::make_unique<Knight>(Color::White);
    squares[7][1] = std::make_unique<Knight>(Color::Black);
    squares[7][6] = std::make_unique<Knight>(Color::Black);

    squares[0][2] = std::make_unique<Bishop>(Color::White);
    squares[0][5] = std::make_unique<Bishop>(Color::White);
    squares[7][2] = std::make_unique<Bishop>(Color::Black);
    squares[7][5] = std::make_unique<Bishop>(Color::Black);

    squares[0][3] = std::make_unique<Queen>(Color::White);
    squares[0][4] = std::make_unique<King>(Color::White);
    squares[7][3] = std::make_unique<Queen>(Color::Black);
    squares[7][4] = std::make_unique<King>(Color::Black);
}

void Board::Display() const
{
    std::cout << "  a b c d e f g h\n"; // Метки столбцов
    std::cout << " +-----------------+\n"; // Верхняя рамка
    for (int row = 0; row < 8; ++row)
    {
        std::cout << 8 - row << " | "; // Метки строк и левая рамка
        for (int col = 0; col < 8; ++col)
        {
            if (squares[row][col])
            {
                // Если на клетке есть фигура, отображаем её символ
                std::cout << squares[row][col]->GetSymbol() << ' ';
            }
            else
            {
                bool isBlack = (row + col) % 2 == 0;
                std::cout << (isBlack ? '#' : ' ') << ' ';
            }
        }
        std::cout << "| " << 8 - row << '\n'; // Правая рамка и метка строки
    }
    std::cout << " +-----------------+\n"; // Нижняя рамка
    std::cout << "  a b c d e f g h\n"; // Метки столбцов
}

bool Board::MovePiece(int startX, int startY, int endX, int endY)
{
    if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
        endX < 0 || endX >= 8 || endY < 0 || endY >= 8)
    {
        return false; // Координаты вне диапазона
    }

    auto& piece = squares[startY][startX];
    if (!piece) {
        return false; // Нет фигуры в начальной позиции
    }

    auto& target = squares[endY][endX];

    if (piece->IsValidMove(startX, startY, endX, endY))
    {
        if (target && target->GetColor() == piece->GetColor())
        {
            return false; // Нельзя бить свои фигуры
        }
        target = std::move(piece); // Перемещение фигуры
        squares[startY][startX] = nullptr; // Очистка старой клетки
        return true;
    }

    return false; // Недопустимый ход
}
