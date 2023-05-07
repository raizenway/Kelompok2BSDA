/*  AUTHOR      : Kelompok 2
    NAMA        : SpHimpunan.h
    DESKRIPSI   : Header untuk struktur data himpunan
    TANGGAL     : 16 APRIL 2023
=======================================================================================================================*/
#ifndef SPHIMPUNAN_H
#define SPHIMPUNAN_H
#include <stdio.h>
#include <stdbool.h>
/*============================ STRUKTUR DATA ============================*/
typedef struct subset *alamatsub;
typedef struct subset{
    char nama_sub[20];
    char member_sub[61];
    char id_sub[10];
    alamatsub next_sub;
}elmtsubset;

typedef struct superset* alamatsuper;
typedef struct superset{
    char nama_super[10];
    char member_sp[61];
    char id_member[10];
    alamatsuper next_sp;
}elmtsuper;

typedef struct{
    alamatsuper first_super;
}superset_list;

typedef struct {
    alamatsub first_sub;
}subset_list;

/*============================ METHOD ============================*/
void create_super (superset_list *S);
void create_sub (subset_list *H1);
bool IsSuperEmpty (superset_list S);
bool IsSubEmpty (subset_list H1);
bool IsExistSuper(superset_list S, char nama_mhs[], char NIM[]);
bool IsExistSub(subset_list H1, char nama_mhs[], char NIM[]);
bool IsSuperEmpty(superset_list S);
bool IsSubEmpty(subset_list H1);
bool IsFull();
void add_membersuper(superset_list *S, char nama_mhs[], char NIM[]);
void add_membersub(subset_list *H1, char nama_mhs[], char NIM[], char UKM[]);
void Seleksi_MemberSuper(superset_list *S);
void del_membersuper(superset_list *S, char nama_mhs[], char NIM[]);
void del_membersub(subset_list *H1, char nama_mhs[], char NIM[]);
void Penghentian_Studi(superset_list *S, char nama_mhs[], char NIM[]);
void irisan(subset_list H1, subset_list H2);
void gabungan(subset_list H1, subset_list H2); 
void komplemen(superset_list S, subset_list H1 );
void selisih(subset_list H1, subset_list H2);
void append_history(superset_list S, subset_list H1 );
void write_cur(superset_list S, subset_list H1);
void write_guide();
void display_cur(subset_list H);
void display_menu();
void display_membersuper(superset_list S); 
void display_membersubset(subset_list H);
void display_search(superset_list S, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF, char nama_mhs[], char NIM[]);
void display_guide();
void MenuAddSub(superset_list POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
void MenuEditSub(superset_list POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
int  ListUKM(); 
void addnama(char* nama_mhs); 
void addnim(char* NIM); 
void MenuBuatHimpunan(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
void MenuEditHimpunan(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF, char nama_mhs[], char NIM[]);
void MenuDisplayHimpunan(superset_list POLBAN, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF, char nama_mhs[], char NIM[]);
void MenuOperasi(superset_list S, subset_list* H1, subset_list* H2, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF);
void EkstrakList(subset_list* H, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF);
void CopyList(subset_list* H, subset_list SC); 
void WritePOLBAN(char nama_mhs[], char NIM[]);  
void WriteUKM(int opsi, char nama_mhs[], char NIM[]);  
void EkstrakPOLBAN(superset_list* POLBAN);  
void EkstrakUKM(superset_list S, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
void CopyFromFile(superset_list S, subset_list* H, char NamaUKM[]);
void DeleteFromPOLBANFile(char nama_mhs[], char NIM[]); 
void DeleteFromUKMFile(char nama_mhs[], char NIM[], char UKM[]);
void WriteHistory(char kalimat[]);
void DisplayHistory();
void MenuEditMahasiswa(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
void EditMahasiswaPOLBAN(char nama_mhs[], char NIM[], superset_list* POLBAN);
void EditAnggotaUKM(char nama_mhs[], char NIM[], subset_list H);
void EditFilePOLBAN(char nama_mhs[], char NIM[], superset_list S);
void EditFileUKM(char nama_mhs[], char NIM[], char UKM[]);
void PanduanPenggunaan();
void TampilkanPanduan();
#endif /* SPHIMPUNAN_H */