#include<bits/stdc++.h>
using namespace std;

struct process{
    int pid;
    int arrival;
    int cpu;
    int rem_cpu;
}p;

bool cmp(process a,process b)
{
    return a.arrival<b.arrival;
}

int main()
{
    int n;
    cin>>n;
    process ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>p.pid>>p.arrival>>p.cpu;
        p.rem_cpu=p.cpu;
        ar[i]=p;
    }
    sort(ar,ar+n,cmp);
    int time=0;
    double twt=0,t_tat=0;
    for(int i=0;i<n;i++)
    {
        time+=ar[i].cpu;
        ar[i].rem_cpu=0;
        int w=time-ar[i].arrival-ar[i].cpu;
        int tat=w+ar[i].cpu;
        cout<<"process "<<ar[i].pid<<"W "<<w<<"T "<<tat<<endl;
        twt+=w;
        t_tat+=tat;
    }
    cout<<twt/n<<" "<<t_tat/n<<endl;
}
