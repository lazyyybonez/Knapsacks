//Lela Bones
//Cosc 320 Project 3
//This file is the driver for the knapsack class

#include <iostream>
#include "knapsacks.h"
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <fstream>

// the maximum weight
const int MAX_WEIGHT = 65536;

// the number of packages to examine
const int NUM_PACKAGES = 36149;

int main()
{
	// declare variables;
	Knapsacks proj5;
	PackageStats access;
	std::ifstream infile;
	std::vector<PackageStats> packages;
	std::vector<PackageStats> bestCombo;
	std::vector<int> knapResult;
	int* packageWeight = new int[NUM_PACKAGES];
	int* packageVotes = new int[NUM_PACKAGES];
	int totPackages = 0;

	// open file & make sure it exists
	infile.open("knapsack_packages.txt");
	if(infile.fail())
	{
		std::cout<<"Cant find file!";
		exit(1);
	}

	// get the total number of packages from the file
	infile >> totPackages;

	// make sure there are enough packages in the file
	assert(NUM_PACKAGES <= totPackages);

	// get the remaining info from the file
	//                      std::string        int             int
	for(int x=0;(infile >> access.name >> access.votes >> access.size)
		&& x < NUM_PACKAGES; ++x)
	{
		packages.push_back(access);
		packageWeight[x] = access.size;
		packageVotes[x] = access.votes;
	}
	infile.close();

	// display stats
	std::cerr<<"n = "<<NUM_PACKAGES<<", W = "<<MAX_WEIGHT
		<< std::endl << "Dynamic Search Solution";

	// return a vector containing the array indexes
	// of the best knapsack package solution
	knapResult = proj5.DynamicKnapsack(packageWeight, packageVotes, NUM_PACKAGES, MAX_WEIGHT);

	// using the data found from above, return
	// // the packages that reside in those array indexes
	bestCombo = proj5.ReturnBest(packages, knapResult);

	// display info to the screen
    std::cout<<"Number of packages generated in this set: "<<bestCombo.size()
  		<<"First 20 packages..";

  	// display the best solution packages
  	proj5.Display(bestCombo, 20);

  	// display the size and total votes
  	std::cout<<"Total Size = "<<proj5.TotalSize(bestCombo)<<" -- Total Votes = "
  		<<proj5.TotalVotes(bestCombo)<<std::endl;

  	// display the elapsed time
	delete[] packageWeight;
	delete[] packageVotes;
  return 0;
}
