/* USER: theodoridis_geo35pdp
LANG: C++
TASK: roadfix */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// STRUCTURE:
//  offers{{20 45 10}, {30 75 20}, {40 80 30}, {60 95 5}, {90 100 15}}
//  offers{     0,          1,          2,          3,         4		}
//
//  currentCombination{{20, 45, 10}, {30, 75, 20}, {40, 80, 30}, {60, 95, 5}, {90, 100, 15}}
//  currentCombination{      0,            1,            2,            3,            4}\
// OR
//  currentCombination{{20, 45, 10}, {30, 75, 20}, {60, 95, 5}, {90, 100, 15}}
//  currentCombination{      0,            1,            2,           3}

int low = 10001;
void findCombinations(vector<vector<int>> &offers, int startingKilometer, int endingKilometer, vector<vector<int>> &currentCombination, int index, int sum)
{
	// we have a valid combination!
	if (currentCombination.size() > 0 && currentCombination[0][0] <= startingKilometer && currentCombination[0][1] >= startingKilometer && currentCombination.back()[0] <= endingKilometer && currentCombination.back()[1] >= endingKilometer)
	{
		if (sum < low)
			low = sum;
		return;
	}

	// adding and removing offers to the current combination and adding and removing total cost accordingly
	for (int i = index; i < offers.size(); i++)
	{
		if (currentCombination.empty() || offers[i][0] <= currentCombination.back()[1] && offers[i][1] > currentCombination.back()[1])
		{
			currentCombination.push_back(offers[i]);
			sum += offers[i][2];
			findCombinations(offers, startingKilometer, endingKilometer, currentCombination, i + 1, sum);
			currentCombination.pop_back();
		}
	}
}

int main()
{
	ifstream in("roadfix.in");
	ofstream out("roadfix.out");

	// 1. initializations
	int offersCounter, queriesCounter, offerStartingKilometer, offerLength, offerCost, queryStartingKilometer, queryLength;
	vector<int> temp, testingStartingKilometer, testingEndingKilometer;
	vector<vector<int>> offers, queries, offersConstant, currentCombination;
	// 1.

	// 2. Getting Values
	in >> offersCounter >> queriesCounter;

	/*	offers[starting kilometer, ending kilometer, cost]:
		20 45 10
		30 75 20
		40 80 30
		60 95 5
		90 100 15
	*/
	for (int i = 0; i < offersCounter; i++)
	{
		in >> offerStartingKilometer >> offerLength >> offerCost;
		temp.push_back(offerStartingKilometer);
		temp.push_back(offerStartingKilometer + offerLength);
		temp.push_back(offerCost);
		offers.push_back(temp);
		temp.clear();
	}
	sort(offers.begin(), offers.end());

	/*	queries[starting kilometer, ending kilometer]:
		20 100
		50 80
		10 40
	*/
	for (int i = 0; i < queriesCounter; i++)
	{
		in >> queryStartingKilometer >> queryLength;
		temp.push_back(queryStartingKilometer);
		temp.push_back(queryStartingKilometer + queryLength);
		queries.push_back(temp);
		temp.clear();
	}
	// 2.

	// 3. Logic & Print
	offersConstant = offers;
	// iterating through every query
	for (int i = 0; i < queriesCounter; i++)
	{
		// and through every offer (only for the elimination, recursion runs for every query only)
		for (int k = 0; k < offers.size(); k++)
		{
			// there is offer neither in the starting nor in the ending kilometer of the current query, so i save time complexity by ignoring the recursion and printing -1
			if (offers[k][0] <= queries[i][0] && offers[k][1] >= queries[i][0])
				testingStartingKilometer.push_back(1);
			if (offers[k][0] <= queries[i][1] && offers[k][1] >= queries[i][1])
				testingEndingKilometer.push_back(1);
			// To lower the complexity even further i find offers outside of the current query bounds and eliminate them before starting the recursion. This also saves time.
			if (offers[k][1] < queries[i][0] || offers[k][0] > queries[i][1])
				offers.erase(offers.begin() + k);
		}
		if (testingStartingKilometer.empty() || testingEndingKilometer.empty())
			out << -1 << endl;
		else
		{
			findCombinations(offers, queries[i][0], queries[i][1], currentCombination, 0, 0);
			out << low << endl;
		}
		// resetting values
		low = 10001;
		testingStartingKilometer.clear();
		testingEndingKilometer.clear();
		offers = offersConstant;
	}
	// 3.
	return (0);
}