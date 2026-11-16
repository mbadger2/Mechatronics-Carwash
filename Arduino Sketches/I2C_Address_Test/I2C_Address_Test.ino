
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD addresses (w/ GND connections)
LiquidCrystal_I2C lcd1(0x27, 16, 2); // 
LiquidCrystal_I2C lcd2(0x26, 16, 2); // A0
LiquidCrystal_I2C lcd3(0x25, 16, 2); // A1
LiquidCrystal_I2C lcd4(0x23, 16, 2); // A2
LiquidCrystal_I2C lcd5(0x21, 16, 2); // A2 A1

void setup() {
  // Initialize LCDs
  lcd1.init();
  lcd2.init();
  lcd3.init();
  lcd4.init();
  lcd5.init();

  // Enable backlights
  lcd1.backlight();
  lcd2.backlight();
  lcd3.backlight();
  lcd4.backlight();
  lcd5.backlight();

  // Display sentence across four screens
  lcd1.setCursor(0, 0);
  lcd1.print("Mitch");

  lcd2.setCursor(0, 0);
  lcd2.print("Has");

  lcd3.setCursor(0, 0);
  lcd3.print("Successfully");

  lcd4.setCursor(0, 0);
  lcd4.print("Tested");

  lcd5.setCursor(0, 0);
  lcd5.print("Screens");
}

void loop() {
}
