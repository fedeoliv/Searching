#include <stdio.h>
#include <climits>
#include <cstdlib>
using namespace std;

/*  Given two sorted arrays and a number x, find the pair whose sum is closest to x
    and the pair has an element from each array.

    Input:  ar1[] = {1, 4, 5, 7}, ar2[] = {10, 20, 30, 40};
            x = 32
    Output:  1 and 30. */

void printClosest(int ar1[], int ar2[], int m, int n, int x) {
    int diff = INT_MAX;
    int res_l, res_r;
    int l = 0, r = n-1;

    while(l < m && r >= 0) {
        /*  If this pair is closer to x than the previously
            found closest, then update res_l, res_r and diff */
       if(abs(ar1[l] + ar2[r] - x) < diff) {
           res_l = l;
           res_r = r;
           diff = abs(ar1[l] + ar2[r] - x);
       }

       /*   If sum of this pair is more than x, move to smaller side */
       if(ar1[l] + ar2[r] > x) r--;
       else l++;
    }

    printf("%d %d\n", ar1[res_l], ar2[res_r]);
}

int main() {
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    int x = 50;
    printClosest(ar1, ar2, m, n, x);
    return 0;
}
