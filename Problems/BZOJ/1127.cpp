/*
[POI2008]KUP
�����������Ӧ����Ȩֵ�Ǹ��ɣ���Ȼ����û�취����
	  ���ȿ���1*n�����
		�������[k,2k]֮��ĵ㣬ֱ�����
		�����������һ�����������>=k������Ԫ��<k ���н� �����޽�
		�������Ȼ ��Ϊ����������Ԫ�ض�<k ���ǰ׺�Ͳ����Խ[k,2k]ֱ�ӵ���(2k,+��)
		��ô���ǰ����������չ����ά Ҳ�ǶԵ�
		֤�����������һ���Ӿ��������>=k������Ԫ��<k����ô��
		�������Ӿ��εĺ�<=2k����ô��������ֱ�����
		��������Ӿ��εĺ�һ��>2k
		�������ۣ�
		�������Ӿ���ֻ��һ�У���ôͬ�����������
		��������ȡ����������Ϸ���һ�к����·���һ��
		��֪һ������һ�еĺ�<=�������εĺ͵�һ��
		��ô���ǰ���һ�п��� �����������εĺ�>2k ��˿�������εĺ�һ��>k
		�������޿���ȥ������һʱ�̾��εĺͻ�<=2k����ʱֱ���������

		��>2k�ĵ��ж�Ϊ���㣬�����߷�/�������и�����еļ����Ӿ��Σ������жϼ���
		ʱ�临�Ӷ�O(n^2) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
int mp[MAXN+3][MAXN+3],n,K,h[MAXN+3],sum[MAXN+3][MAXN+3];
long long getsum(int x1,int y1,int x2,int y2){  
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];  
}
void output(int x1,int y1,int x2,int y2){  
    while(getsum(x1,y1,x2,y2)>K*2){  
        if(x1==x2)y2--;  
        else{  
            if(getsum(x1+1,y1,x2,y2)>=K)x1++;  
            else x2--;
        }
    }  
    printf("%d %d %d %d\n",y1,x1,y2,x2);
    exit(0);
}  
void getmax(int base){
	static int sta[MAXN+3],top,l[MAXN+3],r[MAXN+3],i;//����ÿ��λ��i�������ұ���h[i] �߶ȵ������ 
	for(top=0,i=1;i<=n+1;i++){
		while(top && h[sta[top]]>h[i])r[sta[top--]]=i-1;
		sta[++top]=i;
	}
	for(top=0,i=n;~i;i--){
		while(top && h[sta[top]]>h[i])l[sta[top--]]=i+1;
		sta[++top]=i;
	}
	for(i=1;i<=n;i++)
		if(h[i]){  
            if(getsum(base-h[i]+1,l[i],base,r[i])>=K)output(base-h[i]+1,l[i],base,r[i]);  
        }
}
int main(){
	scanf("%d%d",&K,&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		scanf("%d",&mp[i][j]);
		if(mp[i][j]>=K && mp[i][j]<=K*2){
			printf("%d %d %d %d\n",j,i,j,i);  
			return 0;
		}
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)h[j]=mp[i][j]>K*2?0:h[j]+1;
		getmax(i);
	}
	puts("NIE");
	return 0;
}

