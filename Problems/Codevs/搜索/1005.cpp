/*
��������
���⣺�õ�һ����С��K��ʹ�ÿ��Ե���m�֣�ÿ��k�ŵĺ�����
������ö��K����֤���ڵ�ǰ��K�ܷ���һ�ֺ��ʵķ�������֤��DFS���ɣ���ע�⼸�㣺
		1.�����ɳ�ÿ�ֱ��ӵĸ������ټ�����֤ 
		2.�����֦��Ԥ�����ÿ�ֱ���������ֽ���ж��٣�DFS�����ж���û�п��ܳ���K������ޡ�
		3.DFS������һ��д����ʵʱ����ÿ��ֽ�ŵ����������������������ʧ����Ҳ���и�ǿ�ļ�֦
			ÿ�αȽϵ�ǰ������K��һ��������������ѭ������Ŀǰ�޷�ȷ�������ַ����ĸ��Ӷ�����
��ע����д�ķ���2��Ȼ��û���������Ǹĳ��˷���1������֮��ʱ�����Ǽ��˼�֦
2015.2.20 30min 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=13;
typedef int sta[MAXN];
int n,m,a[MAXN][MAXN],b[MAXN],k;
bool flag;
sta T,S;
void dfs(int ind){
	if(ind>n){
		memset(S,0,sizeof(S));
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				S[j]+=T[i]*a[i][j];
			}
			if(S[j]!=k)return;
		}
		flag=true;return;
	}
	for(int i=0;i<=b[ind];i++){
		if(flag)return;
		if(i*a[ind][12]>k)break;
		T[ind]=i;
		dfs(ind+1);
	}
} 
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int &t=a[i][12];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			t=max(t,a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)cin>>b[i];
	for(k=1;m*k<=1000;k++){
		memset(T,0,sizeof(T));
		dfs(1);
		if(flag){
			cout<<k*m<<endl;
			return 0;
		}
	}
	cout<<"alternative!";
	return 0;
} 
