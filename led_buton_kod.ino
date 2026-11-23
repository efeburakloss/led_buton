const int ledPin = 13;
const int butonPin = 2;
int sonOkunanDurum = HIGH;     
int kararliButonDurumu = HIGH;
unsigned long sonDegisimZamani = 0;
const unsigned long beklemeSuresi = 50;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(butonPin, INPUT_PULLUP);
  Serial.begin(9600);}
void loop() {
  int okunan = digitalRead(butonPin);
  if (okunan != sonOkunanDurum) {sonDegisimZamani = millis();}
  if ((millis() - sonDegisimZamani) > beklemeSuresi) {
    if (okunan != kararliButonDurumu) {
      kararliButonDurumu = okunan;
      if (kararliButonDurumu == LOW) {
        digitalWrite(ledPin, HIGH);
        Serial.println("Butona basiliyor");} 
        else {digitalWrite(ledPin, LOW);}}}
  sonOkunanDurum = okunan;}