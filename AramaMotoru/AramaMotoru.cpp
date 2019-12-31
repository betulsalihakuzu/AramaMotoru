// AramaMotoruProje.cpp : Defines the entry point for the console application.
//


#include  <iostream>		//Dosya İşlemleri kütüphane
#include  <fstream>			//Dosya İşlemleri kütüphane
#include <string>			//String işlemleri için kütüphane
#include <time.h>			//Zaman Tutmamız İçin kütüphane
#include <windows.h>	    //İşlem Sonucunun Direk Ekrana Gelmesi Txt dosyası olarak açılması için.
using namespace std;



//Word Dosyasında Arama İşlemi
void wordArama(string dosya, string aranan) {
	int sayac = 0;
	string str, satir;

	clock_t baslangic, bitis;

	ifstream file(dosya);
	if (file.is_open()) {
		while (!file.eof())
		{
			getline(file, satir);
			str += satir;
		}
		file.close();
	}
	else {
		system("color 4F"); cout << "Word dosyasi acilamadi." << endl;
		return;
	}


	bool buldu_mu = false;

	ofstream sonuc("wordsonuc.txt", ios::out);

	sonuc << "Word dosyasının arama sonucu" << endl << endl;

	baslangic = clock();


	//BRUD FORCE TAM EŞLEME ALGORİTMASI
	for (int i = 0; i <= str.length() - aranan.length(); i++) //Text ve pattern boyutunun farkı kadar dön
	{
		int j = 0;

		while (j < aranan.length() && aranan[j] == str[i + j]) //Harfler eşitse
		{
			j++;
		}
		if (j == aranan.length()) //Karşılaştırma sayısı pattern boyutuna eşitse eşleşme vardır
		{
			sayac++;
			buldu_mu = true;
			sonuc << aranan << " Kelimesi " << i << ".indiste bulundu" << endl;

		}
	}
	//BRUD FORCE TAM EŞLEME ALGORİTMASI


	bitis = clock();

	float sure = (((float)bitis - baslangic) / CLOCKS_PER_SEC);
	cout << endl;
	cout << "                Word dosyasinda " << sayac << " adet sonuc " << sure << " saniyede bulundu." << endl;

	if (!buldu_mu)
		system("color 4F"); sonuc << "Sonuc bulunamadı." << endl;

	sonuc.close();

	system("notepad wordsonuc.txt");

}



//Txt Dosyasında Arama İşlemi
void txtArama(string dosya, string pattern)    //dosya = "osmanlitarihi.txt"   //pattern=aranan kelime
{


	int sayac = 0;        /////////Kelimeyi kaç kez bulduğunu sayıyor.
	string str, satir;

	clock_t baslangic, bitis;  /////////İşlem süresi için başlangıç bitiş değişken tanımlaması

	ifstream file(dosya);      /////////Mainden gönderilen dosya yoluna göre ÖRN: "osmanlitarihi.txt" 

	if (file.is_open()) {   //dosya açıldımı kontrolü
		while (!file.eof())  //dosyanın okunması
		{
			getline(file, satir);
			str += satir;
		}
		file.close();
	}
	else {
		system("color 4F"); cout << endl << "Text dosyasi acilamadi." << endl;
		return;
	}



	ofstream sonuc("txtsonuc.txt", ios::out);

	sonuc << "Text dosyasının arama sonucu :" << endl << endl;

	baslangic = clock();  //işlem öncesi süre başlangıçı.


	//BRUD FORCE TAM EŞLEME ALGORİTMASI

	bool buldu_mu = false;
	for (int i = 0; i <= str.length() - pattern.length(); i++) //Text ve aranan boyutunun farkı kadar dön
	{
		int j = 0;

		while (j < pattern.length() && pattern[j] == str[i + j]) //Harfler eşitse
		{
			j++;
		}
		if (j == pattern.length()) //Karşılaştırma sayısı aranan boyutuna eşitse eşleşme vardır
		{
			sayac++;
			buldu_mu = true;
			sonuc << pattern << " Kelimesi " << i << ".indiste bulundu" << endl;  //bulduğu sırada indis de yazdırma
		}
	}

	//BRUD FORCE TAM EŞLEME ALGORİTMASI



	bitis = clock();   //işlemden hemen sonra süre tutumu

	float sure = (((float)bitis - baslangic) / CLOCKS_PER_SEC);				 //işlem  sonucundaki geçen süre hesaplaması

	cout << endl;
	cout << "                Text dosyasinda " << sayac << " adet sonuc " << sure << " saniyede bulundu." << endl;

	if (!buldu_mu)
		system("color 4F"); sonuc << "Sonuc bulunamadı." << endl;

	sonuc.close();

	system("notepad txtsonuc.txt");  //istenilen kriter olan sonuçları arama bittikten hemen sonra bizim belirliceğimiz bir belgenin sonuçları içinde yazılcak şekilde 
																		//ekrana otomatik olarak gelmesini sağlayan kod

}



//Pdf Dosyasında Arama İşlemi
void pdfArama(string dosya, string aranan) {
	int sayac = 0;
	string str, satir;

	clock_t baslangic, bitis;

	ifstream file(dosya);
	if (file.is_open()) {
		while (!file.eof())
		{
			getline(file, satir);
			str += satir;
		}
		file.close();
	}
	else {
		system("color 4F"); cout << "PDF dosyasi acilamadi." << endl;
		return;
	}


	bool buldu_mu = false;

	ofstream sonuc("pdfsonuc.txt", ios::out);

	sonuc << "PDF dosyasının arama sonucu" << endl << endl;

	baslangic = clock();



	//BRUD FORCE TAM EŞLEME ALGORİTMASI
	for (int i = 0; i <= str.length() - aranan.length(); i++) //Text ve pattern boyutunun farkı kadar dön
	{
		int j = 0;

		while (j < aranan.length() && aranan[j] == str[i + j]) //Harfler eşitse
		{
			j++;
		}
		if (j == aranan.length()) //Karşılaştırma sayısı pattern boyutuna eşitse eşleşme vardır
		{
			sayac++;
			buldu_mu = true;
			sonuc << aranan << " Kelimesi " << i << ".indiste bulundu" << endl;

		}
	}
	//BRUD FORCE TAM EŞLEME ALGORİTMASI



	bitis = clock();

	float sure = (((float)bitis - baslangic) / CLOCKS_PER_SEC);

	cout << endl;
	cout << "                PDF dosyasinda " << sayac << " adet sonuc " << sure << " saniyede bulundu." << endl;

	if (!buldu_mu)
		system("color 4F"); sonuc << "Sonuc bulunamadı." << endl;

	sonuc.close();


	system("notepad pdfsonuc.txt");

}


//Html Dosyasında Arama İşlemi
void htmlArama(string dosya, string aranan) {
	int sayac = 0;
	string str, satir;

	clock_t baslangic, bitis;

	ifstream file(dosya);
	if (file.is_open()) {
		while (!file.eof())
		{
			getline(file, satir);
			str += satir;
		}
		file.close();
	}
	else {
		system("color 4F"); cout << "HTML dosyasi acilamadi." << endl;
		return;
	}

	bool buldu_mu = false;

	ofstream sonuc("htmlsonuc.txt", ios::out);

	sonuc << "HTML dosyasının arama sonucu" << endl << endl;

	baslangic = clock();



	//BRUD FORCE TAM EŞLEME ALGORİTMASI
	for (int i = 0; i <= str.length() - aranan.length(); i++) //Text ve pattern boyutunun farkı kadar dön
	{
		int j = 0;

		while (j < aranan.length() && aranan[j] == str[i + j]) //Harfler eşitse
		{
			j++;
		}
		if (j == aranan.length()) //Karşılaştırma sayısı pattern boyutuna eşitse eşleşme vardır
		{
			sayac++;
			buldu_mu = true;
			sonuc << aranan << " Kelimesi " << i << ".indiste bulundu" << endl;
		}
	}
	//BRUD FORCE TAM EŞLEME ALGORİTMASI


	bitis = clock();

	float sure = (((float)bitis - baslangic) / CLOCKS_PER_SEC);

	cout << endl;
	cout << "                HTML dosyasinda " << sayac << " adet sonuc " << sure << " saniyede bulundu." << endl;

	if (!buldu_mu)
		system("color 4F"); sonuc << "Sonuc bulunamadı." << endl;

	sonuc.close();

	system("notepad htmlsonuc.txt");

}



int main()

{


	system("color 5E");							//////////Konsol ekranı rengini belirler
	system("MODE CON:COLS=95 LINES=30");		////////////////Konsol ekranı boyutunu ayarlar
	setlocale(LC_ALL, "Turkish");				//////////Türkçe Karakter Kullanmayı sağlar
	SetConsoleTitle(TEXT("                                                                                                 Arama Motoru"));		 //////////////////Konsol başlığı/////////////////
	system("cls");								///////////////Konsol ekranını temizler////////////

	string secim;   //MENÜ SEÇİMİNE GÖRE ATANACAK DEĞİŞKEN

	cout << "Veri Yapıları Arama Motoru Proje Ödevi|" << endl;
	cout << "---------------------------------------" << endl;
	cout << "172114009 Betül Saliha KUZU (vy21)    |" << endl;
	cout << "172114015 Derya USTA (vy21)           |" << endl;
	cout << "172114208 Seda DEMİR (vy21)           |" << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;


	//MENÜ
	//MENÜ
	//MENÜ
	cout << "\t		--------------------------------------------\n";
	cout << "\t		||||||  Arama Motorumuza Hoşgeldiniz  ||||||\n";
	cout << "\t		--------------------------------------------\n\n";
	cout << "			--------------------------------------------\n";
	cout << "			|1.Tüm Dosyalar  İçinde Arama İşlemi       |\n";
	cout << "			--------------------------------------------\n";
	cout << "			|2.Word Belgesi (docx)  İçinde Arama İşlemi|\n";
	cout << "			--------------------------------------------\n";
	cout << "			|3.Metin Belgesi (txt) İçinde Arama İşlemi |\n";
	cout << "			--------------------------------------------\n";
	cout << "			|4.Pdf Belgesi İçinde Arama İşlemi         |\n";
	cout << "			--------------------------------------------\n";
	cout << "			|5.Html İçinde Arama İşlemi		   |\n";
	cout << "			--------------------------------------------\n";
	cout << "			|6.Programı Kapat                          |\n";
	cout << "			--------------------------------------------\n\n";
	cout << "			Arama işleminin yapılacağı belge numarasını giriniz :";
	getline(cin, secim);  //boşluklu arama yapabilmek için

	string aranan;   //Aranacak kelimenin string tanımlaması
	cout << endl;



	//Tüm Dosyalar
	if (secim == "1")   
	{
		cout << "	        ***Tüm Dosyalar  İçinde Arama İşlemine Aktaralıyorsunuz... ***" << endl;

		Sleep(1000);				////Programı belirtilen süre boyunca bekletir
		system("cls");				////Konsol ekranını temizler
		system("color B1");		    ////Konsol Ekranı Renk değiştirme


		cout << "	---------------------------------------------------------------------------\n";
		cout << " \t\t\t      Tüm Dosyalar İçinde Arama İşlemi \n";
		cout << "	---------------------------------------------------------------------------\n";
		cout << endl;



		//Aranacak kelimenin kullanıcıdan istenmesi ve arancak belgeye göre fonksiyon göndermesi

		cout << "        Aranacak Kelimeyi Giriniz :";
		getline(cin, aranan);   //boşluklu şekilde arama yapabilmek için
		aranan = " " + aranan + " ";  //aradığımız kelime bir kelimenin içinde geçiyorsa sonuç olarak gelmesini engeller. ÖRN lorem >> dolorem 
		cout << endl << "	---------------------------------------------------------------------------\n";
		
		wordArama("bildiriozetlerimakale.docx", aranan); //Aranacak belgenin yol bilgisinin fonksiyona gönderilmesi
		txtArama("osmanlitarihi.txt", aranan);               
		pdfArama("uluslararasidilsempozyum.pdf", aranan);
		htmlArama("din.html", aranan);

		//Aranacak kelimenin kullanıcıdan istenmesi ve arancak belgeye göre fonksiyon göndermesi

		cout << endl << "	---------------------------------------------------------------------------\n";
		cout << endl;
		cout << endl;
		system("pause");


	}

	else if (secim == "2")
	{


		cout << "	    *** Word Belgesi (docx)  İçinde Arama İşlemine Aktaralıyorsunuz... ***" << endl;

		Sleep(1000);              //////////Programı belirtilen süre boyunca bekletir
		system("cls");           ////////Konsol ekranını temizler
		system("color B1");      ///////Konsol ekranının rengini belirler
		cout << "	---------------------------------------------------------------------------\n";
		cout << " \t\t\t      Word Belgesi İçinde Arama İşlemi \n";
		cout << "	---------------------------------------------------------------------------\n";
		cout << endl;

		//Aranacak kelimenin kullanıcıdan istenmesi ve arancak belgeye göre fonksiyon göndermesi


		cout << "        Aranacak Kelimeyi Giriniz :";
		getline(cin, aranan);   //boşluklu şekilde aramaya yarar
		aranan = " " + aranan + " ";  //aradığımız kelime bir kelimenin içinde geçiyorsa sonuç olarak gelmesini engeller. ÖRN lorem >> dolorem 
		cout << endl << "	---------------------------------------------------------------------------\n";
		//Aranacak belgenin yol bilgisinin fonksiyona gönderilmesi
		wordArama("bildiriozetlerimakale.docx", aranan);


		//Aranacak kelimenin kullanıcan istenmesi ve arancak belgeye göre fonksiyon göndermesi

		cout << endl << "	---------------------------------------------------------------------------\n";
		cout << endl;
		cout << endl;
		system("pause");

	}

	else if (secim == "3")
	{

		cout << "	   ***    Metin Belgesi (txt)  İçinde Arama İşlemine Aktaralıyorsunuz...     ***" << endl;
		Sleep(1000);//////////////////Programı belirtilen süre boyunca bekletir///////////////////
		system("cls");////////////////Konsol ekranını temizler////////////
		system("color B1");
		cout << "	---------------------------------------------------------------------------\n";
		cout << " \t\t\t      Metin Belgesi İçinde Arama İşlemi \n";
		cout << "	---------------------------------------------------------------------------\n";
		cout << endl;

		//Aranacak kelimenin kullanıcan istenmesi ve arancak belgeye göre fonksiyon göndermesi

		cout << "        Aranacak Kelimeyi Giriniz :";
		getline(cin, aranan);   //boşluklu şekilde aramaya yarar
		aranan = " " + aranan + " ";  //aradığımız kelime bir kelimenin içinde geçiyorsa sonuç olarak gelmesini engeller. ÖRN lorem >> dolorem 
		cout << endl << "	---------------------------------------------------------------------------\n";
		txtArama("osmanlitarihi.txt", aranan);                  //Aranacak belgenin yol bilgisinin fonksiyona gönderilmesi




		//Aranacak kelimenin kullanıcan istenmesi ve arancak belgeye göre fonksiyon göndermesi

		cout << endl << "	---------------------------------------------------------------------------\n";
		cout << endl;
		cout << endl;
		system("pause");

	}

	else if (secim == "4")
	{
		cout << "	        ***     Pdf  İçinde Arama İşlemine Aktaralıyorsunuz...    ***" << endl;
		Sleep(1000);              ////////Programı belirtilen süre boyunca bekletir
		system("cls");            ////////Konsol ekranını temizler
		system("color B1");       ////////Konsol rengini belirler
		cout << "	---------------------------------------------------------------------------\n";
		cout << " \t\t\t      Pdf Belgesi İçinde Arama İşlemi \n";
		cout << "	---------------------------------------------------------------------------\n";
		cout << endl;

		//Aranacak kelimenin kullanıcan istenmesi ve arancak belgeye göre fonksiyon göndermesi

		cout << "        Aranacak Kelimeyi Giriniz :";
		getline(cin, aranan);   //boşluklu şekilde aramaya yarar
		aranan = " " + aranan + " ";  //aradığımız kelime bir kelimenin içinde geçiyorsa sonuç olarak gelmesini engeller. ÖRN lorem >> dolorem 
		cout << endl << "	---------------------------------------------------------------------------\n";
		//Aranacak belgenin yol bilgisinin fonksiyona gönderilmesi

		pdfArama("uluslararasidilsempozyum.pdf", aranan);


		//Aranacak kelimenin kullanıcan istenmesi ve arancak belgeye göre fonksiyon göndermesi

		cout << endl << "	---------------------------------------------------------------------------\n";
		cout << endl;
		cout << endl;
		system("pause");


	}

	else if (secim == "5")
	{
		cout << "	         ***    Html  İçinde Arama İşlemine Aktaralıyorsunuz...     ***" << endl;
		Sleep(1000); //////////////////Programı belirtilen süre boyunca bekletir///////////////////
		system("cls");////////////////Konsol ekranını temizler////////////

		system("color B1");
		cout << "	---------------------------------------------------------------------------\n";
		cout << " \t\t\t           Html İçinde Arama İşlemi \n";
		cout << "	---------------------------------------------------------------------------\n";
		cout << endl;


		//Aranacak kelimenin kullanıcan istenmesi ve arancak belgeye göre fonksiyon göndermesi


		cout << "        Aranacak Kelimeyi Giriniz :";
		getline(cin, aranan);   ////////boşluklu şekilde aramaya yarar
		aranan = " " + aranan + " ";  //aradığımız kelime bir kelimenin içinde geçiyorsa sonuç olarak gelmesini engeller. ÖRN lorem >> dolorem 
		cout << endl << "	---------------------------------------------------------------------------\n";

		//Aranacak belgenin yol bilgisinin fonksiyona gönderilmesi

		htmlArama("din.html", aranan);

		//Aranacak kelimenin kullanıcan istenmesi ve arancak belgeye göre fonksiyon göndermesi

		cout << endl << "	---------------------------------------------------------------------------\n";
		cout << endl;
		cout << endl;
		system("pause");


	}
	else
	{

		system("color 1E");
		cout << endl;
		cout << "			--------------------------------------------------\n";
		cout << "			***     Program Kapatılıyor iyi günler :)     ***" << endl;
		cout << "			--------------------------------------------------\n";
		Sleep(3000);         //////////Programı belirtilen süre boyunca bekletir
		exit(1);


	}

	main();	 //Consol ekranının işlemler sonucunda tekrar ana ekrana dönmesini sağlar.
	return 0;
}


