#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	int tc;
	
	cin>>tc;
	
//	while(tc>0){
//		stack<int> st;
//		string str;
//		
//		cin>>str;
//		for(int j=0;j<str.length();j++){
//			if(str[j]=='('||st.empty())
//				st.push(str[j]);
//			else if(st.top()=='(')
//				st.pop();
//		}
//		
//		if(st.empty())
//			cout<<"YES"<<endl;
//		else
//			cout<<"NO"<<endl;
//		
//		tc--;		
//	}
	
	for(int i=0;i<tc;i++){
		string s;
		cin>>s;
		int count =0;
		
		for(int j=0;j<s.length()&&count>=0;j++){
			if(s[j]=='(')
				count++;
			else
				count--;			
		}
		
		if(count==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
	
	return 0;
}
