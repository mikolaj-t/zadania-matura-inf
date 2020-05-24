#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream plik;
	plik.open("slowa.txt");
	int ilosc = 0;
	string slowo = "";
	string poprzednieSlowo;
	int iloscA = 0;
	int iloscWewn = 0;
	int iloscAna = 0;
	int literyWPoprz[128];
	while(!plik.eof()){
		ilosc++;
		plik >> slowo;
		if(slowo[slowo.length() - 1] == 'A'){
			iloscA++;
		}
		if(ilosc % 2 == 1){
			poprzednieSlowo = slowo;
			for(int i = 0; i<slowo.length(); i++){
				literyWPoprz[(int)slowo[i]]++;
			}
		}else{
		    if(slowo.length() >= poprzednieSlowo.length()){
				for(int i = 0; i <= slowo.length() - poprzednieSlowo.length(); i++){
					bool zawiera = true;
					for(int j = 0; j < poprzednieSlowo.length(); j++){
						if(slowo[i + j] != poprzednieSlowo[j]){
							zawiera = false;
							break;
						}
					}
					if(zawiera){
						iloscWewn++;
						cout << "zawiera " << slowo << " " <<poprzednieSlowo<<endl;
						break;
					}
				}
			}
			int literyWTym[128];
			for(int i = 0; i<slowo.length(); i++){
				literyWTym[(int)slowo[i]]++;
			}
			bool anagram = true;
			for(int i = 0; i<128; i++){
				if(literyWTym[i] != literyWPoprz[i]){
					anagram = false;
					break;
				}
			}
			if(anagram){
				iloscAna++;
			}
			for(int i = 0; i<128; i++){
				literyWTym[i] = 0;
				literyWPoprz[i] = 0;
			}
		}
	}
	cout<<iloscA<<endl;
	cout<<iloscWewn<<endl;
	cout<<iloscAna<<endl;
	return 1;
}
