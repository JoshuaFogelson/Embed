const int BUTTON_PIN = 2; // pushbutton pin
const int PWM_PIN = 9; //pwm pin

double old_value = 0.0;
double value = 0.0;
int button_state = 0;
double probe_value = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON_PIN,INPUT);
  pinMode(PWM_PIN,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //Write out pwm signal (0 - 255)
  analogWrite(PWM_PIN,25);

  //Read from DIO Pin 2 to get status of the button
  button_state = digitalRead(BUTTON_PIN);

  //Read the Analog input A0 to get voltage value of the probe
  probe_value = (5.0/1024)*analogRead(A0);

  //Logic to manipulate Serial Plotter to freeze the screen
  if(button_state = HIGH){
    value = old_value;
  } else {
    value = probe_value;
    Serial.println(value);
  }
  old_value = value;
}
