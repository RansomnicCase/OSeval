#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &allocation, vector<vector<int>> &max, vector<int> available, int processes, int resources)
{
    vector<vector<int>> need(processes, vector<int>(resources));
    vector<bool> finished(processes, false);
    vector<int> safe;
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    vector<int> work = available;
    while (safe.size() < processes)
    {
        bool foundprocess = false;
        for (int i = 0; i < processes; i++)
        {
            if (!finished[i])
            {
                bool cangive = true;

                for (int j = 0; j < processes; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        cangive = false;
                        break;
                    }
                }
            }
        }
    }
}