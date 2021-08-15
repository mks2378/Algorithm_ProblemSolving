#include <iostream>
using namespace std;

int E, S, M;

// 변수를 하나로 초기화 하려는 아이디어  
int calculateYear(){
	//Year - E = 15*x
	//Year - S = 28*y
	//Year - M = 19*z
	int year = 1;
	while(1){
		if((year-E)%15==0&&(year-S)%28==0&&(year-M)%19==0)
			return year;
		year++;
	}
}

int main(){
	cin>>E>>S>>M;
	
	cout<<calculateYear()<<'\n';
	
	return 0;
}
