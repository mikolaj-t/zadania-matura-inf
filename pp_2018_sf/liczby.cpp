#include <iostream>
#include <fstream>

using namespace std;

bool palindrom(string s){
	if(s.length() == 1) return true;
	for(int i=0; i<s.length()/2; i++){
		if(s[i] != s[s.length() - 1 - i]){
			return false;
		}
	}
	return true;
}

int pow(int x, int y){
	if(y == 0) return 1;
	int result = x;
	for(int i=2; i<=y; i++){
		result*=x;
	}
	return result;
}

int fromChar(char c){
	int res ((int) c - 48);
	if(res > 9 || res < 0) return 0;
}

int fromString(string s){
	int result;
	for(int i=0; i<s.length(); i++){
		result += pow(10, (s.length() - 1 -i)) * fromChar(s[i]);
	}
	return result;
}

int main(){
	fstream plik;
	plik.open("liczby.txt");
	int najwParzysta = 0;
	string s;
	int in;
	int suma = 0;
	while(!plik.eof()){
		plik >> s;
		in = fromString(s);
		if(in % 2 == 0 && in > najwParzysta){	
			najwParzysta = in;
		}
		if(palindrom(s)){
			cout<<"P: "<<in<<endl;
		}
	}
	plik.close();
	plik.open("liczby.txt");
	while(!plik.eof()){
		plik >> s;
		in = fromString(s);
		int sumaLok = 0;
		for(int i=0; i<s.length(); i++){
			sumaLok += fromChar(s[i]);	
		}	
		if(sumaLok > 30){
			cout<<"S: "<<in<<endl;
		}
		suma += sumaLok;
	}	
	cout<<"najw: "<<najwParzysta<<endl;
	cout<<"suma: "<<suma<<endl;
	return 1;
}
