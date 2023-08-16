#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool matrixFound = false;
    bool isSafe(vector<vector<char>>& board, int i, int j, int num) {
        char no = num + '0';
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == no || board[i][k] == no) {
                return false;
            }
        }
        int sx = (i / 3) * 3;
        int sy = (j / 3) * 3;
        for (int x = sx; x < sx + 3; x++) {
            for (int y = sy; y < sy + 3; y++) {
                if (board[x][y] == no) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void recursiveSol(vector<vector<char>>& board, int i, int j) {
        if (matrixFound) return;
        if (i == 9) {
            matrixFound = true;
            return;
        }
        if (j == 9) {
            recursiveSol(board, i + 1, 0);
        } else {
            if (board[i][j] != '.') {
                recursiveSol(board, i, j + 1);
                if (matrixFound) return;
            } else {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(board, i, j, num)) {
                        board[i][j] = num + '0';
                        recursiveSol(board, i, j + 1);
                        if (matrixFound) return;
                        board[i][j] = '.';
                    }
                }
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        recursiveSol(board, 0, 0);
    }
};

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    Solution solver;
    solver.solveSudoku(board);
    printBoard(board);
    
    return 0;
}
