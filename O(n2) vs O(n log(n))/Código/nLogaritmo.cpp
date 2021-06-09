#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int n;
	cin>>n;
	pair <int, int> arr[n];
	int luz=1;
	

	// INGRESA LOS PARES AL ARREGLO 
	 for(int i = 0;i<n;i++){
	 	
	 	cin>>arr[i].first;
	 	cin>>arr[i].second;
	 }
	 
		auto start = chrono::high_resolution_clock::now();

	// ORDENA EL ARREGLO DE MENOR A MAYOR, TOMANDO EN CUENTA
	// EL PRIMER ELEMENTO DE CADA ARRELGO ARR[i].first
	
	sort(arr, arr+n); 

	
	
	
	int z=0;
	
	for(int j=1;j<n;j++){
		if(arr[z].second<=arr[j].first){
			z=j;
			luz++;
		}
		else if(arr[z].second<=arr[j].second){
			z=j;
		
		}
	}
	
	
	cout<<luz<<endl;
	
	

   auto finish = chrono::high_resolution_clock::now();  
	
	auto duration = chrono::duration_cast<chrono::nanoseconds> (finish - start).count();
	cout <<"total time "<< duration << " [milliseconds]" << " \n";
	
	
	
	
	
	return 0;
}