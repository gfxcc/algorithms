//
// Created by Yong Cao at Dec/26/2017
//

#include <string>
#include <vector>
#include <memory>

namespace AsciiTree {

using std::shared_ptr;
using std::string;
using std::vector;

class Node {
public:
    Node(const string& data) : data(data) {}
    Node() {}
    string data;
    vector<shared_ptr<Node>> children;
};


class Tree {
public:

    Tree();

    bool load_binary_tree();
    Node* get_root();

    void print_tree();
    void set_root(const string& data) {
        root_->data = data;
    }

    void reset() {
        root_ = std::make_shared<Node>();
        prefix.clear();
    }

private:

    void pre_order(Node* node);
    void push_level(char c);
    void pop_level();

    shared_ptr<Node> root_;
    string prefix;
};

} // namespace As
