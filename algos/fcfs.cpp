#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
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
void findCompletionTime(vector<process> &proc, int n)
{
    sort(proc.begin(), proc.end(), [](const process &a, const process &b)
         { return a.arrival < b.arrival; });
    proc[0].completion = proc[0].burst + proc[0].arrival;
    for (int i = 1; i < n; i++)
    {
        proc[i].completion = max(proc[i - 1].completion, proc[i].arrival) + proc[i].burst;
    }
}

void findTAT(vector<process> &proc, int n)
{
    for (int i = 0; i < n; i++)
    {
        proc[i].tat = proc[i].completion - proc[i].arrival;
    }
}
void findwait(vector<process> &proc, int n)
{
    proc[0].waiting = 0;
    for (int i = 0; i < n; i++)
    {
        proc[i].waiting = proc[i].tat - proc[i].burst;
    }
}

void FindFCFS(vector<process> &proc, int n)
{
    findCompletionTime(proc, n);
    findTAT(proc, n);
    findwait(proc, n);
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
    sort(proc.begin(), proc.end(), [](const process &a, const process &b)
         { return a.arrival < b.arrival; });
    FindFCFS(proc, n);
    print(proc, n);
}
