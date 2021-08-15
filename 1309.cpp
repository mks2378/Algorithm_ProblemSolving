#include <iostream>
using namespace std;

int N;
int dp[100001];


// 관계가 안보인다면, dp[1]~dp[4]까지는 직접 해보면서  
// 관계 추론하는 것이 확실(보통 항3개까지 관계를 고려하게 출제)  
int main(){
	cin>>N;
	
	dp[1] = 3;
	dp[2] = 7;
	
	for(int i=3;i<=N;i++)
		dp[i] = (dp[i-2]*3 + (dp[i-1] - dp[i-2])*2)%9901;
	
	cout<<dp[N];
	
	return 0;
}
