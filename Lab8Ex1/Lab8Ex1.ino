const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte toggle = LOW;
int i=1;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop()
{
  digitalWrite(ledPin, toggle);
  delay(i*1000);
  toggle = !toggle;
}

void blink()
{
  i++;
  if(i>3)
  {
    i = 1;
  }
    
}
