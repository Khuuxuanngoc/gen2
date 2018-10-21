#include "Serial_command_robot_ReadBat.h"
#include "Serial_command_robot_Bluetooth.h"

SimpleKalmanFilter Vin_Filter(1, 1, 0.1);
float g_f_Vin_value = 0.0;

CREATE_FUNCTION(Read_Vin){
    while(1){
        static uint8_t cf = 0;
        for(cf; cf < 9; cf++){
            float average2 = (float)analogRead(I_BATERY_VOLT_PIN) * 1000;
            average2 = average2 * ((R_GND + R_RAW) / R_GND) * V_REF / 1023;
            average2 = Vin_Filter.updateEstimate(average2);
            average2 = map(average2, ML_BAT_READ_VALUE_WARN_MIN, ML_BAT_READ_VALUE_WARN_MAX, ML_BAT_MIN_VALUE, ML_BAT_MAX_VALUE + 1);
            g_f_Vin_value = constrain(average2, ML_BAT_MIN_VALUE, ML_BAT_MAX_VALUE);
            M_DELAY(100);
        }
        Db_volt("Volt value: ");
        Db_voltn(g_f_Vin_value);
        cf = 0;
        if(g_f_Vin_value == ML_BAT_MIN_VALUE){
            setModeRobot(_RADA_MODE_LOWVOLT_);
        }else{
            setModeRobot(uc_lastMode);
        }
        Send_info_OverBluetooth();
        // M_DELAY(1000);
        
    }

    END_CREATE_FUNCTION
}