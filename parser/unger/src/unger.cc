//
// Created by Yong Cao at Dec/22/2017
//
#include "unger.h"
#include <fstream>

using namespace std;

Parser::Parser(const string& grammar) {

    ifstream file(grammar);
    string line;

    while (getline(file, line)) {
        grammar_[line[0]].push_back(line.substr(5));
    }

}

bool Parser::parse(const string& pattern, const string& input) {

    if (pattern == input)
        return true;

    if (pattern.size() > input.size())
        return false;
    if (pattern.size() == 1) {
        for (auto& right : grammar_[pattern[0]]) {
            if (parse(right, input)) {
                printf("rule:%c->%s  conduct:%c->%s\n", pattern[0], right.c_str(), pattern[0], input.c_str());
                return true;
            }
        }
    }

    for (int len = 1; len < input.size(); len++) {
        string left = pattern.substr(0, 1), left_remain = pattern.substr(1);
        string right = input.substr(0, len), right_remain = input.substr(len);
        if (parse(left, right) && parse(left_remain, right_remain)) {
            return true;
        }
    }

    return false;
}
