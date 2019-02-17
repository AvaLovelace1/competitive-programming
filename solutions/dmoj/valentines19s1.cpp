/*
 Solution to Valentine's Day '19 S1 - Voting by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const int MAX = 10005;

int N, M;
string names[25];
map<string, int> mp;
vi arr[MAX];
int cnt[MAX];
int nVotes[25];
bool out[25];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    string str;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        names[i] = str;
        mp[str] = i;
    }
    
    for (int i = 1; i <= M; i++) {
        int n;
        cin >> n;
        while (n--) {
            cin >> str;
            arr[i].pb(mp[str]);
        }
    }
    
    for (int t = 1; t < N; t++) {
        FILL(nVotes, 0);
        for (int i = 1; i <= M; i++) {
            if (cnt[i] < arr[i].size()) {
                nVotes[arr[i][cnt[i]]]++;
            }
        }
        int lowest = INF;
        int elim = 0;
        for (int i = 1; i <= N; i++) {
            if (!out[i]) {
                if (nVotes[i] < lowest) {
                    lowest = nVotes[i];
                    elim = i;
                }
            }
        }
        out[elim] = 1;
        for (int i = 1; i <= M; i++) {
            while (cnt[i] < arr[i].size() && out[arr[i][cnt[i]]]) {
                cnt[i]++;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!out[i]) {
            cout << names[i] << '\n';
        }
    }
    return 0;
}
