#include <string>
#include "iostream"

using namespace std;

std::string generateName(){
    string res = "";

    for(int i = 0; i < 6; i++){
        res += 'A' + rand() % 26;
    }
    return res;
}

int main(){
    cout << generateName() << endl;
    return 0;
}