/* THE PROJECT IS TIC TAC TOA , WHICH IS KNOWN AS (X O) GAME  */


// used pre-defined libraries and classes
#include <iostream>
#include <algorithm>
#include <fstream>//files in c++
#include <cstdio>//files in c
using namespace std;

// obj definition 
typedef struct board {
public:
    bool isfill = false;//avilable box
    char sym = ' ';

}; // definition for each element in board (box) using c paradigm ( structs )

// used functions

void put(board arr[][3]) { // find where is the last empty box exist 
    for (int c = 0; c < 3; c++) {
        if (arr[c][0].sym == ' ') {
            arr[c][0].sym = 'x';
            arr[c][0].isfill = true;
            return;
        }

        if (arr[c][1].sym == ' ') {
            arr[c][1].sym = 'x';
            arr[c][1].isfill = true;
            return;
        }

        if (arr[c][2].sym == ' ') {
            arr[c][2].sym = 'x';
            arr[c][2].isfill = true;
            return;
        }

    }
}

void show(board arr[][3]) { // show the board on command screen line (console)

    cout << "____________";

    cout << endl;
    for (int c = 0; c < 3; c++) {
        cout << "| " << arr[c][0].sym << " | " << arr[c][1].sym << " | " << arr[c][2].sym << " | ";
        cout << endl;
        cout << "|___|___|___|";
        cout << endl;

    }
}

void show(board arr[][3], FILE* p) { // overload show fun. to show the board 
    fprintf(p, "____________");// on file by using c syntax files
    fprintf(p, "\n");
    for (int c = 0; c < 3; c++) {
        fprintf(p, "| %c | %c | %c |", arr[c][0].sym, arr[c][1].sym, arr[c][2].sym);
        fprintf(p, "\n");
        fprintf(p, "|___|___|___|");
        fprintf(p, "\n");

    }
    fprintf(p, "\n");
}

ofstream& operator<<(ofstream& file, board arr[][3]) { // overload operator (<<) to show the board 
    file << "____________";// on file by using c++ syntax files
    file << endl;
    for (int c = 0; c < 3; c++) {
        file << "| " << arr[c][0].sym << " | " << arr[c][1].sym << " | " << arr[c][2].sym << " | ";
        file << endl;
        file << "|___|___|___|";
        file << endl;
    }
    file << endl;
    return file;
}

bool checkisfill(int a /*row*/, int b/*column*/, board arr[][3]) { // to check if the chosen box empty or not ,

    return arr[a][b].isfill;
}

bool winvertical(board arr[][3]) { // check if one of the players win vertically
    for (int c = 0; c < 3; c++)
        if ((arr[0][c].sym == arr[1][c].sym) && (arr[0][c].sym == arr[2][c].sym) && arr[0][c].sym != ' ')
            return true;
    return false;
}

bool winhorizantal(board arr[][3]) { // check if one of the players win horizantally
    for (int c = 0; c < 3; c++)
        if ((arr[c][0].sym == arr[c][1].sym) && (arr[c][0].sym == arr[c][2].sym) && arr[c][0].sym != ' ')
            return true;
    return false;
}

bool windiagonal(board arr[][3]) { // check if one of the players win diagonally

    if (((arr[0][0].sym == arr[1][1].sym) && (arr[0][0].sym == arr[2][2].sym) && arr[0][0].sym != ' ') || ((arr[0][2].sym == arr[1][1].sym) && (arr[0][2].sym == arr[2][0].sym) && arr[0][2].sym != ' '))
        return true;
    return false;
}

bool win(board arr[][3]) {

    if (windiagonal(arr) == true)
        return true;
    if (winhorizantal(arr) == true)
        return true;
    if (winvertical(arr) == true)
        return true;
    return false;

}


// the main 
int main()
{
    ofstream file("c++.txt");
    FILE* fi = fopen("c.txt", "w");


    board arr[3][3];

    char one, two;  // one : x(1st player)    two :o(2nd player)
    int a, b;// chosen indicies
    bool f = 1;
    int c = 1;
    for (; c <= 4; c++) {

        show(arr);
        file << arr;
        show(arr, fi);
        cout << "choose the location for your (X) as indeceies (the 1st player)" << endl;
        while (1) {

            cin >> a >> b;
            if (checkisfill(a, b, arr) == false)
                break;
            cout << "please choose another locationn !" << endl;
        }
        cout << "write x " << endl;
        cin >> one;
        arr[a][b].sym = one;
        arr[a][b].isfill = true;

        if (win(arr) == true) {// check if the 1st player win 
            cout << "the winner is the first player (X_X)!" << endl;
            f = 0;
            show(arr);
            file << arr;
            show(arr, fi);
            file << "the winner is the first player (X_X)!" << endl;
            fprintf(fi, "the winner is the first player (X_X)!\n");
            break;
        }

        show(arr);
        file << arr;
        show(arr, fi);


        cout << "choose the location for your (O) as indeceies (the 2nd player)" << endl;
        while (1) {
            cin >> a >> b;
            if (checkisfill(a, b, arr) == false)
                break;
            cout << "please choose another locationn !" << endl;
        }
        cout << "write o  ";
        cin >> two;
        arr[a][b].sym = two;
        arr[a][b].isfill = true;


        if (win(arr) == true) {// check if the 2nd player win 
            cout << "the winner is the second player (O_O)!" << endl;
            f = 0;
            show(arr);
            file << arr;
            show(arr, fi);
            file << "the winner is the second player (O_O)!" << endl;
            fprintf(fi, "the winner is the second player (O_O)!\n");
            break;
        }

    }
    if ((c == 5) && (f == 1)) {
        put(arr);
        show(arr);
        file << arr;
        show(arr, fi);
        if (win(arr) == true) {
            cout << "the winner is the first player (X_X)!" << endl;
            f = 0;
            show(arr);
            file << arr;
            show(arr, fi);
            file << "the winner is the second player (X_X)!" << endl;
            fprintf(fi, "the winner is the second player (xX_X)!\n");

        }
    }


    if (f == 1) {
        cout << "no one won the game !";
        file << "no one won the game !" << endl;
        fprintf(fi, "no one won the game !\n");
    }
}