void lcdprob()
{
  if(millis()-time1>=4000)
  {
      lcd.init();                      // initialize the lcd 
      time1=millis();
  }
}
