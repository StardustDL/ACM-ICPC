/*
[Usaco2006 Nov]Big Square �޴�������
���������� ��ö�������㣬��������Ϊ�����ε�һ���ߣ�������������㣨ע�������ַ������ֱ������ࣩ����֤�������� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100*2,INF=0x3f3f3f3f;//û���г���n�����Կ����� 
int mp[MAXN+3][MAXN+3],n,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
        	char ch=getchar();while(ch!='J'&&ch!='B'&&ch!='*')ch=getchar();
        	if(ch=='J') mp[i][j]=2;
        	else if(ch=='*') mp[i][j]=1;
    }

    for(int x=1;x<=n;x++){//ö��һ���� 
		for(int y=1;y<=n;y++){
			if(mp[x][y]!=2)continue;
        	for(int i=1;i<=n;i++){ 
				for(int j=1;j<=n;j++){//ö����һ���㣬ע��������Ѿ�����J��Ҳ������û��ţ����Ϊ Bessie���Ǳ��������Ϊ�����ε��ĸ�����֮һ
					if(x==i&&y==j || mp[i][j]==0)continue; 
            		int l=i-x,r=j-y;
					if(l*l+r*r<ans) continue;
					if(i-r>=0 && j+l>=0 && x-r>=0 && y+l>=0 && mp[i-r][j+l]==2 && mp[x-r][y+l]==2)ans=l*l+r*r;
					if(i+r>=0 && j-l>=0 && x+r>=0 && y-l>=0 && mp[i+r][j-l]==2 && mp[x+r][y-l]==2)ans=l*l+r*r;
				}
			}
		}
	}
	printf("%d\n",ans);
    return 0;
}
