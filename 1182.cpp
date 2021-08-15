#include <iostream>
#include <vector>
using namespace std;

int N,S;
int cnt;
vector<int> v;

int main(){
	cin>>N>>S;	
	for(int i=0;i<N;i++){
		int num;
		cin>>num;
		v.push_back(num);	
	}
	
	for(int b=1;b<(1<<N);b++){//모든 경우의 수에 대하여  
		int sum=0;
		for(int i=0;i<N;i++){
			if((b&(1<<i))!=0)//원소에 해당하는 값을 1로 표현하여 선택  
				sum+=v[i];
		}
		
		if(sum==S)
			++cnt;
	}
	
	cout<<cnt;
	return 0;
}
