//
//  GR_Quad.cpp
//  ArduCopter
//
//  Created by GIOVANNI REY on 12/26/14.
//  Copyright (c) 2014 GIOVANNI REY. All rights reserved.
//



#include <stdlib.h>
#include <math.h>
#include <stdio.h> 


#include "RC_Channel.h"
#include "GR_Quad.h"

// AP_HAL to Arduino compatibility layer
#include "compat.h"
#include "defines.h"
#include "config.h"
#include "config_channels.h"
#include <AC_PID.h>
#include <AC_P.h>
#include <AP_HAL.h>
#include "GCS_MAVLink.h"


// key aircraft parameters passed to multiple libraries
//static AP_Vehicle::MultiCopter aparm;
#include "Parameters.h"


extern Parameters * g;
extern const AP_HAL::HAL& hal;
extern void gcs_send_text_P(gcs_severity severity, const prog_char_t *str);



GR_Quad::GR_Quad (RC_Channel_aux* cam_switch_ch)
{
    //AP_Param::setup_object_defaults(this, var_info);
    CamSwitch = cam_switch_ch; //&g->rc_8; // RC_Channel(CAMERA_SWITCH_CHANNEL);
    //CamSwitchSetup(); //moved to after rc_init stuff in system.pde.
    last_RC_setting = 55;

}


    
void
GR_Quad::CamSwitchSetup()
{
    //hal.console->println("GR_Quad RC Init for Camera Switch test");
    
    //print_radio_values();
    
    // set type of output, symmetrical angles or a number range;
    CamSwitch->function=RC_Channel_aux::k_cam_switch;
    /* i grew tired of trying to reverse engineer un documemented RC modes, mins, macs, trims, and scalings.  I am going to directly write radio_out.
     
    CamSwitch->set_angle(4500);
    
    CamSwitch->set_default_dead_zone(80);
    
    CamSwitch->set_type(RC_CHANNEL_TYPE_ANGLE_RAW);
    */
    CamSwitch->enable_out();
    
    gcs_send_text_P(SEVERITY_HIGH, PSTR("GR_Quad: Camera switch initiallized"));

    
}

void
GR_Quad::setCameraSwitch(int16_t mode){
    if(mode != last_RC_setting){
        switch (mode) {
            case FORWARD_CAMERA:
                CamSwitch->radio_out = 1100;
                gcs_send_text_P(SEVERITY_HIGH, PSTR("camera switch set to 0, forward"));
                break;
            case DOWNWARD_CAMERA:
                CamSwitch->radio_out = 1900;
                gcs_send_text_P(SEVERITY_HIGH, PSTR("camera switch set to 1, down"));
                break;
        }
        last_RC_setting = mode;
        CamSwitch->enable_out();

        CamSwitch->output(); //send to output... this happens anyway on a tight loop, but WTH
    }
}


void
GR_Quad::print_pwm()
{
    hal.console->printf("ch%u: %4d ", (unsigned)CAMERA_SWITCH_CHANNEL, (int)CamSwitch->control_in);
    hal.console->printf("\n");
}


void
GR_Quad::print_radio_values()
{
    hal.console->printf("CH%u: %u|%u\n",
                        (unsigned)CAMERA_SWITCH_CHANNEL,
                        (unsigned)CamSwitch->radio_min,
                        (unsigned)CamSwitch->radio_max);
}





