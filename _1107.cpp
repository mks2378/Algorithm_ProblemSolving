#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 987654321;
const int MAX = 1000000+1;

int N,M;
vector<int> broken;

//���� ä�ο��� �ٲٴ� ���
int changeFromHundred(){
	return abs(N-100);
}

//�ش� ä���� ������ ���� �������� ����
//���峭 ��ư�� ������ false 
bool possible(int num){
	if(num==0)
		if(find(broken.begin(),broken.end(),0)==broken.end())
			return true;
		else
			return false;
	
	while(num){
		if(find(broken.begin(), broken.end(), num%10)!=broken.end())
			return false;
		num/=10;		
	}
	return true;
}

// ���� ä���� ���� 
int length(int num){
	//0�̸� ���� 1(�߿��� ����ó��) 
	if(num==0)
		return 1;
	
	int result = 0;
	while(num){
		num/=10;
		result++;		
	}
	return result;	
}

//100���� ������ �ƴ� ä���� ������ ���� +/-
int changeEntirely(){
	int result = INF;
	int similar = 0;
	
	for(int i=0;i<MAX;i++){
		//�ش� ä���� ���� �� �ִٸ�
		if(possible(i)){
			int click = abs(N-i); // +/-�� �� �� ������ �ϴ��� Ȯ�� 
			if(result>click){ // �� Ŭ���ص��ȴٸ�  
				result = click;
				similar = i; // �ش� ���� ����  
			}
		}		
	}
	return result+length(similar);
}

int main(){
	cin>>N>>M;
	
	for(int i=0;i<M;i++){
		int button;
		cin>>button;
		broken.push_back(button);		
	}
	
	cout<<min(changeFromHundred(), changeEntirely())<<'\n';	
	
	return 0;
}
