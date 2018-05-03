//Lela Bones
//Cosc 320 Project 3
//This file will hold the functions of the knapsack class
#include <iostream>
#include "knapsacks.h"
#include <vector>
#include <algorithm>

std::vector<int> Knapsacks::DynamicKnapsack(int packageWeight[], int packagevalue[],
  int numPackages, int maxWeight)
{
  // declare variables
  std::vector<int> best;
  std::vector<int> temp;
  std::vector<Item> pset;
  int** T = new int*[numPackages+1];
  int deleted = 0;
  int currWeight = maxWeight;
  bool dontCheck = false;
  for(int i=0; i <= numPackages; i++)
  {
    T[i] = new int[maxWeight+1];
    Item access;
    dontCheck = false;
    temp.clear();

    for(int y=0; y <= maxWeight; ++y)
    {
      if(i==0 || y==0)
      {
        T[i][y] = 0;
      }
      else if(packageWeight[i-1] <= y)
      {
        T[i][y] = std::max(T[i-1][y-packageWeight[i-1]]
            + packagevalue[i-1], T[i-1][y]);
        if(T[i][y] == (T[i-1][y-packageWeight[i-1]]
            + packagevalue[i-1]))
        {
          // if we find a valid packet, place it into
          // the temp vector for storage
          if(!dontCheck &&
            !(std::find(temp.begin(), temp.end(),
            packageWeight[i-1]) != temp.end()))
          {
            temp.push_back(packageWeight[i-1]);
          }
          // find all of the weight instances where
          // this packet is "valid"
          access.appearances.push_back(y);
          dontCheck = true;
        }
      }
      else
      {
        T[i][y] = T[i-1][y];
      }
    }// end for loop

    // gather info about the packet we just found
    if((std::find(temp.begin(), temp.end(),
        packageWeight[i-1]) != temp.end()))
    {
      access.index = i-1;
      access.weight = packageWeight[i-1];
      pset.push_back(access);
    }

    // memory management, used to delete
    // array indexes thats no longer in use
    if(i > 1)
    {
      delete[] T[deleted++];
    }
  }// end for loop

  delete[] T;

  // obtain the best possible knapsack solutuion, and save
  // their array indexes into a vector, starting from the end
  // NOTE: this places the knapsack solution in opposite (reverse) order
  for(int i = pset.size()-1; i >= 0; i--)
  {
    if(IsSolution(pset, i, currWeight))
    {
      best.push_back(pset.at(i).index);
      currWeight -= pset.at(i).weight;
    }
    pset.pop_back();
  }

  // reverse the vector back into ascending order
  std::reverse(best.begin(), best.end());

  return best;
}// end of DynamicKnapsack

bool Knapsacks::IsSolution(std::vector<Item>& pset, int index, int currWeight)
{
  return std::find(pset.at(index).appearances.begin(),
    pset.at(index).appearances.end(), currWeight) !=
    pset.at(index).appearances.end();
}// end of IsSolution

std::vector<ItemStats> Knapsacks::ReturnBest(std::vector<ItemStats>& packages,
  std::vector<int>& knapResult)
{
  std::vector<ItemStats> best;
  for(unsigned x=0; x < knapResult.size(); ++x)
  {
    best.push_back(packages.at(knapResult.at(x)));
  }
  return best;
}// end of ReturnBest

void Knapsacks::Display(std::vector<ItemStats>& packages, unsigned size)
{
for(unsigned x=0; x < size && x < packages.size(); ++x)
{
std::cout<<packages.at(x).name<<" "
     <<packages.at(x).size<<" "<<packages.at(x).value<<std::endl;
}
}// end of Display

int Knapsacks::TotalSize(std::vector<ItemStats>& packages)
{
  std::vector<int> s = std::vector<int>();
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

int Knapsacks::Totalvalue(std::vector<ItemStats>& packages)
{
  std::vector<int> s = std::vector<int>();
  int total = 0;

  // if theres 2 parameters
  if(!s.empty())
  {
    for(unsigned x=0; x < s.size(); ++x)
    {
      total += packages.at(s.at(x)).value;
    }
  }
  else // if theres only 1
  {
    for(unsigned x=0; x < packages.size(); ++x)
    {
      total += packages.at(x).value;
    }
  }
  return total;
}// end of Totalvalue
