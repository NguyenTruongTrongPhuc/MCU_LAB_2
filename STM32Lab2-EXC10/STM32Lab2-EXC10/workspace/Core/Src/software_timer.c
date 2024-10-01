/*
 * software_timer.c
 *
 *  Created on: Oct 2, 2023
 *      Author: ad
 */
#include "software_timer.h"

int timer_counter[10] = {0};
int timer_flag[10] = {0};

void setTimer(int timer_ID, int duration){
	timer_counter[timer_ID] = duration;
	timer_flag[timer_ID] = 0;
}
void timerRun(int timer_ID){
	if(timer_counter[timer_ID] > 0){
		timer_counter[timer_ID]--;
		if(timer_counter[timer_ID] <= 0){
			timer_flag[timer_ID] = 1;
		}
	}
}

