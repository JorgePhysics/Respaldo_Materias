#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generarPixel ();
vector<int> generarPixeles (int n);
void limites (vector<int> pixeles, int n);

int main()
{
    int n;
    cout << "Ingrese la cantidad de pixeles: " << endl;
    cin >> n;
    vector<int> pixeles = generarPixeles(n);
    for(int i : pixeles)
	{
        cout << i << endl;
    }
    cout << endl << endl;
    limites(pixeles, n);

    return 0;
}

int generarPixel ()
{
    int r = rand()%(256);
    return r;
}

vector<int> generarPixeles (int n)
{
    vector<int> pixeles(n);
    for(int i = 0; i < n; i++)
	{
        pixeles[i] = generarPixel();
    }
    
    return pixeles;
}

void limites (vector<int> pixeles, int n)
{
    vector<int> cantidad(26, 0);
    for(int i = 0;i < n;i++)
	{
        if(pixeles[i] >= 0 && pixeles[i] <= 9)
		{
            cantidad[0]++;
        } 
		else if (pixeles[i] >= 10 && pixeles[i] <= 19)
		{
            cantidad[1]++;
        } 
		else if (pixeles[i] >= 20 && pixeles[i] <= 29)
		{
            cantidad[2]++;
        } 
		else if (pixeles[i] >= 30 && pixeles[i] <= 39)
		{
            cantidad[3]++;
        } 
		else if (pixeles[i] >= 40 && pixeles[i] <= 49)
		{
            cantidad[4]++;
        } 
		else if (pixeles[i] >= 50 && pixeles[i] <= 59)
		{
            cantidad[5]++;
        } 
		else if (pixeles[i] >= 60 && pixeles[i] <= 69)
		{
            cantidad[6]++;
        } 
		else if (pixeles[i] >= 70 && pixeles[i] <= 79)
		{
            cantidad[7]++;
        } 
		else if (pixeles[i] >= 80 && pixeles[i] <= 89)
		{
            cantidad[8]++;
        } 
		else if (pixeles[i] >= 90 && pixeles[i] <= 99)
		{
            cantidad[9]++;
        } 
		else if (pixeles[i] >= 100 && pixeles[i] <= 109)
		{
            cantidad[10]++;
        } 
		else if (pixeles[i] >= 110 && pixeles[i] <= 119)
		{
            cantidad[11]++;
        } 
		else if (pixeles[i] >= 120 && pixeles[i] <= 129)
		{
            cantidad[12]++;
        } 
		else if (pixeles[i] >= 130 && pixeles[i] <= 139)
		{
            cantidad[13]++;
        } 
		else if (pixeles[i] >= 140 && pixeles[i] <= 149)
		{
            cantidad[14]++;
        } 
		else if (pixeles[i] >= 150 && pixeles[i] <= 159)
		{
            cantidad[15]++;
        } 
		else if (pixeles[i] >= 160 && pixeles[i] <= 169)
		{
            cantidad[16]++;
        } 
		else if (pixeles[i] >= 170 && pixeles[i] <= 179)
		{
            cantidad[17]++;
        } 
		else if (pixeles[i] >= 180 && pixeles[i] <= 189)
		{
            cantidad[18]++;
        } 
		else if (pixeles[i] >= 190 && pixeles[i] <= 199)
		{
            cantidad[19]++;
        } 
		else if (pixeles[i] >= 200 && pixeles[i] <= 209)
		{
            cantidad[20]++;
        } 
		else if (pixeles[i] >= 210 && pixeles[i] <= 219)
		{
            cantidad[21]++;
        } 
		else if (pixeles[i] >= 220 && pixeles[i] <= 229)
		{
            cantidad[22]++;
        } 
		else if (pixeles[i] >= 230 && pixeles[i] <= 239)
		{
            cantidad[23]++;
        } 
		else if (pixeles[i] >= 240 && pixeles[i] <= 249)
		{
            cantidad[24]++;
        } 
		else if (pixeles[i] >= 250 && pixeles[i] <= 255)
		{
            cantidad[25]++;
        }
    }
    
    for(int i = 0; i < 26; i++)
	{
        cout << "Para el rango de " << 10 * i << " " << (10 * i) + 9 << ": " << cantidad[i] << endl;
    }
}