#include "Serial_command_robot_DCMotor.h"
#ifndef _DIS_SERIAL_H_COMMAND_ROBOT_DCMOTOR_H_

Vietduino_DCmotor Motor_L(O_PWM_PIN_L, O_DIR_PIN_L);
Vietduino_DCmotor Motor_R(O_PWM_PIN_R, O_DIR_PIN_R);
unsigned char uc_rada_dcSpeed_value         = 10;
unsigned char uc_rada_dcDir_value           =  RADABOT_DC_DIR_CW;

void runMotor(uint8_t dirL, uint8_t dirR, uint8_t speed_L, uint8_t speed_R){
    Motor_L.write(dirL, min(speed_L , RADABOT_DC_MAX_SPEED) * 255 / RADABOT_DC_MAX_SPEED, RADABOT_DC_MAX_TIME_RUN_IFNOT_BLUETOOTH);\
    Motor_R.write(dirR, min(speed_R , RADABOT_DC_MAX_SPEED) * 255 / RADABOT_DC_MAX_SPEED , RADABOT_DC_MAX_TIME_RUN_IFNOT_BLUETOOTH);
}

void runMotor(uint8_t dirL, uint8_t dirR){
    runMotor(dirL, dirR, uc_rada_dcSpeed_value, uc_rada_dcSpeed_value);
}

void RadaBot_Run(String _char_command){
    uc_rada_dcSpeed_value = min(uc_rada_dcSpeed_value, RADABOT_DC_MAX_SPEED);

    if(_char_command == "FF"){
        runMotor(RADABOT_DC_DIR_CW, RADABOT_DC_DIR_CW);
    }else if(_char_command == "FL"){
        runMotor(RADABOT_DC_DIR_CW, RADABOT_DC_DIR_CW, 0, uc_rada_dcSpeed_value);
    }else if(_char_command == "FR"){
        runMotor(RADABOT_DC_DIR_CW, RADABOT_DC_DIR_CW, uc_rada_dcSpeed_value, 0);
    }else if(_char_command == "BB"){
        runMotor(RADABOT_DC_DIR_CCW, RADABOT_DC_DIR_CCW);
    }else if(_char_command == "BL"){
        runMotor(RADABOT_DC_DIR_CCW, RADABOT_DC_DIR_CCW, 0, uc_rada_dcSpeed_value);
    }else if(_char_command == "BR"){
        runMotor(RADABOT_DC_DIR_CCW, RADABOT_DC_DIR_CCW, uc_rada_dcSpeed_value, 0);
    }else if(_char_command == "LL"){
        runMotor(RADABOT_DC_DIR_CCW, RADABOT_DC_DIR_CW);
    }else if(_char_command == "RR"){
        runMotor(RADABOT_DC_DIR_CW, RADABOT_DC_DIR_CCW);
    }
}


#endif