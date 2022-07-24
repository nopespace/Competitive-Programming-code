#include <bits/stdc++.h> 
//this is fucking tle
using namespace std; 
#define MAXN 200007
struct Node{
    int parent;
    vector<int> childs;
    int in_value;
    int vis;
};
void solve(){
    int n;
    scanf("%d", &n);
    Node node[MAXN];
    for(int i=1; i<=n; ++i){
        int a;
        scanf("%d", &a);
        node[i].parent=a;
        if(a!=i){
            node[a].in_value++;
            node[a].childs.push_back(i);
        }

    }
    vector<int> childlist;
    for(int i=1; i<=n; ++i){
        if(node[i].in_value==0){
            childlist.push_back(i);
        }
    }
    int len = childlist.size();
    printf("%d\n",len);
    for(int i = 0; i<len;++i){
        int path_len = 1;
        int path[MAXN];
        path[0]=childlist[i];
        node[path[0]].vis =1;
        while(node[path[path_len-1]].parent!=path[path_len-1]){
            if(node[node[path[path_len-1]].parent].vis==1){
                break;
            }
            path[path_len] = node[path[path_len-1]].parent;
            path_len++;
            // cout<<"i am"<<path[path_len-1]<<endl;
            // cout<<"par is"<<node[path[path_len-1]].parent<<endl;
            // cout<<"vis of it"<<node[path[path_len-1]].vis<<endl;
            node[path[path_len-1]].vis=1;
        } 
        printf("%d\n", path_len);
        for(int k = path_len -1; k > 0; --k){
            printf("%d ", path[k]);
        }
        printf("%d\n", path[0]);
    }
    printf("\n");
    memset(node,0,(n+7)*sizeof(Node));
    return;
}

int main(){
    int t;
    cin >> t;
    while(t){
        solve();
        t--;
    }
    return 0;
}