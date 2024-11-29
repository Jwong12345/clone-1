#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include "VoterBST.h"
#include "MaxHeap.h"
#include "AgeIndexedVector.h"
#include "Voter.h"

using namespace std;

// Global data structures
VoterBST votedTree;
VoterBST voterTree;
MaxHeap voterHeap;
AgeIndexedVector voterAges(18, 118);

void addVoter(const string& lastName, const string& firstName, int age) {
    if (age < 18 || age > 118) {
        cout << "Voter age should be between 18 and 118" << endl;
        return;
    }
    
    Voter* voter = votedTree.find(firstName, lastName);
    if (voter) {
        cout << "Voter already voted." << endl;
        return;
    }
    
    Voter* existingVoter = voterTree.find(firstName, lastName);
    if (existingVoter) {
        cout << "Voter " << firstName << " " << lastName << ", age " << age << ", already exists." << endl;
        return;
    }

    Voter* newVoter = new Voter(firstName, lastName, age);
    voterTree.insert(firstName, lastName, newVoter);
    voterHeap.insertVoter(newVoter);
    voterAges.addVoter(newVoter);
    cout << "New voter " << firstName << " " << lastName << ", age " << age << ", added." << endl;
}

void markVoted(const string& lastName, const string& firstName) {
Voter* voted = votedTree.find(firstName, lastName);
    if (voted) {
        cout << "Voter already voted." << endl;
        return;
    }
    Voter* voter = voterTree.find(firstName, lastName);
    if (!voter) {
        cout << "Voter not found" << endl;
        return;
    }

    cout << "Voter " << firstName << " " << lastName << ", age " << voter->getAge() << ", voted." << endl;
    votedTree.insert(firstName, lastName, voter);
    voterTree.deleteNode(firstName, lastName);
    voterHeap.extractMax();
    voterAges.removeVoter(voter);
    //delete voter;
}

void updateSupport(const string& lastName, const string& firstName, int strength) {
    Voter* voter = voterTree.find(firstName, lastName);
    if (!voter) {
        cout << "Voter not found" << endl;
        return;
    }
Voter* voted = votedTree.find(firstName, lastName);
    if (voted) {
        cout << "Voter already voted." << endl;
        return;
    }
    voter->support(lastName, firstName, voter->getAge(), strength);
    voterHeap.updateImpact(voter->getHeapIndex());
    cout << "Support from " << firstName << " " << lastName << " increased by " << strength << " strength points." << endl;
}

void reduceLikelihood(const string& lastName, const string& firstName, int reduction) {
    Voter* voter = voterTree.find(firstName, lastName);
    if (!voter) {
        cout << "Voter not found" << endl;
        return;
    }
Voter* voted = votedTree.find(firstName, lastName);
    if (voted) {
        cout << "Voter already voted." << endl;
        return;
    }
    voter->reduce_likelihood(lastName, firstName, reduction);
    voterHeap.updateImpact(voter->getHeapIndex());
    cout << "Voting likelihood of " << firstName << " " << lastName << " decreased by " << reduction << "%" << endl;
}

void chauffeur() {
    Voter* voter = voterHeap.getMax();
    if (!voter) {
        cout << "No voters available for chauffeur." << endl;
        return;
    }

    cout << "Driving " << voter->getFirstName() << " " << voter->getLastName()
         << " (" << voter->getAge() << "): strength of support: " << voter->getStrength()
         << ", likelihood: " << voter->getLikelihood() << ", impact: " << voter->getImpact() << endl;
    votedTree.insert(voter->getFirstName(), voter->getLastName(), voter);
    voterTree.deleteNode(voter->getFirstName(), voter->getLastName());
    voterHeap.extractMax();
    voterAges.removeVoter(voter);
    //delete voter;
}

void showImpact() {
    voterAges.displayVoters();
}

/*int main() {
    string command;
    bool running = true;
    while (running) {
        cout << ": ";
        getline(cin, command);

        stringstream ss(command);
        string operation;
        ss >> operation;

        if (operation == "voter") {
            string lastName, firstName;
            int age;
            ss >> lastName >> firstName >> age;
            addVoter(lastName, firstName, age);
        } else if (operation == "voted") {
            string lastName, firstName;
            ss >> lastName >> firstName;
            markVoted(lastName, firstName);
        } else if (operation == "support") {
            string lastName, firstName;
            int strength;
            ss >> lastName >> firstName >> strength;
            updateSupport(lastName, firstName, strength);
        } else if (operation == "reduce-likelihood") {
            string lastName, firstName;
            int reduction;
            ss >> lastName >> firstName >> reduction;
            reduceLikelihood(lastName, firstName, reduction);
        } else if (operation == "chauffeur") {
            chauffeur();
        } else if (operation == "show-impact") {
            showImpact();
        } else if (operation == "quit") {
            running = false;
        } else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}*/
int main() {

    char command[100];  // Array to store the input command
    char lastName[50], firstName[50];
    int age, strength, reduction;
    bool running = true;
    while (running) {
    
        printf(": ");
        // Read the first word (operation) from the user
        scanf("%s", command);

        // Check the operation type and perform corresponding actions
        if (strcmp(command, "voter") == 0) {
            // For 'voter', read last name, first name, and age
            scanf("%s %s %d", lastName, firstName, &age);
            addVoter(lastName, firstName, age);
        } else if (strcmp(command, "voted") == 0) {
            // For 'voted', read last name and first name
            scanf("%s %s", lastName, firstName);
            markVoted(lastName, firstName);
        } else if (strcmp(command, "support") == 0) {
            // For 'support', read last name, first name, and support strength
            scanf("%s %s %d", lastName, firstName, &strength);
            updateSupport(lastName, firstName, strength);
        } else if (strcmp(command, "reduce-likelihood") == 0) {
            // For 'reduce-likelihood', read last name, first name, and reduction amount
            scanf("%s %s %d", lastName, firstName, &reduction);
            reduceLikelihood(lastName, firstName, reduction);
        } else if (strcmp(command, "chauffeur") == 0) {
            // For 'chauffeur', no additional input required
            chauffeur();
        } else if (strcmp(command, "show-impact") == 0) {
            // For 'show-impact', no additional input required
            showImpact();
        } else if (strcmp(command, "quit") == 0) {
            // Exit the loop on 'quit'
            running = false;
        } else {
            // Handle invalid commands
            printf("Invalid command.\n");
        }
    }

    return 0;
}
