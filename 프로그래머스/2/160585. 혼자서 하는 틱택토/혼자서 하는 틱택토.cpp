#include <string>
#include <vector>

using namespace std;
int aB[3][3] = {0, };

bool IsRightDiagonal(int X)
{
    return aB[0][0] == X && aB[1][1] == X && aB[2][2] == X;
}
bool IsLeftDiagonal(int X)
{
    return aB[0][2] == X && aB[1][1] == X && aB[2][0] == X;
}
bool IsVertical(int col, int X)
{
    return aB[0][col] == X && aB[1][col] == X && aB[2][col] == X;
}
bool IsHorizon(int row, int X)
{
    return aB[row][0] == X && aB[row][1] == X && aB[row][2] == X;
}

int solution(vector<string> board) {
    int countO = 0;
    int countX = 0;
    
    bool WinO = false;
    bool WinX = false;
    
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(board[i][j] == 'O') {
                aB[i][j] = 1;
                countO++;
            } else if (board[i][j] == 'X') {
                aB[i][j] = 2;
                countX++;
            }
        }
    }
    
    if(countX > countO || countO > countX + 1)
        return 0;
    
    for(int i = 0; i < 3; ++i) {
        WinO |= IsHorizon(i, 1) || IsVertical(i, 1);
        WinX |= IsHorizon(i, 2) || IsVertical(i, 2);
    }
    WinO |= IsRightDiagonal(1) || IsLeftDiagonal(1);
    WinX |= IsRightDiagonal(2) || IsLeftDiagonal(2);
    
    if(WinO && WinX) return 0;
    if(WinO && countO != countX + 1) return 0;
    if(WinX && countO != countX) return 0;
    
    return 1;
}