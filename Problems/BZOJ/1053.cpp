/*
[HAOI2007]������ant
���������������������м�����֦ 
*/
#include<cstdio>
using namespace std;
int anst,a[15]={1,2,3,5,7,11,13,17,19,23,29,31};
long long ans,n;
int b[15]={1000};//��֤��һ����ֵ�㹻�� 
void dfs(int x,long long y,int cnt){
	y*=a[cnt];x=x/(b[cnt]+1)*(b[cnt]+2);//�����ϵ�cnt���������������ͱ�� x/(b[cnt]+1)*(b[cnt]+2);
	if(y>n||x<=anst&&y>=ans)return;//��֦�������ӽ��٣���ֵ�ϴ�����
	b[cnt]++;
	if(x>=anst)anst=x,ans=y;
	if(b[cnt+1]<b[cnt])dfs(x,y,cnt+1);//����ö�����Ӹ���ģ���Ϊ����ͨ��anst�����ܶ�С��������2~8��
	if(b[cnt]<b[cnt-1])dfs(x,y,cnt);//b[0]��Ӧ���� 
    b[cnt]--;
}
int main(){
	scanf("%d",&n);
	dfs(1,1,1);
	printf("%d\n",ans);
	return 0;
}
