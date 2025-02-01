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
		cout << "                                       |----------�SUBU TUR�ZM-----------|" << endl;
		cout << "                                       |--------1 Sefer giri�i-----------|" << endl;
		cout << "                                       |--------2 Sefer listesi----------|" << endl;
		cout << "                                       |--------3 Sefer d�zenle----------|" << endl;
		cout << "                                       |--------4 Sefer sil--------------|" << endl;
		cout << "                                       |--------5 Sefer ara--------------|" << endl;
		cout << "                                       |---6 Firma otob�s �ofor� giri�i--|" << endl;
		cout << "                                       |---7 Firma �of�rler listesi------|" << endl;
		cout << "                                       |--------8 �of�r sil--------------|" << endl;
		cout << "Se�im yap�n�z: ";
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
			cout << "Ge�ersiz se�im!" << endl;
		}
		cout << "Ana men�ye d�nmek ister misiniz(e/h)? " ;
		cin >> menu;

		kayitSeferBilgileri();
        kayitSoforBilgileri();
	}
	while(menu=='e' || menu=='E');
	return 0;

}
// sefer giri�i yapmak i�in kullan�lan fonksiyondur
void sefergir()
{
	char cvp;
	do
	{
	int seferno;
	cout << "Sefer numaras�n� giriniz(1/100): ";
	cin >> seferno;
	if(seferler[seferno].kyeri=="")
	{
	cout << "Kalk�� yeri: ";
	cin >> seferler[seferno].kyeri;
	cout << "Kalk�� saati: ";
	cin >> seferler[seferno].ksaati;
	cout << "Var�� yeri: ";
	cin >> seferler[seferno].vyeri;
	cout << "Var�� saati: ";
	cin >> seferler[seferno].vsaati;
	cout << "Seferi yapacak olan otob�s numaras�: ";
	cin >> seferler[seferno].o_no;
	cin.ignore();
	cout << "Sefer kaptanlar�: ";
	getline(cin,seferler[seferno].kaptan);
	}
	else
	cout << "Eklemek istedi�iniz sefer numaras�na �nceden tan�mlanan sefer vard�r. " << endl;
	cout << "Sefer eklemeye devam etmek ister misiniz(e/h)?" << endl;
	cin >> cvp;

	}while(cvp=='e' || cvp=='E');
}

// sefer listelemek i�in kullan�lan fonksiyondur
void seferlistesi()
{
	for(int i=0;i<max;i++)
	{
		if(seferler[i].kyeri == "") continue;
		cout << i << ". sefer kalk�� yeri : " << seferler[i].kyeri << endl;
		cout << i << ". sefer kalk�� saati : " << seferler[i].ksaati << endl;
		cout << i << ". sefer var�� yeri : " << seferler[i].vyeri << endl;
		cout << i << ". sefer var�� saati : " << seferler[i].vsaati << endl;
		cout << i << ". sefer otob�s numaras� : " << seferler[i].o_no << endl;
		cout << i << ". sefer kaptanlar� : " << seferler[i].kaptan << endl;
		cout << "\n\n";
	}
}

// sefer d�zenlemek i�in kullan�lan fonksiyondur
void seferduzenle()
{
	int no;
	cout << "D�zenlemek istedi�iniz sefer numarasini giriniz: ";
	cin >> no;
	if(seferler[no].kyeri=="")
	{
		cout << "D�zenlemek istedi�iniz sefer bulunamam��t�r. " << endl;
	}
	else
	{
	cout << "\nSefer d�zenlemesi yap�n�z" << endl;
	cout << "Kalk�� yeri: ";
	cin >> seferler[no].kyeri;
	cout << "Kalk�� saati: ";
	cin >> seferler[no].ksaati;
	cout << "Var�� yeri: ";
	cin >> seferler[no].vyeri;
	cout << "Var�� saati: ";
	cin >> seferler[no].vsaati;
	cout << "Seferi yapacak olan otob�s numaras�: ";
	cin >> seferler[no].o_no;
	cin.ignore();
	cout << "Sefer kaptanlar�: ";
	getline(cin,seferler[no].kaptan);
	}
}

//sefer silmek i�in kullan�lan fonksiyondur
void sefersil()
{
	int no;
	char secim;
	do
	{
	cout << "Silmek istedi�iniz sefer numaras�n� giriniz: ";
	cin >> no;
	if(no<0 || no>100 || seferler[no].kyeri=="")
	{
		cout << "Silinecek sefer bulunamad�." << endl;
	}
	else
	{
		seferler[no].kyeri="";
		seferler[no].ksaati=0.0f;
		seferler[no].vyeri="";
		seferler[no].vsaati=0.0f;
		seferler[no].o_no=0;
		seferler[no].kaptan="";
		cout << "Sefer numaras� " << no << " olan sefer ba�ar�yla silindi." << endl;
		cout << "\n\n";
	}
	cout << "Silme i�lemine devam etmek istiyor musunuz(e/h)? " ;
	cin >> secim;

	}while(secim=='e' || secim=='E');
}

// sefer aramak i�in kullan�lan fonksiyondur
void seferara()
{
	int no;
	char secim;
	do
	{
	cout << "Aramak istedi�iniz sefer numaras�n� giriniz: ";
	cin >> no;
	if(no>=100 || seferler[no].kyeri=="")
	{
		cout << "Arad���n�z sefer bulunamam��t�r,l�tfen ge�erli bir say� giriniz." << endl;
	}
	else
		for(int i=no;i<no+1;i++)
		{
			cout << i << ". sefer kalk�� yeri : " << seferler[no].kyeri << endl;
			cout << i << ". sefer kalk�� saati : " << seferler[no].ksaati << endl;
			cout << i << ". sefer var�� yeri : " << seferler[no].vyeri << endl;
			cout << i << ". sefer var�� saati : " << seferler[no].vsaati << endl;
			cout << i << ". sefer otob�s numaras� : " << seferler[no].o_no << endl;
			cout << i << ". sefer kaptanlar� : " << seferler[no].kaptan << endl;
			cout << "\n\n";
		}
	cout << "Arama i�lemine devam etmek istiyor musunuz(e/E)? " ;
	cin >> secim;
	}while(secim=='e' || secim=='E');
}

// �of�r giri�i i�in kullan�lan fonksiyondur
void soforgiris()
{
	int numara;
	cout << "Firma �of�r say�s�n� giriniz: ";
	cin >> numara;
	cin.ignore();
	cout << "�sim soyisim giriniz: " ;
	getline(cin,soforler[numara+1].ad_soyad);
	cout << "Tc kimlik no giriniz: ";
	cin >> soforler[numara+1].tc;
	cout << "Ya� giriniz: ";
	cin >> soforler[numara+1].yas;
	cout << "Deneyim y�l�n� giriniz: ";
	cin >> soforler[numara+1].deneyimyili;
}

// �of�r listelemek i�in kullan�lan fonksiyondur
void soforlistesi()
{
	for (int i=1;i<max;i++)
	{
		if(soforler[i].ad_soyad == "") continue;
		cout << "�of�r " << i << " Bilgileri:" << endl;
        cout << "�sim Soyisim: " << soforler[i].ad_soyad << endl;
        cout << "TC Kimlik No: " << soforler[i].tc << endl;
        cout << "Ya�: " << soforler[i].yas << endl;
        cout << "Deneyim Y�l�: " << soforler[i].deneyimyili << endl;
        cout << endl;
	}
}

// �of�r silmek i�in kullan�lan fonksiyondur
void soforsil()
{
	int no;
	char secim;
	do
	{
	cout << "Silmek istedi�iniz �of�r numaras�n� giriniz: ";
	cin >> no;
	if(no<0 || no>100 || soforler[no].ad_soyad=="")
	{
		cout << "Silinecek �of�r bulunamad�." << endl;
	}
	else
	{
		soforler[no].ad_soyad="";
		soforler[no].tc=0;
		soforler[no].yas=0;
		soforler[no].deneyimyili=0;
		cout << "�of�r numaras� " << no << " olan �of�r ba�ar�yla silindi." << endl;
		cout << "\n\n";
	}
	cout << "Silme i�lemine devam etmek istiyor musunuz(e/h)? " ;
	cin >> secim;

	}while(secim=='e' || secim=='E');

}

// Sefer bilgilerini ve g�ncellemelerini dosyaya kaydetmek i�in kullan�lan fonksiyondur
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

// �of�r bilgilerini ve g�ncellemelerini dosyaya kaydetmek i�in kullan�lan fonksiyondur
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

// Program tekrar a��ld���nda sefer dosyas�nda ki bilgilerin geri gelmesini sa�layan fonksiyondur
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
    cout << "Sefer bilgileri dosyadan y�klendi!" << endl;
}

// Program tekrar a��ld���nda �of�r dosyas�nda ki bilgilerin geri gelmesini sa�layan fonksiyondur
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
    cout << "Sofor bilgileri dosyadan y�klendi!" <<endl;
}



