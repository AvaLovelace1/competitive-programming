/*
 Solution to ECOO '13 R2 P2 - The Walking Dead by Ava Pun
 Key concepts: geometry
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1005;

double X, Y, R;
int T, N;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}

int main() {
    
    for (int test = 1; test <= 10; test++) {
        
        scanf("%lf%lf%lf", &X, &Y, &R);
        scanf("%d%d", &T, &N);
        
        double x, y, cx, cy, spd;
        int ans = 0;
        
        for (int i = 1; i <= N; i++) {
            
            scanf("%lf%lf%lf%lf%lf", &x, &y, &cx, &cy, &spd);
            double xx = x - cx, yy = y - cy;
            double r = dist(x, y, cx, cy);
            double d = -spd * T / r;
            double theta = atan(yy / xx);
            
            if (xx < 0) {
                theta += M_PI;
            } else if (yy < 0) {
                theta += 2 * M_PI;
            }
            theta += d;
            
            xx = r * cos(theta) + cx;
            yy = r * sin(theta) + cy;
            if (dist(xx, yy, X, Y) <= R) {
                ans++;
            }
            
        }
        
        printf("%d\n", ans);
        
    }
    
    return 0;
}
