#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin>>s;
	
	int val = (s[0]-'0')/4;
	int re = (s[0]-'0')%4;;
	if(val!=0){
		cout<<val;
		
		val = re/2;
		re = re%2;
		cout<<val;
		cout<<re;
	}
	else{
		val = re/2;
		re = re%2;
		
		if(val==0)
			cout<<re;
		else{
			cout<<val;
			cout<<re;
		}
	}
	
	for(int i=1;i<s.length();i++){
		val = (s[i]-'0')/4;		
		cout<<val;
		re = (s[i]-'0')%4;
		
		val = re/2;
		cout<<val;
		re = re%2;
		
		cout<<re;
	}

	return 0;
}
