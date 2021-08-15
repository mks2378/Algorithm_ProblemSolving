#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int p[1001];
int dp[1001];

int main(){
	cin>>N;
	
	for(int i=1;i<=N;i++)
		cin>>p[i];
		
	for(int i=1;i<=N;i++){
		dp[i] = 10000;
		for(int j=1;j<=i;j++){
			dp[i] = min(dp[i], dp[i-j]+p[j]);
		}
	}
	
	cout<<dp[N];
	
	return 0;
}
