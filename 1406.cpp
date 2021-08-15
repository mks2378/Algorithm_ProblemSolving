#include <iostream>
#include <string>
#include <stack>
using namespace std;

// cin은 space를 기준으로 끊어 받고 남은 데이터는 버퍼에 남아 있다. 

int main(){
	int n;
	string s;
	
	cin>>s;
	cin>>n;
	stack<char> s1, s2;
	
	//stack<char> s1(s.begin(), s.end()); string 클래스도 begin(), end() 사용 가능  
	for(auto &x:s){
		s1.push(x);
	}
	
	//s1.end() 커서의 위치 
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
	
	// 처음부터 순서대로 출력하기 위해 s1 스택에서 s2 스택으로 옮긴다  
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
