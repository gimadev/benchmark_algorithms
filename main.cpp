#include <iostream>
#include "functions.h"

int main()
{

    const int arraySize = 100;

    int *a = create_array(arraySize);

    int *b = copy_array(a, arraySize);

    int *sorted = bubble_sort(b, arraySize);

    print_arr(sorted, arraySize);
    
}
