//Link:https://atcoder.jp/contests/abc242/tasks/abc242_g
/*
*   -------------- ?*?*? --------------
* |         In The Name of *Allah*     |
* |             Author : Tarik         |
* |                                    |
*  -------------- ?*?*? ---------------
*/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define  pb        push_back
#define  all(v)    v.begin(),v.end()
#define  endl       '\n'  
#define  uint       long long
#define  int        long long
#define  BLOCK        700
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; 

const int mxn=1e6+123;
int a[mxn],ans[mxn],freq[mxn];
int total=0;
struct query{
	int l;
	int r;
	int i;
};
query Q[mxn];
bool cmp(query a,query b){
	if(a.l/BLOCK!=b.l/BLOCK)return a.l/BLOCK<b.l/BLOCK;
	else return a.r<b.r;
}
int get(int n){
	return n/2;
}
void add(int pos){
	total-=get(freq[a[pos]]);
	freq[a[pos]]++;
	total+=get(freq[a[pos]]);
}
void remove(int pos){
	total-=get(freq[a[pos]]);
	freq[a[pos]]--;
	total+=get(freq[a[pos]]);
}
void solve(){
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].i=i;
	}
	sort(Q+1,Q+q+1,cmp);
	
	int ml=0,mr=-1;
	for(int i=1;i<=q;i++){
		int L=Q[i].l;
		int R=Q[i].r;
		while(ml>L){
			ml--,add(ml);
		}
		while(mr<R){
			mr++,add(mr);
		}
		while(ml<L){
			remove(ml),ml++;
		}
		while(mr>R){
			remove(mr),mr--;
		}
		ans[Q[i].i]=total;
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
	cout<<endl;
	
 
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
