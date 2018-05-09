#include <stdio.h>
#include <string.h>

#define MAX_ACTIVITY 1000

struct activity {
    int number[MAX_ACTIVITY];
    int start[MAX_ACTIVITY];
    int finish[MAX_ACTIVITY];
    int value[MAX_ACTIVITY];
};

struct activity_result {
    int max;
    int number[MAX_ACTIVITY];
    int size;
};

int find_max(int a, int b) {
    return (a > b) ? a : b;
}

int reverse() {

}

struct activity_result find_activity(struct activity acty, int n) {
    // to do: sort by finish time
    
    struct activity_result result;
    int max = 0;
    int max_index = 0;

    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = acty.value[i];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (acty.start[i] >= acty.finish[j]) {
                temp[i] = find_max(temp[i], temp[j] + acty.value[i]);
                if (temp[i] > max) {
                    max = temp[i];
                    max_index = i;
                }
            }
        }
    }
    result.max = max;    

    int index = MAX_ACTIVITY - 1;
    int size = 0;
    for (int i = max_index; i >= 0 ; i--) {
        if (temp[i] == max) {
            max -= acty.value[i];
            result.number[index] = acty.number[i];
            index--;
            size++;
        }
    }
    
    result.size = size;
    return result;
}

int main() {
    struct activity acty;
    acty.number[0] = 1;
    acty.number[1] = 2;
    acty.number[2] = 3;

    acty.start[0] = 0;
    acty.start[1] = 3;
    acty.start[2] = 3;

    acty.finish[0] = 3;
    acty.finish[1] = 4;
    acty.finish[2] = 5;

    acty.value[0] = 4;
    acty.value[1] = 1;
    acty.value[2] = 2;    

    struct activity_result result = find_activity(acty, 3);
    printf("%d\n", result.max);
    for (int i = MAX_ACTIVITY - result.size; i < MAX_ACTIVITY; i++) {
        printf("%d ", result.number[i]);
    }
    printf("\n");
}
