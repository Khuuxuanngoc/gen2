#include "Serial_command_robot_debug.h"
#ifndef _DIS_SERIAL_H_COMMAND_ROBOT_SERVORC_H_
#ifndef _SERIAL_H_COMMAND_ROBOT_SERVORC_H_
#define _SERIAL_H_COMMAND_ROBOT_SERVORC_H_

#include "Serial_command_robot_io.h"
#include "Vietduino_Servo.h"
#include "Vietduino_NewFunction.h"

#define ML_SERVO_VALUE_MAX              (180)
#define ML_SERVO_VALUE_MIN              (0)

extern Vietduino_Servo Servo_L;
extern Vietduino_Servo Servo_R;

extern unsigned char uc_servo_speed;
extern unsigned char uc_Servo_Pos_L;
extern unsigned char uc_Servo_Pos_R;

// DEFINE_FUNCTION(testServo);

#endif
#endif