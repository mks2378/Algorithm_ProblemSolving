#include <iostream>
#include <cmath>
using namespace std;

bool no_prime[1000001] = {0,1}; // 배열 선언 동시 초기화  

int main(){
	int num1, num2;
	
	cin>>num1; cin>>num2;
	
	// 2,3은 이미 소수라고 가정하고 접근  
	for(int i=2;i<=sqrt(num2);i++){
		for(int j=2;i*j<=num2;j++)
			no_prime[i*j] = 1;
	}
	
	for(int i=num1;i<=num2;i++){
		if(!no_prime[i])
			cout<<i<<'\n';
	}
	
	return 0;
}
