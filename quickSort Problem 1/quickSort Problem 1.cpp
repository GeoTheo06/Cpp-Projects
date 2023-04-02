//Given an array of integers, find the kth smallest element using the QuickSort algorithm.
//For example, if the array is[3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5], and k is 3, the function should return 3, because 3 is the 3rd smallest element in the array.
#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& arr, int start, int end)
{
	if (start < end)
	{
		int b = start - 1; //s stands for small, b stands for big
		for (int s = start; s < end; s++)
		{
			if (arr[s] <= arr[end])
			{
				b++;
				swap(arr[s], arr[b]);
			}
		}
		swap(arr[b + 1], arr[end]);

		sort(arr, start, b);
		sort(arr, b + 2, end);
	}
}

int findKthSmallest(vector<int> arr, int k)
{
	sort(arr, 0, arr.size() - 1);

	int counter = 0;
	while (counter < k - 1)
	{
		counter++;
		if (arr[counter] == arr[counter - 1])
			k++;
	}
	return arr[counter];
}

int main()
{
	vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
	int k = 7;
	int kthSmallest = findKthSmallest(arr, k);
	cout << "The " << k << "th smallest element is: " << kthSmallest << endl;
	return 0;
}