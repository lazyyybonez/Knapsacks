//Lela Bones
//Cosc 320 Project 3
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
struct PackageStats
{
	std::string name;
	int votes;
	int size;
};

struct PackageSet
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
    bool IsSolution(std::vector<PackageSet>&, int, int); //checks solution
    std::vector<PackageStats> ReturnBest(std::vector<PackageStats>&, std::vector<int>&); //returns solution
    void Display(std::vector<PackageStats>& packages, unsigned size);
    int TotalSize(std::vector<PackageStats>& packages, std::vector<int> s = std::vector<int>())
{
  int total = 0;

  // if theres 2 parameters
  if(!s.empty())
  {
    for(unsigned x=0; x < s.size(); ++x)
    {
      total += packages.at(s.at(x)).size;
    }
  }
  else // if theres only 1
  {
    for(unsigned x=0; x < packages.size(); ++x)
    {
      total += packages.at(x).size;
    }
  }
  return total;
}// end of TotalSize

int TotalVotes(std::vector<PackageStats>& packages, std::vector<int> s = std::vector<int>())
{
  int total = 0;

  // if theres 2 parameters
  if(!s.empty())
  {
    for(unsigned x=0; x < s.size(); ++x)
    {
      total += packages.at(s.at(x)).votes;
    }
  }
  else // if theres only 1
  {
    for(unsigned x=0; x < packages.size(); ++x)
    {
      total += packages.at(x).votes;
    }
  }
  return total;
}// end of TotalVotes
};

#endif
