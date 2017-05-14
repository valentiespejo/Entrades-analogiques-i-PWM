/******************************************************************************
**                                                                           **
**                             REPTE 6 MELODIA                               **
**            c=DO, d=RE, e=MI, f=FA, g=SOL, a=LA, b=SI, C=DO'               **
**                                                                           **
**  Valentí Espejo Rodriguez                                    14/05/2017   **
*******************************************************************************/
 
int speakerPin = 9; //definir pin
int length = 26;
// definir les notes de la canço
char notes[] = "eeeeeeegcde fffffeeeeddedg";
// definir el temps de cada nota
int beats[] = { 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

int tempo = 300;
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
void setup() {
  pinMode(speakerPin, OUTPUT);
}
void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    
    // pausa entre notes
    delay(tempo / 10); 
  }
}
