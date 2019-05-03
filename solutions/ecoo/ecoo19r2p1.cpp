/*
 Solution to ECOO '19 R2 P1 - Email by Ava Pun
 Key concepts: implementation, set
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;
string arr[MAX];
unordered_set<string> ss;

inline string process(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    int idxAt = (int) str.find('@');
    int idxPlus = (int) str.find('+');
    if (idxPlus == string::npos) {
        idxPlus = INF;
    }
    string beg = "";
    for (int i = 0; i < min(idxAt, idxPlus); i++) {
        if (str[i] != '.') {
            beg += str[i];
        }
    }
    return beg + str.substr(idxAt, string::npos);
}

int main() {
    
    for (int test = 1; test <= 10; test++) {
        cin >> N;
        ss.clear();
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            ss.insert(process(arr[i]));
        }
        cout << ss.size() << '\n';
    }
    
    return 0;
}
