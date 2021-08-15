#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

/*
bottom up
1�� ���� ������ �����ؼ� ���� ����� ���� �̸� arr[i]�� (�ִ�)���� �޸�������̼��� �մϴ�.
2�� ������ ����������, 3���� ������ �������� ��쿡 �տ� ����� arr[i/2]�� arr[i/3]�� ������ arr[i]�� ���Ͽ� 
�� �� �ּ� ���� arr[i]�� �ٽ� ����(memorization)�մϴ�  
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
