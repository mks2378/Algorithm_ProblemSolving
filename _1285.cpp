#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ans, n;

char flip(char ch){
	if(ch=='T') return 'H';
	else return 'T';
}

int main(){
	cin>>n;
	
	vector<string> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
		
	ans = n*n;
	// 행 단위로 가능한 모든 경우의 수에 대하여 뒤집기 
	// brute force 
	for(int state=0;state<(1<<n);state++){
		int sum=0;
		for(int j=0;j<n;j++){
			int cnt=0;
			for(int i=0;i<n;i++){
				char ch = v[i][j];
				if(state & (1<<i))
					ch = flip(ch);
				if(ch=='T')
					cnt++;			
			}
			
			// 각 열에 대하여 'T'가 적다면 개수 그대로 
			// 'T'가 많다면 해당 열 전체를 뒤집어 적은 'T' 개수를  
			// sum에 더하겠다는 의미 
			sum += min(cnt,n-cnt);
		}
		if(ans>sum)
			ans = sum;		
	}
	
	cout<<ans;	
	
	return 0;
}
