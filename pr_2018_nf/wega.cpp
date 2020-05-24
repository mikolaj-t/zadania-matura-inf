#include <iostream>
#include <fstream>

using namespace std;

int abs(int x){
	if(x>0) return x;
	if(x<0) return -x;
}

int main()
{
	fstream plik;
	plik.open("sygnaly.txt");
	int ilosc = 0;
	string przeslanie = "";
	string roznliter = "";
	int najwRoznLiter = 0;
	while (!plik.eof()) {
		ilosc++;
		string slowo;
		plik >> slowo;
		if(ilosc%40 == 0 && ilosc != 1){
			przeslanie += slowo[9];
		}
		bool letters[128]; 
		int curRozn = 0;
		bool oddalone = false;
		for(int i=0; i<slowo.length(); i++){
			if(letters[(int)slowo[i]] == false){
				letters[(int)slowo[i]] = true;
				curRozn++;
			}
			for(int j=i+1; j<slowo.length(); j++){
				if(i != slowo.length()-1 && !oddalone){
					if((abs((int)slowo[i] - (int)slowo[j])) > 10){
						oddalone = true;
					}
				}
			}
		}
		if(curRozn > najwRoznLiter){
			roznliter = slowo;
			najwRoznLiter = curRozn;
		}
		for(int i=0; i<128; i++){
			letters[i] = false;
		}
		if(!oddalone) cout << slowo << endl;
	}
	cout << przeslanie << endl;
	cout << roznliter << " " << najwRoznLiter;
}
