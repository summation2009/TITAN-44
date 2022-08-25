#include <ModbusMaster.h>
#include <Wire.h>
#define RXD 34
#define TXD 27

ModbusMaster node;

void setup() {
  Serial1.begin(9600, SERIAL_8N1, RXD, TXD);
  Serial.begin(115200);

}
float humi, temp , CO2;
void loop() {
  humi = Read_sensor(1 , 0);//(ID,ADDRESS)
  delay(200);
  temp = Read_sensor(1 , 1);
  delay(200);
  CO2 = Read_sensor(1 , 5);
  delay(200);
  Serial.print("Temperature : ");
  Serial.print(temp / 10, 1);
  Serial.println("C");

  Serial.print("Humidity : ");
  Serial.print(humi / 10, 1);
  Serial.println("%");

  Serial.print("CO2 : ");
  Serial.print(CO2);
  Serial.println("PPM");
}

int Read_sensor(int addr , uint16_t  REG) {
  int j, result;
  node.begin(addr, Serial1);
  result = node.readHoldingRegisters (REG, 2); ///< Modbus function 0x04 Read Input Registers
  if (result == node.ku8MBSuccess) {
    return node.getResponseBuffer(0);
  } else { 
    return 333;
  }
}
