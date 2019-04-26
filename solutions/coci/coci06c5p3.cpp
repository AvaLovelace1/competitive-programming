/*
 Solution to COCI '06 Contest 5 #3 Tenis by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 105;

int N;
string S;
string players[2];
vector<string> win, lose, lastSet;
unordered_map<string, int> mp; // 0 - lost all, 2 - won all

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i <= 4; i++) {
        win.pb("6:" + to_string(i));
        lose.pb(to_string(i) + ":6");
    }
    win.pb("7:5");
    lose.pb("5:7");
    for (string str : win) {
        lastSet.pb(str);
    }
    for (string str : lose) {
        lastSet.pb(str);
    }
    for (int i = 8; i <= 99; i++) {
        lastSet.pb(to_string(i) + ":" + to_string(i - 2));
        lastSet.pb(to_string(i - 2) + ":" + to_string(i));
    }
    win.pb("7:6");
    lose.pb("6:7");

    for (string a : win) {
        for (string b : win) {
            mp[a + " " + b] = 2;
        }
    }
    for (string a : lose) {
        for (string b : lose) {
            mp[a + " " + b] = 0;
        }   
    }
    for (string a : win) {
        for (string b : lose) {
            for (string c : lastSet) {
                mp[a + " " + b + " " + c] = 1;
                mp[b + " " + a + " " + c] = 1;
            }
        }
    }

    cin >> players[0] >> players[1] >> N;
    getline(cin, S);
    for (int i = 1; i <= N; i++) {
        getline(cin, S);
        if (mp.find(S) == mp.end()) {
            cout << "ne\n";
        } else if (players[0] == "federer") {
            cout << (mp[S] == 2 ? "da\n" : "ne\n");
        } else if (players[1] == "federer") {
            cout << (mp[S] == 0 ? "da\n" : "ne\n");
        } else {
            cout << "da\n";
        }
    }
    
    return 0;
}
