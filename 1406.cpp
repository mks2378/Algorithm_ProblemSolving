#include <iostream>
#include <string>
#include <stack>
using namespace std;

// cin�� space�� �������� ���� �ް� ���� �����ʹ� ���ۿ� ���� �ִ�. 

int main(){
	int n;
	string s;
	
	cin>>s;
	cin>>n;
	stack<char> s1, s2;
	
	//stack<char> s1(s.begin(), s.end()); string Ŭ������ begin(), end() ��� ����  
	for(auto &x:s){
		s1.push(x);
	}
	
	//s1.end() Ŀ���� ��ġ 
	while(n--){ 
	 	char cmd;
	 	cin>>cmd;
		
		if(cmd=='L'){
			if(!(s1.empty())){
				s2.push(s1.top());
				s1.pop();
			}
		}
		else if(cmd=='D'){
			if(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}		
		}
		
		else if(cmd=='B'){
			if(!(s1.empty())){
				s1.pop();
			}
		}
		else if(cmd=='P'){
			char x;
			cin>>x;
			s1.push(x);
		}
	}
	
	// ó������ ������� ����ϱ� ���� s1 ���ÿ��� s2 �������� �ű��  
	while(!(s1.empty())){
		s2.push(s1.top());
		s1.pop();
	}
	
	while(!(s2.empty())){
		cout<<s2.top();
		s2.pop();
	}
	
	return 0;
}
