/*
 Solution to CCC '16 S1 - Ragaman by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

string A, B;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B;
    
    for (char c : A) {
        auto itr = B.find(c);
        if (itr == string::npos) {
            itr = B.find('*');
            if (itr == string::npos) {
                cout << 'N';
                return 0;
            }
        }
        B.erase(itr, 1);
    }
    
    cout << 'A';
    
    return 0;
}
