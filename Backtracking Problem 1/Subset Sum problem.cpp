#include <iostream>
#include <vector>

using namespace std;

// Define a function to find subsets of a given set that add up to a target sum. The function takes in two parameters:
// set: a vector of integers representing a set of numbers.
// target: an integer representing the target sum that we want to find using elements from the set.
void findSums(vector<int> set, vector<int> subset, int index, int target, int sum)
{
	// If the current sum is greater than the target sum or if the index is greater than or equal to the size of the set, return.
	if (sum > target || index >= set.size())
	{
		return;
	}
	// If the current sum is equal to the target sum, print the elements of the subset vector to the console and return.
	else if (sum == target)
	{
		for (int i = 0; i <= subset.size() - 1; i++)
		{
			cout << subset[i] << " ";
		}
		cout << endl;
		return;
	}

	// Add the element at the current index to the subset vector and update the sum accordingly.
	subset.push_back(set[index]);
	// Recursively call the findSums() function with the same set, subset, and target values, but with the index incremented by 1.
	findSums(set, subset, index, target, sum + set[index]);
	// Remove the last element of the subset vector (i.e. pop it off).
	subset.pop_back();
	// Recursively call the findSums() function with the same set, subset, and target values, but with the index incremented by 1 and the sum unchanged.
	findSums(set, subset, index + 1, target, sum);
}

void eliminateDuplicates(vector<int> &set, int index)
{
	if (index >= set.size())
		return;
	for (int i = 0; i < set.size(); i++)
	{
		if (index != i && set[index] == set[i])
		{
			set.erase(set.begin() + i);
			eliminateDuplicates(set, index);
		}
	}

	eliminateDuplicates(set, index + 1);
}

int main()
{
	vector<int> set;
	int input, target;
	cin >> input;
	while (input > 0)
	{
		set.push_back(input);
		cin >> input;
	}
	if (input < 0)
		return 0;
	else if (input == 0)
	{
		cout << "select target: ";
		cin >> target;
	}
	vector<int> subset;
	cout << "Output:" << endl;
	eliminateDuplicates(set, 0);
	findSums(set, subset, 0, target, 0);
	return 0;
}