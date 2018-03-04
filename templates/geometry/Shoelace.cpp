/*
 ~ Shoelace Formula ~
 
 Finds the area of a polygon, given its vertices.
 
 Time complexity: O(N)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N;
pii arr[MAX];

double area() {
    double ans = 0;
    for (int i = 0; i < N; i++) {
        ans += arr[i].first * arr[(i + 1) % N].second;
    }
    for (int i = 0; i < N; i++) {
        ans -= arr[(i + 1) % N].first * arr[i].second;
    }
    ans /= 2;
    return ans;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    printf("Area of polygon: %lf\n", area());
    
    return 0;
    
}
