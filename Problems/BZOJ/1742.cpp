/*
[Usaco2005 nov]Grazing on the Run ���ܱ߳Բ�
����������֤���κ�ʱ�̳Ե��Ĳݶ���һ�����䡣
		�����f[i,j,k]��ʾ�Ѿ��Ե�����i��ͷ��j��ݣ���ǰ����˵�/�Ҷ˵����С����ֵ֮��(�������Ե��ĺ�δ���Ե��ģ���Ȼ���Ե��ĸ���ֵ�Ͳ���������) 
		�����뵽����f[l][r][0..1]��ʾ���䱻���꣬Ȼ�������ң�����ֱ�������ռ�ᱬ��������ģ���ö�����䳤�ȣ��������Թ������� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=3000,INF=0x3f3f3f3f;
int opt[MAXN+3][2][2];
int n,p,a[MAXN+3];
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[++n]=p;
	sort(a+1,a+n+1);
	p=lower_bound(a+1,a+n+1,p)-a;
	memset(opt,INF,sizeof(opt));
	opt[p][1][0]=opt[p][1][1]=0;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n;i++)opt[i][len&1][0]=opt[i][len&1][1]=INF;
		for(int l=max(p-len+1,1);l<=min(p,n-len+1);l++){//����Ҫ��Խp 
			int r=l+len-1;
			if(l!=p)//l��pʱֻ�����Ҷ˵� 
                opt[l][len&1][0]=min(opt[l+1][~len&1][0]+(n-len+1)*abs(a[l]-a[l+1]),opt[l+1][~len&1][1]+(n-len+1)*abs(a[l]-a[r]));
            if(r!=p)//r��pʱֻ������˵� 
                opt[l][len&1][1]=min(opt[l][~len&1][0]+(n-len+1)*abs(a[l]-a[r]),opt[l][~len&1][1]+(n-len+1)*abs(a[r-1]-a[r]));
        }
    }
    printf("%d",min(opt[1][n&1][0],opt[1][n&1][1]));
	return 0;
}

