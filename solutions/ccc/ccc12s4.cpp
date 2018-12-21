/*
 Solution to CCC '12 S4 - A Coin Game by Ava Pun
 Key concepts: BFS
 */
 
 #include <bits/stdc++.h>

using namespace std;

int N;
string s, ans;
queue<string> q;
unordered_map<string, bool> vis;
unordered_map<string, int> dist;

int get(string x, int pos) {
    pos *= (N + 1);
    while (x[pos] != ' ') {
        pos++;
    }
    return pos;
}

void process(string x, int pos0, int pos) {
    if (pos < 0 || pos >= N) {
        return;
    }
    string n = x;
    int coin0pos = get(x, pos0);
    int coin1pos = get(x, pos);
    if (coin0pos == pos0 * (N + 1)) {
        return;
    }
    if (coin1pos == pos * (N + 1)) {
        n[coin1pos] = n[coin0pos - 1];
        n[coin0pos - 1] = ' ';
    } else if (x[coin0pos - 1] < x[coin1pos - 1]) {
        n[coin1pos] = n[coin0pos - 1];
        n[coin0pos - 1] = ' ';
    } else {
        return;
    }
    
    if (!vis[n]) {
        vis[n] = true;
        dist[n] = dist[x] + 1;
        q.push(n);
    }
}

int main() {
    
    scanf("%d", &N);
    int n;
    while (N != 0) {
        s = "";
        ans = "";
        for (int i = 0; i < N * (N + 1); i++) {
            s += ' ';
            ans += ' ';
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &n);
            s[i * (N + 1)] = n + '0';
            ans[i * (N + 1)] = i + '1';
        }
        while (!q.empty()) {
            q.pop();
        }
        vis.clear();
        dist.clear();
        q.push(s);
        vis[s] = true;
        dist[s] = 0;
        while (!q.empty()) {
            string x = q.front();
            q.pop();
            if (x == ans) {
                break;
            }
            for (int i = 0; i < N; i++) {
                process(x, i, i + 1);
                process(x, i, i - 1);
            }
        }
        if (dist.find(ans) == dist.end()) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", dist[ans]);
        }
        scanf("%d", &N);
    }
 
    return 0;
    
}
