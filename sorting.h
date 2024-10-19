#include <stdio.h>

struct Date {
    int hour;
    int date;
    int month;
    int si;// si=i+1    //i
};

void swap(struct Date *a, struct Date *b) {
    struct Date temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Date arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].month > arr[j + 1].month || 
                (arr[j].month == arr[j + 1].month && arr[j].date > arr[j + 1].date) ||
                (arr[j].month == arr[j + 1].month && arr[j].date == arr[j + 1].date && arr[j].hour > arr[j + 1].hour)) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


