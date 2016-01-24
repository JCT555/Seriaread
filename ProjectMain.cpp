
#include "ProjectMain.h"

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int BT_x;
void setup() {
	Serial.begin(57600);
}

void loop() {
	delay(10);
	if (stringComplete) {
		Serial.println("BT_x");
		Serial.println(BT_x);

		stringComplete = false;
	}
}

void serialEvent() {
	while (Serial.available()) {
		char h=Serial.read();
		if(h=='x')
		{
			char str[]="";
			char b=0;
			int i=0;

			while(b!=';')
			{
				Serial.print("b");
				Serial.println(b);
				

				b=Serial.read();
				if(b!=-1)
				{
					str[i]=b;
					i++;
				}
			}
			BT_x=atoi(str)  ;
		}
		
		stringComplete=true;
	}
}

