#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000009

int T, value;
unsigned long long dp[1000001];

int main(){
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for(int i=4;i<=1000000;i++)
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%mod;		
	
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>value;
		cout<<dp[value]<<'\n';
	}
	
	return 0;
}
