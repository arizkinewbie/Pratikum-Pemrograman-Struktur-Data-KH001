#include <stdio.h>
#include <string.h>
char huruf[50], kata[50];
int i, j, nInput, nHuruf, nKata;

void Huruf() {
	//hitung nHuruf
	while (huruf[i] != '\0') {
		if(huruf[i] != ' ') {
			nHuruf = nHuruf + 1;
		};
		i++;
	};
	//output nama terbaik dan jumlah huruf
    printf("\nNama terbalik (Reversed) \t: %s\n", strrev(huruf));
    printf("Jumlah Huruf \t\t\t: %d\n", nHuruf);
}

void Kata(){
	//cetak kata dari belakang dan hitung nKata
	printf("\nUrutan nama dari kata belakang  : ");
	for(i=nInput-1; i>=-1; i--){
        if(kata[i] == ' ' || i<0){
            j = i;
            while(j+1 <= nInput){ 
            	printf("%c", kata[j+1]);
                j++;
        	};
        nKata++;
        nInput = nInput-(nInput-i);
        };
	};
	//cetak jumlah kata
	printf("\nJumlah Kata \t\t\t: %d", nKata);
};

int main() {
    printf("Masukkan nama (string) \t\t: ");
    gets(huruf);
    nInput = strlen(huruf);
    strcpy(kata, huruf);
    // panggil fungsi
	Huruf(); Kata();
    return 0;
};