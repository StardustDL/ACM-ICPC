/*
COURSES
���⣺����p�ſγ̺�n��ѧ����һ��ѧ������ѡ0�ţ�1�ţ����߶��ſγ̣�����Ҫ��һ����p��ѧ����ɵļ��ϣ���������2��������
	  1.ÿ��ѧ��ѡ��һ����ͬ�Ŀγ̣�2.ÿ���γ̶��в�ͬ�Ĵ���������㣬�����YES
����������ͼ���ƥ�䡣ע��Ҫ�������ֵ� 
*/
#include<cstdio>
#include<cstring>
#include<bitset>
#include<vector>
using namespace std;
const int MAXL=100,MAXP=300,INF=0x3f3f3f3f;
const char OUT[2][5]={"NO","YES"};
vector<int> g[MAXL+3];//������󲿵�������Ҳ���
int link[MAXP+3];//������Ҳ����Ӧ���󲿵� 
bitset<MAXP+3> vis;//������Ҳ�����û�б����� 
bool find(int u){
	for(int i=0;i<g[u].size();i++){
		if(!vis[g[u][i]]){
			vis[g[u][i]]=1;
			if(!link[g[u][i]] || find(link[g[u][i]])){link[g[u][i]]=u;return true;}
		}
	}
	return false;
}
int lesson,stu;
int maxp(){
	memset(link,0,sizeof(link));
	int ans=0;
	for(int i=1;i<=lesson;i++)vis=0,ans+=find(i);
	return ans;
}
int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&lesson,&stu);
		for(int i=1,c,t;i<=lesson;i++){
			g[i].clear();
			for(scanf("%d",&c);c;c--){
				scanf("%d",&t);
				g[i].push_back(t);
			}
		}
		puts(OUT[maxp()==lesson]);
	}
	return 0;
}

