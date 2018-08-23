/*
 Solution to IOI '14 P4 - Gondola by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 9;
const int MAX = 1e5 + 5;

int T, N;
int arr[MAX], rep[MAX], seq[MAX];
map<int, int> mp;

int valid(int n, int inputSeq[]) {
    
    mp.clear();
    int j = -1;
    for (int i = 0; i < n; i++) {
        mp[inputSeq[i]]++;
        if (mp[inputSeq[i]] > 1) {
            return 0;
        }
        if (inputSeq[i] <= n && j == -1) {
            j = i;
        }
    }
    
    int curr = inputSeq[j];
    for (int i = 0; i < n; i++) {
        if (inputSeq[(i + j) % n] <= n && inputSeq[(i + j) % n] != curr) {
            return 0;
        }
        curr %= n;
        curr++;
    }
    return 1;
}

int replacement(int n, int gondolaSeq[], int replacementSeq[]) {
    
    mp.clear();
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (gondolaSeq[i] <= n) {
            if (j == -1) {
                j = i;
            }
        } else {
            mp[gondolaSeq[i]] = i;
        }
    }
    int curr;
    if (j == -1) {
        j = 0;
        curr = 1;
    } else {
        curr = gondolaSeq[j];
    }
    for (int i = 0; i < n; i++) {
        seq[(i + j) % n] = curr;
        curr %= n;
        curr++;
    }
    
    int cnt = 0, pre = n + 1;
    for (pii p : mp) {
        int k = p.f, i = p.s, a = seq[i];
        replacementSeq[cnt++] = a;
        for (int i = pre; i < k; i++) {
            replacementSeq[cnt++] = i;
        }
        pre = k + 1;
    }
    return cnt;
}

ll modPow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else {
        ll ans = modPow(a * a % MOD, b / 2);
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        return ans;
    }
}

int countReplacement(int n, int inputSeq[]) {
    
    if (!valid(n, inputSeq)) {
        return 0;
    }
    mp.clear();
    for (int i = 0; i < n; i++) {
        if (inputSeq[i] > n) {
            mp[inputSeq[i]] = i;
        }
    }
    
    ll ans = 1;
    int pre = n + 1, cnt = 0;
    for (pii p : mp) {
        int k = p.f;
        ans *= modPow((int) mp.size() - cnt, k - pre);
        ans %= MOD;
        pre = k + 1;
        cnt++;
    }
    if (mp.size() == n) {
        ans *= n;
        ans %= MOD;
    }
    return (int) ans;
}

int main() {
    
    scanf("%d%d", &T, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    if (T >= 1 && T <= 3) {
        printf("%d\n", valid(N, arr));
    } else if (T >= 4 && T <= 6) {
        int k = replacement(N, arr, rep);
        printf("%d ", k);
        for (int i = 0; i < k; i++) {
            printf("%d ", rep[i]);
        }
        printf("\n");
    } else {
        printf("%d\n", countReplacement(N, arr));
    }
    
    return 0;
}
