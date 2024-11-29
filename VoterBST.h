#ifndef VOTERBST_H
#define VOTERBST_H

#include <string>
#include "Voter.h"

class VoterBST {
private:
    struct Node {
        std::string firstName;
        std::string lastName;
        Voter* voter;
        Node* left;
        Node* right;

        Node(const std::string& fName, const std::string& lName, Voter* voter)
            : firstName(fName), lastName(lName), voter(voter), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* root, const std::string& firstName, const std::string& lastName, Voter* voter);
    Node* find(Node* root, const std::string& firstName, const std::string& lastName) const;
    Node* deleteNode(Node* root, const std::string& firstName, const std::string& lastName);
    Node* findMin(Node* node) const;
    void deleteTree(Node* node);

public:
    VoterBST();
    ~VoterBST();

    void insert(const std::string& firstName, const std::string& lastName, Voter* voter);
    Voter* find(const std::string& firstName, const std::string& lastName) const;
    void deleteNode(const std::string& firstName, const std::string& lastName);
};

#endif // VOTERBST_H
