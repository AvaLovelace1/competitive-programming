/*
 ~ Binary Search ~
 
 Awesome technique that can be used in many applications, not always obvious ones.
 Can be used whenever the search space is monotonically increasing or monotonically decreasing.
 Use if you can verify that an answer is possible quickly.
 Ternary search is used when the range is monotonically increasing then decreasing or decreasing then increasing.
 
 Time complexity: O(logN*F)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e3 + 5;

const int N = INF;
int A, B, C, X;

ll func(int x) {
    return (ll) abs(A) * x + B;
}

double func1(double x) {
    return -abs(A) * x * x + B * x + C;
}

int binSearch(int x) {
    int start = 0, end = N, mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (func(mid) >= x) { //change to > for upper bound
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

double terSearch() {
    double start = 0, end = N, mid1, mid2;
    for (int i = 0; i < 200; i++) {
        mid1 = (start * 2 + end) / 3;
        mid2 = (start + 2 * end) / 3;
        if (func1(mid1) >= func1(mid2)) {
            end = mid2;
        } else {
            start = mid1;
        }
    }
    return start;
}

int main() {
    
    scanf("%d%d%d%d", &A, &B, &C, &X);
    printf("Point at which line y = %dx + %d becomes greater than or equal to %d: %d\n", abs(A), B, X, binSearch(X));
    printf("Point at which parabola y = %dx^2 + %dx + %d is maximized: %lf\n", -abs(A), B, C, terSearch());
    
    return 0;
    
}
