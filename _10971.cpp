#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, start;
int Total=999999999;
int city[10][10];
bool visited[10];
vector<int> cost;

//�׷����� ��ȸ�Ϸ��� �⺻���� ������ ��ȸ ���� ��� ��   
//��� �ϳ� ���� ����� 0�� �ƴϾ�� �Ѵ�.(0�̸� �� �� ����.)
//������ ������ ��Ȯ�� �ľ����� ���Ͽ� �ذ����� ����  
void dfs(int cnt,int prev_idx,int cur_idx){
	if(cnt==N-2){		
		int sum=0;
		
		if(city[cur_idx][start]==0)
			return;
		
		for(int i=0;i<cost.size();i++)
			sum+=cost[i];
		sum+=city[cur_idx][start];
		
		Total = min(Total, sum);
		return;
	}
	
	for(int i=0;i<N;i++){
		if(!visited[i]&&city[cur_idx][i]!=0){
			visited[i] = true;
			cost.push_back(city[cur_idx][i]);
			dfs(cnt+1,cur_idx,i);
			cost.pop_back();
			visited[i] = false;
		}		
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>city[i][j];
	
	for(int i=0;i<N;i++){
		start = i;
		visited[i] = true;
		for(int j=0;j<N;j++){
			if(i!=j&&city[i][j]!=0){
				visited[j] = true;
				cost.push_back(city[i][j]);	
				dfs(0,i,j);
				cost.pop_back();
				visited[j] = false;
			}
		}
		visited[i] = false;
	}
	
	cout<<Total;
	return 0;
}
