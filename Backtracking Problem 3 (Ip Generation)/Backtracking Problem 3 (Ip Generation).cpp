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

	void findCombinations(vector<string>& combinations, string s, string& substring, int dotCounter)
	{
		int dotCounter = 0;
		for (int i = 0; i < s.length(); i++)
		{
		}

		findCombinations(combinations, s, substring, 1);
	}

	vector<string> genIp(string& s)
	{
		string substring;
		vector<string> combinations;

		int divider = (float(s.length() / 4) == 0) ? s.length() / 4 : (s.length() / 4) + 1;

		for (int i = 0; i < s.length(); i++)
		{
			substring += s[i];

			if (i != 0 && (i + 1) % divider == 0)
			{
				substring += '.';
			}
		}
		cout << substring;
		//findCombinations(combinations, s, substring, s.length() / 4);
		return combinations;
	}

};

int main()
{
	Solution solution;
	string numbers = "12323512621";
	solution.genIp(numbers);
}