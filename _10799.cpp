// 10799 �踷��� 

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
		else{ //str[i] �� ')' �� ��  
			if(str[i-1]=='('){ // �ٷ� ���� '(' �̸� ������ 
				s.pop();
				result += s.size();		
			}
			else{ // �ٷ� ���� ')' �̸� ������ ���� ���� �ϳ� �߰�  
				s.pop();
				result += 1;
			}
		}
	}
	
	cout<<result<<'\n';

	return 0;
}
