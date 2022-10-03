#include <iostream>  
using namespace std;
int main()
{
    setlocale(0, "");
    int taskNumber;
    cout << "������� ����� �������: ";
    cin >> taskNumber;

    switch (taskNumber)
    {
    case 1:
        // 1) �������, ������� ������ (� ������) �� ����� ���������� ��������� ��� ��������� ���� ������ �� ��������������� � ���: int, short int, long int, float, double, long double, char � bool.

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
        // 2) ������� �� ����� �������� ������������� � ������ (��� �������) ������ �����. ��� ������ ���������� ��������� ���������� �������� ������ � �������� ������� ��������� ��� ������.
    {
        cout << "\n������� ����� ���� int: ";
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
        } // ������� ����� �������������� ��� ����� input
        break;
    }
    case 3:
        // 3) ������� �� ����� �������� ������������� � ������ (��� �������) ���� float. ��� ������ ���������� ��������� ���������� �������� ������ ��������, �������� ������ ������� (���� ����), �������� � �������.
    {
        union {
            int tool;
            float input;
        };
        cout << "\n������� ����� ���� float: ";
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
        // 4) ������� �� ����� �������� ������������� � ������ (��� �������) ���� double. ��� ������ ���������� ��������� ���������� �������� ������ ��������, �������� ������ ������� (���� ����), �������� � �������. (*)
    {
        union {
            double input;
            int arr[2];
        };
        cout << "\n������� ����� ���� double: ";
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