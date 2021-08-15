#include <iostream>
#include <vector>
using namespace std;

const unsigned long long mod = 1000000009;

unsigned long long dp[100001][4];

int T, num;
vector<int> v;
unsigned long long total;

// ������ ������ ������ ������ ���� ��, 
// ó�� ������ ������ ������ �� ��������
// ���� ������ ���� ������ ���� ���������� 
// ���� ���� ������ ���� �������� ����  

// ���� ��� ���� �ʹ� Ŀ�� �ڷ����� �� ��� �������� �ذ��Ϸ��� �ǵ�  
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
