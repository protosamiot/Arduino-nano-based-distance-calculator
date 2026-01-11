/*
 * Project: Ultrasonic Distance Calculator with 0.96" OLED Display
 * Microcontroller: Arduino Nano
 * Display: 0.96" 128x64 I2C OLED (SSD1306 Driver)
 * Sensor: HC-SR04 Ultrasonic Sensor
 * GitHub: https://github.com/ProtoSamIoT
 * YouTube: https://www.youtube.com/@protosamiot
 * Date: January 11, 2026
 *
 * Description:
 * This code initializes the SSD1306 OLED display (128x64 pixels, I2C address 0x3C or 0x3D) 
 * and the HC-SR04 ultrasonic sensor. It first displays the welcome message 
 * "Distance Calculator by Protem IoT" for a few seconds.
 * It then transitions to a live data screen, continuously measuring the distance 
 * in centimeters and displaying the value prominently on the OLED screen.
 */

#include <SPI.h>       // Needed for some display configurations (though I2C is used)
#include <Wire.h>      // I2C communication library
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_SSD1306.h> // Library for SSD1306 OLED

// --- DISPLAY DEFINITIONS ---
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// Default I2C address is typically 0x3C or 0x3D
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --- SENSOR DEFINITIONS ---
#define TRIG_PIN 10 // Trigger Pin for HC-SR04
#define ECHO_PIN 9  // Echo Pin for HC-SR04

void setup() {
  // Initialize the sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize Serial (Optional, for debugging)
  Serial.begin(9600);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C (or 0x3D)
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  // Display the welcome message
  displayWelcomeScreen();
  delay(3000); // Display for 3 seconds

  // Clear the screen for the main loop
  display.clearDisplay();
  display.display();
}

void loop() {
  long duration;
  float distanceCm;

  // --- 1. Measure Distance ---
  
  // Clear the Trig pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Set the Trig pin high for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the Echo pin, which returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert time to distance (cm)
  // Distance = Duration * 0.0343 / 2
  distanceCm = duration * 0.0343 / 2.0;
  
  // --- 2. Display on OLED ---
  
  displayDistance(distanceCm);

  delay(500); // Update the distance every half second
}

/**
 * @brief Displays the welcome screen with the project title.
 */
void displayWelcomeScreen() {
  display.clearDisplay();
  
  // Set Text Settings
  display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE);

  // Draw a border for an interesting look
  display.drawRect(0, 0, display.width(), display.height(), SSD1306_WHITE);
  
  // Title Text: "Distance Calculator"
  display.setCursor(5, 10);
  display.setTextSize(2); // Large text for the main title
  display.println(F("DISTANCE"));
  
  display.setCursor(5, 28);
  display.setTextSize(2);
  display.println(F("CALCULATOR"));
  
  // Subtitle/Author Text
  display.setCursor(15, 52);
  display.setTextSize(1);
  display.println(F("by PROTOSAMIOT"));
  
  display.display(); // Show the splash screen
}

/**
 * @brief Updates the main screen with the current distance reading.
 * @param distanceCm The measured distance in centimeters.
 */
void displayDistance(float distanceCm) {
  display.clearDisplay();
  
  // --- Header Text ---
  display.setCursor(5, 5);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.println(F("Distance Reading:"));
  
  // --- Distance Value Display ---
  
  display.setCursor(5, 25);
  display.setTextSize(4); // Very large text for the main reading
  
  // Print distance with one decimal place
  display.print(distanceCm, 1); 
  
  // Print the units (cm) next to the number
  display.setCursor(display.getCursorX() + 5, 40); // Move cursor to the right and slightly up
  display.setTextSize(1);
  display.println(F("cm"));
  
  display.display(); // Update the screen
}