#include "iostream"
#include "vector"

class Dinglemouse {
    std::string name;
    int age;
    char sex;

public:

    Dinglemouse() {
    }

    Dinglemouse &setAge(int age) {
        this->age = age;

        for (int i = 0; i < order.size(); i++) {
            if (order[i] == 3) {
                return *this;
            }
        }

        order.push_back(3);
        return *this;
    }

    Dinglemouse &setSex(char sex) {
        this->sex = sex;

        for (int i = 0; i < order.size(); i++) {
            if (order[i] == 2) {
                return *this;
            }
        }

        order.push_back(2);
        return *this;
    }

    Dinglemouse &setName(const std::string &name) {
        this->name = name;

        for (int i = 0; i < order.size(); i++) {
            if (order[i] == 1) {
                return *this;
            }
        }

        order.push_back(1);

        return *this;
    }

    std::vector<int> order;

    std::string hello() {
        std::string result = "Hello.";

        for (int i = 0; i < order.size(); i++) {
            if (order[i] == 1) {
                result += " My name is " + name + ".";
            } else if (order[i] == 3) {
                result += " I am " + std::to_string(age) + ".";
            } else if (order[i] == 2) {
                result += " I am ";
                result += ('M' == sex ? "male." : "female.");
            };

        }

        return result;
    }

};

int main() {
    Dinglemouse dinglemouse;
    dinglemouse.setName("Alice").setAge(24).setSex('F').setName("Bob").setSex('M');
    std::cout << dinglemouse.hello() << std::endl;
    return 0;
}