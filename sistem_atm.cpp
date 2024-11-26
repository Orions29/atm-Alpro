#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
// (NEW) Declare Function
void login();
void cekSaldo(int saldo);
void setorSaldo(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi);
void tarikSaldo(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi);
void transferRekening(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi);
void riwayatTransaksi(int transaksi[], string deskripsi[], int idTransaksi[], int indexTransaksi);
void Pause();
// Declare Function
// void login();
// void cekSaldo(int saldo);
// void setorSaldo(int &saldo, int transaksi[], int &indexTransaksi);
// void tarikSaldo(int &saldo, int transaksi[], int &indexTransaksi);
// void transferRekening(int &saldo, int transaksi[], int &indexTransaksi);
// void riwayatTransaksi(int transaksi[], int indexTransaksi);
// void Pause();

int main()
{
    int nomor_rek;
    int password_rek;
    int correct_nmr = 12345678;
    int correct_pass = 123456;
    const int max_chance = 3;
    int chance = 0;
    int transaksi[100];
    string deskripsi[100];
    int idTransaksi[100];
    int indexTransaksi = 0;
    int saldo = 0;
    int choice;
    do
    {
        cout << "Masukkan Nomor Rekening (8 Digit)\n";
        cout << ">> ";
        cin >> nomor_rek;
        cout << "Masukkan Password Rekening (6 Digit)\n";
        cout << ">> ";
        cin >> password_rek;

        if (nomor_rek == correct_nmr && password_rek == correct_pass)
        {
            cout << "Detail yang anda masukkan benar.\n";
            Pause();
            break;
        }
        else if (nomor_rek != correct_nmr && password_rek != correct_pass)
        {
            chance++;
            cout << "Nomor Rekening dan Password Rekening yang dimasukkan salah!\n";
            cout << "Kesempatan Anda tersisa " << (max_chance - chance) << endl;
        }
        else if (nomor_rek != correct_nmr)
        {
            chance++;
            cout << "Nomor Rekening yang dimasukkan salah!\n";
            cout << "Kesempatan Anda tersisa " << (max_chance - chance) << endl;
        }
        else if (password_rek != correct_pass)
        {
            chance++;
            cout << "Password Rekening yang dimasukkan salah!\n";
            cout << "Kesempatan Anda tersisa " << (max_chance - chance) << endl;
        }
    } while (chance < max_chance);
    if (chance == max_chance)
    {
        cout << "Kesempatan Anda habis\n";
        return 0;
    }
    do
    {
        system("cls");
        cout << "\t\t<<< Menu ATM >>>\n";
        cout << "1> Cek Saldo\t\t\t     Transfer Rekening <4\n\n";
        cout << "2> Setor Saldo\t\t\t     Riwayat Transaksi <5\n\n";
        cout << "3> Tarik Tunai\t\t\t     Exit              <6\n\n";
        cout << "Masukkan pilihan >> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cekSaldo(saldo);
            break;
        case 2:
            setorSaldo(saldo, transaksi, deskripsi, idTransaksi, indexTransaksi);
            break;
        case 3:
            tarikSaldo(saldo, transaksi, deskripsi, idTransaksi, indexTransaksi);
            break;
        case 4:
            transferRekening(saldo, transaksi, deskripsi, idTransaksi, indexTransaksi);
            break;
        case 5:
            riwayatTransaksi(transaksi, deskripsi, idTransaksi, indexTransaksi);
            break;
        case 6:
            cout << "Terimakasih telah menggunakan ATM ini, Anda kena hack wkwkwk 😂😂😂😂😂😂😂😂😂😍😍😍😍😍😍😍😘😘🤣🤣🤣🤣" << endl;
            return 0;
            break;
        default:
            cout << "Pilihan yang Anda masukkan salah\n";
            break;
        }
    } while (choice != 6);
    return 0;
}
// Fungsi Login

// Function Pengecekan Saldo
void cekSaldo(int saldo)
{
    cout << "Saldo Anda saat ini adalah Rp. " << saldo << endl;
    Pause();
}
// Function Setor Saldo
void setorSaldo(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi)
{
    int jumlah;
    cout << "Masukkan jumlah saldo yang ingin ditransfer\n";
    cout << ">> ";
    cin >> jumlah;

    saldo += jumlah;
    transaksi[indexTransaksi] = -jumlah;
    deskripsi[indexTransaksi] = "Setor Saldo";
    idTransaksi[indexTransaksi] = rand() % 90000000 + 10000000;
    indexTransaksi++;
    Pause();
}
// Function Tarik Saldo
void tarikSaldo(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi)
{
    int jumlah;
    cout << "Masukkan jumlah Tunai yang ingin ditarik\n";
    cout << ">> ";
    cin >> jumlah;
    if (saldo < jumlah)
    {
        cout << "Saldo Anda belum mencukupi untuk melakukan penarikan.\n";
    }
    else
    {
        saldo -= jumlah;
        transaksi[indexTransaksi] = jumlah;
        deskripsi[indexTransaksi] = "Tarik Saldo";
        idTransaksi[indexTransaksi] = rand() % 90000000 + 10000000;
        indexTransaksi++;
        cout << "Saldo anda saat ini tersisa : " << saldo << endl;
    }
    Pause();
}
// Function Transfer Rekening
void transferRekening(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi)
{
    int rekening_tujuan;
    int jumlah;
    do
    {
        cout << "Masukkan Nomor Rekening tujuan anda (8 digit)\n";
        cout << ">> ";
        cin >> rekening_tujuan;
        if (rekening_tujuan < 10000000 || rekening_tujuan > 99999999)
        {
            cout << "Nomor Rekening yang Anda Masukkan tidak valid\n";
        }
    } while (rekening_tujuan < 10000000 || rekening_tujuan > 99999999);

    cout << "Masukkan jumlah Saldo yang ingin ditransfer\n";
    cout << ">> ";
    cin >> jumlah;
    if (saldo < jumlah)
    {
        cout << "Saldo Anda tidak mencukupi\n";
    }
    else
    {
        saldo -= jumlah;
        transaksi[indexTransaksi] = -jumlah;
        deskripsi[indexTransaksi] = "Transfer";
        idTransaksi[indexTransaksi] = rand() % 90000000 + 10000000;
        indexTransaksi++;
        cout << "Transfer berhasil ke rekening " << rekening_tujuan << "\n";
        cout << "Saldo anda saat ini tersisa : " << saldo << endl;
    }
    Pause();
}
// Function Riwayat Transaksi
void riwayatTransaksi(int transaksi[], string deskripsi[], int idTransaksi[], int indexTransaksi)
{
    const int transHal =  5;
    int halaman = 0;
    int totalHal = (indexTransaksi + transHal - 1)/ transHal;
    int pilihan;
    bool exit = false;
    if (indexTransaksi == 0)
    {
        cout << "Riwayat transaksi anda belum ada\n";
        Pause();
        return;
    }
do {system("cls");
    cout << "<= Riwayat Transaksi =>\n";
    cout << "Page (" << halaman + 1 << "/" << totalHal << ")\n";
    cout << "|No | Id Transaksi | Nominal         | Tujuan           |\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    for (int i = halaman * transHal; i < min(indexTransaksi, (halaman + 1) * transHal); i++)
    {
        string nominalTrans = (transaksi[i] > 0 ? "+" : "-") + to_string(abs(transaksi[i]));
        string tujuan = deskripsi[i];
        cout << "|" << setw(3) << i + 1 << " | " << setw(10) << idTransaksi[i] << " | Rp" << setw(15) << nominalTrans + ",00" << " | " << setw(15) << tujuan << " |\n";
    }
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "\n                                       Next Page     1<\n";
    cout <<"                                       Previous Page 2<\n";
    cout << "                                       Keluar        3<\n";
    cout << "Masukkan pilihan >> ";
    cin >> pilihan;

    if (pilihan == 1)
    {
        halaman = (halaman + 1) % totalHal;
    } else if (pilihan == 2)
    {
        halaman = (halaman - 1) % totalHal;
    } else if (pilihan == 3)
    {
        exit = true;
    } else
    {
        cout << "pilihan yang Anda masukkan salah\n";
        Pause();
    }
    } while (!exit);
    Pause();
}
void Pause()
{
    cout << "\nTekan Enter untuk melanjutkan...\n";
    cin.ignore();
    cin.get();
}
{
    cout << "\nTekan Enter untuk melanjutkan...\n";
    cin.ignore();
    cin.get();
}
