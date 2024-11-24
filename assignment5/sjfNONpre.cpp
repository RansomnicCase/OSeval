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
};

void sjf(vector<process> &proc, int n)
{
    vector<bool> IScompleted(n, false);

    int currentTime = 0;
    int completed = 0;

    while (completed < n)
    {

        int idx = -1;
        int minburst = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!IScompleted[i] && proc[i].arrival <= currentTime && proc[i].burst < minburst)
            {
                minburst = proc[i].burst;
                idx = i;
            }
        }
        if (idx != -1)
        {
            currentTime += proc[idx].burst;
            proc[idx].completion = currentTime;
            proc[idx].tat = proc[idx].completion - proc[idx].arrival;
            proc[idx].waiting = proc[idx].tat - proc[idx].burst;
            IScompleted[idx] = true;
            completed++;
        }
        else
        {
            currentTime++;
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

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<process> proc(n);
    for (int i = 0; i < n; i++)
    {
        proc[i].pid = i + 1;
        cout << "Enter arrival time and burst time for Process " << i + 1 << ": ";
        cin >> proc[i].arrival >> proc[i].burst;
    }

    sjf(proc, n);
    print(proc, n);
}