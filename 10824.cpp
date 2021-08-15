#include <iostream>
#include <string>

using namespace std;

int main(){
	string str[4];
	long long result; // longlong : intÇü 8byte data type 
	
	for(int i=0;i<4;i++)
		cin>>str[i];
		
	str[0] = str[0]+str[1];
	str[2] = str[2]+str[3];
	
	// to_string() : int->string |||| stoi() : string->int
	result = stoll(str[0]) + stoll(str[2]); 
	cout<<result;
	return 0;
}
