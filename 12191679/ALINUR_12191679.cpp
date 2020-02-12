#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

void kop()
{
    cout << "***********************************************" << endl;
    cout << "\t\t   Say Kimchi" << endl;
    cout << "\t     Bukti Pemesanan Makanan" << endl;
    cout << "===============================================" << endl;
}

void line()
{
    cout << "===============================================" << endl;
}

struct agen
{
    int noPesan;
    string namaCusto;
    int jumData;
}custo;

int main()
{
    int i;
    char kode[10];
    int jumBeli[10];
    string isiPaket[10];
    int hargaPaket[10], subTotal[10];
    char jawab;
    int totalHarga, ppn, totalBayar, uangBayar, kembalian;

    pesan:
    totalHarga = 0;
    system("cls");
    kop();
    cout << endl;
    cout << "Input No Pesan         : "; cin >> custo.noPesan;
    cout << "Input Nama Customer    : "; cin >> custo.namaCusto;
    cout << "Input Jumlah Data      : "; cin >> custo.jumData;
    for(i = 1; i <= custo.jumData; i++)
    {
        cout << endl;
        cout << "Data Ke-" << i << endl;
        cout << "Input Kode Paket Makanan [S/M/L] : "; cin >> kode[i];
        if(kode[i] == 's' || kode[i] == 'S')
        {
            isiPaket[i] = "Toppokki 150 gr";
            hargaPaket[i] = 55000;
        }
        else if(kode[i] == 'm' || kode[i] == 'M')
        {
            isiPaket[i] = "2 Toppokki 150 gr";
            hargaPaket[i] = 125000;
        }
        else if(kode[i] == 'l' || kode[i] == 'L')
        {
            isiPaket[i] = "5 Toppokki 150 gr";
            hargaPaket[i] = 175000;
        }
        else
        {
            isiPaket[i] = "Null";
            hargaPaket[i] = 0;
        }
        cout << "Input Jumlah Beli                : "; cin >> jumBeli[i];
    }

    system("cls");
    kop();
    cout << endl;
    cout << "No Pesan        : " << custo.noPesan << endl;
    cout << "Nama Customer   : " << custo.namaCusto << endl;
    cout << endl;
    line();
    cout << "No" << "      Isi Paket     " << " " << "HargaPaket" << " " << "Beli" << " " << "Subtotal" <<  endl;
    line();
    for(i = 1; i <= custo.jumData; i++)
    {
        cout << setiosflags(ios::left) << setw(3) << i;
        cout << setiosflags(ios::left) << setw(22) << isiPaket[i];
        cout << setiosflags(ios::left) << setw(10) << hargaPaket[i];
        cout << setiosflags(ios::left) << setw(4) << jumBeli[i];
        subTotal[i] = jumBeli[i]*hargaPaket[i];
        cout << setiosflags(ios::left) << setw(0) << subTotal[i] << endl;
        totalHarga = totalHarga+subTotal[i];
    }
    line();
    cout << setiosflags(ios::left) << setw(24) << " ";
    cout << setiosflags(ios::left) << setw(0) << "Total Harga Rp." << totalHarga << endl;
    ppn = totalHarga*0.1;
    cout << setiosflags(ios::left) << setw(24) << " ";
    cout << setiosflags(ios::left) << setw(0) << "PPn 10%     Rp." << ppn << endl;
    totalBayar = ppn+totalHarga;
    cout << setiosflags(ios::left) << setw(24) << " ";
    cout << setiosflags(ios::left) << setw(0) << "Total Bayar Rp." << totalBayar << endl;
    cout << setiosflags(ios::left) << setw(24) << " ";
    cout << setiosflags(ios::left) << setw(0) << "Uang Bayar  Rp."; cin >> uangBayar;
    kembalian = uangBayar-totalBayar;
    cout << setiosflags(ios::left) << setw(24) << " ";
    cout << setiosflags(ios::left) << setw(0) << "Kembalian   Rp." << kembalian << endl;

    cout << endl;
    cout << "Pesan Kembali ? [Y/n] : "; cin >> jawab;
    if(jawab == 'y' || jawab == 'Y')
    {
        goto pesan;
    }
    else
    {
        cout << endl;
        cout << "Terimakasih pesanannya~" << endl;
        getch();
    }
    
    return 0;
}
 