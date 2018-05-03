//Lela Bones
//Cosc 320 Project 3
//This file is the driver for the knapsack class

#include <iostream>
#include "knapsacks.h"
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <fstream>

int main()
{
	// declare variables;
	Knapsacks proj5;
	ItemStats access;
	std::ifstream infile;
	std::vector<ItemStats> packages;
	std::vector<ItemStats> bestCombo;
	std::vector<int> knapResult;
	int maxWeight;
	int totPackages = 0;

	// open file & make sure it exists
	infile.open("knapsack_packages.txt");
	if(infile.fail())
	{
		std::cout<<"Cant find file!";
		exit(1);
	}

	// get the total number of packages from the file
	infile >> maxWeight;
	infile >> totPackages;
	int* packageWeight = new int[totPackages];
	int* packagevalue = new int[totPackages];
	// get the remaining info from the file
	//                      std::string        int             int
	for(int x=0;(infile >> access.name >> access.value >> access.size)
		&& x < totPackages; ++x)
	{
		packages.push_back(access);
		packageWeight[x] = access.size;
		packagevalue[x] = access.value;
	}
	infile.close();

	// display stats
	std::cerr<<"There are "<<totPackages<<" items and the total weight is "<<maxWeight
		<< std::endl << "Dynamic Search Solution" << std::endl;

	// return a vector containing the array indexes
	// of the best knapsack package solution
	knapResult = proj5.DynamicKnapsack(packageWeight, packagevalue, totPackages, maxWeight);

	// using the data found from above, return
	// // the packages that reside in those array indexes
	bestCombo = proj5.ReturnBest(packages, knapResult);

	// display info to the screen
    std::cout<<"Number of packages generated in this set: "<<bestCombo.size() << std::endl
  		<<"First 20 items.." << std::endl;

  	// display the best solution packages
  	proj5.Display(bestCombo, 20);

  	// display the size and total value
  	std::cout<<"Total Size = "<<proj5.TotalSize(bestCombo)<<" -- Total value = "
  		<<proj5.Totalvalue(bestCombo)<<std::endl;

  	// display the elapsed time
	delete[] packageWeight;
	delete[] packagevalue;
  return 0;
}
