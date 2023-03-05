#include <iostream>
#include "functions.h"

int main()
{

    const int arraySize = 100;

    int *a = create_array(arraySize);

    int *b = bubble_sort(a, arraySize);

    print_arr(b, arraySize);

    
}
