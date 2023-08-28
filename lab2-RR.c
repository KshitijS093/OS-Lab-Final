#include <stdio.h>

#define MAX_PROCESSES 4
#define TIME_QUANTUM 2

void roundRobinScheduling(int processes[], int burst_times[], int arrival_times[], int n) {
    int remaining_time[MAX_PROCESSES];
    int completion_time[MAX_PROCESSES];
    int turnaround_times[MAX_PROCESSES];
    int waiting_times[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_times[i];
        completion_time[i] = 0;
    }

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (arrival_times[i] <= current_time && remaining_time[i] > 0) {
                int execute_time = (remaining_time[i] > TIME_QUANTUM) ? TIME_QUANTUM : remaining_time[i];
                current_time += execute_time;
                remaining_time[i] -= execute_time;

                if (remaining_time[i] == 0) {
                    completion_time[i] = current_time;
                    completed_processes++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        turnaround_times[i] = completion_time[i] - arrival_times[i];
        waiting_times[i] = turnaround_times[i] - burst_times[i];
    }

    double avg_turnaround_time = 0, avg_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        avg_turnaround_time += turnaround_times[i];
        avg_waiting_time += waiting_times[i];
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    printf("Process\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i], turnaround_times[i], waiting_times[i]);
    }
    printf("\nAverage Turnaround Time: %.2lf\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2lf\n", avg_waiting_time);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int burst_times[] = {4,7,2,2};
    int arrival_times[] = {0,2,3,3};
    int n = sizeof(processes) / sizeof(processes[0]);

    roundRobinScheduling(processes, burst_times, arrival_times, n);

    return 0;
}