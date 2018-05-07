//Lela Bones
//Cosc 320 Project 3
//knapsacks.h
//This file will hold the prototypes for the knapsack class

#ifndef KNAPSACKS_H
#define KNAPSACKS_H
#include <iostream>
#include <vector>

// struct Items{
//   int index;
//   int weight;
//   std::vector<int> appearances;
// };
// structure to hold the items contained in the file
struct ItemStats
{
    std::string name;
    int value;
    int size;
};

struct Item
{
    int index;
    int weight;
    std::vector<int> appearances;
};

//knapsack class declaration goes here
class Knapsacks{
  public:
    Knapsacks(){}
    ~Knapsacks(){}
    std::vector<int> DynamicKnapsack(int[], int[], int, int); //dynamic implentation
    bool IsSolution(std::vector<Item>&, int, int); //checks solution
    std::vector<ItemStats> ReturnBest(std::vector<ItemStats>&, std::vector<int>&); //returns solution
    void Display(std::vector<ItemStats>& packages, unsigned size);
    int TotalSize(std::vector<ItemStats>&);
    int Totalvalue(std::vector<ItemStats>&);
};

#endif
