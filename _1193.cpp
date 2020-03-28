#include <iostream>
using namespace std;

int main(){
	int X;
	cin>>X;
	
	int i=1;
	while(true){
		if(i*(i+1)/2<X)
			i++;
		else{
			X = X-((i-1)*i/2);
			break;
		}
	}
	
	if(i%2==0)
		cout<<X<<"/"<<i-(X-1);	
	else
		cout<<i-(X-1)<<"/"<<X;

	return 0;
}
