# led_buton
# Arduino Buton Kontrollü LED ve Seri Monitör Çıktısı

Bu proje, Arduino Uno kullanarak bir push buton aracılığıyla LED kontrolü yapmayı ve butona her basıldığında Seri Monitör (Serial Monitor) üzerinden tek seferlik durum bildirimi göndermeyi amaçlar.

## Kullanılan Malzemeler
* 1x Arduino Uno
* 1x Breadboard
* 1x Kırmızı LED
* 1x 220Ω Direnç
* 1x Push Buton (4 bacaklı)
* Jumper Kablolar

## Devre Bağlantısı
1. **LED Bağlantısı:** LED'in uzun bacağını (Anot / +) **220Ω direnç** üzerinden **Arduino Pin 13**'e, kısa bacağını (Katot / -) **GND** pinine bağlayın.
2. **Buton Bağlantısı:** Butonu breadboard'un orta yarığının (kanalı) üzerine yerleştirin. Sol üst bacağını **Arduino Pin 2**'ye, sol alt bacağını ise **GND** pinine bağlayın.
wokwi bağlantı linki:
https://wokwi.com/projects/481511500545624065

## Çalışma Mantığı
* **Dahili Direnç (`INPUT_PULLUP`):** Harici bir pull-up direncine ihtiyaç duymadan Arduino'nun dahili direnci aktif edilir; butona basıldığında pin `LOW` (0) sinyali okur.
* **Yazılım Tabanlı Debounce (`millis()`):** Mekanik buton sıçramalarından (titreşimlerden) kaynaklanan hatalı veya çift okumaları engellemek için 50 milisaniyelik zaman filtresi uygulanır.
* **Tek Seferlik Çıktı:** Butona basılı tutulduğu sürece LED yanık kalır ancak Seri Monitör'e (9600 baud) yalnızca ilk basış anında bir kez `Butona basiliyor` mesajı yazdırılır. Buton bırakıldığında LED söner.
