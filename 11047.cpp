#include <iostream>

using namespace std;

int N,K;
int cnt;
int price[10];


int main(){
	cin>>N>>K;	
	
	for(int i=0;i<N;i++)
		cin>>price[i];
	
	for(int i=N-1;i>=0;i--){
		if(K/price[i]!=0){
			cnt += K/price[i];
			K = K - (K/price[i])*price[i];
		}
	}
	
	cout<<cnt;	
	
	return 0;
}
