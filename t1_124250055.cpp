//Chairil Fikri M_124250055           ||Username:Admin||Pw:55||
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Karyawan
{
    int IdKaryawan;
    char NamaKaryawan[20];
};

Karyawan ka[100];

struct Barang
{
    char NamaBarang[20];
    int HargaBarang;
    int StokBarang;
};

Barang ba[100];

FILE *tunjuk;

void MenuAwal(){
    cout << "======== WELOCOME TO COCOA HEAVEN ========" << endl;
    cout << "1. Login Admin" << endl;
    cout << "2. Login Karyawan" << endl;
    cout << "3. Keluar" << endl;
    cout << "===========================================" << endl;
}


void TampilAdmin(){
    system("cls");
    cout << "=============================" << endl;
    cout << "         Halo Admin!         " << endl;
    cout << "=============================" << endl;
    cout << "1. Tambah data karyawan" << endl;
    cout << "2. Lihat data karyawan" << endl;
    cout << "3. Searching data karyawan" << endl;
    cout << "4. Logout" << endl;
    cout << "=============================" << endl;
}

void menuAd1(){
    int jumlahkaryawan;
    do {
    cout << "Masukkan jumlah data yang ingin dimasukkan: ";
    cin >> jumlahkaryawan;

    if (cin.fail() || jumlahkaryawan <= 0) {
        cout << "Silahkan masukkan angka Positif." << endl;
        cin.clear();
        cin.ignore();
    } 
} while (jumlahkaryawan <= 0);

    tunjuk = fopen("Karyawan.txt", "ab");
        for (int i=0; i<jumlahkaryawan; i++) {
    
    cout << "\nData ke-" << i+1 << endl;
    cout << "===============================" << endl;
    
    do {
    cout << "ID Karyawan: ";
    cin >> ka[i].IdKaryawan;

    if (cin.fail() || ka[i].IdKaryawan <= 0) {
        cout << "Silahkan masukkan angka Positif.\n" << endl;
        cin.clear();
        cin.ignore();
    }
    } while (ka[i].IdKaryawan <= 0);

    cout << "Nama Karyawan: ";
    cin >> ka[i].NamaKaryawan;
    cout << "===============================" << endl;
    fwrite(&ka[i], sizeof(Karyawan), 1, tunjuk);
    
}
fclose(tunjuk);

cout << "\nData berhasil disimpan!!\n" << endl;


}

void menuAd2(){
    int nomer = 1;
      tunjuk = fopen("Karyawan.txt", "rb");
      cout << "===== Data Karyawan =====" << endl;
      while (fread(&ka, sizeof(Karyawan), 1, tunjuk)){
        cout << "karyawan ke-" << nomer << endl;
        cout << "ID Karyawan: " << ka[0].IdKaryawan << endl;
        cout << "Nama Karyawan: " << ka[0].NamaKaryawan << endl;
        cout << endl;
        nomer++;
      }
      cout << "=====================" << endl;
      fclose(tunjuk);

}

void menuAd3(){
    int IdKa;

    tunjuk = fopen("Karyawan.txt", "rb");

    cout << "Masukkan ID karyawan yang ingin dicari: ";
    cin >> IdKa;

    bool found = false;
    while (fread(&ka, sizeof(Karyawan), 1, tunjuk)) {
        if (ka[0].IdKaryawan == IdKa) {
            cout << "\nData Ditemukan!" << endl;
            cout << "===============================" << endl;
            cout << "ID Karyawan: " << ka[0].IdKaryawan << endl;
            cout << "Nama Karyawan: " << ka[0].NamaKaryawan << endl;
            cout << "===============================\n" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Data tidak ditemukan!!\n" << endl;
    }
    fclose(tunjuk);

}

void MenuAdmin(){
    int PwAd;
    string userAd;
    int kesempatan;
    int pilihAd;
    char lanjutAd;

    cout << "Masukkan username anda: ";
    cin >> userAd;
    cout << "Masukkan Paswsord Anda: ";
    cin >> PwAd;

    if ( userAd != "Admin" && PwAd != 55) {
        

        for ( kesempatan = 0; kesempatan < 3; kesempatan++) {
            system("cls");
            cout << "Tolong Masukkan Username dan Password yang benar!!!" << endl;
            cout << "Sisa kesempatan anda " << 3 - kesempatan << " kali" << endl;
            cout << "Masukkan username anda: ";
            cin >> userAd;
            cout << "Masukkan Pasword Anda: ";
            cin >> PwAd;

            if (userAd == "Admin" && PwAd == 55){
                cout << "\n=====================" << endl;
                cout << "Anda berhasil Login!!" << endl;
                cout << "=====================\n" << endl;
                break;
            }
        }

        if (kesempatan == 3) {
            cout << "\n=====================" << endl;
            cout << "Kesempatan anda habis, Anda bukan admin kami!!" << endl;
            exit(0);
        }
    }

      
    do {
        TampilAdmin();
        cout << "Pilih Menu: ";
        cin >> pilihAd;
        system("cls");


        if (cin.fail() || pilihAd < 1 || pilihAd > 4  ) {
            cin.clear();
            cin.ignore();
            cout << "\nMasukkan angka antara 1-4!!\n" << endl;
            continue;
        }

        switch (pilihAd)
        {
        case 1:
            menuAd1();
            system("pause");
            break;

        case 2:
            menuAd2();
            system("pause");
            break;
        
        case 3:
            menuAd3();
            system("pause");
            break;
        
        case 4:
            system("cls");
            return;
        }

    
            if (pilihAd == 1 || pilihAd == 2 || pilihAd == 3) {
            system("cls");
            cout << "Apakah anda ingin melanjutkan program admin(y/t): ";
            cin >> lanjutAd;
            system("cls");

            do {
                    if (lanjutAd == 'y' || lanjutAd == 'Y') {
                        system("cls");
                        break;
                    } else if (lanjutAd == 't' || lanjutAd == 'T') {
                        return;
                    } else {
                        cout << "Pilihan tidak tersedia. Silakah masukkan(y/t): ";
                        cin >> lanjutAd;
                    }
                } while (true);

        }

    } while (pilihAd != 4);

}




void TampilKaryawan(){
    system("cls");
    cout << "==============================" << endl;
    cout << "        Halo Karyawan!        " << endl;
    cout << "==============================" << endl;
    cout << "1. Tambah data barang" << endl;
    cout << "2. Lihat data barang" << endl;
    cout << "3. edit data barang" << endl;
    cout << "4. cari data barang" << endl;
    cout << "5. Logout" << endl;
    cout << "==============================" << endl;
}

void menuKa1(){
    int jumlahBarang;
    do {
    cout << "Masukkan jumlah barang: ";
    cin >> jumlahBarang;

    if (cin.fail() || jumlahBarang <= 0) {
        cout << "Silahkan masukkan angka positif." << endl;
        cin.clear();
        cin.ignore();
    } 
} while (jumlahBarang <= 0);

    tunjuk = fopen("Barang.txt", "ab");
        for (int i=0; i<jumlahBarang; i++) {
    
    cout << "\nData ke-" << i+1 << endl;
    cout << "===============================" << endl;
    cout << "Nama Barang: ";
    cin >> ba[i].NamaBarang;
    cout << "Harga Barang: ";
    cin >> ba[i].HargaBarang;
    cout << "Stok Barang: ";
    cin >> ba[i].StokBarang;
    cout << "===============================" << endl;
    fwrite(&ba[i], sizeof(Barang), 1, tunjuk);
    
}
fclose(tunjuk);

cout << "\nData berhasil disimpan!" << endl;


}

void Ascending(){
    //buble sort
    int n = 0;
    Barang temp;
    

    tunjuk = fopen("Barang.txt", "rb");
    if (tunjuk == NULL) {
        cout << "File Barang.txt tidak ditemukan!\n" << endl;
        return;
    }

    while (fread(&ba[n], sizeof(Barang), 1, tunjuk)) {
        n++;
    }
    fclose(tunjuk);

    if (n == 0) {
        cout << "Tidak terdapat data dalam file Barang.txt" << "\n" << endl;
        return;
    }

    int j, k;

    for (k = 0; k < n - 1; k++) {
        for ( j = 0; j < n - 1 - k; j++){
            if (ba[j].HargaBarang > ba[j + 1].HargaBarang){
                temp = ba[j];
                ba[j] = ba[j + 1];
                ba[j + 1] = temp;
            }
        }
    }


    for (int i = 0; i < n; i++){
        cout << "\nData ke-" << i+1 << endl;
        cout << "===============================" << endl;
        cout << "Nama Barang: " << ba[i].NamaBarang << endl;
        cout << "Harga Barang: " << ba[i].HargaBarang << endl;
        cout << "Stok Barang: " << ba[i].StokBarang << endl;
        cout << "===============================" << endl;
    }



}

void quickSort(Barang array[], int awal, int akhir) {
    int low = awal, high = akhir;
    int pivot = array[(awal + akhir) / 2].HargaBarang;

    do{
        while (array[low].HargaBarang > pivot)
        {
            low++;
        } 
        
        while (array[high].HargaBarang < pivot)
        {
            high--;
        }
        
        if (low <= high){
            Barang temp = array[low];
            array[low] = array[high];
            array[high] = temp;
            low++;
            high--;
        }
    } while ( low <= high);

    if (awal < high){
        quickSort(array, awal, high);
    }

    if (low < akhir){
        quickSort(array, low, akhir);
    }

}

void quickSortnama(Barang array[], int awal, int akhir) {
    int low = awal, high = akhir;
    char pivot[20];
    strcpy(pivot, array[(awal + akhir) / 2].NamaBarang);

    do{
        while (strcmp(array[low].NamaBarang, pivot) < 0)
        {
            low++;
        } 
        
        while (strcmp(array[high].NamaBarang, pivot) > 0)
        {
            high--;
        }
        
        if (low <= high){
            Barang temp = array[low];
            array[low] = array[high];
            array[high] = temp;
            low++;
            high--;
        }
    } while ( low <= high);

    if (awal < high){
        quickSortnama(array, awal, high);
    }

    if (low < akhir){
        quickSortnama(array, low, akhir);
    }

}

void Descending(){
    //Quick sort
    int n = 0;

    tunjuk = fopen("Barang.txt", "rb");
    if (tunjuk == NULL) {
        cout << "File Barang.txt tidak ditemukan!\n" << endl;
        return;
    }

    while (fread(&ba[n], sizeof(Barang), 1, tunjuk)) {
        n++;
    }
    fclose(tunjuk);

    if (n == 0) {
        cout << "Tidak terdapat data dalam file Barang.txt" << "\n" << endl;
        return;
    }

    quickSort(ba, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << "\nData ke-" << i+1 << endl;
        cout << "===============================" << endl;
        cout << "Nama Barang: " << ba[i].NamaBarang << endl;
        cout << "Harga Barang: " << ba[i].HargaBarang << endl;
        cout << "Stok Barang: " << ba[i].StokBarang << endl;
        cout << "===============================" << endl;
    }


}

void menuKa2(){
int pilihsort;
    
do {
    cout << "======== Sorting ========" << endl;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    cout << "Pilih sorting: ";
    cin >> pilihsort;

    if (cin.fail() || pilihsort < 1 || pilihsort > 2  ) {
        cin.clear();
        cin.ignore();
        cout << "\nMasukkan angka antara 1-2!!!\n" << endl;
        continue;
     }
    } while (pilihsort < 1 || pilihsort > 2);


    switch (pilihsort)
    {
    case 1:
        Ascending();
        break;
    
    case 2:
        Descending();
        break;
    }
}

void menuKa3(){
    char ganti[20];
    int n = 0;
    bool found = false;
    
    tunjuk = fopen("Barang.txt", "rb+");

    if (tunjuk == NULL) {
        cout << "File Barang.txt tidak ditemukan!\n" << endl;
        return;
    }

    while (fread(&ba[n], sizeof(Barang), 1, tunjuk)) {
        n++;
    }

    fclose(tunjuk);

    if (n == 0) {
        cout << "Tidak terdapat data dalam file Barang.txt" << "\n" << endl;
        return;
    }

    cout << "Masukkan Nama Barang yang ingin diedit: ";
    cin >> ganti;

    for (int i = 0; i < n; i++) {
        if (strcmp(ba[i].NamaBarang, ganti) == 0) {
            found = true;

            cout << "\nData Ditemukan!" << endl;
            cout << "===============================" << endl;
            cout << "Nama Barang: " << ba[i].NamaBarang << endl;
            cout << "Harga Barang: " << ba[i].HargaBarang << endl;
            cout << "Stok Barang: " << ba[i].StokBarang << endl;
            cout << "===============================\n" << endl;
    
            
            cout << "Masukkan Nama Barang Baru: ";
            cin >> ba[i].NamaBarang;
            cout << "Masukkan Harga Barang Baru: ";
            cin >> ba[i].HargaBarang;
            cout << "Masukkan Stok Barang Baru: ";
            cin >> ba[i].StokBarang;
            break;
        }
        
    }

    if (found) {
        tunjuk = fopen("Barang.txt", "wb");
        for (int j = 0; j < n; j++) {
            fwrite(&ba[j], sizeof(Barang), 1, tunjuk);
        }
        fclose(tunjuk);


        cout << "\nData berhasil diubah!" << endl;
        cout << "\n===============================" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

}

void menuKa4(){
    int metode, n = 0;
    char cari[20];
    bool found = false;

    tunjuk = fopen("Barang.txt", "rb");
    if (tunjuk == NULL) {
        cout << "File Barang.txt tidak ditemukan!\n" << endl;
        return;
    }


    cout << "Masukkan Nama Barang yang ingin dicari: ";
    cin >> cari;
    cout << "\n";

    while (fread(&ba[n], sizeof(Barang), 1, tunjuk)) {
        n++;
    }
    fclose(tunjuk);

do {
    cout << "1. Sequential Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Pilih metode pencarian: ";
    cin >> metode;

    if (cin.fail() || metode < 1 || metode > 2  ) {
        cin.clear();
        cin.ignore();
        system("cls");
        cout << "Masukkan angka antara 1-2!!!\n" << endl;
        continue;
     }
} while (metode < 1 || metode > 2);


    switch (metode)
    {
    case 1:
        for (int i = 0; i < n; i++){
            if (strcmp(ba[i].NamaBarang, cari) == 0) {
                cout << "\nData Ditemukan!" << endl;
                cout << "===============================" << endl;
                cout << "Nama Barang: " << ba[i].NamaBarang << endl;
                cout << "Harga Barang: " << ba[i].HargaBarang << endl;
                cout << "Stok Barang: " << ba[i].StokBarang << endl;
                cout << "===============================" << endl;
                found = true;
                break;
            }
        }
        break;
    
    case 2:

        quickSortnama(ba, 0, n - 1);

        int kiri = 0; 
        int kanan = n - 1;
        int tengah = (kiri + kanan) / 2;
        int cek;
        while (kiri <= kanan){
            cek = strcmp(ba[tengah].NamaBarang, cari);

            if (cek == 0){
                cout << "\nData Ditemukan!" << endl;
                cout << "===============================" << endl;
                cout << "Nama Barang: " << ba[tengah].NamaBarang << endl;
                cout << "Harga Barang: " << ba[tengah].HargaBarang << endl;
                cout << "Stok Barang: " << ba[tengah].StokBarang << endl;
                cout << "===============================" << endl;
                found = true;
                break;
            } else if (cek < 0) {
                kiri = tengah + 1;
            } else {
                kanan = tengah - 1;
            }

            tengah = (kiri + kanan) / 2;
        }
        break;
    }

    if (!found) {
        cout << "Data tidak ditemukan!" << endl;
    }

}

void MenuKaryawan(){
    int pilihKa;
    char lanjutKa;
    
        do {
        TampilKaryawan();
        cout << "Pilih Menu: ";
        cin >> pilihKa;

        if (cin.fail() || pilihKa < 1 || pilihKa > 5  ) {
            cin.clear();
            cin.ignore();
            cout << "\nMasukkan angka antara 1-5!\n" << endl;
            continue;
        }

        switch (pilihKa)
        {
        case 1:
            system("cls");
            menuKa1();
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            menuKa2();
            system("pause");
            system("cls");
            break;
        
        case 3:
            system("cls");
            menuKa3();
            system("pause");
            system("cls");
            break;
        
        case 4:
            system("cls");
            menuKa4();
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            return;
        } 

            if (pilihKa == 1 || pilihKa == 2 || pilihKa == 3) {
            cout << "Apakah anda ingin melanjutkan program karyawan(y/t): ";
            cin >> lanjutKa;
            system("cls");

            do {
                    if (lanjutKa == 'y' || lanjutKa == 'Y') {
                        break;
                    } else if (lanjutKa == 't' || lanjutKa == 'T') {
                        return;
                    } else {
                        cout << "Pilihan tidak tersedia. Silakah masukkan(y/t): ";
                        cin >> lanjutKa;
                    }
                } while (true);

            cout << "\n";
        }



    } while (pilihKa != 5);

}


int main(){

    int pilih;

    do {
        MenuAwal();
        cout << "Masukkan pilihan menu anda: ";
        cin >> pilih;
  

         if (cin.fail() || pilih < 1 || pilih > 3  ) {
            cin.clear();
            cin.ignore();
            cout << "\nMasukkan angka antara 1-3!!!\n" << endl;
            continue;
         }


        switch (pilih)
        {
        case 1:
            system("cls");
            MenuAdmin();
            break;
        
        case 2:
            system("cls");
            MenuKaryawan();
            break;
        
        case 3:
            cout << "Terima Kasih!!!" << endl;
            return 0;

        }


    } while (pilih != 3);
    

    return 0;
}
