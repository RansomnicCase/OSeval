#include <iostream>
#include <vector>
using namespace std;

void firstfit(int process[], int blocks[], int n, int m)
{
    vector<int> allocation(n, -1);

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
}

void worstfit(int process[], int blocks[], int n, int m)
{
    vector<int> allocation(n, -1);

    for (int i = 0; i < n; i++)
    {
        int max = -1;
        int idx = -1;
        for (int j = 0; j < m; j++)
        {
            if (process[i] <= blocks[j] && blocks[j] > max)
            {
                max = blocks[j];
                idx = j;
            }
        }
        if (!idx == -1)
        {
            allocation[i] = idx;
            blocks[idx] -= process[idx];
        }
    }
}

void bestfit(int process[], int blocks[], int n, int m)
{

    vector<int> allocation(n, -1);
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        int idx = -1;
        for (int j = 0; j < m; j++)
        {
            if (process[i] <= blocks[j] && blocks[j] < min)
            {
                idx = j;
                min = blocks[j];
            }
        }
        if (!idx == -1)
        {
            allocation[i] = idx;
            blocks[idx] -= process[i];
        }
    }
}