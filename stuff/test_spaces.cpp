#include "iostream"

using namespace std;

int main() {
    cout << "What is your name?:     ";
    string name;
    cin >> name;
    cin.clear();    //  clear the input buffer

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    //  ignore the rest of the line (if any


    cout << "Hello, " << name << "!" << endl;

    return 0;
}