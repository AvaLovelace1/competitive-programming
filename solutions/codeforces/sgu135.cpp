/*
 Solution to Drawing Lines by Ava Pun
 Key concepts: mathematics, combinatorics, implementation, machine language
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
    for (int i = 0; i < 40; i++) {
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
        //coredump();
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
        "7",
        "1", // [01]: 1
        "2", // [02]: 2
        "0", // [03]: N
        "1", // [04]: acc
        "1", // [05]: cnt
        "8", // [06]: *
        "80300", // scan into N
        "40003", // * if N = 0, skip next
        "10002", // skip next 2
        "70004", // print acc
        "90000", // HALT
        "10405", // acc += cnt
        "00500", // cnt++
        "20301", // N -= 1
        "30006" // go back to *
    };

    read(acc);

    return 0;
}
