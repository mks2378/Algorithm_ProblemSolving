#include <iostream>
using namespace std;

int N;
unsigned long long dp[91][2];

int main(){
	cin>>N;
	
	dp[1][1] = 1;
	dp[2][0] = 1;
	
	for(int i=3;i<=N;i++){
		for(int j=0;j<2;j++){
			if(j==0)
				dp[i][j] = dp[i-1][0] + dp[i-1][1];
			else
				dp[i][j] = dp[i-1][0];
		}
	}

	cout<<dp[N][0]+dp[N][1];
	
	return 0;
}
