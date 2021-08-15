// 10799 쇠막대기 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> s;
string str;
int result;

int main(){
	cin>>str; 
	
	for(int i=0;i<str.length();i++){
		if(str[i]=='(')
			s.push('(');
		else{ //str[i] 가 ')' 일 때  
			if(str[i-1]=='('){ // 바로 전이 '(' 이면 레이저 
				s.pop();
				result += s.size();		
			}
			else{ // 바로 전이 ')' 이면 마지막 남은 도형 하나 추가  
				s.pop();
				result += 1;
			}
		}
	}
	
	cout<<result<<'\n';

	return 0;
}
