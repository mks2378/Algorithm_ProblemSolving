#include <iostream>
using namespace std;

#define mod 10007

int N;
int dp[1001];

int main(){
	cin>>N;
	
	dp[1] = 1;
	dp[2] = 3;
	
	for(int i=3;i<=N;i++)
		dp[i] = (dp[i-1] + 2*dp[i-2])%mod;
		// �������� ���� �� ��� ����

	cout<<dp[N];
	
	return 0;
}
