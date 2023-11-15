#pragma once

#include<iostream>
#include<stdlib.h> 
#include<time.h>
#include"Windows.h"

using namespace std;

void first_task() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    const int m = 3;
    const int n = 4;
    int A[m][n];

    int count = 0;

    //заполнение массива случайными числами и показ на экран

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
            cout << A[i][j] << " ";
        }
        cout << "\n\n";
    }

    //поск нулевых элементов в массиве
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 0) {
                count++;
            }
        }
    }

    cout << "Количество нулей в массиве -- " << count << endl;
}
/////////////////////////

void matrix_show(int** A, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "\n\n";
    }
}

int matrix_a(int** A, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (A[i][j] >= max)
            {
                max = A[i][j];
                //A[i][j] = 1; -- проверка
            }
        }
    }
    return max;
};

int matrix_b(int** A, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (A[i][j] >= max)
            {
                max = A[i][j];
                //A[i][j] = 1;
            }
        }
    }
    return max;
};

int matrix_v(int** A, int n)
{
    int max = 0;
    for (int i = 0; i <= n / 2; i++) {
        for (int j = i; j < n && j < n - i; j++) {
            if (A[i][j] >= max)
            {
                max = A[i][j];
            }
            //A[i][j] = 1;
        }
    }
    return max;
};

int matrix_g(int** A, int n)
{
    int max = n / 2;
    for (int i = n - 1; i >= n / 2; --i) {
        for (int j = i; j >= 0 && j >= n - i - 1; --j) {
            if (A[i][j] >= max)
            {
                max = A[i][j];
            }
            //A[i][j] = 1;
        }
    }
    return max;
};

int matrix_d(int** A, int n)
{
    int max = 0;
    for (int i = 0; i <= n / 2; i++) {
        for (int j = i; j < n && j < n - i; j++) {
            if (A[i][j] >= max || A[n - i - 1][j] >= max)
            {
                max = A[i][j];
            }
            /* A[i][j] = 1;
             A[n - i-1][j] = 1;*/
        }
    }
    return max;
};

int matrix_e(int** A, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n / 2 && j <= i && j < n - i; j++) {
            if (A[i][j] >= max || A[i][n - j - 1] >= max)
            {
                max = A[i][j];
            }
            //A[i][j] = 1;
            //A[i][n-j-1] = 1;
        }
    }
    return max;
};

int matrix_zh(int** A, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n / 2 && j <= i && j < n - i; j++) {
            if (A[i][j] >= max)
            {
                max = A[i][j];
            }
            // A[i][j] = 1;
        }
    }
    return max;
};

int matrix_z(int** A, int n)
{
    int max = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = (i < n / 2) ? n - i - 1 : i; j < n; j++) {
            if (A[i][j] >= max)
            {
                max = A[i][j];
            }
            // A[i][j] = 1;
        }
    }

    return max;
};

int matrix_u(int** A, int n)
{
    int max = 0;
    for (int i = 0; i <= n / 2; i++) {
        for (int j = i; j < n && j < n - i; j++) {
            if (A[i][j] >= max && A[j][i] >= max)
            {
                max = A[i][j];
            }
            //A[i][j] = 1;
            //A[j][i] = 1;
        }
    }
    return max;
};

int matrix_k(int** A, int n)
{
    int max = n / 2;
    for (int i = n - 1; i >= n / 2; --i) {
        for (int j = i; j >= 0 && j >= n - i - 1; --j) {
            if (A[i][j] >= max && A[j][i] >= max)
            {
                max = A[i][j];
            }
            A[i][j] = 1;
            A[j][i] = 1;
        }
    }
    return max;
};
////////////////

void second_task()
{
    int n;
    cout << "Введите порядок матрицы: ";
    cin >> n;

    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
        }
    }
    int type_area, max_element;
    cout << "Select type search area (a-1, b-2, v-3, g-4, d-5, e-6, zh-7, z-8, u-9, k-10):\t";
    cin >> type_area;

    switch (type_area)
    {
    case 1:
        max_element = matrix_a(A, n);
        break;
    case 2:
        max_element = matrix_b(A, n);
        break;
    case 3:
        max_element = matrix_v(A, n);
        break;
    case 4:
        max_element = matrix_g(A, n);
        break;
    case 5:
        max_element = matrix_d(A, n);
        break;
    case 6:
        max_element = matrix_e(A, n);
        break;
    case 7:
        max_element = matrix_zh(A, n);
        break;
    case 8:
        max_element = matrix_z(A, n);
        break;
    case 9:
        max_element = matrix_u(A, n);
        break;
    case 10:
        max_element = matrix_k(A, n);
        break;
    default:
        break;
    }

    cout << endl << "Max element of area -- " << max_element << endl;
    cout << "All matrix: " << endl;
    matrix_show(A, n);

    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
}



