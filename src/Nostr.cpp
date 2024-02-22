
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

NostrEvent Noostr;
NostrRelayManager nostrrelayManager;
NostrQueueProcessor nostrqueue;


TSettings Settings;

char const *nsecHex = Settings.NostrPrivatekey ; // sender private key in hex e.g. bdd19cecdXXXXXXXXXXXXXXXXXXXXXXXXXX
char const *npubHex = Settings.NostrPubkey;

void nip04Event(const std::string& key, const char* payload) {
    Serial.println("NIP04 event");
    String dmMessage = Noostr.decryptDm(nsecHex, payload);
    Serial.println("message is: ");
    Serial.println(dmMessage);

}



void initializeNostr() {
    const char *const relays[] = {
      "relay.damus.io",
      "nostr.mom",
      "relay.nostr.bg",
      "nos.lol",
      "nostr.bitcoiner.social",
      "nostr.wine",
      "eden.nostr.land",
      "relay.orangepill.dev",
    };
    int relayCount = sizeof(relays) / sizeof(relays[0]);
    
    Noostr.setLogging(true);
    nostrrelayManager.setMinRelaysAndTimeout(2,10000);

    // Set some event specific callbacks here
    nostrrelayManager.setEventCallback("nip04", nip04Event);
    nostrrelayManager.connect();
}