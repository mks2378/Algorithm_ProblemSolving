#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

/*
bottom up
1을 빼는 계산부터 시작해서 작은 계산을 통해 미리 arr[i]에 (최대)값을 메모라이제이션을 합니다.
2로 나누어 떨어지는지, 3으로 나누어 떨어지는 경우에 앞에 계산한 arr[i/2]와 arr[i/3]과 현재의 arr[i]와 비교하여 
그 중 최소 값을 arr[i]에 다시 저장(memorization)합니다  
*/

int main(){
	int N;
	cin>>N;
	
	dp[1] = 0;
	
	for(int i=2;i<=N;i++){
		dp[i] = dp[i-1] + 1;
		
		if(i%2==0)
			dp[i] = min(dp[i], dp[i/2]+1);
		if(i%3==0)
			dp[i] = min(dp[i], dp[i/3]+1);
	}
	
	cout<<dp[N];
	
	return 0;
}
