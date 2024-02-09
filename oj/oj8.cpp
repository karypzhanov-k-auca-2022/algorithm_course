#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> words;
string allPasswords;

struct RuleIndex {
    string rule;
    int index;
};

void generatePasswords(string password, RuleIndex ruleIndex);

int main() {
    int n, m;

    while (cin >> n) {
        words.resize(n); // create sized vector for words

        for (auto &word: words) {
            string currW;
            cin >> currW;
            word += currW;
        }

        cin >> m;
        vector<string> rules(m); // create sized vector for rules

        for (auto &rule: rules) {
            string currR;
            cin >> currR;
            rule += currR;
        }

        cout << "--" << endl;

        // Generate passwords for each rule
        for (auto &rule: rules) {
            generatePasswords("", {rule, 0});
        }

        // Print all passwords
        cout << allPasswords;
        allPasswords = ""; // Clear the passwords
    }

    return 0;
}

void generatePasswords(string password, RuleIndex ruleIndex) {
    if (ruleIndex.index == ruleIndex.rule.size()) {
        allPasswords += password + "\n"; // each line
        return;
    }

    if (ruleIndex.rule[ruleIndex.index] == '0') {
        for (int i = 0; i < 10; i++) {
            generatePasswords(password + to_string(i), {ruleIndex.rule, ruleIndex.index + 1});
        }
    }
    else if (ruleIndex.rule[ruleIndex.index] == '#') {
        for (auto &word: words) {
            generatePasswords(password + word, {ruleIndex.rule, ruleIndex.index + 1});
        }
    }
}
