void control_counter()
{
//increment
  if(digitalRead(inc)==HIGH)
  {
    delay(10);
    digitalWrite(Buzzer, HIGH);
    delay (100);
    digitalWrite(Buzzer, LOW);
    delay (100);
    count++; 
    delay (100);
  }

//Decrement
  if(digitalRead(dec)==HIGH)
  {
    delay(10);
    digitalWrite(Buzzer, HIGH);
    delay (100);
    digitalWrite(Buzzer, LOW);
    delay (100);
    count--; 
    delay (100);
  }
}
