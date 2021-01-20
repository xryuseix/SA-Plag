#include <iostream>
#include <regex>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool ch = 0;
    if (regex_match(s, regex(".*keyence")) ||
        std::regex_match(s, regex("keyence")) ||
        std::regex_match(s, regex("k.*eyence$")) ||
        std::regex_match(s, regex("ke.*yence")) ||
        std::regex_match(s, regex("key.*ence")) ||
        std::regex_match(s, regex("keyen.*ce")) ||
        std::regex_match(s, regex("keye.*nce")) ||
        std::regex_match(s, regex("keyenc.*e")) ||
        std::regex_match(s, regex("keyence.*"))) {
        ch = 1;
    }
    if (ch)
        cout << ("YES") << endl;
    else
        cout << ("NO") << endl;
}
