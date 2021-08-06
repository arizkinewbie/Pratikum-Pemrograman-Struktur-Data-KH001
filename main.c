#include <stdio.h>
#include <string.h>
char huruf[30], reversed[30];
int i, nHuruf;

int main(void) {
  printf("Masukkan nama (string):\n");
fgets(huruf, sizeof(huruf), stdin);
long int length = strlen(huruf);

//Reverse string
for(i=0; i<length; ++i) {
  reversed[length-1-i] = huruf[i];
}

printf("Reversed string : %s\n",reversed);
printf("Jumlah : %d\n",i);

return 0;
}