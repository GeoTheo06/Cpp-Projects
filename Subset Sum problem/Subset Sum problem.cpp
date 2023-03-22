#include <iostream>
#include <vector>

using namespace std;

// Define a function to find subsets of a given set that add up to a target sum. The function takes in two parameters:
// set: a vector of integers representing a set of numbers.
// target: an integer representing the target sum that we want to find using elements from the set.
void findSums(vector<int> set, vector<int> subset, int index, int target, int sum)
{
	if (sum > target || index >= set.size())
	{
		return;
	}
	else if (sum == target)
	{
		for (int i = 0; i <= subset.size() - 1; i++)
		{
			cout << subset[i] << " ";
		}
		cout << endl;
		return;
	}

	subset.push_back(set[index]);
	findSums(set, subset, index, target, sum + set[index]);
	subset.pop_back();
	findSums(set, subset, index + 1, target, sum);
}

void eliminateDuplicates(vector<int>& set, int index)
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