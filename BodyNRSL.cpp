/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "spnrsll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/********** BODY SUB PROGRAM ***********/

//pembentukan list superset
void create_super (superset_list *S){
    S->first_super = NULL;
}

//pembentukan list subset-1
void CreateSub1 (subset1_list *H1){
    H1->first_sub1 = NULL;
}

//pembentukan list subset-2
void Createsub2 (subset2_list *H2){
    H2->first_sub2 = NULL;
}

//mengecek apakah superset kosong
bool IsSuperEmpty (superset_list S){
    return (S.first_super == NULL);
}

//mengecek apakah subset-1 kosong
bool IsSubAEmpty (subset1_list H1){
    return (H1.first_sub1 == NULL);
}

//mengecek apakah subset-2 kosong
bool IsSubBEmpty (subset2_list H2){
    return (H2.first_sub2 == NULL);
}

//mengecek apakah proses alokasi berhasil atau gagal karena memori yang kurang
bool IsSuperFull() {
    alamatsuper bantu;

    bantu = (alamatsuper) malloc (sizeof(elmtsuper));
    
    if (bantu != NULL) {
        return true;
    } else { 
		return false;
	}
}

// Meminta input dari pengguna dan menambahkan mahasiswa ke dalam superset_list
void add_membersuper(superset_list *S, char nama_mhs[], char NIM[]) {
    printf("/nMasuk Superset");
    alamatsuper P;
//    char* Polban[] = "POLBAN";

    // Mengalokasikan memori untuk node baru
    P = (alamatsuper) malloc(sizeof(elmtsuper));
    
//	P->member_sp = NULL;
//    P->id_member = NULL;
//    P->next_sp = NULL;

    // Mengisi data pada node baru
//    P->nama_super = "POLBAN";
    strcpy(P->member_sp, nama_mhs);
    strcpy(P->id_member, NIM);
    P->next_sp = NULL;

    // Mengecek apakah daftar kosong
    if (IsSuperEmpty(*S)) {
        // Jika daftar kosong, maka node baru akan menjadi head 
        printf("Berhasil Masuk IF\n");
        S->first_super = P;
        S->first_super->next_sp = NULL;
        printf("Berhasil Tambah Node\n");
    }
    else {
        // Menambahkan node baru ke akhir list
        printf("Berhasil Masuk Else\n");
        alamatsuper last;
		last = S->first_super;
        while (last->next_sp != NULL) {
            last = last->next_sp;
        }
        last->next_sp = P;
        last->next_sp->next_sp = NULL;
        printf("Berhasil Masuk Node di Akhir\n");
    }
}

// Memeriksa apakah mahasiswa dengan nama dan NIM yang diberikan sudah terdaftar dalam list
bool isExistSuper(superset_list S, char nama_mhs[], char NIM[]) {
    alamatsuper P;
	P = S.first_super;
    while (P != NULL) {
        if (strcmp(P->member_sp, nama_mhs) == 0 && strcmp(P->id_member, NIM) == 0) {
            return true;
        }
        P = P->next_sp;
    }
    return false;
}

void Seleksi_MemberSuper(superset_list *S){
    char nama_mhs[20];
    int opsi;
    bool syarat = true;

    system("cls");
    printf("Silahkan masukkan nama calon mahasiswa.\n");
    scanf("%s", &nama_mhs);
    // fgets(nama_mhs, sizeof(nama_mhs), stdin);
    while(syarat){
            printf("\n\nApakah calon mahasiswa tersebut lolos seleksi SNMPTN/SBMPTN atau SNMPN/SBMPN atau Ujian Mandiri?\n");
            printf("1. Ya\n2. Tidak\n");
            scanf("%d", &opsi);
            switch (opsi)
            {
            case 1 :
                while(syarat){
                printf("\n\nApakah calon mahasiswa tersebut lolos seleksi berkas administrasi?\n");
                printf("1. Ya\n2. Tidak\n");
                scanf("%d", &opsi);
                    switch (opsi)
                    {
                    case 1:
                        while(syarat){
                        printf("\n\nApakah calon mahasiswa tersebut sudah melunasi pembayaran UKT awal?\n");
                        printf("1. Ya\n2. Tidak\n");
                        scanf("%d", &opsi);
                            switch (opsi)
                            {
                            case 1 :
                                char NIM[10];
                                printf("Silahkan masukkan NIM mahasiswa tersebut!\n");
                                printf("NIM\t:");
                                scanf("%s", &NIM);
                                // fgets(NIM, sizeof(NIM), stdin);
                                if(isExistSuper(*S, nama_mhs, NIM)){
                                   printf("\n\nMahasiswa tersebut sudah terdaftar di POLBAN!"); 
                                }
                                else{
                                    printf("Hai!");
                                    add_membersuper(S, nama_mhs, NIM);
                                    alamatsuper mhs;
                                    mhs = S->first_super;

                                    printf("\n\nCalon mahasiswa telah resmi menjadi mahasiswa POLBAN!");
                                    printf("\nInformasi Mahasiswa:");
                                    printf("\nNama Mahasiswa\t: %s", mhs->member_sp);
                                    printf("\nNIM\t: %s", mhs->id_member);
                                }
                                break;

                                
                            default:
                                syarat = false;
                                printf("\nMasukkan opsi yang valid!");
                            }
                            break;
                        }

                    default:
                        syarat = false;
                        printf("\nMasukkan opsi yang valid!");
                    }
                    break;
                }
                
            default:
                syarat = false;
                printf("\nMasukkan opsi yang valid!");
            }
            break;
    syarat = false;
    }

}

void display_menu() {
    	printf("=========================================\n");
        printf("|        Program Himpunan POLBAN        |\n");
        printf("=========================================\n");
        printf("| Menu: \t\t\t\t|\n");
        printf("| [1] Buat Himpunan \t\t\t|\n");
        printf("| [2] Operasi Himpunan \t\t\t|\n");
        printf("| [3] Edit Daftar Himpunan \t\t|\n");
        printf("| [4] Cari Anggota Himpunan \t\t|\n");
        printf("| [5] Tampilkan Daftar Himpunan \t|\n");
        printf("| [99] Exit \t\t\t\t|\n");
        printf("=========================================\n");
}


