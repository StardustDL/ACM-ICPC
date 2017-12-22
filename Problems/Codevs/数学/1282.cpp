/*
约瑟夫问题
分析：用vector模拟，非常好，
	  还可以用线段树，维护一个区间剩余的人数，不停跳跃区间 
*/
#include<cstdio>
#include<vector>
using namespace std;
vector<int> S;
int n,m,t=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)S.push_back(i);
	while(!S.empty()){
		t=(t+m-1)%S.size();
		printf("%d ",S[t]);
		S.erase(S.begin()+t);
	}
	return 0;
}

