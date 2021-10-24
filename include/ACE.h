#ifndef _ACE_H_
#define _ACE_H_

void printVersion();
const char* printKernelVersion();
void getAceOsVersion();
void getAceOsBranch();
void getScreenResolution();
void createToast(char* text);
void createSnackbar(char* text);
void SUDOSleep();
void SUDOWake();
void SUDOExitApplication();
void SUDOEnterPowerSavingMode();
void SUDOExitPowerSavingMode();

#endif /* _ACE_H_ */
