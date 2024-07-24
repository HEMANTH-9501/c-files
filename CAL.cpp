#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "enter the value of a";
    cin >> a;
    cout << "enter the value of b";
    cin >> b;

    while (1)
    {
        cout << "\nENTER THE ARITHEMATIC OPERATIONS WHICH YOU WANT\n";
        cout << "1.+\n";
        cout << "2.-\n";
        cout << "3.*\n";
        cout << "4./\n";
        cout << "5.%\n";
        cout << "6.EXIT\n";
        char choice;
        cout << "enter your choice";
        cin >> choice;
        switch (choice)
        {
        case '+':
            cout << a << " + " << b << " = " << a + b << endl;
            break;
        case '-':
            cout << a << " - " << b << " = " << a - b << endl;
            break;
        case '*':
            cout << a << " * " << b << " = " << a * b << endl;
            break;
        case '/':
            if (b == 0)
            {
                cout << "Error: Division by zero!" << endl;
            }
            else
            {
                cout << a << " / " << b << " = " << a / b << endl;
                break;
            case '%':
                if (b == 0)
                {
                    cout << "Error: Division by zero!" << endl;
                }
                else
                {
                    cout << a << " % " << b << " = " << a % b << endl;
                    break;
                case '6':
                    cout << "THANK YOU FOR USING THIS PROGRAM";
                    exit(0);
                    break;
                default:
                    cout << "INVALID CHOICE";
                }
            }
        }
    }
}