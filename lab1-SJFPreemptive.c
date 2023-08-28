#include <stdio.h>
#include<limits.h>
#define MAX_PROCESSES 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortProcessesByArrival(int processes[], int burst_times[], int arrival_times[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrival_times[j] > arrival_times[j + 1]) {
                swap(&arrival_times[j], &arrival_times[j + 1]);
                swap(&processes[j], &processes[j + 1]);
                swap(&burst_times[j], &burst_times[j + 1]);
            }
        }
    }
}

void preemptiveSJFScheduling(int processes[], int burst_times[], int arrival_times[], int n) {
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
        int shortest_remaining_time = INT_MAX;
        int selected_process = -1;

        for (int i = 0; i < n; i++) {
            if (arrival_times[i] <= current_time && remaining_time[i] > 0 && remaining_time[i] < shortest_remaining_time) {
                shortest_remaining_time = remaining_time[i];
                selected_process = i;
            }
        }

        if (selected_process == -1) {
            current_time++;
            continue;
        }

        remaining_time[selected_process]--;
        current_time++;

        if (remaining_time[selected_process] == 0) {
            completion_time[selected_process] = current_time;
            completed_processes++;
        }
    }

    for (int i = 0; i < n; i++) {
        turnaround_times[i] = completion_time[i] - arrival_times[i];
        waiting_times[i] = turnaround_times[i] - burst_times[i];
    }

    printf("Process\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], completion_time[i], turnaround_times[i], waiting_times[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[MAX_PROCESSES];
    int burst_times[MAX_PROCESSES];
    int arrival_times[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrival_times[i], &burst_times[i]);
        processes[i] = i + 1;
    }

    sortProcessesByArrival(processes, burst_times, arrival_times, n);
    preemptiveSJFScheduling(processes, burst_times, arrival_times, n);

    return 0;
}