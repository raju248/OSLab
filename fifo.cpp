#include<bits/stdc++.h>
using namespace std;
int ar[1000];
int main()
{
    int p;
    int num;
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

    int F;
    printf("\nNumber of Memory Page Frame: ");
    fscanf(fptr,"%d",&F);
    printf("%d\n\n\n",F);

    int memory [F];
    for (int i = 0; i < F; i++)
    {
        memory[i] = -1;
    }

    int first = 0;
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
                memory[first] = ar[i];
                first++;
                first = first%F;
            }
            for(int k=0; k<F; k++)
            {
                printf("%d ",memory[k]);
            }
            printf("\n");
        }
    }
    cout << "Number of page fault using FIFO Page replacement Algorithm: " << fault << "\n";
    cout << "Page Fault Rate: " << (double) fault / (double) n * 100.00 << "%\n";
    fclose(fptr);
    return 0;
}
