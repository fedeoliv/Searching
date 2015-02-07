#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
    while(l <= r) {
        int m = l + (r-l)/2;
        if(arr[m] == x) return m;
        if(arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
   int arr[] = {2, 3, 10, 7, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;

   printf("%d\n", binarySearch(arr, 0, n-1, x));
   return 0;
}
