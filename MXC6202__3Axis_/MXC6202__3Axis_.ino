//2016_3.16 mariko original
//↓mxc6202 datasheet
//https://www.dropbox.com/s/j13ehxiy3l070rp/MXC6202.pdf

#include <Wire.h>

#define MXC6202 0x15

unsigned int readRegister(byte reg){
 Wire.beginTransmission(MXC6202) ;
 Wire.write(reg);
 Wire.endTransmission();

 Wire.requestFrom(MXC6202,5);
 return Wire.read();
}

void writeRegister(byte reg,byte data){
  Wire.beginTransmission(MXC6202);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

void setup(){
  Wire.begin();
  Serial.begin(9600);

  writeRegister(0x00,0x00);
  int res = readRegister(0x0F);
  Serial.println(res);
}

void loop(){
  int a = 0;
  
  int x = 0;
  int y = 0;

  int i = 0;
  
  int MSB = 0;
  int LSB = 0;
  int iAccReal[0x02];
  int iAccFilter;

  
  if (abs(iAccReal[0x00]-iAccReal[0x01])<0x80){
    iAccFilter = iAccReal[0x00];
    iAccReal[0x01] = iAccReal[0x00];
  
    writeRegister(0x00,0x00);

    for(i=0;i<5;i++){
      //read X
      LSB = readRegister(0x02);
      MSB = readRegister(0x01);
      x = x + (MSB << 8 | LSB);

      //read Y
      LSB = readRegister(0x04);
      MSB = readRegister(0x03);
      y = y + (MSB << 8 | LSB);
    }
    x = x / 5  - 2048;
    y = y / 5  - 2048;

    Serial.print("x=");
    Serial.print(x);
    Serial.print(",");
    Serial.print("y=");
    Serial.println(y);

    }
    delay(1000);
}



