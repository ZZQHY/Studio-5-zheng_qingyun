// CONNECTIONS:
// DS1302 CLK/SCLK --> 5
// DS1302 DAT/IO --> 4
// DS1302 RST/CE --> 2
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND
// LED1_Module --> PIN9 --> Fire Fly 18:00pm-21:00pm
// LED2_Module --> PIN10
// Heating_Module --> Pin3 --> Morning Glory 4:00am-12:00pm
// Vibration_Module*3 (from left to right) --> A5 / PIN11 / PIN6 --> 12:00 am - 2:00 am (Midnight) and 12:00 pm - 2:00 pm (Noon)
// 5 LED (from left to right) --> A0-A4 --> 6:00-8:24 / 8:25-10:48 / 10:49-13:12 / 13:13-15:36 / 15:37-18:00
// Button - PIN7 

#include <RtcDS1302.h>

ThreeWire myWire(4, 5, 2);  // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

int buttonPin = 7; //Button模式切换
int buttonState = 0; 
bool b1 = false; 

int ledPin_0 = A0;  //时间LED，从左到右
int ledPin_1 = A1;
int ledPin_2 = A2;
int ledPin_3 = A3;
int ledPin_4 = A4;

int ledPin_Module_1 = 9;   //LED1模块的引脚
int ledPin_Module_2 = 10;  //LED2模块的引脚

int Vib_Module_1 = A5;  //震动模块，A5为持续缓慢震动；6、11为模拟输出
int Vib_Module_2 = 11;  //6、11为模拟输出
int Vib_Module_3 = 6;

int Heat_Module = 3;  //加热模块

//设定模式切换的逻辑
void keyScan(){
  if (digitalRead(buttonPin) == HIGH){
    delay(5);
    if (digitalRead(buttonPin) == HIGH){
      b1 = !b1;
      while (digitalRead(buttonPin) == HIGH);
    }
  }
}

void setup() {
  Serial.begin(57600);

  pinMode(buttonPin, INPUT);

  pinMode(ledPin_0, OUTPUT);  //显示时间的LED引脚定义
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  pinMode(ledPin_4, OUTPUT);

  pinMode(ledPin_Module_1, OUTPUT);  //输出模块引脚定义
  pinMode(ledPin_Module_2, OUTPUT);

  pinMode(Vib_Module_1, OUTPUT);
  pinMode(Vib_Module_2, OUTPUT);
  pinMode(Vib_Module_3, OUTPUT);

  pinMode(Heat_Module, OUTPUT);

  Serial.print("compiled: ");
  Serial.print(__DATE__);
  Serial.println(__TIME__);

  Rtc.Begin();
  //初始化，通过电脑获取并设定当前时间
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  printDateTime(compiled);
  Serial.println();

  if (!Rtc.IsDateTimeValid()) {
    // Common Causes:
    //    1) first time you ran and the device wasn't running yet
    //    2) the battery on the device is low or even missing

    Serial.println("RTC lost confidence in the DateTime!");
    Rtc.SetDateTime(compiled);
  }

  if (Rtc.GetIsWriteProtected()) {
    Serial.println("RTC was write protected, enabling writing now");
    Rtc.SetIsWriteProtected(false);
  }

  if (!Rtc.GetIsRunning()) {
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }

  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled) {
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(compiled);
  } else if (now > compiled) {
    Serial.println("RTC is newer than compile time. (this is expected)");
  } else if (now == compiled) {
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();

  printDateTime(now);
  Serial.println();

  if (!now.IsValid()) {
    // Common Causes:
    //    1) the battery on the device is low or even missing and the power line was disconnected
    Serial.println("RTC lost confidence in the DateTime!");
  }
  delay(1000);  // ten seconds

  keyScan();
  if (b1 == true) {
    Serial.println("Now is MUL Mode");
    digitalWrite(ledPin_0, LOW); 
    digitalWrite(ledPin_1, LOW);
    digitalWrite(ledPin_2, LOW);
    digitalWrite(ledPin_3, LOW);
    digitalWrite(ledPin_4, LOW);

    //FireFly时间，两个LED模块，18:00pm-21:00pm
    if (now.Hour() >= 18 && now.Hour() <= 21) {
      Serial.println("LED Module is working");
      for (int i = 10; i <= 255; i++) {
        analogWrite(ledPin_Module_1, i);
        analogWrite(ledPin_Module_2, i);
        delay(1);
      }
      for (int i = 255; i >= 10; i--) {
        analogWrite(ledPin_Module_1, i);
        analogWrite(ledPin_Module_2, i);
        delay(1);
      }
    } 

    //牵牛花时间，加热模块，4:00am-12:00pm
    if (now.Hour() >= 4 && now.Hour() <= 12) {
      Serial.println("Heating Module is working");
      analogWrite(Heat_Module, 255);
    }

    //潮汐时间，12:00 am - 2:00 am (Midnight) and 12:00 pm - 2:00 pm (Noon)
    if (now.Hour() >= 1 && now.Hour() <= 2 || now.Hour() >= 13 && now.Hour() <= 14) {
      
      for (int i = 0; i <= 255; i++) {
        analogWrite(Vib_Module_2, i);
        analogWrite(Vib_Module_3, i);
      }
      for (int i = 255; i >= 20; i--) {
        analogWrite(Vib_Module_2, i);
        analogWrite(Vib_Module_3, i);
      }
    }  
  }

  if (b1 == false){
    Serial.println("Now clock mode");
    analogWrite(ledPin_Module_1, 0);
    analogWrite(ledPin_Module_2, 0);
    analogWrite(Heat_Module, 0);
    digitalWrite(Vib_Module_1, 0);
    analogWrite(Vib_Module_2, 0);
    analogWrite(Vib_Module_3, 0);
    
    //以下代码为按钮按键前，正面时钟LED的显示：
    //A0-A4 --> 6:00-8:24 LED0 / 8:25-10:48 LED1 / 10:49-13:12 LED2 / 13:13-15:36 LED3 / 15:37-18:00 LED4
    RtcDateTime six_am = RtcDateTime(now.Year(), now.Month(), now.Day(), 6, 0, 0); //6:00
    RtcDateTime eight_24 = RtcDateTime(now.Year(), now.Month(), now.Day(), 8, 24, 0); //8:24

    if (now >= six_am && now <= eight_24) {
      digitalWrite(ledPin_0, HIGH);
    }

    RtcDateTime eight_25 = RtcDateTime(now.Year(), now.Month(), now.Day(), 8, 25, 0); //8:25
    RtcDateTime ten_48 = RtcDateTime(now.Year(), now.Month(), now.Day(), 10, 48, 0); //10:48

    if (now >= eight_25 && now <= ten_48) {
      digitalWrite(ledPin_0, LOW);
      digitalWrite(ledPin_1, HIGH);
    }

    RtcDateTime ten_49 = RtcDateTime(now.Year(), now.Month(), now.Day(), 10, 49, 0); //10:49
    RtcDateTime thirteen_12 = RtcDateTime(now.Year(), now.Month(), now.Day(), 13, 12, 0); //13:12

    if (now >= ten_49 && now <= thirteen_12) {
      digitalWrite(ledPin_1, LOW);
      digitalWrite(ledPin_2, HIGH);
    }

    RtcDateTime thirteen_13 = RtcDateTime(now.Year(), now.Month(), now.Day(), 13, 13, 0); //13:13
    RtcDateTime fifteen_36 = RtcDateTime(now.Year(), now.Month(), now.Day(), 15, 36, 0); //15:36

    if (now >= thirteen_13 && now <= fifteen_36) {
      digitalWrite(ledPin_2, LOW);
      digitalWrite(ledPin_3, HIGH);
    }

    RtcDateTime fifteen_37 = RtcDateTime(now.Year(), now.Month(), now.Day(), 15, 37, 0); //15:37
    RtcDateTime eighteen_pm = RtcDateTime(now.Year(), now.Month(), now.Day(), 18, 0, 0); //18:00

    if (now >= fifteen_37 && now <= eighteen_pm) {
      digitalWrite(ledPin_3, LOW);
      digitalWrite(ledPin_4, HIGH);
    }

    RtcDateTime twentythree_59 = RtcDateTime(now.Year(), now.Month(), now.Day(), 23, 59, 0); //23：59
    RtcDateTime zero_1 = RtcDateTime(now.Year(), now.Month(), now.Day(), 0, 1, 0); //）0：01

    //下午6点之后到上午6点之前，显示浅光
    if (now > eighteen_pm && now < twentythree_59 || now > zero_1 && now < six_am) {
      analogWrite(ledPin_Module_1, 50);
      analogWrite(ledPin_Module_2, 50);
    }
  }
}
#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt) {
  char datestring[26];

  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Month(),
             dt.Day(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second());
  Serial.print(datestring);
}
