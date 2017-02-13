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
//	double a[3][3]={{1,-1,1},{1,1,-2},{3,-4,-7}}; 
//	double b[3]={-2,9,0};
//	double solution_exact[3]={3,4,-1};
//	double solution_numeric[3];
//	size=3;
//	
//	double row_temp[3];
//	double vector_temp;
//	
	
	 // Linear system - Testcase 2
	double a[4][4]={{1,1,1,0},{-2,-2,2,3.33},{1,-1,-1,0},{0,2.5,3,-1}}; 
	double b[4]={2,2,8,-11};
	double solution_exact[4]={5,-2,-1,3};
	double solution_numeric[4];
	double solution_guess[4]={0,0,0,0};
	size=4;
	
	double row_temp[4];
	double vector_temp;
	
	
	
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
	sum= 0
	
	residual=convergence_limit+1;
	
	int n_iteration; // number of iterations
	
	
	solution_numeric_old=solution_guess;

	
	// Jacobi algorithm
	
	while(residual >= convergence_limit) {
		
	for (i=1:1:size-1)	 {
		
	sum=0;
		while( oder for-Schleife) {
			if (i != j)
			sum=sum+(a[i][j]*solution_numeric_old[j])
	}
	
	solution_numeric[]=(b[i]-sum)/a[i][i];
	sum=0;
	
	// Residual
	
	for () {
			sum=sum+a[][]*solution_numeric[]-b[]
	}
	
	residual=sum;
	}
	
	n_iteration++;
			
	}
	
	cout << "residual" << residual << endl;
	cout << "number of iterations" << n_iteration << endl;	

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
			cout << solution_exact[3] << endl;
	
	
	cout << "solution numeric" << endl;
	cout << solution_numeric[0] << endl;
		cout << solution_numeric[1] << endl;
			cout << solution_numeric[2] << endl;
		cout << solution_numeric[3] << endl;
	
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

	 

