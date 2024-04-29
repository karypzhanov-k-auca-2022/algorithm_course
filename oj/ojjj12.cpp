#include "iostream"
#include <string>

using namespace std;

std::string solution(int number){
    // convert the number to a roman numeral
    string res = "";
    while(number >= 1000){
        res += "M";
        number -= 1000;
    }
    while(number >= 900){
        res += "CM";
        number -= 900;
    }
    while(number >= 500){
        res += "D";
        number -= 500;
    }
    while(number >= 400){
        res += "CD";
        number -= 400;
    }
    while(number >= 100){
        res += "C";
        number -= 100;
    }
    while(number >= 90){
        res += "XC";
        number -= 90;
    }
    while(number >= 50){
        res += "L";
        number -= 50;
    }
    while(number >= 40){
        res += "XL";
        number -= 40;
    }
    while(number >= 10){
        res += "X";
        number -= 10;
    }
    while(number >= 9){
        res += "IX";
        number -= 9;
    }
    while(number >= 5){
        res += "V";
        number -= 5;
    }
    while(number >= 4){
        res += "IV";
        number -= 4;
    }
    while(number >= 1){
        res += "I";
        number -= 1;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    string res = solution(n);

    cout << res << endl;
    return 0;
}