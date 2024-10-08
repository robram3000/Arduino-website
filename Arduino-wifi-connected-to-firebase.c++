#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

String data;
FirebaseConfig config;
FirebaseAuth auth;

const char* ssid = ""; 
const char* password = ""; 


FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");
  Serial.println(WiFi.localIP());


  config.host = "arduinotofirebase-d65c5-default-rtdb.firebaseio.com/"; 
  config.api_key = "AIzaSyAunMT08LY13RUJLt7eL9cxAJTsUK4BF_c"; 

  auth.user.email = "parleroalbertpalma@gmail.com";  
  auth.user.password = "Ezekiel16";  

  Serial.println("Initializing Firebase...");
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true); 
  Serial.println("Firebase initialized");

  if (Firebase.ready()) {
    Serial.println("Connected to Firebase");
  } else {
    Serial.println("Failed to connect to Firebase");
  }
}

void loop() {
  Serial.println("Sending Data");

  data = "Connected"; 

 
  if (Firebase.setString(firebaseData, "/random/option1", data)) {
    Serial.println("Data successfully sent to Firebase.");
  } else {
    Serial.println("Failed to send Data");
    Serial.println(firebaseData.errorReason());
  }
  delay(10000); 
}