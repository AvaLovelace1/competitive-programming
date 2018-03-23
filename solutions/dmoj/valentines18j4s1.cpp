/*
 Solution to Valentine's Day '18 J4 & S1 - Carol's Cute Cactus by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e4 + 5;

int N, M;

int toPalin(int n, string mid) {
    if (n == 0) {
        if (mid == "") {
            return 0;
        }
        return stoi(mid);
    }
    string s = to_string(n);
    reverse(s.begin(), s.end());
    s = to_string(n) + mid + s;
    if (s.length() > 9) {
        return 0;
    }
    return stoi(s);
}

bool valid(int n, string mid) {
    string s = to_string(toPalin(n, mid));
    if (stoi(s) < N || stoi(s) > M) {
        return false;
    }
    return true;
}

int main() {
    
    scanf("%d%d", &N, &M);
    
    int len1 = (int) to_string(N).length(), len2 = (int) to_string(M).length();
    int bestN = 0, bestDiff = 0;
    for (int i = pow(10, len1 / 2 - 1); i <= pow(10, len2 / 2); i++) {
        int p;
        if (valid(i, "")) {
            p = toPalin(i, "");
            int diff = min(p - N, M - p);
            if (diff >= bestDiff) {
                bestDiff = diff;
                bestN = p;
            }
        }
        for (int j = 0; j <= 9; j++) {
            if (valid(i, to_string(j))) {
                p = toPalin(i, to_string(j));
                int diff = min(p - N, M - p);
                if (diff >= bestDiff) {
                    bestDiff = diff;
                    bestN = p;
                }
            }
        }
    }
    
    printf("%d", bestN);
    
    return 0;
}
