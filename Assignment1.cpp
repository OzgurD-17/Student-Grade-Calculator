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

// 6 farklı notu yüzdesel aralıklarına göre rastgele oluşturan fonksiyon
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
    while (true)               //**** Öğrenci sayısını alan döngü ****//
    {
        cout << "Öğrenci sayısını giriniz (max 50 öğrenci): \n";
        cin >> ogrenciSayisi;
        if (ogrenciSayisi > 0)
            break;                              
        else
            cout << "Hatalı öğrenci sayısı girişi, lütfen tekrar deneyiniz.\n";
    }
    
    float quizNotAgirligi = 0, odevNotAgirligi = 0, vizeNotAgirligi = 0, finalNotAgirligi = 0, yilIciNotlarinagirligi = 0;

    while (true)   //**** Sınavların not ağırlıklarını alan döngü ****//
    {
        while (true)
        {
            cout << "Kısa sınavların(toplam 2 adet) not yüzdesine etkisini giriniz (1-100): \n";
            cin >> quizNotAgirligi;
            if (quizNotAgirligi > 100 || quizNotAgirligi < 0)
            {
                cout << "Hatalı tuşlama tekrar deneyiniz.\n";
            }
            else
                break;
        }
 
        while (true)
        {
            cout << "Ödev notlarının(toplam 2 adet) not yüzdesine etkisini giriniz (1-100): \n";
            cin >> odevNotAgirligi;
            if (odevNotAgirligi > 100 || odevNotAgirligi < 0)
            {
                cout << "Hatalı tuşlama tekrar deneyiniz.\n";
            }
            else
                break;
        }


        if (quizNotAgirligi + odevNotAgirligi > 100)
        {
            cout << "\'Quiz Not Ağırlığı\' ve \'Ödev Not Ağırlığı\' toplamı \'100\''den fazla olmamalıdır lütfen değerleri tekrar giriniz\n ";
        }
        if (quizNotAgirligi + odevNotAgirligi == 100)
        {
            vizeNotAgirligi = 0;
            cout << "Girdiğiniz değerlere göre Vize Not Ağırlığı \'0\' olarak belirlenmiştir\n";
            break;
        }
        else
        {
            cout << endl;
            cout << endl;

            cout << "Vize notunun not yüzdesine etkisi girdiğiniz verilere göre otomatik olarak belirlenmiştir.";
            vizeNotAgirligi = 100 - (quizNotAgirligi * 2 + odevNotAgirligi * 2);
            cout << "Otomatik belirlenen vize yüzde etkisi: " << vizeNotAgirligi << endl;

            break;

        }
    }
    
    while (true)     //**** Final sınavının not ağırlığını alan döngü ****//
    {
        cout << "Final sınavının not yüzdesine etkisini giriniz (1-100): \n";
        cin >> finalNotAgirligi;
        if (finalNotAgirligi > 100 || finalNotAgirligi < 0)
        {
            cout << "Hatalı tuşlama tekrar deneyiniz.\n";
        }
        else
            break;
    }

    cout << endl;
    cout << endl;
    cout << endl;
    // Yıl içi notların ağırlığı belirlendi
    cout << "Yıl içi notların not yüzdesine etkisi girdiğiniz final not ağırlığına göre otomatik olarak belirlenmiştir.";
    yilIciNotlarinagirligi = 100 - finalNotAgirligi;
    cout << "Otomatik belirlenen yıl içi notların yılsonu not ortalamasına etkisi: " << yilIciNotlarinagirligi << endl;
    cout << endl;
    cout << endl;

    if (yilIciNotlarinagirligi > 100 || yilIciNotlarinagirligi < 0)
    {
        cout << "Hatalı tuşlama... (Bir yerlerde hata yaptın ama nerede? Lütfen tekrar dene...)\n";
        return 0;
    }

    float aa = 0, ba = 0, bb = 0, cb = 0, cc = 0, dc = 0, dd = 0, df = 0, ff = 0;

    int harfSayısı[9] = { aa, ba, bb, cb, cc, dc, dd, df, ff };

    // const int sabitogr = ogrenciSayisi;
    float tumfinalNotlar[500] = {}; // 1- Dizi boyutunu sabit bir değişkenle(örn; bir üstteki değişken) değiştiremediğim için,2-
    int sayac = 0;                  // 2- yeterince büyük bir dizi oluşturdum
    float toplam = 0;
    float toplamNot = 0;

    int i = 0;
    ogrenciler ogrenci;
    // Rastgele bir şekilde isim ve notları belirleyen ve final notunu da hesaplayıp yazdıran döngü
    do
    {
        const int ogrs = ogrenciSayisi;
        int rastgeleSayi = rand() % ogrs;
                                 
        // Struct yapısına rastgele öğrenci ve notları eklendi
        ogrenci.isim = studentNameS[rastgeleSayi];
        ogrenci.soyad = studentSurnameS[rastgeleSayi];
        ogrenci.quiz1 = rastgeleNotlar();
        ogrenci.quiz2 = rastgeleNotlar();
        ogrenci.odev1 = rastgeleNotlar();
        ogrenci.odev2 = rastgeleNotlar();
        ogrenci.vize = rastgeleNotlar();
        ogrenci.final = rastgeleNotlar();


        // öğrencinin notu ve harf karşılığı belirlendi
        float toplamQuizNotu = (ogrenci.quiz1 + ogrenci.quiz2) * quizNotAgirligi / 100;
        float toplamOdevNotu = (ogrenci.odev1 + ogrenci.odev2) * odevNotAgirligi / 100;
        float vizeNotu = ogrenci.vize * vizeNotAgirligi / 100;
        float yilIciNot = (toplamQuizNotu + toplamOdevNotu + vizeNotu) * yilIciNotlarinagirligi / 100;
        float finalNotu = ogrenci.final * finalNotAgirligi / 100;

        ogrenci.finalNot = yilIciNot + finalNotu;
        // Oluşturulan final notu tüm final notlarının olacağı diziye eklendi
        tumfinalNotlar[sayac] = ogrenci.finalNot;
        sayac++;
        // Ortalama hesaplamak için final notları toplandı
        toplam += ogrenci.finalNot;

        // Öğrencinin notuna göre harf karşılığı yazdırıldı ve hangi harften kaç tane alındığını-
        // -hesaplamak için harfSayısı adlı dizinin elemanları arttırıldı
        toplamNot = ogrenci.finalNot;
        cout << "Sayın " << ogrenci.isim + " " + ogrenci.soyad << ".  Yıl sonu notunuz: " << toplamNot << ".  Notunuzun harf karşılığı: ";

        if (toplamNot >= 90.00 && toplamNot <= 100)
        {
            cout << "AA\n\n";
            harfSayısı[0]++;
            i++;
        }
        else if (toplamNot >= 85.00 && toplamNot < 90)
        {
            cout << "BA\n\n";
            harfSayısı[1]++;
            i++;
        }
        else if (toplamNot >= 80.00 && toplamNot < 85)
        {
            cout << "BB\n\n";
            harfSayısı[2]++;
            i++;
        }
        else if (toplamNot >= 75.00 && toplamNot < 80)
        {
            cout << "CB\n\n";
            harfSayısı[3]++;
            i++;
        }
        else if (toplamNot >= 65.00 && toplamNot < 75)
        {
            cout << "CC\n\n";
            harfSayısı[4]++;
            i++;
        }
        else if (toplamNot >= 58.00 && toplamNot <= 65)
        {
            cout << "DC\n\n";
            harfSayısı[5]++;
            i++;
        }
        else if (toplamNot >= 50.00 && toplamNot <= 58)
        {
            cout << "DD\n\n";
            harfSayısı[6]++;
            i++;
        }
        else if (toplamNot >= 40.00 && toplamNot <= 50)
        {
            cout << "FD\n\n";
            harfSayısı[7]++;
            i++;
        }
        else if (toplamNot >= 0 && toplamNot <= 40)
        {
            cout << "FF\n\n";
            harfSayısı[8]++;
            i++;
        }
        else
        {
            cout << "Notunuz belirlenemedi. Sebebini bulamadık. Eksik veya hatalı giriş yaptığınızı düşünüyorsanız lütfen tekrar deneyiniz.\n";
            break;
        }

        string harfler[9] = { "AA", "BA", "BB", "CB", "CC", "DC", "DD", "DF", "FF" };

        // Hangi harf notunu kaç kişinin aldığını ve sınıfa göre yüzdesini gösteren döngü
        if (i == ogrenciSayisi)
        {
            for (int a = 0; a < 9; a++)
            {
                cout << harfler[a] << " notunu  alan kişi sayısı: " << harfSayısı[a] << endl;
                cout << "Sınıfa göre yüzdesi: %" << (float)harfSayısı[a]/ogrenciSayisi * 100 << endl;
            }
        }

    } while (i < ogrenciSayisi);
    cout << endl;
    cout << endl;

    // Sınıf ortalaması yazdırıldı
    float sınıfort = toplam / ogrenciSayisi;
    cout << "Sınıf ortalaması: " << sınıfort << endl;

    
    float fark = 0;
    // Standart sapma yazdırıldı
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        fark += pow(tumfinalNotlar[i] - sınıfort,2);
    }
    float standartSapma = sqrt(fark / (ogrenciSayisi-1));
    cout << "Sınıfın standart sapması: " << standartSapma << endl;


    float enbuyuk = tumfinalNotlar[0];
    float enkucuk = tumfinalNotlar[0];
    // En düşük ve en yüksek notu belirleyen döngü
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
    cout << "Sınıfın en düşük notu: " << enkucuk << endl;
    cout << "Sınıfın en yuksek notu: " << enbuyuk << endl;
}


// 6 farklı notu yüzdesel aralıklarına göre rastgele oluşturan fonksiyon
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
