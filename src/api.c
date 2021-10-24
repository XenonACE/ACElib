#include <ACE.h>
#include <stdio.h>
#include <sys/utsname.h>

void printVersion() {
	printf(VERSION"\n");
}

const char* printKernelVersion() {
	struct utsname udata;

	if (uname(&udata) < 0) {
		printf("uname\n");
		return NULL;
	}

	return bprintf("%s", udata.release);
}

void getAceOsVersion() {
	//TODO: read version from some file in /opt/Xenon
}

void getAceOsBranch() {
	//TODO:
	//Possible: LTS, stable(production), nightly, classified
}

void getScreenResolution() {
	//TODO: Some Xorg implementation
}

void createToast(char* text) {
	//TODO: Launch an X program that does this
}

void createSnackbar(char* text) {
	//TODO: Launch an X program that does this
}

void SUDOSleep() {
	//TODO: Same as pressing the power button
	//display shuts off
	//usb is disabled
	//applications get suspended with SIG 19
}

void SUDOWake() {
	//TODO: Wake the phone to the lock screen
	//display turns back on
	//usb is probably still disabled
	//applications get resumed with SIG 18
}

void SUDOExitApplication() {
	//TODO: Maybe some call to dwm or X that gets the name of the window then sends the exit code
}

void SUDOEnterPowerSavingMode() {
	//TODO: run programs with cpulimit and change screen resolution with xrandr
}

void SUDOExitPowerSavingMode() {
	//TODO: Opposite of Entering Power Saving
}

//TODO: Make toggles for these
//Enable/disable Wi-Fi (sudo) 
//Enable/disable Bluetooth (sudo) 
//Turn on flashlight 
