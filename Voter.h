#pragma once
#include <string>

class Voter {
public:
    Voter(const std::string& firstName, const std::string& lastName, int age);

    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;
    int getStrength() const;
    double getLikelihood() const;
    double getImpact() const;
    void setHeapIndex(int index);
    int getHeapIndex() const;

    void support(const std::string& lastName, const std::string& firstName, int age, int strength);
    void reduce_likelihood(const std::string& lastName, const std::string& firstName, int reduction);

private:
    std::string firstName;
    std::string lastName;
    int age;
    int strength;
    double likelihood;
    double impact;
    int heapIndex;

    void calculateImpact();
};
