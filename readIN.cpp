#include<iostream> // Ein- und Ausgabe
#include<fstream> // zur Dateiein- und ausgabe
#include<string> // zum Einlesen einer Datei
#include <sstream>  // um istingstream zu verwenden


using namespace std;

int arrayA[1000][1000]={{0}};
int size=0;

int readIN() //Funktion um Matrix einzulesen in einem bestimmten Format, ggf. weitere paramter spezifieren
{
 string filename;
  string lineA;
  int x;

  
  ifstream fileIN;
  
  int rowA=0;
  int colA=0;

  fileIN.open("input_matrix.csv", ios::in);
  
   // Reading the Data file
  while(fileIN.good()){
   while(getline(fileIN,lineA)){
   istringstream streamA(lineA);
   colA = 0;
   while(streamA >> x) {
   arrayA[rowA][colA] = x;
   colA++;
     
  }
     rowA++;
     size=rowA;
  } 
  }
  
  
}


int main(void) 
{
  /* Reading files and columns is based on https://www.youtube.com/watch?v=4nz6rPzVm70 */
  

  readIN();
 
  
  cout << "reading file succesful" << endl;
  cout << arrayA[0][0] << endl;
  cout << arrayA[0][1] << endl;
  cout << arrayA[0][2] << endl;
  cout << arrayA[1][0] << endl;
  cout << arrayA[1][1] << endl;
  cout << arrayA[1][2] << endl;
  cout << arrayA[2][0] << endl;
  cout << arrayA[2][1] << endl;
  cout << arrayA[2][2] << endl;
  cout << "size" << size << endl;
 
  
}