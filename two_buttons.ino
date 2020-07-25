//code for part three of my arduino tutorial: https://lacklusterstudios.blogspot.com/2020/07/arduino-tutorial-two-buttons.html
//when you press push button 1 the LED lights up and stays on. when you press button 2 the LED switches off.
//licensed under GPL 3.0
//Author: chris nichols (github/rteturn5)


#define LEDPIN 4       //pin which is connected to the LED
#define ON_BTTN  8    //pin which is connected to the pushbutton 1
#define OFF_BTTN 12  //pin which is connected to pushbutton 2
bool reset  = false; //holds whether to turn off the LED or not.

void setup() {
 pinMode(LEDPIN,OUTPUT);  //set pin to output a signal
 pinMode(ON_BTTN,INPUT);  //set pin to be receive input signal
 pinMode(OFF_BTTN,INPUT);  //set pin to be receive input signal
}

void loop() {
  if(digitalRead(OFF_BTTN) == HIGH) {
    reset = true;
  }
  if(digitalRead(ON_BTTN) == HIGH && reset == false) { //if button 1 is pressed
    digitalWrite(LEDPIN,HIGH);  //set the output to HIGH on LEDPIN
  }
  else if(reset == true ) {     //if button 2 was pressed
    digitalWrite(LEDPIN,HIGH);   //set output to LOW on LEDPIN
    delay(1000);
    digitalWrite(LEDPIN,LOW);   //set output to LOW on LEDPIN
    reset = false;           //reset is returned to a value of false
  }
}
