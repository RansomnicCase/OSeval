#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits.h>
using namespace std;

class process
{
public:
    int pid;
    int arrival;
    int burst;
    int waiting;
    int tat;
    int completion;
    int priority;
    int remaining;
};

void priorityPRE(vector<process> &proc, int n)
{
    int current = 0;
    int completed = 0;
    int idx = -1;
    int minpriority = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        proc[i].remaining = proc[i].burst;
    }

    while (completed < n)
    {
        idx = -1;
        minpriority = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (proc[i].arrival <= current && proc[i].remaining > 0 && proc[i].priority < minpriority)
            {
                idx = i;
                minpriority = proc[i].priority;
            }
        }
        if (idx != -1)
        {
            current++;
            proc[idx].remaining--;
        }
        if (proc[idx].remaining == 0)
        {
            completed++;
            proc[idx].completion = current;
            proc[idx].tat = proc[idx].completion - proc[idx].arrival;
            proc[idx].waiting = proc[idx].tat - proc[idx].burst;
        }
        else
        {
            current++;
        }
    }
}