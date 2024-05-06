#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

class ProdFib
{
public:
    static std::vector<ull> productFib(ull prod) {
        ull prev = 0, curr = 1;
        while (prev * curr < prod) {
            ull next = prev + curr;
            prev = curr;
            curr = next;
        }
        return {prev, curr, prev * curr == prod};
    }
};

int main() {
    ull prod;
    cin >> prod;

    vector<ull> result = ProdFib::productFib(prod);
    cout << result[0] << " " << result[1] << " " << result[2] << endl;

    return 0;
}