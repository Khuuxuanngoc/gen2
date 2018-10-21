#include "Serial_command_robot_Config.h"

unsigned char uc_mode = _RADA_MODE_MANUAL_;
unsigned char uc_lastMode = _RADA_MODE_MANUAL_;

void setModeRobot(unsigned char _mode_Set_){
    if(uc_mode == _mode_Set_){
        return;
    }
    uc_lastMode = uc_mode;
    uc_mode = _mode_Set_;
}