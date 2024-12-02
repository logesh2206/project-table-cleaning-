char a = '0';

void setup()
{
    pinMode(2, OUTPUT); // cleaner on or off
    pinMode(4, OUTPUT); // dustbin open or close
    pinMode(5, INPUT);  // ir sensor input
    Serial.begin(9600);
}

void loop()
{
    int irState = digitalRead(5);

    if (irState == HIGH)
    {
        Serial.println("No person detected");
        delay(1000);
        if (a == '1')
        {
            // Customer has left, initialize cleaning
            Serial.println("Initializing cleaning");
            delay(1000);
            digitalWrite(2, HIGH);
            digitalWrite(4, HIGH);
            a = '0';
        }
    }
    else
    {
        Serial.println("Person present");
        delay(1000);
        if (a == '0')
        {
            // Customer has arrived, set flag
            a = '1';
        }
    }
}