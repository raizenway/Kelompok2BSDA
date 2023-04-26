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
void add_membersub(subset_list *H1, char nama_mhs[], char NIM[], char UKM[]){
    
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

void display_cur(subset_list H){
    alamatsub P;
    P = H.first_sub;
    while(P != NULL){
        printf("%s ", P->member_sub);
        P = P->next_sub;
    }
    system("pause");
}

int ListUKM(){

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

void MenuBuatHimpunan(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF){
    int opsi;
    system("cls");
        printf("=========================================\n");
        printf("|\t[1] Buat Himpunan\t\t|\n");
        printf("=========================================\n");
        printf("| Menu: \t\t\t\t|\n");
        printf("| [1] Tambah Mahasiswa POLBAN \t\t|\n");
        printf("| [2] Tambah Anggota UKM POLBAN \t|\n");
        printf("| [99] Back \t\t\t\t|\n");
        printf("=========================================\n");
    scanf("%d", &opsi);
    switch (opsi){
        case 1:
            Seleksi_MemberSuper(POLBAN);
            break;
        case 2: MenuAddSub(*POLBAN, DKM, KEWIRAUSAHAAN, BADMINTON, BASKET, VOLI, POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF);
            break;
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

void addnama(char* nama_mhs){
    bool valid = false;
    while(!valid){
        
        printf("Masukkan nama mahasiswa\t: ");
        //fgets(nama_mhs, 61, stdin);
        scanf(" %[^\n]", nama_mhs);
        //scanf("%s ", nama_mhs);
        getchar();
        if(strlen(nama_mhs) > 60){
            printf("Nama mahasiswa terlalu panjang!\n");
        }
        else{
            valid = true;
        }
    }

}



void addnim(char* NIM){
    bool valid = false;

    while(!valid){
        printf("Masukkan NIM\t\t: ");
        //fgets(NIM, 9, stdin);
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

void del_membersuper(superset_list *S, char nama_mhs[], char NIM[]){
    /*  AUTHOR  : Bob Manuel
    IS          : List superset sudah terbentuk dan memiliki isi sebagai anggota superset
    FS          : List yang berisi nama dan NIM yang ingin dihapus berhasil dihapus
    DESKRIPSI   : Prosedur untuk mencari mahasiswa pada superset maupun subset.
                  Pengguna akan diarahkan untuk menginput nama dan NIM dari mahasiswa yang ingin dicari.
                  Jika nama dan NIM ditemukan maka modul akan mengembalikan nilai true, 
                  sebaliknya jika nama dan NIM tidak ditemukan maka akan mengembalikan nilai false
    =======================================================================================================================*/
    //Kamus Lokal
    alamatsuper bantu, hapus, next;
    bantu = S->first_super;

    if(IsExistSuper(*S, nama_mhs, NIM)){
        while((bantu->next_sp->member_sp != nama_mhs) || (bantu != NULL)){
            bantu= bantu->next_sp; 
            if(bantu->next_sp->member_sp == nama_mhs){
                hapus = bantu->next_sp;
                next = hapus->next_sp;
                bantu->next_sp = next;
                printf("Mahasiswa bernama %s sudah berhasil dihapus", &hapus->member_sp);
                free(hapus);
            } 
        }
    } else {
        printf("Mahasiswa tidak ditemukan");
    }
    
}

void del_membersub(subset_list *H1, char nama_mhs[], char NIM[]) {
    alamatsub bantu, hapus, next;
    bantu = H1->first_sub;

    if(IsExistSub(*H1, nama_mhs, NIM)){
        while((bantu->next_sub->member_sub != nama_mhs) || (bantu != NULL)){
           bantu = bantu->next_sub;
           if(bantu->next_sub->member_sub == nama_mhs){
            
           }
        }
    }
}

void Penghentian_Studi(superset_list *S, char nama_mhs[], char NIM[]){
    int jumlah;
    char jawaban[5]; // variabel untuk menyimpan jawaban

    printf("Berapa banyak mahasiswa yang ingin dihapus?\n");
    scanf("%d", &jumlah);
    while((jumlah == 0)||(jumlah<0)){
        printf("Jumlah tidak valid! Silahkan masukkan jumlah yang valid.\n");
        scanf("%d", &jumlah);
    }

    for(int i=0;i<jumlah;i++){
        system("cls");
        printf("Silahkan masukkan nama mahasiswa yang ingin dihapus.\n");
        scanf("%s", &nama_mhs);

        printf("Silahkan masukkan NIM mahasiswa tersebut!\n");
        printf("NIM\t:");
        scanf("%s", &NIM);
        if(IsExistSuper(*S, nama_mhs, NIM)){
            printf("JSilakan jawab dengan ya atau tidak.\n");
            // pertanyaan 1
            printf("Apakah mahasiswa dua semester berturut-turut lulus percobaan sampai dengan semester IV untuk mahasiswa Program Diploma III dan semester VI untuk mahasiswa Program Diploma IV?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 2
            printf("Apakah Indeks Prestasi (IP) mahasiswa berada di antara 1,70 dan 2,00 dan jumlah SKS nilai D lebih dari 7 SKS?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 3
            printf("Apakah nilai IP mahasiswa di bawah 1,70?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 4
            printf("Apakah mahasiswa tidak memenuhi syarat kelulusan pada semester VI untuk mahasiswa Program Diploma III dan pada semester VIII untuk mahasiswa Program Diploma IV, setelah diberi kesempatan mengulang satu kali?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 5
            printf("Apakah mahasiswa mempunyai nilai E pada semester I sampai dengan IV untuk mahasiswa Program Diploma III dan semester I sampai IV?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 6
            printf("Apakah mahasiswa melewati batas studi yang telah ditetapkan dalam Pasal 18 Ayat 1 dan 2?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 7
            printf("Apakah mahasiswa memiliki status ketidakhadiran yang tidak diperbolehkan, sebagaimana diatur dalam Pasal 22?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            } 

            // pertanyaan 8
            printf("Apakah mahasiswa terlibat dalam perbuatan kriminal yang dinyatakan oleh pihak berwajib?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }
            
            else if (strcmp(jawaban, "tidak") == 0) {
                // jawaban tidak, lanjut ke pertanyaan berikutnya
            } else {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                return;
            }


        }

    }
}

void CopyList(subset_list* H, subset_list SC){
    alamatsub bantu;
    bantu = SC.first_sub;

    while(bantu != NULL){
        add_membersub(H, bantu->member_sub, bantu->id_sub, bantu->nama_sub);
        bantu = bantu->next_sub;
    }
}

void EkstrakList(subset_list* H, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF)
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
        }
    }
}

void MenuOperasi(subset_list* H1, subset_list* H2, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF){
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
    scanf("%d", &opsi);

    while(!valid){
        switch (opsi)
        {
        case 1 :
            printf("Irisan(Super, H1, H2) 'contoh: %s dan %s'\n", H1->first_sub->member_sub, H2->first_sub->member_sub);
            valid = true; break;
        case 2 :
            printf("Gabungan(Super, H1, H2)'contoh: %s dan %s'\n", H1->first_sub->member_sub, H2->first_sub->member_sub);
            valid = true;break;
        case 3 :
            printf("Selisih(Super, H1, H2)'contoh: %s dan %s'\n", H1->first_sub->member_sub, H2->first_sub->member_sub);
            valid = true;break;        
        case 4 :
            printf("Komplemen(Super, H1, H2)'contoh: %s dan %s'\n", H1->first_sub->member_sub, H2->first_sub->member_sub);
            valid = true;break;
        default:
            printf("Masukkan opsi yang valid!");
            system("pause");
            break;
        }
    }
    system("pause");
}

void irisan(superset_list S, subset_list H1 ){
    alamatsuper P;
    alamatsub Q;
    if(IsSuperEmpty(S) || IsSubEmpty(H1)) {
        printf("Tidak terdapat irisan, karena terdapat himpunan yang kosong.\n");
    } else {
        printf("Irisan dari kedua himpunan adalah:\n");
        // Traverse superset_list
        P = S.first_super;
        while ( P!=NULL ) {
            // Traverse subset_list
            Q = H1.first_sub;
            while (Q != NULL) {
                // Jika ada anggota yang sama di kedua himpunan, maka print anggota tersebut
                if (strcmp(P->member_sp, Q->member_sub) == 0 && strcmp(P->id_member, Q->id_sub) == 0) {
                    printf("%s - %s\n", P->member_sp, P->id_member);
                    break;
                }
                Q = Q->next_sub;
            }
            P = P->next_sp;
        }
    }
}

void selisih(superset_list S, subset_list H1 ) {

}

void gabungan(superset_list S, subset_list H1 ) {
    
}

void display_menu() {
        system("cls");
    	printf("=========================================\n");
        printf("|    Kalkulator Himpunan UKM POLBAN     |\n");
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

