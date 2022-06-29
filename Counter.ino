void counter()
{
  if(millis()-time_counter>=1500)
   {
    time_counter=millis();
          count++;
    lcd.setCursor(7,1);
    lcd.print(String (count));
    lcd.print("                 ");
         delay(10);
    digitalWrite(Buzzer, HIGH);
    delay (200);
    digitalWrite(Buzzer, LOW);
    delay (100);
   }
}
