#include <iostream>
#include <iomanip>
using namespace std;
// Global Var Init
bool mainMenuLoop = false;
// Decklare Funtion
// Error handling Func
void ifCinError();
// Main Feature
void login();
void cekSaldo(int saldo);
void setorSaldo(int &saldo, int transaksi[], int &indexTransaksi);
void tarikSaldo(int &saldo, int transaksi[], int &indexTransaksi);
void transferRekening(int &saldo, int transaksi[], int &indexTransaksi);
void riwayatTransaksi(int transaksi[], int indexTransaksi);
void pause();

int main()
{
      unsigned short opt;
      // Identitas Pembuat
      cout << "\n<Selamat Datang di ATM Program ATM> \nKarya: "
           << " \t\n1. Zaka Ahmad Ghofari             (123240144)"
           << " \t\n2. Dimas Hafid Fathoni            (123240159)"
           << " \t\n3. Erlan Rifqi Davin Darmawan     (123240173)"
           << " \t\n4. Jauza Ilham Mahardika Putra    (123240174)"
           << " \t\n5. Rio Meidi Ataurrahman          (123240175)\n\n";
      do
      {
            // Penampil Menu Utama
            cout << "\t\t <<Menu ATM>>\n";
            cout << left << setw(25) << "1> Cek Saldo" << right << setw(25) << "Transfer Rekening <4\n\n";
            cout << left << setw(25) << "2> Deposit Saldo" << right << setw(25) << "Tarik Tunai <5\n\n";
            cout << left << setw(25) << "3> Riwayat Transaksi" << right << setw(25) << "Gajadi Hehe <6\n\n";
            // Input User
            cout << "\nNasabah Mau Yang Mana?: ";
            cin >> opt;
            ifCinError();
      } while (mainMenuLoop = false);

      return 0;
}
// Error Handling Func
void ifCinError()
{
      if (cin.fail())
      {
            cin.clear();          // Menghapus Semua Fail Flag
            cin.ignore(30, '\n'); // Mengabaikan Input
            cout << "\n[Error Tag] -" << "Walah Mas Nginput apa njenengan\n";
      }
};
// Main Feature
void login()
{
}