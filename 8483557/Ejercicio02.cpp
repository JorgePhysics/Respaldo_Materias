#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int n;
	int a;
	int b;
	
	cout << "Ingrese el tamano de la matriz: ";
	cin >> n;
	
	cout << "Ingrese el valor de a: ";
	cin >> a;
	
	cout << "Ingrese el valor de b: ";
	cin >> b;
	
	GenerarAleatorio(int a, int b);
	
	ProcesarMatriz();
	
	return 0;
}

int GenerarAleatorio(int LimInferior, int LimSuperior)
{
    int aleatorio = 0;
    
    aleatorio = ( rand() % ( LimSuperior - LimInferior + 1) ) + LimInferior;
    
    return aleatorio;
}

void ProcesarMatriz()
{
	int m[100][100];
	
	for(int i =0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			m[i][j] = GenerarAleatorio(int LimInferior, int LimSuperior);
		}
	}
	
	int SumCol1 = 0;
	
	for(int i = 0; i < n; i++)
	{
		SumCol1 += m[i][0];
	}
	
	int ProdCol1 = 1;
	
	for(int j = 0; j < n; j++)
	{
		ProdCol1 *= m[0][j];
	}
	
	int menor = m[0][0], posI = 0, posJ = 0;
	
	if(m[i][j] < menor)
	{
		menor = m[i][j];
		
		posI = i;
		
		posJ = j;
	}
}