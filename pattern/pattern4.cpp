#include<iostream>
using namespace std;
int main(){
    int n;
    cout <<"enter no";
    cin>>n;
    int row=1;
   
    while(row<=n){
        int j=1;
        int count=1;
        while (j<=row)
        {
           cout<<count;
            count++;
           j++; /* code */
        }
       cout<<endl;
       row++; 
    }
}