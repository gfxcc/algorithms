//
// Created by Yong Cao at Dec/22/2017
//
//

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdio.h>

using std::string;
using std::vector;
using std::unordered_map;

class Parser {
public:

  Parser(const string& grammar);
  bool parse(const string& pattern, const string& input);

  void print_grammar() {
    printf("-----grammar------\n");
    for (auto& rule : grammar_) {
      for (auto& right : rule.second) {
        printf("%c -> %s\n", rule.first, right.c_str());
      }
    }
  }

private:

  unordered_map<char, vector<string>> grammar_;
};

class Rule {
public:
  char left;
  vector<char> right;

};
