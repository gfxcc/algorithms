//
// Created by Yong Cao at Dec/22/2017
//
#include "unger.h"
#include <fstream>
#include <queue>

using namespace std;

Parser::Parser(const string& grammar) {

    ifstream file(grammar);
    string line;

    while (getline(file, line)) {
        grammar_[line[0]].push_back(line.substr(5));
    }

}

bool Parser::parse(const string& pattern, const string& input) {

    printf("ROOT:%s\n", pattern.c_str());
    printf("input:%s\n", input.c_str());
    ptree_.reset();
    ptree_.set_root(pattern);
    bool rc = parse(pattern, input, ptree_.get_root());
    ptree_.print_tree();
    return rc;
}

bool Parser::parse(const string& pattern, const string& input, Node* node) {

    if (pattern == input && pattern.size() == 1) {
        node->children.push_back(make_shared<Node>(pattern));
        return true;
    }

    if (pattern.size() > input.size())
        return false;
    if (pattern.size() == 1) {
        for (auto& right : grammar_[pattern[0]]) {
            node->children.push_back(make_shared<Node>(right));
            if (parse(right, input, node->children.back().get())) {
                return true;
            }
            node->children.pop_back();
        }
        return false;
    }


    for (int len = 1; len < input.size(); len++) {
        string left = pattern.substr(0, 1), left_remain = pattern.substr(1);
        string right = input.substr(0, len), right_remain = input.substr(len);

        node->children.push_back(make_shared<Node>(left));
        if (parse(left, right, node->children.back().get()) &&
                parse(left_remain, right_remain, node)) {
            return true;
        }
        node->children.pop_back();
    }


    return false;
}
