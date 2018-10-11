/*
  Các tính năng cần có:
  - Nhận Command từ Serial
    + Frame: <Type board>, <ID number board>, <Mode GET/SET data>, <ID Component>, <Len bufferdata>, <Buffer1>, ..., <Buffer n>,

    + Board config: <Type board>,   <Command>,                  <Vallue1>,                        <Vallue2>,        <Vallue3>,        <Vallue4>,
                      RADA_B,         SET_ID,          (From 1 to 254, 255 is broadcast),
                      RADA_B,         GET_ID,

    + Board control: <RADA+ID>,     <Command>,                   <Vallue>,
                      RADA+255,       SET_SERVO_L,                 (From 0 to 180)                  //đang truyền dạng boardcast,
                      RADA+255,       GET_SERVO_L,                                                  //đang truyền dạng boardcast,

                      Serial_Device                                                                                          MCU
                                          READ_INFO,\r\n
                                    )----------------------------->-------------------------------------------------------->
                                          READ_INFO , <Batery value(1 to 3)> , <Servo L (0-180)> ,<Servo R (0-180)> , <speed(0=10)> \r\n
                                    <=============================<========================================================(

                                          JOYSTICK, <DIRECTION> \r\n
                                    )----------------------------->-------------------------------------------------------->

                                          SPEED, <value> \r\n
                                    )----------------------------->-------------------------------------------------------->
                                          SERVO_L, <value> \r\n
                                    )----------------------------->-------------------------------------------------------->
                                          SERVO_R, <value> \r\n
                                    )----------------------------->-------------------------------------------------------->
                                    
                                    
  - Điều khiển 2 động cơ DC
  - Điều khiển 2 động cơ RC (9G)
*/

#include "Serial_command_robot_io.h"
#include "Vietduino_DCmotor.h"
#include "Serial_command_robot_ReadBat.h"
#include "Serial_command_robot_ServoRC.h"
#include "Serial_command_robot_Bluetooth.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start!");
  Servo_L.begin(O_SERVO_PIN_L);
  Servo_R.begin(O_SERVO_PIN_R);

}

void loop() {
    // put your main code here, to run repeatedly:
  VIETDUINO_UPDATE;
}
