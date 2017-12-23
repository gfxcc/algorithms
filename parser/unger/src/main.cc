//
// Created by Yong Cao at Dec/22/2017
//


#include "unger.h"

using namespace std;

int main() {

  Parser parser("./data/grammar.dat");

  parser.print_grammar();

  printf("----parsing process----\n");
  parser.parse("E", "a*a+a");

  return 0;
}
