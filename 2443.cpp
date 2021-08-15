#include <iostream>
using namespace std;

int main(){
	int N;
	
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=1;j<N;j++){
			if(i<j)
				cout<<'*';
			else
				cout<<' ';	
		}
		cout<<'*';
		for(int j=N-1;j>0;j--){
			if(j>i)
				cout<<'*';
			else
				break;
		}
		cout<<'\n';
	}
	
	return 0;
}
