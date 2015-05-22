#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h> 
#define MAX_THREADS 4


/* Time in seconds from some point in the past */
double dwalltime();




int main (int argc, char *argv[]){

	 double *A; // Matriz A
	 double *B; // Matriz B
	 double *C; // Matriz C
	 double *D; // Matriz D
	 double *V_a; // Vector que contiene los datos del item 2: minA, maxA, avgA, minB, maxB, avgB
	 double *V_b; // Vector auxiliar para la matriz B
	 double *result // para poner le resultado final
	 double *calculation; // el resultado de hacer
	 double timetick;
   const  MAX_THREADS;

	//El tamano de la matriz sera n*n , y se debe
	// ingresar por teclado n

	if (argc != 1){
		printf("\n Debe ingresar solamente un parámetro: ");
		printf("\n n: la dimensión de la matriz ");
		return 0;
	}

	int n = atoi(argv[0]);

	int size_matrix=n*n; //cantidad total de datos matriz

	A = (double *)malloc(size_matrix*sizeof(double)); //aloca memoria para A (se ordena por filas)
	B = (double *)malloc(size_matrix*sizeof(double)); //aloca memoria para B (se ordena por columnas)
	C = (double *)malloc(size_matrix*sizeof(double)); //aloca memoria para C (se ordena por filas)
	D = (double *)malloc(size_matrix*sizeof(double)); //aloca memoria para D (solo se almacena la diagonal)
	V_a = (double *)malloc(12*sizeof(double)); //aloca memoria para V (el vector q contiene los minA, maxA, avg", minB, maxB, avgB)
	V_b = (double *)malloc(6*sizeof(double)); 

	build_matrix(A, size_matrix);			//Inicializa A
	build_matrix(B, size_matrix);			//Inicializa A 
	build_diagonal_matrix(D, n);			//Inicializa A
	build_matrix(V_a, 12);
	build_matrix(V_b, 6);
  

	timetick = dwalltime();
	multiply_matrix(A,B,C,D);
	printf("Tiempo en segundos %f \n", dwalltime() - timetick);
	
	calculation = factor(V)

//comprobar el resultado
//imprimir en pantalla el resultado

}

void build_matrix(double S*, int size_matrix) {
	int i;
	for(i=0; i<size_matrix; i++){
		S[i] = rand()%10;
	}
}

void build_diagonal_matrix(double S*, int n){
	int i;
	for(i=0; i<n){
		S[i] = rand()%10;
	}
}

void multiply_matrix(double *A,double *B,double *C, double *D, int size_matrix){
  
  num_threads = 4;

  for(i=0; i<num_threads; i++){
    pthread_create(&p_threads[i], &attr, compute_pi, (void *) &hits[i]); 
  }

}

void *como_quieras(*V){
  for(i=0; i<n; i++){
    for(j=0; j<(n/MAX_THREADS); j++){
      A[i+(j*numero_proceso)]
    }
  }
}

double factor(double *V){
  return  (pow(((max_a-min_a), 2)/ avg_a)*(pow((max_b-min_b, 2)/ avg_b)
}

double min_a(double *V){
  return V[2]+V[5]+V[8]+v[11]
}

double max_a(double *V){
  return V[10]+V[1]+V[4]+v[7]
}

double avg_a(double *V){
  return V[3]+V[6]+V[9]+v[12]
}

double min_b(double *V){
  return V[2]+V[5]+V[8]+v[11]
}

double max_b(double *V){
  return V[10]+V[1]+V[4]+v[7]
}

double avg_b(double *V){
  return V[3]+V[6]+V[9]+v[12]
}

/*****************************************************************/

#include <sys/time.h>

double dwalltime()
{
	double sec;
	struct timeval tv;

	gettimeofday(&tv,NULL);
	sec = tv.tv_sec + tv.tv_usec/1000000.0;
	return sec;
}
