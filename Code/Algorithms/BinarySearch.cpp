#include<iostream>

using namespace std;

int BinarySearch(int arr[], int size, int key){
    int strt = 0, end = size;
    while(strt<=end){
        int mid = (strt+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            strt = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
int n;
cout<<"Enter the size of the array:"<<endl;
cin>>n;

int array[n];
cout<<"Enter the elements of the array:"<<endl;
for(int i=0; i<n; i++){
    cin>>array[i];
}

int key;
cout<<"Enter the key to be searched:"<<endl;
cin>>key;

cout<<"The required index is: "<<BinarySearch(array, n, key);
return 0;
}
