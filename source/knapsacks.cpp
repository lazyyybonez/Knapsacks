//Lela Bones
//Cosc 320 Project 3
//This file will hold the functions of the knapsack class
#include <iostream>
#include "knapsacks.h"
#include <vector>
#include <algorithm>

std::vector<int> Knapsacks::DynamicKnapsack(int packageWeight[], int packageVotes[],
  int numPackages, int maxWeight)
{
  // declare variables
  std::vector<int> best;
  std::vector<int> temp;
  std::vector<PackageSet> pset;
  int** T = new int*[numPackages+1];
  int deleted = 0;
  int currWeight = maxWeight;
  bool dontCheck = false;

  for(int x=0; x <= numPackages; ++x)
  {
    T[x] = new int[maxWeight+1];
    PackageSet access;
    dontCheck = false;
    temp.clear();

    for(int y=0; y <= maxWeight; ++y)
    {
      if(x==0 || y==0)
      {
        T[x][y] = 0;
      }
      else if(packageWeight[x-1] <= y)
      {
        T[x][y] = std::max(T[x-1][y-packageWeight[x-1]]
            + packageVotes[x-1], T[x-1][y]);
        if(T[x][y] == (T[x-1][y-packageWeight[x-1]]
            + packageVotes[x-1]))
        {
          // if we find a valid packet, place it into
          // the temp vector for storage
          if(!dontCheck &&
            !(std::find(temp.begin(), temp.end(),
            packageWeight[x-1]) != temp.end()))
          {
            temp.push_back(packageWeight[x-1]);
          }
          // find all of the weight instances where
          // this packet is "valid"
          access.appearances.push_back(y);
          dontCheck = true;
        }
      }
      else
      {
        T[x][y] = T[x-1][y];
      }
    }// end for loop

    // gather info about the packet we just found
    if((std::find(temp.begin(), temp.end(),
        packageWeight[x-1]) != temp.end()))
    {
      access.index = x-1;
      access.weight = packageWeight[x-1];
      pset.push_back(access);
    }

    // memory management, used to delete
    // array indexes thats no longer in use
    if(x > 1)
    {
      delete[] T[deleted++];
    }
  }// end for loop

  delete[] T;

  // obtain the best possible knapsack solutuion, and save
  // their array indexes into a vector, starting from the end
  // NOTE: this places the knapsack solution in opposite (reverse) order
  for(int x = pset.size()-1; x >= 0; --x)
  {
    if(IsSolution(pset, x, currWeight))
    {
      best.push_back(pset.at(x).index);
      currWeight -= pset.at(x).weight;
    }
    pset.pop_back();
  }

  // reverse the vector back into ascending order
  std::reverse(best.begin(), best.end());

  return best;
}// end of DynamicKnapsack

bool Knapsacks::IsSolution(std::vector<PackageSet>& pset, int index, int currWeight)
{
  return std::find(pset.at(index).appearances.begin(),
    pset.at(index).appearances.end(), currWeight) !=
    pset.at(index).appearances.end();
}// end of IsSolution

std::vector<PackageStats> Knapsacks::ReturnBest(std::vector<PackageStats>& packages,
  std::vector<int>& knapResult)
{
  std::vector<PackageStats> best;
  for(unsigned x=0; x < knapResult.size(); ++x)
  {
    best.push_back(packages.at(knapResult.at(x)));
  }
  return best;
}// end of ReturnBest

void Knapsacks::Display(std::vector<PackageStats>& packages, unsigned size)
{
for(unsigned x=0; x < size && x < packages.size(); ++x)
{
std::cout<<packages.at(x).name<<" "
     <<packages.at(x).size<<" "<<packages.at(x).votes<<std::endl;
}
}// end of Display
