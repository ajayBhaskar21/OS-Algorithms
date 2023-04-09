#include <stdio.h>

void sortBasedonAT(int PID[], int BT[], int AT[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (AT[i] > AT[j]) {
                int t1 = AT[i];
                AT[i] = AT[j];
                AT[j] = t1;

                t1 = BT[i];
                BT[i] = BT[j];
                BT[j] = t1;

                t1 = PID[i];
                PID[i] = PID[j];
                PID[j] = t1;
            }
        }
    }
}

int sjfBT(int readyQueue[], int BT[], int n) {
    int m = 9999;
    for (int i = 0; i < n; i++) {
        if (readyQueue[i] != -1) {
            if (m > BT[i]) {
                m = BT[i];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (BT[i] == m) {
            readyQueue[i] = -1;
            return i;
        }
    }
}

int main() {
    int n = 5;
    int PID[5] = {1, 2, 3, 4, 5};
    int AT[5] = {1, 3, 6, 7, 9};
    int BT[5] = {7, 3, 2, 10, 8};
    
    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    int PID[n];
    int AT[n];
    int BT[n];
    int TAT[n];
    int WT[n];
    int readyQueue[n];
    int exec[n];
    int end = 0;
    for (int i = 0; i < n; i++){
        PID[i] = i;
        printf("enter AT for process - %d : ", i);
        scanf("%d", &AT[i]);
        printf("enter BT for process - %d : ", i);
        scanf("%d", &BT[i]);
        readyQueue[i] = -1;
        exec[i] = 0;
    }
    
    
    
    sortBasedonAT(PID, BT, AT, n);
    
    int CT[5] = {0};
    int m = AT[0];
    

    // Completion time for first process
    for (int i = 0; i < n; i++) {
        if (AT[i] == m && exec[i] == 0) {
            readyQueue[i] = AT[i];
        }
    }
    int minIndex = sjfBT(readyQueue, BT, n);
    CT[minIndex] = AT[minIndex] + BT[minIndex];
    end = CT[minIndex];
    printf("readyqueue = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", readyQueue[i]);
    }
    printf("\nCT = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", CT[i]);
    }
    printf("\n");
    exec[minIndex] = 1;

    // Completion time for remaining processes
    for (int j = 0; j < n-1; j++) {
        for (int i = 0; i < n; i++) {
            if (AT[i] <= end && exec[i] == 0) {
                readyQueue[i] = AT[i];
            }
        }
        printf("readyqueue = ");
        for (int i = 0; i < n; i++) {
            printf("%d ", readyQueue[i]);
        }
        printf("\n");
        minIndex = sjfBT(readyQueue, BT, n);
        CT[minIndex] = end + BT[minIndex];
        end = CT[minIndex];
        printf("readyqueue = ");
        for (int i = 0; i < n; i++) {
            printf("%d ", readyQueue[i]);
        }
        printf("\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", CT[i]);
        }
        printf("\n");
        exec[minIndex] = 1;
    }
    for(int i = 0; i < n; i++){
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",PID[i],AT[i], BT[i], CT[i], TAT[i], WT[i]);
        
    
}
