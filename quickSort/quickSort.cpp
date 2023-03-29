#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& randNums, int start, int end)
{
	if (start < end)
	{
		int b = start - 1, pivot = end; //b for (b)igger numbers than pivot | s for (s)maller numbers than pivot

		for (int s = start; s < end; s++)
		{
			if (randNums[s] <= randNums[pivot])
			{
				//i don't care what randNums[b] will be because i know it will be bigger or equal to randNums[s] as b will only be iterated if an s that is smaller is already found
				b++;
				swap(randNums[s], randNums[b]);
			}
		}
		swap(randNums[b + 1], randNums[pivot]);

		quickSort(randNums, start, b);
		quickSort(randNums, b + 2, end);
	}
}

int main()
{
	vector<int> randNums;
	string temp;
	cout << "give numbers to be sorted (press enter for each number). When you are done, simply enter '.' (without quotes)" << endl;
	cin >> temp;
	while (temp != ".")
	{
		randNums.push_back(stoi(temp));
		cin >> temp;
	}
	quickSort(randNums, 0, randNums.size() - 1);
	cout << endl << "sorted version of your numbers: ";
	for (int i = 0; i <= randNums.size() - 1; i++)
		cout << randNums[i] << " ";
}