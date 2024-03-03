#include "iostream"
#include "unordered_set"

using namespace std;

int main() {
    unordered_set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);



    for (int i : set) {
        cout << i << endl;
    }

}