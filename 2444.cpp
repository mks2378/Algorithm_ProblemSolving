#include <iostream>
using namespace std;

int main(){
	int N;
	
	cin>>N;
	for(int i=0;i<2*N-1;i++){
		if(i<N-1){
			for(int j=N-1;j>0;j--){
				if(i<j)
					cout<<' ';
				else
					cout<<'*';	
			}
			cout<<'*';
			for(int j=0;j<N-1;j++){
				if(i>j)
					cout<<'*';
				else
					break;	
			}
		}
		
		else if(i==N-1){
			for(int i=1;i<2*N;i++)
				cout<<'*';
		}
		
		else{
			for(int j=N;j<2*N-1;j++){
				if(i<j)
					cout<<'*';
				else
					cout<<' ';	
			}
			cout<<'*';
			for(int j=2*N-2;j>=N;j--){
				if(j>i)
					cout<<'*';
				else
					break;
			}			
		}
		cout<<'\n';
	}
	
	return 0;
}
