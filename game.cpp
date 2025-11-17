#include <iostream>
using namespace std;

char space[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int row;
int column;
char token = 'x';
bool isTie = false;
string n1 = "";
string n2 = "";

void functionOne() {

    cout << "\nCurrent Board:\n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << "\n\n";
}

void functionTwo() {

    int digit;

    if(token == 'x')
    {
        cout << n1 << ", please enter a number: ";
        cin >> digit;
    }

    if(token == '0')
    {
        cout << n2 << ", please enter a number: ";
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
    else
    {
        cout << "Invalid !!!" << endl;
        return;
    }

    if(token == 'x' && space[row][column] != 'x' && space[row][column] != 'o')
    {
        space[row][column] = 'x';
        token = '0';
    }
    else if(token == '0' && space[row][column] != 'x' && space[row][column] != 'o')
    {
        space[row][column] = 'o';
        token = 'x';
    }
    else
    {
        cout << "There is no empty space!" << endl;
        functionTwo();
    }
}

bool functionThree() {

    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[1][i] == space[2][i]))
        {
            return true;
        }
    }

    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[2][0] == space[1][1] && space[1][1] == space[0][2]))
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != 'o')
            {
                return false;
            }
        }
    }

    isTie = true;
    return true;
}

int main()
{
    while (true)
    {
        cout << "Enter the name of the first player: ";
        getline(cin, n1);

        cout << "Enter the name of the second player: ";
        getline(cin, n2);

        if (n1 == n2)
        {
            cout << "Both players cannot have the same name. Please enter different names.\n\n";
        }
        else
        {
            break;
        }
    }

    cout << n1 << " is player1, so he/she will play first.\n";
    cout << n2 << " is player2, so he/she will play second.\n\n";

    while(!functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
    }

    functionOne();

    if(token == '0' && isTie == false)
    {
        cout << n1 << " wins!" << endl;
    }
    else if(token == 'x' && isTie == false)
    {
        cout << n2 << " wins!" << endl;
    }
    else
    {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
