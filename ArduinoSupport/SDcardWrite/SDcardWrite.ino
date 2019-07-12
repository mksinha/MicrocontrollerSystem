#include <SD.h>
#include <SPI.h>
#include <SoftwareSerial.h>

int CS_PIN = 4;
File file;
SoftwareSerial com(3, 2);

void setup()
{
  com.begin(4800);
  initializeSD();
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  createFile("acc3.txt");
  writeToFile("ax,ay,az");
}

void loop()
{
  mainThread();
}

void mainThread()
{
  int x = 0, y = 0, z = 0;
  int a = 0, b = 0, c = 0;
  int r = 0;
  while (a < 3 || b < 3 || c < 3)
  {
    while (!com.available());
    r = com.read();
    // Serial.println(r, BIN);
    if ((r & 0b11100000) == 0b01000000) { x += (r & 0b00011111);      a += 1; } 
    if ((r & 0b11100000) == 0b01100000) { x += (r & 0b00011111) << 5; a += 2; } 
    if ((r & 0b11100000) == 0b10000000) { y += (r & 0b00011111);      b += 1; } 
    if ((r & 0b11100000) == 0b10100000) { y += (r & 0b00011111) << 5; b += 2; } 
    if ((r & 0b11100000) == 0b11000000) { z += (r & 0b00011111);      c += 1; } 
    if ((r & 0b11100000) == 0b11100000) { z += (r & 0b00011111) << 5; c += 2; } 
    if (r == 0b00001111) { a = 0; b = 0; c = 0; }
    if (r == 0b00111111) { writeToFile("completed"); closeFile(); digitalWrite(LED_BUILTIN, HIGH); while(1); }
  }
  if (a != 3 || b != 3 || c != 3) return;
  writeToFile(String(String(x) + "," + String(y) + "," + String(z)));
}

void initializeSD()
{
//  Serial.println("Initializing SD card...");
  pinMode(CS_PIN, OUTPUT);
  if (SD.begin())
  {
//    Serial.println("SD card is ready to use.");
  } else
  {
//    Serial.println("SD card initialization failed");
    return;
  }
}

int createFile(String filename)
{
  file = SD.open(filename, FILE_WRITE);
  if (file)
  {
//    Serial.println("File created successfully.");
    return 1;
  } else
  {
//    Serial.println("Error while creating file.");
    return 0;
  }
}
int writeToFile(String text)
{
  if (file)
  {
    file.println(text);
//    Serial.print("Writing to file: ");
//    Serial.println(text);
    return 1;
  } else
  {
//    Serial.println("Couldn't write to file");
    return 0;
  }
}
void closeFile()
{
  if (file)
  {
    file.close();
//    Serial.println("File closed");
  }
}
int openFile(String filename)
{
  file = SD.open(filename);
  if (file)
  {
//    Serial.println("File opened with success!");
    return 1;
  } else
  {
//    Serial.println("Error opening file...");
    return 0;
  }
}
String readLine()
{
  String received = "";
  char ch;
  while (file.available())
  {
    ch = file.read();
    if (ch == '\n')
    {
      return String(received);
    }
    else
    {
      received += ch;
    }
  }
  return "";
}
