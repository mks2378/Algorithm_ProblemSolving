/* 처음에 짠 코드  
#include <iostream>
using namespace std;

int P[1001];
int N, idx, total;
float max_card;

int main(){
	cin>>N;
	
	for(int i=1;i<=N;i++){
		cin>>P[i];
		
		if(max_card<(double(P[i])/i)){
			max_card = (double(P[i])/i);
			idx = i;
		}
	}
		
	while(N>0){
		while(N-idx>=0){
			N-=idx;
			total += P[idx];
		}
		
		max_card = 0;
		for(int j=1;j<idx;j++){
			if(max_card<(double(P[j])/j)){
				max_card = (double(P[j])/j);
				idx = j;
			}
		}
	}
	
	cout<<total;
	
	return 0;
}
*/ 

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int p[1001];
int dp[1001];

// bottom-up 방식 
// N개 만큼의 입력 받고, i-j까지의 수를 넘어갈 수 없으므로 
// max를 i-j까지 p값을 더해나가면서 이용하여 최댓값을 구한다 
// 결국 최종 N의 값에 최댓값이 들어간다  
int main(){
	cin>>N;
	
	for(int i=1;i<=N;i++)
		cin>>p[i];	
		
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			dp[i] = max(dp[i], dp[i-j]+p[j]);
		}		
	}
	
	cout<<dp[N];
	
	return 0;
}
// https://yangorithm.tistory.com/67
