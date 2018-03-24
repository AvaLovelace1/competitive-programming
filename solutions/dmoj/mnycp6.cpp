/*
 Solution to Mackenzie New Year's Challenge P6 - Rocks by Ava Pun
 Key concepts: binary indexed tree
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;
int C;
unordered_map<string, pair<int, int>> names;
int tree[MAX] = {};

int findValue(string s) {
    int sum = 0;
    for (char c : s) {
        sum += c - 'a' + 1;
    }
    return sum;
}

void update(int pos, int x) {
    for (int i = pos; i <= MAX; i += i & -i) {
        tree[i] += x;
    }
}

int query(int pos) {
    int sum = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        sum += tree[i];
    }
    return sum;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> C;
    
    char c;
    string s1, s2;
    int len = 0;
    while (C--) {
        cin.ignore();
        cin >> c;
        if (c == 'A') {
            cin >> s1;
            if (names.find(s1) == names.end()) {
                len++;
                names[s1].first = len;
                names[s1].second = findValue(s1);
                update(len, names[s1].second);
            } else {
                cout << "Can't add " << s1 << "\n";
            }
        } else if (c == 'S') {
            cin >> s1 >> s2;
            int diff = names[s2].second - names[s1].second;
            update(names[s1].first, diff);
            update(names[s2].first, -diff);
            int tmp = names[s1].first;
            names[s1].first = names[s2].first;
            names[s2].first = tmp;
        } else if (c == 'M') {
            cin >> s1 >> s2;
            int a = names[s1].first;
            int b = names[s2].first;
            if (a < b) {
                cout << query(a, b);
            } else {
                cout << query(b, a);
            }
            cout << "\n";
        } else if (c == 'R') {
            cin >> s1 >> s2;
            int mass = findValue(s2);
            int pos = names[s1].first;
            update(pos, mass - names[s1].second);
            names.erase(s1);
            names[s2].first = pos;
            names[s2].second = mass;
        } else {
            cout << len << "\n";
        }
    }
    
    return 0;
    
}
