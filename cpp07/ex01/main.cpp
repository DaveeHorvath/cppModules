#include "iter.h"

int main()
{
    int arr[] = {1,2,3,4,5};

    iter<int>(&(arr[0]), 5, f2<int>);
    std::cout << "\n";
    iter<int>(&(arr[0]), 5, f1<int>);
    iter<int>(&(arr[0]), 5, f2<int>);
    std::cout << "\n";

    char arr2[] = {'g','d','k','k','n'};
    iter<char>(&(arr2[0]), 5, f2<char>);
    std::cout << "\n";
    iter<char>(&(arr2[0]), 5, f1<char>);
    iter<char>(&(arr2[0]), 5, f2<char>);
    std::cout << "\n";

    // maybe test for compiler errors/warning for the concept
}