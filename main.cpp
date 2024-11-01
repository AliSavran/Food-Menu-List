#include <iostream>
#include <string>

using namespace std;

// Menü yapýsý
struct Menu {
    string isim;
    string icerik;
    float fiyat;
    int gelis_suresi;
};

// Menü iþlemlerini içeren sýnýf
class MenuIslem {
public:
    // Menüler
    Menu menuler[4] = {
        {"1 - Vejeteryan Menu", "Yogurtlu Soguk Corba, Vejeteryan Lazanya, Akdeniz Salatasi, Damla Sakizli Kurabiye", 650, 45},
        {"2 - Kova Menu ", "Golden But, Tenders,4'lu Nuggets, 2 Acili Kanat, Biscuit", 550, 40},
        {"3 - Protein Menu", "Mantar Corbasi, Sarimsakli Balli Tavuk, Akdeniz Salata, Tavuk Gogsu Tatlisi", 470, 50},
        {"4 - Deniz Menu", "Kuru Soðan, Mantar, Kalamar, Somon, Karides, Midye, Yengec", 850, 60}
    };

    // Menü bilgilerini görüntüleme fonksiyonu
    void MenuBilgi(const Menu& menu) {
        cout << menu.isim << ": " << menu.icerik << " - " << menu.fiyat << "TL, " << menu.gelis_suresi << "Dk\n" << endl;
    }

    // Mevcut menüleri gösterme fonksiyonu
    void MevcutMenuleriGoster() {
        cout << "       Menuler      \n";
        for (const auto& menu : menuler) {
            MenuBilgi(menu);
        }
    }

    // Sipariþ alma fonksiyonu
    void MenuSiparis() {
        Menu secilen_menuler[4]; // En fazla 4 menü seçilebilir
        int secim;
        int secilen_sayisi = 0;
        float toplam_fiyat = 0.0;
        char devam;

        do {
            cout << "Siparis vermek istediginiz menunun numarasini giriniz : ";
            cin >> secim;

            if (secim < 1 || secim > 4) {
                cout << "Gecersiz menu numarasi!\n";
                continue;
            }

            secilen_menuler[secilen_sayisi++] = menuler[secim - 1];
            toplam_fiyat += menuler[secim - 1].fiyat;

            cout << "Siparisiniz eklendi.\n";
            cout << "Devam etmek istiyor musunuz? (E/H): ";
            cin >> devam;
        } while ((devam == 'E' || devam == 'e') && secilen_sayisi < 4);

        // Seçilen menüleri göster
        cout << "\nSiparisiniz:\n";
        for (int i = 0; i < secilen_sayisi; ++i) {
            MenuBilgi(secilen_menuler[i]);
        }

        cout << "Toplam fiyat: " << toplam_fiyat << " TL" << endl;

        // Kredi kartý ile ödeme
        KrediKartiOdeme(toplam_fiyat);
    }

private:
    // Kredi kartý ile ödeme fonksiyonu
    void KrediKartiOdeme(float toplam_fiyat) {
        cout << "Kredi karti bilgilerinizi giriniz:\n";
        string kart_numarasi;
        string son_kullanma_tarihi;
        string guvenlik_kodu;
        cout << "Kart Numarasi: ";
        cin >> kart_numarasi;
        cout << "Son Kullanma Tarihi (AA/YY): ";
        cin >> son_kullanma_tarihi;
        cout << "Guvenlik Kodu: ";
        cin >> guvenlik_kodu;

        // Basit bir doðrulama yapalým (örneðin, kart numarasýnýn uzunluðunu kontrol edebiliriz)
        if (kart_numarasi.length() != 16) {
            cout << "Hatali kredi karti numarasi!\n";
            return;
        }

        cout << "Odeme basariyla gerceklestirildi. Afiyet olsun!\n";
    }
};

int main() {
    MenuIslem menuIslem;

    // Mevcut menüleri gösterme
    menuIslem.MevcutMenuleriGoster();

    // Sipariþ alma döngüsü
    char devam;
    do {
        menuIslem.MenuSiparis();
        cout << "Yeni siparis almak istiyor musunuz? (E/H): ";
        cin >> devam;
    } while (devam == 'E' || devam == 'e');

    return 0;
}
