#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &allocation, vector<vector<int>> &max, vector<int> available, int processes, int resources)
{

    vector<vector<int>> need(processes, vector<int>(resources));
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    vector<int> work = available;
    vector<bool> finished(processes, false);
    vector<int> safeSequence;

    while (safeSequence.size() < processes)
    {
        bool foundProcess = false;

        for (int i = 0; i < processes; i++)
        {
            if (!finished[i])
            {
                bool canAllocate = true;

                for (int j = 0; j < resources; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate)
                {
                    for (int j = 0; j < resources; j++)
                    {
                        work[j] += allocation[i][j];
                    }

                    safeSequence.push_back(i);
                    finished[i] = true;
                    foundProcess = true;
                }
            }
        }

        if (!foundProcess)
        {
            cout << "The system is not in a safe state." << endl;
            return false;
        }
    }

    cout << "The system is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < safeSequence.size(); i++)
    {
        cout << "P" << safeSequence[i];
        if (i != safeSequence.size() - 1)
            cout << " -> ";
    }
    cout << endl;
    return true;
}

int main()
{
    int processes, resources;

    cout << "Enter the number of processes: ";
    cin >> processes;
    cout << "Enter the number of resources: ";
    cin >> resources;

    vector<vector<int>> allocation(processes, vector<int>(resources));
    vector<vector<int>> max(processes, vector<int>(resources));
    vector<int> available(resources);

    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter the max matrix:\n";
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            cin >> max[i][j];
        }
    }

    cout << "Enter the available resources: ";
    for (int i = 0; i < resources; i++)
    {
        cin >> available[i];
    }

    isSafe(allocation, max, available, processes, resources);

    return 0;
}
