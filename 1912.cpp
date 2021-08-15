#include <iostream>
using namespace std;

int dp[100001];
int arr[100001];

int N;

int main(){
	cin>>N;
	
	for(int i=1;i<=N;i++)
		cin>>arr[i];
	
	int max = -1001;
	for(int i=1;i<=N;i++){
		if(dp[i-1]>=0)
			dp[i] = dp[i-1] + arr[i];
		else
			dp[i] = arr[i];
			
		if(dp[i]>max)
			max = dp[i];
	}
	
	cout<<max;	

	return 0;
}
