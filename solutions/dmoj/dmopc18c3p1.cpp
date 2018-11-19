/*
 Solution to DMOPC '18 Contest 3 P1 - Bob and Music Class by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

const string NOTES[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
const string TYPES[2][2] = { { "diminished", "minor" }, { "major", "augmented" } };
int triad[3];

inline int getVal(string str) {
    return (int) (find(NOTES, NOTES + 12, str) - NOTES); 
}

int main() {

    string note;
    for (int i = 0; i < 3; i++) {
        cin >> note;
        triad[i] = getVal(note);
    }

    int root = 0;
    string type = "";
    for (int i = 0; i < 3; i++) {
        int diff1 = (triad[(i + 1) % 3] - triad[i] + 12) % 12;
        int diff2 = (triad[(i + 2) % 3] - triad[(i + 1) % 3] + 12) % 12;
        if ((diff1 == 3 || diff1 == 4) && (diff2 == 3 || diff2 == 4)) {
            root = i;
            type = TYPES[diff1 - 3][diff2 - 3];
            break;
        }
    }

    cout << NOTES[triad[root]] << '\n';
    cout << type << '\n';
    cout << (root == 0 ? "root position" : root == 2 ? "first inversion" : "second inversion") << '\n';
   
    return 0;
}
