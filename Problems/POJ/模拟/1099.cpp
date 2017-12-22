/*
Square Ice
题意：模拟题，画冰中水分子排列形式的二维结构。 
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define M 1024
using namespace std;
char s[M][M];
int map[16][16],r,c,n;
void Run(){
	int x,y;
	for(int i=0;i<n;i++){
		x=i<<2;y=2;
		for(int j=0;j<n;j++,y+=4){
			s[x][y]='O';
			if(map[i][j]){
				if(map[i][j]==1){
					s[x][y-1]=s[x][y+1]='-';
					s[x][y-2]=s[x][y+2]='H';
				}
				else{
					s[x-1][y]=s[x+1][y]='|';
					s[x-2][y]=s[x+2][y]='H';
				}
			}
			else{
				if(s[x][y-2]=='H'){
					s[x][y+1]='-';
					s[x][y+2]='H';
				}
				else{
					s[x][y-1]='-';
					s[x][y-2]='H';
				}
				if(x<2||x>=2&&s[x-2][y]=='H'){
					s[x+1][y]='|';
					s[x+2][y]='H';
				}
				else{
					s[x-1][y]='|';
					s[x-2][y]='H';
				}
			}
		}
	}
}
void Answer(int t){
	printf("Case %d:\n\n",t);
	for(int i=0;i<c+2;i++)putchar('*');
	puts("");//打回车 
	for(int i=0;i<r;i++)printf("*%s*\n",s[i]);
	for(int i=0;i<c+2;i++)putchar('*');
	puts("\n");
}
int main(){
	int k=1;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&map[i][j]);
		r=(n<<2)-3;c=(n<<2)+1;
		for(int i=0;i<r;i++){
			memset(s[i],' ',sizeof(char)*c);
			s[i][c]=0;
		}
		Run();
		Answer(k++);
	}
	return 0;
}
