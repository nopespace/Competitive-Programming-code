//
// Created by Ashley Gao on 2022-04-26.
//
#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define MAXCHAR 1000007
int n;
char c;
string x;
int first_al = 0;
int first_num = 0;
int second_al = 0;
int second_num = 0;
int flag_al = 0;
int flag_num = 0;

void init(){
    first_al = 0;
    first_num = 0;
    second_al = 0;
    second_num = 0;
    flag_al = 0;
    flag_num = 0;
}

int convert_slice(const char *s, size_t a, size_t b) {
    int val = 0;
    while (a < b) {
       val = val * 10 + s[a++] - '0';
    }
    return val;
}

void process(){
    init();
    cin>>x;
    for(int i = 0; i <= x.size(); ++i){
        char c = x[i];
        if(isalpha(c)){
            if(flag_al==0){
                // x[first_al] = c;
                first_al++;
            }
            else{
                flag_num = 1;
                // x[first_al+first_num+second_al] = c;
                second_al++; 
            }
        }
        else if(isdigit(c)){
            if(flag_num==0){
                flag_al = 1;
                // x[first_al+first_num] = c;
                first_num++;
            }
            else{
                // x[first_al+first_num+second_al] = c;
                second_num++;
            }
        }
    }
}
void translate_to_twonum(){
    // BC23 to R23C55
    int cnt = 0;
    for(int i = 0; i < first_al; ++i){
        char t = x[i];
        int num1 = t - '@';
        cnt = cnt * 26;
        cnt += num1;
    }
    cout<<"R"<<x.substr(first_al, x.size())<<"C"<<cnt<<endl;
}

void translate_to_onenum(){
    // R23C55 to BC23
    string tmp_num = x.substr(1, first_num);
    int f_num = stoi(tmp_num);
    tmp_num = x.substr(first_al+first_num+1);
    int s_num = stoi(tmp_num);
    string tmp;
    while(s_num > 0){
        s_num -= 1;
        char reminder = 'A' + (s_num % 26);
        s_num = s_num/26;
        tmp = reminder + tmp;
    }
    cout<<tmp<<f_num<<endl;
}

int main(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        process();
        if(second_num == 0){
            translate_to_twonum();
        }
        else{
            translate_to_onenum();
        }
    }
}