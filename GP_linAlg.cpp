#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Inicializacion de funciones
double** get_Matrix(int N, int M);
double** matrix_product(double** mat1, double** mat2);

//funcion que construye una matriz dada una matriz dada por consola shell
double** get_Matrix(int N, int M){
  
  //Inicializacion de matriz MxN
  double **mat=new double*[M];
  for(int k=0;k<M;k++){
     mat[k] = new double[N];
  }
  cout<<"La matriz sera de dimension "<<M<<"x"<<N<<endl;

  //Aqui se rellena la matriz por numeros dados por el usuario en consola
  for(int i =0 ;i<M;i++){
    for(int j=0;j<N;j++){
      cout<<"Ingrese el valor "<<i<<","<<j<<" de la matriz"<<endl;
      double var; 
      cin >> var;
      mat[i][j] = var;
    }
  }
  //Imprimir matriz
  cout<<"Su matriz resultante es la siguiente:"<<endl;
  for(int i_2=0;i_2<M;i_2++){
    for(int j_2=0;j_2<N;j_2++){
      cout<<mat[i_2][j_2]<<" ";      
    }
    cout << endl;
  } 
  return mat;
}

double** matrix_product(double** mat1, double** mat2, int M1, int N1, int M2, int N2){
    
  //Inicializacion de matriz 
  double **product=new double*[M1];
  for(int k=0;k<M2;k++){
     product[k] = new double[N2];
  }
  //se hace la multiplicacion
  for(int i=0;i<M1;i++){
    for(int j=0;j<N2;j++){
      double suma = 0;
      for(int m=0;m<M2;m++){
        double mult= mat1[i][m] * mat2[m][j];
        suma = suma + mult;     
      }
      product[i][j] = suma; 
    }
  } 
  return product;
}


//Funcion main, para multiplicar matriz 1 con matriz 2
int main(){
  //Variables de dimensiones se piden al usuario. Se verifica dimensionalidad.
  double M1;
  double N1;
  double M2;
  double N2;
  cout<<"Ingrese dimension M (filas) de matriz 1"<<endl;
  cin>> M1;
  cout<<"Ingrese dimension N (columnas) de matriz 1"<<endl;
  cin>> N1;  
  cout<<"Ingrese dimension M (filas) de matriz 2. Esta debe ser igual a la dimension N de la matriz 1"<<endl;
  cin>> M2;
  cout<<"Ingrese dimension N (columnas) de matriz 2"<<endl;
  cin>> N2;

  if(M2 != N1){
	cout<<"La dimension de columnas de matriz 1 es diferente "<<endl;
        cout<<"a la dimension filas de matriz 2. Deben ser igual."<<endl;	
  }

  double** mat1;
  double** mat2;

  cout<<"Ingrese valores de Matriz 1"<<endl;
  mat1 = get_Matrix(M1,N1);

  cout<<"Ingrese valores de Matriz 2"<<endl;
  mat2 = get_Matrix(M2,N2);

  double** resultado = matrix_product(mat1,mat2,M1,N1,M2,N2);
  cout<<"El resultado de la multiplicacion de sus dos matrices es: "<<endl;
  cout<<resultado<<endl;
  return 0;
}
