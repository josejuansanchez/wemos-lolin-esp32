#include <WiFi.h>
#include <SSD1306.h>

SSD1306  display(0x3c, 5, 4);

const char* ssid     = "your-ssid";
const char* password = "your-password";

void setup() {
  Serial.begin(115200);
  
  display.init();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);  

  Serial.print("Connecting to: " + String(ssid));
  display.drawStringMaxWidth(0, 0, 128, "Connecting to: " + String(ssid));
  display.display();

  WiFi.begin(ssid, password);

  int progress = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    display.drawProgressBar(0, 32, 120, 10, progress++);
    display.display();
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: " + WiFi.localIP());

  display.clear();
  display.drawString(0, 0, "WiFi connected");
  display.drawString(0, 10, "IP address: " + WiFi.localIP().toString());
  display.display();
}

void loop() {
}

