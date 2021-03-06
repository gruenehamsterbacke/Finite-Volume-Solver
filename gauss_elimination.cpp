/* dieses Programm implementiert den Gauss algorithmus inkl. Pivotisierung */


#include<iostream>
#include <cmath> /* notwending u.a. f�r die Betragsfunktion in der Pivotisierung */

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
	
	
	
	// Funktion: �bergebe Matrix, Vektor, Verfahren, epsilon >> Ausgabe: L�sungsvektor, quadratisches Residuum, ggf. Anzahl der Iterationen
	
	
	
	
	// Algorithm
	i=0; // Z�hlindex Zeile
	j=0; // Z�hlindex Spalte
	
	
	while (i < size){

			i_temp=i+1; // Gibt die aktuelle Zeile an, die bearbeitet wird
			pivot_row=i;
			
			// Pivot: search
			while(i_temp<size)
			{
				if (abs(a[i_temp][i])>a[i][i]) pivot_row=i_temp; 
				i_temp++;
			}
			
//			// Pivot: change
//			
			j_temp=0; // BEMERKUNG: hier reicht ggf. auch ein h�herer Z�hler
			while(j_temp < size) 
				{
					row_temp[j_temp]=a[i][j_temp];
					a[i][j_temp]=a[pivot_row][j_temp];
					a[pivot_row][j_temp]=row_temp[j_temp];									
					j_temp++;
				}
				
			vector_temp=b[i];
			b[i]=b[pivot_row];
			b[pivot_row]=vector_temp;

 			 //Gauss: Matrix elimination
 				i_temp=i+1;  // i is the row with the reference row (pivot row) and the Gauss elimination starts one row below
		
 				while (i_temp < size)
 				{
 					j_temp=0; // Z�hler ggf. erh�hen
 					temp_var=a[i_temp][i];
 				
 					while(j_temp < size) 
 					{
 						 cout << "j_temp:" << j_temp << endl;
 						 cout << "a(i, j_temp)" << a[i][j_temp] << endl;
 						 cout << "a(i,i)" << a[i][i] << endl;
 						 cout << "a[i_temp][i]" << a[i_temp][i] << endl;
 						 cout << "temp_var" << temp_var << endl;
				 
						 a[i_temp][j_temp]=a[i_temp][j_temp] - (temp_var / a[i][i])*a[i][j_temp];
//						 cout << "a(i_temp, j_temp)" << a[i_temp][j_temp] << endl;
						 
 						 j_temp++;
 					}						
 					b[i_temp]=b[i_temp]-(temp_var / a[i][i])*b[i];
					 					
 					i_temp++;
 				}
			i++;
	}
	
	
//		// Display the upper triangular matrix
//
//		  cout << "upper triangular matrix"  << endl;
//		  cout << a[0][0] << endl;
//		  cout << a[0][1] << endl;
//		  cout << a[0][2] << endl;
//		  cout << a[1][0] << endl;
//		  cout << a[1][1] << endl;
//		  cout << a[1][2] << endl;
//		  cout << a[2][0] << endl;
//		  cout << a[2][1] << endl;
//		  cout << a[2][2] << endl;
//	
//	
//		  cout << "vector" << endl;
//		  cout << b[0] << endl;
//		  cout << b[1] << endl;
//		  cout << b[2] << endl;
		
	// Substitute to find the solution
	
	
	// Testfall f�r untere Matrix definieren.
	
	double sum; 
	int row;
	
	row=size-1;
	sum=0;
	
	solution_numeric[row]=(b[row]-sum)/a[row][row];
	
	row=row-1;
	
	while (row >= 0) {
		j=0;		
		while (row+j <= size-1) {
		sum=sum+a[row][row+j]*solution_numeric[row+j];
		j++;
		}
	cout << "sum" << sum << endl;
	solution_numeric[row]=(b[row]-sum)/a[row][row];
	sum=0;
	row--;
	}
	
	
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

	 

