#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Voter.h"
#include <iostream>

class LinkedList {
public:
    struct Node {
        Voter* voter;
        Node* prev;
        Node* next;

        Node(Voter* voter);

        Node* getNext() const;
        Node* getPrev() const;

        void setNext(Node* nextNode);
        void setPrev(Node* prevNode);
    };

private:
    Node* head;
    Node* tail;

public:
    LinkedList();
    ~LinkedList();

    Node* getHead() const;
    Node* getTail() const;

    void addVoterToList(Voter* voter);
    void removeVoterFromList(Voter* voter);
    void displayVoters() const;
};

#endif // LINKEDLIST_H
