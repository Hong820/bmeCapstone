#include <WiFiNINA.h>
#include <ThingSpeak.h>


// Ultrasonic sensor pins
const int trigPin = 2;
const int echoPin = 3;


// WiFi credentials
const char* ssid = "URI_BME2.4G";
const char* password = "URIb3m6e1";

WiFiClient client;

// ThingSpeak settings
unsigned long myChannelNumber = 2711389;
// const char* myWriteAPIKey = "CAI8XCLH95E9H4C5";
const char* myWriteAPIKey = "5U24SF1KELOEWI3D";

void setup() {
 Serial.begin(9600);


 // Sensor pin modes
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);


 // Connect to WiFi
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(1000);
   Serial.println("Connecting to WiFi...");
 }
 Serial.println("Connected to WiFi");


 // Initialize ThingSpeak
 ThingSpeak.begin(client);
 // while(ThingSpeak.status() != TL_CONNECTED) {
 //   delay(500);
 //   Serial.println("Connecting to ThingSpeak...");
 // }
 // Serial.println('Connected to ThingSpeak');
}


void loop() {
 // Send a trigger pulse
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);


 // Measure the echo time
 long duration = pulseIn(echoPin, HIGH);
 Serial.print("Duration: ");
 Serial.println(duration);


 // Calculate the distance in cm
 float distance = (duration * 0.0343) / 2;


 // Print the distance to the serial monitor
 Serial.print("Distance: ");
 Serial.println(distance);


 // Send the data to ThingSpeak
 ThingSpeak.setField(1, distance);  // Set the distance value in field 1
 int responseCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);


 if (responseCode == 200) {
  Serial.println("Data sent to ThingSpeak");
} else {
  Serial.println("Failed to send data to ThingSpeak");
}


delay(200);  // Wait 20 seconds
}

