/*
Լɪ������
��������vectorģ�⣬�ǳ��ã�
	  ���������߶�����ά��һ������ʣ�����������ͣ��Ծ���� 
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

