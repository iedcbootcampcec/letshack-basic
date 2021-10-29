#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int merge(vector <int> &arr,int s,int e){
	int i=s;
	int m =(s+e)/2;
	int j = m+1;
   vector <int> temp;
    vector <int> res;


   int cnt =0;
	while(i <= m and j <=e){
		    
		if(arr[i]<arr[j]){
			temp.push_back(arr[i]);
			i++;
		}else{
			cnt += (m-i+1);
			res.push_back(cnt);
			temp.push_back(arr[j]);
			j++;
		};

	};

   while(i <=m){
		temp.push_back(arr[i]);
		i++;
	}
	while(j <=e){
		temp.push_back(arr[j]);
		j++;
	};
   int k =0;
   for(int idx = s; idx <=e;idx++){
   	arr[idx] = temp[k++];
   }
   
   return cnt;
}

int mergeSort(vector <int> &arr,int s ,int e){
	if(s >= e){
		return 0;
	}

	int mid = (s+e)/2;
	int c1 = mergeSort(arr,s,mid);
	int c2 =mergeSort(arr,mid+1,e);
    int ci = merge(arr,s,e);

    //merge function
    return c1 +c2 + ci;

}

int main(){
	vector <int> arr{3,66,5,2,78,9};
	int s = 0;
	int e = arr.size()-1;
	cout << mergeSort(arr,s,e) <<endl;
    return 0;
}
