#include <iostream>
#include "Timer.h"

int *create_array(int size)
{
    int *a = new int[size];

    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 10000;
    }

    return a;
}

int *copy_array(int *a, int size)
{
    int *b = new int[size];

    for (int i = 0; i < size; i++)
    {
        b[i] = a[i];
    }

    return b;
}

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

int *bubble_sort(int *a, int size)
{
    int i = 0;

    Timer t("bubble sort");

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

    return a;
}