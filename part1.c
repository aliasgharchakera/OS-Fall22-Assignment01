#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ProcessDetails{
    int ticket, arr_time, duration;
    int process;
    int priority;
}ProcessDetails;

void swap(struct ProcessDetails xp, struct ProcessDetails yp)
{
    struct ProcessDetails temp = xp;
    xp = yp;
    yp = temp;
}
 
// Function to perform Selection Sort
void selectionSort(struct ProcessDetails arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
         min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j].arr_time < arr[min_idx].arr_time)
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
     
    int n; scanf("%d\n", &n);
    struct ProcessDetails *p = malloc(n*sizeof(ProcessDetails));
    // typedef struct ProcessDetails [n];
    for(int i = 0; i < n; i++){
        char priority[10];
        // struct ProcessDetails *tmp = malloc(sizeof(struct ProcessDetails));
        struct ProcessDetails tmp;
        scanf("P%d:%d:%d:%s\n", &tmp.process, &tmp.arr_time, &tmp.duration, priority);
        // printf("%d == %d == %d == %c", tmp->process, tmp->arr_time, tmp->duration, priority[0]);
        
        if (priority[0] == 'l')
            tmp.priority = 1;
        else if (priority[0] == 'n')
            tmp.priority = 2;
        else
            tmp.priority = 3;
        p[i] = tmp;
    }
    selectionSort(p, n);
    int timestamp = 0;
    struct ProcessDetails *queue[n];
    // int queue[n];
    int queue2 [n];
    
    bool done = false;
    while (!done) {
        int index = 0;
      for (int i = 0; i < n; i++) {
        if ((p[i].arr_time <= timestamp) && (p[i].duration > 0)) {
        //   queue[index] = p[i];
          queue2[index] = i;
          index++;
        }
      }
      int counter = 0;
      int tickets[n*3];
      int total_tickets = 0;
      for (int i = 0; i < index; i++) {
        // ProcessDetails pos = *(p[queue2[i]]);
        for (int j = 0; i < p[queue2[i]].priority; j++) {
          tickets[total_tickets] = p[queue2[i]].process;
          total_tickets++;
        }
      }
    //   return 0;
      if (total_tickets > 0) {
        srand(1);
        int winner = rand() % total_tickets;
        for (int i = 0; i < index; i++) {
            // ProcessDetails *pos = p[queue2[i]];
          if (tickets[winner] == p[queue2[i]].process) {
            p[queue2[i]].duration--;
            if(p[queue2[i]].duration == 0)
                process_completed++;
          }
        //   return 0;
        }
        for (int i = 0; i < index; i++) {
            // ProcessDetails pos = *(p[queue2[i]]);
          if (tickets[winner] != p[queue2[i]].process)
            printf("P%d,", p[queue2[i]].process);
        }
        printf("\n");
      }
      if (timestamp == 5)
        break;
      timestamp++;
    }
    return 0;
}