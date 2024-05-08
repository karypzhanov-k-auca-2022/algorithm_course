#include "string"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

string replace(const string &s) {
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string result = s;

    for (char &c : result) {
        if (find(vowels.begin(), vowels.end(), c) != vowels.end()) {
            c = '!';
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    cout << replace(s) << endl;
    return 0;
}