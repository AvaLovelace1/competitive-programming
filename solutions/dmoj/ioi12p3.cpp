/*
 Solution to IOI '12 P3 - Crayfish Scrivener by Ava Pun
 Key concepts: k-th ancestor with sparse table, persistent data structures
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
const int MOD = 1e9;
const int MAX = 1e6 + 5;

int NC = 0;
char tree[MAX];
int par[MAX][25], depth[MAX];

inline void addNode(int p, char c) {
    NC++;
    par[NC][0] = p;
    tree[NC] = c;
    for (int i = 1; i <= 20; i++) {
        par[NC][i] = par[par[NC][i - 1]][i - 1];
    }
    depth[NC] = depth[p] + 1;
}

void Init() {
}

void TypeLetter(char L) { 
    addNode(NC, L);
}

void UndoCommands(int U) {
    int ver = NC - U;
    addNode(par[ver][0], tree[ver]);
}

char GetLetter(int P) {
    P++;
    int dist = depth[NC] - P;
    int u = NC;
    for (int i = 20; i >= 0; i--) {
        if (dist - (1 << i) >= 0) {
            u = par[u][i];
            dist -= (1 << i);
        }
    }
    return tree[u];
}

int main() {

    int Q;
    scanf("%d", &Q);
    Init();
    int b;
    char a, c;
    for (int i = 1; i <= Q; i++) {
        scanf(" %c", &a);
        if (a == 'T') {
            scanf(" %c", &c);
            TypeLetter(c);
        } else if (a == 'U') {
            scanf("%d", &b);
            UndoCommands(b);
        } else {
            scanf("%d", &b);
            printf("%c\n", GetLetter(b));
        }
    }

    return 0;
}
