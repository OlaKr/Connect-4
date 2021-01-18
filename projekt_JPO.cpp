#include <iostream>
#include <string>
#include <vector>
#include "Gamer.h"
#include "GameOperations.h"
using namespace std;

int main(){

    cout << "Welcome to the game Connect 4!" << endl;
    cout << endl;

    Gamer player1;
    Gamer player2;
    vector<Gamer> v = { player1, player2 };         //dzięki temu wyświetlają mi sie wszyscy gracze- dzieki operatorowi wyjścia też
    
    cout << "Lets start our game!" << endl;
    cout << endl;
    
    cout << "First Player " << endl;
    cin >> v[0];
    cout << endl;

    cout << "Second Player " << endl;
    cin >> v[1];
    cout << endl;

    vector<vector<char>> matrix(6, vector<char>(7));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            matrix[i][j] = '*';
        }
    }
    
    fillBoard(matrix, v);
    newGame(matrix, v);
    
}
