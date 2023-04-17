/*
Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position is low (the index of the array) and its ending position is high(the index of the array).

Note: The low and high are inclusive.

Implement the partition() and quickSort() functions to sort the array.


Example 1:

Input:
N = 5
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9
Example 2:

Input:
N = 9
arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7}
Output:
1 1 2 3 4 6 7 9 10

Your Task:
You don't need to read input or print anything. Your task is to complete the functions partition()  and quickSort() which takes the array arr[], low and high as input parameters and partitions the array. Consider the last element as the pivot such that all the elements less than(or equal to) the pivot lie before it and the elements greater than it lie after the pivot.


Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(logN)


Constraints:
1 <= N <= 103
1 <= arr[i] <= 104
*/

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d", arr[i]);
	printf("\n");
}

class Solution
{
public:
//Function to sort an array using quick sort algorithm.
	void quickSort(int arr[], int low, int high)
	{
		if (low < high)
		{
			int pivot = partition(arr, low, high);

			quickSort(arr, low, pivot - 1);
			quickSort(arr, pivot + 1, high);
		}
	}

	int swap(int arr[], int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	int partition(int arr[], int low, int high)
	{
		int b = low - 1;
		for (int i = low; i < high; i++)
		{
			if (arr[i] <= arr[high])
			{
				b++;
				swap(arr, b, i);
			}
		}
		swap(arr, b + 1, high);
		return b + 1;
	}
};

int main()
{
	int arr[1000], n, T, i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			Solution ob;
			ob.quickSort(arr, 0, n - 1);
			printArray(arr, n);
		}
		return 0;
	}
}