//17412 �ܾ� ������ 2 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int i;
string str;

// ���� ������ -> stack 
int rev_st(int cnt){
	int end = cnt;
	stack<char> s;
	
	// getline�� null���� ���� �Է¹��� ���ڸ� ���� 
	while(str[end]!=' '){
		if(end==str.length() || str[end]=='<')
			break;
		else
			++end;
	}
	
	for(int j=cnt;j<end;j++)
		s.push(str[j]);
	
	for(int j=cnt;j<end;j++){
		cout<<s.top();
		s.pop();
	}
	
	return end-1;
}

int prt_tag(int cnt){
	int end = cnt;
	while(str[++end]!='>'){} // used loop to find index 
		//++end;
	
	for(int j=cnt;j<=end;j++)
		cout<<str[j];
	
	return end;
}

int main(){
	int len;
	
	getline(cin, str); // getline : string library method  
	
	len = str.length();
	
	for(i=0;i<len;i++){
		if(str[i] == '<')
			i = prt_tag(i);
		else if(str[i]==' ')
			cout<<str[i];
		else
			i = rev_st(i);
	}

	return 0;
}
