#include <iostream>

using namespace std;

// 20억 숫자는 long long 타입 사용 
// 값이 20억이면 O(n)도 시간 초과 나온다  
// 숫자 곱의 결과가 unsigned long long 넘어가면 
// 다 곱한 결과로 푸는게 아니라 약수의 개수로 푸는 방법으로 우회 
// nCm은 2이 개수가 더 적을수 있기 때문에 5,2 개수 중 작은 것 택 

int count_5(long long num){
	int count=0;
	
	for(long long i=5;i<=num;i*=5)
		count+=(num/i);
	
	return count;	
}

int count_2(long long num){
	int count=0;
	
	for(long long i=2;i<=num;i*=2)
		count+=(num/i);	
	
	return count;
}

int main(){
	long long n, m;
	int cnt_5, cnt_2;
	int result;
	
	cin>>n; cin>>m;
	
	cnt_5 = count_5(n);
	cnt_5 -= (count_5(m)+count_5(n-m));
	
	cnt_2 = count_2(n);
	cnt_2 -= (count_2(m)+count_2(n-m));
	
	result = cnt_2<cnt_5?cnt_2:cnt_5;
	
	cout<<result;
	
	return 0;
}
