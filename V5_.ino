 #include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
#define PUMP 4
#define st_pump 7
#define inc 8
#define dec 9
#define photo_sil 12 
#define Buzzer 13

unsigned long time1;
int Timer_pump=0;                         //count_v1er
bool mask_autowork=false;               // Automatic Mode
bool mask_manualwork=false;             // Manual Mode
bool mask_pump=false;                     //Pump
void pump(bool st);                      //pump Fan
unsigned int count=0;                   //Timer_Counter
unsigned long time_counter;             //Counter
unsigned long time_pump=4;                //Valve1

void setup() {
  lcd.init();                     // initialize the lcd 
  lcd.backlight();                // Turn On backlight LCD
  Serial.begin(9600); // Starts the serial communication
  pinMode(PUMP,OUTPUT);          // Pump
  pinMode(Buzzer,OUTPUT);        //Buzzer
  digitalWrite(PUMP,HIGH);       // Stop Pump
  pinMode(st_pump,INPUT);
  pinMode(inc,INPUT);
  pinMode(dec,INPUT);
  pinMode(photo_sil,INPUT);
            logo();
  lcd.clear();
  time_counter=millis();           //Counter
  time_pump=millis();                //Timer pump
  time1=millis();
}

void loop() 
{
  lcdprob();
  lcd.setCursor(7,1);
    lcd.print(String (count));
    lcd.print("                 ");

  start();

 pump_fun();
/* if (mask_autowork=true)
  {
    pump_fun();
  }
 else
  {
    manual_operation_of_valves();
  }*/
  /*if(digitalRead(st_pump)==HIGH)
  {
    while(digitalRead(st_pump)==HIGH);
    counter();
    delay(10);
    digitalWrite(PUMP,LOW);             //Low=High                //Start
    delay(3000);
  }else
  digitalWrite(PUMP,HIGH);        //High=LOW                //Stop*/
  
  control_counter();
  
}
