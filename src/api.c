#include <ACE.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <string.h>

const char* getVersion() {
	return VERSION;
}

void die(char* msg) {
	fprintf(stderr, "ERROR: %s\n", msg);
	exit(1);
}

static void charToStr(char ch, char string[2]) {
	string[0] = ch;
	string[1] = '\0';
}

// Returns 0 on success, 1 on failure
int putFileInString(char* fp, char content[]) { 
	char ch;
	FILE* file = fopen(fp, "r");

	if (file == NULL)
		return 1;

	while ((ch = fgetc(file)) != EOF) {
		char fakeChar[2];
		charToStr(ch, fakeChar);

		strcat(content, fakeChar);
	}

	fclose(file);

	return 0;
}

void printKernelVersion() {
	struct utsname unameData;
	uname(&unameData);
	printf("%s\n", unameData.release);
}

void parseSecFile(char *data) {}

void printAceOsVersion() {
	char contents[512];
	putFileInString("/opt/Xenon/release", contents);
	printf("%s", contents);
}

const char* getAceOsVersion() {
	//return putFileInString("/opt/Xenon/release");
}

const char* getAceOsBranch() {
	//Possible: LTS, stable(production), nightly, classified
	//return putFileInString("/opt/Xenon/branch");
}

void createToast(char* text) {
	//TODO: Launch an X program that does this
}

void createSnackbar(char* text) {
	//TODO: Launch an X program that does this
}

int getTheme() {
	char themeData[4]; // Little more memory than required
	putFileInString("/etc/Xenon/theme", themeData);
	
	int darkthemeEnabled = atoi(themeData);

	if (darkthemeEnabled) {
		return DARKTHEME;
	} else {
		return LIGHTTHEME;
	}
}

int getBgColor() {
	if (getTheme() == DARKTHEME)
		return DARKBGCOLOR;
	else // Light Theme
		return LIGHTBGCOLOR;
}

int getFgColor() {
	if (getTheme() == DARKTHEME)
		return DARKFGCOLOR;
	else // Light Theme
		return LIGHTFGCOLOR;
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
