#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

/* Goal is to have a cheap wifi arduino with a microphone on it that posts to sms/email/push notification/slack 
 *  if the dog barks. Also, can trigger a playback of a recording of him being told to stop.
 */

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char server[] = "www.google.com";    // name address for Google (using DNS)


void setup() {
  // put your setup code here, to run once:

}

void loop() {

}

void triggerSMS() {
   Serial.println("connecting...");
  String PostData="sample={\"fittingId\":1,";
  unsigned char i;
  for(i=0;i<6;i++)
  {
    PostData=PostData+"\"channel-";
    PostData=String(PostData+i);
    PostData=PostData+"\":";
    PostData=String(PostData + String(analogRead(i)));
    if(i!=5)
      PostData=PostData+",";
  }
    PostData=PostData+"}";  
  Serial.println(PostData);
  if (client.connect()) {
    Serial.println("connected");
  client.println("POST /tinyFittings/index.php HTTP/1.1");
  client.println("Host:  artiswrong.com");
  client.println("User-Agent: Arduino/1.0");
  client.println("Connection: close");
  client.println("Content-Type: application/x-www-form-urlencoded;");
  client.print("Content-Length: ");
  client.println(PostData.length());
  client.println();
  client.println(PostData);
  } else {
    Serial.println("connection failed");
  }
}

void triggetEmail() {
  
}

void triggerPush () {
  
}

void playSound() {
  
}


