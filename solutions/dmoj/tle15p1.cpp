/*
 Solution to TLE '15 P1 - Power Rankings by Ava Pun
 Key concepts: sorting, implementation
 */

 #include <bits/stdc++.h>

using namespace std;

int N, P;
pair<int, string> arr[101];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> P;
    
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        arr[i] = {0, s};
    }
    
    int n;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < N; j++) {
            cin >> n;
            arr[j].first += n;
        }
    }
    
    sort(arr, arr + N, greater< pair<int, string> >());
    for (int i = 0; i < N; i++) {
        cout << i + 3 << ". " << arr[i].second << "\n";
    }
    
    return 0;
    
}
