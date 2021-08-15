#include <iostream>
#include <string>
using namespace std;

int alpha[26];
string str;

int main(){
	fill_n(alpha,26,-1);
	cin>>str;
	
	for(int i=0;i<str.length();i++){
		if(alpha[str[i]-'a']==(-1))
			alpha[str[i]-'a'] = i;
	}
	
	for(int i=0;i<26;i++)
		cout<<alpha[i]<<' ';
	
	return 0;
}
