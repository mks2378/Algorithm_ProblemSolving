#include <iostream>
using namespace std;

int main(){
	int A, B, C;
	int result[4];
	
	cin>>A; cin>>B; cin>>C;
	
	result[0] = (A+B)%C;
	result[1] = ((A%C)+(B%C))%C;
	result[2] = (A*B)%C;
	result[3] =  ((A%C)*(B%C))%C;
	
	for(int i=0;i<4;i++)
		cout<<result[i]<<'\n';	
	return 0;
}
