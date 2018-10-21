/*
  Các tính năng cần có:
  - Nhận Command từ Serial
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
