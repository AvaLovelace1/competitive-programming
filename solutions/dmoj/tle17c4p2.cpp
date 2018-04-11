/*
 Solution to TLE '17 Contest 4 P2 - Microwave Buttons by Ava Pun
 Key concepts: brute force
 */

#include <bits/stdc++.h>

using namespace std;

int H, M, S, T;
string t, nums;
bool working[10];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t >> nums;
    
    H = stoi(t.substr(0, 2));
    M = stoi(t.substr(3, 2));
    S = stoi(t.substr(6, 2));
    
    T = S + 60 * M + 3600 * H;
    
    for (char c : nums) {
        working[c - '0'] = true;
    }
    
    int bestH = 0, bestM = 0, bestS = 0, bestT = INT_MAX;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                if (working[i / 10] && working[i - i / 10 * 10] &&
                    working[j / 10] && working[j - j / 10 * 10] &&
                    working[k / 10] && working[k - k / 10 * 10] &&
                    abs((i * 3600 + j * 60 + k) - T) < bestT) {
                    bestH = i, bestM = j, bestS = k, bestT = abs((i * 3600 + j * 60 + k) - T);
                }
            }
        }
    }
    
    cout << (bestH <= 9 ? "0" : "") << bestH << ":" << (bestM <= 9 ? "0" : "") << bestM << ":" << (bestS <= 9 ? "0" : "") << bestS;
    
    return 0;
    
}
