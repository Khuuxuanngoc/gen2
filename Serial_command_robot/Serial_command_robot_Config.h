#ifndef _SERIAL_H_COMMAND_ROBOT_CONFIG_H_
#define _SERIAL_H_COMMAND_ROBOT_CONFIG_H_

#define COMMAND_SERVO_L         "SERVO_L"
#define COMMAND_SERVO_R         "SERVO_R"

#define COMMAND_JOYSTICK        "JOYSTICK"
#define COMMAND_SPEED           "SPEED"
#define COMMAND_INFO            "READ_INFO"

enum{
    _RADA_MODE_MANUAL_,
    _RADA_MODE_AVOID_,
    _RADA_MODE_FOLLOW_,
    _RADA_MODE_LOWVOLT_
}RadaBot_MODE;

extern unsigned char uc_mode;
extern unsigned char uc_lastMode;
extern void setModeRobot(unsigned char _mode_Set_);
extern unsigned char getModeRobot();

#endif