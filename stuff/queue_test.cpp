#include "iostream"
#include "unordered_map"

class Solution {
public:
    int romanToInt(std::string &s) {
        int result = 0;
        std::unordered_map<char, int> romanMap;

        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;

        for (int i = 0; i < s.size(); i++) { // iterate through the string
            if (i > 0 and romanMap[s[i]] > romanMap[s[i - 1]]) { // if the current value is greater than the previous value
                result += romanMap[s[i]] - 2 * romanMap[s[i - 1]]; // subtract the previous value from the current value
            } else {
                result += romanMap[s[i]]; // add the current value to the result
            }
        }

        return result;
    }

    int factorial(int n) {
        if (n == 0) {
            return 1;
        }
        return n * factorial(n - 1);
    }

    int stringToNumber(const std::string &digits) {
        int number = 0;
        for (int i = 0; i < digits.size(); ++i) {
            number = number * 10 + (digits[i] - '0'); // make  numbers from string, "123" --> 123
        }
        return number;
    }

};



int main() {
    std::string s = "MCMXCIV";
    Solution solution;
    Solution solution1;
    Solution solution2;

    std::cout << solution2.stringToNumber("123") << std::endl;
    std::cout << solution1.factorial(5) << std::endl;
    std::cout << solution.romanToInt(s) << std::endl;
    return 0;
}