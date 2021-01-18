#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <sstream>
#include "GameOperations.h"

using namespace std;

void showBoard(vector<vector<char>> matrix) {           //wywo³anie tabilicy gry
    cout << "Our board: " << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }
    matrix.clear();
}

bool overflowedBoard(vector<vector<char>> matrix) {         //sprawdzenie, czy w tablicy zosta³y wolne miejsca do wype³nienia
    if (matrix[0][0] != '*' && matrix[0][1] != '*' && matrix[0][2] != '*' && matrix[0][3] != '*' && matrix[0][4] != '*' && matrix[0][5] != '*' && matrix[0][6] != '*') {
        cout << "Board is full" << endl;
        return false;
    }
    return true;
}

bool endGame(vector<vector<char>> matrix, vector<Gamer> v) {            //sprawdzenie, czy spe³nione zosta³y warunki wygranej

    for (auto rr : v) {
        //poziomo
        for (int w = 0; w < 6; w++) {
            for (int i = 0; i < 4; i++) {
                if (matrix[w][i] == rr.get_sign() && matrix[w][i + 1] == rr.get_sign() && matrix[w][i + 2] == rr.get_sign() && matrix[w][i + 3] == rr.get_sign()) {
                    cout << "Player " << rr.get_nick() << " won the game!" << endl;
                    return false;
                }
            }
        }

        //ukosem
        for (int w = 5; w > 2; w--) {
            for (int i = 3; i < 7; i++) {
                if (matrix[w][i] == rr.get_sign() && matrix[w - 1][i - 1] == rr.get_sign() && matrix[w - 2][i - 2] == rr.get_sign() && matrix[w - 3][i - 3] == rr.get_sign()) {
                    cout << "Player " << rr.get_nick() << " won the game!" << endl;
                    return false;
                }
            }
        }

        //drugim ukosem
        for (int w = 5; w > 2; w--) {
            for (int i = 0; i < 4; i++) {
                if (matrix[w][i] == rr.get_sign() && matrix[w - 1][i + 1] == rr.get_sign() && matrix[w - 2][i + 2] == rr.get_sign() && matrix[w - 3][i + 3] == rr.get_sign()) {
                    cout << "Player " << rr.get_nick() << " won the game!" << endl;
                    return false;
                }
            }
        }

        //pionowo
        for (int i = 0; i < 7; i++) {
            for (int w = 0; w < 3; w++) {
                if (matrix[w][i] == rr.get_sign() && matrix[w + 1][i] == rr.get_sign() && matrix[w + 2][i] == rr.get_sign() && matrix[w + 3][i] == rr.get_sign()) {
                    cout << "Player " << rr.get_nick() << " won the game!" << endl;
                    //continue;

                    return false;

                }
            }
        }
    }
    return true;
}

void fillBoard(vector<vector<char>> matrix, vector<Gamer> v) {          //gracze wybieraja pozycjê, na której chc¹ umieœciæ swój znak

    system("cls");
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << endl;
    showBoard(matrix);
    while (overflowedBoard(matrix) && endGame(matrix, v)) { //rob dopoki jedno i drugie to true

        for (auto i : v) {

            cout << endl;
            cout << i.get_nick() << " choose a number from 1 to 7: " << endl;
            string number;
            cin >> number;

            if (number == "exit")
                return;

            vector<string> nums{ "1", "2", "3", "4", "5", "6", "7" };
            auto it = find(nums.begin(), nums.end(), number);
            if (it == nums.end()) {
                bool FLAG = true;
                while (FLAG) {
                    cout << "Try again: " << endl;
                    cin >> number;
                    auto it = find(nums.begin(), nums.end(), number);
                    if (it != nums.end()) FLAG = false;
                }
            }

            stringstream convert(number);
            int converted;
            convert >> converted;
            int position;
            position = converted - 1;

            if (matrix[0][position] != '*') {
                bool FLAG = true;
                while (FLAG) {
                    cout << "This column is overflowed, please select another number:" << endl;
                    //string number;
                    cin >> number;
                    auto it = find(nums.begin(), nums.end(), number);
                    if (it == nums.end()) {
                        do {
                            cout << "Try again: " << endl;
                            cin >> number;
                            auto it = find(nums.begin(), nums.end(), number);
                            if (it != nums.end())
                                break;
                            
                        } while (it == nums.end());
                    }
                    
                    stringstream convert(number);
                    int he;
                    convert >> he;
                    position = he - 1;

                    if (matrix[0][position] == '*') FLAG = false;
                }
            }

            int g = 5;
            if (matrix[g][position] == '*')
                matrix[g][position] = i.get_sign();
            else {
                if (matrix[g - 1][position] == '*')
                    matrix[g - 1][position] = i.get_sign();
                else {
                    if (matrix[g - 2][position] == '*')
                        matrix[g - 2][position] = i.get_sign();
                    else {
                        if (matrix[g - 3][position] == '*')
                            matrix[g - 3][position] = i.get_sign();
                        else {
                            if (matrix[g - 4][position] == '*')
                                matrix[g - 4][position] = i.get_sign();
                            else
                                matrix[g - 5][position] = i.get_sign();
                        }
                    }
                }
            }

            system("cls");
            cout << v[0] << endl;
            cout << v[1] << endl;
            cout << endl;
            showBoard(matrix);

            if (endGame(matrix, v) == false)
                return;
     
        }
    }
}

void newGame(vector<vector<char>> matrix, vector<Gamer> v) {            //rozpoczyna now¹ grê
    cout << endl;

    cout << "Do you want to play again?" << endl;
    cout << "Write yes or no: ";
    string answer;
    cin >> answer;

    if (answer != "yes" && answer != "no") {
        bool FLAG = true;
        while (FLAG) {
            cout << "Try again: ";
            cin >> answer;
            if (answer == "yes" || answer == "no") FLAG = false;
        }
    }

    if (answer == "yes") {
        bool FLAG = true;
        while (FLAG) {

            fillBoard(matrix, v);
            cout << "Do you still want to play?" << endl;
            cout << "Write yes or no: ";
            cin >> answer;
            if (answer != "yes") FLAG = false;
        }
    }

    if (answer == "no")
        cout << "See you next time!" << endl;

}