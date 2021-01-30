/*
 * Solution to Kayaking by Ava Pun
 * Key concepts: greedy algorithms, sorting, brute force
 */

package main

import (
    "fmt"
    "sort"
)

func main() {

    var N int
    fmt.Scan(&N)

    arr := make([]int, 2 * N)
    for i := 0; i < 2 * N; i++ {
        fmt.Scan(&arr[i])
    }
    sort.Ints(arr)

    ans := 1000000000
    for i := 0; i < 2 * N; i++ {
        for j := i + 1; j < 2 * N; j++ {
            tot := 0
            for k := 0;; {

                for ; k < 2 * N && (k == i || k == j); k++ {}
                k1 := k
                k++
                for ; k < 2 * N && (k == i || k == j); k++ {}
                k2 := k
                k++
                if k1 >= 2 * N || k2 >= 2 * N {
                    break
                }

                p1 := arr[k1]
                p2 := arr[k2]
                if diff := p1 - p2; diff > 0 {
                    tot += diff
                } else {
                    tot += -diff
                }
            }
            if tot < ans {
                ans = tot
            }
        }
    }
    fmt.Println(ans)

}
