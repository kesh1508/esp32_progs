#include <HardwareSerial.h>

HardwareSerial SerialPort(2);  // use UART2

void setup() {
  // Initialize Serial Monitor (UART0) at 115200 baud rate
  Serial.begin(115200);
  
  // Initialize UART2 with baud rate 15200, 8 data bits, no parity, 1 stop bit, TX on GPIO 16, RX on GPIO 17
  SerialPort.begin(15200, SERIAL_8N1, 16, 17);
}

void loop() {
  // Send '1' over UART2
  SerialPort.print(1);
  delay(5000);  // Wait for 5 seconds
  
  // Send '0' over UART2
  SerialPort.print(0);
  delay(5000);  // Wait for 5 seconds
  
  // Check if data is available on UART2
  while (SerialPort.available() > 0) {
    // Read incoming byte
    int incomingByte = SerialPort.read();
    
    // Print the received byte to the Serial Monitor
    Serial.print("Received: ");
  Serial.println(incomingByte);
  }
}
