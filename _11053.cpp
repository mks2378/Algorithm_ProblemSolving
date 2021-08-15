#include <iostream>

using namespace std;

int dp[1001];
int arr[1001];


int main(){
	int N;
	int max=0;
	
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>arr[i];
		
	for(int i=1;i<=N;i++){
		int min = 0;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && min<dp[j])	
				min = dp[j];
		}
		
		dp[i] = min+1;
		if(max<dp[i])
			max = dp[i];
	}
	
	cout<<max;
	
	return 0;
}
