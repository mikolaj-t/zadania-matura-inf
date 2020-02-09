#include <iostream>
#include <fstream>

//6.1 236
//6.2 min 73 max 29881
//6.3 1999 1997
//1721 1723
//1481 1483
//809 811

using namespace std;

bool pierwsza(int liczba){
	for(int j=2; j<liczba; j++){
		if(liczba%j == 0){
			return false;
		}
	}
	return true;
}

int main(){
	fstream plik;
	plik.open("dane4.txt");
	int s;
	int ilosc;
	int min = 30001;
	int max = -1;
	int tablica[2000];
	for(int i=0; i<2000; i++){
		plik>>s;
		tablica[i] = s;
		if(pierwsza(s)){
			ilosc++;
			if(s < min){
				min = s;
			}
			if(s > max){
				max = s;
			}
		}
	}
	cout<<"ilosc "<<ilosc<<endl;
	cout<<"min "<<min<<endl;
	cout<<"max "<<max<<endl;
	cout<<"blizniacze "<<endl;
	for(int i=0; i<2000; i++){
		if(pierwsza(tablica[i]) && pierwsza(tablica[i+1])){
			int roznica = tablica[i] - tablica[i+1];
			if(roznica == 2 || roznica == -2){
				cout<<tablica[i]<<" "<<tablica[i+1]<<endl;
			}
		}
	}
	return 0;
}
