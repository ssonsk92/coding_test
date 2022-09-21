#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class comp
{
public:
	bool operator()(vector<int>& lhs, vector<int>& rhs)
	{
		if (rhs[1] == lhs[1])
			return rhs[0] < lhs[0];

		return rhs[1] < lhs[1];
	}
};

int solution(vector<vector<int>> jobs)
{
	int answer = 0;

	priority_queue<vector<int>, vector<vector<int>>, comp> pq(jobs.begin(), jobs.end());

	int ms = 0;
	vector<vector<int>> temp;
	while (!pq.empty())
	{
		vector<int> job = pq.top();
		pq.pop();

		// cpu idle time skip
		if (ms < job[0])
		{
			temp.push_back(job);

			if (pq.empty())
			{
				ms = 1000;
				for (vector<int> v : temp)
				{
					pq.push(v);
					ms = min(ms, v[0]);
				}
				temp.clear();
			}

			continue;
		}

		int wait_time = max(0, ms - job[0]);
		int process_time = wait_time + job[1];
		ms += job[1];
		answer += process_time;

		printf("job (%d %d), wait time : %d, process time : %d, current ms : %d\n", job[0], job[1], wait_time, process_time, ms);

		if (!temp.empty())
		{
			for (vector<int> v : temp)
			{
				pq.push(v);
			}
			temp.clear();
		}
	}

	return answer / jobs.size();
}

int main()
{
	vector<vector<int>> jobs = { {9, 1}, {5, 2}, {0,3} };

	cout << solution(jobs) << endl;

	return 0;
}