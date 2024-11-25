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
    int current = 0;
    int completed = 0;
    vector<bool> visited(n, false);

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
            proc[idx].remaining = 0;
            proc[idx].completion = current;
            proc[idx].tat = proc[idx].completion - proc[idx].arrival;
            proc[idx].waiting = proc[idx].tat - proc[idx].burst;
            completed++;
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && proc[i].arrival <= current && proc[i].remaining > 0)
            {
                ready.push(i);
                visited[i] = true;
            }
        }

        if (proc[idx].remaining > 0)
        {
            ready.push(idx);
        }
    }
}

void print(vector<process> &proc, int n)
{
    cout << "\nProcess Information:\n";
    cout << setw(10) << "Process" << setw(15) << "Arrival Time" << setw(15) << "Burst Time"
         << setw(15) << "Waiting Time" << setw(15) << "Turnaround Time" << setw(15) << "Completion time" << endl;
    for (const auto &p : proc)
    {
        cout << setw(10) << "P" << p.pid << setw(15) << p.arrival
             << setw(15) << p.burst << setw(15) << p.waiting
             << setw(15) << p.tat << setw(15) << p.completion << endl;
    }
}
