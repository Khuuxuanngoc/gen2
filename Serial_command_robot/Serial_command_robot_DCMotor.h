#include "Serial_command_robot_debug.h"
#ifndef _DIS_SERIAL_H_COMMAND_ROBOT_DCMOTOR_H_
#ifndef _SERIAL_H_COMMAND_ROBOT_DCMOTOR_H_
#define _SERIAL_H_COMMAND_ROBOT_DCMOTOR_H_

#include "Vietduino_NewFunction.h"
#include "Serial_command_robot_io.h"
#include "Vietduino_DCmotor.h"

#define RADABOT_DC_MAX_SPEED                            10
#define RADABOT_DC_MAX_TIME_RUN_IFNOT_BLUETOOTH         100

#define RADABOT_DC_DIR_CW                               0
#define RADABOT_DC_DIR_CCW                              1

extern Vietduino_DCmotor Motor_L;
extern Vietduino_DCmotor Motor_R;
extern unsigned char uc_rada_dcSpeed_value;

extern void RadaBot_Run(String _char_command);
extern void runMotor(uint8_t dirL, uint8_t dirR, uint8_t speed_L, uint8_t speed_R);
extern void runMotor(uint8_t dirL, uint8_t dirR);

// DEFINE_FUNCTION(Read_Vin);

#endif
#endif