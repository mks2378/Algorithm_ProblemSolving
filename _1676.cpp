#include <iostream>
using namespace std;

// 0의 개수는 2와 5의 개수로 결정된다. 
// 특정 수까지의 팩토리얼 값에서는 5보다 2의 개수가 절대적으로 많기 때문에
// 적은 개수인 5의 개수가 곧 끝자리 0의 갯수 의미 
// 500이하에서 5, 25, 125가 5의 제곱수들이기 때문에 이들의 개수를 
// 잘 활용하여 개수를 세어주면 쉽게 풀 수 있다.  

int main(){
	int num, cnt=0;
	
	cin>>num;
	
//	for(int i=1;i<=num;i++){
//		if(i%5==0)
//			++cnt;
//		if(i%25==0)
//			++cnt;
//		if(i%125==0)
//			++cnt;
//	}

	for(int i=5;i<=num;i*=5)
		cnt+=num/i;
	
	cout<<cnt;
	
	return 0;
}

// to_string 가능한 수 범위 있다. 
//	str = to_string(result);
//	
//	for(int i=(str.length()-1);i>=0;--i){
//		++cnt;
//		if(str[i]!='0'){
//			--cnt;
//			break;	
//		}
//	}
//	cout<<cnt;
