#include<bits/stdc++.h>
using namespace std;

struct process
{
    int id ;
    int cpuTime ;
    int arrivalTime;
    int waitTime =0;
    int serviceTime=0;
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

int total_time = 0;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;

    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;

    cout << "Enter the number of process : ";
    cin >> n;

    vector<process> v (n);
    vector<process> temp;

    int x;

    cout << "Enter the CPU times :\n";

    for(int i=0;i<n;i++)
    {
        cin >> v[i].cpuTime ;
        v[i].id = i+1;
        v[i].remainTime = v[i].cpuTime;
    }

    cout << "Enter the arrival times :\n";

    for(int i=0;i<n;i++)
    {
        cin >> v[i].arrivalTime;
    }


    cout << "Enter the value of time quantam : ";
    cin >> q;

    sort(v.begin(),v.end(),comp);

    queue<process>tempQ;

    for(process p : v)
    {
        tempQ.push(p);
    }

    cout << endl;

    tempQ.pop();

    queue <process> readyQueue;

    readyQueue.push(v[0]);
    v[0].serviceTime = 0;
    v[0].waitTime = 0;
    cout << "0" ;

    while(!readyQueue.empty())
    {
        process p = readyQueue.front();
        readyQueue.pop();

        p.waitTime += total_time - p.arrivalTime;

        if(p.remainTime>=q)
        {
            total_time += q;
            p.remainTime -= q;
        }
        else if(p.remainTime<q)
        {
            total_time+=p.remainTime;
            p.remainTime = 0;
        }

        cout << "--P" << p.id <<"--"<<total_time ;


        process x;

        int nextArrivalTime = 0;

        while(!tempQ.empty() && nextArrivalTime<=total_time)
        {
            x = tempQ.front();
            nextArrivalTime = x.arrivalTime;

            if(nextArrivalTime<=total_time)
            {
                readyQueue.push(x);
                tempQ.pop();
            }
        }

        if(p.remainTime>0)
        {
            p.arrivalTime = total_time;
            readyQueue.push(p);
        }
        else if(p.remainTime==0)
        {
            temp.push_back(p);
            p.completeTime = total_time;
        }
    }
    cout << endl;

    sort(temp.begin(),temp.end(),compID);

    vector <process> :: iterator it;

    for(it= temp.begin(); it!= temp.end(); it++)
    {
        cout << "Process " << it->id << ":  waiting time : " << it->waitTime << " turn around time : " << (it->cpuTime + it->waitTime)  << endl;
        totalWaitTime += it->waitTime;
        totalTurnAroundTime += (it->cpuTime + it->waitTime);
    }

    cout << "Average turnaround time : " << totalTurnAroundTime/(1.0*n) <<endl;
    cout << "Average waiting time : " << totalWaitTime/(1.0*n) << endl;


    return 0;
}


