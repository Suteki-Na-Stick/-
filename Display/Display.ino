#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 10, 5, 4, 3, 2);

void setup()
{
lcd.begin(16, 2);           // 16文字,2行
lcd.clear();                // 初期化

// 文字の書き出し開始地点を指定 
//lcd.setCursor(?文字目,?行目(-1))
lcd.setCursor(0, 0);        // 1(0)文字目1(0)行目1  1 000000000000000000000
lcd.print("1234567890123456");            // 1(0)文字目2(1)行目
lcd.setCursor(0, 1);
lcd.print("1234567890123456");
}

void loop() {}
