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
/*  AUTHOR      : Bob Manuel
    IS          : Struktur data Superset telah dibentuk, variabel S sudah di deklarasikan
    FS          : Subvariabel first_super berhasil atau gagal menunjuk ke NULL
    DESKRIPSI   : Prosedur untuk membuat list S
=======================================================================================================================*/
void create_sub (subset_list *H1);
/*  AUTHOR      : Bob Manuel
    IS          : Struktur data Subset telah dibentuk, variabel H1 sudah di deklarasikan
    FS          : Subvariabel first_sub berhasil atau gagal menunjuk ke NULL
    DESKRIPSI   : Prosedur untuk membuat list H1
=======================================================================================================================*/
bool IsSuperEmpty (superset_list S);
/*  AUTHOR      : Bob Manuel
    IS          : Menerima list S
    FS          : Diketahui jika list S kosong atau tidak (True berarti kosong, False berarti terisi)
    DESKRIPSI   : Fungsi untuk mengetahui jika satu list super kosong atau terisi
=======================================================================================================================*/
bool IsSubEmpty (subset_list H1);
/*  AUTHOR      : Bob Manuel
    IS          : Menerima list H1
    FS          : Diketahui jika list H1 kosong atau tidak (True berarti kosong, False berarti terisi)
    DESKRIPSI   : Fungsi untuk mengetahui jika satu list sub kosong atau terisi
=======================================================================================================================*/
bool IsExistSuper(superset_list S, char nama_mhs[], char NIM[]);
/*  AUTHOR      : Bob Manuel
    IS          : Menerima list S, nama dan NIM
    FS          : Diketahui jika satu mahasiswa sudah ada dalam list atau belum (True berarti ada, False berarti tidak ada)
    DESKRIPSI   : Fungsi untuk mengetahui jika terdapat mahasiswa di list S
=======================================================================================================================*/
bool IsExistSub(subset_list H1, char nama_mhs[], char NIM[]);
/*  AUTHOR      : Bob Manuel
    IS          : Menerima list H1, nama dan NIM
    FS          : Diketahui jika satu mahasiswa sudah ada dalam list atau belum (True berarti ada, False berarti tidak ada)
    DESKRIPSI   : Fungsi untuk mengetahui jika terdapat mahasiswa di list H1
=======================================================================================================================*/
bool IsSuperEmpty(superset_list S);
/*  AUTHOR      : Bob Manuel
    IS          : Menerima list S
    FS          : Diketahui jika list S kosong atau tidak (True berarti kosong, False berarti terisi)
    DESKRIPSI   : Fungsi untuk mengetahui jika satu list super kosong atau terisi
=======================================================================================================================*/
bool IsSubEmpty(subset_list H1);
/*  AUTHOR      : Bob Manuel
    IS          : Menerima list H1
    FS          : Diketahui jika list H1 kosong atau tidak (True berarti kosong, False berarti terisi)
    DESKRIPSI   : Fungsi untuk mengetahui jika satu list sub kosong atau terisi
=======================================================================================================================*/
bool IsFull();
/*  AUTHOR      : Bob Manuel
    IS          : Tidak diketahui penuh kosongnya memori
    FS          : Diketahui jika memori penuh atau kosong (True berarti penuh, False berarti kosong)
    DESKRIPSI   : Fungsi untuk mengetahui jika terdapat mahasiswa di list S
=======================================================================================================================*/
void add_membersuper(superset_list *S, char nama_mhs[], char NIM[]);
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : List POLBAN mungkin kosong
    FS          : Melakukan alokasi dan menambahkan node baru di salah satu list superset.
    DESKRIPSI   : Prosedur untuk mengalokasikan dan menambahkan Mahasiswa baru ke Polban.
                  Informasi yang ada adalah Nama, NIM.
=======================================================================================================================*/
void add_membersub(subset_list *H1, char nama_mhs[], char NIM[], char UKM[]);
/*  AUTHOR      : Banteng Harisantoso
    IS          : H1 mungkin kosong
    FS          : Melakukan alokasi dan menambahkan node baru di salah satu list subset
    DESKRIPSI   : Prosedur untuk mengalokasikan dan menambahkan Mahasiswa baru ke salah satu UKM.
                  Informasi yang ada adalah Nama, NIM, dan Nama UKM 
=======================================================================================================================*/
void Seleksi_MemberSuper(superset_list *S);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Sudah terbentuk list superset
    FS          : Menampilkan pesan berhasil atau gagal menambahkan mahasiswa ke dalam list POLBAN
    DESKRIPSI   : Prosedur untuk masuk ke menu penambahan mahasiswa dengan syarat-syarat POLBAN,
                  pengguna akan diarahkan ke switch, jika memilih 1 berturut-turut maka calon mahasiswa dapat menjadi mahasiswa
                  POLBAN. Namun, jika mahasiswa tidak lolos salah satu persyaratan maka calon mahasiswa belum bisa menjadi
                  mahasiswa POLBAN
=======================================================================================================================*/
void del_membersuper(superset_list *S, char nama_mhs[], char NIM[]);
/*  AUTHOR      : Bob Manuel
    IS          : List superset sudah terbentuk dan memiliki isi sebagai anggota superset atau masih kosong
    FS          : List yang berisi nama dan NIM yang ingin dihapus berhasil dihapus
    DESKRIPSI   : Prosedur untuk menghapus suatu node berdasarkan nama mahasiswa dan nim.
                  Node sebelumnya akan terhubung dengan node setelah node yang dihapus.
========================================================================================================================*/
void del_membersub(subset_list *H1, char nama_mhs[], char NIM[]);
/*  AUTHOR      : Bob Manuel
    IS          : List subset sudah terbentuk dan memiliki isi sebagai anggota subset atau masih kosong 
    FS          : List yang berisi nama dan NIM yang ingin dihapus berhasil dihapus
    DESKRIPSI   : Prosedur untuk menghapus suatu node berdasarkan nama mahasiswa dan nim.
                  Node sebelumnya akan terhubung dengan node setelah node yang dihapus.
========================================================================================================================*/
void Penghentian_Studi(superset_list *S, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : Sudah terbentuk list superset
    FS          : Menampilkan pesan berhasil atau gagal menghapus mahasiswa ke dalam list POLBAN
    DESKRIPSI   : Prosedur untuk masuk ke menu penghapusan mahasiswa dengan syarat-syarat POLBAN,
                  pengguna akan diarahkan ke kondisi if else, jika salah satu kondisi memenuhi,
                  maka akan memanggil modul untuk menghapus anggota dari List POLBAN.
=======================================================================================================================*/
void irisan(subset_list H1, subset_list H2);
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : List subset1 dan subset2 sudah terbentuk, serta memiliki isi anggota-anggota subset1 dan subset2.
    FS          : Menampilkan irisan atau anggota-anggota yang sama pada kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan anggota yang sama dari kedua himpunan yang diinputkan.
                  Jika salah satu atau kedua himpunan kosong, maka akan menampilkan pesan bahwa tidak terdapat irisan karena terdapat himpunan yang kosong.
                  Jika ditemukan anggota yang sama, maka anggota tersebut akan ditampilkan ke layar.
                  Jika tidak ditemukan anggota yang sama, maka akan menampilkan pesan bahwa tidak terdapat anggota yang sama di kedua himpunan.
========================================================================================================================*/
void gabungan(subset_list H1, subset_list H2); 
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : List subset1 dan subset2 sudah terbentuk, serta memiliki isi anggota-anggota subset1 dan subset2.
    FS          : Menampilkan hasil gabungan kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan gabungan dari kedua himpunan yang diinputkan.
                  Jika terdapat anggota yang sama diantara kedua list, maka akan ditampilkan satu kali saja.
                  Hasil gabungan akan ditampung dalam sebuah list baru.
========================================================================================================================*/
void komplemen(superset_list S, subset_list H1 );
/*  AUTHOR      : Bob Manuel
    IS          : List super dan subset sudah terbentuk, ada kemungkinan jika subset kosong.
    FS          : Menampilkan komplemen atau anggota-anggota yang sama pada kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan anggota hasil dari operasi komplemen
                  Jika salah satu atau kedua set kosong, maka akan menampilkan pesan bahwa tidak terdapat
                  hasil operasi komplemen karena terdapat himpunan yang kosong.
========================================================================================================================*/
void selisih(subset_list H1, subset_list H2);
/*  AUTHOR      : Bob Manuel
    IS          : List subset1 dan subset2 sudah terbentuk, ada kemungkinan jika subset kosong.
    FS          : Menampilkan selisih atau anggota-anggota yang sama pada kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan anggota hasil dari operasi selisih antara 2 subset
                  Jika salah satu atau kedua subset kosong, maka akan menampilkan pesan bahwa tidak terdapat hasil operasi selisih karena terdapat himpunan yang kosong.
========================================================================================================================*/
void display_menu();
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : Belum atau mungkin sudah menampilkan display_menu()
    FS          : Menampilkan menu dari opsi-opsi fitur yang ada
    DESKRIPSI   : Prosedur untuk menampilkan menu dari fitur yang tersedia
========================================================================================================================*/
void display_membersuper(superset_list S);
/*  AUTHOR      : Bob Manuel
    IS          : List S sudah terbentuk
    FS          : Menampilkan mahasiswa yang ada di list S (POLBAN)
    DESKRIPSI   : Prosedur untuk menampilkan mahasiswa di POLBAN
========================================================================================================================*/
void display_membersubset(subset_list H);
/*  AUTHOR      : Bob Manuel
    IS          : List H sudah terbentuk
    FS          : Menampilkan mahasiswa yang ada di list H (UKM)
    DESKRIPSI   : Prosedur untuk menampilkan mahasiswa di salah satu UKM
========================================================================================================================*/
void display_search(superset_list S, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF, char nama_mhs[], char NIM[]);
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : List POLBAN dan UKM sudah terbentuk, menerima nama mahasiswa beserta NIMnya
    FS          : Berhasil atau gagal menampilkan mahasiswa yang dicari serta UKM yang diikutinya
    DESKRIPSI   : Prosedur untuk menampilkan mahasiswa yang dicari beserta dengan UKM yang diikuti
========================================================================================================================*/
void MenuAddSub(superset_list POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Sudah terbentuk list subset
    FS          : Menampilkan pesan berhasil atau gagal menambahkan mahasiswa ke dalam himp
    DESKRIPSI   : Prosedur untuk masuk ke menu penambahan mahasiswa ke pilihan UKM
=======================================================================================================================*/
void MenuEditSub(subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : Sudah terbentuk list subset
    FS          : Menampilkan pesan berhasil atau gagal menghapus atau mengubah data mahasiswa ke dalam himpunan.
    DESKRIPSI   : Prosedur untuk masuk ke menu penghapusan atau pengubahan mahasiswa dari list UKM maupun list POLBAN.
=======================================================================================================================*/
int  ListUKM();
/*  AUTHOR      : Banteng Harisantoso
    IS          : ListUKM bernilai tidak tentu
    FS          : ListUKM bernilai antara 1-10
    DESKRIPSI   : Fungsi untuk memilih opsi ukm dan mengembalikan nilai integer
                  dari 1-10
=======================================================================================================================*/
void addnama(char* nama_mhs); 
/*  AUTHOR      : Banteng Harisantoso
    IS          : nama_mhs sudah di deklarasikan
    FS          : nama_mhs sudah diberi nilai sesuai dengan inputan dari pengguna
    DESKRIPSI   : Prosedur untuk menginput nama_mhs dari pengguna, nama mahasiswa
                  maksimal terdiri dari 61 karakter (termasuk spasi)
=======================================================================================================================*/
void addnim(char* NIM); 
/*  AUTHOR      : Banteng Harisantoso
    IS          : NIM sudah di deklarasikan
    FS          : NIM sudah diberi nilai sesuai dengan inputan dari pengguna
    DESKRIPSI   : Prosedur untuk menginput NIM dari pengguna, nama mahasiswa
                  maksimal terdiri dari 9 karakter
=======================================================================================================================*/
void MenuBuatHimpunan(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
/*  AUTHOR      : Banteng Harisantoso
    IS          : List POLBAN dan 10 UKM telah dibuat baik sudah berisi atau belum
    FS          : Menampilkan menu untuk melakukan pendataan mahasiswa
    DESKRIPSI   : Prosedur untuk menampilkan menu dan opsi-opsi dalam melakukan pendataan
                  mahasiswa. Terdapat dua pendataan, pendataan mahasiswa POLBAN dan anggota UKM
=======================================================================================================================*/
void MenuEditHimpunan(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : Sudah terbentuk list subset
    FS          : Menampilkan pesan berhasil atau gagal menghapus atau mengubah data mahasiswa ke dalam himpunan.
    DESKRIPSI   : Prosedur untuk memilih menu penghapusan atau pengubahan mahasiswa dari list UKM maupun list POLBAN.
=======================================================================================================================*/
void MenuDisplayHimpunan(superset_list POLBAN, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF);
/*  AUTHOR      : Bob Manuel
    IS          : List superset POLBAN dan subset UKM sudah terbentuk
    FS          : Menampilkan setiap anggota superset POLBAN ataupun setiap anggota dari subset UKM
    DESKRIPSI   : Prosedur untuk masuk ke menu menampilkan mahasiswa dalam superset POLBAN,
                  pengguna akan diarahkan dengan pengkondisian (if else) untuk memilih superset atau subset yang akan ditampilkan anggotanya,
                  Setelahnya, akan menampilkan anggota sesuai opsi yang dipilih
=======================================================================================================================*/ 
void MenuOperasi(superset_list S, subset_list* H1, subset_list* H2, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF);
/*  AUTHOR      : Banteng Harisantoso
    IS          : List POLBAN dan 10 UKM sudah terbentu baik berisi atau kosong
    FS          : Ditampilkan menu untuk melakukan operasi himpunan pada 10 UKM di POLBAN dan menampilkan hasil operasi
    DESKRIPSI   : Prosedur untuk menampilkan menu operasi himpunan untuk 10 UKM di POLBAN terdapat 4 operasi
                  yakni Irisan, Gabungan, Selisih, dan Komplemen
=======================================================================================================================*/
void EkstrakList(subset_list* H, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF);
/*  AUTHOR      : Banteng Harisantoso
    IS          : List 10 UKM sudah terbentu baik berisi atau kosong
    FS          : Mengirimkan parameter berupa UKM ke modul CopyList
    DESKRIPSI   : Prosedur untuk menampilkan memilih UKM yang akan disalin isinya
                  ke variabel sementara yaitu H
=======================================================================================================================*/
void CopyList(subset_list* H, subset_list SC); 
/*  AUTHOR      : Banteng Harisantoso
    IS          : List UKM telah terbentuk
    FS          : Berhasil menyalin list dari UKM ke variabel sementara (H)
    DESKRIPSI   : Prosedur untuk menyalin isi list UKM ke H
=======================================================================================================================*/
void WritePOLBAN(char nama_mhs[], char NIM[]);  
/*  AUTHOR      : Banteng Harisantoso
    IS          : nama_mhs dan NIM berisi nilai yang valid
    FS          : Berhasil menuliskan informasi nama dan NIM mahasiswa baru ke file eksternal bernama POLBAN.txt
    DESKRIPSI   : Prosedur untuk menuliskan informasi mahasiswa ke file eksternal bernama POLBAN.txt
                  
=======================================================================================================================*/
void WriteUKM(int opsi, char nama_mhs[], char NIM[]);  
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima opsi UKM, nama, dan NIM mahasiswa
    FS          : Informasi mahasiswa berhasil ditulis di salah satu UKM 
    DESKRIPSI   : Prosedur untuk menuliskan informasi mahasiwa ke file eksternal dengan
                  format nama "NAMA_UKM.txt"
=======================================================================================================================*/
void EkstrakPOLBAN(superset_list* POLBAN);  
/*  AUTHOR      : Banteng Harisantoso
    IS          : List S sudah terbentuk
    FS          : Berhasil atau gagal menyalin nama-nama mahasiswa beserta nim ke list POLBAN
    DESKRIPSI   : Prosedur untuk menyalin isi file POLBAN.txt ke list S
=======================================================================================================================*/
void EkstrakUKM(superset_list S, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
/*  AUTHOR      : Banteng Harisantoso
    IS          : List S sudah terbentuk
    FS          : Berhasil atau gagal mengirim parameter berupa pilihan UKM ke modul CopyFromFiles
    DESKRIPSI   : Prosedur untuk mengirimkan parameter UKM ke CopyFromFiles
=======================================================================================================================*/
void CopyFromFile(superset_list S, subset_list* H, char NamaUKM[]);
/*  AUTHOR      : Banteng Harisantoso
    IS          : List S dan H sudah terbentuk
    FS          : Berhasil atau gagal menyalin nama-nama mahasiswa beserta nim ke list UKM
    DESKRIPSI   : Prosedur untuk menyalin isi file "NAMA_UKM".txt ke list H
=======================================================================================================================*/
void DeleteFromPOLBANFile(char nama_mhs[], char NIM[]); 
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima variabel nama_mhs dan NIM
    FS          : Berhasil atau gagal menghapus nama-nama mahasiswa beserta nim dari file POLBAN.txt
    DESKRIPSI   : Prosedur untuk menghapus mahasiswa dari file POLBAN.txt
=======================================================================================================================*/
void DeleteInAllUKM(subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF, char nama_mhs[], char NIM[]);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima nama, nim, serta list UKM
    FS          : Berhasil atau gagal menghapus mahasiswa dari semua UKM yang diikuti
    DESKRIPSI   : Prosedur untuk menghapus mahasiswa dari semua list dan file UKM yang diikuti
=======================================================================================================================*/
void DeleteFromUKMFile(char nama_mhs[], char NIM[], char UKM[]);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima nama mahasiwa sebelumnya, nama baru, serta nama UKM
    FS          : Berhasil atau gagal menghapus mahasiswa dari file UKM tertentu
    DESKRIPSI   : Prosedur untuk menghapus mahasiswa dari file UKM tertentu
=======================================================================================================================*/
void WriteLog(char kalimat[]);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima pesan aktivitas
    FS          : Berhasil atau gagal menuliskan pesan ke LOG.txt
    DESKRIPSI   : Prosedur untuk menulis pesan ke LOG.txt
=======================================================================================================================*/
void DisplayLog();
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima nama mahasiwa sebelumnya, nama baru, serta nama UKM
    FS          : Berhasil atau gagal menampilkan LOG dari file LOG.txt
    DESKRIPSI   : Prosedur untuk menampilkan LOG dari file LOG.txt
=======================================================================================================================*/
void MenuEditMahasiswa(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF);
/*  AUTHOR      : Banteng Harisantoso
    IS          : List UKM telah terbentuk
    FS          : Berhasil atau gagal mengedit informasi mahasiswa
    DESKRIPSI   : Prosedur untuk menampilkan menu edit mahasiswa
=======================================================================================================================*/
void PanduanPenggunaan();
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : File PANDUAN.txt bisa ada atau tidak ada
    FS          : Berhasil membuat file PANDUAN.txt
    DESKRIPSI   : Prosedur untuk membuat file PANDUAN.txt
=======================================================================================================================*/
void TampilkanPanduan();
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : File PANDUAN.txt bisa ada atau tidak ada
    FS          : Berhasil menampilkan file PANDUAN.txt
    DESKRIPSI   : Prosedur untuk menampilkan file PANDUAN.txt
=======================================================================================================================*/
bool IsNIMTaken(char NIM[], char NIM_lama[], superset_list S);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima NIM lama, NIM baru, serta list S
    FS          : Diketahui jika satu NIM sudah digunakan atau belum (True berarti sudah, False berarti belum)
    DESKRIPSI   : Fungsi untuk mengetahui jika satu NIM sudah digunakan atau belum
=======================================================================================================================*/
void update_membersuper(char nama_mhs[], char NIM[], char nama_baru[], char NIM_baru[], superset_list* S);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima nama mahasiwa sebelumnya, nama baru, serta list POLBAN
    FS          : Berhasil atau gagal mengedit mahasiswa di list POLBAN
    DESKRIPSI   : Prosedur untuk mengedit mahasiswa di list POLBAN
=======================================================================================================================*/
void EditInAllUKM(subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF, char nama_mhs[], char NIM[], char nama_baru[], char NIM_baru[]);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima nama, nim, serta list UKM
    FS          : Berhasil atau gagal menghapus mahasiswa dari semua UKM yang diikuti
    DESKRIPSI   : Prosedur untuk menghapus mahasiswa dari semua list dan file UKM yang diikuti
=======================================================================================================================*/
void update_membersub(char nama_mhs[], char NIM[], char nama_baru[], char NIM_baru[], subset_list H);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima nama mahasiwa sebelumnya, nama baru, NIM sebelumnya, NIM baru, serta salah satu UKM
    FS          : Berhasil atau gagal mengedit mahasiswa di list UKM tertentu
    DESKRIPSI   : Prosedur untuk mengedit mahasiswa di list UKM tertentu
=======================================================================================================================*/
void EditFilePOLBAN(char nama_mhs[], char NIM[], char nama_baru[], char NIM_baru[]);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima nama mahasiwa sebelumnya, nama baru, NIM sebelumnya, dan NIM baru,
    FS          : Berhasil atau gagal mengedit informasi mahasiswa di file POLBAN.txt
    DESKRIPSI   : Prosedur untuk mengedit mahasiswa di file POLBAN.txt
=======================================================================================================================*/
void EditFileUKM(char nama_mhs[], char NIM[], char nama_baru[], char NIM_baru[],char UKM[]);
/*  AUTHOR      : Banteng Harisantoso
    IS          : Menerima nama mahasiwa sebelumnya, nama baru, NIM sebelumnya, dan NIM baru, serta UKM
    FS          : Berhasil atau gagal mengedit informasi mahasiswa di file UKM
    DESKRIPSI   : Prosedur untuk mengedit mahasiswa di file UKM tertentu
========================================================================================================================*/
#endif 

/* SPHIMPUNAN_H */
