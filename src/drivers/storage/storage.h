#ifndef _STORAGE_H_
#define _STORAGE_H_

#include <Arduino.h>

// config files

// default settings
#define DEFAULT_SSID		"NostrAP"
#define DEFAULT_WIFIPW		"CheckYourMessages"
#define DEFAULT_NOSTR_PRIVATE_KEY "YourNostrPrivateKey"
#define DEFAULT_NOSTR_PUB_KEY "YourNostrPublicKey"
#define DEFAULT_TIMEZONE	1

// JSON config files
#define JSON_CONFIG_FILE	"/config.json"


// JSON config file SPIFFS (different for backward compatibility with existing devices)
#define JSON_SPIFFS_KEY_NOSTR_PRIVATE_KEY    "nostrprivatekey"
#define JSON_SPIFFS_KEY_NOSTR_PUBKEY    "nostrpubkey"
#define JSON_SPIFFS_KEY_TIMEZONE	"gmtZone"

// settings
struct TSettings
{
	String WifiSSID{ DEFAULT_SSID };
	String WifiPW{ DEFAULT_WIFIPW };
	const char * NostrPrivatekey{ DEFAULT_NOSTR_PRIVATE_KEY };
    const char * NostrPubkey{ DEFAULT_NOSTR_PUB_KEY };
	int Timezone{ DEFAULT_TIMEZONE };
};

#endif // _STORAGE_H_