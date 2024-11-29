#include "Voter.h"

Voter::Voter(const std::string& firstName, const std::string& lastName, int age)
    : firstName(firstName), lastName(lastName), age(age), strength(75), likelihood(75), impact(1), heapIndex(-1) {}

std::string Voter::getFirstName() const { return firstName; }
std::string Voter::getLastName() const { return lastName; }
int Voter::getAge() const { return age; }
int Voter::getStrength() const { return strength; }
double Voter::getLikelihood() const { return likelihood; }
double Voter::getImpact() const { return impact; }

void Voter::setHeapIndex(int index) { heapIndex = index; }
int Voter::getHeapIndex() const { return heapIndex; }

void Voter::support(const std::string&, const std::string&, int, int strengthIncrease) {
    strength += strengthIncrease;
    calculateImpact();
}

void Voter::reduce_likelihood(const std::string&, const std::string&, int reductionPercentage) {
    likelihood *= (100.0 - reductionPercentage) / 100.0;
    calculateImpact();
}

void Voter::calculateImpact() {
    impact = strength / likelihood;
}
