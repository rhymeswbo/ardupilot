//
//  GR_Quad.h
//  ArduCopter
//
//  Created by GIOVANNI REY on 12/26/14.
//  Copyright (c) 2014 GIOVANNI REY. All rights reserved.
//

#ifndef __ArduCopter__GR_Quad__
#define __ArduCopter__GR_Quad__

#include <AP_Common.h>
#include <AP_Param.h>

#define FORWARD_CAMERA 0
#define DOWNWARD_CAMERA 1
#define CH_1 0
#define CH_2 1
#define CH_3 2
#define CH_4 3
#define CH_5 4
#define CH_6 5
#define CH_7 6
#define CH_8 7
#define NUM_CHANNELS 8


#define CAMERA_SWITCH_CHANNEL CH_8


class GR_Quad {
public:
    GR_Quad(RC_Channel_aux* cam_switch_ch);
    void    setCameraSwitch(int16_t mode);
    void    CamSwitchSetup();

    
private:
    // Camera Switch Settings
    int16_t     last_RC_setting;
    RC_Channel_aux* CamSwitch;
    
    
    void    print_pwm();
    void    print_radio_values();
    
    
    
};





#endif /* defined(__ArduCopter__GR_Quad__) */
