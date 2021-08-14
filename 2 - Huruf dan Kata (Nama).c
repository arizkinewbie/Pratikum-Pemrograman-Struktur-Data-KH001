#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char huruf[50], kata[50];
int i, j, k, nInput, nHuruf, nKata;

void Huruf() {
	//hitung nHuruf
	while (huruf[i] != '\0') {
		if(huruf[i] != ' ') {
			nHuruf = nHuruf + 1;
		}
		i++;
	}
	//output nama terbaik dan jumlah huruf
    printf("\nNama terbalik (Reversed) \t: %s\n", strrev(huruf));
    printf("Jumlah Huruf \t\t\t: %d\n", nHuruf);
}

void Kata(){
	//cetak kata dari belakang dan hitung nKata
	bool cek = 1;
	printf("\nUrutan nama dari kata belakang  : ");

	for(i=nInput-1; i>=-1; i--){
        if(kata[i] == ' ' || i<0){
            j = i;
            if (cek) {
            	while(j+1 <= nInput){ 
            		printf("%c", kata[j+1]);
              	  j++;
        		}
        		cek = 0;
        	}
        	else {
        		while(k <= nInput) {
        			printf("%c", kata[k]);
              	  k++;
				}
			}
        nKata++;
        nInput = nInput-(nInput-i);
        }
	}
    
	//cetak jumlah kata
	printf("\nJumlah Kata \t\t\t: %d", nKata);
}

int main() {
    printf("Masukkan nama (string) \t\t: ");
    gets(huruf);
    nInput = strlen(huruf);
    strcpy(kata, huruf);
    // panggil fungsi
	Huruf(); Kata();
    return 0;
}