#include <iostream>

using namespace std;

int LCM(int num1, int num2){
	int min = num1<num2?num1:num2;
	int lcm=1;
	
	for(int i=2;i<=min;i++){
		while(num1%i==0&&num2%i==0){
			lcm*=i;
			num1 = num1/i;
			num2 = num2/i;	
		}
	}
	lcm*=num1;
	lcm*=num2;
	
	return lcm;
}

int main(){
	int tc;
	int num1, num2;
	
	cin>>tc;
	while(tc--){
		cin>>num1; cin>>num2;	
		cout<<LCM(num1,num2)<<'\n';
	}
	
	return 0;
}
