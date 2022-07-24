#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; ++i){
        int tmp[200007];
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; ++j){
            scanf("%d", &tmp[j]);
        }
        int first = tmp[0];
        int flag = 0;
        if(m%2==0){
            int keep_max = max(tmp[0],tmp[1]);
            for(int i=2; i < m; i+=2){
                int keep_min = min(tmp[i], tmp[i+1]);
                if(keep_max>keep_min){
                    flag = 1;
                    break;
                }
                keep_max = max(tmp[i], tmp[i+1]);
            }
        }
        else{
            int keep_max = tmp[0];
            for(int i=1; i < m; i+=2){
                int keep_min = min(tmp[i], tmp[i+1]);
                if(keep_max>keep_min){
                    flag = 1;
                    break;
                }
                keep_max = max(tmp[i], tmp[i+1]);
            }
        }
        if(flag == 1){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
}

}
