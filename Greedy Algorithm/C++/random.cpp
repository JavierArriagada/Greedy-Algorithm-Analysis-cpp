#include<bits/stdc++.h>

using namespace std;

int coloresTotales=0;


struct Actividades{


    int id;
    int inicio;
    int fin;
    int color;
    bool conColor;

    



};

void seleccionarActividades(vector <Actividades> actividades,int n){

    Actividades temp;
    int temporal=-1;

    queue <Actividades> auxiliares;

    stack <int> s;
    stack <int> aux;



    for(int i=0; i<n; i++){
        s.push(i);
    }



    //ordena actividades
     for(int i = 1; i < n; i++) {
    for(int j = 0; j < n - 1; j++){
      if(actividades[j].fin > actividades[j+1].fin) {
        temp = actividades[j];
        actividades[j] = actividades[j+1];
        actividades[j+1] = temp;
      }
    }
  }

  int z=0;


  bool asignadoTemp=false;

  for(int i=1; i<n; i++){

      if(actividades[z].conColor==false){
          actividades[z].color=s.top();
          aux.push(s.top());
          s.pop();
          actividades[z].conColor=true;
          
          
      }

      

      

      if(actividades[z].fin<=actividades[i].inicio && actividades[i].conColor==false){

          actividades[i].color=actividades[z].color;
          actividades[i].conColor=true;
          
         
          
          z++;
          i=z;



      }
     

       

     

      

       else if(actividades[z].fin>actividades[i].inicio ){
          if(auxiliares.size()>0 && auxiliares.front().fin<=actividades[i].inicio && actividades[i].conColor==false){

       
          actividades[i].color=auxiliares.front().color;
          actividades[i].conColor=true;
          
          auxiliares.pop();
          auxiliares.push(actividades[z]);
          
          z++;
          i=z;

          
          

          }

          else if(i==n-1 && actividades[i].conColor==false){
        actividades[i].color=s.top();
          aux.push(s.top());
          s.pop();
          actividades[z].conColor=true;
          break;
      }

          else{

            auxiliares.push(actividades[z]);
            
            z++;
            i=z;



          }

          


      }

    



  }

  z=0;

  for(int i=0; i<n ; i++){
    if((actividades[z].fin>actividades[i].inicio && actividades[z].fin>actividades[i].inicio)){
        if(z!=i){
          cout<<"Arista entre Nodo"<<actividades[z].id<<" y Nodo"<<actividades[i].id<<endl;

        }
        
      }
    if(i==n-1 && z!=n-1){
      z++;
      i=z;
    }
  }

  

  for(int i=0 ; i<actividades.size(); i++){
        cout<<"Nodo"<<actividades[i].id<<" Color: "<<actividades[i].color<<" Inicio: "<<actividades[i].inicio<<" Fin: "<<actividades[i].fin<<endl;

    }

  cout<<"Cantidad de Colores Utilizados: "<<aux.size()<<endl;



}





int main() {


    vector <Actividades> actividades;

    Actividades temp;

    int n;



    int in;
    int fn;
    int i=0;

    cout<<"Ingrese el n° de actividades a generar: "<<endl;
    cin>>n;
     if(n==1){
      cout<<"Se ingreso un sólo nodo, por lo tanto se asigna 1 solo color"<<endl;
      return 0;
    }
   
    srand((int)time(0));

	while(i< n) {
		int r = (rand() % 100) + 1;
		int r2 = (rand() % 100) + r;
	    actividades.push_back({i,r,r2,1000,false});
		i++;
	}
  
   



    seleccionarActividades(actividades,n);



    






  return 0;
}
