char a = '0';
void setup()
{
    pinMode(2, OUTPUT); // cleaner on or off
    pinMode(4, OUTPUT); // dustbin open or close
    pinMode(23, INPUT); // ir sensor input
    Serial.begin(9600);
}
void loop()
{
    digitalWrite(2, LOW);
    Serial.println("Seated");
    delay(10000);
    if (digitalRead(23) == LOW)
    {
        digitalWrite(2, LOW);
        a = '1';
        Serial.println(a);
        loop();
    }
    if (a == '1' && digitalRead(23) == HIGH)
    {
        Serial.println("intilizing cleaning ");
        digitalWrite(2, HIGH);
        digitalWrite(4, HIGH);
        a = '0';
        Serial.println(a);
    }
}