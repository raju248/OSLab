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
};

bool comp(process a, process b)
{
    return a.arrivalTime < b.arrivalTime;
}

bool comp2(process a, process b)
{
    return a.cpuTime < b.cpuTime;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    int total_time = 0;

    cout << "Enter the number of process : ";
    cin >> n;

    vector<process> v (n);

    int x;

    cout << "Enter the CPU times :\n";

    for(int i=0;i<n;i++)
    {
        cin >> x;
        v[i].cpuTime = x;
        v[i].id = i+1;
        total_time += x;
    }

    cout << "Enter the CPU times :\n";

    for(int i=0;i<n;i++)
    {
        cin >> x;
        v[i].arrivalTime = x;
    }

    sort(v.begin(),v.end(),comp);

//    for(int i =0;i<n;i++)
//    {
//        cout << v[i].id << endl;
//    }

    sort(v.begin()+1,v.end(),comp2);

    for(int i =0;i<n;i++)
//    {
//        cout << v[i].id << endl;
//    }

    int t = v[0].arrivalTime;
    int totalTurnAroundTime=0;
    int totalWaitingTime=0;

    for(int j=0;j<n;j++)
    {
        t+=v[j].cpuTime;
        v[j].completeTime+=t;
    }

    for(int i=0;i<n;i++)
    {
        v[i].turnAroundTime = v[i].completeTime - v[i].arrivalTime;
        v[i].waitTime = v[i].turnAroundTime - v[i].cpuTime;
        totalTurnAroundTime+=v[i].turnAroundTime;
        totalWaitingTime+=v[i].waitTime;
    }

    for(int i =0;i<n;i++)
    {
        cout << v[i].id << " " << v[i].waitTime << " " << v[i].turnAroundTime << endl;
    }

    cout << "Average turnaround time : " << totalTurnAroundTime/(n*1.0) << endl;
    cout << "Average waiting time : " << totalWaitingTime/(n*1.0) << endl;


    return 0;
}
