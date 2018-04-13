/*
 Solution to ECOO '13 R2 P1 - Upsetris by Ava Pun
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
const int MAX = 1e6 + 5;

int N;
string arr[25];
int num[25];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for (int test = 1; test <= 5; test++) {
        
        FILL(num, 0);
        string str;
        int cnt = 0;
        do {
            getline(cin, str);
            arr[cnt++] = str;
        } while (str[1] != '=');
        
        for (int i = (int) arr[0].length() - 1; i >= 0; i--) {
            if (arr[0][i] == '|') {
                N = i + 1;
                break;
            }
        }
        
        for (int i = 0; i < cnt - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                if (arr[i][j] == 'O') {
                    num[j]++;
                }
            }
        }

        bool found = false;
        while (!found) {
            for (int j = 1; j < N - 1; j++) {
                if (!num[j]) {
                    found = true;
                }
            }
            if (!found) {
                for (int j = 1; j < N - 1; j++) {
                    num[j]--;
                }
            }
        }
        
        for (int i = 0; i < cnt - 1; i++) {
            cout << '|';
            for (int j = (int) N - 2; j >= 1; j--) {
                if (i > cnt - num[j] - 2) {
                    cout << 'O';
                } else {
                    cout << ' ';
                }
            }
            cout << '|' << "\n";
        }
        
        cout << '|';
        for (int j = 1; j < N - 1; j++) {
            cout << '=';
        }
        cout << '|' << "\n";
        
    }
    
    return 0;
}
