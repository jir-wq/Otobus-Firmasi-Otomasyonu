#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<locale.h>
#define max 100
using namespace std;
struct seferbilgi
{
	string kyeri;
	string vyeri;
	float ksaati;
	float vsaati;
	string kaptan;
	int o_no;
};

struct soforbilgi
{
	string ad_soyad;
	long long tc;
	int yas;
	int deneyimyili;
};

soforbilgi soforler[max];
seferbilgi seferler[max];

void yukleSeferBilgileri();
void yukleSoforBilgileri();
void sefergir();
void seferlistesi();
void seferduzenle();
void sefersil();
void seferara();
void soforgiris();
void soforlistesi();
void soforsil();
void kayitSeferBilgileri();
void kayitSoforBilgileri();


using namespace std;

int main()
{
	yukleSeferBilgileri();
	yukleSoforBilgileri();
	char menu;
	do
	{
		system("cls");

		int secim;
		setlocale(LC_ALL,"Turkish");
		cout << "                                       |----------ÝSUBU TURÝZM-----------|" << endl;
		cout << "                                       |--------1 Sefer giriþi-----------|" << endl;
		cout << "                                       |--------2 Sefer listesi----------|" << endl;
		cout << "                                       |--------3 Sefer düzenle----------|" << endl;
		cout << "                                       |--------4 Sefer sil--------------|" << endl;
		cout << "                                       |--------5 Sefer ara--------------|" << endl;
		cout << "                                       |---6 Firma otobüs þoforü giriþi--|" << endl;
		cout << "                                       |---7 Firma þoförler listesi------|" << endl;
		cout << "                                       |--------8 Þoför sil--------------|" << endl;
		cout << "Seçim yapýnýz: ";
		cin >> secim;

		switch(secim)
		{
			case 1:
			sefergir();
			break;

			case 2:
			seferlistesi();
			break;

			case 3:
			seferduzenle();
			break;

			case 4:
			sefersil();
			break;

			case 5:
			seferara();
			break;

			case 6:
			soforgiris();
			break;

			case 7:
			soforlistesi();
			break;

			case 8:
			soforsil();
			break;

			default:
			cout << "Geçersiz seçim!" << endl;
		}
		cout << "Ana menüye dönmek ister misiniz(e/h)? " ;
		cin >> menu;

		kayitSeferBilgileri();
        kayitSoforBilgileri();
	}
	while(menu=='e' || menu=='E');
	return 0;

}
// sefer giriþi yapmak için kullanýlan fonksiyondur
void sefergir()
{
	char cvp;
	do
	{
	int seferno;
	cout << "Sefer numarasýný giriniz(1/100): ";
	cin >> seferno;
	if(seferler[seferno].kyeri=="")
	{
	cout << "Kalkýþ yeri: ";
	cin >> seferler[seferno].kyeri;
	cout << "Kalkýþ saati: ";
	cin >> seferler[seferno].ksaati;
	cout << "Varýþ yeri: ";
	cin >> seferler[seferno].vyeri;
	cout << "Varýþ saati: ";
	cin >> seferler[seferno].vsaati;
	cout << "Seferi yapacak olan otobüs numarasý: ";
	cin >> seferler[seferno].o_no;
	cin.ignore();
	cout << "Sefer kaptanlarý: ";
	getline(cin,seferler[seferno].kaptan);
	}
	else
	cout << "Eklemek istediðiniz sefer numarasýna önceden tanýmlanan sefer vardýr. " << endl;
	cout << "Sefer eklemeye devam etmek ister misiniz(e/h)?" << endl;
	cin >> cvp;

	}while(cvp=='e' || cvp=='E');
}

// sefer listelemek için kullanýlan fonksiyondur
void seferlistesi()
{
	for(int i=0;i<max;i++)
	{
		if(seferler[i].kyeri == "") continue;
		cout << i << ". sefer kalkýþ yeri : " << seferler[i].kyeri << endl;
		cout << i << ". sefer kalkýþ saati : " << seferler[i].ksaati << endl;
		cout << i << ". sefer varýþ yeri : " << seferler[i].vyeri << endl;
		cout << i << ". sefer varýþ saati : " << seferler[i].vsaati << endl;
		cout << i << ". sefer otobüs numarasý : " << seferler[i].o_no << endl;
		cout << i << ". sefer kaptanlarý : " << seferler[i].kaptan << endl;
		cout << "\n\n";
	}
}

// sefer düzenlemek için kullanýlan fonksiyondur
void seferduzenle()
{
	int no;
	cout << "Düzenlemek istediðiniz sefer numarasini giriniz: ";
	cin >> no;
	if(seferler[no].kyeri=="")
	{
		cout << "Düzenlemek istediðiniz sefer bulunamamýþtýr. " << endl;
	}
	else
	{
	cout << "\nSefer düzenlemesi yapýnýz" << endl;
	cout << "Kalkýþ yeri: ";
	cin >> seferler[no].kyeri;
	cout << "Kalkýþ saati: ";
	cin >> seferler[no].ksaati;
	cout << "Varýþ yeri: ";
	cin >> seferler[no].vyeri;
	cout << "Varýþ saati: ";
	cin >> seferler[no].vsaati;
	cout << "Seferi yapacak olan otobüs numarasý: ";
	cin >> seferler[no].o_no;
	cin.ignore();
	cout << "Sefer kaptanlarý: ";
	getline(cin,seferler[no].kaptan);
	}
}

//sefer silmek için kullanýlan fonksiyondur
void sefersil()
{
	int no;
	char secim;
	do
	{
	cout << "Silmek istediðiniz sefer numarasýný giriniz: ";
	cin >> no;
	if(no<0 || no>100 || seferler[no].kyeri=="")
	{
		cout << "Silinecek sefer bulunamadý." << endl;
	}
	else
	{
		seferler[no].kyeri="";
		seferler[no].ksaati=0.0f;
		seferler[no].vyeri="";
		seferler[no].vsaati=0.0f;
		seferler[no].o_no=0;
		seferler[no].kaptan="";
		cout << "Sefer numarasý " << no << " olan sefer baþarýyla silindi." << endl;
		cout << "\n\n";
	}
	cout << "Silme iþlemine devam etmek istiyor musunuz(e/h)? " ;
	cin >> secim;

	}while(secim=='e' || secim=='E');
}

// sefer aramak için kullanýlan fonksiyondur
void seferara()
{
	int no;
	char secim;
	do
	{
	cout << "Aramak istediðiniz sefer numarasýný giriniz: ";
	cin >> no;
	if(no>=100 || seferler[no].kyeri=="")
	{
		cout << "Aradýðýnýz sefer bulunamamýþtýr,lütfen geçerli bir sayý giriniz." << endl;
	}
	else
		for(int i=no;i<no+1;i++)
		{
			cout << i << ". sefer kalkýþ yeri : " << seferler[no].kyeri << endl;
			cout << i << ". sefer kalkýþ saati : " << seferler[no].ksaati << endl;
			cout << i << ". sefer varýþ yeri : " << seferler[no].vyeri << endl;
			cout << i << ". sefer varýþ saati : " << seferler[no].vsaati << endl;
			cout << i << ". sefer otobüs numarasý : " << seferler[no].o_no << endl;
			cout << i << ". sefer kaptanlarý : " << seferler[no].kaptan << endl;
			cout << "\n\n";
		}
	cout << "Arama iþlemine devam etmek istiyor musunuz(e/E)? " ;
	cin >> secim;
	}while(secim=='e' || secim=='E');
}

// þoför giriþi için kullanýlan fonksiyondur
void soforgiris()
{
	int numara;
	cout << "Firma þoför sayýsýný giriniz: ";
	cin >> numara;
	cin.ignore();
	cout << "Ýsim soyisim giriniz: " ;
	getline(cin,soforler[numara+1].ad_soyad);
	cout << "Tc kimlik no giriniz: ";
	cin >> soforler[numara+1].tc;
	cout << "Yaþ giriniz: ";
	cin >> soforler[numara+1].yas;
	cout << "Deneyim yýlýný giriniz: ";
	cin >> soforler[numara+1].deneyimyili;
}

// þoför listelemek için kullanýlan fonksiyondur
void soforlistesi()
{
	for (int i=1;i<max;i++)
	{
		if(soforler[i].ad_soyad == "") continue;
		cout << "Þoför " << i << " Bilgileri:" << endl;
        cout << "Ýsim Soyisim: " << soforler[i].ad_soyad << endl;
        cout << "TC Kimlik No: " << soforler[i].tc << endl;
        cout << "Yaþ: " << soforler[i].yas << endl;
        cout << "Deneyim Yýlý: " << soforler[i].deneyimyili << endl;
        cout << endl;
	}
}

// þoför silmek için kullanýlan fonksiyondur
void soforsil()
{
	int no;
	char secim;
	do
	{
	cout << "Silmek istediðiniz þoför numarasýný giriniz: ";
	cin >> no;
	if(no<0 || no>100 || soforler[no].ad_soyad=="")
	{
		cout << "Silinecek þoför bulunamadý." << endl;
	}
	else
	{
		soforler[no].ad_soyad="";
		soforler[no].tc=0;
		soforler[no].yas=0;
		soforler[no].deneyimyili=0;
		cout << "Þoför numarasý " << no << " olan þoför baþarýyla silindi." << endl;
		cout << "\n\n";
	}
	cout << "Silme iþlemine devam etmek istiyor musunuz(e/h)? " ;
	cin >> secim;

	}while(secim=='e' || secim=='E');

}

// Sefer bilgilerini ve güncellemelerini dosyaya kaydetmek için kullanýlan fonksiyondur
void kayitSeferBilgileri()
{
    ofstream dosya("seferbilgileri.dat",ios::binary);
    for (int i = 0; i < max; i++)
	{
        int kyeriuzunluk=seferler[i].kyeri.size();
        dosya.write(reinterpret_cast<char*>(&kyeriuzunluk), sizeof(kyeriuzunluk));
        for (int j = 0; j < kyeriuzunluk; j++)
			{
            char c = seferler[i].kyeri[j];
            dosya.write(&c, sizeof(char));
    		}
        int vyeriuzunluk = seferler[i].vyeri.size();
        dosya.write(reinterpret_cast<char*>(&vyeriuzunluk), sizeof(vyeriuzunluk));
        for (int j = 0; j < vyeriuzunluk; j++)
			{
            char c = seferler[i].vyeri[j];
            dosya.write(&c, sizeof(char));
        	}
        dosya.write(reinterpret_cast<char*>(&seferler[i].ksaati), sizeof(seferler[i].ksaati));
        dosya.write(reinterpret_cast<char*>(&seferler[i].vsaati), sizeof(seferler[i].vsaati));

        int kaptanuzunluk = seferler[i].kaptan.size();
        dosya.write(reinterpret_cast<char*>(&kaptanuzunluk), sizeof(kaptanuzunluk));
        for (int j = 0; j < kaptanuzunluk; j++)
		{
            char c = seferler[i].kaptan[j];
            dosya.write(&c, sizeof(char));
        }
        dosya.write(reinterpret_cast<char*>(&seferler[i].o_no), sizeof(seferler[i].o_no));
    }

    cout << "Sefer bilgileri dosyaya kaydedildi!" << std::endl;
    dosya.close();
}

// Þoför bilgilerini ve güncellemelerini dosyaya kaydetmek için kullanýlan fonksiyondur
void kayitSoforBilgileri()
{
    ofstream dosya("soforbilgileri.dat",ios::binary);
    for (int i = 0; i < max; i++)
	{
        int adSoyaduzun = soforler[i].ad_soyad.size();
        dosya.write(reinterpret_cast<char*>(&adSoyaduzun), sizeof(adSoyaduzun));
        for (int j = 0; j < adSoyaduzun; j++)
		{
            char c = soforler[i].ad_soyad[j];
            dosya.write(&c, sizeof(char));
        }

        dosya.write(reinterpret_cast<char*>(&soforler[i].tc), sizeof(soforler[i].tc));

        dosya.write(reinterpret_cast<char*>(&soforler[i].yas), sizeof(soforler[i].yas));

        dosya.write(reinterpret_cast<char*>(&soforler[i].deneyimyili), sizeof(soforler[i].deneyimyili));
    }

    cout << "Sofor bilgileri dosyaya kaydedildi!" << endl;
    dosya.close();
}

// Program tekrar açýldýðýnda sefer dosyasýnda ki bilgilerin geri gelmesini saðlayan fonksiyondur
void yukleSeferBilgileri()
{
    ifstream dosya("seferbilgileri.dat",ios::binary );
    if (!dosya) return;

    for (int i=0;i<max;i++)
	{
        if (dosya.eof()) break;
        int kyeriuznluk = 0;

        dosya.read(reinterpret_cast<char*>(&kyeriuznluk), sizeof(kyeriuznluk));
        seferler[i].kyeri = "";
        for (int j=0;j<kyeriuznluk;j++)
		{
            char c;
            dosya.read(&c, sizeof(char));
            if (dosya.eof()) break;
            seferler[i].kyeri += c;
        }

        int vyeriuznluk=0;
        dosya.read(reinterpret_cast<char*>(&vyeriuznluk), sizeof(vyeriuznluk));
        seferler[i].vyeri = "";
        for (int j=0;j<vyeriuznluk;j++)
		{
            char c;
            dosya.read(&c, sizeof(char));
            if (dosya.eof()) break;
            seferler[i].vyeri += c;
        }

        dosya.read(reinterpret_cast<char*>(&seferler[i].ksaati), sizeof(seferler[i].ksaati));

        dosya.read(reinterpret_cast<char*>(&seferler[i].vsaati), sizeof(seferler[i].vsaati));

        int kaptanuznluk=0;
        dosya.read(reinterpret_cast<char*>(&kaptanuznluk), sizeof(kaptanuznluk));
        seferler[i].kaptan = "";
        for (int j=0;j<kaptanuznluk;j++)
		{
            char c;
            dosya.read(&c, sizeof(char));
            if (dosya.eof()) break;
            seferler[i].kaptan += c;
        }

        dosya.read(reinterpret_cast<char*>(&seferler[i].o_no), sizeof(seferler[i].o_no));

        if (dosya.eof()) break;
    }

    dosya.close();
    cout << "Sefer bilgileri dosyadan yüklendi!" << endl;
}

// Program tekrar açýldýðýnda þoför dosyasýnda ki bilgilerin geri gelmesini saðlayan fonksiyondur
void yukleSoforBilgileri()
{
    ifstream dosya("soforbilgileri.dat", ios::binary);
    if (!dosya) return;

    for (int i= 0;i<max;i++)
	{
        if (dosya.eof()) break;

        int adSoyaduznluk =0;
        dosya.read(reinterpret_cast<char*>(&adSoyaduznluk), sizeof(adSoyaduznluk));
        soforler[i].ad_soyad = "";
        for (int j=0;j<adSoyaduznluk;j++)
		{
            char c;
            dosya.read(&c, sizeof(char));
            if (dosya.eof()) break;
            soforler[i].ad_soyad += c;
        }
        dosya.read(reinterpret_cast<char*>(&soforler[i].tc), sizeof(soforler[i].tc));

        dosya.read(reinterpret_cast<char*>(&soforler[i].yas), sizeof(soforler[i].yas));

        dosya.read(reinterpret_cast<char*>(&soforler[i].deneyimyili), sizeof(soforler[i].deneyimyili));

        if (dosya.eof()) break;
    }

    dosya.close();
    cout << "Sofor bilgileri dosyadan yüklendi!" <<endl;
}



