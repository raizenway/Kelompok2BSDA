/*  File        : BodyHimpunan.cpp 															 
    Deskripsi   : Body prototype ADT aplikasi himpunan untuk pendataan UKM di Polban (NRLL) 
    Author      : Kelompok 2B												                
    Tanggal     : 16 APRIL 2023															  
===================================================================================================*/
#include <limits.h>
#include <malloc.h>
#include "SpHimpunan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

/********** BODY SUB PROGRAM ***********/

//pembentukan list superset
void create_super (superset_list *S){
    S->first_super = NULL;
}

//pembentukan list subset-1
void create_sub (subset_list *H1){
    H1->first_sub = NULL;
}

//mengecek apakah superset kosong
bool IsSuperEmpty (superset_list S){
    return (S.first_super == NULL);
}

//mengecek apakah subset-1 kosong
bool IsSubEmpty (subset_list H1){
    return (H1.first_sub == NULL);
}

// Memeriksa apakah mahasiswa dengan nama dan NIM yang diberikan sudah terdaftar dalam list super
bool IsExistSuper(superset_list S, char nama_mhs[], char NIM[]) {
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

bool IsExistSub(subset_list H1, char nama_mhs[], char NIM[]){
    alamatsub P;
    P = H1.first_sub;
    while (P != NULL) {
        if (strcmp(P->member_sub, nama_mhs) == 0 && strcmp(P->id_sub, NIM) == 0) {
            return true;
        }
        P = P->next_sub;
    }
    return false;
}

//mengecek apakah proses alokasi berhasil atau gagal karena memori yang kurang
bool IsFull() {
    alamatsuper bantu;
    bantu = (alamatsuper) malloc (sizeof(elmtsuper));
    
    if (bantu != NULL) {
        return false;
    } else { 
		return true;
	}
}

// Meminta input dari pengguna dan menambahkan mahasiswa ke dalam superset_list
void add_membersuper(superset_list *S, char nama_mhs[], char NIM[]) {
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : List POLBAN mungkin kosong
    FS          : Melakukan alokasi dan menambahkan node baru di salah satu list superset.
    DESKRIPSI   : Prosedur untuk mengalokasikan dan menambahkan Mahasiswa baru ke Polban.
                  Informasi yang ada adalah Nama, NIM.
=======================================================================================================================*/
    alamatsuper P;
    P = (alamatsuper) malloc(sizeof(elmtsuper));
    strcpy(P->member_sp, nama_mhs);
    strcpy(P->id_member, NIM);
    P->next_sp = NULL;

    //Mengecek apakah memori penuh
    if(IsFull()){
        printf("Memori penuh!\n");
    }
    else{
    // Mengecek apakah daftar kosong
    if (IsSuperEmpty(*S)) {
        // Jika daftar kosong, maka node baru akan menjadi head
        S->first_super = P;
        S->first_super->next_sp = NULL;
    }
    else {
        // Menambahkan node baru ke akhir list
        alamatsuper last;
		last = S->first_super;
        while (last->next_sp != NULL) {
            last = last->next_sp;
        }
        last->next_sp = P;
        last->next_sp->next_sp = NULL;
    }
    }
    
}

/* Menambah member subset*/
void add_membersub(subset_list *H1, char nama_mhs[], char NIM[], char UKM[])
/*  AUTHOR      : Banteng Harisantoso
    IS          : H1 mungkin kosong
    FS          : Melakukan alokasi dan menambahkan node baru di salah satu list subset
    DESKRIPSI   : Prosedur untuk mengalokasikan dan menambahkan Mahasiswa baru ke salah satu UKM.
                  Informasi yang ada adalah Nama, NIM, dan Nama UKM 
=======================================================================================================================*/
{
    
    alamatsub P;
    P = (alamatsub) malloc(sizeof(elmtsubset));
    strcpy(P->member_sub, nama_mhs);
    strcpy(P->id_sub, NIM); 
    strcpy(P->nama_sub, UKM);
    P->next_sub = NULL;
    //Mengecek apakah memori penuh
    if(IsFull()){
        printf("Memori penuh!\n");
    }
    else{
    // Mengecek apakah daftar kosong
    if (IsSubEmpty(*H1)) {
        // Jika daftar kosong, maka node baru akan menjadi head
        H1->first_sub = P;
        H1->first_sub->next_sub = NULL;
    }
    else {
        // Menambahkan node baru ke akhir list
        alamatsub last;
		last = H1->first_sub;
        while (last->next_sub != NULL) {
            last = last->next_sub;
        }
        last->next_sub = P;
        last->next_sub->next_sub = NULL;
    }
    }

}
   

void display_membersuper(superset_list S) {
    int i = 1;
    alamatsuper P;
    P = S.first_super;
    printf("\nMahasiswa yang terdaftar di POLBAN adalah : \n");
    while (P != NULL) {
        printf("%d. %s - %s\n", i, P->id_member, P->member_sp);
        P = P->next_sp;
        i++;
    }
    system("pause");
}

void display_membersubset(subset_list H){
    int i = 1;
    alamatsub P;
    P = H.first_sub;
    printf("Mahasiswa yang terdaftar di %s :\n", P->nama_sub);
    while(P != NULL) {
        printf("%d. %s - %s\n", i, P->id_sub, P->member_sub);
        P = P->next_sub;
        i++;
    }
    system("pause");
}

void MenuDisplayHimpunan(superset_list POLBAN, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF) {
/*  AUTHOR      : Bob Manuel
    IS          : List superset POLBAN dan subset UKM sudah terbentuk
    FS          : Menampilkan setiap anggota superset POLBAN ataupun setiap anggota dari subset UKM
    DESKRIPSI   : Prosedur untuk masuk ke menu menampilkan mahasiswa dalam superset POLBAN,
                  pengguna akan diarahkan dengan pengkondisian (if else) untuk memilih superset atau subset yang akan ditampilkan anggotanya,
                  Setelahnya, akan menampilkan anggota sesuai opsi yang dipilih
=======================================================================================================================*/ 
    bool valid = false;
    int menu = 0;

    while (!valid) {
        system("cls");
        printf("=========================================\n");
        printf("|\t[5] Display Himpunan\t\t|\n");
        printf("=========================================\n");
        printf("| Menu: \t\t\t\t|\n");
        printf("| [1] Display Mahasiswa POLBAN \t\t|\n");
        printf("| [2] Display Anggota UKM POLBAN \t|\n");
        printf("| [99] Back \t\t\t\t|\n");
        printf("=========================================\n");
        scanf("%d", &menu);

        if(menu == 1){
            if(IsSuperEmpty(POLBAN)){
                printf("\nTidak ada mahasiswa yang terdata.\n"); system("pause");
                valid = true;
            }else{
                display_membersuper(POLBAN);
                valid = true;
            }
            
        }else if(menu == 2){
            int opsi = ListUKM();

            if (opsi == 1) {
                if(IsSubEmpty(DKM)){
                    printf("Tidak ada mahasiswa yang terdata di %s", DKM.first_sub->nama_sub); system("pause");
                    valid = true;
                }else{
                    display_membersubset(DKM);
                    valid = true;
                }
                
            } else if (opsi == 2) {
                if(IsSubEmpty(KEWIRAUSAHAAN)){
                    printf("Tidak ada mahasiswa yang terdata di %s", KEWIRAUSAHAAN.first_sub->nama_sub);system("pause");
                    valid = true;
                }else{
                    display_membersubset(KEWIRAUSAHAAN);
                    valid = true;
                }
            } else if (opsi == 3) {
                if(IsSubEmpty(BADMINTON)){
                    printf("Tidak ada mahasiswa yang terdata di %s", BADMINTON.first_sub->nama_sub);system("pause");
                    valid = true;
                }else{
                    display_membersubset(BADMINTON);
                    valid = true;
                }
            } else if (opsi == 4) {
                if(IsSubEmpty(BASKET)){
                    printf("Tidak ada mahasiswa yang terdata di %s", BASKET.first_sub->nama_sub);system("pause");
                    valid = true;
                }else{
                    display_membersubset(BASKET);
                    valid = true;
                }
            } else if (opsi == 5) {
                if(IsSubEmpty(VOLI)){
                    printf("Tidak ada mahasiswa yang terdata di %s", VOLI.first_sub->nama_sub);system("pause");
                    valid = true;
                }else{
                    display_membersubset(VOLI);
                    valid = true;
                }
            } else if (opsi == 6) {
                if(IsSubEmpty(POLBAN_CHESS)){
                    printf("Tidak ada mahasiswa yang terdata di %s", POLBAN_CHESS.first_sub->nama_sub);system("pause");
                    valid = true;
                }else{
                    display_membersubset(POLBAN_CHESS);
                    valid = true;
                }
            } else if (opsi == 7) {
                if(IsSubEmpty(JFP)){
                    printf("Tidak ada mahasiswa yang terdata di %s", JFP.first_sub->nama_sub);system("pause");
                    valid = true;
                }else{
                    display_membersubset(JFP);
                    valid = true;
                }
            } else if (opsi == 8) {
                if(IsSubEmpty(ROBOTIK)){
                    printf("Tidak ada mahasiswa yang terdata di %s", ROBOTIK.first_sub->nama_sub);system("pause");
                    valid = true;
                }else{
                    display_membersubset(ROBOTIK);
                    valid = true;
                }
            } else if (opsi == 9) {
                if(IsSubEmpty(FELLAS)){
                    printf("Tidak ada mahasiswa yang terdata di %s", FELLAS.first_sub->nama_sub);system("pause");
                    valid = true;
                }else{
                    display_membersubset(FELLAS);
                    valid = true;
                }
            } else if (opsi == 10) {
                if(IsSubEmpty(USF)){
                    printf("Tidak ada mahasiswa yang terdata di %s", USF.first_sub->nama_sub);system("pause");
                    valid = true;
                }else{
                    display_membersubset(USF);
                    valid = true;
                }
            }
        }else if(menu == 99){
            valid = true; break;
        } else{
            printf("Masukkan opsi yang valid!\n"); system("pause");
        }
        
    }  
    
}

int ListUKM()
/*  AUTHOR      : Banteng Harisantoso
    IS          : ListUKM bernilai tidak tentu
    FS          : ListUKM bernilai antara 1-10
    DESKRIPSI   : Fungsi untuk memilih opsi ukm dan mengembalikan nilai integer
                  dari 1-10
=======================================================================================================================*/
{

        printf("| Pilih salah satu UKM di bawah:\t|\n");
        printf("| [1] DKM \t\t\t\t|\n");
        printf("| [2] KEWIRAUSAHAAN \t\t\t|\n");
        printf("| [3] BADMINTON \t\t\t|\n");
        printf("| [4] BASKET \t\t\t\t|\n");
        printf("| [5] VOLI \t\t\t\t|\n");
        printf("| [6] POLBAN CHESS \t\t\t|\n");
        printf("| [7] JFP \t\t\t\t|\n");
        printf("| [8] ROBOTIK \t\t\t\t|\n");
        printf("| [9] FELLAS \t\t\t\t|\n");
        printf("| [10] USF \t\t\t\t|\n");
        printf("=========================================\n");
        
        int opsi;
        printf("Opsi: ");
        scanf("%d", &opsi);
        while ((opsi < 1)||(opsi > 10))
        {   
            printf("\nOpsi tidak valid\n");
            printf("Opsi: ");
            scanf("%d", &opsi);
        }

        return opsi;
}   

void MenuBuatHimpunan(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF)
/*  AUTHOR      : Banteng Harisantoso
    IS          : List POLBAN dan 10 UKM telah dibuat baik sudah berisi atau belum
    FS          : Menampilkan menu untuk melakukan pendataan mahasiswa
    DESKRIPSI   : Prosedur untuk menampilkan menu dan opsi-opsi dalam melakukan pendataan
                  mahasiswa. Terdapat dua pendataan, pendataan mahasiswa POLBAN dan anggota UKM
=======================================================================================================================*/
{
    int opsi;
    system("cls");
        printf("=========================================\n");
        printf("|\t[1] Pendataan Mahasiswa\t\t|\n");
        printf("=========================================\n");
        printf("| Menu: \t\t\t\t|\n");
        printf("| [1] Tambah Mahasiswa POLBAN \t\t|\n");
        printf("| [2] Tambah Anggota UKM POLBAN \t|\n");
        printf("| [3] Ekstrak Mahasiswa POLBAN \t\t|\n");
        printf("| [4] Ekstrak Anggota UKM POLBAN \t|\n");
        printf("| [99] Back \t\t\t\t|\n");
        printf("=========================================\n");
    scanf("%d", &opsi);
    switch (opsi){
        case 1: Seleksi_MemberSuper(POLBAN);  break;
        case 2: MenuAddSub(*POLBAN, DKM, KEWIRAUSAHAAN, BADMINTON, BASKET, VOLI, POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF); break;
        case 3: EkstrakPOLBAN(POLBAN); break;
        case 4: EkstrakUKM(*POLBAN, DKM, KEWIRAUSAHAAN, BADMINTON, BASKET, VOLI, POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF); break;
        case 99 :
            break;
    }
}

void MenuEditHimpunan(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF) {
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : Sudah terbentuk list subset
    FS          : Menampilkan pesan berhasil atau gagal menghapus atau mengubah data mahasiswa ke dalam himpunan.
    DESKRIPSI   : Prosedur untuk memilih menu penghapusan atau pengubahan mahasiswa dari list UKM maupun list POLBAN.
=======================================================================================================================*/

    int opsi;
        system("cls");
        printf("=========================================\n");
        printf("|\t[1] Edit Himpunan\t\t|\n");
        printf("=========================================\n");
        printf("| Menu: \t\t\t\t|\n");
        printf("| [1] Hapus Mahasiswa POLBAN \t\t|\n");
        printf("| [2] Hapus Anggota UKM POLBAN \t\t|\n");
        printf("| [3] Edit Mahasiswa POLBAN \t\t|\n");
        printf("| [99] Back \t\t\t\t|\n");
        printf("=========================================\n");
    scanf("%d", &opsi);
    switch (opsi){
        case 1:
            Penghentian_Studi(POLBAN); break;
            break;
        case 2: 
            MenuEditSub(*POLBAN, DKM, KEWIRAUSAHAAN, BADMINTON, BASKET, VOLI, POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF); break;
            break;
        case 3:
            MenuEditMahasiswa(POLBAN, DKM, KEWIRAUSAHAAN, BADMINTON, BASKET, VOLI, POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF); break;
        case 99 :
            break;
    }
}

void Seleksi_MemberSuper(superset_list *S)
/*  AUTHOR      : Banteng Harisantoso
    IS          : Sudah terbentuk list superset
    FS          : Menampilkan pesan berhasil atau gagal menambahkan mahasiswa ke dalam list POLBAN
    DESKRIPSI   : Prosedur untuk masuk ke menu penambahan mahasiswa dengan syarat-syarat POLBAN,
                  pengguna akan diarahkan ke switch, jika memilih 1 berturut-turut maka calon mahasiswa dapat menjadi mahasiswa
                  POLBAN. Namun, jika mahasiswa tidak lolos salah satu persyaratan maka calon mahasiswa belum bisa menjadi
                  mahasiswa POLBAN
=======================================================================================================================*/
{
    char nama_mhs[61];
    int jumlah;
    int opsi = 0;
    bool syarat = true;
    do
    {
        system("cls");
        printf("=========================================\n");
        printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
        printf("=========================================\n");
        printf("| Berapa banyak calon mahasiswa \t|\n");
        printf("| yang ingin didata? \t\t\t|\n");
        printf("=========================================\n");
        printf("Jumlah : ");
        scanf("%d", &jumlah);
        if((jumlah <=0)||(jumlah>=100)){
            printf("\nJumlah tidak valid, minimal 1 mahasiswa dan maksimal 100 mahasiswa persesi!\n");
        }
    } while ((jumlah <= 0)||(jumlah>=100));
    
    
    for(int i=0;i<jumlah;i++){
    system("cls");
    printf("=========================================\n");
    printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
    printf("=========================================\n");
    printf("| Masukkan nama calon mahasiswa \t|\n");
    printf("=========================================\n");
    addnama(nama_mhs);
    while(syarat){
            system("cls");
            printf("=========================================\n");
            printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
            printf("=========================================\n");
            printf("| Apakah calon mahasiswa tersebut lolos\t|\n");
            printf("| seleksi SNMPTN/SBMPTN atau SNMPN/\t|\n");
            printf("| SBMPN atau Ujian Mandiri?\t\t|\n");
            printf("| 1. Ya 2. Tidak\t\t\t|\n");
            printf("=========================================\n");
            printf("Opsi: "); scanf("%d", &opsi);
            switch (opsi)
            {
            case 1 :
                while(syarat){
                system("cls");
                printf("=========================================\n");
                printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
                printf("=========================================\n");
                printf("| Apakah calon mahasiswa tersebut lolos\t|\n");
                printf("| seleksi berkas administrasi?\t\t|\n");
                printf("| 1. Ya 2. Tidak\t\t\t|\n");
                printf("=========================================\n");
                printf("Opsi: "); scanf("%d", &opsi);    
                    switch (opsi)
                    {
                    case 1:
                        while(syarat){
                        system("cls");
                        printf("=========================================\n");
                        printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
                        printf("=========================================\n");
                        printf("| Apakah calon mahasiswa tersebut sudah\t|\n");
                        printf("| melunasi pembayaran UKT awal?/\t|\n");
                        printf("| 1. Ya 2. Tidak\t\t\t|\n");
                        printf("=========================================\n");
                        printf("Opsi: "); scanf("%d", &opsi);
                            switch (opsi)
                            {
                            case 1 :
                                char NIM[10];
                                system("cls");
                                printf("=========================================\n");
                                printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
                                printf("=========================================\n");
                                printf("| Mahasiswa lolos persyaratan POLBAN! \t|\n");
                                printf("| Masukkan NIM mahasiswa tersebut\t|\n");
                                printf("=========================================\n");
                                addnim(NIM);
                                if(IsExistSuper(*S, nama_mhs, NIM)){
                                   printf("\n\nMahasiswa tersebut sudah terdaftar di POLBAN!");
                                   system("pause");
                                }
                                else{
                                    add_membersuper(S, nama_mhs, NIM);
                                    system("cls");
                                    printf("Calon mahasiswa telah resmi menjadi mahasiswa POLBAN\t\t\n");
                                    printf("=========================================\n");
                                    printf("|\t INFORMASI MAHASISWA \t\t|\n");
                                    printf("=========================================\n");
                                    printf(" Nama\t\t: %.*s.\n", 20, nama_mhs);
                                    printf(" NIM\t\t: %s\n\n", NIM);
                                    WritePOLBAN(nama_mhs, NIM);
                                    //menulis history
                                    char pesan[100];
                                    sprintf(pesan, "%s (%s) telah resmi menjadi mahasiswa POLBAN", nama_mhs, NIM);
                                    WriteHistory(pesan);
                                    system("pause");
                                }
                                syarat = false;
                                break;

                            case 2 :
                            printf("\nMahasiswa belum memenuhi persyaratan!");
                            system("pause");
                            syarat = false;
                            break;

                            default:
                                printf("\nMasukkan opsi yang valid!");
                                system("pause");
                            }
                        }
                    break;
                    case 2 :
                        printf("\nMahasiswa belum memenuhi persyaratan!");
                        system("pause");
                        syarat = false;
                        break;
                    default:
                        printf("\nMasukkan opsi yang valid!");
                        system("pause");
                    }
                }

            break;
            case 2 :
               printf("\nMahasiswa belum memenuhi persyaratan!\n");
               system("pause");
               syarat = false;
               break;
            default:
                printf("\nMasukkan opsi yang valid!\n");
                system("pause");
            }

    }
    syarat = true;
    }
    
}

void MenuAddSub(superset_list POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF)
/*  AUTHOR      : Banteng Harisantoso
    IS          : Sudah terbentuk list subset
    FS          : Menampilkan pesan berhasil atau gagal menambahkan mahasiswa ke dalam himp
    DESKRIPSI   : Prosedur untuk masuk ke menu penambahan mahasiswa ke pilihan UKM
=======================================================================================================================*/
{
system("cls");
char nama_mhs[61];
char NIM[10];
bool valid = false;
int jumlah = 0;

while(!valid){
    
    printf("============================ Menu Pendataan Anggota UKM ===================================\n");
    int opsi = ListUKM();
    if(opsi==1){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan DKM: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*DKM, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan DKM!\n\n");
            } 
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(DKM, nama_mhs, NIM, "DKM");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan DKM!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan DKM", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;        
        break;
    }else if(opsi==2){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan KEWIRAUSAHAAN: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*KEWIRAUSAHAAN, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan KEWIRAUSAHAAN!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(KEWIRAUSAHAAN, nama_mhs, NIM, "KEWIRAUSAHAAN");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan KEWIRAUSAHAAN!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan KEWIRAUSAHAAN", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==3){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan BADMINTON: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*BADMINTON, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan BADMINTON!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(BADMINTON, nama_mhs, NIM, "BADMINTON");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan BADMINTON!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan BADMINTON", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==4){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan BASKET: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*BASKET, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan BASKET!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(BASKET, nama_mhs, NIM, "BASKET");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan BASKET!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan BASKET", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break; 
    }else if(opsi==5){
       printf("Masukkan jumlah mahasiswa yang akan bergabung dengan VOLI: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*VOLI, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan VOLI!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(VOLI, nama_mhs, NIM, "VOLI");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan VOLI!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan VOLI", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break; 
    }else if(opsi==6){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan POLBAN CHESS: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*POLBAN_CHESS, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan POLBAN CHESS!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(POLBAN_CHESS, nama_mhs, NIM, "POLBAN_CHESS");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan POLBAN CHESS!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan POLBAN CHESS", nama_mhs, NIM);
                WriteHistory(pesan);
            }            
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==7){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan JFP: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*JFP, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan JFP!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(JFP, nama_mhs, NIM, "JFP");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan JFP!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan JFP", nama_mhs, NIM);
                WriteHistory(pesan);
            }   
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==8){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan ROBOTIK: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*ROBOTIK, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan ROBOTIK!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(ROBOTIK, nama_mhs, NIM, "ROBOTIK");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan ROBOTIK!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan ROBOTIK", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==9){
       printf("Masukkan jumlah mahasiswa yang akan bergabung dengan FELLAS: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*FELLAS, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan FELLAS!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(FELLAS, nama_mhs, NIM, "FELLAS");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan FELLAS!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan FELLAS", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break; 
    }else if(opsi==10){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan USF: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*USF, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan USF!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(USF, nama_mhs, NIM, "USF");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan USF!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
                char pesan[100];
                sprintf(pesan, "%s (%s) telah bergabung dengan USF", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break; 
    }
    }
    system("pause");
}

void MenuEditSub(superset_list POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF)
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : Sudah terbentuk list subset
    FS          : Menampilkan pesan berhasil atau gagal menghapus atau mengubah data mahasiswa ke dalam himpunan.
    DESKRIPSI   : Prosedur untuk masuk ke menu penghapusan atau pengubahan mahasiswa dari list UKM maupun list POLBAN.
=======================================================================================================================*/
{
system("cls");
char nama_mhs[61];
char NIM[10];
bool valid = false;
int jumlah = 0;

while(!valid){
    
    printf("============================ Menu Update Anggota UKM ===================================\n");
    int opsi = ListUKM();
    if(opsi==1){
        printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM DKM: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*DKM, nama_mhs, NIM)){
                del_membersub(DKM, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "DKM");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari DKM", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
            }
        }
        valid = true;        
        break;
    }else if(opsi==2){
        printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM KEWIRAUSAHAAN: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*KEWIRAUSAHAAN, nama_mhs, NIM)){
                del_membersub(KEWIRAUSAHAAN, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "KEWIRAUSAHAAN");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari KEWIRAUSAHAAN", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
            }
        }
        valid = true;
        break;
    }else if(opsi==3){
        printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM BADMINTON: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*BADMINTON, nama_mhs, NIM)){
                del_membersub(BADMINTON, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "BADMINTON");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari BADMINTON", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
            }
        }
        valid = true;
        break;
    }else if(opsi==4){
        printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM BASKET: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*BASKET, nama_mhs, NIM)){
                del_membersub(BASKET, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "BASKET");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari BASKET", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
            }
        }
        valid = true;
        break; 
    }else if(opsi==5){
       printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM VOLI: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*VOLI, nama_mhs, NIM)){
                del_membersub(VOLI, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "VOLI");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari VOLI", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
            }
        }
        valid = true;
        break; 
    }else if(opsi==6){
        printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM POLBAN CHESS: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*POLBAN_CHESS, nama_mhs, NIM)){
                del_membersub(POLBAN_CHESS, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "POLBAN_CHESS");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari POLBAN CHESS", nama_mhs, NIM);
                WriteHistory(pesan);
            }       
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
            }
        }
        valid = true;
        break;
    }else if(opsi==7){
        printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM JFP: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*JFP, nama_mhs, NIM)){
                del_membersub(JFP, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "JFP");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari JFP", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
            }
        }
        valid = true;
        break;
    }else if(opsi==8){
        printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM ROBOTIK: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*ROBOTIK, nama_mhs, NIM)){
                del_membersub(ROBOTIK, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "ROBOTIK");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari ROBOTIK", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
            }
        }
        valid = true;
        break;
    }else if(opsi==9){
       printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM FELLAS: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*FELLAS, nama_mhs, NIM)){
                del_membersub(FELLAS, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "FELLAS");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari FELLAS", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
                
            }
        }
        valid = true;
        break; 
    }else if(opsi==10){
        printf("Masukkan jumlah mahasiswa yang akan dihapus dari UKM USF: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*USF, nama_mhs, NIM)){
                del_membersub(USF, nama_mhs, NIM);
                DeleteFromUKMFile(nama_mhs, NIM, "USF");
                char pesan[100];
                sprintf(pesan, "%s (%s) telah dikeluarkan dari USF", nama_mhs, NIM);
                WriteHistory(pesan);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
                system("pause");
            }
        }
        valid = true;
        break; 
    }
    }
    system("pause");
}

void addnama(char* nama_mhs)
/*  AUTHOR      : Banteng Harisantoso
    IS          : nama_mhs sudah di deklarasikan
    FS          : nama_mhs sudah diberi nilai sesuai dengan inputan dari pengguna
    DESKRIPSI   : Prosedur untuk menginput nama_mhs dari pengguna, nama mahasiswa
                  maksimal terdiri dari 61 karakter (termasuk spasi)
=======================================================================================================================*/
{
    bool valid = false;
    while(!valid){
        
        printf("Masukkan nama mahasiswa\t: ");
        scanf(" %[^\n]", nama_mhs);
        getchar();
        if(strlen(nama_mhs) > 60){
            printf("Nama mahasiswa terlalu panjang!\n");
        }
        else{
            valid = true;
        }
    }

}


void addnim(char* NIM)
/*  AUTHOR      : Banteng Harisantoso
    IS          : NIM sudah di deklarasikan
    FS          : NIM sudah diberi nilai sesuai dengan inputan dari pengguna
    DESKRIPSI   : Prosedur untuk menginput NIM dari pengguna, nama mahasiswa
                  maksimal terdiri dari 9 karakter
=======================================================================================================================*/

{
    bool valid = false;

    while(!valid){
        printf("Masukkan NIM\t\t: ");
        scanf("%s", NIM);
        getchar();
        if(strlen(NIM) > 9){
            printf("NIM terlalu panjang!\n");
        }
        else{
            valid = true;
        }
    }

}


void del_membersuper(superset_list *S, char nama_mhs[], char NIM[]) {
/*  AUTHOR      : Bob Manuel
    IS          : List superset sudah terbentuk dan memiliki isi sebagai anggota superset atau masih kosong
    FS          : List yang berisi nama dan NIM yang ingin dihapus berhasil dihapus
    DESKRIPSI   : Prosedur untuk menghapus suatu node berdasarkan nama mahasiswa dan nim.
                  Node sebelumnya akan terhubung dengan node setelah node yang dihapus.
    =======================================================================================================================*/
    alamatsuper P, Q;
    P = S->first_super;
    Q = NULL;
    while (P != NULL) {
        if (strcmp(P->member_sp, nama_mhs) == 0 && strcmp(P->id_member, NIM) == 0) {
            if (Q == NULL) {
                S->first_super = P->next_sp;
            } else {
                Q->next_sp = P->next_sp;
            }
            free(P);
            return;
        }
        Q = P;
        P = P->next_sp;
    }
}

void del_membersub(subset_list *H1, char nama_mhs[], char NIM[])
/*  AUTHOR      : Bob Manuel
    IS          : List subset sudah terbentuk dan memiliki isi sebagai anggota subset atau masih kosong 
    FS          : List yang berisi nama dan NIM yang ingin dihapus berhasil dihapus
    DESKRIPSI   : Prosedur untuk menghapus suatu node berdasarkan nama mahasiswa dan nim.
                  Node sebelumnya akan terhubung dengan node setelah node yang dihapus.
    =======================================================================================================================*/
    {
    alamatsub P, Q;
    P = H1->first_sub;
    Q = NULL;
    while (P != NULL) {
        if (strcmp(P->member_sub, nama_mhs) == 0 && strcmp(P->id_sub, NIM) == 0) {
            if (Q == NULL) {
                H1->first_sub = P->next_sub;
            } else {
                Q->next_sub = P->next_sub;
            }
            free(P);
            printf("Anggota %s bernama %s (%s) telah dihapus!\n", P->nama_sub, nama_mhs, NIM);
            return;
        }
        Q = P;
        P = P->next_sub;
    }
    printf("Anggota %s bernama %s (%s) tidak ditemukan!\n", P->nama_sub, nama_mhs, NIM);
}


void Penghentian_Studi(superset_list *S)
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : Sudah terbentuk list superset
    FS          : Menampilkan pesan berhasil atau gagal menghapus mahasiswa ke dalam list POLBAN
    DESKRIPSI   : Prosedur untuk masuk ke menu penghapusan mahasiswa dengan syarat-syarat POLBAN,
                  pengguna akan diarahkan ke kondisi if else, jika salah satu kondisi memenuhi,
                  maka akan memanggil modul untuk menghapus anggota dari List POLBAN.
=======================================================================================================================*/
{
    int jumlah;
    char jawaban[5]; // variabel untuk menyimpan jawaban
    char nama_mhs[61];
    char NIM[61];

    printf("Berapa banyak mahasiswa yang ingin dihapus?\n");
    scanf("%d", &jumlah);
    while((jumlah == 0)||(jumlah<0)){
        printf("Jumlah tidak valid! Silahkan masukkan jumlah yang valid.\n");
        scanf("%d", &jumlah);
    }

    for(int i=0;i<jumlah;i++){
        system("cls");
        addnama(nama_mhs);
        addnim(NIM);
        if(IsExistSuper(*S, nama_mhs, NIM)){
            printf("Silakan jawab dengan ya atau tidak.\n");
            // pertanyaan 1
            printf("Apakah mahasiswa dua semester berturut-turut lulus percobaan sampai dengan semester IV untuk mahasiswa Program Diploma III dan semester VI untuk mahasiswa Program Diploma IV?\n");
            scanf("%s", jawaban);
            while (strcmp(jawaban, "ya") != 0 && strcmp(jawaban, "tidak") != 0) {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                printf("Apakah mahasiswa dua semester berturut-turut lulus percobaan sampai dengan semester IV untuk mahasiswa Program Diploma III dan semester VI untuk mahasiswa Program Diploma IV?\n");
                scanf("%s", jawaban);
            }
            if (strcmp(jawaban, "ya") == 0) {
                    del_membersuper(S, nama_mhs, NIM);
                    DeleteFromPOLBANFile(nama_mhs, NIM);
                    printf("Mahasiswa %s dengan NIM telah dihapus dari daftar anggota POLBAN.\n", nama_mhs, NIM);
                    char pesan[100];
                    sprintf(pesan, "%s (%s) telah dikeluarkan dari POLBAN!\n", nama_mhs, NIM);
                    WriteHistory(pesan);
                    system("pause");
                    return;
            }  else if (strcmp(jawaban, "tidak") == 0) {

            }

            // pertanyaan 2
            printf("Apakah Indeks Prestasi (IP) mahasiswa berada di antara 1,70 dan 2,00 dan jumlah SKS nilai D lebih dari 7 SKS?\n");
            scanf("%s", jawaban);
            while (strcmp(jawaban, "ya") != 0 && strcmp(jawaban, "tidak") != 0) {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                printf("Apakah Indeks Prestasi (IP) mahasiswa berada di antara 1,70 dan 2,00 dan jumlah SKS nilai D lebih dari 7 SKS?\n");
                scanf("%s", jawaban);
            }
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                    DeleteFromPOLBANFile(nama_mhs, NIM);
                    printf("Mahasiswa %s dengan NIM telah dihapus dari daftar anggota POLBAN.\n", nama_mhs, NIM);
                    char pesan[100];
                    sprintf(pesan, "%s (%s) telah dikeluarkan dari POLBAN!\n", nama_mhs, NIM);
                    WriteHistory(pesan);
                    system("pause");
                    return;
            } else if (strcmp(jawaban, "tidak") == 0) {

            }

            // pertanyaan 3
            printf("Apakah nilai IP mahasiswa di bawah 1,70?\n");
            scanf("%s", jawaban);
            while (strcmp(jawaban, "ya") != 0 && strcmp(jawaban, "tidak") != 0) {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                printf("Apakah nilai IP mahasiswa di bawah 1,70?\n");
                scanf("%s", jawaban);
            }
            if (strcmp(jawaban, "ya") == 0) {
                    del_membersuper(S, nama_mhs, NIM);
                    DeleteFromPOLBANFile(nama_mhs, NIM);
                    printf("Mahasiswa %s dengan NIM telah dihapus dari daftar anggota POLBAN.\n", nama_mhs, NIM);
                    char pesan[100];
                    sprintf(pesan, "%s (%s) telah dikeluarkan dari POLBAN!\n", nama_mhs, NIM);
                    WriteHistory(pesan);
                    system("pause");
                    return;
            } else if (strcmp(jawaban, "tidak") == 0) {

            }

            // pertanyaan 4
            printf("Apakah mahasiswa tidak memenuhi syarat kelulusan pada semester VI untuk mahasiswa Program Diploma III dan pada semester VIII untuk mahasiswa Program Diploma IV, setelah diberi kesempatan mengulang satu kali?\n");
            scanf("%s", jawaban);
            while (strcmp(jawaban, "ya") != 0 && strcmp(jawaban, "tidak") != 0) {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                printf("Apakah mahasiswa tidak memenuhi syarat kelulusan pada semester VI untuk mahasiswa Program Diploma III dan pada semester VIII untuk mahasiswa Program Diploma IV, setelah diberi kesempatan mengulang satu kali?\n");
                scanf("%s", jawaban);
            }
            if (strcmp(jawaban, "ya") == 0) {
                    del_membersuper(S, nama_mhs, NIM);
                    DeleteFromPOLBANFile(nama_mhs, NIM);
                    printf("Mahasiswa %s dengan NIM telah dihapus dari daftar anggota POLBAN.\n", nama_mhs, NIM);
                    char pesan[100];
                    sprintf(pesan, "%s (%s) telah dikeluarkan dari POLBAN!\n", nama_mhs, NIM);
                    WriteHistory(pesan);
                    system("pause");
                    return;
            } else if (strcmp(jawaban, "tidak") == 0) {

            } 

            // pertanyaan 5
            printf("Apakah mahasiswa mempunyai nilai E pada semester I sampai dengan IV untuk mahasiswa Program Diploma III dan semester I sampai IV?\n");
            scanf("%s", jawaban);
            while (strcmp(jawaban, "ya") != 0 && strcmp(jawaban, "tidak") != 0) {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                printf("Apakah mahasiswa mempunyai nilai E pada semester I sampai dengan IV untuk mahasiswa Program Diploma III dan semester I sampai IV?\n");
                scanf("%s", jawaban);
            }
            if (strcmp(jawaban, "ya") == 0) {
                    del_membersuper(S, nama_mhs, NIM);
                    DeleteFromPOLBANFile(nama_mhs, NIM);
                    printf("Mahasiswa %s dengan NIM telah dihapus dari daftar anggota POLBAN.\n", nama_mhs, NIM);
                    char pesan[100];
                    sprintf(pesan, "%s (%s) telah dikeluarkan dari POLBAN!\n", nama_mhs, NIM);
                    WriteHistory(pesan);
                    system("pause");
                    return;
            } else if (strcmp(jawaban, "tidak") == 0) {

            } 

            // pertanyaan 6
            printf("Apakah mahasiswa melewati batas studi yang telah ditetapkan dalam Pasal 18 Ayat 1 dan 2?\n");
            scanf("%s", jawaban);
            while (strcmp(jawaban, "ya") != 0 && strcmp(jawaban, "tidak") != 0) {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                printf("Apakah mahasiswa melewati batas studi yang telah ditetapkan dalam Pasal 18 Ayat 1 dan 2?\n");
                scanf("%s", jawaban);
            }
            if (strcmp(jawaban, "ya") == 0) {
                    del_membersuper(S, nama_mhs, NIM);
                    DeleteFromPOLBANFile(nama_mhs, NIM);
                    printf("Mahasiswa %s dengan NIM telah dihapus dari daftar anggota POLBAN.\n", nama_mhs, NIM);
                    char pesan[100];
                    sprintf(pesan, "%s (%s) telah dikeluarkan dari POLBAN!\n", nama_mhs, NIM);
                    WriteHistory(pesan);
                    system("pause");
                    return;
            } else if (strcmp(jawaban, "tidak") == 0) {

            } 

            // pertanyaan 7
            printf("Apakah mahasiswa memiliki status ketidakhadiran yang tidak diperbolehkan, sebagaimana diatur dalam Pasal 22?\n");
            scanf("%s", jawaban);
            while (strcmp(jawaban, "ya") != 0 && strcmp(jawaban, "tidak") != 0) {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                printf("Apakah mahasiswa memiliki status ketidakhadiran yang tidak diperbolehkan, sebagaimana diatur dalam Pasal 22?\n");
                scanf("%s", jawaban);
            }
            if (strcmp(jawaban, "ya") == 0) {
                    del_membersuper(S, nama_mhs, NIM);
                    DeleteFromPOLBANFile(nama_mhs, NIM);
                    printf("Mahasiswa %s dengan NIM telah dihapus dari daftar anggota POLBAN.\n", nama_mhs, NIM);
                    char pesan[100];
                    sprintf(pesan, "%s (%s) telah dikeluarkan dari POLBAN!\n", nama_mhs, NIM);
                    WriteHistory(pesan);
                    system("pause");
                    return;
            } else if (strcmp(jawaban, "tidak") == 0) {

            } 

            // pertanyaan 8
            printf("Apakah mahasiswa terlibat dalam perbuatan kriminal yang dinyatakan oleh pihak berwajib?\n");
            scanf("%s", jawaban);
            while (strcmp(jawaban, "ya") != 0 && strcmp(jawaban, "tidak") != 0) {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                printf("Apakah mahasiswa terlibat dalam perbuatan kriminal yang dinyatakan oleh pihak berwajib?\n");
                scanf("%s", jawaban);
            }
            if (strcmp(jawaban, "ya") == 0) {
                    del_membersuper(S, nama_mhs, NIM);
                    DeleteFromPOLBANFile(nama_mhs, NIM);
                    printf("Mahasiswa %s dengan NIM telah dihapus dari daftar anggota POLBAN.\n", nama_mhs, NIM);
                    char pesan[100];
                    sprintf(pesan, "%s (%s) telah dikeluarkan dari POLBAN!\n", nama_mhs, NIM);
                    WriteHistory(pesan);
                    system("pause");
                    return;
            } else if (strcmp(jawaban, "tidak") == 0) {

            } 
            

        }

        else {
            printf("Tidak ada mahasiswa tersebut!\n");
            system("pause");
        }
        
    }
}


void CopyList(subset_list* H, subset_list SC)
/*  AUTHOR      : Banteng Harisantoso
    IS          : List UKM telah terbentuk
    FS          : Berhasil menyalin list dari UKM ke variabel sementara (H)
    DESKRIPSI   : Prosedur untuk menyalin isi list UKM ke H
=======================================================================================================================*/
{
    alamatsub bantu;
    bantu = SC.first_sub;

    while(bantu != NULL){
        add_membersub(H, bantu->member_sub, bantu->id_sub, bantu->nama_sub);
        bantu = bantu->next_sub;
    }
}

void EkstrakList(subset_list* H, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF)
/*  AUTHOR      : Banteng Harisantoso
    IS          : List 10 UKM sudah terbentu baik berisi atau kosong
    FS          : Mengirimkan parameter berupa UKM ke modul CopyList
    DESKRIPSI   : Prosedur untuk menampilkan memilih UKM yang akan disalin isinya
                  ke variabel sementara yaitu H
=======================================================================================================================*/
{
    create_sub(H);
    bool valid = false;

    while(!valid){
        int opsi = ListUKM();
        if(opsi==1){
            CopyList(H, DKM);
            valid = true;
        }else if(opsi==2){
            CopyList(H, KEWIRAUSAHAAN);
            valid = true;
        }else if(opsi==3){
            CopyList(H, BADMINTON);
            valid = true;
        }else if(opsi==4){
            CopyList(H, BASKET);
            valid = true;
        }else if(opsi==5){
            CopyList(H, VOLI);
            valid = true;
        }else if(opsi==6){
            CopyList(H, POLBAN_CHESS);
            valid = true;
        }else if(opsi==7){
            CopyList(H, JFP);
            valid = true;
        }else if(opsi==8){
            CopyList(H, ROBOTIK);
            valid = true;
        }else if(opsi==9){
            CopyList(H, FELLAS);
            valid = true;
        }else if(opsi==10){
            CopyList(H, USF);
            valid = true;
        }else if(opsi==99){
            valid = true;
            break;
        }
    }
}

void MenuOperasi(superset_list S, subset_list* H1, subset_list* H2, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF)
/*  AUTHOR      : Banteng Harisantoso
    IS          : List POLBAN dan 10 UKM sudah terbentu baik berisi atau kosong
    FS          : Ditampilkan menu untuk melakukan operasi himpunan pada 10 UKM di POLBAN dan menampilkan hasil operasi
    DESKRIPSI   : Prosedur untuk menampilkan menu operasi himpunan untuk 10 UKM di POLBAN terdapat 4 operasi
                  yakni Irisan, Gabungan, Selisih, dan Komplemen
=======================================================================================================================*/
{
    int opsi = 0;
    bool valid = false;
    
    system("cls");
        printf("=========================================\n");
        printf("|\t[2] Operasi Himpunan\t\t|\n");
        printf("=========================================\n");
        printf("| Saat ini program hanya dapat\t\t|\n| mengkalkulasikan dua himpunan\t\t|\n");
        printf("| \t\t\t\t\t|\n");
        printf("| UKM 1: \t\t\t\t|\n");
        EkstrakList(H1, DKM,  KEWIRAUSAHAAN,  BADMINTON,  BASKET,  VOLI,  POLBAN_CHESS,  JFP,  ROBOTIK,  FELLAS,  USF);
        system("cls");
        printf("=========================================\n");
        printf("|\t[2] Operasi Himpunan\t\t|\n");
        printf("=========================================\n");
        printf("| UKM 2: \t\t\t\t|\n");
        EkstrakList(H2, DKM,  KEWIRAUSAHAAN,  BADMINTON,  BASKET,  VOLI,  POLBAN_CHESS,  JFP,  ROBOTIK,  FELLAS,  USF);
    
    system("cls");
    printf("UKM 1 : %s\n", H1->first_sub->nama_sub);
    printf("UKM 2 : %s\n\n", H2->first_sub->nama_sub);
    printf("Silahkan pilih operasi di bawah:\n");
    printf("1. Irisan\n");
    printf("2. Gabungan\n");
    printf("3. Selisih\n");
    printf("4. Komplemen\n");
    printf("99. Back\n");
    scanf("%d", &opsi);

    while(!valid){
        switch (opsi)
        {
        case 1 :
            irisan(*H1, *H2);
            valid = true; break;
        case 2 :
            gabungan(*H1, *H2);
            valid = true;break;
        case 3 :
            selisih(*H1, *H2);
            valid = true;break;        
        case 4 :
            printf("Komplemen(Super, H1, H2)'contoh: %s dan %s'\n", H1->first_sub->member_sub, H2->first_sub->member_sub);
            valid = true;break;
        case 99 :
            valid = true;break;
        default:
            printf("Masukkan opsi yang valid!");
            system("pause");
            break;
        }
    }
    system("pause");
}

void irisan(subset_list H1, subset_list H2){
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : List subset1 dan subset2 sudah terbentuk, serta memiliki isi anggota-anggota subset1 dan subset2.
    FS          : Menampilkan irisan atau anggota-anggota yang sama pada kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan anggota yang sama dari kedua himpunan yang diinputkan.
                  Jika salah satu atau kedua himpunan kosong, maka akan menampilkan pesan bahwa tidak terdapat irisan karena terdapat himpunan yang kosong.
                  Jika ditemukan anggota yang sama, maka anggota tersebut akan ditampilkan ke layar.
                  Jika tidak ditemukan anggota yang sama, maka akan menampilkan pesan bahwa tidak terdapat anggota yang sama di kedua himpunan.
    =======================================================================================================================*/
    // Kamus Data
    alamatsub P;
    alamatsub Q;
    bool found = false;
    if(IsSubEmpty(H1) || IsSubEmpty(H2)) {
        printf("Tidak terdapat irisan, karena terdapat himpunan UKM yang kosong.\n");
    } else {
        printf("\nIrisan dari %s dan %s adalah:\n", H1.first_sub->nama_sub, H2.first_sub->nama_sub);
        // Traverse subset_list H1
        P = H1.first_sub;
        while ( P != NULL ) {
            // Traverse subset_list H2
            Q = H2.first_sub;
            while (Q != NULL) {
                // Jika ada anggota yang sama di kedua himpunan UKM, maka print anggota tersebut
                if (strcmp(P->member_sub, Q->member_sub) == 0 && strcmp(P->id_sub, Q->id_sub) == 0) {
                    printf("-%s (%s)\n", P->member_sub, P->id_sub);
                    found = true;
                    break;
                }
                Q = Q->next_sub;
            }
            P = P->next_sub;
        }
        // Jika tidak ada irisan, tampilkan pesan.
        if (!found) {
            printf("Tidak terdapat anggota yang sama di kedua UKM.\n");
        }
    }
}

void gabungan(subset_list H1, subset_list H2) {
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : List subset1 dan subset2 sudah terbentuk, serta memiliki isi anggota-anggota subset1 dan subset2.
    FS          : Menampilkan hasil gabungan kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan gabungan dari kedua himpunan yang diinputkan.
                  Jika terdapat anggota yang sama diantara kedua list, maka akan ditampilkan satu kali saja.
                  Hasil gabungan akan ditampung dalam sebuah list baru.
    =======================================================================================================================*/

    // Membuat list baru untuk menampung gabungan dari subset1 dan subset2.
    subset_list HasilGabungan;
    create_sub(&HasilGabungan);

    // Kamus Data
    alamatsub P;

    // Menambahkan semua anggota subset1 ke list HasilGabungan.
    P =  H1.first_sub;
    while (P != NULL) {
        add_membersub(&HasilGabungan, P->member_sub, P->id_sub, "Gabungan");
        P = P->next_sub;
    }

    // Menambahkan semua anggota subset2 ke list HasilGabungan.
    // Jika ada anggota yang sudah terdapat dalam list, tidak akan ditambahkan lagi.
    P = H2.first_sub;
    while (P != NULL) {
        if(!IsExistSub(HasilGabungan, P->member_sub, P->id_sub)) {
            add_membersub(&HasilGabungan, P->member_sub, P->id_sub, "Gabungan");
        }
        P = P->next_sub;
    }

    // Menampilkan semua anggota himpunan gabungan.
    P = HasilGabungan.first_sub;
    printf("\nGabungan dari %s dan %s adalah:\n", H1.first_sub->nama_sub, H2.first_sub->nama_sub);
    while (P != NULL) {
        printf("-%s (%s)\n", P->member_sub, P->id_sub);
        P = P->next_sub;
    }

}

void  selisih(subset_list H1, subset_list H2) {
/*  AUTHOR      : Bob Manuel
    IS          : List subset1 dan subset2 sudah terbentuk, ada kemungkinan jika subset kosong.
    FS          : Menampilkan irisan atau anggota-anggota yang sama pada kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan anggota hasil dari operasi selisih antara 2 subset
                  Jika salah satu atau kedua subset kosong, maka akan menampilkan pesan bahwa tidak terdapat hasil operasi selisih karena terdapat himpunan yang kosong.
    =======================================================================================================================*/
    alamatsub P;
    alamatsub Q;
    int found;
    int ada_selisih = 0;


    printf("\nSelisih anggota %s dan %s adalah:\n", H1.first_sub->nama_sub, H2.first_sub->nama_sub);

    P = H1.first_sub;
    while (P != NULL) {
        found = 0;
        Q = H2.first_sub;
        while (Q != NULL) {
            if (strcmp(P->member_sub,Q->member_sub) == 0) {
                found = 1;
                break;
            }
            Q = Q->next_sub;
        }
        if (!found) {
            printf("-%s (%s)\n", P->member_sub, P->id_sub);
            ada_selisih = 1;
        }
        P = P->next_sub;
    }

    if (!ada_selisih) {
        printf("Tidak terdapat selisih antara %s - %s\n", H1.first_sub->nama_sub, H2.first_sub->nama_sub);
    }

    printf("\nSelisih anggota %s dan %s adalah:\n", H2.first_sub->nama_sub, H1.first_sub->nama_sub);

    Q = H2.first_sub;
    while (Q != NULL) {
        found = 0;
        P = H1.first_sub;
        while (P != NULL) {
            if (strcmp(Q->member_sub, P->member_sub) == 0) {
                found = 1;
                break;
            }
            P = P->next_sub;
        }
        if (!found) {
            printf("-%s (%s)\n", Q->member_sub, Q->id_sub);
            ada_selisih = 1;
        }
        Q = Q->next_sub;
    }

    if (!ada_selisih) {
        printf("Tidak terdapat selisih antara %s - %s\n", H2.first_sub->nama_sub, H1.first_sub->nama_sub);
    }
}


void komplemen(superset_list S, subset_list H1, subset_list H2) {
    int i = 0;
    int y = 0;
    alamatsuper p;
    alamatsub q, r;
    char * complemen[i];

    p = S.first_super;
    while(p != NULL){
        q = H1.first_sub;
        while (q != NULL) {
            r = H2.first_sub;
            if (strcmp(p->member_sp, q->member_sub) == 0 && strcmp(p->id_member, q->id_sub) == 0){
                complemen[i] = p->member_sp;
                i++;
                y = i;
            } else {
                q = q->next_sub;
            }
            q = q->next_sub;
        }
    p = p->next_sp;
    }
    for (int i = 0; i <= y; i++){
        printf("Hasil dari komplemen adalah : \n");
        printf("%s\n", complemen[i]);
    }
}

void search(superset_list S, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF, char nama_mhs[], char NIM[]){
    addnama(nama_mhs);
    addnim(NIM);
    display_search(S, DKM, KEWIRAUSAHAAN, BADMINTON, BASKET, VOLI, POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF, nama_mhs, NIM);
}

void display_search(superset_list S, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF, char nama_mhs[], char NIM[]) {
    alamatsuper P;
    alamatsub Q;
    P = S.first_super;
    bool found = false;

    while (P != NULL) {
    if (strcmp(P->member_sp, nama_mhs) == 0 && strcmp(P->id_member, NIM) == 0) {
        found = true;
        printf("Data Mahasiswa:\n");
        printf("Nama: %s\n", P->member_sp);
        printf("NIM: %s\n", P->id_member);
        printf("UKM yang diikuti:\n");
        if (IsExistSub(DKM, nama_mhs, NIM)) {
            printf("- DKM\n");
        }
        if (IsExistSub(KEWIRAUSAHAAN, nama_mhs, NIM)) {
            printf("- UKM Kewirausahaan\n");
        }
        if (IsExistSub(BADMINTON, nama_mhs, NIM)) {
            printf("- UKM Badminton\n");
        }
        if (IsExistSub(BASKET, nama_mhs, NIM)) {
            printf("- UKM Basket\n");
        }
        if (IsExistSub(VOLI, nama_mhs, NIM)) {
            printf("- UKM Voli\n");
        }
        if (IsExistSub(POLBAN_CHESS, nama_mhs, NIM)) {
            printf("- UKM Polban Chess\n");
        }
        if (IsExistSub(JFP, nama_mhs, NIM)) {
            printf("- UKM JFP\n");
        }
        if (IsExistSub(ROBOTIK, nama_mhs, NIM)) {
            printf("- UKM Robotik\n");
        }
        if (IsExistSub(FELLAS, nama_mhs, NIM)) {
            printf("- UKM Fellas\n");
        }
        if (IsExistSub(USF, nama_mhs, NIM)) {
            printf("- UKM USF\n");
        }
        printf("\n");
        break;
    }
    P = P->next_sp;
    }

    if (!found) {
        printf("Data mahasiswa tidak ditemukan.\n");
    }

    system("pause");

}

void PanduanPenggunaan(){
    FILE *fp = fopen("PANDUAN.txt", "w+");

    if(fp == NULL){
        printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
    }

    fprintf(fp, "%s", "==================== PROGRAM HIMPUNAN ====================\n");
    fprintf(fp, "%s", "Program himpunan memiliki 3 himpunan yaitu, himpunan POLBAN sebagai superset, himpunan UKM-1 sebagai subset-1, dan himpunan UKM-2 sebagai subset-2.\n");
    fprintf(fp, "%s", "Dalam konteks ini, setiap anggota UKM-1 dan UKM-2 juga merupakan anggota dari POLBAN.\n\n");
    fprintf(fp, "%s", "TUJUAN\n");
    fprintf(fp, "%s", "Tujuan dari program himpunan ini adalah untuk memodelkan hubungan antara himpunan dalam konteks keanggotaan organisasi suatu universitas.\n");
    fprintf(fp, "%s", "Dengan menggunakan himpunan sebagai model, dapat dilakukan berbagai operasi dan analisis terhadap anggota organisasi universitas.\n\n");
    fprintf(fp, "%s", "CARA MENGGUNAKAN\n");
    fprintf(fp, "%s", "1. Jalankan program himpunan pada IDE masing-masing.\n");
    fprintf(fp, "%s", "2. Setelah program berhasil dijalankan, maka pengguna akan ditampilkan dengan display menu.\n");
    fprintf(fp, "%s", "3. Dalam display menu, pengguna dapat melakukan beberapa fitur, diantaranya :\n");
    fprintf(fp, "%s", "\t [1] Buat Himpunan\n");
    fprintf(fp, "%s", "\t     Pada menu ini pengguna dapat menambahkan anggota mahasiswa POLBAN sebagai\n\t     superset, dan juga dapat menambahkan anggota pada UKM POLBAN sebagai subset.\n");
    fprintf(fp, "%s", "\t [2] Operasi Himpunan\n");
    fprintf(fp, "%s", "\t     Pada operasi himpunan, pengguna dapat menampilkan operasi himpunan seperti\n\t     irisan, gabungan, selisih, dan komplemen sesuai kebutuhan.\n");
    fprintf(fp, "%s", "\t [3] Edit Daftar Himpunan\n");
    fprintf(fp, "%s", "\t     Pada menu ini, pengguna dapat mengubah atau menghapus anggota superset maupun anggota subset\n");
    fprintf(fp, "%s", "\t [4] Cari Anggota Himpunan\n");
    fprintf(fp, "%s", "\t     Pada menu ini pengguna dapat memasukkan nama dan NIM dari mahasiswa,\n\t     kemudian program akan menampilkan mahasiswa tergabung dalam UKM apa saja.\n");
    fprintf(fp, "%s", "\t [5] Tampilkan Daftar Himpunan\n");
    fprintf(fp, "%s", "\t     Pada operasi himpunan, pengguna dapat memilih untuk melihat anggota himpunan\n\t     secara HISTORY, CURRENT, dan menampilkan GUIDE atau panduan penggunaan aplikasi.\n");

    fclose(fp);

}

void TampilkanPanduan(){
    FILE *fp = fopen("PANDUAN.txt", "r");

    if(fp == NULL){
        printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        return;
    }

    char ch;
    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }

    fclose(fp);
    system("pause");
}

void display_menu() {
        system("cls");
    	printf("=========================================\n");
        printf("|\t   PROGRAM HIMPUNAN\t        |\n");
        printf("=========================================\n");
        printf("| Menu: \t\t\t\t|\n");
        printf("| [1] Pendataan Mahasiswa \t\t|\n");
        printf("| [2] Operasi Himpunan \t\t\t|\n");
        printf("| [3] Edit Daftar Himpunan \t\t|\n");
        printf("| [4] Cari Anggota Himpunan \t\t|\n");
        printf("| [5] Tampilkan Daftar Himpunan \t|\n");
        printf("| [6] Panduan Pengguna \t\t\t|\n");
        printf("| [99] Exit \t\t\t\t|\n");
        printf("=========================================\n");

}

void WritePOLBAN(char nama_mhs[], char NIM[])
/*  AUTHOR      : Banteng Harisantoso
    IS          : nama_mhs dan NIM berisi nilai yang valid
    FS          : Berhasil menuliskan informasi nama dan NIM mahasiswa baru ke file eksternal bernama POLBAN.txt
    DESKRIPSI   : Prosedur untuk menuliskan informasi mahasiswa ke file eksternal bernama POLBAN.txt
                  
=======================================================================================================================*/
{
    FILE *fp = fopen("POLBAN.txt", "a+");

    if(fp == NULL){
        printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
    }

    fprintf(fp, "%s\n", nama_mhs);
    fprintf(fp, "%s\n", NIM);

    fclose(fp);

    printf("Berhasil ditambahkan ke database POLBAN!\n");
}

void WriteUKM(int opsi, char nama_mhs[], char NIM[])
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima opsi UKM, nama, dan NIM mahasiswa
    FS          : Informasi mahasiswa berhasil ditulis di salah satu UKM 
    DESKRIPSI   : Prosedur untuk menuliskan informasi mahasiwa ke file eksternal dengan
                  format nama "NAMA_UKM.txt"
=======================================================================================================================*/
{
    
    if(opsi == 1){
        FILE *fp = fopen("DKM.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database DKM!\n");
    } else if(opsi == 2){
        FILE *fp = fopen("KEWIRAUSAHAAN.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database KEWIRAUSAHAAN!\n");
    } else if(opsi == 3){
        FILE *fp = fopen("BADMINTON.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database BADMINTON!\n");
    } else if(opsi == 4){
        FILE *fp = fopen("BASKET.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database BASKET!\n");
    } else if(opsi == 5){
        FILE *fp = fopen("VOLI.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database VOLI!\n");
    } else if(opsi == 6){
        FILE *fp = fopen("POLBAN_CHESS.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database POLBAN_CHESS!\n");
    } else if(opsi == 7){
        FILE *fp = fopen("JFP.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database JFP!\n");
    } else if(opsi == 8){
        FILE *fp = fopen("ROBOTIK.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database ROBOTIK!\n");
    } else if(opsi == 9){
        FILE *fp = fopen("FELLAS.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database FELLAS!\n");
    } else if(opsi == 10){
        FILE *fp = fopen("USF.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database USF!\n");
    }
     
}

void EkstrakPOLBAN(superset_list* S)
/*  AUTHOR      : Banteng Harisantoso
    IS          : List S sudah terbentuk
    FS          : Berhasil atau gagal menyalin nama-nama mahasiswa beserta nim ke list POLBAN
    DESKRIPSI   : Prosedur untuk menyalin isi file POLBAN.txt ke list S
=======================================================================================================================*/
{
    int i = 0;
    FILE* fp = fopen("POLBAN.txt", "r");

    if(fp == NULL){
        printf("\nDatabase belum dibuat!\n");
    }

    char nama[61];
    char nim[10];
    char buffer[100];

    while(fgets(buffer, sizeof(buffer), fp)){
        //Token agar tidak mengambil new line
        strtok(buffer, "\n");
        strcpy(nama, buffer); 
        fgets(buffer, sizeof(buffer), fp);
        sscanf(buffer, "%9[^\n]", nim);
        
        if(!IsExistSuper(*S, nama, nim)){ 
            add_membersuper(S, nama, nim);
            i++;
        }
    }
    if(i > 0){
        printf("Berhasil mengekstrak database!\n");
    } else{
        printf("Tidak ada data yang dapat diekstrak!\n");
    }
           
    system("pause");

    fclose(fp);
}

void EkstrakUKM(superset_list S, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF)
/*  AUTHOR      : Banteng Harisantoso
    IS          : List S sudah terbentuk
    FS          : Berhasil atau gagal mengirim parameter berupa pilihan UKM ke modul CopyFromFiles
    DESKRIPSI   : Prosedur untuk mengirimkan parameter UKM ke CopyFromFiles
=======================================================================================================================*/
{
    bool valid = false;
    
    while(!valid){
        int opsi = ListUKM();
        if(opsi==1){
            CopyFromFile(S, DKM, "DKM");
            valid = true;
        }else if(opsi==2){
            CopyFromFile(S, KEWIRAUSAHAAN, "KEWIRAUSAHAAN");
            valid = true;
        }else if(opsi==3){
            CopyFromFile(S, BADMINTON, "BADMINTON");
            valid = true;
        }else if(opsi==4){
           
            CopyFromFile(S, BASKET, "BASKET");
            valid = true;
        }else if(opsi==5){
            
            CopyFromFile(S, VOLI, "VOLI");
            valid = true;
        }else if(opsi==6){
           
            CopyFromFile(S, POLBAN_CHESS, "POLBAN_CHESS");
            valid = true;
        }else if(opsi==7){
            
            CopyFromFile(S, JFP, "JFP");
            valid = true;
        }else if(opsi==8){
           
            CopyFromFile(S, ROBOTIK, "ROBOTIK");
            valid = true;
        }else if(opsi==9){
            
            CopyFromFile(S, FELLAS, "FELLAS");
            valid = true;
        }else if(opsi==10){
            
            CopyFromFile(S, USF, "USF");
            valid = true;
        }
    }
}

void CopyFromFile(superset_list S, subset_list* H, char NamaUKM[])
/*  AUTHOR      : Banteng Harisantoso
    IS          : List S dan H sudah terbentuk
    FS          : Berhasil atau gagal menyalin nama-nama mahasiswa beserta nim ke list UKM
    DESKRIPSI   : Prosedur untuk menyalin isi file "NAMA_UKM".txt ke list H
=======================================================================================================================*/
{
    char nama_file[100];
    char nama[61];
    char nim[10];
    char buffer[100];
    alamatsub UKM;
    int i = 0;

    UKM = H->first_sub;

    if(UKM == NULL){
        UKM = (alamatsub) malloc(sizeof(elmtsubset));
        strcpy(UKM->nama_sub, NamaUKM);
    }

    sprintf(nama_file, "%s.txt", UKM->nama_sub);
    FILE* fp = fopen(nama_file, "r");


    if(fp == NULL){
        printf("\nDatabase belum dibuat!\n");
    }


    while(fgets(buffer, sizeof(buffer), fp)){
        //Token agar tidak mengambil new line
        char* token = strtok(buffer, "\n");
        strcpy(nama, buffer);
        fgets(buffer, sizeof(buffer), fp);
        sscanf(buffer, "%9[^\n]", nim);
        
        if(IsExistSuper(S, nama, nim)){
            if(!IsExistSub(*H, nama, nim)){
            add_membersub(H, nama, nim, UKM->nama_sub);
            i++;
            } else {
                printf("Mahasiswa sudah terdaftar!\n");
            }
        }
        else{
            printf("Tidak ada mahasiswa bernama %s!\n", nama);
        }
    }
    if(i > 0){
        printf("Berhasil mengekstrak database!\n");
    } else{
        printf("Tidak ada data yang dapat diekstrak!\n");
    } 
    system("pause");
    fclose(fp); 
}

void DeleteFromPOLBANFile(char nama_mhs[], char NIM[]){
    char buffer[100];
    int line = 1;
    int found = 0;
    
    FILE *fp, *temp;
    fp = fopen("POLBAN.txt", "r");
    if(fp == NULL){
        printf("File tidak dapat dibuka atau ditemukan!\n");
        exit(EXIT_FAILURE);
    }

    temp = fopen("temp.txt", "a+");
    if(temp == NULL){
        printf("File temp.txt tidak dapat dibuka atau ditemukan!\n");
        exit(EXIT_FAILURE);
    }


    while(fgets(buffer, sizeof(buffer), fp)){
        //Mencari nama dan nim
        char *ptr;
        ptr = strstr(buffer, nama_mhs);
        if(ptr != NULL){
            printf("Nama ditemukan!\n");
            fgets(buffer, sizeof(buffer), fp);
            char *ptrnim;
            ptrnim = strstr(buffer, NIM);
            if(ptrnim != NULL){
                printf("NIM sesuai!"); 
                found = 1;
                continue;
            }
        }
        fprintf(temp, "%s", buffer);
        line++;
    }   
    
    fclose(fp);
    fclose(temp);

    if(found == 1){
        remove("POLBAN.txt");
        rename("temp.txt", "POLBAN.txt");
        printf("Mahasiswa bernama %s dengan NIM %s sudah berhasil dihapus dari database.\n", nama_mhs, NIM);
    } else{
        remove("temp.txt");
        printf("Tidak ada mahasiswa bernama %s dengan NIM %s", nama_mhs, NIM); system("pause");
    }
    system("pause");
}

void DeleteFromUKMFile(char nama_mhs[], char NIM[], char UKM[]){
    char nama_file[100];
    char buffer[100];
    int line = 1;
    int found = 0;

    sprintf(nama_file, "%s.txt", UKM);
    FILE *fp, *temp;


    fp = fopen(nama_file, "r");
    if(fp == NULL){
        printf("File tidak dapat dibuka atau ditemukan!\n");
        exit(EXIT_FAILURE);
    }

    temp = fopen("temp.txt", "a+");
    if(temp == NULL){
        printf("File temp.txt tidak dapat dibuka atau ditemukan!\n");
        exit(EXIT_FAILURE);
    }


    while(fgets(buffer, sizeof(buffer), fp)){
        //Mencari nama dan nim
        char *ptr;
        ptr = strstr(buffer, nama_mhs);
        if(ptr != NULL){
            printf("Nama ditemukan!\n");
            fgets(buffer, sizeof(buffer), fp);
            char *ptrnim;
            ptrnim = strstr(buffer, NIM);
            if(ptrnim != NULL){
                printf("NIM sesuai!"); 
                found = 1;
                continue;
            }
        }
        fprintf(temp, "%s", buffer);
        line++;
    }   
    
    fclose(fp);
    fclose(temp);

    if(found == 1){
        remove(nama_file);
        rename("temp.txt", nama_file);
        printf("Mahasiswa bernama %s dengan NIM %s sudah berhasil dihapus dari database.\n", nama_mhs, NIM);
    } else{
        remove("temp.txt");
        printf("Tidak ada mahasiswa bernama %s dengan NIM %s", nama_mhs, NIM); system("pause");
    }
    system("pause");
}

void WriteHistory(char kalimat[]){
    FILE *fp = fopen("HISTORI.txt", "a+");

    if(fp == NULL){
        printf("File tidak bisa dibuka atau tidak ditemukan!\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s\n\n", kalimat);
    fclose(fp);
}

void DisplayHistory(){
    FILE *fp = fopen("HISTORI.txt", "r+");
    if(fp == NULL){
        printf("File tidak ada atau tidak dapat dibuka!\n");
        exit(EXIT_FAILURE);
    }

    char buffer[500];
    int count = 0;
    long int file_size;
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    for(long int i = file_size - 1; i >= 0; i--){
        fseek(fp, i, SEEK_SET);
        if(fgetc(fp) == '\n' ){
            count++;
        } if (count == 25){
            break;
        }
    }

    while(fgets(buffer, sizeof(buffer), fp)){
        printf("%s", buffer);
    }
    fclose(fp);
    system("pause");
}

void MenuEditMahasiswa(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF){
    char nama_mhs[61], nama_baru[61];
    char NIM[10], NIM_baru[10];
    bool valid = false;


    while(!valid){
    addnama(nama_mhs);
    addnim(NIM);

    if(IsExistSuper(*POLBAN, nama_mhs, NIM)){
        int opsi = 0;
        printf("\nSilahkan edit Nama dan NIM Mahasiswa\n");
            addnama(nama_baru);
            addnim(NIM_baru);
            printf("\nKonfirmasi Perubahan Informasi:\n");
            printf("Nama Asal\t:"); printf("%s\n", nama_mhs);
            printf("NIM Asal\t:"); printf("%s\n", NIM);
            printf("\n");
            printf("Nama Baru\t: "); printf("%s\n", nama_baru);
            printf("NIM Baru\t: "); printf("%s\n", NIM_baru);
            printf("\nLanjutkan perubahan?\n1. Ya\n2. Tidak\n99. Back\n");
            scanf("%d", &opsi);
            if(opsi == 1){
                EditMahasiswaPOLBAN(nama_mhs, NIM, nama_baru, NIM_baru, POLBAN);
                 system("pause");
                valid = true;
            } else if(opsi == 2){
                MenuEditHimpunan(POLBAN, DKM, KEWIRAUSAHAAN, BADMINTON,  BASKET, VOLI, POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF);
                valid = true;
            } else if(opsi == 99){
                valid = true;
            } else{
                printf("\nOpsi tidak valid!\n"); system("pause");
                system("cls");
                printf("=========================================\n");
                printf("|\t[1] Edit Himpunan\t\t|\n");
                printf("=========================================\n");
                printf("| Menu: \t\t\t\t|\n");
                printf("| [1] Hapus Mahasiswa POLBAN \t\t|\n");
                printf("| [2] Hapus Anggota UKM POLBAN \t\t|\n");
                printf("| [3] Edit Mahasiswa POLBAN \t\t|\n");
                printf("| [4] Edit Anggota UKM POLBAN \t\t|\n");
                printf("| [99] Back \t\t\t\t|\n");
                printf("=========================================\n");
            }
    } else{
        printf("Tidak ada mahasiswa tersebut!\n"); system("pause");
        MenuEditHimpunan(POLBAN, DKM, KEWIRAUSAHAAN, BADMINTON,  BASKET, VOLI, POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF);
        valid = true;
    }
    } 
}  
void EditMahasiswaPOLBAN(char nama_mhs[], char NIM[], char nama_baru[], char NIM_baru[], superset_list* S){
    alamatsuper P;
	P = S->first_super;
    while (P != NULL) {
        if (strcmp(P->member_sp, nama_mhs) == 0 && strcmp(P->id_member, NIM) == 0) {
            strcpy(P->member_sp, nama_baru);
            strcpy(P->id_member, NIM_baru);
            //EditAnggotaUKM();
        }
        P = P->next_sp;
    }
    printf("Berhasil mengedit informasi mahasiswa\n");
}


