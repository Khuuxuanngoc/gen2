#ifndef _SERIAL_H_COMMAND_ROBOT_READBAT_H_
#define _SERIAL_H_COMMAND_ROBOT_READBAT_H_

#include "Vietduino_NewFunction.h"
#include <SimpleKalmanFilter.h>
#include "Serial_command_robot_io.h"
#include "Serial_command_robot_debug.h"

#define ML_BAT_MAX_VALUE                (3)
#define ML_BAT_MIN_VALUE                (0)
#define ML_BAT_READ_VALUE_WARN_MIN      (6500)      // mV
#define ML_BAT_READ_VALUE_WARN_MAX      (8500)      // mV

#define R_GND                           (1.0) //1k
#define R_RAW                           (4.7) //4k7
#define R_CALCULATE                     (R_GND/(R_GND+R_RAW)) 
#define V_REF                           (5.0)   //V

extern SimpleKalmanFilter Vin_Filter;
extern float g_f_Vin_value;
DEFINE_FUNCTION(Read_Vin);

#endif