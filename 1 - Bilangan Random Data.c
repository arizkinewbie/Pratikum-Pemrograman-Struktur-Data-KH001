#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
char pilihan;
int i, min, max, baru, data[1000], choose, random, frek;

//fungsi random (1-100)
int Random() {
 	random = rand() % 100 + 1;
 	return random;
}

//fungsi rata-rata nilai
float nRata() {
	float nRata = (float)nData()/frek;
	return nRata;
}

//fungsi jumlah nilai dari data
int nData() {
	float nData;
	for (i=0;i<=frek-1;i++) {
		nData += data[i];
	}
	return nData;
}

//fungsi nilai terbesar dan terkecil
int maxmin() {
	min = data[0];
	max = data[0];
	for (i=1;i<=frek-1;i++) {
		if (data[i] < min) {
			min = data[i];
		}
		else if (data[i] > max) {
			max = data[i];	
		}
	}
	return min, max;	
}

//fungsi rentang/jangkauan nilai pada data
int rentang() {
	int rentang;
	maxmin();
	rentang = max-min;
	return rentang;
}

//fungsi menambahkan data baru (user)
int nBaru (){
	printf("Masukan nilai (bilangan bulat) yang ingin ditambah : ");
	scanf("%i", &data[frek]);
	printf("Data telah ditambahkan.\n");
	for (i=0;i<=frek;i++) {
		printf("[%i] ", data[i]);
	}
	frek++;
}

//cetak nilai pada data(array)
int PrintData() {
	puts("Berikut Nilai dalam Data (array) : ");
	for (i=0;i<=frek-1;i++) {
		printf("[%i] ", data[i]);
	}
}

int main(void) {
	srand(time(0));
	printf("Apakah anda ingin menentukan banyak data random (y/n) : ");
	scanf("%c", &pilihan);
		if (pilihan == 'y' || pilihan == 'Y') {
			printf("Masukan berapa banyak data random : ");
			scanf("%i", &frek);
		} else {
			frek = Random();
			printf("[Acak banyak data random.....]"); sleep(1);
		}
	system("cls");
	//random nilai dalam data
	for (i=0;i<=frek-1;i++) {
		data[i] = Random();
		printf("[%i] ", data[i]);
	}
	printf("\n[Hasil Random] jumlah data : %i data\n", frek);
	do {
	puts("\n  -------------------------");
	puts("\tMenu Pilihan");
	puts("  -------------------------");
	puts("[1] Rata-rata nilai (average)\n"
		 "[2] Jumlah nilai data\n"
		 "[3] Nilai terbesar dan terkecil\n"
		 "[4] Rentang/jangkauan nilai\n"
		 "[5] Tambah data baru\n"
		 "[6] Cetak Nilai Dalam Data\n"
		 "[7] Keluar\n");
	printf("Masukan pilihan : ");
 	scanf("%i",&choose);
 	system("cls");
  	switch (choose) {
    case 1:
	  printf("Rata-rata nilai dari data : %.2f\n", nRata());
      break;
    case 2:
      printf("Jumlah nilai dari data : %i\n", nData());
      break;
    case 3:
      maxmin();
    	printf("Nilai terbesar : %i\n", max);
    	printf("Nilai terkecil : %i\n", min);
      break;
    case 4:
      printf("Rentang/jangkauan nilai dari data : %i\n", rentang());
      break;
    case 5:
      nBaru();
      break;
    case 6:
      PrintData();
      break;
    default:
      if (choose != 7) {
      printf("Pilihan tidak tersedia !\n");
      }
      break;
  	}
 } while (choose !=7);
 puts ("Thanks you :) telah menggunakan program ini.");
 return 0;
}