#include <iostream>

void printArr(char arr[][3], int turn) {
    std::cout << "Current move #" << turn << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void initMap(char arr[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = '.';
        }
    }
}

bool checkInput(char map[][3], int row, int col) {
    if (col < 0 || col > 2 || row > 2 || row < 0) {
        return false;
    }
    if (map[row][col] != '.') {
        return false;
    }
    return true;
}

bool is_winChar(char map[][3], char sym) {
    for (int j = 0; j < 3; ++j) {
        int rowCount = 0;
        int colCount = 0;
        int leftDgCount = 0;
        int rightDgCount = 0;
        for (int i = 0; i < 3; ++i) {
            if (map[j][i] == sym) {
                ++rowCount;
            }
            if (map[i][j] == sym) {
                ++colCount;
            }
            if (map[i][i] == sym) {
                ++leftDgCount;
            }
            if (map[i][2 - i] == sym) {
                ++rightDgCount;
            }
            if (rowCount == 3 || colCount == 3 || leftDgCount == 3 || rightDgCount == 3) {
                return true;
            }
        }
    }
    return false;
}

bool is_endGame (char map[][3], int turn) {
    char sym = turn % 2 ? 'O' : 'X';
    if (is_winChar(map, sym)) {
        std::cout << "Player " << (sym == 'X' ? "1" : "2") << " is win." << std::endl;
        return true;
    } else if (turn + 1 == 9) {
        std::cout << "Draw" << std::endl;
        return true;
    }
    return false;
}

bool step (char map[][3], int turn) {
    int col = 0;
    int row = 0;
    char sym = turn % 2 ? 'O' : 'X';
    printArr(map, turn);
    do {
        std::cout << "Player #" << (sym == 'X' ? "1" : "2") << " your move: ";
        std::cin >> row >> col;

        if ( !checkInput(map, row, col) ) {
            std::cout << "Wrong coords!" << std::endl;
        }
    } while ( !checkInput(map, row, col) );

    map[row][col] = sym;
    if (is_endGame(map, turn)) {
        return true;
    }
    return false;
}

int main() {
    char map[3][3];
    int turn = 0;
    initMap(map);
    std::cout << std::endl << "***** Welcome in game tic tac toe! *****" << std::endl;
    std::cout << std::endl << "Enter the row and col on map." << std::endl;

    while (!step (map, turn++)); // без тела, всё в функциях

    return 0;
}
