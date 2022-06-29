void pump_fun()
{
  if(digitalRead(photo_sil)==HIGH||digitalRead(st_pump)==HIGH)
  { 
    while(digitalRead(photo_sil)==HIGH);
      counter();
      Timer_pump=2;
      mask_pump=true;
      pump(true);
      Serial.println(Timer_pump);
       Serial.println("photo_sil");
      Serial.println(digitalRead(photo_sil));
    }
    if((unsigned long)millis()-time_pump>800&&mask_pump==true)
    {
      if(Timer_pump>0)
      {
        Timer_pump--;
      }
      else if(Timer_pump==0)
      {
        pump(false);
        mask_pump=false;
        
        //delay(2000);
      }
      time_pump=millis();
    }

}
  void pump(bool st)
  {
    if(st==true)
    {
      delay(10);
    digitalWrite(PUMP,LOW);
    }else
    {
    digitalWrite(PUMP,HIGH);
    }
  }
