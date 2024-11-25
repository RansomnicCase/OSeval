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

void SJFpre(vector<process> &proc, int n)
{
    vector<int> remaining(n); // Holds remaining burst times
    int current = 0;          // Current time
    int completed = 0;        // Number of completed processes

    // Initialize remaining burst times
    for (int i = 0; i < n; i++)
    {
        remaining[i] = proc[i].burst;
    }

    while (completed < n)
    {
        int mintime = INT_MAX; // Minimum remaining time
        int idx = -1;          // Index of the selected process

        // Find the process with the shortest remaining time at the current time
        for (int i = 0; i < n; i++)
        {
            if (proc[i].arrival <= current && remaining[i] > 0 && remaining[i] < mintime)
            {
                idx = i;
                mintime = remaining[i];
            }
        }

        if (idx != -1)
        {
            // Process the selected process for 1 unit of time
            remaining[idx]--;
            current++;

            // If the process finishes
            if (remaining[idx] == 0)
            {
                completed++;
                proc[idx].completion = current;                           // Set completion time
                proc[idx].tat = proc[idx].completion - proc[idx].arrival; // Turnaround time
                proc[idx].waiting = proc[idx].tat - proc[idx].burst;      // Waiting time
            }
        }
        else
        {

            current++;
        }
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

    SJFpre(proc, n);
    print(proc, n);
}