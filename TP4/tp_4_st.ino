#include <Wire.h>     // libreria para bus I2C
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306
#include <Preferences.h>

Preferences preferences;
<<<<<<< HEAD:TP4/TP4/TP4.ino
=======

 int ValorUmbral;
>>>>>>> aa79d385a3a80e93a9dec8efb7555849bbe69bd7:tp_4_st/tp_4_st.ino

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);  // crea objeto


#include "DHT.h"
#include <DHT.h>
#include <DHT_U.h>
float t;

#define DHTPIN 23     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

int state;
#define inicio 1
#define pantalla2 2
#define SUBIR_UMBRAL 3
<<<<<<< HEAD:TP4/TP4/TP4.ino
#define BAJAR_UMBRAL 4  
=======
#define BAJAR_UMBRAL 4
>>>>>>> aa79d385a3a80e93a9dec8efb7555849bbe69bd7:tp_4_st/tp_4_st.ino
#define VOLVER 5

#define BTS 34 // suma
#define BTR 35 // resta
int BTSlecture;
int BTRlecture;

void setup() {
  Serial.begin(115200);
  Wire.begin();         // inicializa bus I2C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  dht.begin();
  pinMode(BTS, INPUT_PULLUP);
  pinMode(BTR, INPUT_PULLUP);

<<<<<<< HEAD:TP4/TP4/TP4.ino
   preferences.begin("my-app", false);

  unsigned int ValorUmbral = preferences.getUInt("ValorUmbral");
=======
  preferences.begin("my-app", false);

  ValorUmbral = preferences.getUInt("ValorUmbral", 0);
>>>>>>> aa79d385a3a80e93a9dec8efb7555849bbe69bd7:tp_4_st/tp_4_st.ino

  state = inicio;
}

void loop() {
  switch (state)
  {
    case (inicio):

<<<<<<< HEAD:TP4/TP4/TP4.ino
     BTSlecture = digitalRead(BTS);
=======
      BTSlecture = digitalRead(BTS);
>>>>>>> aa79d385a3a80e93a9dec8efb7555849bbe69bd7:tp_4_st/tp_4_st.ino
      BTRlecture = digitalRead(BTR);
      if ( BTSlecture == 1 && BTRlecture  == 1)
      {

<<<<<<< HEAD:TP4/TP4/TP4.ino
 

      dhtFunc();
      oledFunc();
      lectureBtn();
      }
      
=======


        dhtFunc();
        oledFunc();
        lectureBtn();
      }

>>>>>>> aa79d385a3a80e93a9dec8efb7555849bbe69bd7:tp_4_st/tp_4_st.ino
      break;

    case (pantalla2):
      delay(50);
      BTSlecture = digitalRead(BTS);
      BTRlecture = digitalRead(BTR);
      if ( BTSlecture == 1 && BTRlecture  == 1)
      {
        display.clearDisplay();      // limpia pantalla
        display.setTextColor(WHITE);
        display.setCursor(0, 30);
        display.print("valor umbral: ");  // escribe en pantalla el texto
        display.print(ValorUmbral);  // escribe en pantalla el texto
        display.display();     // muestra en pantalla todo lo establecido anteriormente

        Serial.print("paso");
        BTSlecture = digitalRead(BTS);
        BTRlecture = digitalRead(BTR);

      } if ( BTSlecture == 1 && BTRlecture  == 0)
      {

        state = SUBIR_UMBRAL;

      } if ( BTSlecture == 0 && BTRlecture  == 1)
      {

        state = BAJAR_UMBRAL;
      }



      break;


    case SUBIR_UMBRAL:
      BTSlecture = digitalRead(BTS);
      BTRlecture = digitalRead(BTR);
      if ( BTSlecture == 0 && BTRlecture  == 0)
      {
        Serial.print("inicio");
        BTSlecture = digitalRead(BTS);
        BTRlecture = digitalRead(BTR);
        delay(200);

        state = VOLVER;


      }
      BTSlecture = digitalRead(BTS);
      BTRlecture = digitalRead(BTR);
      if ( BTSlecture == 1 && BTRlecture  == 1)
      {


        ValorUmbral = ValorUmbral + 1;
        delay(100);
        BTSlecture = digitalRead(BTS);
        BTRlecture = digitalRead(BTR);

        state = pantalla2;

      }

      break;


    case BAJAR_UMBRAL:
      BTSlecture = digitalRead(BTS);
      BTRlecture = digitalRead(BTR);
      if ( BTSlecture == 0 && BTRlecture  == 0)
      {
        Serial.print("inicio");
        BTSlecture = digitalRead(BTS);
        BTRlecture = digitalRead(BTR);
        delay(200);

        state = VOLVER;


      }
      BTSlecture = digitalRead(BTS);
      BTRlecture = digitalRead(BTR);
      if ( BTSlecture == 1 && BTRlecture  == 1)
      {

        ValorUmbral = ValorUmbral - 1;
        delay(100);
        BTSlecture = digitalRead(BTS);
        BTRlecture = digitalRead(BTR);


        state = pantalla2;
      }


      break;

<<<<<<< HEAD:TP4/TP4/TP4.ino
case VOLVER:

Serial.println("GUARDADO");

  preferences.putUInt("ValorUmbral", ValorUmbral);

 
  preferences.end();

  state= inicio;


      break;
      }


     
=======
    case VOLVER:

      BTSlecture = digitalRead(BTS);
      BTRlecture = digitalRead(BTR);
      if ( BTSlecture == 1 && BTRlecture  == 1)
      {
        Serial.println("GUARDADO");
        preferences.putUInt("ValorUmbral", ValorUmbral);
        state = inicio;
      }
      break;
>>>>>>> aa79d385a3a80e93a9dec8efb7555849bbe69bd7:tp_4_st/tp_4_st.ino
  }



}

void dhtFunc() {

  t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
}
void oledFunc()
{
  display.clearDisplay();      // limpia pantalla
  display.setCursor(0, 20);     // ubica cursor en inicio de coordenadas 0,0
  display.setTextSize(1);
  display.print("temp actual: ");  // escribe en pantalla el texto
  display.setTextColor(WHITE);
  display.print(t);  // escribe en pantalla el texto
  display.setCursor(0, 40);
  display.print("valor umbral: ");  // escribe en pantalla el texto
  display.print(ValorUmbral);  // escribe en pantalla el texto
  display.display();     // muestra en pantalla todo lo establecido anteriormente
}




void lectureBtn()
{

  BTSlecture = digitalRead(BTS);
  BTRlecture = digitalRead(BTR);

  if ( BTSlecture == 0 && BTRlecture  == 0)
  {
    Serial.println("prueba");
    BTSlecture = digitalRead(BTS);
    BTRlecture = digitalRead(BTR);

    state = pantalla2;


  }
}
