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
int move(int, int);
bool check(int);
bool check(int, int);
bool check();
void place_obstacles();

int main(){
    cout << "Welcome to Robellion: the boardgame";
    cout << "You are the leader of the rebellion against the stupid humans " 
    << "and you must exit the robot factory" << endl;

    bool at_exit = false;
    int dice_roll = 0, direction = 0;
    place_obstacles();
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
        if(move(direction, dice_roll) == 0) return 0;
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
int move(int direction, int dice_roll) {
    switch(direction) {
        case 1:
            if(check(direction)) {
                cout << "Can't move north. Try again." << endl;
                return 1;
            }
            else {
                board[row][col] = '*';
                for(int i = 0; i < dice_roll; i++) {
                    row--;
                    if(check(direction)) {
                        if(check()) return 0;
                        cout << "Oops. You've hit the wall. Can't move anymore." << endl;
                        board[row][col] = '8';
                        return 1;
                    }
                }
                if(check()) return 0;
                board[row][col] = '8';
                cout << "Moved North." << endl;
            }
            break;
        case 2:
            if(check(direction)) {
                cout << "Can't move east. Try again." << endl;
                return 1;
            }
            else {
                board[row][col] = '*';
                for(int i = 0; i < dice_roll; i++) {
                    col++;
                    if(check(direction)) {
                        if(check()) return 0;
                        cout << "Oops. You've hit the wall. Can't move anymore." << endl;
                        board[row][col] = '8';
                        return 1;
                    }
                }
                if(check()) return 0;
                board[row][col] = '8';
                cout << "Moved east." << endl;
            }
            break;
        case 3:
            if(check(direction)) {
                cout << "Can't move south. Try again." << endl;
                return 1;
            }
            else {
                board[row][col] = '*';
                for(int i = 0; i < dice_roll; i++) {
                    row++;
                    if(check(direction)) {
                        if(check()) return 0;
                        cout << "Oops. You've hit the wall. Can't move anymore." << endl;
                        board[row][col] = '8';
                        return 1;
                    }
                }
                if(check()) return 0;
                board[row][col] = '8';
                cout << "Moved south." << endl;
            }
            break;
        case 4:
            if(check(direction)) {
                cout << "Can't move west. Try again." << endl;
                return 1;
            }
            else {
                board[row][col] = '*';
                for(int i = 0; i < dice_roll; i++) {
                    col--;
                    if(check(direction)) {
                        if(check()) return 0; 
                        cout << "Oops. You've hit the wall. Can't move anymore." << endl;
                        board[row][col] = '8';
                        return 1;
                    }
                }
                if(check()) return 0;
                board[row][col] = '8';
                cout << "Moved west." << endl;
            }
            break;
    }
    cout << "Input not one of the accepted values. Please try again.";
    return 1;
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

//check if player landed on an obstacle
bool check() {
    if(board[row][col] == 'O') {
        cout << "You've hit an obstacle. Game over." << endl;
        return true;
    }
    return false;
}

//places random obstacles on the board
//if a player lands on one, it is gameover
//**tweek algorithm to make sure the game is still winable**
void place_obstacles() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == '*') {
                int random = rand() % 100;
                if(random % 3) {
                    board[i][j] = 'O';
                }
            }
        }
    }
    return;
}