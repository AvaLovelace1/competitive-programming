/*
 Solution to  by Ava Pun
 Key concepts: simulation
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
const int MAX = 20;

int R, C, N;
pii arr[MAX], pos[MAX];
int idx[MAX];
string strat[MAX];
bool blocked[15][15], robot[15][15];
bool stuck[MAX];
const pii moves[] = {{0, 0}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

bool clear(int i, int j) {
    return i >= 1 && i <= R && j >= 1 && j <= C && !blocked[i][j];
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for (int test = 1; test <= 10; test++) {
        
        FILL(robot, 0);
        
        cin >> R >> C >> N;
        for (int i = 1; i <= N - 1; i++) {
            cin >> arr[i].f >> arr[i].s;
            robot[arr[i].f][arr[i].s] = true;
        }
        for (int i = 1; i <= N; i++) {
            cin >> strat[i];
        }
        
        bool lose = true;
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                
                if (robot[r][c]) {
                    continue;
                }
                
                FILL(blocked, 0);
                FILL(stuck, 0);
                for (int i = 1; i <= N - 1; i++) {
                    pos[i] = arr[i];
                }
                pos[N] = {r, c};
                for (int i = 1; i <= N; i++) {
                    idx[i] = 0;
                    blocked[pos[i].f][pos[i].s] = true;
                }
                
                bool done = false;
                while (!done) {
                    
                    for (int i = 1; i <= N && !done; i++) {
                        
                        if (!stuck[i]) {
                            int j = 0;
                            bool moved = false;
                            
                            int r1 = pos[i].f, c1 = pos[i].s;
                            for (j = 0; j < strat[i].length() && !moved; j++) {
                                int n = strat[i][(j + idx[i]) % strat[i].length()] - '0';
                                if (clear(r1 + moves[n].f, c1 + moves[n].s)) {
                                    moved = true;
                                    r1 += moves[n].f;
                                    c1 += moves[n].s;
                                    blocked[r1][c1] = true;
                                    break;
                                }
                            }
                            
                            if (!moved) {
                                stuck[i] = true;
                            } else {
                                idx[i] = (j + idx[i] + 1) % strat[i].length();
                                pos[i].f = r1, pos[i].s = c1;
                            }
                            
                            int cnt = 0;
                            for (int j = 1; j <= N; j++) {
                                if (!stuck[j]) {
                                    cnt++;
                                }
                            }
                            if (cnt == 1) {
                                done = true;
                            }
                        }
                    }
                }
                
                if (!stuck[N]) {
                    lose = false;
                    cout << '(' << r << ',' << c << ')' << ' ';
                }
                
            }
        }
        
        if (lose) {
            cout << "LOSE";
        }
        cout << '\n';
        
    }
    
    return 0;
}
