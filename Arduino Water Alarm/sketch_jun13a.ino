#define DH1 523

//列出全部D调的频率
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
//根据简谱列出各频率 
int tune[] = {DH1,DH1,DH1,DH1};
//根据简谱列出各节拍
float duration[]={1,0.5,0.5,1,};
int length;
int temp,data;
int beep = 8; //定义蜂鸣器接口为数字8接口
int water = 4;//定义水位传感器接口为数字4接口

void setup() {
  Serial.begin(9600);
  pinMode(beep, OUTPUT); //定义beep 为输出接口
  pinMode(water, INPUT);
  length=sizeof(tune)/sizeof(tune[0]);   //计算长度
}

void loop() {
  temp = digitalRead(water);
 // data=(temp/650)*4;
  //Serial.print("the depth is:"+data+"cm");
  Serial.print(temp);
  if(temp == 1){
    //digitalWrite(beep, HIGH);
     for(int x=0;x<length;x++)
  {
    tone(beep,tune[x]);//此函数依次播放tune序列里的数组，即每个音符
    delay(500*duration[x]);//每个音符持续的时间，即节拍duration，500是调整时间的越大，曲子速度越慢，越小曲子速度越快
    noTone(beep);//停止当前音符，进入下一音符
  }
  delay(100);//等待100后，循环重新开始
  }
  else{ 
     digitalWrite(beep, LOW);
   }
 delay(100);
}
