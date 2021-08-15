#include <iostream>
#include <algorithm>
using namespace std;

int N;
int p[1001];
int dp[1001];

int f(int N){
	if(N==0)
		return 0;
	if(dp[N])
		return dp[N];
	
	int result = 0;
	for(int i=1;i<=N;i++)
		result = max(result, f(N-i) + p[i]);
	return dp[N] = result;	
}

int main(){
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>p[i];
	cout<<f(N);
	
	return 0;
}
// https://yangorithm.tistory.com/67
