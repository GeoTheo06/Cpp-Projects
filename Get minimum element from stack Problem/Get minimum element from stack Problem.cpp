/*Problem From GFG

You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Example 1:

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 2 1
Explanation: In the first test case for
query
push(2)  Insert 2 into the stack.
		 The stack will be {2}
push(3)  Insert 3 into the stack.
		 The stack will be {2 3}
pop()    Remove top element from stack
		 Poped element will be 3 the
		 stack will be {2}
getMin() Return the minimum element
		 min element will be 2
push(1)  Insert 1 into the stack.
		 The stack will be {2 1}
getMin() Return the minimum element
		 min element will be 1
Your Task:
You are required to complete the three methods push() which take one argument an integer 'x' to be pushed into the stack, pop() which returns a integer poped out from the stack and getMin() which returns the min element from the stack. (-1 will be returned if for pop() and getMin() the stack is empty.)

Expected Time Complexity : O(1) for all the 3 methods.
Expected Auixilliary Space : O(1) for all the 3 methods.

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100

*/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
	stack<int> smallestEl;
	stack<int> s;
	int poppedEl;
public:
   /*returns min element from stack*/
	int getMin()
	{
		if (s.empty())
			return -1;
		return smallestEl.top();
	}

	/*returns poped element from stack*/
	int pop()
	{
		if (s.empty())
		{
			return -1;
		}
		poppedEl = s.top();
		s.pop();
		if (poppedEl == smallestEl.top())
			smallestEl.pop();
		return poppedEl;
	}

	/*push element x into the stack*/
	void push(int x)
	{
		s.push(x);
		if (smallestEl.empty() || smallestEl.top() >= x)
			smallestEl.push(x);
	}
};

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int q;
		cin >> q;
		Solution ob;
		while (q--)
		{
			int qt;
			cin >> qt;
			if (qt == 1)
			{
				//push
				int att;
				cin >> att;
				ob.push(att);
			}
			else if (qt == 2)
			{
				//pop
				cout << ob.pop() << " ";
			}
			else if (qt == 3)
			{
				//getMin
				cout << ob.getMin() << " ";
			}
			cout << endl;
		}
	}
	return 0;
}