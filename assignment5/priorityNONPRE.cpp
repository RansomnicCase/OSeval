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
};

void priorityNONPRE(vector<process> &proc, int n)
{
    sort(proc.begin(), proc.end(), [](const process &a, const process &b)
         {
        if(a.arrival==b.arrival){
            return a.priority<b.priority;
        }
        return a.arrival < b.arrival; });

    int current = 0;
    for (int i = 0; i < n; i++)
    {
        if (proc[i].arrival < current)
            current = proc[i].arrival;

        proc[i].completion = current;
        proc[i].tat = proc[i].completion - proc[i].arrival;
        proc[i].waiting = proc[i].tat - proc[i].burst;
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

// while taking input in main, also take priority.