#include <iostream>
using namespace std;

int main(){
	int cmn=1, cmx=1;
	int num1, num2;
	
	cin>>num1; cin>> num2;
	
	int min = num1<num2?num1:num2;
	
	for(int i=2;i<=min;i++){
		while(num1%i==0&&num2%i==0){
			cmn*=i;
			cmx*=i;
			num1 = num1/i;
			num2 = num2/i;	
		}
	}
	cmx*=num1;
	cmx*=num2;
	
	cout<<cmn<<'\n';
	cout<<cmx<<'\n';		
	
	return 0;
}
