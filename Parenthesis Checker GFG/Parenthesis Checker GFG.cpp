/*
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

Example 1:

Input:
{([])}
Output:
true
Explanation:
{ ( [ ] ) }. Same colored brackets can form
balanced pairs, with 0 number of
unbalanced bracket.
Example 2:

Input:
()
Output:
true
Explanation:
(). Same bracket can form balanced pairs,
and here only 1 type of bracket is
present and in balanced way.
Example 3:

Input:
([]
Output:
false
Explanation:
([]. Here square bracket is balanced but
the small bracket is not balanced and
Hence , the output will be unbalanced.
Your Task:
This is a function problem. You only need to complete the function ispar() that takes a string as a parameter and returns a boolean value true if brackets are balanced else returns false. The printing is done automatically by the driver code.

Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)

Constraints:
1 <= |x| <= 32000
*/


#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
//Function to check if brackets are balanced or not.
	bool ispar(string x)
	{
		//op = opening parenthesis | cp = closing parenthesis
		stack<char> op;
		int opCounter = 0, cpCounter = 0;
		for (int i = 0; i < x.length(); i++)
		{
			switch (x[i])
			{
				case '(':
				case '[':
				case '{':
				op.push(x[i]);
				opCounter++;
				break;
				case ')':
				if (op.empty())
				{
					return false;
				}
				else if (op.top() == '(')
				{
					op.pop();
					cpCounter++;
				}
				else
					return false;
				break;
				case ']':
				if (op.empty())
				{
					return false;
				}
				else if (op.top() == '[')
				{
					op.pop();
					cpCounter++;
				}
				else
					return false;
				break;
				case '}':
				if (op.empty())
				{
					return false;
				}
				else if (op.top() == '{')
				{
					op.pop();
					cpCounter++;
				}
				else
					return false;
				break;
			}
		}
		if (opCounter == cpCounter)
		{
			return true;
		}
		else return false;
	}
};

main()
{
	int t;
	string a;
	cin >> t;
	while (t--)
	{
		cin >> a;
		Solution obj;
		if (obj.ispar(a))
			cout << "balanced" << endl;
		else
			cout << "not balanced" << endl;
	}