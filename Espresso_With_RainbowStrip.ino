/*
  Lots of code borrowed from CheerLights & Adafruit
  Cheerlights - http://www.cheerlights.com
  ThingSpeak - https://www.thingspeak.com

  Credits goes to Marc de Vink (Adafruit) and the original creator of CheerLights, Hans Scharler.
*/

#include <ESP8266WiFi.h> 
#include "ThingSpeak.h" // Include the ThingSpeak library
#include <Adafruit_NeoPixel.h> // Include the adafruit Neopixel Library

#define PIN            2 // What pin is the data being sent to the RainbowStrip
#define NUMPIXELS      30 // Number of RainbowBit

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // Set up the RainbowStrip
int delayval = 500; // delay for half a second

WiFiClient  client;

const char* ssid     = "you_wifi_network"; // Enter your WiFi network name
const char* password = "Wifi_Password"; // Enter your WiFi password
const char* host = "api.thingspeak.com";
unsigned long cheerLightsChannelNumber = 1417; // The channel of Cheerlights


void setup() {

  pixels.begin(); 

  Serial.begin(115200); // Get ready for serial communications and display the connetion status 
  delay(100);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to WiFi network -  ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
}

String colorName[] = {"none", "red", "pink", "green", "blue", "cyan", "white", "warmwhite", "oldlace", "purple", "magenta", "yellow", "orange"}; // List of CheerLights color names

int colorRGB[][3] = {     0,  0,  0,  // "none"  // Map of RGB values for each of the Cheerlight color names
                          255,  0,  0,  // "red"
                          255, 192, 203, // "pink"
                          0, 255,  0, // "green"
                          0,  0, 255, // "blue"
                          0, 255, 255, // "cyan",
                          255, 255, 255, // "white",
                          255, 223, 223, // "warmwhite",
                          255, 223, 223, // "oldlace",
                          128,  0, 128, // "purple",
                          255,  0, 255, // "magenta",
                          255, 255,  0, // "yellow",
                          255,165,  0}; // "orange"};
                        

void loop() {

  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
  String url = "/channels/1417/field/1/last.json"; //from Thingspeak
  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  delay(500); // Just a quick pause to let everything settle
  String color = ThingSpeak.readStringField(cheerLightsChannelNumber, 1); //Read the Cheerlight color and print to the serial monitor
  Serial.println(color);
  setColor(color);
  delay(18000);
}

void setColor(String color)
{
  // Look through the list of colors to find the one that was requested
  for (int iColor = 0; iColor <= 13; iColor++)
  {
    if (color == colorName[iColor])
    {

      pixels.setPixelColor(0, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(1, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(2, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(3, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(4, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(5, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(7, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(8, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(9, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(10, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(11, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(12, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding) 
      pixels.setPixelColor(13, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(14, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(15, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(16, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(17, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(18, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(19, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(20, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(21, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(22, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(23, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(24, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(25, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(26, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(27, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(28, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 1 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(29, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 2 color (kept them seperate for easy hacking & understanding)
      pixels.setPixelColor(30, pixels.Color (colorRGB[iColor][0], colorRGB[iColor][1], colorRGB[iColor][2])); // set pixel 3 color (kept them seperate for easy hacking & understanding) 
     
      /////There are 30 lines because it has 30rainbowbits mounted together in one line.
     
      pixels.show(); // This sends the updated pixel color to the hardware.

      delay(delayval); // Delay for a period of time (in milliseconds).

    }
  }
}
