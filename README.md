🏠 Güvenli Ev ve Akıllı Giriş Sistemi
Bu proje, Arduino platformu üzerinde geliştirilmiş, fiziksel güvenlik ve erişim kontrolü sağlayan bir Akıllı Ev Güvenlik Sistemi prototipidir.
Sistem, çevre birimlerinden gelen verileri işleyerek kapı kilit mekanizmasını (kapı pini) yönetmek ve izinsiz girişleri engellemek üzere tasarlanmıştır.

🛡️ Proje Özellikleri
Erişim Kontrolü: Tanımlanan giriş pinleri üzerinden gelen sinyallerin doğrulanması ve kapı mekanizmasının tetiklenmesi.

Entegre Güvenlik Hattı: Evin kritik noktalarını izleyen sensör verilerinin gerçek zamanlı analizi.

Geri Bildirim Sistemi: Başarılı girişlerde veya alarm durumlarında LED ve Buzzer üzerinden kullanıcıya durum bilgisi aktarımı.

🛠️ Donanım Yapılandırması ve Pin Yönetimi
Kod mimarisi, modüler bir donanım yapısını destekleyecek şekilde optimize edilmiştir:

Kapı Kontrol Pini: Kapı kilidini veya motorunu (Servo/Röle) kontrol eden ana çıkış hattı.

Giriş Denetimi: Kullanıcı girişlerini (Keypad, Buton veya Manyetik Switch) karşılayan giriş pinleri.

Uyarı Birimleri: Sistem durumunu raporlayan görsel ve işitsel çıkış elemanları.

💻 Yazılım Mantığı
Sistem, sonsuz döngü (loop) içerisinde giriş pinlerinin lojik durumlarını (HIGH/LOW) takip eder.

Dinleme: Giriş pinlerinden gelen sinyaller sürekli örneklenir.

Doğrulama: Gelen sinyal, kodda belirtilen güvenlik koşullarını sağladığında kapı pini üzerinden çıkış tetiklenir.

Güvenlik Modu: Belirli bir süre sonra veya manuel komutla kapı tekrar güvenli (kilitli) konuma getirilir.

🚀 Kurulum ve Kullanım
guvenli_ev.ino dosyasını Arduino IDE ile açın.

Kod içerisindeki const int tanımlamalarına bakarak donanım bağlantılarını yapın.

Kodu Arduino kartınıza yükleyin.

Seri Port ekranını (9600 baud) açarak sistemin aktivasyon loglarını takip edin.

👨‍💻 Geliştirici
Mervan DİLLİ - Yazılım Mühendisliği Öğrencisi | Muş Alparslan Üniversitesi
