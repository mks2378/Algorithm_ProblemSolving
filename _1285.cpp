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
	// �� ������ ������ ��� ����� ���� ���Ͽ� ������ 
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
			
			// �� ���� ���Ͽ� 'T'�� ���ٸ� ���� �״�� 
			// 'T'�� ���ٸ� �ش� �� ��ü�� ������ ���� 'T' ������  
			// sum�� ���ϰڴٴ� �ǹ� 
			sum += min(cnt,n-cnt);
		}
		if(ans>sum)
			ans = sum;		
	}
	
	cout<<ans;	
	
	return 0;
}
