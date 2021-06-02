/*
Projeto final de sistemas digitais
Pedro Ferreira - Pedro Zanineli
*/

/* Definição das notas */
#define NOTE_B2 247
#define NOTE_G2 196
#define NOTE_A2 220
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185

/* Pré-processamento da fita de LED */
#include <Adafruit_NeoPixel.h>
#define PIN 13	 // input pin Neopixel is attached to
#define NUMPIXELS 24 // number of neopixels in strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/* Definição das cores */

int redColor;
int greenColor;
int blueColor;

/* Variáveis - delay, random, count */
int d, r, count, i;

/* Pré-processamento do visor LCD */
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* Leitura dos botões e buzzer */
int buttonVer,buttonPre;
int buzzer = 8;

void setup(){
  
  Serial.begin(9600);
  
  // Buzzer
  pinMode(buzzer, OUTPUT);
  
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  
  pixels.begin();
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print("Verde | Vermelho");
  
}

void loop() {
  
  buttonVer = digitalRead(7);
  buttonPre = digitalRead(6);
  
  int teste;
  
  if(buttonVer == 1 || buttonPre == 1){
    
    pixels.clear();
    
    lcd.setCursor(0, 1);
  	lcd.print("       ");
    
    // rodar();
    
    r = random(60,84);
    
    count = i = 0;
    
    while(count <= r){
    
      // pixels.Color usa valores de RGB, de 0,0,0 até 255,255,255
      
      if (i%2==0){
      
      	// Fará com que o LED fique vermelho
      
   		redColor = 255;
		greenColor = 0;
		blueColor = 0;
    
   	  }else{
     	
      	// Fará com que o LED fique verde
      
        redColor = 80;
		greenColor = 255;
		blueColor = 80;
        
      }
    
      pixels.setPixelColor(i, pixels.Color(redColor,greenColor,blueColor));
      if(i==0){
        
        pixels.setPixelColor(23, pixels.Color(0, 0,0));
      }
      
      else{
      	pixels.setPixelColor(i-1, pixels.Color(0, 0,0));
      }
      
      pixels.show();
     
      /* Controle de velocidade */
      
      if(count <=((4*r)/10)){
      	d = 100;
      }
         
      if(count > ((4*r)/10) && count <=((5*r)/10)){
      	d = 250;
      }
         
       if(count > ((5*r)/10) && count <=((7*r)/10)){
        d = 350;
      }
       if(count > ((7*r)/10) && count <=((8*r)/10)){
        d = 450;
      }
         
       if(count > ((8*r)/10) && count <=((9*r)/10)){
      	d = 550;
      }
         
       if(count > ((9*r)/10) && count <=((9.5*r)/10)){
      	d = 700;
      }
       if(count > ((9.5*r)/10) && count <=((9.8*r)/10)){
      	d = 900;
      }
      if(count > ((9.8*r)/10) && count <=((9.9*r)/10)){
      	d = 1000;
      }
       if(count >((9.9*r)/10)){
        d = 1100;
      }
      
      if(i >= 23){
        i=0;
      }else{
        i++;
      } 
      
      count++;
      delay(d);
     
    }
    
    int res = r%2;
    
    if(buttonVer == res){
      
      Serial.print("Ganhou ");
      
      lcd.setCursor(0, 1);
  	  lcd.print("Ganhou!");
      
    }else if(buttonPre != res){
      
      Serial.print("Ganhou ");
      
      lcd.setCursor(0, 1);
  	  lcd.print("Ganhou!");
      
    }else{
      
      Serial.print("Perdeu ");
      
      lcd.setCursor(0, 1);
  	  lcd.print("Perdeu!");
    }
    
    Serial.println(r);
    delay(1000);
    if(buttonVer == res || buttonPre != res){
      
      musicaWin();
      
    }
    
    else{
      
      musicaLose();
    }
    
    acender(res);
  
  // Envia uma atualização da cor do pixel para o hardware
 
  delay(200);
  }

}

void acender(int result){

	if (result){
      
      // Fará com que o LED fique vermelho
      
   		redColor = 80;
		greenColor = 255;
		blueColor = 80;
    
   	}else{
     	
      	// Fará com que o LED fique cinza
     
        redColor = 255;
		greenColor = 0;
		blueColor = 0;
        
    }
  
  for(int j = 0; j <= NUMPIXELS; j++){
  		pixels.setPixelColor(j, pixels.Color(redColor,greenColor,blueColor));
  }
  
  pixels.show();
  
  delay(4000);
}

//Contrução das melodias do Buzzer

int melodyLose[] = {
    
  	NOTE_FS3, NOTE_F3, NOTE_E3
      
  };

  int noteDurationsLose[] = {
    
    3,3,3
      
  };

  int melodyWin[] = {
    
  	NOTE_B2, NOTE_B2, NOTE_A2, NOTE_B2, NOTE_B2, NOTE_A2, NOTE_B2,
 	NOTE_B2, NOTE_A2, NOTE_G2
      
  };

  int noteDurationsWin[] = {
    
    5, 8, 8, 5, 8, 8, 5, 8, 8, 5
      
  };

void musicaWin(){

   for (int thisNote = 0; thisNote < 11; thisNote++) {

    int noteDuration = 2000 / noteDurationsWin[thisNote];

    tone(8, melodyWin[thisNote], noteDuration);

  
    int pauseBetweenNotes = noteDuration * 1.40;

    delay(pauseBetweenNotes);

    noTone(8);
   }

  }
  
  void musicaLose(){
  

   for (int thisNote = 0; thisNote < 3; thisNote++) {

    int noteDuration = 2000 / noteDurationsLose[thisNote];

    tone(8, melodyLose[thisNote], noteDuration);

  

    int pauseBetweenNotes = noteDuration * 1.40;

    delay(pauseBetweenNotes);

    noTone(8);

  }
}