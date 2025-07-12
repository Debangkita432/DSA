#include <iostream>
#include <vector>
using namespace std;

bool ifvalid(vector<int> arr, int n, int m,int maxAllowed){
    int time=0,painter=1;

    for(int i=0;i<n;i++){
    if(time+arr[i]<=maxAllowed){
          time+=arr[i];
    }
    else{
        painter++;
        time=arr[i];
    }

}
  return painter <= m;
     
}


int paintedBoards(vector<int> arr, int n, int m){
   int sum =0 ,MaxVal= INT_MIN;
   if (m > n) 
        return -1;
   
   for(int i =0;i<n;i++){
    sum+=arr[i];
    MaxVal= max (MaxVal,arr[i]);
   }

   int st=MaxVal,end=sum,answer=-1;
   while (st <= end) {
   int mid=st+(end-st)/2;

    if(ifvalid(arr,n,m,mid)){
        answer=mid;
        end=mid-1;
    }
    else{
        st=mid+1;
    }
}


    return answer;
}



int main() {
    vector<int> arr = {40,30,10,20};
    int n = arr.size();//boards
    int m = 2; //painters
    cout << paintedBoards(arr, n, m) << "\n";  //min time ot paint all the boards
    return 0;
}