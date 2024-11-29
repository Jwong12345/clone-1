#include "VoterBST.h"

VoterBST::VoterBST() : root(nullptr) {}
VoterBST::~VoterBST() {
    deleteTree(root);
}

void VoterBST::deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node->voter;
    delete node;
}

void VoterBST::insert(const std::string& firstName, const std::string& lastName, Voter* voter) {
    root = insert(root, firstName, lastName, voter);
}

VoterBST::Node* VoterBST::insert(Node* root, const std::string& firstName, const std::string& lastName, Voter* voter) {
    if (!root) return new Node(firstName, lastName, voter);
    if (lastName < root->lastName || (lastName == root->lastName && firstName < root->firstName)) {
        root->left = insert(root->left, firstName, lastName, voter);
    } else {
        root->right = insert(root->right, firstName, lastName, voter);
    }
    return root;
}

Voter* VoterBST::find(const std::string& firstName, const std::string& lastName) const {
    Node* result = find(root, firstName, lastName);
    return result ? result->voter : nullptr;
}

VoterBST::Node* VoterBST::find(Node* root, const std::string& firstName, const std::string& lastName) const {
    if (!root) return nullptr;
    if (lastName < root->lastName || (lastName == root->lastName && firstName < root->firstName)) {
        return find(root->left, firstName, lastName);
    } else if (lastName > root->lastName || (lastName == root->lastName && firstName > root->firstName)) {
        return find(root->right, firstName, lastName);
    }
    return root;
}

void VoterBST::deleteNode(const std::string& firstName, const std::string& lastName) {
    root = deleteNode(root, firstName, lastName);
}

VoterBST::Node* VoterBST::deleteNode(Node* root, const std::string& firstName, const std::string& lastName) {
    if (!root) return nullptr;
    if (lastName < root->lastName || (lastName == root->lastName && firstName < root->firstName)) {
        root->left = deleteNode(root->left, firstName, lastName);
    } else if (lastName > root->lastName || (lastName == root->lastName && firstName > root->firstName)) {
        root->right = deleteNode(root->right, firstName, lastName);
    } else {
        if (!root->left) {
            Node* rightChild = root->right;
            delete root->voter;
            delete root;
            return rightChild;
        } else if (!root->right) {
            Node* leftChild = root->left;
            delete root->voter;
            delete root;
            return leftChild;
        }
        Node* successor = findMin(root->right);
        root->firstName = successor->firstName;
        root->lastName = successor->lastName;
        root->voter = successor->voter;
        root->right = deleteNode(root->right, successor->firstName, successor->lastName);
    }
    return root;
}

VoterBST::Node* VoterBST::findMin(Node* node) const {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}
