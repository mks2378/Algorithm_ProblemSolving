#include <iostream>
using namespace std;

int cnt;

int main(){
	int N;
	cin>>N;
	
	for(int i=1;i<=N;i++){
		if(i/10==0){
			cnt+=1;
			continue;
		}
		else if(i/100==0){
			cnt+=2;	
			continue;
		}
		else if(i/1000==0){
			cnt+=3;	
			continue;
		}
		else if(i/10000==0){
			cnt+=4;	
			continue;
		}
		else if(i/100000==0){
			cnt+=5;	
			continue;
		}
		else if(i/1000000==0){
			cnt+=6;	
			continue;
		}
		else if(i/10000000==0){
			cnt+=7;	
			continue;
		}
		else if(i/100000000==0){
			cnt+=8;	
			continue;
		}
		else if(i/1000000000==0){
			cnt+=9;
			continue;
		}
		else
			cnt+=10;
	}
	cout<<cnt;
	
	return 0;
}
