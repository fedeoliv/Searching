#include <stdio.h>
#include <climits>
#include <cstdlib>

/*  Given a sorted array and a number x, find a pair in array whose sum is closest to x.
    Input: arr[] = {10, 22, 28, 29, 30, 40}, x = 54
    Output: 22 and 30 */

void printClosest(int arr[], int n, int x) {
    int res_l, res_r;
    int l = 0, r = n-1, diff = INT_MAX;

    while (r > l) {
       /* Check if this pair is closer than the closest pair so far */
       if(abs(arr[l] + arr[r] - x) < diff) {
           res_l = l;
           res_r = r;
           diff = abs(arr[l] + arr[r] - x);
       }

       /* If this pair has more sum, move to smaller values. */
       if(arr[l] + arr[r] > x) r--;
       else l++;
    }
    printf("%d %d\n", arr[res_l], arr[res_r]);
}

int main() {
    int arr[] =  {10, 22, 28, 29, 30, 40}, x = 54;
    int n = sizeof(arr)/sizeof(arr[0]);
    printClosest(arr, n, x);
    return 0;
}
