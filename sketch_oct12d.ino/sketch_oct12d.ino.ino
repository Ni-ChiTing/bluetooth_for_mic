#include  <SoftwareSerial.h>
int mic=A0;
char newline2=10;
char newline1=13;
SoftwareSerial BTSerial(15, 14);
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);  
   BTSerial.begin(9600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("device OK");

}
int micout;
void loop() {
  // put your main code here, to run repeatedly:
  byte out;
  micout=analogRead(mic);
  String s=String(micout) ;
  s=s+"\n";
  Serial.print(s);
  char data[s.length()];
  s.toCharArray(data,s.length());
  for(int i=0;i<sizeof(data);i++)
  {
    BTSerial.write(data[i]);
  }
  BTSerial.write(newline1);
  BTSerial.write(newline2);
}
