#include <iostream>
#include <string>

using namespace std;
/*
length() 함수 -> 길이 반환 
cin.ignore(), fflush(stdin) -> 입력 버퍼 비우기  
cin으로 받고 getline으로 받으면 입력 버퍼 비워야 한다. 
단어 구분 기준이 space일 때, for 나 while 이면 끝나면서 string의 마지막 index를 알 수 있다. 
cstring은 '\n'도 포함하여 저장된다. string은 '\n' 제외하고 저장된다. 
*/
int main(){
	string str;
	int num;
	int end, start;
	
	cin>>num;
	cin.ignore(); //fflush(stdin); cin.ignore(256,'\n'); cin.ignore();
	int i,j;
	for(i=num;i>0;i--){
		getline(cin,str);
		start=0;
		for(j=0;j<str.length();j++){
			if(str[j]==' '){
				end = j-1;
				while(end>=start){
					cout<<str[end];
					end--;
				}
				cout<<" ";
				start = j+1;
			}
		}
		end = j-1;
		while(end>=start){
			cout<<str[end];
			end--;
		}
		cout<<"\n";
	}
	return 0;
}
