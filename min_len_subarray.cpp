#include<stdio.h>

/*  Given an unsorted array, find the minimum length subarray such that
    sorting this subarray makes the whole array sorted.

    1)  Input: [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60]
        Output: Indexes 3 and 8.*/

void find_end(int *arr, int n, int *i, int *big, int *end) {
    if(*i >= n-1) return;

    int temp_i = *i, temp_big = *big;
    temp_i++;

    while(temp_i < n && arr[temp_big] > arr[temp_i]) {
        *end = temp_i;
        temp_i++;
    }

    temp_big = temp_i;
    *big = temp_big;
    *i = temp_i;
    find_end(arr, n, i, big, end);
}

int find_start(int *arr, int n, int *big, int *till_now) {
    int i, j, large;
    large = *big;

    for(i = 1; i < n; i++) {
        if(arr[large] <arr[i]) large=i;
        if(arr[i] < arr[i-1]) break;
    }

    if(i == n) return i;

    j = i;
    for(i = j-2; i >=0; i--)
        if(arr[i] < arr[j]) break;

    *till_now = j;
    *big = large;
    return i+1;
}

void find_min(int *arr, int n) {
    int start, end, big, till_now;
    till_now = 0; big = 0; end = 0;
    start = find_start(arr, n, &big, &till_now);

    if(start == n) printf("Array is already sorted\n");
    else {
        end = n-1;
        find_end(arr, n, &till_now, &big, &end);
        printf("%d %d", start, end);
    }
}

int main() {
    int arr[]={10,12,20,30,25,40,32,31,35,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    find_min(arr, n);
    return 0;
}
