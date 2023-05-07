/*  File        : MainNRSL.cpp 															 
    Deskripsi   : Driver / main program aplikasi himpunan untuk pendataan UKM di Polban 
    Author      : Kelompok 2B												                
    Tanggal     : 16 APRIL 2023															  
===================================================================================================*/
#include "SpHimpunan.h"
#include "BodyHimpunan.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

int main(){
    superset_list POLBAN;
    subset_list DKM, KEWIRAUSAHAAN, BADMINTON, BASKET, VOLI;
    subset_list POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF;
    subset_list H1, H2;
    create_super(&POLBAN);
    create_sub(&DKM); create_sub(&KEWIRAUSAHAAN);
    create_sub(&BADMINTON); create_sub(&BASKET);
    create_sub(&VOLI); create_sub(&POLBAN_CHESS);
    create_sub(&JFP); create_sub(&ROBOTIK);
    create_sub(&FELLAS); create_sub(&USF);
    int choice, opsi, operasi;
    char nama_mhs[61]; 
	char NIM[10];
    char UKM[20];

    do {
        display_menu();
        printf("Masukkan Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	MenuBuatHimpunan(&POLBAN, &DKM, &KEWIRAUSAHAAN, &BADMINTON, &BASKET, &VOLI, &POLBAN_CHESS, &JFP, &ROBOTIK, &FELLAS, &USF);
                break;
            case 2:
                MenuOperasi(POLBAN, &H1, &H2, DKM,  KEWIRAUSAHAAN,  BADMINTON,  BASKET,  VOLI,  POLBAN_CHESS,  JFP,  ROBOTIK,  FELLAS,  USF);
                break;
            case 3:
            	MenuEditHimpunan(&POLBAN, &DKM, &KEWIRAUSAHAAN, &BADMINTON, &BASKET, &VOLI, &POLBAN_CHESS, &JFP, &ROBOTIK, &FELLAS, &USF, nama_mhs, NIM); break;
            case 4 : search(POLBAN, DKM,  KEWIRAUSAHAAN,  BADMINTON,  BASKET,  VOLI,  POLBAN_CHESS,  JFP,  ROBOTIK,  FELLAS,  USF, nama_mhs, NIM); break;
            case 5 : MenuDisplayHimpunan(POLBAN, DKM,  KEWIRAUSAHAAN,  BADMINTON,  BASKET,  VOLI,  POLBAN_CHESS,  JFP,  ROBOTIK,  FELLAS,  USF, nama_mhs, NIM); break;
            case 6 : PanduanPenggunaan(); TampilkanPanduan(); break;
            //case 7 : display_UKM(DKM);
            //case 8 : DeleteFromUKMFile("Banteng Harisantoso", "221524036", "DKM");
            //case 9 : DisplayHistory();
           }

        printf("\n");
    } while (choice != 99);

	system("pause");
    return 0;
}
	