/****************************************************************************************
**
**
**                       SAKARYA ÜNÝVERSÝTESÝ                                 
**              BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ                    
**                   BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ                          
**                      PROGRAMLAMAYA GÝRÝÞ DERSÝ                             
**                                                                       
**           ÖDEV NUMARASI    : 1                                     
**           ÖÐRENCÝ ADI      : Özgür Demir                         
**           ÖÐRENCÝ NUMARASI : b221210017                       
**           DERS GRUBU       : C                                     
**  
**                                                                      
*****************************************************************************************/


#include <iostream>
#include <locale.h>
#include <math.h>
#include <ctime>

using namespace std;

struct ogrenciler
{
    string isim;
    string soyad;
    float quiz1 = 0, quiz2 = 0;
    float odev1 = 0, odev2 = 0;
    float vize = 0, final = 0;
    float finalNot = 0;
};

// 6 farklý notu yüzdesel aralýklarýna göre rastgele oluþturan fonksiyon
int rastgeleNotlar();


int main()
{
    setlocale(LC_ALL, "Turkish");
    srand(time(0));

    string studentNameS[50] = {
        "Ali", "Aylin", "Baran", "Begum", "Can", "Ceren", "Deniz", "Duru", "Emir", "Ece",
        "Furkan", "Fatma", "Gizem", "Gokhan", "Hande", "Hakan", "Irem", "Ismail", "Jale", "Janset",
        "Kaan", "Kader", "Levent", "Lale", "Mehmet", "Merve", "Nur", "Naz", "Ozan", "Oya",
        "Pelin", "Poyraz", "Rabia", "Recep", "Selin", "Sarp", "Tugba", "Tolga", "Ufuk", "Umay",
        "Volkan", "Vildan", "Yasin", "Yagmur", "Zeynep", "Zeki", "Cemre", "Cihan", "Cansu", "Burak"
    };
    string studentSurnameS[50] = {
        "Yilmaz", "Demir", "Kaya", "Cetin", "Arslan", "Yildirim", "Koc", "Sahin", "Ozdemir", "Celik",
        "Kara", "Ucar", "Kilic", "Cinar", "Aksoy", "Yildiz", "Tas", "Aslan", "Ozturk", "Kaplan",
        "Karaca", "Cakir", "Bulut", "Erdogan", "Sahin", "Guler", "Kocak", "Yaman", "Erdem", "Aydin",
        "Gul", "Polat", "Avci", "Uzun", "Ozkan", "Kurt", "Eren", "Turan", "Yalcin", "Akin",
        "Cebeci", "Aydos", "Aydin", "Taylan", "Bilgin", "Dogru", "Kilic", "Kara", "Kocak", "Sari"
    };


    int ogrenciSayisi;
    while (true)               //**** Öðrenci sayýsýný alan döngü ****//
    {
        cout << "Öðrenci sayýsýný giriniz (max 50 öðrenci): \n";
        cin >> ogrenciSayisi;
        if (ogrenciSayisi > 0)
            break;                              
        else
            cout << "Hatalý öðrenci sayýsý giriþi, lütfen tekrar deneyiniz.\n";
    }
    
    float quizNotAgirligi = 0, odevNotAgirligi = 0, vizeNotAgirligi = 0, finalNotAgirligi = 0, yilIciNotlarinagirligi = 0;

    while (true)   //**** Sýnavlarýn not aðýrlýklarýný alan döngü ****//
    {
        while (true)
        {
            cout << "Kýsa sýnavlarýn(toplam 2 adet) not yüzdesine etkisini giriniz (1-100): \n";
            cin >> quizNotAgirligi;
            if (quizNotAgirligi > 100 || quizNotAgirligi < 0)
            {
                cout << "Hatalý tuþlama tekrar deneyiniz.\n";
            }
            else
                break;
        }
 
        while (true)
        {
            cout << "Ödev notlarýnýn(toplam 2 adet) not yüzdesine etkisini giriniz (1-100): \n";
            cin >> odevNotAgirligi;
            if (odevNotAgirligi > 100 || odevNotAgirligi < 0)
            {
                cout << "Hatalý tuþlama tekrar deneyiniz.\n";
            }
            else
                break;
        }


        if (quizNotAgirligi + odevNotAgirligi > 100)
        {
            cout << "\'Quiz Not Aðýrlýðý\' ve \'Ödev Not Aðýrlýðý\' toplamý \'100\''den fazla olmamalýdýr lütfen deðerleri tekrar giriniz\n ";
        }
        if (quizNotAgirligi + odevNotAgirligi == 100)
        {
            vizeNotAgirligi = 0;
            cout << "Girdiðiniz deðerlere göre Vize Not Aðýrlýðý \'0\' olarak belirlenmiþtir\n";
            break;
        }
        else
        {
            cout << endl;
            cout << endl;

            cout << "Vize notunun not yüzdesine etkisi girdiðiniz verilere göre otomatik olarak belirlenmiþtir.";
            vizeNotAgirligi = 100 - (quizNotAgirligi * 2 + odevNotAgirligi * 2);
            cout << "Otomatik belirlenen vize yüzde etkisi: " << vizeNotAgirligi << endl;

            break;

        }
    }
    
    while (true)     //**** Final sýnavýnýn not aðýrlýðýný alan döngü ****//
    {
        cout << "Final sýnavýnýn not yüzdesine etkisini giriniz (1-100): \n";
        cin >> finalNotAgirligi;
        if (finalNotAgirligi > 100 || finalNotAgirligi < 0)
        {
            cout << "Hatalý tuþlama tekrar deneyiniz.\n";
        }
        else
            break;
    }

    cout << endl;
    cout << endl;
    cout << endl;
    // Yýl içi notlarýn aðýrlýðý belirlendi
    cout << "Yýl içi notlarýn not yüzdesine etkisi girdiðiniz final not aðýrlýðýna göre otomatik olarak belirlenmiþtir.";
    yilIciNotlarinagirligi = 100 - finalNotAgirligi;
    cout << "Otomatik belirlenen yýl içi notlarýn yýlsonu not ortalamasýna etkisi: " << yilIciNotlarinagirligi << endl;
    cout << endl;
    cout << endl;

    if (yilIciNotlarinagirligi > 100 || yilIciNotlarinagirligi < 0)
    {
        cout << "Hatalý tuþlama... (Bir yerlerde hata yaptýn ama nerede? Lütfen tekrar dene...)\n";
        return 0;
    }

    float aa = 0, ba = 0, bb = 0, cb = 0, cc = 0, dc = 0, dd = 0, df = 0, ff = 0;

    int harfSayýsý[9] = { aa, ba, bb, cb, cc, dc, dd, df, ff };

    // const int sabitogr = ogrenciSayisi;
    float tumfinalNotlar[500] = {}; // 1- Dizi boyutunu sabit bir deðiþkenle(örn; bir üstteki deðiþken) deðiþtiremediðim için,2-
    int sayac = 0;                  // 2- yeterince büyük bir dizi oluþturdum
    float toplam = 0;
    float toplamNot = 0;

    int i = 0;
    ogrenciler ogrenci;
    // Rastgele bir þekilde isim ve notlarý belirleyen ve final notunu da hesaplayýp yazdýran döngü
    do
    {
        const int ogrs = ogrenciSayisi;
        int rastgeleSayi = rand() % ogrs;
                                 
        // Struct yapýsýna rastgele öðrenci ve notlarý eklendi
        ogrenci.isim = studentNameS[rastgeleSayi];
        ogrenci.soyad = studentSurnameS[rastgeleSayi];
        ogrenci.quiz1 = rastgeleNotlar();
        ogrenci.quiz2 = rastgeleNotlar();
        ogrenci.odev1 = rastgeleNotlar();
        ogrenci.odev2 = rastgeleNotlar();
        ogrenci.vize = rastgeleNotlar();
        ogrenci.final = rastgeleNotlar();


        // öðrencinin notu ve harf karþýlýðý belirlendi
        float toplamQuizNotu = (ogrenci.quiz1 + ogrenci.quiz2) * quizNotAgirligi / 100;
        float toplamOdevNotu = (ogrenci.odev1 + ogrenci.odev2) * odevNotAgirligi / 100;
        float vizeNotu = ogrenci.vize * vizeNotAgirligi / 100;
        float yilIciNot = (toplamQuizNotu + toplamOdevNotu + vizeNotu) * yilIciNotlarinagirligi / 100;
        float finalNotu = ogrenci.final * finalNotAgirligi / 100;

        ogrenci.finalNot = yilIciNot + finalNotu;
        // Oluþturulan final notu tüm final notlarýnýn olacaðý diziye eklendi
        tumfinalNotlar[sayac] = ogrenci.finalNot;
        sayac++;
        // Ortalama hesaplamak için final notlarý toplandý
        toplam += ogrenci.finalNot;

        // Öðrencinin notuna göre harf karþýlýðý yazdýrýldý ve hangi harften kaç tane alýndýðýný-
        // -hesaplamak için harfSayýsý adlý dizinin elemanlarý arttýrýldý
        toplamNot = ogrenci.finalNot;
        cout << "Sayýn " << ogrenci.isim + " " + ogrenci.soyad << ".  Yýl sonu notunuz: " << toplamNot << ".  Notunuzun harf karþýlýðý: ";

        if (toplamNot >= 90.00 && toplamNot <= 100)
        {
            cout << "AA\n\n";
            harfSayýsý[0]++;
            i++;
        }
        else if (toplamNot >= 85.00 && toplamNot < 90)
        {
            cout << "BA\n\n";
            harfSayýsý[1]++;
            i++;
        }
        else if (toplamNot >= 80.00 && toplamNot < 85)
        {
            cout << "BB\n\n";
            harfSayýsý[2]++;
            i++;
        }
        else if (toplamNot >= 75.00 && toplamNot < 80)
        {
            cout << "CB\n\n";
            harfSayýsý[3]++;
            i++;
        }
        else if (toplamNot >= 65.00 && toplamNot < 75)
        {
            cout << "CC\n\n";
            harfSayýsý[4]++;
            i++;
        }
        else if (toplamNot >= 58.00 && toplamNot <= 65)
        {
            cout << "DC\n\n";
            harfSayýsý[5]++;
            i++;
        }
        else if (toplamNot >= 50.00 && toplamNot <= 58)
        {
            cout << "DD\n\n";
            harfSayýsý[6]++;
            i++;
        }
        else if (toplamNot >= 40.00 && toplamNot <= 50)
        {
            cout << "FD\n\n";
            harfSayýsý[7]++;
            i++;
        }
        else if (toplamNot >= 0 && toplamNot <= 40)
        {
            cout << "FF\n\n";
            harfSayýsý[8]++;
            i++;
        }
        else
        {
            cout << "Notunuz belirlenemedi. Sebebini bulamadýk. Eksik veya hatalý giriþ yaptýðýnýzý düþünüyorsanýz lütfen tekrar deneyiniz.\n";
            break;
        }

        string harfler[9] = { "AA", "BA", "BB", "CB", "CC", "DC", "DD", "DF", "FF" };

        // Hangi harf notunu kaç kiþinin aldýðýný ve sýnýfa göre yüzdesini gösteren döngü
        if (i == ogrenciSayisi)
        {
            for (int a = 0; a < 9; a++)
            {
                cout << harfler[a] << " notunu  alan kiþi sayýsý: " << harfSayýsý[a] << endl;
                cout << "Sýnýfa göre yüzdesi: %" << (float)harfSayýsý[a]/ogrenciSayisi * 100 << endl;
            }
        }

    } while (i < ogrenciSayisi);
    cout << endl;
    cout << endl;

    // Sýnýf ortalamasý yazdýrýldý
    float sýnýfort = toplam / ogrenciSayisi;
    cout << "Sýnýf ortalamasý: " << sýnýfort << endl;

    
    float fark = 0;
    // Standart sapma yazdýrýldý
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        fark += pow(tumfinalNotlar[i] - sýnýfort,2);
    }
    float standartSapma = sqrt(fark / (ogrenciSayisi-1));
    cout << "Sýnýfýn standart sapmasý: " << standartSapma << endl;


    float enbuyuk = tumfinalNotlar[0];
    float enkucuk = tumfinalNotlar[0];
    // En düþük ve en yüksek notu belirleyen döngü
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        if (tumfinalNotlar[i] < enkucuk)
        {
            enkucuk = tumfinalNotlar[i];
        }
        if (tumfinalNotlar[i] > enbuyuk)
        {
            enbuyuk = tumfinalNotlar[i];
        }
    }
    cout << "Sýnýfýn en düþük notu: " << enkucuk << endl;
    cout << "Sýnýfýn en yuksek notu: " << enbuyuk << endl;
}


// 6 farklý notu yüzdesel aralýklarýna göre rastgele oluþturan fonksiyon
int rastgeleNotlar()
{
    int rastgele = rand() % 11;

    if (rastgele > 8)
        return rand() % 21 + 80;

    else if (rastgele > 3 && rastgele <= 8)
        return rand() % 31 + 50;

    else
        return rand() % 51;
}