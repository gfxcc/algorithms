//
// Created by Yong Cao at Dec/26/2017
//

#include <stdio.h>

#include "ascii_tree.h"

using namespace std;

namespace AsciiTree {

Tree::Tree() {
    root_ = make_shared<Node>("");
}

bool Tree::load_binary_tree() {
    return false;
}


Node* Tree::get_root() {
    return root_.get();
}

void Tree::print_tree() {
    pre_order(root_.get());
}

void Tree::pre_order(Node* node) {
    printf("(%s)\n", node->data.c_str());

    for (int i = 0; i != node->children.size(); i++) {
        auto child = node->children[i];
        printf("%s `--", prefix.c_str());
        push_level(i + 1 == node->children.size() ? ' ' : '|');
        pre_order(child.get());
        pop_level();
    }
}

void Tree::push_level(char c) {
    prefix.push_back(' ');
    prefix.push_back(c);
    prefix.push_back(' ');
    prefix.push_back(' ');
}

void Tree::pop_level() {
    prefix = prefix.substr(0, prefix.size() - 4);
}


} // AsciiTree