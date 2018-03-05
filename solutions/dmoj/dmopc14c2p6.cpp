/*
 Solution to DMOPC '14 Contest 2 P6 - Selective Cutting by Ava Pun
 Key concepts: binary indexed tree, offline queries
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pair<pii, pii>, ll> qq;

int N, Q;
vector<pii> arr;
vector<qq> queries;
ll tree[100005];

bool comp(qq a, qq b) {
    return a.first.first.second < b.first.first.second;
}

void update(int pos, int x) {
    for (int i = pos; i <= N; i += i & -i) {
        tree[i] += x;
    }
}

ll query(int x) {
    ll sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        sum += tree[i];
    }
    return sum;
}

ll query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    
    scanf("%d", &N);
    int a;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a);
        arr.push_back({a, i});
    }
    sort(arr.begin(), arr.end(), greater<pii>());
    
    scanf("%d", &Q);
    int pos = 0, l, r, x;
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d%d", &l, &r, &x);
        queries.push_back({{{x, i}, {l, r}}, 0});
    }
    
    sort(queries.begin(), queries.end(), greater<qq>());
    
    for (int i = 0; i < Q; i++) {
        x = queries[i].first.first.first;
        l = queries[i].first.second.first;
        r = queries[i].first.second.second;
        while (arr[pos].first >= x && pos < N) {
            update(arr[pos].second, arr[pos].first);
            pos++;
        }
        queries[i].second = query(l + 1, r + 1);
    }
    
    sort(queries.begin(), queries.end(), comp);
    
    for (qq q : queries) {
        printf("%lld\n", q.second);
    }
    
    return 0;
    
}
