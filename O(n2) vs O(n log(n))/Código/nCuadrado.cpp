#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int n;
	cin>>n;
	pair <int, int> arr[n];
	int luz=1;
	int aux,aux2;
	
	
	

	// INGRESA LOS PARES AL ARREGLO 
	 for(int i = 0;i<n;i++){
	 	
	 	cin>>arr[i].first;
	 	cin>>arr[i].second;
	 }
	 
	auto start = chrono::high_resolution_clock::now();
	// ORDENA EL ARREGLO DE MENOR A MAYOR, TOMANDO EN CUENTA
	// EL PRIMER ELEMENTO DE CADA ARRELGO ARR[i].first
	
	for(int i =0;i<n;i++){
		for(int j=i+1;j<n;j++ ){
			if(arr[i].first>arr[j].first){
				aux=arr[i].first;
				aux2=arr[i].second;
				arr[i].first=arr[j].first;
				arr[i].second=arr[j].second;
				arr[j].first=aux;
				arr[j].second=aux2;
			}
		}
	}

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
	
	auto d = chrono::duration_cast<chrono::nanoseconds> (finish - start).count();
	cout <<"total time "<< d << " [ns]" << " \n";
	
	
	
	return 0;
}
