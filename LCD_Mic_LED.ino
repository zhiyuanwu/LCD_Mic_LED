/*
  SerialDisplay.ino
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Author:Loovee
  2013-9-18

  Grove - Serial LCD RGB Backlight demo.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int t;
String temp;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
  t = 0;
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available())
  {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0)
    {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
  t = analogRead(A3);
  Serial.print(t);
  String space = "  ";
  Serial.print(space);
  lcd.clear();
  temp = String(t);
  Serial.println(temp);
  lcd.print("Noise Level:"+temp);

  if (t <= 350) { 
    lcd.setRGB(0, 255, 0);
  }else if (t>350&& t <= 450) {
    lcd.setRGB(255, 255, 0);
  }else if (t>450) {
    lcd.setRGB(255, 0, 0);
  }

  delay(300);


}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
