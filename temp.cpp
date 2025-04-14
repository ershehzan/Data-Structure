#include<iostream>
using namespace std;
int main() {

int arr[100]={12, 23, 34, 45, 56, 67, 78, 89, 90};


int start=0,end=9-1;

while(start<end){
    swap(arr[start],arr[end]);
    start++;
    end--;
}
cout<<"Reversed array is: "<<endl;
for(int i=0;i<9;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}
