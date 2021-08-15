#include <iostream>
#include <cmath>
using namespace std;
int prime;

bool is_prime(int num){
	if(num==1)
		return false;
	
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0)
			return false;		
	}
	return true;	
}

int main(){
	int tc, num;
	
	cin>>tc;
	
	for(int i=0;i<tc;i++){
		cin>>num;
		if(is_prime(num))
			prime++;		
	}
	
	cout<<prime;		
	
	return 0;
}
