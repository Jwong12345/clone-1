#include "MaxHeap.h"
#include "Voter.h"

void MaxHeap::swap(int i, int j) {
    Voter* temp1 = heap[i];
    Voter* temp2 = heap[j];

    heap[i] = temp2;
    heap[j] = temp1;

    heap[i]->setHeapIndex(i);
    heap[j]->setHeapIndex(j);
}

void MaxHeap::percolateDown(int index) {
    int sizeOfHeap = heap.size();
    bool done = false;
    while (!done) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        double largestImpact = heap[largest]->getImpact();

        if (leftChild < sizeOfHeap && heap[leftChild]->getImpact() > largestImpact) {
            largest = leftChild;
            largestImpact = heap[leftChild]->getImpact();
        }

        if (rightChild < sizeOfHeap && heap[rightChild]->getImpact() > largestImpact) {
            largest = rightChild;
            largestImpact = heap[rightChild]->getImpact();
        }

        if (largest != index) {
            swap(index, largest);
            index = largest;
        } else {
            done = true;
        }
    }
}

void MaxHeap::percolateUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index]->getImpact() > heap[parent]->getImpact()) {
            swap(index, parent);
            index = parent;
        } else {
            break;
        }
    }
}

MaxHeap::MaxHeap() {}
MaxHeap::~MaxHeap() {}

void MaxHeap::insertVoter(Voter* voter) {
    heap.push_back(voter);
    int index = heap.size() - 1;
    voter->setHeapIndex(index);
    percolateUp(index);
}

Voter* MaxHeap::getMax() const {
    if (heap.empty()) {
        return nullptr;
    }
    return heap[0];
}

void MaxHeap::extractMax() {
    if (heap.empty()) {
        return;
    }
    Voter* lastVoter = heap.back();
    heap[0] = lastVoter;
    lastVoter->setHeapIndex(0);
    heap.pop_back();
    
    if (!heap.empty()) {
        percolateDown(0);
    }
}

void MaxHeap::updateImpact(int index) {
    percolateUp(index);
    percolateDown(index);
}

bool MaxHeap::empty() const {
    return heap.empty();
}
