//
//  main.cpp
//  Wall
//
//  for csgo wall hack
//  special edition
//
//  Created by sheep on 16/5/14.
//  Copyright © 2016年 nadp. All rights reserved.
//

/**
 *
 * @toggle key : CTRL + ALT (OPT) + V
 * Change modifier at line 233
 * Change keycode at line 234
 *
 */

#include <iostream>
#include "Utils.hpp"
#include "Utils.cpp"
#include <ApplicationServices/ApplicationServices.h>

uint64_t glowInfoOffset     = 0x59ebf90;
uint64_t LocalPlayerBase    = 0x51dc668;
uint64_t playerBase         = 0x5158f68;

uint64_t m_iGlowIndex       = 0xAC10;

// score variables:
// first is the offset for the scoreboard
// next we create a global variable for the highscore which will be updated later
uint64_t scoreBase          = 0x50E2310;
int highscore               = 0;

bool statBool = true;

bool ctr = false;
bool sft = false;
bool cmd = false;
bool alt = false;
bool states = true;

struct Color {
    float red;
    float green;
    float blue;
    float alpha;
};

uint16_t keyCodeForKeyString(const char * keyString) {
    if (strcmp(keyString, "a") == 0) return 0;
    if (strcmp(keyString, "s") == 0) return 1;
    if (strcmp(keyString, "d") == 0) return 2;
    if (strcmp(keyString, "f") == 0) return 3;
    if (strcmp(keyString, "h") == 0) return 4;
    if (strcmp(keyString, "g") == 0) return 5;
    if (strcmp(keyString, "z") == 0) return 6;
    if (strcmp(keyString, "x") == 0) return 7;
    if (strcmp(keyString, "c") == 0) return 8;
    if (strcmp(keyString, "v") == 0) return 9;
    // what is 10?
    if (strcmp(keyString, "b") == 0) return 11;
    if (strcmp(keyString, "q") == 0) return 12;
    if (strcmp(keyString, "w") == 0) return 13;
    if (strcmp(keyString, "e") == 0) return 14;
    if (strcmp(keyString, "r") == 0) return 15;
    if (strcmp(keyString, "y") == 0) return 16;
    if (strcmp(keyString, "t") == 0) return 17;
    if (strcmp(keyString, "1") == 0) return 18;
    if (strcmp(keyString, "2") == 0) return 19;
    if (strcmp(keyString, "3") == 0) return 20;
    if (strcmp(keyString, "4") == 0) return 21;
    if (strcmp(keyString, "6") == 0) return 22;
    if (strcmp(keyString, "5") == 0) return 23;
    if (strcmp(keyString, "=") == 0) return 24;
    if (strcmp(keyString, "9") == 0) return 25;
    if (strcmp(keyString, "7") == 0) return 26;
    if (strcmp(keyString, "-") == 0) return 27;
    if (strcmp(keyString, "8") == 0) return 28;
    if (strcmp(keyString, "0") == 0) return 29;
    if (strcmp(keyString, "]") == 0) return 30;
    if (strcmp(keyString, "o") == 0) return 31;
    if (strcmp(keyString, "u") == 0) return 32;
    if (strcmp(keyString, "[") == 0) return 33;
    if (strcmp(keyString, "i") == 0) return 34;
    if (strcmp(keyString, "p") == 0) return 35;
    if (strcmp(keyString, "RETURN") == 0) return 36;
    if (strcmp(keyString, "l") == 0) return 37;
    if (strcmp(keyString, "j") == 0) return 38;
    if (strcmp(keyString, "'") == 0) return 39;
    if (strcmp(keyString, "k") == 0) return 40;
    if (strcmp(keyString, ";") == 0) return 41;
    if (strcmp(keyString, "\\") == 0) return 42;
    if (strcmp(keyString, ",") == 0) return 43;
    if (strcmp(keyString, "/") == 0) return 44;
    if (strcmp(keyString, "n") == 0) return 45;
    if (strcmp(keyString, "m") == 0) return 46;
    if (strcmp(keyString, ".") == 0) return 47;
    if (strcmp(keyString, "TAB") == 0) return 48;
    if (strcmp(keyString, "SPACE") == 0) return 49;
    if (strcmp(keyString, "`") == 0) return 50;
    if (strcmp(keyString, "DELETE") == 0) return 51;
    if (strcmp(keyString, "ENTER") == 0) return 52;
    if (strcmp(keyString, "ESCAPE") == 0) return 53;
    
    // some more missing codes abound, reserved I presume, but it would
    // have been helpful for Apple to have a document with them all listed
    
    if (strcmp(keyString, ".") == 0) return 65;
    
    if (strcmp(keyString, "*") == 0) return 67;
    
    if (strcmp(keyString, "+") == 0) return 69;
    
    if (strcmp(keyString, "CLEAR") == 0) return 71;
    
    if (strcmp(keyString, "/") == 0) return 75;
    if (strcmp(keyString, "ENTER") == 0) return 76;  // numberpad on full kbd
    
    if (strcmp(keyString, "=") == 0) return 78;
    
    if (strcmp(keyString, "=") == 0) return 81;
    if (strcmp(keyString, "0") == 0) return 82;
    if (strcmp(keyString, "1") == 0) return 83;
    if (strcmp(keyString, "2") == 0) return 84;
    if (strcmp(keyString, "3") == 0) return 85;
    if (strcmp(keyString, "4") == 0) return 86;
    if (strcmp(keyString, "5") == 0) return 87;
    if (strcmp(keyString, "6") == 0) return 88;
    if (strcmp(keyString, "7") == 0) return 89;
    
    if (strcmp(keyString, "8") == 0) return 91;
    if (strcmp(keyString, "9") == 0) return 92;
    
    if (strcmp(keyString, "F5") == 0) return 96;
    if (strcmp(keyString, "F6") == 0) return 97;
    if (strcmp(keyString, "F7") == 0) return 98;
    if (strcmp(keyString, "F3") == 0) return 99;
    if (strcmp(keyString, "F8") == 0) return 100;
    if (strcmp(keyString, "F9") == 0) return 101;
    
    if (strcmp(keyString, "F11") == 0) return 103;
    
    if (strcmp(keyString, "F13") == 0) return 105;
    
    if (strcmp(keyString, "F14") == 0) return 107;
    
    if (strcmp(keyString, "F10") == 0) return 109;
    
    if (strcmp(keyString, "F12") == 0) return 111;
    
    if (strcmp(keyString, "F15") == 0) return 113;
    if (strcmp(keyString, "HELP") == 0) return 114;
    if (strcmp(keyString, "HOME") == 0) return 115;
    if (strcmp(keyString, "PGUP") == 0) return 116;
    if (strcmp(keyString, "DELETE") == 0) return 117;
    if (strcmp(keyString, "F4") == 0) return 118;
    if (strcmp(keyString, "END") == 0) return 119;
    if (strcmp(keyString, "F2") == 0) return 120;
    if (strcmp(keyString, "PGDN") == 0) return 121;
    if (strcmp(keyString, "F1") == 0) return 122;
    if (strcmp(keyString, "LEFT") == 0) return 123;
    if (strcmp(keyString, "RIGHT") == 0) return 124;
    if (strcmp(keyString, "DOWN") == 0) return 125;
    if (strcmp(keyString, "UP") == 0) return 126;
    
    fprintf(stderr, "keyString %s Not Found. Aborting...\n", keyString);
    exit(EXIT_FAILURE);
}

CGEventRef keyBoardCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
    if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp) && (type != kCGEventFlagsChanged)) return event;
    
    // The incoming keycode.
    CGKeyCode keycode = (CGKeyCode)CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);
    //    printf("%i", keycode);
    
    // Control
    if (keycode == (CGKeyCode)59 || keycode == (CGKeyCode)62) {
        if (ctr) {
            ctr = false;
        } else {
            ctr = true;
        }
    }
    
    if (ctr) {
        CGEventSetFlags(event, (CGEventFlags)(NX_CONTROLMASK | CGEventGetFlags(event)));
    }
    
    //Shift
    if (keycode == (CGKeyCode)60 || keycode == (CGKeyCode)56) {
        if (sft) {
            sft = false;
        } else {
            sft = true;
        }
    }
    
    if (sft) {
        CGEventSetFlags(event, (CGEventFlags)(NX_SHIFTMASK | CGEventGetFlags(event)));
    }
    
    //Command
    if (keycode == (CGKeyCode)55 || keycode == (CGKeyCode)54) {
        if (cmd) {
            cmd = false;
        } else {
            cmd = true;
        }
    }
    
    if (cmd) {
        CGEventSetFlags(event, (CGEventFlags)(NX_COMMANDMASK | CGEventGetFlags(event)));
    }
    
    //Option
    if (keycode == (CGKeyCode)58 || keycode == (CGKeyCode)61) {
        if (alt) {
            alt = false;
        } else{
            alt = true;
        }
    }
    
    if (alt) {
        CGEventSetFlags(event, (CGEventFlags)(NX_ALTERNATEMASK | CGEventGetFlags(event)));
    }
    
    CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t)keycode);
    if (ctr && alt) {
        if (keycode == keyCodeForKeyString("v")) {
            states = !states;
            //printf("State Changed! %s\n", states ? "ON" : "OFF");
        }
    }
    
    // We must return the event for it to be useful.
    return event;
}

void keyBoardListen() {
    CFMachPortRef     eventTap;
    CGEventMask     eventMask;
    CFRunLoopSourceRef runLoopSource;
    eventMask = ((1 << kCGEventKeyDown) | (1 << kCGEventFlagsChanged));
    eventTap = CGEventTapCreate((CGEventTapLocation)kCGSessionEventTap, (CGEventTapPlacement)kCGHeadInsertEventTap, (CGEventTapOptions)0, eventMask, keyBoardCallback, NULL);
    if (!eventTap) {
        exit(1);
    }
    runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);
    CGEventTapEnable(eventTap, true);
    CFRunLoopRun();
}

int get_process() {
    pid_t pids[1024];
    int numberOfProcesses = proc_listpids(PROC_ALL_PIDS, 0, NULL, 0);
    proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
    
    for (int i = 0; i < numberOfProcesses; ++i) {
        if (pids[i] == 0) { continue; }
        char name[1024];
        proc_name(pids[i], name, sizeof(name));
        if (!strncmp(name, "csgo_osx64", sizeof("csgo_osx64"))) {
            return pids[i];
        }
    }
    return -1;
}

int get_client_module_info(task_t task, pid_t pid, mach_vm_address_t * start, unsigned long * length) {
    kern_return_t error = task_for_pid(current_task(), pid, &task);
    printf("Process reallocation: %d -> %x [%d - %s]\n", pid, task, error, mach_error_string(error));
    
    struct task_dyld_info dyld_info;
    mach_vm_address_t address;
    mach_msg_type_number_t count = TASK_DYLD_INFO_COUNT;
    if (task_info(task, TASK_DYLD_INFO, (task_info_t)&dyld_info, &count) == KERN_SUCCESS) {
        address = dyld_info.all_image_info_addr;
    } else {
        printf("Failed to get get info.\n");
        return 0;
    }
    
    struct dyld_all_image_infos *dyldaii;
    mach_msg_type_number_t size = sizeof(dyld_all_image_infos);
    vm_offset_t readMem;
    kern_return_t kr = vm_read(task, address, size, &readMem, &size);
    if (kr != KERN_SUCCESS) {
        printf("RIP");
        return 0;
    } else {
        printf("CSGO Memory %lu \n", readMem);
    }
    
    dyldaii = (dyld_all_image_infos *) readMem;
    printf("Version: %d, %d images at offset %p\n", dyldaii->version, dyldaii->infoArrayCount, dyldaii->infoArray);
    
    int imageCount = dyldaii->infoArrayCount;
    mach_msg_type_number_t dataCnt = imageCount * 24;
    struct dyld_image_info *g_dii = NULL;
    g_dii = (struct dyld_image_info *) malloc (dataCnt);
    
    // 32bit bs 64bit
    kern_return_t kr2 = vm_read(task, (mach_vm_address_t)dyldaii->infoArray, dataCnt, &readMem, &dataCnt);
    if (kr2) {
        printf("get lists failed \n");
        return 0;
    } else {
        
    }
    
    struct dyld_image_info *dii = (struct dyld_image_info *) readMem;
    for (int i = 0; i < imageCount; i++) {
        dataCnt = 1024;
        vm_read(task, (mach_vm_address_t)dii[i].imageFilePath, dataCnt, &readMem, &dataCnt);
        char *imageName = (char *)readMem;
        if (imageName){
            g_dii[i].imageFilePath = strdup(imageName);
        }
        else{
            g_dii[i].imageFilePath = NULL;
        }
        g_dii[i].imageLoadAddress = dii[i].imageLoadAddress;
        if (strstr(imageName, "/client.dylib") != NULL ){
            *start = (mach_vm_address_t)dii[i].imageLoadAddress;
            //            printf("!!!!!!!!find %s\n, address is 0x%llx \n", imageName, (mach_vm_address_t)dii[i].imageLoadAddress);
        }
        if (strstr(imageName, "/engine.dylib") != NULL ){
            *start = (mach_vm_address_t)dii[i].imageLoadAddress;
            //            printf("!!!!!!!!find %s\n, address is 0x%llx \n", imageName, (mach_vm_address_t)dii[i].imageLoadAddress);
        }
    }
    return task;
}

template <typename Type>
int readRam(task_t task, uint64_t address, Type * result) {
    int * size = (int* )malloc(sizeof(int));
    *size = 4;
    uint32_t * sz = (uint32_t *)malloc(sizeof(uint32_t));
    vm_offset_t * data = (vm_offset_t *)malloc(sizeof(uint64_t));
    
    //vm_offset_t data;
    if (vm_read(task, address, *size, data, sz) != KERN_SUCCESS){
        free(sz);
        free(data);
        free(size);
        return 0;
    }
    
    *result = (Type) *(Type* )(*data);
    free(sz);
    free(size);
    free(data);
    return 1;
}

int getEntityGlowLoopStartAddressAndCount(task_t task, mach_vm_address_t imgbase, uint64_t * address, int * count) {
    int glowObjectLoopCount = 0x18;
    auto reAddress = Utils::ReadMemAndDeAllocate<uint64_t>(task, current_task() ,imgbase + glowInfoOffset, address);
    auto reCount = readRam<int>(task, imgbase + glowInfoOffset + glowObjectLoopCount, count);
    if (!reAddress || !reCount) {
        return 0;
    } else {
        return 1;
    }
}

template <typename Type>
void WriteMem(task_t task, mach_vm_address_t address, Type value) {
    vm_write(task, address, (vm_offset_t) &value, sizeof(Type));
}

void applyGlowEffect(task_t task, mach_vm_address_t glowStartAddress, int glowObjectIndex, Color color) {
    uint64_t glowBaseAddress = glowStartAddress + (0x40 * glowObjectIndex);
    
    WriteMem<bool>(task, glowBaseAddress + 0x28, statBool);
    WriteMem<Color>(task, glowBaseAddress + 0x8, color);
}

void readPlayerPointAndHealth(task_t task, task_t taskSelf, mach_vm_address_t imgbase, mach_vm_address_t startAddress, int iTeamNum) {
    uint64_t memoryAddress, scoreAddress;
    int glowIndex;
    
    for (int i = 0; i < 20; i++) {
        int playerTeamNum;
        if (Utils::ReadMemAndDeAllocate<uint64_t>(task, taskSelf, imgbase + playerBase + 0x20 * i, &memoryAddress) == -1) {
            continue;
        }
        if (memoryAddress <= 0x0){
            continue;
        }
        if (Utils::ReadMemAndDeAllocate<int>(task, taskSelf, memoryAddress + m_iGlowIndex, &glowIndex)) {
            continue;
        }
        int health;
        if (Utils::ReadMemAndDeAllocate<int>(task, taskSelf, memoryAddress + 0x134, &health)) {
            continue;
        }
        if (Utils::ReadMemAndDeAllocate<int>(task, taskSelf, memoryAddress + 0x128, &playerTeamNum)) {
            continue;
        }
        if (playerTeamNum == 0) {
            continue;
        }
        if (health == 0){
            health = 100;
        }
        
        //Team glow (team will glow light blue)
        if (playerTeamNum == iTeamNum) {
            Color color = {(0 / 255), (255 / 255), (255 / 255), 0.4f}; //remove this line if you don't want a team glow
            applyGlowEffect(task, startAddress, glowIndex, color);  //remove this line if you don't want a team glow
            continue;
        }
        
        // here we create a variable that will hold the amount of kills a player has.
        int playerKills;
       
        // we read the scoreboard and check each player's amount of kills
        // we don't need to worry about possibly checking teammates
        // becasue they were already skipped over by code above this
        Utils::ReadMemAndDeAllocate(task, current_task(), imgbase + scoreBase, &scoreAddress);
        Utils::ReadMemAndDeAllocate(task, current_task(), scoreAddress + 0x1288 + 0x4 * i, &playerKills);
       
        // below we will give the enemy with the highest score a different glow color. 
        // it only turns on once a player has 3 kills.
        // if multiple enemy players are tied for the highscore, they all get the new glow. 
        // this works even if they take over a bot.
        
       Color color = {float((100 - health) / 100.0), float((health) / 100.0), 0.0f, 0.55f};
       if((highscore <= playerKills) && (highscore > 2)){
            color = {float((100 - health) / 100.0),  (0 / 255), float((health) / 100.0), 0.55f};
       }
       applyGlowEffect(task, startAddress, glowIndex, color);
    }
}

int testLocalPlayerAddress(task_t csgo, uint64_t clientBase) {
    uint64_t playerAddress, scoreAddress;;
    int health, iTeamNum, pKills, pTeamNum, pConnected;
    Utils::ReadMemAndDeAllocate(csgo, current_task(), clientBase + LocalPlayerBase, &playerAddress);
    Utils::ReadMemAndDeAllocate(csgo, current_task(), playerAddress + 0x134, &health);
    Utils::ReadMemAndDeAllocate(csgo, current_task(), playerAddress + 0x128, &iTeamNum);
    
    //set the highscore to zero
    //then check every player for a new high score
    highscore = 0;
   
    for (int x = 0; x < 20; x++) {
        Utils::ReadMemAndDeAllocate(csgo, current_task(), clientBase + scoreBase, &scoreAddress);
        Utils::ReadMemAndDeAllocate(csgo, current_task(), scoreAddress + 0x1288 + 0x4 * x, &pKills);
        Utils::ReadMemAndDeAllocate(csgo, current_task(), scoreAddress + 0x15D8 + 0x4 * x, &pTeamNum);
        Utils::ReadMemAndDeAllocate(csgo, current_task(), scoreAddress + 0x1591 + 0x1 * x, &pConnected);
         
        // CSGO saves score info for players even if they leave
        // so we must check if the player is connected
        if(pConnected == 0){
            continue;
        }
        
        // checks to make sure the player is on the opposite team
        if((iTeamNum == 2 && pTeamNum == 3) || (iTeamNum == 3 && pTeamNum == 2)){
            if(highscore < pKills){
                highscore = pKills;
            }
        }
    }
    return iTeamNum;
}

int main(int argc, const char * argv[]) {
    // keyboard listen
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0), ^{
        keyBoardListen();
    });
    
    unsigned long moduleLength = 0x0511e000;
    
    mach_vm_address_t moduleStartAddress;
    pid_t pid = get_process();
    if (pid == -1) {
        printf("Cant find the PID of CSGO\n");
        exit(0);
    } else {
        printf("Found CSGO PID: %i\n", pid);
    }
    
    task_t task;
    task = get_client_module_info(task, pid, &moduleStartAddress, &moduleLength);
    if (task) {
        printf("Found the Client.dylib address: 0x%llx \n", moduleStartAddress);
        printf("Module should end at 0x%llx\n", moduleStartAddress + moduleLength);
    } else {
        printf("Failed to get the Client.dylib address\n");
    }
    
    // info check end
    uint64_t glowObjectLoopStartAddress;
    int glowObjectLoopCount = 0;
    getEntityGlowLoopStartAddressAndCount(task, moduleStartAddress, &glowObjectLoopStartAddress, &glowObjectLoopCount);
    while (true) {
        if (states) {
            int i_teamNum = testLocalPlayerAddress(task, moduleStartAddress);
            readPlayerPointAndHealth(task, current_task(), moduleStartAddress, glowObjectLoopStartAddress, i_teamNum);
        }
        usleep(7800);
    }
}
