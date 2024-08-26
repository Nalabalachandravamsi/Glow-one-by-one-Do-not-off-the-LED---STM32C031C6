void delay1(int);
void setup() {
  // put your setup code here, to run once:
  volatile unsigned int *config,*set,count,temp;
  config = (volatile unsigned int *)0x50000000;  // Cast to volatile int pointer
  *config = 0x00005555;
  set = (volatile unsigned int *)0x50000018;  // Cast to volatile int pointer
  *set = 0x00000001; 
  temp = 0x00000000;
  count = 0;
  while(1){
    *set = *set | temp;   // set leds
    delay1(2);
    count++;
    temp = 1 << count;
    if(count > 7){
      count = 0;
      *set = 0x00ff0000;   // resetting all leds
      delay1(2);
      *set = 0x00000001;
    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:
}
void delay1(int num){
  volatile int i;
  while(num){
    for(i=0;i<100000;i++);
    num--;
  }
}
