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
	
	
	// Linear system - Testcase 1
	double a[3][3]={{1,-1,1},{1,1,-2},{3,-4,-7}}; 
	double b[3]={-2,9,0};
	double solution_exact[3]={3,4,-1};
	double solution_numeric[3];
	size=3;
	
	double row_temp[3];
	double vector_temp;
	
  cout << a[0][0] << endl;
  cout << a[0][1] << endl;
  cout << a[0][2] << endl;
  cout << a[1][0] << endl;
  cout << a[1][1] << endl;
  cout << a[1][2] << endl;
  cout << a[2][0] << endl;
  cout << a[2][1] << endl;
  cout << a[2][2] << endl;
  
  
    cout << "vector" << endl;
  cout << b[0] << endl;
  cout << b[1] << endl;
  cout << b[2] << endl;
	
//	// Linear system - Testcase 2
//	double a[4][4]={{1,1,1,0},{-2,-2,2,3.33},{1,-1,-1,0}{0,2.5,3,-1}}; 
//	double b[4]={2,2,8,-11};
//	double solution_exact[4]={5,-2,-1,3};
//	double solution_numeric[4];
//	size=4;
//	
//	double row_temp[4];
//	double vector_temp;
	
	
	
	
	// Algorithm
	i=0; // Zählindex Zeile
	j=0; // Zählindex Spalte
	
	
	while (i < size){

			i_temp=i; // Gibt die aktuelle Zeile an, die bearbeitet wird
			pivot_row =i;
			
			// Pivot: search
			while(i_temp<size)
			{
				if (abs(a[i_temp][i])>a[i][i]) pivot_row=i_temp; 
				i_temp++;
			}
			cout << "break" << endl;
			cout << pivot_row << endl;
			
			
			
//			// Pivot: change
//			
			j_temp=0; // BEMERKUNG: hier reicht ggf. auch ein höherer Zähler
			while(j_temp < size) 
				{
					row_temp[j_temp]=a[i][j_temp];
					a[i][j_temp]=a[pivot_row][j_temp];
					a[pivot_row][j_temp]=row_temp[j_temp];
										
					j_temp++;
				}
				
			  cout << "matrix" << endl;
  cout << a[0][0] << endl;
  cout << a[0][1] << endl;
  cout << a[0][2] << endl;
  cout << a[1][0] << endl;
  cout << a[1][1] << endl;
  cout << a[1][2] << endl;
  cout << a[2][0] << endl;
  cout << a[2][1] << endl;
  cout << a[2][2] << endl;
				
			vector_temp=b[i];
			b[i]=b[pivot_row];
			b[pivot_row]=vector_temp;

  cout << "vector" << endl;
  cout << b[0] << endl;
  cout << b[1] << endl;
  cout << b[2] << endl;
			
			
			
			
// 			 //Gauss: Matrix decomposition	
// 
// 				i_temp=i+1;  
// 				
// 				while (i_temp < size)
// 				{
// 					j_temp=0;
// 
// 					while(j_temp < size) 
// 					{
// 						a[i_temp][j_temp]=a[i_temp][j_temp] - (a[i_temp][i] / a[i][i])*a[i][j_temp];
// 						b[i_temp]=b[i_temp]-(a[i_temp][i] / a[i][i])*b[i];
// 						j_temp++;
// 					}	
// 					i_temp++;
// 				}
////				
			i++;
	}
	
	
		// Display the lower triangular matrix
	cout << "upper triangular matrix" << endl;
				  cout << "matrix" << endl;
  cout << a[0][0] << endl;
  cout << a[0][1] << endl;
  cout << a[0][2] << endl;
  cout << a[1][0] << endl;
  cout << a[1][1] << endl;
  cout << a[1][2] << endl;
  cout << a[2][0] << endl;
  cout << a[2][1] << endl;
  cout << a[2][2] << endl;
	
	


	
	
	
	// Substitute to find the solution
	
	
	// Testfall für untere Matrix definieren.
	
	double sum;
	
	solution_numeric[size-1]=b[size-1]/a[size-1][size-1];
	
	i=0;
	i_temp=0;
	while (i < size) 
	{
		sum=0;
		j_temp=size-1-i;
		while (j_temp < size)
		{
			sum=sum+a[size-2-i][j_temp-1]*solution_numeric[j_temp-1];
			j_temp++;
		}
		
		solution_numeric[size-2-i]=(b[size-2-i]-sum)/a[size-2-i][size-2-i];
		i++;
	}
	
	/* output solution */
		cout << "solution exact" << endl;
	cout << solution_exact[0] << endl;
		cout << solution_exact[1] << endl;
			cout << solution_exact[2] << endl;
	
	
	cout << "solution numeric" << endl;
	cout << solution_numeric[0] << endl;
		cout << solution_numeric[1] << endl;
			cout << solution_numeric[2] << endl;
	
	
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
	
	
	
	
	
	
	
	
	
//	
//	
//	
//	int testcase=0;
//	
//
//	int size = 0;
//	int pivot_row=1;
//	double diff;
//	
//	int i_temp=0;
//	int j_temp=0;
//	
//	cout << "Solve linear systems of equations" << endl;
//	cout << "Gauss elimination" << endl;
//	
//	/* ToDo: Choose algorithm */
//	
//	/* Define test cases */
//		
//
//	
//	
//	
//	/* ggf. auf vollen Rank testen oder so */	
//			
//	i=0;
//	j=0;		
//	while (j<size)
//	{
//			/* Implement pivot */
//	while (i < size)
//		{
//			if (abs(a[i][j])>a[1][j]) pivot_row=j; /* search the biggest absolute value */
//			i++;		
//		}
//	
//	/* change the rows */
//	
//	
//	/* Implement decomposition to lower matrix */
//	
//	
//	/* Calculate solution */
//	
//	
//	j++;
//	
//	}
//
//
//	
//		

//	
//}
