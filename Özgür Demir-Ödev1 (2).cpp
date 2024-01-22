/****************************************************************************************
**
**
**���������              SAKARYA �N�VERS�TESݠ��������������������������������
**�����         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTESݠ�������������������
**��������           B�LG�SAYAR M�HEND�SL��� B�L�Mܠ�������������������������
**�������   ���         PROGRAMLAMAYA G�R�� DERSݠ����������������������������
**�����������������������������������������������������������������������
**����� ��   �DEV NUMARASI��� : 1�������������������������������������
**����� ��   ��RENC� ADI����� : �zg�r Demir�������������������������
**����� ��   ��RENC� NUMARASI : b221210017�����������������������
**������     DERS GRUBU������ : C�������������������������������������
**  
** ���������������������������������������������������������������������
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

// 6 farkl� notu y�zdesel aral�klar�na g�re rastgele olu�turan fonksiyon
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
    while (true)               //**** ��renci say�s�n� alan d�ng� ****//
    {
        cout << "��renci say�s�n� giriniz (max 50 ��renci): \n";
        cin >> ogrenciSayisi;
        if (ogrenciSayisi > 0)
            break;                              
        else
            cout << "Hatal� ��renci say�s� giri�i, l�tfen tekrar deneyiniz.\n";
    }
    
    float quizNotAgirligi = 0, odevNotAgirligi = 0, vizeNotAgirligi = 0, finalNotAgirligi = 0, yilIciNotlarinagirligi = 0;

    while (true)   //**** S�navlar�n not a��rl�klar�n� alan d�ng� ****//
    {
        while (true)
        {
            cout << "K�sa s�navlar�n(toplam 2 adet) not y�zdesine etkisini giriniz (1-100): \n";
            cin >> quizNotAgirligi;
            if (quizNotAgirligi > 100 || quizNotAgirligi < 0)
            {
                cout << "Hatal� tu�lama tekrar deneyiniz.\n";
            }
            else
                break;
        }
 
        while (true)
        {
            cout << "�dev notlar�n�n(toplam 2 adet) not y�zdesine etkisini giriniz (1-100): \n";
            cin >> odevNotAgirligi;
            if (odevNotAgirligi > 100 || odevNotAgirligi < 0)
            {
                cout << "Hatal� tu�lama tekrar deneyiniz.\n";
            }
            else
                break;
        }


        if (quizNotAgirligi + odevNotAgirligi > 100)
        {
            cout << "\'Quiz Not A��rl���\' ve \'�dev Not A��rl���\' toplam� \'100\''den fazla olmamal�d�r l�tfen de�erleri tekrar giriniz\n ";
        }
        if (quizNotAgirligi + odevNotAgirligi == 100)
        {
            vizeNotAgirligi = 0;
            cout << "Girdi�iniz de�erlere g�re Vize Not A��rl��� \'0\' olarak belirlenmi�tir\n";
            break;
        }
        else
        {
            cout << endl;
            cout << endl;

            cout << "Vize notunun not y�zdesine etkisi girdi�iniz verilere g�re otomatik olarak belirlenmi�tir.";
            vizeNotAgirligi = 100 - (quizNotAgirligi * 2 + odevNotAgirligi * 2);
            cout << "Otomatik belirlenen vize y�zde etkisi: " << vizeNotAgirligi << endl;

            break;

        }
    }
    
    while (true)     //**** Final s�nav�n�n not a��rl���n� alan d�ng� ****//
    {
        cout << "Final s�nav�n�n not y�zdesine etkisini giriniz (1-100): \n";
        cin >> finalNotAgirligi;
        if (finalNotAgirligi > 100 || finalNotAgirligi < 0)
        {
            cout << "Hatal� tu�lama tekrar deneyiniz.\n";
        }
        else
            break;
    }

    cout << endl;
    cout << endl;
    cout << endl;
    // Y�l i�i notlar�n a��rl��� belirlendi
    cout << "Y�l i�i notlar�n not y�zdesine etkisi girdi�iniz final not a��rl���na g�re otomatik olarak belirlenmi�tir.";
    yilIciNotlarinagirligi = 100 - finalNotAgirligi;
    cout << "Otomatik belirlenen y�l i�i notlar�n y�lsonu not ortalamas�na etkisi: " << yilIciNotlarinagirligi << endl;
    cout << endl;
    cout << endl;

    if (yilIciNotlarinagirligi > 100 || yilIciNotlarinagirligi < 0)
    {
        cout << "Hatal� tu�lama... (Bir yerlerde hata yapt�n ama nerede? L�tfen tekrar dene...)\n";
        return 0;
    }

    float aa = 0, ba = 0, bb = 0, cb = 0, cc = 0, dc = 0, dd = 0, df = 0, ff = 0;

    int harfSay�s�[9] = { aa, ba, bb, cb, cc, dc, dd, df, ff };

    // const int sabitogr = ogrenciSayisi;
    float tumfinalNotlar[500] = {}; // 1- Dizi boyutunu sabit bir de�i�kenle(�rn; bir �stteki de�i�ken) de�i�tiremedi�im i�in,2-
    int sayac = 0;                  // 2- yeterince b�y�k bir dizi olu�turdum
    float toplam = 0;
    float toplamNot = 0;

    int i = 0;
    ogrenciler ogrenci;
    // Rastgele bir �ekilde isim ve notlar� belirleyen ve final notunu da hesaplay�p yazd�ran d�ng�
    do
    {
        const int ogrs = ogrenciSayisi;
        int rastgeleSayi = rand() % ogrs;
                                 
        // Struct yap�s�na rastgele ��renci ve notlar� eklendi
        ogrenci.isim = studentNameS[rastgeleSayi];
        ogrenci.soyad = studentSurnameS[rastgeleSayi];
        ogrenci.quiz1 = rastgeleNotlar();
        ogrenci.quiz2 = rastgeleNotlar();
        ogrenci.odev1 = rastgeleNotlar();
        ogrenci.odev2 = rastgeleNotlar();
        ogrenci.vize = rastgeleNotlar();
        ogrenci.final = rastgeleNotlar();


        // ��rencinin notu ve harf kar��l��� belirlendi
        float toplamQuizNotu = (ogrenci.quiz1 + ogrenci.quiz2) * quizNotAgirligi / 100;
        float toplamOdevNotu = (ogrenci.odev1 + ogrenci.odev2) * odevNotAgirligi / 100;
        float vizeNotu = ogrenci.vize * vizeNotAgirligi / 100;
        float yilIciNot = (toplamQuizNotu + toplamOdevNotu + vizeNotu) * yilIciNotlarinagirligi / 100;
        float finalNotu = ogrenci.final * finalNotAgirligi / 100;

        ogrenci.finalNot = yilIciNot + finalNotu;
        // Olu�turulan final notu t�m final notlar�n�n olaca�� diziye eklendi
        tumfinalNotlar[sayac] = ogrenci.finalNot;
        sayac++;
        // Ortalama hesaplamak i�in final notlar� topland�
        toplam += ogrenci.finalNot;

        // ��rencinin notuna g�re harf kar��l��� yazd�r�ld� ve hangi harften ka� tane al�nd���n�-
        // -hesaplamak i�in harfSay�s� adl� dizinin elemanlar� artt�r�ld�
        toplamNot = ogrenci.finalNot;
        cout << "Say�n " << ogrenci.isim + " " + ogrenci.soyad << ".  Y�l sonu notunuz: " << toplamNot << ".  Notunuzun harf kar��l���: ";

        if (toplamNot >= 90.00 && toplamNot <= 100)
        {
            cout << "AA\n\n";
            harfSay�s�[0]++;
            i++;
        }
        else if (toplamNot >= 85.00 && toplamNot < 90)
        {
            cout << "BA\n\n";
            harfSay�s�[1]++;
            i++;
        }
        else if (toplamNot >= 80.00 && toplamNot < 85)
        {
            cout << "BB\n\n";
            harfSay�s�[2]++;
            i++;
        }
        else if (toplamNot >= 75.00 && toplamNot < 80)
        {
            cout << "CB\n\n";
            harfSay�s�[3]++;
            i++;
        }
        else if (toplamNot >= 65.00 && toplamNot < 75)
        {
            cout << "CC\n\n";
            harfSay�s�[4]++;
            i++;
        }
        else if (toplamNot >= 58.00 && toplamNot <= 65)
        {
            cout << "DC\n\n";
            harfSay�s�[5]++;
            i++;
        }
        else if (toplamNot >= 50.00 && toplamNot <= 58)
        {
            cout << "DD\n\n";
            harfSay�s�[6]++;
            i++;
        }
        else if (toplamNot >= 40.00 && toplamNot <= 50)
        {
            cout << "FD\n\n";
            harfSay�s�[7]++;
            i++;
        }
        else if (toplamNot >= 0 && toplamNot <= 40)
        {
            cout << "FF\n\n";
            harfSay�s�[8]++;
            i++;
        }
        else
        {
            cout << "Notunuz belirlenemedi. Sebebini bulamad�k. Eksik veya hatal� giri� yapt���n�z� d���n�yorsan�z l�tfen tekrar deneyiniz.\n";
            break;
        }

        string harfler[9] = { "AA", "BA", "BB", "CB", "CC", "DC", "DD", "DF", "FF" };

        // Hangi harf notunu ka� ki�inin ald���n� ve s�n�fa g�re y�zdesini g�steren d�ng�
        if (i == ogrenciSayisi)
        {
            for (int a = 0; a < 9; a++)
            {
                cout << harfler[a] << " notunu  alan ki�i say�s�: " << harfSay�s�[a] << endl;
                cout << "S�n�fa g�re y�zdesi: %" << (float)harfSay�s�[a]/ogrenciSayisi * 100 << endl;
            }
        }

    } while (i < ogrenciSayisi);
    cout << endl;
    cout << endl;

    // S�n�f ortalamas� yazd�r�ld�
    float s�n�fort = toplam / ogrenciSayisi;
    cout << "S�n�f ortalamas�: " << s�n�fort << endl;

    
    float fark = 0;
    // Standart sapma yazd�r�ld�
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        fark += pow(tumfinalNotlar[i] - s�n�fort,2);
    }
    float standartSapma = sqrt(fark / (ogrenciSayisi-1));
    cout << "S�n�f�n standart sapmas�: " << standartSapma << endl;


    float enbuyuk = tumfinalNotlar[0];
    float enkucuk = tumfinalNotlar[0];
    // En d���k ve en y�ksek notu belirleyen d�ng�
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
    cout << "S�n�f�n en d���k notu: " << enkucuk << endl;
    cout << "S�n�f�n en yuksek notu: " << enbuyuk << endl;
}


// 6 farkl� notu y�zdesel aral�klar�na g�re rastgele olu�turan fonksiyon
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