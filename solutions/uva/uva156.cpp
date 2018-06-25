/*
 Solution to 156 - Ananagrams by Ava Pun
 Key concepts: implementation
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

string arr[MAX], arr1[MAX];
map<string, int> mp;
vector<string> ans;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int idx = 0;
    string S;
    cin >> S;
    while (S != "#") {
        arr[idx] = S;
        idx++;
        cin >> S;
    }
    
    for (int i = 0; i < idx; i++) {
        string S1 = arr[i];
        for (char &c : S1) {
            c = toupper(c);
        }
        sort(S1.begin(), S1.end());
        arr1[i] = S1;
        mp[S1]++;
    }
    
    for (int i = 0; i < idx; i++) {
        if (mp[arr1[i]] < 2) {
            ans.pb(arr[i]);
        }
    }
    
    sort(ans.begin(), ans.end());
    for (string s : ans) {
        cout << s << "\n";
    }
    
    return 0;
}
