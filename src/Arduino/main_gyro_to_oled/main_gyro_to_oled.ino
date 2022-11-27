//Author Romuald BELLION
//Date 27NOV 2022


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> // OLED

#include <basicMPU6050.h> //GYRO


#define WIRE Wire
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &WIRE);

// Create instance
basicMPU6050<> imu;

void setup() {
  // Set registers GYRO
  imu.setup();
  // put your setup code here, to run once:
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Initialisation\n");
  display.println("Get GY521");
  display.setCursor(0,0);
  display.display(); // actually display all of the above

}

void loop() {
  delay(500);
  // Clear the buffer.
  display.clearDisplay();
  display.display();

  //AFFICHE
  display.setCursor(0,0);
  display.print("G X=");
  display.println(imu.rawGx());
  display.print("G Y=");
  display.println(imu.rawGy());
  display.print("G Z=");
  display.println(imu.rawGz());
  display.print("temperature=");
  display.println(imu.rawTemp());
      
  // put your main code here, to run repeatedly:
 /*
  
  //-- Raw output:
  // Accel
  Serial.print( imu.rawAx() );
  Serial.print( " " );
  Serial.print( imu.rawAy() );
  Serial.print( " " );
  Serial.print( imu.rawAz() );
  Serial.print( "    " );
  
  // Gyro
  Serial.print( imu.rawGx() );
  Serial.print( " " );
  Serial.print( imu.rawGy() );
  Serial.print( " " );
  Serial.print( imu.rawGz() );
  Serial.print( "    " ); 
  // Temperature
  Serial.print( imu.rawTemp() );
  Serial.println();  
  */
  

  delay(10);
  yield();
  display.display();

}
