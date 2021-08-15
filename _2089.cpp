#include <iostream>
using namespace std;

void cal(long long n){
	if(n==0)
		return;
		
	if(n<0){
		cal(-((n-1)/2));
		cout<<(-n)%2;
	}
	else if(n>0){
		cal(-(n/2));
		cout<<(n%2);
	}	
}

int main(){
	long long N;
	cin>>N;
	
	if(N==0){
		cout<<0;
		return 0;
	}
	cal(N);
	
	return 0;	
}
