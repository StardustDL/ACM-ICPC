/*
[HAOI2008]ÒÆ¶¯Íæ¾ß
·ÖÎö£ºBfs 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int xx[4]= {0,0,1,-1},yy[4]= {1,-1,0,0};
bool mark[1<<16];
struct data {
	bool a[5][5];
	int step;
} q[1<<16],ans,start;
int hash(data &d) {
	int k=1,s=0;
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++) {
			s+=k*d.a[i][j];
			k<<=1;
		}
	return s;
}
int bfs(data &S,data &T){
	int t=0,w=1;
	q[t]=S;
	int bg=hash(S),ed=hash(T);
	if(bg==ed)return 0;
	mark[bg]=1;
	int x,y;
	while(t<w) {
		for(int i=1; i<=4; i++)
			for(int j=1; j<=4; j++) {
				if(q[t].a[i][j]==0)continue;
				for(int k=0; k<4; k++) {
					x=i+xx[k],y=j+yy[k];
					if(q[t].a[x][y]||x>4||y>4||x<1||y<1)continue;
					swap(q[t].a[i][j],q[t].a[x][y]);
					int h=hash(q[t]);
					if(!mark[h]) {
						if(h==ed)return q[t].step+1;
						mark[h]=1;
						q[w]=q[t];q[w].step=q[t].step+1;
						w++;
					}
					swap(q[t].a[i][j],q[t].a[x][y]);
				}
			}
		t++;
	}
}
int main() {
	char ch[5];
	for(int i=1; i<=4; i++) {
		scanf("%s",ch);
		for(int j=1; j<=4; j++)start.a[i][j]=ch[j-1]-'0';
	}
	for(int i=1; i<=4; i++) {
		scanf("%s",ch);
		for(int j=1; j<=4; j++)ans.a[i][j]=ch[j-1]-'0';
	}
	printf("%d\n",bfs(start,ans));
	return 0;
}
