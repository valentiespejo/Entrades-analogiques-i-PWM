/******************************************************************************
**                                                                           **
**                          REPTE 5 AVISADOR ACUSTIC                         **
**                                                                           **
**                                                                           **
**  Valentí Espejo Rodriguez                                    15/05/2017   **
*******************************************************************************/

//******************************* INCLUDES ****************************************

//******************************* VARIABLES ***************************************
const int xiulet = 9;        // donar nom al pin 9 de l’Arduino
const int ldr0 = A0;         // donar nom al pin A0 de l’Arduino
const int ldr1 = A1;         // donar nom al pin A1 de l’Arduino
const int ldr2 = A2;         // donar nom al pin A2 de l’Arduino

int valLdr0;                 // guardar valor del ldr  
int valLdr1;
int valLdr2;
int freq;                    // freqüència del xiulet
//******************************** SETUP ******************************************
void setup()
{
  pinMode(xiulet, OUTPUT);     // definir el pin 9 com una sortida
  Serial.begin(9600);
}
//********************************* LOOP ******************************************
void loop()
{
  valLdr0 = analogRead(ldr0);   // llegir valor ldr
  valLdr1 = analogRead(ldr1);   
  valLdr2 = analogRead(ldr2);
  
  freq = min(valLdr0, valLdr1);  // veure quin ldr té objecte més aprop
  //freq = min(valLdr2, freq);
  freq = map(freq, 0, 1023, 2000, 0);   // mapejar valor de 0-1023 a 2000-10
  
  tone(xiulet, freq, 100);   // xiulet de durada 300ms
  delay(map(valLdr2,400,780,1,700));            // esperar xiulet + silenci
  Serial.println(valLdr2);
}

//******************************* FUNCIONS ****************************************
