/*
[Usaco2008 Open]Cow Cars ��ţ�ɳ�
������ע���⼸�㣺ţ���ٶȲ�һ���������ޣ��ж���·��̰�ġ� 
		��ţ���ٶȴ�С�����������ο��ǣ�ÿ��ѡ��һ���������ٵļ��Ͽ��Ǽ��룬��Ϊ�Ǵ�С������ô���к����ţһ�����ڵ�ǰ��ţ������һ���ǳ��԰���ͷţ�Ž�ȥ�� 
		���������ٵļ��ϵ�����=ѡ����������������� 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,d,l,ans=0,s[50000+3]; 
int main(){
	scanf("%d%d%d%d",&n,&m,&d,&l);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)if(s[i]-d*(ans/m)>=l)ans++;
	printf("%d\n",ans);
	return 0;
}

