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
    // typedef struct ProcessDetails [n];
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
    int timestamp = 0;
    struct ProcessDetails *queue[n];
    // int queue[n];
    int queue2 [n];
    int tickets[n*3];
    
    while (process_completed < n) {
        int index = 0;
      for (int i = 0; i < n; i++) {
        if ((p[i]->arr_time == timestamp) && (p[i]->duration > 0)) {
        //   queue[index] = p[i];
          queue2[index] = i;
          index++;
        }
      }
      int counter = 0;
      int total_tickets = 0;
      // for(int i = 0; i < index; i++){
      //     for(int j = 0; j < queue[i]->priority; j++){
      //         // printf("i=%d, total tickets=%d\n", i, total_tickets);
      //         if((p[i]->duration != 0) && ((queue[i]->process != -1))){
      //             tickets[total_tickets] = queue[i]->process;
      //             total_tickets++;
      //         }
      //     }
      // }
      for (int i = 0; i < index; i++) {
        ProcessDetails pos = *(p[queue2[i]]);
        for (int j = 0; i < pos.priority; j++) {
          tickets[total_tickets] = pos.process;
          total_tickets++;
        }
      }
      if (total_tickets > 0) {
        srand(1);
        int winner = rand() % total_tickets;
        for (int i = 0; i < index; i++) {
            ProcessDetails *pos = p[queue2[i]];
          if (tickets[winner] == pos->process) {
            pos->duration--;
            if(pos->duration == 0)
                process_completed++;
          }
        }
        for (int i = 0; i < index; i++) {
            ProcessDetails pos = *(p[queue2[i]]);
          if (tickets[winner] != pos.process)
            printf("P%d,", pos.process);
        }
        printf("\n");
      }
    //   if (total_tickets > 0) {
    //     srand(1);
    //     int winner = rand() % total_tickets;
    //     int lottery_winner;
    //     for (int i = 0; i < index; i++) {
    //       if (tickets[winner] == queue[i]->process) {
    //         queue[i]->duration--;
    //         printf("%d:P%d:", timestamp, p[i]->process);
    //         if (queue[i]->duration == 0) {
    //           for (int i = 0; i < n; i++) {
    //             if (queue[i]->process == p[i]->process)
    //               p[i]->process = -1;
    //           }
    //         }
    //         // queue[i]->process = -1;
    //       }
    //     }
    //     for (int i = 0; i < index; i++) {
    //       if (tickets[winner] != queue[i]->process)
    //         printf("P%d,", queue[i]->process);
    //     }
    //     printf("\n");
    //   }
      if (timestamp == 5)
        break;
      timestamp++;
    }
    return 0;
}