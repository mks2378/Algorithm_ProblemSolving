#include <iostream>
using namespace std;

int main(){
	int N;
	
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=N-1;j>0;j--){
			if(j>i)
				cout<<' ';
			else
				cout<<'*';				
		}
		cout<<'*';
		for(int j=1;j<=N-1;j++){
			if(i<j)
				break;
			else
				cout<<'*';
		}
		cout<<'\n';
	}

	return 0;
}
