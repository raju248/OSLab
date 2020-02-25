#include<bits/stdc++.h>
using namespace std;

struct process{
    int pid;
    int arrival;
    int cpu;
    int rem_cpu;
}p;

bool cmp(process a, process b)
{
    return a.arrival<b.arrival;
}

int main()
{
    int n;
    cin>>n;

    process ar[n];
    int total_time=0;

    for(int i=0;i<n;i++)
    {
        cin>>p.arrival>>p.cpu;
        p.rem_cpu=p.cpu;
        p.pid=i;
        ar[i]=p;
        total_time+=p.cpu;
    }

    sort(ar,ar+n,cmp);

    for(int time=0;time<=total_time;)
    {
        int remaining=INT_MAX;
        int id;
        for(int i=0;i<n;i++)
        {
            if(ar[i].arrival<=time&&ar[i].rem_cpu<remaining&&ar[i].rem_cpu>0)
            {
                remaining=ar[i].rem_cpu;
                id=i;
            }
        }
        time+=ar[id].cpu;
        ar[id].rem_cpu=0;
        if(ar[id].rem_cpu==0)
        {
            cout<<time<<" "<<ar[id].pid<<endl;;
        }
    }
}

/*
6
7 12
5 11
6 9
0 17
17 3
14 13
*/

//241305

