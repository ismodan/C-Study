/////////////////////////////////////////////
// ������ C++ ���� Ǯ�� �� �˰��� ���� ��//
// ���� ��ó: ���� �˰���                // 
// Ǯ����: Ismodan(������)                 //
// ������ȣ: 11722��                       // 
/////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
 
using namespace std; 

int dp[1001] = {}; 

int Max(int a, int b)
{
	return a > b ? a: b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	int input[1001];
	int max = 0;
	dp[0] = 1;
	for(int i = 0; i < n; i++)
		cin>>input[i];
		
	for(int i = 0; i < n; i++)
	{
		int com = 0;
		for(int j = i - 1; j >= 0; j--)
		{
			if(input[i] < input[j])
			{
				com = Max(com, dp[j]);
			}
		}
		dp[i] = com + 1;
		
	}
	
	int ret = -1;
	for(int i = 0; i < n; i++)
		ret = Max(dp[i], ret);
		
	cout<<ret;
		
	
	return 0;
}



