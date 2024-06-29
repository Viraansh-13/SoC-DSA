// Code can rotate in both directions by any number of elements

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void leftrotate(int arr[],int n, int num){
    int temp_arr[n];


    for (size_t i = 0; i < n; i++)
    {
        temp_arr[i] = arr[(i+num)%n];

    }
    for (size_t i = 0; i < n; i++)
    {
        cout<<temp_arr[i];
    }
    cout<<endl;

}

void rightrotate(int arr[],int n, int num){
    int temp_arr[n];


    for (size_t i = 0; i < n; i++)
    {
        temp_arr[i] = arr[(n*100+(i-num))%n];

    }
    for (size_t i = 0; i < n; i++)
    {
        cout<<temp_arr[i];
    }
    cout<<endl;

}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int num = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    char direction;
    cin>>direction;
    if(direction == 'l'){
    leftrotate(arr,n,num);
    }
    else if(direction == 'r'){
        rightrotate(arr,n,num);
    }


}