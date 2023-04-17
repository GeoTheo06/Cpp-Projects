/* GFG
Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.


For string 11211 the IP address possible are
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Example 1:

Input:
S = 1111
Output: 1.1.1.1
Example 2:

Input:
S = 55
Output: -1

Your Task:

Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses or -1 if no such IP address could be generated through the input string S, the only argument to the function.

Expected Time Complexity: O(N * N * N)
Expected Auxiliary Space: O(N * N * N * N)

Constraints:
1<=N<=16
here, N = length of S.
S only contains digits(i.e. 0-9)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int number = 0;
	int lastDotIndex, currentDotIndex;
	//dotsUsedCounter: counts how many dots have been inserted | dotCounter: counts when the next dot will be added to the combination | lastDot: lastDot is the only dot that will change
	void findCombinations(vector<string>& combinations, string s, string& combination, int dotCounter, int lastDotCounter, int dotsUsedCounter, int lastDot)
	{


		//create combination
		for (int i = 0; i < s.length(); i++)
		{
			//this will only run if we have not passed the last dot yet.
			if (dotsUsedCounter <= 4)
			{
				//we add the numbers
				combination += s[i];

				//if it is time to add a dot
				if (dotCounter == i + 1)
				{
					dotsUsedCounter++;
					combination += '.';

					//here we tell when it will be the next time to add the next dot. If the next dot is the last one, the "time to add a dot" will not be incremented by 1 but more.
					if (lastDot == dotsUsedCounter - 1)
						dotCounter += lastDotCounter;
					else
						dotCounter += 1;
				}
				//storing last dot index for later use
				if (dotsUsedCounter == 4)
					lastDotIndex = combination.length() - 1;
			}
			else
			//after the last dot, just copy s as it is
				combination += s[i];
		}

			//check if combination is valid and push to combinations accordingly
		combinations.push_back(combination);
		for (int i = 0; i < combination.length(); i++)
		{
			if (combination[i] != '.')
				number += combination[i];
			else
			{
				number = 0;
				currentDotIndex = i;
			}

			if (number > 255)
			{
				if (currentDotIndex > lastDotIndex)
				{
					//call accordingly
				}
				else
				{
					//call accordinglly
				}
				combinations.pop_back();
				break;
			}
		}
		//call with plus one on last dot

		findCombinations(combinations, s, combination, dotCounter, lastDotCounter, 0, lastDot);
	}

	vector<string> genIp(string& s)
	{
		string combination;
		vector<string> combinations;

		findCombinations(combinations, s, combination, 1, 1, 0, 4);
		return combinations;
	}

};

int main()
{
	Solution solution;
	string numbers = "12323512612";
	solution.genIp(numbers);
}