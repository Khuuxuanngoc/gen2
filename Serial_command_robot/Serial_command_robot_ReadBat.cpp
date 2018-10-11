#include "Serial_command_robot_ReadBat.h"

SimpleKalmanFilter Vin_Filter(1, 1, 0.1);
float g_f_Vin_value = 0.0;

CREATE_FUNCTION(Read_Vin){
    while(1){
        static uint8_t cf = 0;
        for(cf; cf < 9; cf++){
            float average2 = (float)analogRead(I_BATERY_VOLT_PIN) * 1000;
            // Db_volt("Volt value ana: ");
            // Db_voltn(average2);
            average2 = average2 * ((R_GND + R_RAW) / R_GND) * V_REF / 1023;
            g_f_Vin_value = Vin_Filter.updateEstimate(average2);
            g_f_Vin_value = map(g_f_Vin_value, ML_BAT_READ_VALUE_WARN_MIN, ML_BAT_READ_VALUE_WARN_MAX, ML_BAT_MIN_VALUE, ML_BAT_MAX_VALUE);
            M_DELAY(100);
        }
        Db_volt("Volt value: ");
        Db_voltn(g_f_Vin_value);
        cf = 0;
        
        M_DELAY(2000);
        
    }

    END_CREATE_FUNCTION
}