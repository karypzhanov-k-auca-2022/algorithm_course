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
            cin >> word; // directly read into the word
        }

        cin >> m;
        vector<string> rules(m); // create sized vector for rules

        for (auto &rule: rules) {
            cin >> rule; // directly read into the rule
        }

        cout << "--" << endl;

        // Generate passwords for each rule
        for (auto &rule: rules) {
            generatePasswords("", {rule, 0});
        }

        cout << allPasswords;   // Print all passwords to only 1 rule
        allPasswords = ""; // then clear for the next word
    }

    return 0;
}

void generatePasswords(string password, RuleIndex ruleIndex) {
    if (ruleIndex.index == ruleIndex.rule.size()) { // go by index through all rules
        allPasswords += password + "\n"; // each line
        return; // base case
    }

    if (ruleIndex.rule[ruleIndex.index] == '0') {
        for (int i = 0; i < 10; i++) {
            int num = i;
            string numS = to_string(num);
            generatePasswords(password + numS, {ruleIndex.rule, ruleIndex.index + 1}); // add digits
        }
    } else if (ruleIndex.rule[ruleIndex.index] == '#') {
        for (auto &word: words) {
            generatePasswords(password + word, {ruleIndex.rule, ruleIndex.index + 1}); // add word
        }
    }
}
