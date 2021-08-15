#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 순열 방법으로 모든 경우의 수를 구한 후, 부등호 조건을 
// 만족하는 경우를 찾아 그 중 최대 최소를 구한다.  
// https://yabmoons.tistory.com/104
// cf) permutation 함수 이용: https://jaimemin.tistory.com/758

int K;
char inequality[10];
bool selected[10];

vector<string> answer;
vector<char> v;

//부등호 비교 방법  
bool Check(int idx, char c){
	if(c=='<'){
		if(v[idx]<v[idx+1]) return true;
		else return false;	
	}
	else if(c=='>'){
		if(v[idx]>v[idx+1]) return true;
		else return false;
	}
}

bool Calculate(){
	for(int i=0;i<K;i++)
		if(Check(i,inequality[i])==false)
			return false;	
	return true;
}

void dfs(int cnt){
	if(cnt==K+1){
		// if안에서 함수 이용하여 조건 만족 여부 판단  
		if(Calculate()==true){ 
			string s_tmp="";
			for(int i=0;i<=K;i++)
				s_tmp+=v[i];
			answer.push_back(s_tmp);	
		}
		return;
	}
	
	for(int i=0;i<10;i++){
		if(!selected[i]){
			selected[i] = true;
			v.push_back(i+'0');
			dfs(cnt+1);
			v.pop_back();
			selected[i] =false;			
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>K;
	for(int i=0;i<K;i++)
		cin>>inequality[i];
	
	dfs(0);
	// string 숫자도 sorting 가능(문자 하나씩 비교후 정렬)  
	sort(answer.begin(), answer.end());
	cout<<answer[answer.size()-1]<<'\n';
	cout<<answer[0];
	
	return 0;
}
