#include "easyfind.hpp"
#include <vector>
int main(){
    std::vector<int> v = {1,2,3,4,5,6,7,8};
    std::cout << *easyfind<std::vector<int>>(v, 1) << "\n";
    try {
        std::cout << *easyfind<std::vector<int>>(v, 9) << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}