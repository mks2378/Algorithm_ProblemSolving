#include <iostream>
using namespace std;

string N;
int Base;

int get_ex(){
	long long num=1;
	for(int i=1;i<N.length();i++)
		num*=Base;
	
	return num;
}

int main(){
	long long ex;
	long long result=0;
	
	cin>>N; cin>>Base;
	ex = get_ex();
	
	for(int i=0;i<N.length();i++){
		if(N[i]>='0'&&N[i]<='9')
			result+=(N[i]-'0')*ex;
		else
			result+=(N[i]-('A'-10))*ex;
			
		ex /= Base;
	}
	
	cout<<result;
	return 0;
}
