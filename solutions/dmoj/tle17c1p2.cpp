/*
 Solution to TLE '17 Contest 1 P2 - Willson and Food by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int F, N;
unordered_map<string, int> vals;
vector< pair<int, string> > food;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> F;
    
    string s;
    int val;
    
    for (int i = 0; i < F; i++) {
        cin >> s >> val;
        vals[s] = val;
    }
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s >> val;
        food.push_back({val, s});
    }
    
    sort(food.begin(), food.end());
    
    int energy = 0;
    int dist = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        energy -= food[i].first - dist;
        if (energy < 0 && food[i].first != dist) {
            break;
        }
        dist = food[i].first;
        energy += vals[food[i].second];
        count++;
    }
    
    cout << count;
    
    return 0;
    
}
