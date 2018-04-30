//Lela Bones
//Cosc 320 Project 3
//This file will hold the prototypes for the knapsack class

#ifndef KNAPSACKS_H
#define KNAPSACKS_H
#include <iostream>
#include <vector>

struct Items{
  int index;
  int weight;
  std::vector<int> appearances;
};

//knapsack class declaration goes here
class Knapsacks{
  public:
    Knapsacks();
    ~Knapsacks();
    std::vector<int> DynamicKnapsack(int itemWeight[], int itemValue[], int amount, int limit); //dynamic implentation
    bool isCorrect(std::vector<Items>& stuff, int index, int currWeight); //checks solution
    std::vector<Items> returnSolution(std::vector<Items>& stuff, std::vector<int>& solution); //returns solution
};

#endif
