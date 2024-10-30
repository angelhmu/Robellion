#include <iostream>

using namespace std;

//a 5x5 board where 
//8 represents the current position of the player
//and X is the exit
char board[5][5] =    {{'8','*','*','*','*'},
    {'*','*','*','*','*'},
    {'*','*','*','*','*'},
    {'*','*','*','*','*'},
    {'*','*','*','*','X'}};
int row = 0, col = 0;
int position[2] = {row,col};

int roll();
void display_board();
void move(int, int);
bool check(int);
bool check(int, int);


int main(){
    cout << "Welcome to Robellion: the boardgame";
    cout << "You are the leader of the rebellion against the stupid humans " 
    << "and you must exit the robot factory" << endl;

    bool at_exit = false;
    int dice_roll = 0, direction = 0;
    display_board();
    while(!at_exit) {
        dice_roll = roll();
        cout << "You rolled a " << dice_roll << endl;
        cout << "Which direction would you like to move?" << endl;
        cout << "1. North" << endl;
        cout << "2. East" << endl;
        cout << "3. South" << endl;
        cout << "4. West\n" << endl;
        cin >> direction;
        move(direction, dice_roll);
        display_board();
        if(check(row, col)) break;
    }
    cout << "Congratulations! You're now free!" << endl;
    return 0;
}

//rolls a 6 sided die
int roll() {
    return rand() % 6 + 1;
}

//displays the current game board
void display_board() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

//moves the player using given parameters
void move(int direction, int dice_roll) {
    switch(direction) {
        case 1:
            if(check(direction)) {
                cout << "Can't move north. Try again." << endl;
                return;
            }
            else {
                board[row][col] = '*';
                for(int i = 0; i < dice_roll; i++) {
                    row--;
                    if(check(direction)) {
                        cout << "Oops. You've hit the wall. Can't move anymore." << endl;
                        board[row][col] = '8';
                        return;
                    }
                }
                board[row][col] = '8';
                cout << "Moved North." << endl;
            }
            break;
        case 2:
            if(check(direction)) {
                cout << "Can't move east. Try again." << endl;
                return;
            }
            else {
                board[row][col] = '*';
                for(int i = 0; i < dice_roll; i++) {
                    col++;
                    if(check(direction)) {
                        cout << "Oops. You've hit the wall. Can't move anymore." << endl;
                        board[row][col] = '8';
                        return;
                    }
                }
                board[row][col] = '8';
                cout << "Moved east." << endl;
            }
            break;
        case 3:
            if(check(direction)) {
                cout << "Can't move south. Try again." << endl;
                return;
            }
            else {
                board[row][col] = '*';
                for(int i = 0; i < dice_roll; i++) {
                    row++;
                    if(check(direction)) {
                        cout << "Oops. You've hit the wall. Can't move anymore." << endl;
                        board[row][col] = '8';
                        return;
                    }
                }
                board[row][col] = '8';
                cout << "Moved south." << endl;
            }
            break;
        case 4:
            if(check(direction)) {
                cout << "Can't move west. Try again." << endl;
                return;
            }
            else {
                board[row][col] = '*';
                for(int i = 0; i < dice_roll; i++) {
                    col--;
                    if(check(direction)) {
                        cout << "Oops. You've hit the wall. Can't move anymore." << endl;
                        board[row][col] = '8';
                        return;
                    }
                }
                board[row][col] = '8';
                cout << "Moved west." << endl;
            }
            break;
    }

}

//make sure that the player is not going out of bounds
bool check(int direction) {
    if(direction == 1) {
        for(int i = 0; i < 5; i++) {
            if(row == 0 && col == i)
                return true;
        }
    }
    else if(direction == 2) {
        if(col == 4)
            return true;
    }
    else if(direction == 3) {
        for(int i = 0; i < 5; i++) {
            if(row == 4 && col == i)
                return true;
        }
    }
    else if(direction == 4) {
        if(col == 0)
            return true;
    }
    return false;
}

//check if player has reached the exit
bool check(int r, int c) {
    if(r == 4 && c == 4) return true;
    else return false;
}