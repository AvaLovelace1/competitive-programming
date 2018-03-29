/*
 Solution to Mimi and Christmas Cake by Ava Pun
 Key concepts: sieve of Eratosthenes
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100001];
bool sieve[100001];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= 100000; i++) {
        if (!sieve[i]) {
            for (int j = i * i; j <= 100000; j += i) {
                sieve[j] = true;
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (!sieve[arr[i]]) {
            count++;
        }
    }
    
    printf("%d", count);
     
    return 0;
}
