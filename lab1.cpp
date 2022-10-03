#include <iostream>  
using namespace std;
int main()
{
    cout << "\t\tTask 1\n";
    cout << "int: " << sizeof(int) << "\n";
    cout << "short int: " << sizeof(short int) << "\n";
    cout << "long int: " << sizeof(long int) << "\n";
    cout << "float: " << sizeof(float) << "\n";
    cout << "double: " << sizeof(double) << "\n";
    cout << "long double: " << sizeof(long double) << "\n";
    cout << "char: " << sizeof(char) << "\n";
    cout << "bool: " << sizeof(bool);

    cout << "\n\n\t\tTask 2\n";
    cout << "Enter int: ";
    int input;
    cin >> input;
    int a = sizeof(int) * 8;
    int mask = 1 << a - 1;
    for (int i = 1; i <= a; i++)
    {
        cout << ((input & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";

        input <<= 1;
    }

    cout << "\n\n\t\tTask 3\n";
    union {
        int tool;
        float f;
    };
    cout << "Enter float: ";
    cin >> f;
    for (int i = 1; i <= a; i++)
    {
        cout << ((tool & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        tool <<= 1;
    }

    cout << "\n\n\t\tTask 4\n";
    union {
        double d;
        int arr[2];
    };
    cout << "Enter double: ";
    cin >> d;
    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[1] & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        arr[1] <<= 1;
    }
    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[0] & mask) ? 1 : 0);
        if (i % 8 == 0)
            cout << " ";
        arr[0] <<= 1;
    }
    cout << "\n\n";
}
