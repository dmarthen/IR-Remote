#include <IRremote.h>;
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
int red = 9;
int green = 10;
int blue = 11;
int stateLed[] = {0,0,0};
#define codered 48703
#define codegreen 58359
#define codeblue 539

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  if(irrecv.decode(&results)){
    unsigned int value = results.value;
    switch(value) {
      case codered:
        if(stateLed[0]==1){
          digitalWrite(red, LOW);
          stateLed[0]=0;
        } else {
          digitalWrite(red, HIGH);
          stateLed[0]=1;
        }
        break;
      case codegreen:
        if(stateLed[1]==1){
          digitalWrite(green, LOW);
          stateLed[1]=0;
        } else {
          digitalWrite(green, HIGH);
          stateLed[1]=1;
        }
        break;
      case codeblue:
        if(stateLed[2]==1){
          digitalWrite(blue, LOW);
          stateLed[2]=0;
        } else {
          digitalWrite(blue, HIGH);
          stateLed[2]=1;
        }
        break;
    }
    Serial.println(value);
    irrecv.resume();
  }
}
