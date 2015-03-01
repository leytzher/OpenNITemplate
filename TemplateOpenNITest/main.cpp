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


char ReadLastCharOfLine(void);

using namespace openni;
using namespace std;
int main(int argc, const char * argv[]) {
    printf("OpenNI Version is %d.%d.%d.%d",
           OpenNI::getVersion().major,
           OpenNI::getVersion().minor,
           OpenNI::getVersion().maintenance,
           OpenNI::getVersion().build);
    printf("Scanning machine for devices and loading "
           "modules/drivers ... \r\n");
    Status status = STATUS_OK;
    
    status = OpenNI::initialize();
    if(status!= STATUS_OK){
        printf("ERROR: %d, %s", status,
               OpenNI::getExtendedError());
        return 1;
    }
    printf("Completed. \r\n");
    printf("Press enter to exit.\r\n");
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

