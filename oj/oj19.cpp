#include <vector>

std::vector<uint64_t> powers_of_two(int n) {
    std::vector<uint64_t> result;
    for (int h: result) {
        result.push_back(1 << h);
    }
}