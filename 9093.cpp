#include <iostream>
#include <string>

using namespace std;
/*
length() �Լ� -> ���� ��ȯ 
cin.ignore(), fflush(stdin) -> �Է� ���� ����  
cin���� �ް� getline���� ������ �Է� ���� ����� �Ѵ�. 
�ܾ� ���� ������ space�� ��, for �� while �̸� �����鼭 string�� ������ index�� �� �� �ִ�. 
cstring�� '\n'�� �����Ͽ� ����ȴ�. string�� '\n' �����ϰ� ����ȴ�. 
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
