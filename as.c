#include <stdio.h>
#include <stdlib.h>

#define MAX_ACTIVITY 1000

struct activity {
    int number;
    int start;
    int finish;
    int value;
};

struct activity_result {
    int max;
    int number[MAX_ACTIVITY];
    int size;
};

int find_max(int a, int b) {
    return (a > b) ? a : b;
}

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *)b;
}

int activity_compare(const void *a, const void *b) {
    struct activity *acty_a = (struct activity *)a;
    struct activity *acty_b = (struct activity *)b;
    return (acty_a->finish - acty_b->finish);
}

struct activity_result find_activity(struct activity acty[], int n) {
    
    qsort(acty, n, sizeof(struct activity), activity_compare);

    struct activity_result result;
    int max = 0;
    int max_index = 0;

    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = acty[i].value;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (acty[i].start >= acty[j].finish) {
                temp[i] = find_max(temp[i], temp[j] + acty[i].value);
                if (temp[i] > max) {
                    max = temp[i];
                    max_index = i;
                }
            }
        }
    }
    result.max = max;    

    int count = 0;
    for (int i = max_index; i >= 0 ; i--) {
        if (temp[i] == max) {
            max -= acty[i].value;
            result.number[count] = acty[i].number;
            count++;
        }
    }

    qsort(result.number, count, sizeof(int), compare);
    
    result.size = count;
    return result;
}
int main() {
    struct activity acty[] = {
        {1,8,21,19}, {2,10,15,12}, {3,4,9,18}, {4,20,30,25}, {5,0,5,15} 
    };
    struct activity_result result = find_activity(acty, 5);
    printf("%d\n", result.max);
    for (int i = 0; i < result.size; i++) {
        printf("%d ", result.number[i]);
    }
    printf("\n"); 
}
