//
//  main.cpp
//  gfpf_tester
//
//  Created by Thomas Rushmore on 09/07/2013.
//  Copyright (c) 2013 Thomas Rushmore. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "gfpfhandler.h"

int main(int argc, const char * argv[])
{
    if(argc <= 3)
    {
        std::cerr << "Usage : string type {batch,single},int resamplThreshold, int testGestureIdx" << std::endl;
        return 1;
    }
    const char *type = argv[1];
    int process_type;
    if(!strcmp(type,"batch") || !strcmp(type,"single"))
    {
        std::cerr << "Usage : string type {batch,single},int resamplThreshold, int testGestureIdx" << std::endl;
    } else {
        if(!strcmp(type, "batch"))
            process_type = 0;
        else
            process_type = 1;
    }
    
    
    int rt = atoi(argv[2]);
    if(rt > 2000){
        std::cerr << "RT must be less than #particles (default:2000) " << std::endl;
        return 1;
    }
    // sim user-input gesture
    int gt = atoi(argv[3]);

    gfpfhandler gfpfhandl(rt,gt);
    gfpfhandl.teach();
    
    printf("Complete.\n");
    return 0;
}
