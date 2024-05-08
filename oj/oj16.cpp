#include <string>
#include <iostream>


std::string even_or_odd(int number) {
    if (number % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }

}

int main() {
    int number;
    std::cin >> number;
    std::cout << even_or_odd(number) << std::endl;
    return 0;
}