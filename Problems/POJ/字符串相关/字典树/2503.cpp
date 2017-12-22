/*
Babelfish
分析：字典树，尾节点记录单词 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<string>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000000,NS=26;
#define id(x) (x-'a')
struct Trie{
	string dat[MAXN+3];
	int ch[MAXN+3][NS],tot;
	
	void init(){
		tot=0;
		memset(ch,0,sizeof(ch));
	}
	
	void insert(char* str,string s){
		int cur=0;
		int len=strlen(str);
		for(int i=0;i<len;i++){
			if(ch[cur][id(str[i])]==0)ch[cur][id(str[i])]=++tot;
			cur=ch[cur][id(str[i])];
		}
		dat[cur]=s;
	}
	
	string search(char *str){
		int cur=0;
		int len=strlen(str);
		for(int i=0;i<strlen(str);i++){
			if(ch[cur][id(str[i])]==0)return "eh";
			cur=ch[cur][id(str[i])];
		}
		return dat[cur];
	}
}T;
char str[33];
string s;
int main(){
	//T.init();
	T.tot=0;
	while(gets(str)){
		//cout<<str<<endl;
		if(strcmp(str,"")==0){/*cout<<"!!!"<<endl;*/break;}
		int i,len=strlen(str);
		for(i=0;i<len;i++){
			if(str[i]==' '){
				str[i++]='\0';
				break;
			} 
		}
		s=str;
		//cin>>s;
		T.insert(str+i,string(str));
	}
	while(cin>>str){
		cout<<T.search(str)<<endl;
	}
	return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
const int maxnode=1000000+100;
const int sigma_size=26;
struct Trie
{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    string str[maxnode];
    int sz;
    void init()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
        val[0]=0;
    }
    void insert(char *s,string ss)
    {
        int n=strlen(s),u=0;
        for(int i=0;i<n;i++)
        {
            int id=s[i]-'a';
            if(ch[u][id]==0)
            {
                ch[u][id]=sz;
                val[sz]=0;
                memset(ch[sz],0,sizeof(ch[sz]));
                sz++;
            }
            u=ch[u][id];
        }
        str[u]=ss;
        val[u]=1;
    }
    string find(char *s)
    {
        int n=strlen(s),u=0;
        for(int i=0;i<n;i++)
        {
            int id=s[i]-'a';
            if(ch[u][id]==0)
            {
                return string("eh");
            }
            u=ch[u][id];
        }
        return str[u];
    }
}trie;
char word[2][30];
char s[50];
int main()
{
    trie.init();
    while(gets(s))
    {
        if(strcmp(s,"")==0)
            break;
        int len=strlen(s);
        int i,j;
        for(i=0;i<len;i++)
        {
            if(s[i]==' ')
                break;
            word[0][i]=s[i];
        }
        word[0][i]=0;
        i++;
        for(j=0;j+i<len;j++)
            word[1][j]=s[j+i];
        word[1][j]=0;
        trie.insert(word[1],string(word[0]));
    }
    while(gets(s))
    {
        cout<<trie.find(s)<<endl;
    }
    return 0;
}

*/

