#include <iostream>
using namespace std;

int N;
int main(){
	cin>>N;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<2*N-1;j++){
			if(i==0){
				if(j==N-1)
					cout<<'*';
				else if(j<N-1)
					cout<<' ';
			}
			else if(i==N-1){
				cout<<'*';
			}
			else{
				if(j==(N-1)-i)
					cout<<'*';
				else if(j==(N-1)+i)
					cout<<'*';
				else if(j<(N-1)+i)
					cout<<' ';
			}
		}
		if(i!=N-1)
			cout<<'\n';
	}
	
	return 0;
}
