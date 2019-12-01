/*
 Solution to CCC '00 S4 - Golf by Ava Pun
 Key concepts: implementation, machine language
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
        "13",
        "1", // 1
        "2", // 2
        "3", // 3
        "0", // [04]: N
        "0", // [05]: A
        "0", // [06]: D
        "0", // [07]: tmp1
        "0", // [08]: tmp2
        "100", // [09]: accA
        "100", // [10]: accD
        "14", // [11]: *
        "31", // [12]: ALE
        "80400", // scan into N
        "40004", // * if N = 0, skip next
        "10003", // skip next 3
        "70009", // print accA
        "70010", // print accD
        "90000", // HALT
        "20401", // N -= 1
        "80500", // scan into A
        "80600", // scan into D
        "30705", // tmp1 = A
        "20706", // tmp1 -= D
        "30806", // tmp2 = D
        "20805", // tmp2 -= A
        "40007", // if tmp1 = 0, skip next
        "00000", // skip next
        "30012", // go to ALE
        "21005", // A wins: accD -= A
        "30011", // go to *
        "40008", // ALE: if tmp2 = 0, skip next
        "00000", // skip next
        "30011", // go to *
        "20906", // D wins: accA -= D
        "30011" // go to *
    };
    read(acc);

    return 0;
}
