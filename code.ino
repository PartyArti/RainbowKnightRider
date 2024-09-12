/*The Rainbow Knight Rider*/

int pins[] = {3, 5, 6, 9, 10};//alustetaan pinnit, laitetaan ne taulukkoon, jotta koodirivejä saadaan vähemmän
int d = 30; //luodaan ajastinmuuttuja
//int a = 0; //luodaan laskurimuuttuja
const int nappi = 11; //luodaan napille muuttaja
int buttonState = 0; //luodaan muuttuja, johon laitetaan napin tila: päällä/pois

void setup(){
  Serial.begin(9600); //laitetaan Serial-väylä päälle degubbausta varten
  pinMode(nappi,INPUT); //märitetään napin digitaalipinni inputiksi
  for (int i = 0; i < 5; i++) {//määritetään ledien digipinnit outputeiksi käymällä läpi taulukkoa
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  
  buttonState = digitalRead(nappi);//tarkkaillaan napin tilaa
 if (buttonState == HIGH) {  //jos nappi on pohjassa, suoritetaan for-loopit
   for(int a = 0; a < 16; a++){
   for (int i = 0; i < 5; i++) { //sytytetään ja sammutetaan pinnit vuoron perään vasemmalta oikealle
    digitalWrite(pins[i], HIGH);
    delay(d); //viive määrittää ledin palamisajan
    digitalWrite(pins[i], LOW);
    delay(d);
  }
  for (int i = 4; i >= 0; i--) { //sytytetään ja sammutetaan ledit oikealta vasemmalle
    digitalWrite(pins[i], HIGH);
    delay(d);
    digitalWrite(pins[i], LOW);
    delay(d);
  }
  Serial.println(a);//debuggausta varten
 }
 }
}
