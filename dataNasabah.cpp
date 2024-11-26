#include <iostream>
using namespace std;

struct histori
{
      int idTrans;
      int nominal;
      int noRektuj;
};

struct nasabah
{
      int noRek;
      string pass;
      string nama;
      int saldo;
      int jumlahTrans;
      histori historiNasabah[100];
};
// Inisialisasi Global Array
nasabah dataNasabah[100];
int jumlahNasabah = 0; // Total Jumlah Data yang dimiliki
// init Fungsi
void listHistori(int tampil);
void inputNasabah();
void inisialisasiData();
void test();
// Overloading Funct untuk Error Handling Pengguna
void inputHandling(string question, string &var)
{
      bool statLoop = false;
      do
      {
            cout << question;
            cin >> var;
            if (cin.fail())
            {
                  cin.clear();          // Menghapus Semua Fail Flag
                  cin.ignore(30, '\n'); // Mengabaikan Input
                  cout << "\n[Error Tag] -" << "Walah Mas Nginput apa njenengan\n";
                  statLoop = true;
            }
            else
            {
                  statLoop = false;
            }
      } while (statLoop == true);
};
void inputHandling(string question, int &var)
{
      bool statLoop = false;
      do
      {
            cout << question;
            cin >> var;
            if (cin.fail())
            {
                  cin.clear();          // Menghapus Semua Fail Flag
                  cin.ignore(30, '\n'); // Mengabaikan Input
                  cout << "\n[Error Tag] -" << "Walah Mas Nginput apa njenengan\n";
                  statLoop = true;
            }
            else
            {
                  statLoop = false;
            }
      } while (statLoop == true);
};
void inputHandling(string question, float &var)
{
      cout << question;
      bool statLoop = false;
      do
      {
            cin >> var;
            if (cin.fail())
            {
                  cin.clear();          // Menghapus Semua Fail Flag
                  cin.ignore(30, '\n'); // Mengabaikan Input
                  cout << "\n[Error Tag] -" << "Walah Mas Nginput apa njenengan\n";
                  statLoop = true;
            }
            else
            {
                  statLoop = false;
            }
      } while (statLoop == true);
};

// File Testing
int main()
{
      // inisialisasiData();
      inputNasabah();
      listHistori(1);
      return 0;
}
// Fungsi Untuk Inisialisasi Data Lama
void inisialisasiData()
{
      dataNasabah[jumlahNasabah++] =
          {12345678, "admin", "Rio Meidi A", 2000000, 3,
           {// Inisialisasi langsung historiNasabah
            {1, 500000, 87654321},
            {2, 300000, 87654322},
            {3, 200000, 87654323}}};
      dataNasabah[jumlahNasabah++] =
          {12215678, "admin", "Tony Antonio", 7000000, 3,
           {// Inisialisasi langsung historiNasabah
            {1, 500000, 87654321},
            {2, 300000, 87654322},
            {3, 200000, 87654323}}};
}
// Fungsi Untuk Menampilkan Data Nasabah
void listHistori(int tampil)
{
      cout << "Nasabah:" << endl;
      cout << "\n Data Nasabah:" << endl;
      cout << "No Rek  : " << dataNasabah[tampil].noRek << endl;
      cout << "Nama    : " << dataNasabah[tampil].nama << endl;
      cout << "Saldo   : " << dataNasabah[tampil].saldo << endl;
      cout << "\nHistori Transaksi:" << endl;
      for (int i = 0; i < dataNasabah[tampil].jumlahTrans; ++i)
      {
            cout << "ID Trans : " << dataNasabah[tampil].historiNasabah[i].idTrans << endl;
            cout << "Nominal  : " << dataNasabah[tampil].historiNasabah[i].nominal << endl;
            cout << "No Rek T : " << dataNasabah[tampil].historiNasabah[i].noRektuj << endl;
            cout << endl;
            // Pemberhentian Jika Array Mencapai Akhir
            if (dataNasabah[tampil].historiNasabah[i].idTrans == 0)
            {
                  break;
            }
      }
}
// Funct Untuk Input Nasabah
void inputNasabah()
{
      int noRekIn, saldoIn;
      string passIn, namaIn;
      jumlahNasabah++;
      cout << "\n\n\t>-Menu Input Nasabah Baru-<\n";
      cout << "\n\nHallo Nasabah Baru!!";
      cout << "\n Data Nasabah:" << endl;
      inputHandling("\nNo Rek  : ", dataNasabah[jumlahNasabah].noRek);
      inputHandling("\nPass  : ", dataNasabah[jumlahNasabah].pass);
      inputHandling("\nNama  : ", dataNasabah[jumlahNasabah].nama);
      inputHandling("\nSaldo  : ", dataNasabah[jumlahNasabah].saldo);
      dataNasabah[jumlahNasabah].jumlahTrans = 0; // Nasabah Baru Tidak Memiliki Histori Transaksi
}