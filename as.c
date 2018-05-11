#include <stdio.h>
#include <stdlib.h>

#define MAX_ACTIVITY 1000
#define ACTIVITY_STRUCT_NUM 4

struct activity {
    int number;
    int start_time;
    int finish_time;
    int value;
};

struct activity_blob {
    struct activity list[MAX_ACTIVITY];
    int size;
};

struct activity_result {
    int max_value;
    int numbers[MAX_ACTIVITY];
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
    return (acty_a->finish_time - acty_b->finish_time);
}

struct activity_result find_activity(struct activity list[], int size) {
    
    qsort(list, size, sizeof(struct activity), activity_compare);

    struct activity_result result;
    int max_value = list[0].value;
    int max_index = 0;

    int temp[size];
    for (int i = 0; i < size; i++) {
        temp[i] = list[i].value;
    }
    
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (list[i].start_time >= list[j].finish_time) {
                temp[i] = find_max(temp[i], temp[j] + list[i].value);
            }
            if (temp[i] > max_value) {
                max_value = temp[i];
                max_index = i;
            }
        }
    }
    result.max_value = max_value;
    
    int count = 0;
    int temp_index = max_index;
    for (int i = max_index; i >= 0 ; i--) {
        if (temp[i] == max_value) {
            if (i == max_index || list[i].finish_time <= list[temp_index].start_time) {
                max_value -= list[i].value;                
                result.numbers[count] = list[i].number;
                count++;
                temp_index = i;
            }     
        }
    }

    qsort(result.numbers, count, sizeof(int), compare);
    
    result.size = count;
    return result;
}

int main() {

    int input_num;
    scanf("%i", &input_num);

    struct activity_blob blob[input_num];
    for (int i = 0; i < input_num; i++) {
        int activity_num;
        scanf("%i", &activity_num);
        for (int j = 0; j < activity_num; j++) {
            int activity_property[ACTIVITY_STRUCT_NUM];
            for(int k = 0; k < ACTIVITY_STRUCT_NUM; k++) {
                scanf("%d", &activity_property[k]);
            }

            blob[i].list[j].number = activity_property[0];
            blob[i].list[j].start_time = activity_property[1];
            blob[i].list[j].finish_time = activity_property[2];
            blob[i].list[j].value = activity_property[3];              
        }
        blob[i].size = activity_num;
    }

    for (int i = 0; i < input_num; i++) {
        struct activity_result result = find_activity(blob[i].list, blob[i].size);
        printf("%d\n", result.max_value);
        for (int i = 0; i < result.size; i++) {
            printf("%d", result.numbers[i]);
            if (i < result.size - 1)
            printf(" ");
        }
        printf("\n");
    }
}
