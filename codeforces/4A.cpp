//
// Created by Ashley Gao on 2022-04-26.
//

#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%2 == 0&&n!=2){
        cout<<"YES";
    }
    else
        cout<<"NO";
}