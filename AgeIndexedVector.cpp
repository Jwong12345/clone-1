#include "AgeIndexedVector.h"
#include <iostream>

AgeIndexedVector::AgeIndexedVector(unsigned int minAge, unsigned int maxAge) {
    if (minAge > maxAge) {
        throw std::invalid_argument("Invalid age range.");
    }
    ageBuckets.resize(maxAge - minAge + 1);
}

void AgeIndexedVector::addVoter(Voter* voter) {
    unsigned int index = getAgeIndex(voter->getAge());
    ageBuckets[index].addVoterToList(voter);
}

void AgeIndexedVector::removeVoter(Voter* voter) {
    unsigned int index = getAgeIndex(voter->getAge());
    ageBuckets[index].removeVoterFromList(voter);
}

void AgeIndexedVector::displayVoters() const {
    for (size_t i = 0; i < ageBuckets.size(); ++i) {
        if (ageBuckets[i].getHead() != nullptr) {
            ageBuckets[i].displayVoters();
        }
    }
}

unsigned int AgeIndexedVector::getAgeIndex(unsigned int age) const {
    if (age < 18 || age > 118) {
        throw std::out_of_range("Age is outside the valid range (18-118).");
    }
    return age - 18;
}
