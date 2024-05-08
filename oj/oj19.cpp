#include <vector>
#include <iostream>
#include <cstdint>

std::vector<uint64_t> powers_of_two(int n) {
    std::vector<uint64_t> result;
    for (int i = 0; i <= n; i++) {
        result.push_back(1ULL << i);
    }
    return result;
}

int main() {
    int n = 54;
    std::vector<uint64_t> result = powers_of_two(n);

    for (uint64_t num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
