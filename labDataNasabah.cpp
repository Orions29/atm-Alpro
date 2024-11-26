#include <iostream>
#include <string>
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
// >> Inisialisasi Global Array
nasabah dataNasabah[100];
int jumlahNasabah = 0; // Total Jumlah Data yang dimiliki
// >> init Fungsi
// Error Handling Function
void inputHandling(string question, string &var, short lineOr); // Untuk String
void inputHandling(string question, int &var);                  // untuk int
void inputHandling(string question, float &var);                // untuk float
void inputHandling(string question, short &var);                // untuk short
// Main Function
void inisialisasiData();
void tampilDataNasabah(int noRekIn);
void inputNasabah();
void delNasabah();
// void test(); // Function Test
// File Testing
int main()
{
      inisialisasiData();
      // inputNasabah();
      tampilDataNasabah(123456888);
      // delNasabah();
      // tampilDataNasabah(0);
      return 0;
}
// Desc Function
// Overloading Funct untuk Error Handling Pengguna
void inputHandling(string question, string &var, short lineOr)
{
      bool statLoop = false;
      do
      {
            cout << question;
            // Jika 1 maka Spasi dianggap kesalahan
            if (lineOr == 1)
            {
                  cin >> var;
            }
            // Jika 2 maka spasi akan dibaca
            else if (lineOr == 2)
            {
                  getline(cin, var);
            }
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
// Untuk Variabel Integer
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
// Untuk Variabel FLoat
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
// Short
void inputHandling(string question, short &var)
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
// Funtioon Inti
// Fungsi Untuk Menampilkan Data Nasabah dengan parameter nomor rekening
void tampilDataNasabah(int noRekIn)
{
      bool find = false;
      for (int i = 0; i < jumlahNasabah; i++)
      {
            if (noRekIn == dataNasabah[i].noRek)
            {
                  find = true;
                  cout << "\n\t<Lihat Data Dan Histori>\n"
                       << endl;
                  cout << "Nasabah:" << endl;
                  cout << "\n Data Nasabah:" << endl;
                  cout << "No Rek  : " << dataNasabah[i].noRek << endl;
                  cout << "Nama    : " << dataNasabah[i].nama << endl;
                  cout << "Saldo   : " << dataNasabah[i].saldo << endl;
                  cout << "\nHistori Transaksi:" << endl;
                  if (dataNasabah[i].historiNasabah[0].idTrans > 0)
                  {
                        for (int j = 0; j < dataNasabah[i].jumlahTrans; ++j)
                        {
                              cout << "ID Trans : " << dataNasabah[i].historiNasabah[j].idTrans << endl;
                              cout << "Nominal  : " << dataNasabah[i].historiNasabah[j].nominal << endl;
                              cout << "No Rek T : " << dataNasabah[i].historiNasabah[j].noRektuj << endl;
                              cout << endl;
                              // Pemberhentian Jika Array Mencapai Akhir
                              if (dataNasabah[i].historiNasabah[j].idTrans == 0)
                              {
                                    break;
                              }
                        }
                  }
                  else
                  {
                        cout << "\n [Empty Set]\n";
                  }
            }
            else
            {
                  find = false;
            }
      }
      find == false ? cout << "\n [Error Tag]- Rekening Tak ditemukan\n" : cout << "\n <Data Tertampil Semua>";
}
// Funct Untuk Input Nasabah
void inputNasabah()
{
      jumlahNasabah++;
      cout << "\n\n\t>-Menu Input Nasabah Baru-<\n";
      cout << "\n\nHallo Nasabah Baru!!";
      cout << "\n Data Nasabah:" << endl;
      inputHandling("\nNo Rek  : ", dataNasabah[jumlahNasabah].noRek);
      inputHandling("\nPass    : ", dataNasabah[jumlahNasabah].pass, 1);
      inputHandling("\nNama    : ", dataNasabah[jumlahNasabah].nama, 2);
      inputHandling("\nSaldo   : ", dataNasabah[jumlahNasabah].saldo);
      dataNasabah[jumlahNasabah].jumlahTrans = 0; // Nasabah Baru Tidak Memiliki Histori Transaksi
}
// Fungsi untuk delete data nasabah
void delNasabah()
{
      int noRekIn;
      short opt;
      bool find = true;
      do
      {
            inputHandling("Berapa Nomor Rekeningnya?: ", noRekIn);
            for (int i = 0; i < jumlahNasabah; i++)
            {
                  if (noRekIn == dataNasabah[i].noRek)
                  {
                        find = true;
                        cout << "\nSuccess Delete Data user {" << dataNasabah[i].nama << "} ";
                        dataNasabah[i] = {
                            0,
                            "",
                            "",
                            0,
                            0,
                            {}}; // Code Pengosongan Data Nasabah
                        break;
                  }
                  else
                  {
                        find = false;
                  }
            }
            if (find == false)
            {
                  cout << "\n[Error Tag] - Input Not Found - Wah ini gaada nih gimana dong?\n";
                  inputHandling("\n(1)Ulang or (2)Keluar?: ", opt);
                  if (opt == 1)
                  {
                        find = false;
                  }
                  else
                  {
                        find = true;
                        cout << "\n Hapus No Rek <" << noRekIn << "> Dibatalkan";
                  }
            }
      } while (find == false);
}