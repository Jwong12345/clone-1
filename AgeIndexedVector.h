#ifndef AGEINDEXEDVECTOR_H
#define AGEINDEXEDVECTOR_H

#include <vector>
#include "LinkedList.h"
#include "Voter.h"

class AgeIndexedVector {
private:
    std::vector<LinkedList> ageBuckets;

public:
    AgeIndexedVector(unsigned int minAge, unsigned int maxAge);
    void addVoter(Voter* voter);
    void removeVoter(Voter* voter);
    void displayVoters() const;
    unsigned int getAgeIndex(unsigned int age) const;
};

#endif // AGEINDEXEDVECTOR_H
