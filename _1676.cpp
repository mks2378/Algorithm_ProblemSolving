#include <iostream>
using namespace std;

// 0�� ������ 2�� 5�� ������ �����ȴ�. 
// Ư�� �������� ���丮�� �������� 5���� 2�� ������ ���������� ���� ������
// ���� ������ 5�� ������ �� ���ڸ� 0�� ���� �ǹ� 
// 500���Ͽ��� 5, 25, 125�� 5�� ���������̱� ������ �̵��� ������ 
// �� Ȱ���Ͽ� ������ �����ָ� ���� Ǯ �� �ִ�.  

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

// to_string ������ �� ���� �ִ�. 
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
