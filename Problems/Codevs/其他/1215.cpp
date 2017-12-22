/*
รินฌ
*/
#include<cstdio>
#include<cstring>
using namespace std;
int map[18][18],n,m;
bool work(int a,int b){
	if((a==n)&&(b==n))return true;
	if(map[a][b]==0)return false;
	map[a][b]=0;
	return work(a+1,b)||work(a,b+1)||work(a-1,b)||work(a,b-1);
}
int main(){
	char c;
	scanf("%d\n",&m);
	for(int k=1;k<=m;k++){
		memset(map,0,sizeof(map));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("\n");
			for(int j=1;j<=n;j++){
				scanf("%c",&c);
				switch(c){
					case 's':case '.':case 'e':map[i][j]=1;break;
				}
			}
		}
		if(work(1,1))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
