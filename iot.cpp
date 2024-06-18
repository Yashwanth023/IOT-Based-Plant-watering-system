include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2); 

// Replace with your network credentials
const char* ssid = "";
const char* password = "";

// Initialize Telegram BOT
#define BOTtoken ""  //  
#define CHAT_ID ""

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

const int relay = 16;
bool ledState = LOW;
#include<dht.h>
#define dht_pin 2
dht DHT;

// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(CHAT_ID, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Use the following commands to control your outputs.\n\n";
      welcome += "/pump_on to turn GPIO ON \n";
      welcome += "/pump_off to turn GPIO OFF \n";
      welcome += "/state to request current GPIO state \n";
      bot.sendMessage(CHAT_ID, welcome, "");
    }

    if (text == "/pump_on") {
      lcd.clear();
      lcd.print("PUMP ON");
      delay(500);
      bot.sendMessage(CHAT_ID, "pump state set to ON", "");
      ledState = HIGH;
      digitalWrite(relay, HIGH);
    }
    
    if (text == "/pump_off") {
      lcd.clear();
      lcd.print("PUMP OFF");
      delay(500);
      bot.sendMessage(chat_id, "pump set to OFF", "");
      ledState = LOW;
      digitalWrite(relay, LOW);
    }
    
    if (text == "/state") {
      if (digitalRead(relay)){
        bot.sendMessage(CHAT_ID, "PUMP is ON", "");
      }
      else{
        bot.sendMessage(CHAT_ID, "PUMP is OFF", "");
      }
    }
  }
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
    client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
   pinMode(relay, OUTPUT);
  digitalWrite(relay, ledState);
  
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PLANT WATERING");
  lcd.setCursor(0,1);
  lcd.print("  SYSTEM  ");
  
   bot.sendMessage(CHAT_ID,"PLANT WATERING SYSTEM");
   digitalWrite(relay,LOW);
}

void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
  Temperature();
  MOISTURE();
}

void Temperature()
{
  DHT.read11(dht_pin);
  Serial.print("HUMIDITY:");
  Serial.print(DHT.humidity);
  Serial.print("%");
  Serial.println(" ");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HUMIDITY:");
  lcd.setCursor(10,0);
  lcd.print(DHT.humidity);
  lcd.setCursor(13,0);
  lcd.print("%");
  bot.sendMessage(CHAT_ID, "Humidity:"+ String(DHT.humidity));
  delay(1000);
  DHT.read11(dht_pin);
  Serial.print("TEMPERATURE:");
  Serial.print(DHT.temperature);
  Serial.print("%");
  Serial.println(" ");
   lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("TEMP:");
  lcd.setCursor(6,1);
  
  lcd.print(DHT.temperature);
  lcd.setCursor(10,0);
  lcd.print("C");
  
  
  bot.sendMessage(CHAT_ID, "Temprature:"+ String(DHT.temperature));
  delay(1000);
 
  
  
  
}

void MOISTURE()
{
  int moistval=analogRead(A0);
  Serial.print("MOIST:");
  Serial.println(moistval);
  bot.sendMessage(CHAT_ID, "Moisture:"+ String(moistval));
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MOIST:");
  lcd.setCursor(7,0);
  lcd.print(moistval);
  
  delay(1000);
}