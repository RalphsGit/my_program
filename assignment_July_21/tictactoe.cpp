#include <iostream>
#include <string>
using namespace std;

void print_grid(int grid[3][3]) {
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            if(grid[i][j] == 1) cout << "X";
            else if(grid[i][j] == 2) cout << "O";
            else cout << " ";
            if(j<2) cout << " | ";
        }
        if(i<2) cout << endl << "__|___|__" << endl;
    }
    cout << endl << endl;
}

bool check_winner(int grid[3][3], int player) {
    // Rows & columns
    for(int i = 0; i < 3; i++) {
        if(grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) return true;
        if(grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) return true;
    }
    // Diagonals
    if(grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) return true;
    if(grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) return true;

    return false;
}

int main() {
    cout << "Welcome to TicTacToe. Player 1 goes X, player 2 goes O.\n";
    cout << "Enter your location as a number from 1 to 9 following this pattern:\n\n";
    cout << "1 | 2 | 3\n";
    cout << "__|___|__\n";
    cout << "4 | 5 | 6\n";
    cout << "__|___|__\n";
    cout << "7 | 8 | 9\n\n";

    cout << "Click enter to start!\n";
    cin.ignore();

    int grid[3][3] = {0};
    int player = 1;

    for(int turn = 0; turn < 9; turn++) {
        print_grid(grid);
        int pos;
        bool valid = false;

        while(!valid) {
            cout << "Player " << player << " (" << (player == 1 ? "X" : "O") << "), enter position: ";
            cin >> pos;
            if(pos < 1 || pos > 9) {
                cout << "Invalid input. Try again.\n";
                continue;
            }
            int row = (pos - 1) / 3;
            int col = (pos - 1) % 3;
            if(grid[row][col] != 0) {
                cout << "That spot is already taken. Try again.\n";
            } else {
                grid[row][col] = player;
                valid = true;
            }
        }

        if(check_winner(grid, player)) {
            print_grid(grid);
            cout << "Player " << player << " wins!" << endl;
            return 0;
        }

        player = (player == 1) ? 2 : 1;
    }

    print_grid(grid);
    cout << "It's a draw!" << endl;
    return 0;
}
