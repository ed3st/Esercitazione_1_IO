#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

//creo una funzione f_affine che mappa un punto dall'intervallo [1,5] all'intervallo [-1,2] 
double f_affine(double x)
{
	return ((3.0/4.0)*x)-(7.0/4.0);
}

int main()
{
	// apro "data.txt"
	string ifilename = "data.txt";
	ifstream ifs(ifilename); 
	if( ifs.fail() ) { // controllo se l'apertura è andata a buon fine
		cerr << "Errore nell'apertura del file " << ifilename << endl;
		return 1;
	}
	
	// creo/apro "result.txt"
	string ofilename = "result.txt"; 
	ofstream ofs(ofilename);
	if( ofs.fail() ) { //controllo se l'apertura è andata a buon fine
		cerr << "Errore nell'apertura del file " << ofilename << endl;
		return 2;
	}
    
	//inizio a stampare nel file di output
	ofs << "# N Mean" << endl; // stampo l'intestazione
	
	/*leggo uno alla volta i valori in "data.txt", 
	li mappo nell'intervallo [-1,2] tramite f_affine,
	calcolo di volta in volta la media dei primi i valori 
	e stampo il risultato in "result.txt" nel formato richiesto. */
	double val;
	unsigned int i = 1; //inizializzo a 1 un contatore intero
	double sum = 0.0; //inizializzo la somma a 0
	while(ifs>>val)
	{
		sum += f_affine(val); //mappo il valore appena letto in [-1,2] e lo aggiungo alla somma
		ofs << i << " " << setprecision(16) << scientific << sum/(i) << endl; 
		//stampo il contatore e la media dei primi i valori mappati. 
		i++; //aggiorno il contatore.
	}
	
	ifs.close(); //chiudo "data.txt"
	ofs.close(); //chiudo "result.txt"
	
	return 0;
}
