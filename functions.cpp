#include <iostream>
#include <time.h>
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

int *stupid_sort(int *a, int size)
{
    int i = 0;

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

int *bubble_sort(int *a, int size)
{
    int i = 0;
    int last = size - 1;

    while (i < last)
    {
        if (a[i] > a[i + 1])
        {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }

        i++;

        if (i == last)
        {
            last--;
            i = 0;
        }
    }

    return a;
}

int *fast_sort(int *a, int size)
{
    if (size < 2)
    {
        return a;
    }

    if (size == 2)
    {
        if (a[0] > a[1])
        {
            int temp = a[0];
            a[0] = a[1];
            a[1] = temp;
        }

        return a;
    }

    srand(time(NULL));
    int support_i = rand() % size;

    int less = 0;
    int more = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] < a[support_i])
        {
            less++;
        }
        else
        {
            more++;
        }
    }

    int less_arr[less];
    int more_arr[more];

    less = 0;
    more = 0;

    for (int i = 0; i < size; i++)
    {
        if (i == support_i)
        {
            continue;
        }

        if (a[i] < a[support_i])
        {
            less_arr[less] = a[i];
            less++;
        }
        else
        {
            more_arr[more] = a[i];
            more++;
        }
    }

    if (less == 0)
    {
        int *sorted_more = fast_sort(more_arr, more);
        int *sorted = new int[more + 1];
        sorted[0] = a[support_i];

        for (int i = 0; i < more; i++)
        {
            sorted[i + 1] = sorted_more[i];
        }

        return sorted;
    }
    else if (more == 0)
    {
        int *sorted_less = fast_sort(less_arr, less);
        int *sorted = new int[less + 1];

        sorted[less] = a[support_i];

        for (int i = 0; i < less; i++)
        {
            sorted[i] = sorted_less[i];
        }

        return sorted;
    }
    else
    {
        int *sorted_less = fast_sort(less_arr, less);
        int *sorted_more = fast_sort(more_arr, more);
        int *sorted = new int[less + more + 1];

        sorted[less] = a[support_i];

        for (int i = 0; i < less; i++)
        {
            sorted[i] = sorted_less[i];
        }

        for (int i = 0; i < more; i++)
        {
            sorted[less + 1 + i] = sorted_more[i];
        }

        return sorted;
    }
}