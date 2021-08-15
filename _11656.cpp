#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<string> v;
	string str;
	cin>>str;
	
	v.push_back(str);
	for(int i=1;i<str.size();i++)
		v.push_back(str.substr(i,str.size()-1)); // substr() usage 
	
	sort(v.begin(),v.end()); // 문자열 sort 적용 가능  
	
	for(string t : v)
		cout<<t<<'\n';	
	
	return 0;
}
