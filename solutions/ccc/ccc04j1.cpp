/*
 Solution to CCC '04 J1 - Squares by Ava Pun
 Key concepts: implementation, simple math
 */

#include <bits/stdc++.h>

using namespace std;

int nTiles;

int main() {
    scanf("%d", &nTiles);
    printf("The largest square has side length %d.", int (sqrt(nTiles)));
}
