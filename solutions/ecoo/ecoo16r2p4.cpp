/*
 Solution to ECOO '16 R2 P4 - Hop, Skip and Jump by Ava Pun
 Key concepts: graph theory, DFS, implementation
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
const int MAX = 205;

int W, H;
char grid[MAX][MAX];
bool vis[MAX][MAX];
unordered_map<char, pii> pos;

bool clear(int i, int j) {
    return i >= 1 && i <= H && j >= 1 && j <= W && grid[i][j] != '=';
}

void dfs(int i, int j, char c);

void push(int i, int j, char c) {
    if (!vis[i][j] && clear(i, j)) {
        vis[i][j] = true;
        dfs(i, j, c);
    }
}

void dfs(int i, int j, char c) {
    
    while (i < H && grid[i + 1][j] == '.' && grid[i][j] != '#') {
        i++;
        vis[i][j] = true;
    }
    
    if (i == H && grid[i][j] == '.') {
        return;
    }
    
    push(i, j - 1, c);
    push(i, j + 1, c);
    if (grid[i][j] == '#') {
        push(i - 1, j, c);
    }
    if (grid[i + 1][j] == '#') {
        push(i + 1, j, c);
    }
    
    if (c == 'h' || c == 'j') {
        if (clear(i - 1, j)) {
            for (int k = -1; k <= 1; k++) {
                if (clear(i - 1, j + k)) {
                    push(i - 1, j + k, c);
                }
            }
        }
    }
    
    if (c == 's' || c == 'j') {
        for (int k = -1; k <= 1; k += 2) {
            if (clear(i, j + k)) {
                push(i, j + 2 * k, c);
            }
        }
    }
    
    if (c == 'j') {
        
        for (int k = -1; k <= 1; k += 2) {
            if (clear(i, j + k) && clear(i, j + 2 * k)) {
                push(i, j + 3 * k, c);
            }
        }
        
        for (int k = -1; k <= 1; k += 2) {
            if (clear(i - 1, j) && clear(i, j + k) && clear(i - 1, j + k)) {
                push(i - 1, j + 2 * k, c);
            }
        }
        
        if (clear(i - 1, j) && clear(i - 2, j)) {
            push(i - 3, j, c);
        }
        
    }
    
}

void dfs(char c) {
    
    FILL(vis, 0);
    vis[pos[c].f][pos[c].s] = true;
    dfs(pos[c].f, pos[c].s, c);
    if (c == 'h') {
        printf("HOP ");
    } else if (c == 's') {
        printf("SKIP ");
    } else {
        printf("JUMP ");
    }
    if (vis[pos['C'].f][pos['C'].s]) {
        printf("C");
    }
    if (vis[pos['F'].f][pos['F'].s]) {
        printf("F");
    }
    if (vis[pos['T'].f][pos['T'].s]) {
        printf("T");
    }
    printf("\n");
    
}

int main() {
    
    for (int test = 1; test <= 10; test++) {
        
        FILL(grid, 0);
        scanf("%d%d", &W, &H);
        for (int i = 1; i <= H; i++) {
            scanf("%s", grid[i] + 1);
            for (int j = 1; j <= W; j++) {
                if (grid[i][j] != '.' && grid[i][j] != '=' && grid[i][j] != '#') {
                    pos[grid[i][j]] = {i, j};
                    grid[i][j] = '.';
                }
            }
        }
        
        dfs('h');
        dfs('s');
        dfs('j');
        
        printf("\n");
    }
    
    return 0;
}
