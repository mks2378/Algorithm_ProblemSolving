#include <iostream>
using namespace std;

int N;
int dp[100001];


// ���谡 �Ⱥ��δٸ�, dp[1]~dp[4]������ ���� �غ��鼭  
// ���� �߷��ϴ� ���� Ȯ��(���� ��3������ ���踦 ����ϰ� ����)  
int main(){
	cin>>N;
	
	dp[1] = 3;
	dp[2] = 7;
	
	for(int i=3;i<=N;i++)
		dp[i] = (dp[i-2]*3 + (dp[i-1] - dp[i-2])*2)%9901;
	
	cout<<dp[N];
	
	return 0;
}
