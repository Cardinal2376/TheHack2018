//TEST
#include <Adafruit_NeoPixel.h>
 
#define PIN 6
#define PINR 5
#define MAX_LED 60 
#define ADD true
#define SUB false
 
int val = 0;
boolean stat = ADD;
 
// Parameter 1 = ws2811级联数量
// Parameter 2 = arduino PIN
// Parameter 3 = pixel type flags, add together as needed:
// NEO_KHZ800 800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_KHZ400 400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
// NEO_GRB Pixels are wired for GRB bitstream (most NeoPixel products)
// NEO_RGB Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel( MAX_LED, PIN, NEO_RGB + NEO_KHZ800 );
Adafruit_NeoPixel strip_r = Adafruit_NeoPixel(MAX_LED, PINR, NEO_RGB + NEO_KHZ800 );
int direct = 3;


String comdata = ""; //String 定义一个空的字符串  a
int STATE=1;  
int pinBuzzer = 8; //管脚D3连接到蜂鸣器模块的信号脚


void setup()
{
  Serial.begin(9600);
  strip.begin();           //初始化Adafruit_NeoPixel；
  strip.show();           //显示所有LED为关状态;
  strip_r.begin();
  strip_r.show();
  pinMode(13,OUTPUT);  
  pinMode(pinBuzzer, OUTPUT); //设置pinBuzzer脚为输出状态
}

void fm_loop() { 
   long frequency = 1300; //频率, 单位Hz
 
   //用tone()函数发出频率为frequency的波形
   tone(pinBuzzer, frequency );
   delay(500); //等待1000毫秒
   
   noTone(pinBuzzer);//停止发声
}



void lightloop()
{
  uint8_t i,a=0, pos;                    
  uint8_t sel1 = 0, sel2 = 0;                    
  uint32_t color = strip.Color(0, 255, 123);         //选择所显示的颜色
  uint32_t color_r = strip_r.Color(0, 255, 123);
  while(a<60)
  {
      if(direct == 0) {
        for(i=0;i<60;i++){
          color = strip.Color(0, 255, 0);
          if(a % 2 == 0)strip.setPixelColor(i, color);     //第几个LED点亮;
          else strip.setPixelColor(i, 0);
          if(a % 2 == 0)strip_r.setPixelColor(i, color);     //第几个LED点亮;
          else strip_r.setPixelColor(i, 0);
        }
        strip.show();
        strip_r.show();
        delay(10);
        //fm_loop();
        a++;
        continue;
      }
      if(direct == 1) {
        sel1 = a % 60;
        sel2 = a % 60;
      } else if(direct == 2) {
        sel1 = (60 - a % 60) % 60;
        sel2 = a % 60;
      } else if(direct == 3) {
        sel1 = a % 60;
        sel2 = (60 - a % 60) % 60;
      } else if(direct == 4) {
        sel1 = (60 - a % 60) % 60;
        sel2 = (60 - a % 60) % 60;
      }
      for(i=0;i<60;i++)
      {
        color = strip.Color(i % 255 + 100, 255, i % 255);
        if(i==sel1) strip.setPixelColor(i, color);     //第几个LED点亮;
        else strip.setPixelColor(i, 0);             //使其他LED全灭;
        if(i==sel2) strip_r.setPixelColor(i, color_r);     //第几个LED点亮;
        else strip_r.setPixelColor(i, 0);             //使其他LED全灭;
        //strip.setPixelColor(i, 0);
        //strip_r.setPixelColor(i, 0);
      }
       strip.show();                                //是LED显示所选的颜色;
       strip_r.show();
       delay(10);                                   //延时200ms；
       a++;                                         
  }
}



void loop()  
{  
    char input_num;
    if(Serial.available() > 0)    
    {  
        input_num = char(Serial.read());
        Serial.println(input_num);  
        direct = input_num - '0';
        STATE=!STATE;  
        digitalWrite(13,STATE);    //通过电平反转可直观看出程序的运行。  
    }
    //loop2();
    lightloop();
} 


