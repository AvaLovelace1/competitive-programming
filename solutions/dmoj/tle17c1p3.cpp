/*
 Solution to TLE '17 Contest 1 P3 - Screensaver 2 by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

int N, T, M;
string mirrors;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> T >> mirrors;
    
    int vert = 0;
    for (int i = 1; i < N; i++) {
        if (mirrors[i] == '|') {
            vert++;
        }
    }
    
    int time = N + 2 * vert;
    bool firstVert = mirrors[0] == '|' ? true : false;
    
    for (int i = 0; i < T; i++) {
        cin >> M;
        
        if (M == 1) {
            firstVert = !firstVert;
        } else {
            if (mirrors[M - 1] == '|') {
                mirrors[M - 1] = '-';
                time -= 2;
            } else {
                mirrors[M - 1] = '|';
                time += 2;
            }
        }
        
        if (firstVert) {
            cout << 1 << "\n";
        } else {
            cout << time << "\n";
        }
        
    }
    
    return 0;
    
}
