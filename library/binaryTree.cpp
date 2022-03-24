#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <class TT>
struct Bintree {
    explicit Bintree(TT val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    TT data;
    Bintree<TT>* left;
    Bintree<TT>* right;
};

template <class TT>
void traversalRecursiveLocal(Bintree<TT>* const node, vector<TT>& result) {
    if (!node) {
        return;
    }
    // Preorder
    // root -> left -> right
    // result.emplace_back(node->data);
    // traversalRecursiveLocal(node->left, result);
    // traversalRecursiveLocal(node->right, result);

    // Inorder
    // left -> root -> right
    traversalRecursiveLocal(node->left, result);
    result.emplace_back(node->data);
    traversalRecursiveLocal(node->right, result);

    // Postorder
    // left -> right -> root
    // result.emplace_back(node->data);
    // traversalRecursiveLocal(node->left, result);
    // traversalRecursiveLocal(node->right, result);
};

template <class TT>
vector<TT> traversalRecursive(Bintree<TT>* const bt) {
    // recursively traversal of binary tree
    vector<TT> result;
    traversalRecursiveLocal(bt, result);
    return result;
}

template <class TT>
vector<TT> traversalPreorder(Bintree<TT>* const bt) {
    // preorder traversal of binary tree
    // root -> left -> right
    stack<Bintree<TT>*> stack_node;
    stack_node.push(bt);
    vector<TT> result;
    Bintree<TT>* cur = nullptr;
    while (!stack_node.empty()) {
        cur = stack_node.top();
        stack_node.pop();
        result.emplace_back(cur->data);
        if (cur->right) {
            stack_node.push(cur->right);
        }
        if (cur->left) {
            stack_node.push(cur->left);
        }
    }
    return result;
};

template <class TT>
vector<TT> traversalInorder(Bintree<TT>* const bt) {
    // inorder traversal of binary tree
    // left -> root -> right
    stack<Bintree<TT>*> stack_node;
    stack_node.push(bt);
    vector<TT> result;
    Bintree<TT>* cur = nullptr;
    while (!stack_node.empty()) {
        cur = stack_node.top();
        stack_node.pop();
        if (cur->left) {
            stack_node.push(cur->left);
        }
        result.emplace_back(cur->data);
        if (cur->right) {
            stack_node.push(cur->right);
        }
    }
    return result;
}

template <class TT>
vector<TT> traversalPostorder(Bintree<TT>* const bt) {
    // postorder traversal of binary tree
    // left -> right -> root
}

int main() {
    auto* node = new Bintree<int>(1);
    node->left = new Bintree<int>(2);
    node->right = new Bintree<int>(3);
    node->left->left = new Bintree<int>(4);
    node->left->right = new Bintree<int>(5);
    node->right->left = new Bintree<int>(6);
    node->right->right = new Bintree<int>(7);
    auto out1 = traversalInorder(node);
    auto out2 = traversalRecursive(node);
    return 0;
}
