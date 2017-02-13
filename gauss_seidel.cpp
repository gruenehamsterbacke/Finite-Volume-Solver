/* dieses Programm implementiert den Gauss algorithmus inkl. Pivotisierung */


#include<iostream>
#include <cmath> /* notwending u.a. für die Betragsfunktion in der Pivotisierung */

using namespace std;




int main()
{
	
	// General definitions
	int i;
	int j;
	int i_temp;
	int j_temp;
	int pivot_row;
	int size;
	
	double temp_var;
	
	
//	// Linear system - Testcase 1
	double a[3][3]={{1,-1,1},{1,1,-2},{3,-4,-7}}; 
	double b[3]={-2,9,0};
	double solution_exact[3]={3,4,-1};
	double solution_numeric[3];
	double solution_numeric_old[3]={0,0,0};
	size=3;
	
	double row_temp[3];
	double vector_temp;
	
	double r[3];
//	
	
// 	 // Linear system - Testcase 2
// 	double a[4][4]={{1,1,1,0},{-2,-2,2,3.33},{1,-1,-1,0},{0,2.5,3,-1}}; 
// 	double b[4]={2,2,8,-11};
// 	double solution_exact[4]={5,-2,-1,3};
// 	double solution_numeric[4];
// 	double solution_numeric_old[4]={0,0,0,0}; // Anfangslösung, kann auch geraten werden
// 	size=4;
// 	
// 	double row_temp[4];
// 	double vector_temp; // not used for iterative algorithm Jacobi and Gauss-Seidel
// 	
// 	
// 	double r[4];

	
//		// Linear system - Testcase 3
//	double a[9][9]={{0.7071,0,0,-1,-0.8660,0,0,0,0},{0.7071,0,1,0,0.5,0,0,0,0},{0,1,0,0,0,-1,0,0,0},{0,0,-1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0.7071},{0,0,0,1,0,0,0,0,-0.7071},{0,0,0,0,0.8660,1,0,-1,0},{0,0,0,0,0.8660,1,0,-1,0},{0,0,0,0,-0.5,0,-1,0,0},{0,0,0,0,0,0,0,1,0.7071}}; 
//	double b[9]={1000,-1000,0,500,500,0,0,-500,0};
//	double solution_exact[4]={5,-2,-1,3};
//	double solution_numeric[9];
//	size=9;
//	
//	double row_temp[9];
//	double vector_temp;
	
	
	
	// Funktion: übergebe Matrix, Vektor, Verfahren, epsilon >> Ausgabe: Lösungsvektor, quadratisches Residuum, ggf. Anzahl der Iterationen
	
		// Algorithm
	i=0; // Zählindex Zeile
	j=0; // Zählindex Spalte
	
	
	
	
	// Preliminary Check
	while(i<size) {
		if(a[i][i] == 0) {
			cout << "This valid has a non-zero diagonal - algorithm fails" << endl; // hier kann ggf. ein weiterer Algorithmus implementiert werden, der das vermeidet oder umgeht.
			return 0;
		}
		i++;
	}
	
	cout << "starting algorithm..." << endl;
	
	
	// ggf. check auf vollen Rank
	

	double residual;
	double convergence_limit;
	
	double sum;
	
	double sum2; // weitere Hilfsvariable
	
	int n_iteration=1; // number of iterations, starting counter at 1
	
	
	

	
	// Jacobi algorithm
	
	// note that the Jacobi algorithm may fail if the matrix is not strictly diagonal!
	
	convergence_limit=1e-3;
	residual=convergence_limit+1; // necessary that while condition is set true at the beginning of the algorithm
	
	cout << "convergence_limit" << convergence_limit << endl;
	
	
	
	// the algorithm gets unstable for a growing number of loops
	
	for(int count=1; count <40;count++) {
		
	  
	  
	  
	  
	  
		 cout << "starting iteration, number " << n_iteration << endl;
	  
		 for (i=0;i<size;i++)	 
		 {
			  
		  sum=0;
			  for (j=0;j< size; j++)
			      { 
				  if (i != j) {
				  sum=sum+(a[i][j]*solution_numeric_old[j]);
				  cout << "i" << i << endl;
				  cout << "j" << j << endl;
				  
				  }
			      }
		  cout << "sum" << sum << endl;
		  solution_numeric[i]=(b[i]-sum)/a[i][i];
		  cout << "a" << a[i][i] << endl; // passt
		 }
		 
		 
// 		 // Calculate residual vector and L2 norm
// 		 sum=0;
// 		 sum2=0;
// 		 for (i=0; i <size; i++) {
// 		   sum=0;
// 		   for(j=0; j < size; j++) {
// 		     sum=a[i][j]*solution_numeric[j];
// 		     
// 		   } 
// 		   r[i]=b[i]-sum;
// 		   sum2=sum2+(r[i]*r[i]); // korrigieren!!! und ggf. in obere Klammer ziehen, so dass sum2 nicht mehr benötigt wird
// 		   
// 		 }
// 		 
// 		 // L2 norm for the vector
// 		 residual = sum2;
		  
		 
		 for (i=0; i < size; i++) {
			solution_numeric_old[i]=solution_numeric[i]; 
		 }
		 
		 
		 //n_iteration++;
		
			
	}
	
	cout << "residual" << residual << endl;
	//cout << "total number of iterations" << n_iteration << endl;	//ggf. elapsed time

	// Gauss-Seidel-algorithm

	
//	solution_numeric[size-1]=b[size-1]/a[size-1][size-1];
//	solution_numeric[size-2]=(b[size-2]-a[size-2][size-1]*solution_numeric[size-1])/a[size-2][size-2];
//	solution_numeric[size-3]=(b[size-3]-a[size-3][size-2]*solution_numeric[size-2]-a[size-3][size-1]*solution_numeric[size-1])/a[size-3][size-3];
//	

	
	/* output solution */
		cout << "solution exact" << endl;
	cout << solution_exact[0] << endl;
		cout << solution_exact[1] << endl;
			cout << solution_exact[2] << endl;
// 			cout << solution_exact[3] << endl;
	
	
	cout << "solution numeric" << endl;
	cout << solution_numeric[0] << endl;
		cout << solution_numeric[1] << endl;
			cout << solution_numeric[2] << endl;
// 		cout << solution_numeric[3] << endl;
	
	/* Compare solution */
	
	i=0;
	double diff = 0;
	while (i<size)
	{
		diff=diff+abs(solution_exact[i]-solution_numeric[i]);
		i++;
	}
	
	cout << "difference between exact and numerical solution" << diff << endl;
	
	
	
	
	
	
	
}

	 

