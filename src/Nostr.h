#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <esp_task_wdt.h>
#include <OneButton.h>
#include <NostrEvent.h>
#include <NostrRelayManager.h>
#include "drivers/storage/storage.h"
#include "mbedtls/md.h"
#include "wManager.h"
#include "drivers/displays/display.h"
#include "drivers/storage/SDCard.h"
#include "drivers/storage/storage.h"



void nip04Event(const std::string& key, const char* payload);
void initializeNostr();