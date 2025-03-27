#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

const int boardWidth = 10;
const int boardHeight = 20;
int score = 0;
int level = 1;
char board[boardHeight][boardWidth];

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

struct Point {
    int x, y;
};

struct Tetromino {
    vector<Point> shape;
    char symbol;
    int color;

    void rotate() {
        for (auto &p : shape) {
            int temp = p.x;
            p.x = -p.y;
            p.y = temp;
        }
    }
};

Tetromino currentPiece;
Point position = { boardWidth / 2, 0 };

void SetColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void ResetColor() {
    SetConsoleTextAttribute(hConsole, 15);
}

void InitializeBoard() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            board[i][j] = ' ';
        }
    }
}

void DrawBoard() {
    system("cls");
    cout << "Score: " << score << " Level: " << level << endl;
    std::cout << "######################" << std::endl;
    for (int i = 0; i < boardHeight; i++) {
        std::cout << "|";
        for (int j = 0; j < boardWidth; j++) {
            if (board[i][j] != ' ') {
                SetColor(board[i][j] - '0');
                std::cout << '*';
                ResetColor();
                std::cout << " ";
            } else {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "######################" << std::endl;
}

Tetromino CreateTetromino() {
    Tetromino t;
    int type = rand() % 7;
    switch (type) {
    case 0: t.shape = { {0,0}, {1,0}, {0,1}, {1,1} }; t.symbol = '1'; t.color = 14; break; // O
    case 1: t.shape = { {0,0}, {1,0}, {2,0}, {3,0} }; t.symbol = '2'; t.color = 11; break; // I
    case 2: t.shape = { {0,0}, {1,0}, {2,0}, {1,1} }; t.symbol = '3'; t.color = 13; break; // T
    case 3: t.shape = { {0,0}, {1,0}, {1,1}, {2,1} }; t.symbol = '4'; t.color = 12; break; // S
    case 4: t.shape = { {0,1}, {1,1}, {1,0}, {2,0} }; t.symbol = '5'; t.color = 10; break; // Z
    case 5: t.shape = { {0,0}, {0,1}, {1,1}, {2,1} }; t.symbol = '6'; t.color = 9;  break; // L
    case 6: t.shape = { {0,1}, {1,1}, {2,1}, {2,0} }; t.symbol = '7'; t.color = 13; break; // J
    }
    return t;
}

bool CheckCollision() {
    for (auto &p : currentPiece.shape) {
        int x = position.x + p.x;
        int y = position.y + p.y;
        if (x < 0 || x >= boardWidth || y >= boardHeight || (y >= 0 && board[y][x] != ' ')) {
            return true;
        }
    }
    return false;
}

bool IsGameOver() {
    for (auto &p : currentPiece.shape) {
        int x = position.x + p.x;
        int y = position.y + p.y;
        if (y >= 0 && board[y][x] != ' ') {
            return true;
        }
    }
    return false;
}

void PlacePiece() {
    for (auto &p : currentPiece.shape) {
        int x = position.x + p.x;
        int y = position.y + p.y;
        if (y >= 0) {
            board[y][x] = currentPiece.symbol;
        }
        // If any part of the placed piece is on or above row 0, game over!
        if (y <= 0) {
            DrawBoard();
            cout << "\nGame Over! The piece reached the top. Final Score: " << score << endl;
            cout << "\nPress any key to exit..." << endl;
            system("pause >nul");
            exit(0);
        }
    }
    position = { boardWidth / 2, 0 };
    currentPiece = CreateTetromino();
}

void ClearLines() {
    for (int i = boardHeight - 1; i >= 0; i--) {
        bool fullLine = true;
        for (int j = 0; j < boardWidth; j++) {
            if (board[i][j] == ' ') {
                fullLine = false;
                break;
            }
        }
        if (fullLine) {
            for (int row = i; row > 0; row--)
                for (int col = 0; col < boardWidth; col++)
                    board[row][col] = board[row - 1][col];
            score += 10;
            if (score % 20 == 0) level++;
            i++;
        }
    }
}

void ClearPiece() {
    for (auto &p : currentPiece.shape) {
        int x = position.x + p.x;
        int y = position.y + p.y;
        if (y >= 0 && y < boardHeight && x >= 0 && x < boardWidth) {
            board[y][x] = ' ';
        }
    }
}

void DrawPiece() {
    for (auto &p : currentPiece.shape) {
        int x = position.x + p.x;
        int y = position.y + p.y;
        if (y >= 0) {
            board[y][x] = currentPiece.symbol;
        }
    }
}

void Input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'a') { position.x--; if (CheckCollision()) position.x++; }
        if (key == 'd') { position.x++; if (CheckCollision()) position.x--; }
        if (key == 'w') { currentPiece.rotate(); if (CheckCollision()) currentPiece.rotate(); }
        if (key == 's') { position.y++; }
        if (key == ' ') { // Hard drop
            while (!CheckCollision()) {
                position.y++;
            }
            position.y--; // Revert one step back to a valid position
            PlacePiece();
            ClearLines();
        }
    }
}

void Update() {
    position.y++;
    if (CheckCollision()) {
        position.y--;
        if (IsGameOver()) {
            DrawBoard();
            cout << "\nGame Over! Final Score: " << score << endl;
            cout << "\nPress any key to exit..." << endl;
            system("pause >nul");
            exit(0);
        }
        PlacePiece();
        ClearLines();
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    InitializeBoard();
    currentPiece = CreateTetromino();

    while (true) {
        ClearPiece();
        Input();
        Update();
        DrawPiece();
        DrawBoard();
        Sleep(500 - (level * 30 > 400 ? 400 : level * 30));
    }

    return 0;
}
                              