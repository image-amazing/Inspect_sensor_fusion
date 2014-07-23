/*! 
* 	\file    utils.h
* 	\author  Gabriel Urbain <gurbain@mit.edu> - Visitor student at MIT SSL
* 	\date    July 2014
* 	\version 0.1
* 	\brief   Software global tools
*
* 	License: The MIT License (MIT)
* 	Copyright (c) 2014, Massachussets Institute of Technology
*/

#ifndef UTILS_HH
#define UTILS_HH

// Project libs
#include "defines.h"
#include "camera.h"
#include "orf.h"

// OpenCV libs
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"

// Common libs
#include <sys/utsname.h>
#include <stdint.h>
#include <iomanip>
#include <limits>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/version.h>

using namespace std;
using namespace orf;

void intro()
{
        cout<<"\n=============== SwissRanger SR4000 Acquisition Software ===============\n"<<endl;
	cout<<"This software allows the user to take and save visual images and depth"<<endl;
	cout<<"information given by a SwissRanger SR4000 connected by ethernet with"<<endl;
	cout<<"a static IP."<<endl<<endl;
	cout<<"PID of the process: "<<(int)getpid()<<endl;
	cout<<"Compiled  On: \t"<<__DATE__<<" at "<<__TIME__<<" UTC"<<endl;
	cout<<"          With:\tGCC: "<< __VERSION__<<endl;
	struct utsname ver;
	uname(&ver);
	cout<<"\t\tUbuntu: Trusty 14.04 - kernel "<<ver.release<<endl;
	cout<<"\t\tOpenCV: "<<CV_VERSION<<endl;
	cout<<"Author: "<<__AUTHOR__<<endl;
	cout<<"Space Systems Lab (SSL) - INSPECT project"<<endl;
	cout<<"July 2014 - Massachussets Institute of Technology (MIT)\n"<<endl;
	cout<<"=======================================================================\n"<<endl;
}

void changeParams(ORF cam)
{
	int time = cam.getIntegrationTime();
	int thresh = cam.getAmplitudeThreshold();
	double freq = cam.getModulationFrequency();
	char autoexp = 'y';
	
	cout<<"\n======================================================================="<<endl;
	cout<<" Device : "<<cam.device_id_<<endl;
	cout<<" Library version : "<<cam.lib_version_<<endl; 
	cout<<"=======================================================================";
	cout<<"\nIntegration time: "<<cam.getIntegrationTime()<<" seconds"<<endl;
	cout<<"Amplitude threshold: "<<cam.getAmplitudeThreshold()<<endl;
	cout<<"Modulation frequency: "<<cam.getModulationFrequency()<<" MHz"<<endl<<endl;
	
	cout<<"Set auto-exposure? (Y)es/(n)o : ";
	cin>>autoexp;
	cout<<"New integration time: ";
	cin>>time;
	cout<<"New amplitude: ";
	cin>>thresh;
	cout<<"New modulation frequency: ";
	cin>>freq;
	
	if (autoexp=='y') {
		cam.setAutoExposure(1);
	} else
		cam.setAutoExposure(0);
	cam.setAmplitudeThreshold(thresh);
	cam.setIntegrationTime(time);
	cam.setModulationFrequency(freq);
	
	cout<<"\nIntegration time: "<<cam.getIntegrationTime()<<"seconds"<<endl;
	cout<<"Amplitude threshold: "<<cam.getAmplitudeThreshold()<<endl;
	cout<<"Modulation frequency: "<<cam.getModulationFrequency()<<"MHz"<<endl<<endl;
	
}

#endif