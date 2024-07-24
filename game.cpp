#include <iostream>
#include <string.h>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'X';
bool tie = false;
string n1 = "";
string n2 = "";

void pattern_one()
{

    cout << "       |       |       \n";
    cout << "  " << space[0][0] << "    |   " << space[0][1] << "   |   " << space[0][2] << "      \n";
    cout << "       |       |       \n";
    cout << "------------------------\n";
    cout << "       |       |       \n";
    cout << "  " << space[1][0] << "    |   " << space[1][1] << "   |   " << space[1][2] << "      \n";
    cout << "       |       |       \n";
    cout << "------------------------\n";
    cout << "       |       |       \n";
    cout << "  " << space[2][0] << "    |   " << space[2][1] << "   |   " << space[2][2] << "      \n";
    cout << "       |       |       \n";
}

void pattern_two()
{

    int digit;

    if (token == 'X')
    {
        cout << n1 << " please enter";
        cin >> digit;
    }
    if (token == '0')
    {
        cout << n2 << " please enter";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    else if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    else if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    else if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    else if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    else if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    else if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    else if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    else if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    if (digit < 1 || digit > 9)
    {
        cout << "CHOOSE BETWEEN 1 ANDS 9" << endl;
        pattern_two();
        return;
    }

    if (space[row][column] != 'X' && space[row][column] != '0')
    {
        space[row][column] = token;
        if (token == 'X')
            token = '0';
        else
            token = 'X';
    }

    else
    {
        cout << "INVALID....!!!!" << endl;
        pattern_two();
        return;
    }
    pattern_one();
}

bool pattern_3()
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2])
        {
            return true;
        }
        if (space[0][i] == space[1][i] && space[0][i] == space[2][i])
        {
            return true;
        }
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2])
    {
        return true;
    }
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie = true;
    return true;
}

int main()
{

    cout << "NAME  (PLAYER 1!!!!) ";
    getline(cin, n1);
    cout << "NAME (PLAYER 2) ";
    getline(cin, n2);
    cout << n1 << "  is player1 will play first\n";
    cout << n2 << "  is player2 will play second\n";
    pattern_one();
    while (!pattern_3())
    {

        pattern_two();
    }

    if (token == 'X' && !tie)
    {
        cout << n2 << "wins" << endl;
    }

    if (token == '0' && !tie)
    {
        cout << n1 << "wins" << endl;
    }
    else
    {
        cout << "It's a tie" << endl;
    }
}