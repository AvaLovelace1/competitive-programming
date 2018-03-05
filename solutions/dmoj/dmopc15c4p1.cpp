/*
 Solution to DMOPC '15 Contest 4 P1 - Dictionary by Ava Pun
 Key concepts: implementation, sorting
 */
 
#include <bits/stdc++.h>

using namespace std;

int N;
string arr[11];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    for (int i = 0; i < N; i++) {
        if (i > 0 && arr[i - 1][0] == arr[i][0]) {
            cout << ", " << arr[i];
        } else {
            if (i > 0) {
                cout << "\n";
            }
            cout << arr[i];
        }
    }
    
    return 0;
    
}
