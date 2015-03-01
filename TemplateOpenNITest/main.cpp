//
//  main.cpp
//  TemplateOpenNITest
//
//  Created by Leytzher on 3/1/15.
//  Copyright (c) 2015 Leytzher. All rights reserved.
//

#include <iostream>
#include "OpenNI.h"
#include "NiTE.h"
using namespace openni;
using namespace std;

char ReadLastCharOfLine(void);
bool HandleStatus(Status);


int main(int argc, const char * argv[]) {

    Status status = STATUS_OK;
    printf("Scanning machine for devices and loading " " modules/drivers ...\r\n");
           status = OpenNI::initialize();
           if (!HandleStatus(status)) return 1;
           printf("Completed.\r\n");
           openni::Array<openni::DeviceInfo> listOfDevices;
           openni::OpenNI::enumerateDevices(&listOfDevices);
           int numberOfDevices = listOfDevices.getSize();
           if (numberOfDevices > 0){
               printf("%d Device(s) are available to use.\r\n\r\n",
                      numberOfDevices);
               for (int i = 0; i < numberOfDevices; i++)
               {
                   openni::DeviceInfo device = listOfDevices[i];
                   printf("%d. %s->%s (VID: %d | PID: %d) is connected "
                          " at %s\r\n",
                          i,
                          device.getVendor(),
                          device.getName(),
                          device.getUsbVendorId(),
                          device.getUsbProductId(),
                          device.getUri());
               }
           }else{
               printf("No device connected to this machine.");
           }
           
           printf("Press ENTER to exit.\r\n");
           ReadLastCharOfLine();
           OpenNI::shutdown();
           return 0;


}


char ReadLastCharOfLine()
{
    int newChar = 0;
    int lastChar;
    do{
        lastChar = newChar;
        newChar = getchar();
    } while((newChar != '\n') && (newChar != EOF));
    return (char) lastChar;
}

bool HandleStatus(Status status)
{
    if (status == STATUS_OK)
        return true;
    printf("ERROR: #%d, %s", status,
           OpenNI::getExtendedError());
    ReadLastCharOfLine();
    return false;
}

