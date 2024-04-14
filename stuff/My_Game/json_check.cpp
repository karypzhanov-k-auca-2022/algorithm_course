#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

struct Budget {
    int financial;
    int resource;
    int ecological;
};

struct Option {
    int cost;
    int capacity_increase;
    int resources_required;
    int impact_score;
};

int main() {
    // Открыть JSON-файл для чтения
    ifstream file("data1.json");
    if (!file.is_open()) {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    // Прочитать данные из JSON-файла
    json data;
    file >> data;

    // Извлечь данные о бюджете
    Budget budget = {
            data["financial"],
            data["resource"],
            data["ecological"]
    };

    // Извлечь данные о вариантах
    vector<Option> options;
    for (const auto& option : data["options"]) {
        options.push_back({
                                  option["cost"],
                                  option["capacity_increase"],
                                  option["resources_required"],
                                  option["impact_score"]
                          });
    }

    // Реализовать алгоритм, используя полученные данные

    // Пример вывода данных о бюджете
    cout << "Financial Budget: " << budget.financial << endl;
    cout << "Resource Budget: " << budget.resource << endl;
    cout << "Ecological Budget: " << budget.ecological << endl;

    // Пример вывода данных о вариантах
    cout << "Options:" << endl;
    for (const auto& option : options) {
        cout << "Cost: " << option.cost << ", ";
        cout << "Capacity Increase: " << option.capacity_increase << ", ";
        cout << "Resources Required: " << option.resources_required << ", ";
        cout << "Impact Score: " << option.impact_score << endl;
    }

    return 0;
}
