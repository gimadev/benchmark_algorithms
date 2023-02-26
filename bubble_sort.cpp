#include <iostream>
#include <chrono>
#include "Timer.h"

int a[] = {54, 26, 13, 7, 21, 5, 90, 10, 2, 1, -500, 1, 0, 7, 21, 5, 90, 10, 2, 1, -500, 1, 0, 90, 90,102};

using namespace std;

void print_arr(int *arr, int size);

int main()
{

    int size = end(a) - begin(a);

    int i = 0;

    {
        Timer t;

        while (i < size - 1)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                i = 0;
                continue;
            }

            i++;
        }
    }

    print_arr(a, size);
}

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
