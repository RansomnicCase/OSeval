#include <iostream>
using namespace std;
void firstfit(int process[], int blocks[], int n, int m)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (process[i] <= blocks[j])
            {
                allocation[i] = j;
                blocks[j] -= process[i];
                break;
            }
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
void worstfit(int process[], int blocks[], int n, int m)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int max = -1;
        int idx = -1;
        for (int j = 0; j < m; j++)
        {
            if (process[i] <= blocks[j] && blocks[j] > max)
            {
                idx = j;
                max = blocks[j];
            }
        }
        if (idx != -1)
        {
            allocation[i] = idx;
            blocks[idx] -= process[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
void Bestfit(int process[], int blocks[], int n, int m)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int min = 10000;
        int idx = -1;
        for (int j = 0; j < m; j++)
        {
            if (process[i] <= blocks[j] && blocks[j] < min)
            {
                idx = j;
                min = blocks[j];
            }
        }
        if (idx != -1)
        {
            allocation[i] = idx;
            blocks[idx] -= process[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int m, n;
    int blocksize[] = {100, 500, 200, 300, 600};
    int processsize[] = {212, 417, 112, 426};
    m = sizeof(blocksize) / sizeof(blocksize[0]);
    n = sizeof(processsize) / sizeof(processsize[0]);
    worstfit(processsize, blocksize, n, m);
}