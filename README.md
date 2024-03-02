# NostrNotifier


<img src="https://img.shields.io/github/last-commit/miguepollo/Nostr-notifier.svg?style=for-the-badge" />
<img src="https://img.shields.io/github/commit-activity/m/miguepollo/Nostr-notifier?style=for-the-badge" />

**The NostrNotifier **

This is a **free and open source project** that let you see your private and public messages with a small piece of hardware.



![image](ponerimagen)

## Requirements

- TTGO T-Display S3 
- 3D BOX [here](3d_files/)

### Project description

This project was initialy developed using ESP32-S3, but currently support other boards. It uses WifiManager to modify miner settings and save them to SPIFF.

Hablar de las screens 



**_Current project is still in developement and more features will be added_**

## Build Tutorial

### Hardware requirements

- LILYGO T-Display S3 
- 3D BOX [here](3d_files/)

#### Current Supported Boards

- LILYGO T-Display S3 ([Aliexpress link\*](https://es.aliexpress.com/item/1005004496543314.html?spm=a2g0o.productlist.main.3.8255XScrXScr5V&algo_pvid=cf5b8699-f425-4f5f-bca3-009f6c21061d&utparam-url=scene%3Asearch%7Cquery_from%3A&gatewayAdapt=glo2esp))

### Flash firmware

#### Standard tool

Create your own miner using the online firwmare flash tool **ESPtool** and one of the **binary files** that you will find in the `bin` folder.
If you want you can compile the entire project using Arduino, PlatformIO or Expressif IDF.

1. Get a TTGO T-display S3
1. Download this repository
1. Go to ESPtool online: https://espressif.github.io/esptool-js/
1. Load the firmware with the binary from one of the sub-folders of `bin` corresponding to your board.
1. Plug your board and select each file from the sub-folder (`.bin` files).

### Update firmware

Update NostrNotifier firmware following same flashing steps but only using the file 0x10000_firmware.bin.

#### Build troubleshooting

1. Online [ESP Tool](https://espressif.github.io/esptool-js/) works with chrome, chromium, brave
1. ESPtool recommendations: use 115200bps
1. Build errors > If during firmware download upload stops, it's recommended to enter the board in boot mode. Unplug cable, hold right bottom button and then plug cable. Try programming
1. In extreme case you can "Erase all flash" on ESPtool to clean all current configuration before uploading firmware. There has been cases that experimented Wifi failures until this was made.
## Nostr configuration

After programming, you will only need to setup your Wifi and Nostr Private Key.


#### Wifi Accesspoint


1. Connect to NostrAP
   - AP: NostrAP
   - PASS: CheckYourMessages
1. Set up your Wifi Network
1. Add your Nostr Private Key

## Developers

### Project guidelines

- Current project was adapted to work with PlatformIO
- Current project works with ESP32-S3.
- Partition squeme should be build as huge app
- All libraries needed shown on platform.ini

### Job done

- [x] Move project to platformIO
- [x] Bug memory leaks
- [x] Bug Reboots when received JSON contains some null values
- [x] Implement midstate sha256
- [x] Bug Wificlient DNS unresolved on Wifi.h
- [x] Code refactoring
- [x] Add clock to show current time
- [x] Add support to TTGO T-display 1.14

### In process

- [ ] Create a daisy chain protocol via UART or I2C to support ESP32 hashboards
- [ ] Create new screen like clockMiner but with BTC price
- [ ] Add support to control BM1397
- [ ] Add password field in web configuration form

