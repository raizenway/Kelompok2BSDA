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
void add_membersub(subset_list *H1, char nama_mhs[], char NIM[]){
    
    alamatsub P;
    P = (alamatsub) malloc(sizeof(elmtsubset));
    strcpy(P->member_sub, nama_mhs);
    strcpy(P->id_sub, NIM); 
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

//void ListUKM(){
//        printf("Pilih salah satu UKM di bawah!\n"
//               "1. DKM\n"
//               "2. MUSKING\n"
//               "3. BADMINTON\n"
//               "4. BASKET\n"
//               "5. VOLI\n"
//               "6. POLBAN CHESS\n"
//               "7. JFP\n"
//               "8. ROBOTIK\n"
//               "9. FELLAS\n"
//               "10. FUTSAL\n");
//}   

int ListUKM(){
        printf("Pilih salah satu UKM di bawah!\n"
               "1. DKM\n"
               "2. MUSKING\n"
               "3. BADMINTON\n"
               "4. BASKET\n"
               "5. VOLI\n"
               "6. POLBAN CHESS\n"
               "7. JFP\n"
               "8. ROBOTIK\n"
               "9. FELLAS\n"
               "10. FUTSAL\n");
        int opsi = 0;
        do
        {   
            printf("Opsi: ");
            scanf("%d", &opsi);
            if((opsi < 1)||(opsi > 10)){
                printf("\nOpsi tidak valid\n");
            }
        } while ((opsi < 1)||(opsi > 10));

        return opsi;
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
    int opsi;
    bool syarat = true;
    
    printf("Berapa banyak calon mahasiswa yang ingin didata?\n");
    scanf("%d", &jumlah);
    while((jumlah == 0)||(jumlah<0)){
        printf("Jumlah tidak valid! Silahkan masukkan jumlah yang valid.\n");
        scanf("%d", &jumlah);
    }

    for(int i=0;i<jumlah;i++){
    system("cls");
    printf("Silahkan masukkan nama calon mahasiswa.\n");
    scanf("%s", &nama_mhs);
    while(syarat){
            system("cls");
            printf("Apakah calon mahasiswa tersebut lolos seleksi SNMPTN/SBMPTN atau SNMPN/SBMPN atau Ujian Mandiri?\n");
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
                                system("cls");
                                printf("Mahasiswa lolos persyaratan POLBAN!\n");
                                printf("Silahkan masukkan NIM mahasiswa tersebut!\n");
                                printf("NIM\t:");
                                scanf("%s", &NIM);
                                if(IsExistSuper(*S, nama_mhs, NIM)){
                                   system("cls"); 
                                   printf("\n\nMahasiswa tersebut sudah terdaftar di POLBAN!");
                                   system("pause");
                                }
                                else{
                                    add_membersuper(S, nama_mhs, NIM);
                                    system("cls");
                                    printf("Calon mahasiswa telah resmi menjadi mahasiswa POLBAN!");
                                    printf("\nInformasi Mahasiswa:");
                                    printf("\nNama Mahasiswa\t: %s", nama_mhs);
                                    printf("\nNIM\t\t: %s\n", NIM);
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
               printf("\nMahasiswa belum memenuhi persyaratan!");
               system("pause");
               syarat = false;
               break;
            default:
                printf("\nMasukkan opsi yang valid!");
                system("pause");
            }

    }
    syarat = true;
    }
    
}

void menu_addsub(subset_list* DKM, subset_list* MUSKING, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* FUTSAL)
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
int opsi = 0;

while(!valid){
    printf("============================ Menu Pendataan UKM Mahasiswa ===================================\n");
    if(ListUKM()==1){
        printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            add_membersub(DKM, nama_mhs, NIM);
            printf("\n%s ", nama_mhs);
            printf("berhasil bergabung di DKM!\n\n");
        }
        valid = true;        
        break;
    }else if(ListUKM()==2){
        printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            printf("\n%s ", nama_mhs);
            printf("berhasil bergabung di MUSKING!\n\n");
        }
        valid = true;
        break;
    }else if(ListUKM()==3){
        printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            add_membersub(BADMINTON, nama_mhs, NIM);
            printf("\n%s ", nama_mhs);
            printf("berhasil bergabung di BADMINTON!\n\n");
        }
        valid = true;
        break;
    }else if(ListUKM()==4){
        printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            add_membersub(BASKET, nama_mhs, NIM);
            printf("\n%s ", nama_mhs);
            printf("berhasil bergabung di BASKET!\n\n");
        }
        valid = true;
        break; 
    }else if(ListUKM()==5){
       printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            add_membersub(VOLI, nama_mhs, NIM);
            printf("\n%s ", nama_mhs);
            printf("berhasil bergabung di VOLI!\n\n");
        }
        valid = true;
        break; 
    }else if(ListUKM()==6){
        printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            add_membersub(POLBAN_CHESS, nama_mhs, NIM);
            printf("\n%s ", nama_mhs);
            printf("berhasil bergabung di ROBOTIK!\n\n");
        }
        valid = true;
        break;
    }else if(ListUKM()==7){
        printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            add_membersub(JFP, nama_mhs, NIM);
            printf("\n%s ", nama_mhs);
            printf("berhasil bergabung di JFP!\n\n");
        }
        valid = true;
        break;
    }else if(ListUKM()==8){
        printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            add_membersub(ROBOTIK, nama_mhs, NIM);
            printf("\n%s ", nama_mhs);
            printf("berhasil bergabung di POLBAN CHESS!\n\n");
        }
        valid = true;
        break;
    }else if(ListUKM()==9){
       printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            add_membersub(FELLAS, nama_mhs, NIM);
            printf("\n%s ", nama_mhs);
            printf("berhasil bergabung di FELLAS!\n\n");
        }
        valid = true;
        break; 
    }else if(ListUKM()==10){
        printf("Masukkan jumlah mahasiswa yang akan bergabung\t: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            add_membersub(FUTSAL, nama_mhs, NIM);
            printf("\n %s ", nama_mhs);
            printf("berhasil bergabung di FUTSAL!\n\n");
            system("pause");
        }
        valid = true;
        break; 
    }
    }
    
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

void Penghentian_Studi(superset_list *S, char nama_mhs[], char NIM[]){
    char nama_mhs[20];
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

