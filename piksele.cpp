#include <iostream>
#include <fstream>

//6.1 najjasn 221 najciemn 7
//6.2 149
//6.3 753
//6.4 5

using namespace std;

int main(){
	fstream plik;
	int tablica[200][320];
 	plik.open("dane.txt");
 	int s;
 	int najjasn=-1;
	int najciemn=256;
 	for(int i=0; i<64000; i++){
 		int x = i/320;
 		int y = i%320;
 		plik>>s;
 		tablica[x][y] = s;
 		if(s>najjasn){
 			najjasn = s;	
		}
		if(s<najciemn){
			najciemn = s;
		}
	}
	cout<<"najjasn "<<najjasn<<endl;
	cout<<"najciemn "<<najciemn<<endl;
	int inne=0;
	for(int i=0; i<200; i++){
		for(int j=0; j<159; j++){
			if(tablica[i][j] != tablica[i][(319-j)]){
				inne++;
				break;
			}
		}
	}
	cout<<"inne "<<inne<<endl;
	int kontrastujace;
	int konstr[200][320];
	for(int i=0; i<200; i++){
		for(int j=0; j<319; j++){
			int roznica = tablica[i][j] - tablica [i][j+1];
			if(roznica > 128 || roznica < -128){
				if(konstr[i][j] == 0){
					konstr[i][j] = 1;
					kontrastujace++;
				}
				if(konstr[i][j+1] == 0){
					konstr[i][j+1] = 1;
					kontrastujace++;
				}
			}
		}
	}
	for(int j=0; j<320; j++){
		for(int i=0; i<199; i++){
			int roznica = tablica[i][j] - tablica [i+1][j];
			if(roznica > 128 || roznica < -128){
				if(konstr[i][j] == 0){
					konstr[i][j] = 1;
					kontrastujace++;
				}
				if(konstr[i+1][j] == 0){
					konstr[i+1][j] = 1;
					kontrastujace++;
				}
			}
		}
	}
	cout<<"kontr "<<kontrastujace<<endl;
	int longest = 1;
	for(int j=0; j<320; j++){
		int last = tablica[0][j];
		int length=1;
		for(int i=1; i<200; i++){
			if(tablica[i][j] != last){
				if(length>0){
					if(length>longest){
						longest=length;
					}
				}
			}else if(tablica[i][j] == last){
				length++;
			}
		}
	}
	cout<<"long "<<longest;
	return 0;
}
