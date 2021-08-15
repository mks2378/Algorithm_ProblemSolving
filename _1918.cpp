//// 1918_후위표기식 
//
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <string>
//using namespace std;
//
//stack<char> paren;
//stack<char> sign;
//queue<char> q;
//
//int main(){
//	string str;
//	cin>>str;
//	
//	for(int i=0;i<str.length();i++){
//		if(str[i]>='A'&&str[i]<='Z'){
//			q.push(str[i]);	
//		}
//		
//		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
//			sign.push(str[i]);	
//		}
//		
//		else if(str[i]=='(')
//			paren.push(str[i]);
//			
//		else if(str[i]==')'){
//			paren.pop();
//			if(paren.empty()){
//				while(!q.empty()){
//					cout<<q.front();
//					q.pop();
//				}
//			
//				while(!sign.empty()){
//					cout<<sign.top();
//					sign.pop();	
//				}
//			}
//		}
//	}
//	
//	while(!q.empty()){
//		cout<<q.front();
//		q.pop();
//	}
//				
//	while(!sign.empty()){
//		cout<<sign.top();
//		sign.pop();	
//	}
//
//	return 0;
//}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> s;
	string str;
	cin>>str;
	
	
	for(int i=0;i<str.length();i++)
	{
		if('A'<=str[i] && str[i]<='Z')
			cout<<str[i];
		else
		{
			switch(str[i])
			{
			case '(':
				s.push(str[i]);
				break;
			case '*':
			case '/':
				while(!s.empty() && (s.top() == '*' ||	s.top() == '/'))
				{
					cout<<s.top();
					s.pop();	
				}
				s.push(str[i]);
				break;
			case '+':
			case '-':
				while(!s.empty() && s.top() != '(')
				{
					cout<<s.top();
					s.pop();					
				}
				s.push(str[i]);
				break;
			case ')':
				while(!s.empty() && s.top()!='(')
				{
					cout<<s.top();
					s.pop();
				}
				s.pop();
				break;		
			}
		}
	}
	
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();		
	}
	
	return 0;
}
	
	
