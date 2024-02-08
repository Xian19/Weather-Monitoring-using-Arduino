#include <DHT.h>;
#include <LiquidCrystal.h>; // includes the LiquidCrystal Library 


LiquidCrystal lcd(3, 4, 8, 9, 10, 11); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 

//Constants
const int DHTPIN  = 2;     // what pin we're connected to
const int DHTTYPE = DHT22;   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
}

void loop()
{
  temp= dht.readTemperature();
  lcd.setCursor(1,0);
  lcd.print("Temperature");
  lcd.setCursor(2,8);
  lcd.print(temp);
  lcd.print(" C");
  //lcd.clear(); // Clears the LCD screen 
}
