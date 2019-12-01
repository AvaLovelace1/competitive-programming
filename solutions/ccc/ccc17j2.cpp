/*
 Solution to CCC '17 J2 - Shifty Sum by Ava Pun
 Key concepts: implementation, simple math, machine language
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const double EPS = 1e-9;

int ram[1000005];

void coredump() {
    printf("---\n");
    for (int i = 0; i < 100; i++) {
        printf("[%d]: %d\n", i, ram[i]);
    }
    printf("---\n");
}

void read(vector<string> acc) {
    for (int i = 0; i < acc.size(); i++) {
        ram[i] = stoi(acc[i]);
        if (ram[i] < 0) {
            printf("ERROR: Attempt to store invalid value\n");
            return;
        }
    }
    while (1) {
        int instr = ram[ram[0]];
        ram[0]++;
        int op = instr / 10000;
        int tt = instr % 10000 / 100;
        int ss = instr % 100;
        switch (op) {
            case 0:
                ram[tt]++;
                break;
            case 1:
                ram[tt] += ram[ss];
                break;
            case 2:
                ram[tt] = max(0, ram[tt] - ram[ss]);
                break;
            case 3:
                ram[tt] = ram[ss];
                break;
            case 4:
                if (ram[ss] == 0) {
                    ram[tt]++;
                }
                break;
            case 5:
                ram[tt] = ram[ram[ss]];
                break;
            case 6:
                ram[ram[tt]] = ram[ss];
                break;
            case 7:
                printf("%d\n", ram[ss]);
                break;
            case 8:
                scanf("%d", &ram[tt]);
                break;
            case 9:
                return;
        }
    }
}

int main() {

    vector<string> acc = {
        "11",
        "1", // 1
        "2", // 2
        "0", // [03]: N
        "0", // [04]: K
        "0", // [05]: tmp1
        "0", // [06]: tmp2
        "0", // [07]: acc
        "13", // [08]: *
        "20", // [09]: **
        "9", // [10]: 9
        "80300", // scan into N
        "80400", // scan into K
        "10703", // * acc = acc + N
        "40004", // if K = 0, skip next
        "10002", // skip next 2
        "70007", // print acc
        "90000", // HALT
        "30510", // tmp1 = 9
        "30603", // tmp2 = N
        "10306", // ** N = N + tmp2
        "20501", // tmp1 = tmp1 - 1
        "40005", // if tmp1 = 0, skip next
        "10002", // skip next 2
        "20401", // K = K - 1
        "30008", // go to *
        "30009" // go to **
    };
    read(acc);

    return 0;
}
