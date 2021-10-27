#include <ACE.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

const char* getVersion() {
	return VERSION;
}

void die(char* msg) {
	fprintf(stderr, "ERROR: %s\n", msg);
}

char* putFileInString(char* fp) {
	char* storagebuffer = 0;
	long length;
	FILE* file = fopen(fp, "rb");

	if (file) {
		fseek(file, 0, SEEK_END);
		length = ftell(file);
		fseek(file, 0, SEEK_SET);
		storagebuffer = malloc(length);
		if (storagebuffer) {
			fread(storagebuffer, 1, length, file);
		}
		fclose(file);
	} else {
		die("Unable to open file");
	}

	fclose(file);

	return storagebuffer;
}

void printKernelVersion() {
	struct utsname unameData;
	uname(&unameData);
	printf("%s\n", unameData.release);
}

void parseSecFile(char *data) {}

const char* getAceOsVersion() {
	return putFileInString("/etc/Xenon/release");
}

const char* getAceOsBranch() {
	//Possible: LTS, stable(production), nightly, classified
	return putFileInString("/etc/Xenon/branch");
}

void createToast(char* text) {
	//TODO: Launch an X program that does this
}

void createSnackbar(char* text) {
	//TODO: Launch an X program that does this
}

void getTheme() {
	char* themeData = putFileInString("/etc/Xenon/theme");
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
