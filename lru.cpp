#include<bits/stdc++.h>
using namespace std;
int ar[1000];
int main()
{
    int p;
    FILE *fptr;
    fptr = fopen("D:\\program.txt","r");


    printf("Number of pages: ");
    fscanf(fptr,"%d",&p);

    printf("%d\n",p);
    int n;
    printf("Number of page References: ");
    fscanf(fptr,"%d",&n);

    printf("%d\n",n);
    printf("Reference String: ");
    for (int i = 0; i < n; i++)
    {
        fscanf(fptr,"%d",&ar[i]);

        printf("%d ",ar[i]);
    }
    printf("\nNumber of Memory Page Frame: ");
    int F;
    fscanf(fptr,"%d",&F);

    printf("%d\n\n\n",F);
    int memory [F];
    for (int i = 0; i < F; i++)
    {
        memory[i] = -1;
    }
    int hit = 0;
    int fault = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < F; j++)
        {
            if (memory[j] == ar[i])
            {
                flag = true;
            }
        }
        if (flag)
        {
            hit++;
        }
        else
        {
            fault++;
            bool done = false;
            for (int j = 0; j < F; j++)
            {
                if (memory[j] == -1)
                {
                    memory[j] = ar[i];
                    done = true;
                    break;
                }
            }
            if (!done)
            {
                int mi = -1;
                int mx = -1;
                for (int j = 0; j < F; j++)
                {
                    int dis = -1;
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (memory[j] == ar[k])
                        {
                            dis = k;
                            break;
                        }
                    }
                    if (abs(dis - i) > mx)
                    {
                        mx = abs(dis - i);
                        mi = j;
                    }
                }
                memory[mi] = ar[i];
            }
             for(int k=0; k<F; k++)
            {
                printf("%d ",memory[k]);
            }
            printf("\n");
        }
    }
    cout << "Number of page fault using Least Recently Used Page replacement Algorithm: " << fault << "\n";
    cout << "Page Fault Rate: " << (double) fault / (double) n * 100.00 << "%\n";
    fclose(fptr);
    return 0;
}
