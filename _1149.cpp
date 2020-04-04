#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];
int cost[1001][3];

int N;

int main(){
	cin>>N;
	
	for(int i=1;i<=N;i++)
		cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
		
	for(int i=1;i<=N;i++){
		dp[i][0] = min(dp[i-1][1],dp[i-1][2])+cost[i][0];	
		dp[i][1] = min(dp[i-1][0],dp[i-1][2])+cost[i][1];
		dp[i][2] = min(dp[i-1][0],dp[i-1][1])+cost[i][2];
	}	
	
	cout<<min(min(dp[N][0],dp[N][1]),dp[N][2])<<'\n';
	
	return 0;
}

/*
3 
1 20 30 
50 5 6 
9 3 7

����:13
����:10

�׸���� ���� ã�ư� �� ���ӵ� row���� ���� column�� �ּڰ��� ������ ��,
��Ģ �Ͽ� �ּڰ��� ������ �����ٸ� ���� ���̽��� �߻��Ѵ� (5+7 vs 6+3) 
*/


// �Ʒ��� �׸���� �߸� �������� ��  
/*
#include <iostream>
using namespace std;

int dp[1001];
int arr[1001][3];
int selected = -1;
int s;

int N;

int main(){
	cin>>N;
	
	for(int i=1;i<=N;i++)
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	
	for(int i=1;i<=N;i++){
		dp[i] = 1001;
		for(int j=0;j<3;j++){
			if(j!=selected && dp[i]>arr[i][j]){
				dp[i] = arr[i][j];
				s = j;	
			}
		}
		selected = s;
	}
	
	int sum=0;
	for(int i=1;i<=N;i++)
		sum+=dp[i];
	
	cout<<sum;
	
	return 0;
}
*/
