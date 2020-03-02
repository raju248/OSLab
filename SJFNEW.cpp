#include<bits/stdc++.h>
using namespace std;

struct process
{
    int id ;
    int cpuTime ;
    int arrivalTime ;
    int waitTime;
    int serviceTime;
    int turnAroundTime;
    int completeTime=0;
    int remainTime;
};

bool comp(process a, process b)
{
    return a.arrivalTime < b.arrivalTime;
}

bool compID(process a, process b)
{
    return a.id < b.id;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int total_time = 0;
    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;

    cout << "Enter the number of process : ";
    cin >> n;

    vector<process> v (n);

    cout << "Enter the CPU times :\n";

    for(int i=0;i<n;i++)
    {
        cin >>  v[i].cpuTime;
        v[i].id = i+1;
        v[i].remainTime = v[i].cpuTime;
    }

    cout << "Enter the arrival times :\n";

    for(int i=0;i<n;i++)
    {
        cin >> v[i].arrivalTime;
    }

    sort(v.begin(),v.end(),comp);

    int processCount = 0;
    int current_process = 0;

    cout << "0";
    while(true)
    {
        processCount++;

        if(current_process==0)
            v[current_process].waitTime = 0;
        else
           totalWaitTime += v[current_process].waitTime = total_time - v[current_process].arrivalTime;

        total_time += v[current_process].cpuTime;
        v[current_process].remainTime = 0;
        v[current_process].completeTime = total_time;

        cout << "--P" << v[current_process].id << "--" << total_time ;

        totalTurnAroundTime += v[current_process].turnAroundTime = v[current_process].waitTime + v[current_process].cpuTime;

        int nextJobCpuTime = 9999;

        for(int i =0;i<n;i++)
        {
            if(v[i].arrivalTime<=total_time && v[i].cpuTime<nextJobCpuTime && v[i].remainTime!=0)
            {
                nextJobCpuTime = v[i].cpuTime;
                current_process = i;
            }
        }

        if(processCount==n)
            break;
    }

    cout << endl;

    sort(v.begin(),v.end(),compID);

    vector <process> :: iterator it;

    for(it= v.begin(); it!= v.end(); it++)
    {
        cout << "Process " << it->id << ":  waiting time : " << it->waitTime << " turn around time : " << (it->cpuTime + it->waitTime)  << endl;
    }

    cout << endl;

    cout << "Average waiting time : " << totalWaitTime/(n*1.0) << endl;
    cout << "Average turn around time : " << totalTurnAroundTime/(n*1.0) <<endl;

    return 0;
}
