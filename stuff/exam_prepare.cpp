#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size()-1; // Получаем размер строки num
        string s=""; // Создаем пустую строку s
        int index; // Объявляем переменную index

        // Начинаем перебор символов справа налево
        for(int i=n;i>=0;i--){
            if(num[i]%2 != 0){ // Если текущий символ нечетный
                index = i; // Запоминаем его индекс
                break; // Прерываем цикл
            }
        }

        // Формируем подстроку с первого символа до index включительно
        for(int i=0;i<=index;i++){
            s+=num[i];
        }

        return s; // Возвращаем подстроку
    }
};

int main() {
    Solution s;
    string w = "35427";

    cout << s.largestOddNumber(w) << "\n";

    return 0;
}