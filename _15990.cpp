#include <iostream>
#include <vector>
using namespace std;

const unsigned long long mod = 1000000009;

unsigned long long dp[100001][4];

int T, num;
vector<int> v;
unsigned long long total;

// 임의의 수들을 임의의 값으로 나눌 때, 
// 처음 수들의 총합을 나눴을 때 나머지는
// 각각 수들을 먼저 나누고 남은 나머지들을 
// 합한 다음 나눴을 때의 나머지와 같다  

// 최종 결과 값이 너무 커서 자료형이 못 담아 나머지로 해결하려는 의도  
int main(){
	int max=0;
	cin>>T;
	
	for(int i=1;i<=T;i++){
		cin>>num;
		v.push_back(num);
		
		if(num>max)
			max = num;
	}
	
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	
	for(int i=4;i<=max;i++){
		dp[i][1] = (dp[i-1][2] + dp[i-1][3])%mod;
		dp[i][2] = (dp[i-2][1] + dp[i-2][3])%mod;
		dp[i][3] = (dp[i-3][1] + dp[i-3][2])%mod;
	}
	
	for(int i=0;i<v.size();i++){
		total = (dp[v[i]][1] + dp[v[i]][2] + dp[v[i]][3])%mod;
		cout<<total<<'\n';
	}
	
	return 0;
}
