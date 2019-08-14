/////////////////////////////////////////////
// 방학중 C++ 문제 풀이 및 알고리즘 공부 용//
// 문제 출처: 백준 알고리즘                // 
// 풀이자: Ismodan(한현민)                 //
// 문제번호: 11054번                       // 
/////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
 
using namespace std; 


 
int main(void){
    int N;
    int Dp[2][1010] = {};
    int A[1010] = {};
    int max = 0;
    scanf("%d", &N);
 
    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
 
    for (int i = 1; i <= N; i++)
    {
        int maxA = 0;
        for (int j = 0; j < i; j++){
            if (A[i]>A[j]){
                if (maxA < Dp[0][j])
                    maxA = Dp[0][j];
            }
        }
        Dp[0][i] = maxA + 1;
    }
 
    
    for (int i = N; i >= 1; i--)
    {
        int maxA = 0;
        for (int j = N; j > i; j--){
            if (A[i]>A[j]){
                if (maxA < Dp[1][j])
                    maxA = Dp[1][j];
            }
        }
        if (Dp[1][i]<maxA + 1)
            Dp[1][i] = maxA + 1;
    }
    
    for (int i = 1; i <= N; i++){
        if (max < Dp[0][i] + Dp[1][i])
            max = Dp[0][i] + Dp[1][i];
    }
 
 
    printf("%d\n", max-1);
 
}




