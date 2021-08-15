#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int dp[100001];
int min_v;
int N, rt;

int main(){
	cin>>N;
	
	for(int i=1;i<=N;i++){
		rt = sqrt(i);

		if(i!=rt*rt){
			dp[i] = INT_MAX;
			for(int j=1;j<=rt;j++){
				min_v = dp[j*j] + dp[i-(j*j)];
				dp[i] = min(dp[i], min_v);			
			}
		}
		else
			dp[i] = 1;
	}
	
	cout<<dp[N];
	
	return 0;
}
