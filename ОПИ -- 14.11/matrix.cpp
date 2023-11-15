#include<iostream>
#include<stdlib.h> 
#include<time.h>
#include"Windows.h"
#include"task 1 & 2.h"

using namespace std;

int menu() {
    int action;
    cout << "1.Fist task" << endl;
    cout << "2.Second tast" << endl;
    cout << "3.Exit" << endl;
    cin >> action;
    return action;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    for (; ;)
    {
        system("cls");

        switch (menu())
        {
        case 1:
            first_task();
            break;
        case 2:
            second_task();
            break;
        case 3:
            return 0;
            break;
        default:
            break;
        }
        system("pause");
    }







    return 0;
}
