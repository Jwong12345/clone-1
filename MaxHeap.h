#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include "Voter.h"

class MaxHeap {
private:
    std::vector<Voter*> heap;

    void swap(int i, int j);
    void percolateDown(int index);
    void percolateUp(int index);

public:
    MaxHeap();
    ~MaxHeap();

    void insertVoter(Voter* voter);
    Voter* getMax() const;
    void extractMax();
    void updateImpact(int index);
    bool empty() const;
};

#endif // MAXHEAP_H
