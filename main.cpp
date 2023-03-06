#include <iostream>
#include "functions.h"
#include "Timer.h"

int main()
{

    const int arraySize = 1000;

    int *a = create_array(arraySize);

    int *b = copy_array(a, arraySize);

    std::cout << std::endl;

    {
        Timer t("bubble sort");
        int *sorted = bubble_sort(b, arraySize);
    }

    int *c = copy_array(a, arraySize);

    {
        Timer t("fast sort");
        int *sorted = fast_sort(c, arraySize);
    }

    std::cout << std::endl;
}
