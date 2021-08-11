/*
	Name: Program Binary Search Tree
	Copyright: Sabeb (ArizkiNewbie)
	Author: Arizki Putra Rahman
	Date: 10/08/21 23:01
	Description: Mulai Aja DUlu
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

Node *pohon = NULL;

//fungsi untuk menambahkan node baru
void tambah (Node **root, int databaru)
{
       //jika root masih kosong
    if ((*root)==NULL)
       {
        //pembuatan node baru
        Node *baru;
        //pengalokasian memori dari node yang telah dibuat
        baru = new Node;
        //inisialisasi awal node yang baru dibuat
        baru->data=databaru;
        baru->kiri=NULL;
        baru->kanan=NULL;
        (*root) = baru;
        (*root) -> kiri = NULL;
        (*root) -> kanan = NULL;
        //jika menujuk menunjuk ke NULL artinya tidak mempunyai child
        printf("Data Bertambah!");
       }
    //jika data yang akan dimasukkan lebih kecil daripada elemen root, maka akan diletakkan di node sebelah kiri.
    else if (databaru<(*root)->data)
              tambah(&(*root)->kiri,databaru);
    //jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan
    else if (databaru>(*root)->data)
        tambah(&(*root)->kanan,databaru);
    //jika saat dicek data yang akan dimasukkan memiliki nilai yang sama dengan data pada root
    else if (databaru==(*root)->data)
        printf("Data Sudah ada!");
}

//fungsi yang digunakan untuk mencetak tree secara preOrder
void preOrder(Node *root)
{
    if(root!=NULL)
    {
        if(root->data!=NULL)
        {
            printf("%d ",root->data);
        }
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

//fungsi yang digunakan untuk mencetak tree secara inOrder
void inOrder(Node *root)
{
       if(root!=NULL)
       {
           inOrder(root->kiri);
           if(root->data!=NULL)
           {
               printf("%d ",root->data);
           }
           inOrder(root->kanan);
        }
}

//fungsi yang digunakan untuk mencetak tree secara postOrder
void postOrder(Node *root)
{
       if(root!=NULL)
       {
         postOrder(root->kiri);
         postOrder(root->kanan);
         if(root->data!=NULL)
         {
            printf("%d ",root->data);
         }
       }
}

//fungsi yang digunakan untuk melakukan pencarian data
void search(Node **root, int cari)
{
    if((*root) == NULL)
    {
        printf("Data tidak ditemukan!");
    }
    //jika data yang dicari lebih kecil dari isi root
    else if(cari < (*root)->data)
        search(&(*root)->kiri,cari);
    //jika data yang dicari lebih besar dari isi root
    else if(cari > (*root)->data)
        search(&(*root)->kanan,cari);
    //jika data yang dicari sama dengan isi dari variabel root
    else if(cari == (*root)->data)
        printf("Data ditemukan!");
}

//fungsi untuk mengetahui jmlah node dalam tree
int count(Node *root)
{
       if(root==NULL)
              return 0;
       else
              return count(root->kiri)+ count(root->kanan)+1;
}

//Fungsi untuk mengetahui ketinggian/kedalaman
int height(Node *root)
{
       if(root == NULL)
              return -1;
       else{
              int u = height(root->kiri);
        int v = height(root->kanan);
        if(u > v)
          return u + 1;
        else
          return v + 1;
       }
}

//fungsi utama
int main() {
    char pil;
    int del,cari;
    while (true)
    {
        system("cls");
        char data;
        printf("\tPROGRAM BINARY SEARCH TREE");
        printf("\n\t==========================");
        printf("\n\nMENU PILIHAN");
        printf("\n------------\n");
        printf("[1] Tambah Data\n");
        printf("[2] Lihat TREE TRAVERSAL (Pre Order, In Order & Post Order)\n");
        printf("[3] Cari Data\n");
        printf("[4] Kosongkan Data\n");
        printf("[5] Hitung Node & Kedalaman Data\n");
        printf("[X] Keluar\n");
        printf("Pilihan Anda : ");
        scanf("%c",&pil);
        switch(pil) {
           	  case '1':
                     printf("\nTAMBAH DATA");
                     printf("\n-------");
                     printf("\nMasukkan data: ");
                     scanf("%d", &data);
                     //panggil fungsi untuk menambah node yang berisi data pada tree
                     tambah(&pohon,data);
                     _getch();
                      break;

              case '2':
                     printf("\nOUTPUT TRAVERSAL (Pre Order, In Order & Post Order)");
                     printf("\n---------------------------------------------------\n");
                     if(pohon!=NULL) {
					
                           //panggil fungsi untuk mencetak data secara preOrder
                           printf("\nPRE ORDER  : ");
                           preOrder(pohon);
                           printf("\nIN ORDER   : ");
                           inOrder(pohon); 
                           printf("\nPOST ORDER : ");
                           postOrder(pohon); 
                      } else
                           printf("Masih Kosong!!!");
                    
                     _getch();
                     break;
                     
			  case '3':
                    printf("\n\nPENCARIAN DATA");
                    printf("\n--------------");
                     if(pohon!=NULL)
                     {
                           printf("\nMasukkan data yang ingin dicari : ");
                           scanf("%d", &cari);
                           //panggil fungsi untuk melakukan pencarian data pada tree
                           search(&pohon, cari);
                     }
                     else
                           printf("\nMasih kosong!");

                     _getch();
                     break;

              case '4':
                     pohon=NULL;
                     printf("\nPENGOSONGAN DATA ");
                     printf("\n------------------");
                     printf("\nSudah dikosongkan!!");
                     _getch();
                     break;

              case '5':
                     printf("\nJUMLAH NODE DI DALAM TREE");
                     printf("\n-------------------------");
                     printf("\nJumlah Node :  %d", count(pohon));
                     printf("\n\nKEDALAMAN TREE(LEVEL -> DIMULAI DARI 0)");
                     printf("\n----------------------------------------");
                     printf("\nKedalaman tree : %d\n", height(pohon));
                     _getch();
                     break;

              case 'X'|'x':
                     exit(0);
                     break;
                
              default:
              	printf("Pilihan Tidak Tersedia!");
              	break;
              }
       }
}