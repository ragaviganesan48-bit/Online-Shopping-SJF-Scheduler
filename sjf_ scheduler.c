#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], ct[20];
    int tat[20], wt[20], done[20] = {0};
    int min, index;

    float avg_tat = 0, avg_wt = 0;

    printf("ONLINE SHOPPING REQUEST SCHEDULER\n");
    printf("NON-PREEMPTIVE SJF SCHEDULING\n\n");

    printf("Enter number of orders: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time and Burst Time for Order %d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    while (completed < n)
    {
        min = 9999;
        index = -1;

        for (i = 0; i < n; i++)
        {
            if (done[i] == 0 && at[i] <= time && bt[i] < min)
            {
                min = bt[i];
                index = i;
            }
        }

        if (index == -1)
        {
            time++;
        }
        else
        {
            time = time + bt[index];
            ct[index] = time;

            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            done[index] = 1;
            completed++;
        }
    }

    printf("\n\nOrder\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("O%d\t%d\t%d\t%d\t%d\t%d\n",
        i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);

    return 0;
}
