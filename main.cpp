#include <iostream>
#include <chrono>
#include "Timer.h"
#include "functions.h"

int a[] = {54, 26, 13, 7, 21, 5, 90, 10, 2, 1, -500, 1, 0, 7, 21, 5, 90, 10, 2, 1, -500, 1, 0, 90, 90,102};

using namespace std;

int main()
{

    int size = end(a) - begin(a);

    int *b = bubble_sort(a, size);

    print_arr(b, size);
}
