#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution
{
public:
    char findMaxReadyTask(unordered_map<char, int> &time_map, unordered_map<char, int> &task_map, vector<char> &taskName)
    {
        char mxTask = ' ';
        int mxTime = -1;

        for (int i = 0; i < taskName.size(); i++)
        {
            if (time_map[taskName[i]] <= 0 && task_map[taskName[i]] > 0)
            {
                if (mxTask == ' ')
                {
                    mxTask = taskName[i];
                    mxTime = task_map[mxTask];
                }
                else
                {
                    if (mxTime < task_map[taskName[i]])
                    {
                        mxTask = taskName[i];
                        mxTime = task_map[mxTask];
                    }
                }
            }
        }

        return mxTask;
    }

    bool isDone(unordered_map<char, int> &task_map, vector<char> &taskName)
    {
        for (int i = 0; i < taskName.size(); i++)
        {
            if (task_map[taskName[i]] > 0)
                return false;
        }
        return true;
    }

    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> time_map;
        unordered_map<char, int> task_map;
        vector<char> taskName;

        for (int i = 0; i < tasks.size(); i++)
        {
            if (task_map.find(tasks[i]) == task_map.end())
            {
                task_map[tasks[i]] = 1;
                taskName.push_back(tasks[i]);
                time_map[tasks[i]] = 0;
            }
            else
            {
                task_map[tasks[i]]++;
            }
        }

        int time = 0;

        while (!isDone(task_map, taskName))
        {
            char task = findMaxReadyTask(time_map, task_map, taskName);

            if (!(task == ' '))
            {
                time_map[task] = n;
                task_map[task]--;
            }

            time++;

            for (int i = 0; i < taskName.size(); i++)
            {
                if (taskName[i] != task)
                {
                    time_map[taskName[i]]--;
                }
            }
        }

        return time;
    }
};

int main()
{
    Solution *solution = new Solution();
    
    int n = 2;
    vector<char> test = {'A','A','A','B','B','B'};

    int res = solution->leastInterval(test, n);

    cout << "Hello world";
}