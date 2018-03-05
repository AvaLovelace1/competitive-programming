/*
 Solution to COCI '07 Contest 5 #6 Baza by Ava Pun
 Key concepts: binary indexed tree, offline queries, binary search
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<string, short int> pii;
const int MAX = 3e4 + 5;

int N, Q;
string arr[MAX], sorted[MAX];
short int bit[MAX];
pii queries[MAX];
int ans[MAX];
unordered_map<string, short int> m;
unordered_map<string, short int> sortedM;

int value(string s) {
    if (m.find(s) == m.end()) {
        return N;
    } else {
        return m[s];
    }
}

bool comp(pii a, pii b) {
    return value(a.first) < value(b.first);
}

void insert(int pos) {
    for (int i = pos; i <= N; i += i & -i) {
        bit[i]++;
    }
}

int query(int pos) {
    int sum = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        sum += bit[i];
    }
    return sum;
}

int binSearch(int l, int r, int pos, char c) {
    int mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (pos < sorted[mid].length() && sorted[mid][pos] >= c) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int query(string s) {
    int sum = 0, l = 1, r = N, l0, r0;
    for (int i = 0; i < s.length(); i++) {
        l0 = binSearch(l, r + 1, i, s[i]);
        r0 = binSearch(l, r + 1, i, s[i] + 1);
        r0--;
        sum += query(r0) - query(l0 - 1);
        l = l0;
        r = r0;
    }
    return sum;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sorted[i] = arr[i];
        m[arr[i]] = i;
    }
    
    sort(sorted + 1, sorted + N + 1);
    
    for (int i = 1; i <= N; i++) {
        sortedM[sorted[i]] = i;
    }
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].first;
        queries[i].second = i;
    }
    
    sort(queries, queries + Q, comp);
    
    int idx = 1;
    for (int i = 0; i < Q; i++) {
        while (idx <= value(queries[i].first)) {
            insert(sortedM[arr[idx]]);
            idx++;
        }
        ans[queries[i].second] = query(queries[i].first) + value(queries[i].first);
    }
    
    for (int i = 0; i < Q; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
    
}
