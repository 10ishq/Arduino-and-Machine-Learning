// Defining Variables
const int trigPin = 9; // Pin connected to Trig pin of HC-SR04
const float increment = 0.1;  // Amount to increment in each successive step
const int echoPin = 10;  // Pin of sensor wich will send pulse in microseconds.
long duration; //will store duration of pulse.
int i = 0; // This Variable will control number of readings taken taken.
void setup() {
pinMode(13, OUTPUT);  // Indicator LED
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
  for (float j=5.0; j<=12.3;)
  {
    
    Serial.println(0+j); // Prints the Distance at which next 1,000 readings will be taken.
    
  
  for(i ;i<=1199;i++)
    {
        digitalWrite(trigPin, LOW);
                                // Clears the trigPin

        delayMicroseconds(2);
                              // Sets the trigPin on HIGH state for 10 micro seconds
    
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);     // Turning on Trig pin for 10 microseconds sends the ultrasonic sound.
        digitalWrite(trigPin, LOW);

    
       duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds


       if (i>199)
         {
          Serial.println(duration); // If number of readings taken exceeds 200 then start sending output on serial port.(through observation: some of initial readings are garbage)
          }


    

    }
    i=0;  // Resetting i for taking next 1000 readings

    digitalWrite(13, HIGH); // Led indication to increment the distance.
    delay(3000);  // Waits 3 seconds for user to increment the distance
    digitalWrite(13, LOW);
    j=j+increment; // Incriments the distance for next 1000 readings
  }
}
