#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;

int main(){
	string str;
	getline(cin, str);
	
	for(int i=0;i<str.length();i++){
		if((str[i]>='a'&&str[i]<='m')||(str[i]>='A'&&str[i]<='M'))
			str[i] = str[i] + 13;			
		else if((str[i]>='n'&&str[i]<='z')||(str[i]>='N'&&str[i]<='Z'))
			str[i] = str[i] - 13;			
	}
	
	cout<<str<<'\n';
	return 0;
}
