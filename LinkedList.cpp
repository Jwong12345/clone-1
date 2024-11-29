#include "LinkedList.h"

LinkedList::Node::Node(Voter* voter)
    : voter(voter), prev(nullptr), next(nullptr) {}

LinkedList::Node* LinkedList::Node::getNext() const {
    return next;
}

LinkedList::Node* LinkedList::Node::getPrev() const {
    return prev;
}

void LinkedList::Node::setNext(Node* nextNode) {
    next = nextNode;
}

void LinkedList::Node::setPrev(Node* prevNode) {
    prev = prevNode;
}

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->getNext();
        delete toDelete->voter;
        delete toDelete;
    }
}

LinkedList::Node* LinkedList::getHead() const {
    return head;
}

LinkedList::Node* LinkedList::getTail() const {
    return tail;
}

void LinkedList::addVoterToList(Voter* voter) {
    Node* newNode = new Node(voter);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
}

void LinkedList::removeVoterFromList(Voter* voter) {
    Node* current = head;
    while (current && current->voter != voter) {
        current = current->getNext();
    }
    if (!current) return; // Voter not found

    if (current == head) {
        head = head->getNext();
        if (head) head->setPrev(nullptr);
    } else if (current == tail) {
        tail = tail->getPrev();
        if (tail) tail->setNext(nullptr);
    } else {
        Node* prevNode = current->getPrev();
        Node* nextNode = current->getNext();
        prevNode->setNext(nextNode);
        nextNode->setPrev(prevNode);
    }

    delete current;
}

void LinkedList::displayVoters() const {
    Node* current = head;
    while (current) {
        Voter* voter = current->voter;
        std::cout << voter->getFirstName() << " " << voter->getLastName()
                  << " (" << voter->getAge() << "): strength of support: " << voter->getStrength()
                  << ", likelihood: " << voter->getLikelihood()
                  << ", impact: " << voter->getImpact() << "\n";
        current = current->getNext();
    }
}
