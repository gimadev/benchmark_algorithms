#include <iostream>
#include "functions.h"
#include "Timer.h"

int main()
{

    const int arraySize = 1000;
    
    std::cout << std::endl << "number of elements " << arraySize << std::endl;

    int *a = create_array(arraySize);

    int *a1 = copy_array(a, arraySize);

    std::cout << std::endl;

    {
        Timer t("stupid sort");
        int *sorted = stupid_sort(a1, arraySize);
    }

    int *a2 = copy_array(a, arraySize);

    {
        Timer t("fast sort");
        int *sorted = fast_sort(a2, arraySize);
    }

    int *a3 = copy_array(a, arraySize);

    {
        Timer t("bubble sort");
        int *sorted = bubble_sort(a3, arraySize);
    }

    std::cout << std::endl;
}
