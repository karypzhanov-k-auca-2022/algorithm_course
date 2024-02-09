#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<string> words;
vector<string> rules;

struct State {
    string password;
    int ruleIndex;
};

void generatePasswords(string rule) {
    stack<State> states;
    for (const string& word : words) {
        states.push({word, 1});
    }

    while (!states.empty()) {
        State current = states.top();
        states.pop();

        if (current.ruleIndex == rule.size()) {
            cout << current.password << endl;
        } else if (rule[current.ruleIndex] == '0') {
            for (int i = 0; i < 10; i++) {
                states.push({current.password + to_string(i), current.ruleIndex + 1});
            }
        } else if (rule[current.ruleIndex] == '#') {
            for (const string& word : words) {
                states.push({current.password + word, current.ruleIndex + 1});
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n) {
        words.resize(n);
        for (string& word : words) {
            cin >> word;
        }

        cin >> m;
        rules.resize(m);
        for (string& rule : rules) {
            cin >> rule;
        }

        cout << "--" << endl;
        for (const string& rule : rules) {
            generatePasswords(rule);
        }
    }

    return 0;
}
