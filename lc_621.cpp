// permenant libs
#include <assert.h>
#include <iostream>
using namespace std;

/* problem description & site:
https://leetcode.com/problems/task-scheduler/description/
621. Task Scheduler

Given a char array representing tasks CPU need to do. 
It contains capital letters A to Z where different letters represent different tasks.
Tasks could be done without original order. Each task could be done in one interval. 
For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, 
there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all
the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

// problem assigned libs
#include <vector>

// add libs

#include <algorithm>

class Solution_621 {
public:

	static void test() {
		vector<char> a = { 'A','A','A','b','b','b'};
		assert(Solution_621().leastInterval(a, 2) == 8);

		a = { 'A','A','A','A','A','A','B','C','D','E','F','G' };
		assert(Solution_621().leastInterval(a, 2) == 16);
		assert(true);
		assert(true);
	}
	int leastInterval(vector<char>& tasks, int n) {
		vector<size_t> occ(26,0);
		
		for (int i = 0; i < tasks.size(); ++i)
		{
			++occ[ tasks[i] - 'A'];
		}

		sort(occ.begin(), occ.end());
		int i = 25;
		while (occ[i] == occ[25]) --i;

		/*
		这是个插空问题，最大频率的tasks，他们的频率x作为插板数目，假设最大的有y个，则需要
		x * (n + 1)  // 理论上需要
		- n + (y - 1) // 减去最后的空转
		AAABBB,2 :
		AB_AB_AB_    2*(2+1) = 9
		AB_AB_AB     9-2+(2-1) = 8

		如果插不满就按照这个来算，如果插满则==一开始的任务vector长度

		如果一共N种任务，且间隔>N，则肯定只用
		计算任务数目里面，数目最大的一个，例如A出现了10次，则看看10次的还有哪些，如果还有B
		其他的则插空进去就行
		*/
		return max(occ[25] * (n + 1) - n + (25 - i - 1), tasks.size());

	}

	/*
	int leastInterval(vector<char>& tasks, int n) {
		int task_num = tasks.size();
		map<char, pair<int,int>> M; 
		// pair: first int = task_count, second = last_run_timestamp
		for (int i = 0; i < task_num; ++i) {
			M[tasks[i]].first++;
		}
		int timestamp = n + 1;
		int interval = 0;
		while (task_num > 0)
		{
			++interval;
			int task_remain = 0;
			map<char, pair<int, int>>::iterator it = M.begin();
			map<char, pair<int, int>>::iterator available= it;
			for (;
				it != M.end();
				++it)
			{
				if (it->second.first > task_remain // still needs to be run
					&& timestamp > it->second.second + n) // time has passed the gap
				{
					task_remain = it->first;
					available = it;
				}
			}

			if (timestamp <= available->second.second + n) // find a round and cannot match
			{
				//printf("idle, ");
			}
			else // found
			{
				//printf("%c, ", available->first);

				available->second.second = timestamp;
				available->second.first--;
				--task_num;
			}
			++timestamp;
		}
		//printf("\n");
		return interval;
	}*/
};