/////////////////////////////////////////////
// 방학중 C++ 문제 풀이 및 알고리즘 공부 용//
// 문제 출처: 백준 알고리즘                // 
// 풀이자: Ismodan(한현민)                 //
// 문제번호: 9465                          // 
/////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std; 

int sticker[2][100001];
int score[2][100001];

int Max(int a, int b)
{
	return a > b ? a: b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, t;
	cin>> t;
	while(t-- > 0)
	{
		cin>>n;
		for(int i = 0; i < 2; i++)
			for(int j = 1; j <= n; j++)
				cin>>sticker[i][j];
		score[0][0] = score[1][0] = 0;
		score[0][1] = sticker[0][1];
		score[1][1] = sticker[1][1];
		
		for(int i = 2; i <= n; i++)
		{
			score[0][i] = Max(score[1][i - 1], score[1][i - 2]) + sticker[0][i];
			score[1][i] = Max(score[0][i - 1], score[0][i - 2]) + sticker[1][i];
		}
		
		cout<<Max(score[0][n], score[1][n])<<'\n';
	}
	
		
	
	return 0;
}


