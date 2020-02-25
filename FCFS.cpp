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
};

bool comp(process a, process b)
{
    return a.arrivalTime < b.arrivalTime;
}

bool compId(process a, process b)
{
    return a.id < b.id;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;

    cout << "Enter the number of process : ";
    cin >> n;

    vector<process> v (n);

    int x;

    cout << "Enter the CPU times :\n";

    for(int i =0;i<n;i++)
    {
        cin >> x;
        v[i].cpuTime = x;
        v[i].id = i+1;
    }

    cout << "Enter the CPU times :\n";

    for(int i =0;i<n;i++)
    {
        cin >> x;
        v[i].arrivalTime = x;
    }

    sort(v.begin(),v.end(),comp);

    v[0].waitTime = 0;
    v[0].serviceTime = 0;

    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;

    for(int i =1;i<n;i++)
    {
        v[i].serviceTime = v[i-1].cpuTime + v[i-1].serviceTime;
        v[i].waitTime =  v[i].serviceTime - v[i].arrivalTime;

        totalWaitTime += v[i].waitTime;
    }

    for(int i =0;i<n;i++)
    {
        v[i].turnAroundTime = v[i].waitTime + v[i].cpuTime;
        totalTurnAroundTime += v[i].turnAroundTime;
    }

    sort(v.begin(),v.end(),compId);

    vector<process> :: iterator it;

    for(it = v.begin(); it!=v.end();it++)
    {
        cout << "Process " << it->id << ": Waiting Time: " << it->waitTime << " Turnaround Time: " << it->turnAroundTime << endl;
    }

    cout << "Average waiting time: " << totalWaitTime/(n*1.0) << endl;
    cout << "Average turnaround time: " << totalTurnAroundTime/(n*1.0) << endl;


    return 0;
}
