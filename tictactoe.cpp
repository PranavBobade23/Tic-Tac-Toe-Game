#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Initialize Board
void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
    currentPlayer = 'X';
}

// Display Board
void displayBoard() {
    cout << "\n";
    cout << "------------- TIC TAC TOE -------------\n\n";

    for (int i = 0; i < 3; i++) {
        cout << "     |     |     \n";
        cout << "  " << board[i][0] << "  |  "
             << board[i][1] << "  |  "
             << board[i][2] << endl;

        if (i != 2)
            cout << "_____|_____|_____\n";
    }

    cout << "\n";
}

// Make Move
bool makeMove(int choice) {

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9)
        return false;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = currentPlayer;

    return true;
}

// Check Win
bool checkWin() {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

// Check Draw
bool checkDraw() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Switch Player
void switchPlayer() {

    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main() {

    char playAgain;

    do {

        initializeBoard();

        bool gameOver = false;

        while (!gameOver) {

            displayBoard();

            int choice;

            cout << "Player "
                 << currentPlayer
                 << ", Enter Position (1-9): ";

            cin >> choice;

            if (!makeMove(choice)) {

                cout << "\nInvalid Move! Try Again.\n";
                continue;
            }

            if (checkWin()) {

                displayBoard();

                cout << " Player "
                     << currentPlayer
                     << " Wins!\n";

                gameOver = true;
            }
            else if (checkDraw()) {

                displayBoard();

                cout << "Game Draw!\n";

                gameOver = true;
            }
            else {

                switchPlayer();
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank You For Playing!\n";

    return 0;
}