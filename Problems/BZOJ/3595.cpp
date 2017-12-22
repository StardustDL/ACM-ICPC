/*
������treap��ֱ�Ӱ����ġ���������������ؼ��־����ˣ��ᵽǰ��ľ��Ǹ��ģ���ʵ����������sz��ע�������Щû�г��ֵĵ� 
		����map����ÿ����Ŷ�Ӧ������ؼ��� ÿ�β��Ҿ����ˡ� 
		��ʼ�����ֻ��һ���ڵ����[1, n]�������䣬��������Ҫ�ƶ�һ�����Ϊi�û�ʱ�����Ǿͽ�����ڵ��ֳ�[1, i-1]��[i, i]��[i+1, n]�����ڵ㣬Ȼ��Ϳ��Խ��в����ˡ�
		��Ϊ�ռ俪���� ���԰�map[x]=0������������ı�ž����Լ����� ���Բ����õ�0��Ϊ����ؼ���
*/
#include <cstdio>
#include <iostream>
#include <map>
#include <cstdlib>
using namespace std;
const int INF = 0x3f3f3f3f;
map <int,int> m;
int cnt=1;
struct treap{
	struct node{
		node *lc, *rc;
		int s, id, r, L, R;
	}t[300055], *null, *root;
	void init(){
		null = &t[0]; null -> lc = null -> rc = null;
		null -> s = 0; null -> id = null -> L = null -> R = null -> r = -INF;
		root = null;
	}
	node *NewNode(int index, int L, int R){
		t[cnt].lc = t[cnt].rc = null; t[cnt].r = rand();
		t[cnt].id = index; t[cnt].L = L; t[cnt].R = R; t[cnt].s = R - L + 1;
		return &t[cnt++];
	}
	void pushup(node *&p){ p->s = p->lc->s + p->rc->s + (p->R-p->L+1);}
	void maintain(node *&p){
		if(p->lc->r > p->r){
			node *temp=p->lc;
			p->lc=temp->rc;
			temp->rc=p;
			pushup(p);p=temp;
		} 
		else if(p->rc->r>p->r){
			node *temp=p->rc;
			p->rc=temp->lc;
			temp->lc=p;
			pushup(p);p=temp;
		}
		pushup(p);
	}
	void insert(node *&p, int L, int R, int index){
		if(p == null){
			p = NewNode(index, L, R);
			return;
		}
		if(R < p -> L) insert(p -> lc, L, R, index);
		else insert(p -> rc, L, R, index);
		maintain(p);
	}
	void merge(node *&ne, node *p, node *q){
		if(p == null || q == null){
			ne = p == null ? q : p;
			return;
		}
		if(p->r > q->r) { ne = p; merge(ne->rc, p->rc, q); }
		else{ ne = q; merge(ne->lc, p, q->lc); }
		pushup(ne);
	}
	void del(node *&p, int pos){
		if(p == null) return;
		if(p->L <= pos && pos <= p->R){
			/*if(p->L == p->R) merge(p, p->lc, p->rc); // ��֤ʵ����Ǵ�ġ����������������˲�����2333
			else */if(p->L == pos) { ++ p -> L; ++ p -> id; pushup(p); }
			else if(p->R == pos) { -- p -> R; pushup(p); }
			else{
				insert(p -> rc, pos + 1, p -> R, pos + 1);
				p -> R = pos - 1; pushup(p);
			}
			return;
		}
		if(p->L > pos) del(p -> lc, pos);
		else del(p -> rc, pos); maintain(p);
	}
	
	int getrank(node *p, int pos){
		if(p == null) return 0;
		if(p->L <= pos && pos <= p->R) return (pos - p->L + 1) + p->lc->s;
		if(p->L > pos) return getrank(p->lc, pos);
		else return getrank(p->rc, pos) + p->lc->s + (p->R - p->L + 1);
	}
	
	int getindex(node *p, int k){
		if(p == null) return 0;
		int lsize = p->lc->s; 
		if(k <= lsize) return getindex(p->lc, k);
		if(lsize < k && lsize + (p->R - p->L + 1) >= k){
			if(p->L == p->R) return p->id;
			else return k-lsize-1 + p->L;
		}
		else return getindex(p->rc, k - lsize - (p->R - p->L + 1));
	}
}t;
int N, M;
int main(){
	srand(20160313);t.init();
	scanf("%d",&N); t.insert(t.root, 1, N, 1);
	int mmin = 0, mmax = N, a = 0; 
	for(scanf("%d",&M); M--; ){
		int sign,x,y;
		scanf("%d%d",&sign,&x); x -= a;
		if(sign == 1){
			scanf("%d",&y); y -= a;
			int pos = m[x]; if(!pos) pos = x;
			printf("%d\n", a = t.getrank(t.root, pos));
			t.del(t.root, pos); 
			t.insert(t.root, pos, pos, y); 
			m[x]=0;m[y]=pos;
		}
		else if(sign == 2){
			int pos = m[x]; if(!pos) pos = x;
			printf("%d\n", a = t.getrank(t.root, pos));
			t.del(t.root, pos);m[x]=pos=--mmin;
			t.insert(t.root,pos,pos,x);
		}
		else if(sign == 3){
			int pos=m[x];if(!pos)pos=x;
			printf("%d\n",a=t.getrank(t.root, pos));
			t.del(t.root, pos);m[x]=pos=++mmax;
			t.insert(t.root, pos, pos, x);
		}
		else printf("%d\n", a = t.getindex(t.root, x));
	}
	return 0;
}

