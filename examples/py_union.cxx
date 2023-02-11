#include <string>
using std::string;

struct Node {
    using AnyType = void;
    enum { kTypeInt, kTypeDouble, kTypeString } type;
    AnyType* data;
};

int main() {
    Node new_node{.type = Node::kTypeInt};
    new_node.type = Node::kTypeInt;
    int* ip = new int(3);
    new_node.data = ip;
    new_node.type = Node::kTypeString;
    auto* sp = new string("newString");
    new_node.data = sp;
    return 0;
}
