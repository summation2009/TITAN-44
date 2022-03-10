// Reads a button attached to a MCP23XXX pin.

// both included here to make things simple for example
#include <Adafruit_MCP23X17.h>

Adafruit_MCP23X17 mcp;    // ประกาศตัวแปรออปเจ็ค สำหรับใช้งาน MCP23017

#define ON HIGH
#define OFF LOW

void setup() {
  Serial.begin(9600);     // กำหนดบอดเรท Serial port สำหรับดูค่าผ่าน Serial monitor;
  
  Serial.println("MCP23xxx Button Test!");

  if (!mcp.begin_I2C()) {               // เริ่มต้นสื่อสารกับชิพ MCP23017 ทาง I2C (SDA : 21, SCL : 22)
    //if (!mcp.begin_SPI(CS_PIN)) {
    Serial.println("Error.");           // กรณีที่ไม่สามารถเชื่อมต่อชิพ MCP23017 ได้ จะแสดงค่าออกมาทาง Serial monitor
    while (1);
  }

  // ชิพ MCP23017 บนบอร์ด PORT GPA[0,7] ตำแหน่งพิน 0-7 จะใช้เป็น INPUT
  // และ GPB[0,7] ตำแหน่งพิน 8-15 จะใช้เป็น OUTPUT
  
  mcp.pinMode(0, INPUT);                      // กำหนดพิน 0-3 เป็น INPUT (X1-X4)
  mcp.pinMode(1, INPUT);
  mcp.pinMode(2, INPUT);
  mcp.pinMode(3, INPUT);
  
  mcp.pinMode(8, OUTPUT);                     // กำหนดพิน 8-11 (รีเลย์ 1-4) เป็น OUTPUT
  mcp.pinMode(9, OUTPUT);
  mcp.pinMode(10, OUTPUT);
  mcp.pinMode(11, OUTPUT);

  mcp.digitalWrite(8, HIGH);                  // สั่งค่าเริ่มต้น OUTPUT 8-11 (รีเลย์ 1-4) ให้มีสถานะเป็น HIGH (OFF)
  mcp.digitalWrite(9, HIGH);
  mcp.digitalWrite(10, HIGH);
  mcp.digitalWrite(11, HIGH);

  Serial.println("Looping...");
}

void loop() {
  IN_OUT_CONTROL();                           // เรียกใช้งานฟังก์ชั่น IN_OUT_CONTROL
}


void IN_OUT_CONTROL() {
  if (mcp.digitalRead(0) == LOW) {            // หากมี INPUT X1 (LOW: เอาขั้ว INPUT ลงกราวด์ GND) เข้ามา
    mcp.digitalWrite(8, ON);                  // จะสั่งให้รีเลย์ตัวที่ 1 (RELAY1) ON
    Serial.println("X1 Active");
  } else {
    mcp.digitalWrite(8, OFF);                  // จะสั่งให้รีเลย์ตัวที่ 1 (RELAY1) OFF
    Serial.println("X1 NOT Active");
  }
  
  if (mcp.digitalRead(1) == LOW) {            // หากมี INPUT X2 (LOW: เอาขั้ว INPUT ลงกราวด์ GND) เข้ามา
    mcp.digitalWrite(9, ON);                  // จะสั่งให้รีเลย์ตัวที่ 2 (RELAY2) ON
    Serial.println("X2 Active");
  } else {
    mcp.digitalWrite(9, OFF);                 // จะสั่งให้รีเลย์ตัวที่ 2 (RELAY2) OFF
    Serial.println("X2 NOT Active");
  }
  
  if (mcp.digitalRead(2) == LOW) {            // หากมี INPUT X3 (LOW: เอาขั้ว INPUT ลงกราวด์ GND) เข้ามา
    mcp.digitalWrite(10, ON);                 // จะสั่งให้รีเลย์ตัวที่ 3 (RELAY3) ON
    Serial.println("X3 Active");
  } else {
    mcp.digitalWrite(10, OFF);                // จะสั่งให้รีเลย์ตัวที่ 3 (RELAY3) OFF
    Serial.println("X3 NOT Active");
  }
  
  if (mcp.digitalRead(3) == LOW) {            // หากมี INPUT X4 (LOW: เอาขั้ว INPUT ลงกราวด์ GND) เข้ามา
    mcp.digitalWrite(11, ON);                 // จะสั่งให้รีเลย์ตัวที่ 4 (RELAY4) ON
    Serial.println("X4 Active");
  } else {
    mcp.digitalWrite(11, OFF);                // จะสั่งให้รีเลย์ตัวที่ 4 (RELAY4) OFF
    Serial.println("X4 NOT Active");
  }
}
