#include <iostream>  
using namespace std;
int main()
{
    setlocale(0, "");
    int taskNumber;
    cout << "Enter the task number: ";
    cin >> taskNumber;

    switch (taskNumber)
    {
    case 1:
        // task 1

        cout << "\nint: " << sizeof(int) << "\n";
        cout << "short int: " << sizeof(short int) << "\n";
        cout << "long int: " << sizeof(long int) << "\n";
        cout << "float: " << sizeof(float) << "\n";
        cout << "double: " << sizeof(double) << "\n";
        cout << "long double: " << sizeof(long double) << "\n";
        cout << "char: " << sizeof(char) << "\n";
        cout << "bool: " << sizeof(bool) << "\n\n";
        break;

    case 2:
        // task 2
    {
        cout << "\nEnter int: ";
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
        break;
    }
    case 3:
        // task 3
    {
        union {
            int tool;
            float input;
        };
        cout << "\nEnter float: ";
        cin >> input;
        int a = sizeof(int) * 8;
        int mask = 1 << a - 1;
        for (int i = 1; i <= a; i++)
        {
            cout << ((tool & mask) ? 1 : 0);
            if (i == 1 || i % 8 == 0)
                cout << " ";
            tool <<= 1;
        }
        break;
    }
    case 4:
        // task 4
    {
        union {
            double input;
            int arr[2];
        };
        cout << "\nEnter double: ";
        cin >> input;
        int a = sizeof(int) * 8;
        int mask = 1 << a - 1;
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
    }
    }
}
