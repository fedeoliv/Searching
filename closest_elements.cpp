#include <stdio.h>

/*  Given a sorted array and a value X, find the k closest elements to X in array.

    Input:  K = 4, X = 35
            arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56}
    Output: 30 39 42 45 */

int binarySearch(int arr[], int l, int r, int x) {
    while(l <= r) {
        int m = l + (r-l)/2;
        if(arr[m] == x) return m;
        if(arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

void printClosestNums(int arr[], int n, int num, int k) {
    int index = binarySearch(arr, 0, n-1, num);

    if(index == -1) {
        printf("Not found\n");
        return;
    }

    int low = index-1;
    int high = index+1;
    int diff1, diff2;

    while(k-- && low >= 0 && high < n) {
        diff1 = arr[high] - arr[index];
        diff2 = arr[index] - arr[low];

        if(diff1 <= diff2) high++;
        else low--;
    }

    while(k >= 0 && low >= 0) {
        low--;
        k--;
    }

    while(k >= 0 && high < n) {
        high++;
        k--;
    }

    for(int i = low+1; i < high; i++)
        if(i != index) printf("%d ", arr[i]);
}

int main() {
   int arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int num = 35;
   int k = 4;
   printClosestNums(arr, n, num, k);
   return 0;
}
