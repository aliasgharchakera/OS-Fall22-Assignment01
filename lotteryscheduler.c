#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ProcessDetails{
    int ticket, arr_time, duration;
    int process;
    int priority;
}ProcessDetails;

void swap(struct ProcessDetails* xp, struct ProcessDetails* yp)
{
    struct ProcessDetails temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// Function to perform Selection Sort
void selectionSort(struct ProcessDetails* arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
         min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j]->arr_time < arr[min_idx]->arr_time)
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
     
    int n; scanf("%d\n", &n);
    int process_completed = 0;
    struct ProcessDetails *p[n];
    for(int i = 0; i < n; i++){
        char priority[10];
        struct ProcessDetails *tmp = malloc(sizeof(struct ProcessDetails));
        scanf("P%d:%d:%d:%s\n", &tmp->process, &tmp->arr_time, &tmp->duration, priority);
        // printf("%d == %d == %d == %c", tmp->process, tmp->arr_time, tmp->duration, priority[0]);
        
        if (priority[0] == 'l')
            tmp->priority = 1;
        else if (priority[0] == 'n')
            tmp->priority = 2;
        else
            tmp->priority = 3;
        p[i] = tmp;
    }
    selectionSort(p, n);
    int timestamp = 1;
    struct ProcessDetails *queue[n];
    // int queue[n];
    int queue2 [n];
    int tickets[n*3];
    
    srand(1);
    while (process_completed < n) {
        int index = 0;
        for (int i = 0; i < n; i++) {
        if ((p[i]->arr_time <= timestamp) && (p[i]->duration > 0)) {
            queue[index] = p[i];
            index++;
            }
        }
        int counter = 0;
        int total_tickets = 0;
        for(int i = 0; i < index; i++){
            for(int j = 0; j < queue[i]->priority; j++){
                    tickets[total_tickets] = queue[i]->process;
                    total_tickets++;
            }
        }
        if (total_tickets > 0) {
            
            int winner = rand() % total_tickets;
            for (int i = 0; i < n; i++) {
                if (tickets[winner] == p[i]->process) {
                    p[i]->duration--;
                    printf("%d:P%d:", timestamp, p[i]->process);
                    if (p[i]->duration == 0) {
                        process_completed++;
                    }
                }
            }
            bool next = false;
            for (int i = 0; i < index; i++) {
                if (tickets[winner] != queue[i]->process){
                    printf("P%d,", queue[i]->process);
                    next = true;
                }
            }
            if(!next){
                printf("empty");
            }
            printf("\n");
        }
        else{
            printf("%d:idle:empty\n", timestamp);
        }
        timestamp++;
    }
    return 0;
}