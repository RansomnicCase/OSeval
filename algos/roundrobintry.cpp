#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits.h>
#include <queue>
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
    int remaining; // we put this here so we can avoid using another array for remaining
};

void roundrobin(vector<process> &proc, int n, int quantum)
{
    queue<int> ready;
    vector<bool> visited(n, false);
    int current = 0;
    int completed = 0;

    for (int i = 0; i < n; i++)
    {
        proc[i].remaining = proc[i].burst;
    }

    ready.push(0);
    visited[0] = true;
    while (completed < n)
    {
        if (ready.empty())
        {
            current++;
            continue;
        }
        int idx = ready.front();
        ready.pop();

        if (proc[idx].remaining > quantum)
        {
            proc[idx].remaining -= quantum;
            current += quantum;
        }
        else
        {
            current += proc[idx].remaining;
            proc[idx].completion = current;
            proc[idx].tat = proc[idx].completion - proc[idx].arrival;
            proc[idx].waiting = proc[idx].tat - proc[idx].burst;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && proc[i].arrival <= current && proc[i].remaining > 0)
            {
                visited[i] = true;
                ready.push(i);
            }
        }
        if (proc[idx].remaining > 0)
        {
            ready.push(idx);
        }
    }
}