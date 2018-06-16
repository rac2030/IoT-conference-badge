# Kraftwerk wifi test
Short test application to see if the wifi is stable with the NINA modules.
This is because the APs are configured that weak clients get disconnected to not bring down the network.
We need to test stability for our badges as then the network admin could adjust the paramters to fit our purpose during the event.

# Example log on Serial

    rst:0x1 (POWERON_RESET),boot:0x33 (SPI_FAST_FLASH_BOOT)
    configsip: 0, SPIWP:0xee
    clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
    mode:DIO, clock div:2
    load:0x3fff0018,len:4
    load:0x3fff001c,len:812
    load:0x40078000,len:0
    load:0x40078000,len:11584
    entry 0x40078a60
    Current RSSI=0
    [WiFi-event] event: 2
    Current RSSI=0
    .....[WiFi-event] event: 5
    Current RSSI=0
    WiFi lost connection. Reason: WIFI_REASON_NO_AP_FOUND
    .....Could not connect!
    Current RSSI=0
    .....[WiFi-event] event: 5
    Current RSSI=0
    WiFi lost connection. Reason: WIFI_REASON_NO_AP_FOUND
    .....Could not connect!
    Current RSSI=0
    .......[WiFi-event] event: 4
    Current RSSI=-33
    ...Could not connect!
    [WiFi-event] event: 7
    Current RSSI=-30
    WiFi connected and got IP address: 192.168.43.27
    Current RSSI=-30
    Current RSSI=-30
    Current RSSI=-29
    Current RSSI=-23
    Current RSSI=-39
    Current RSSI=-73
    Current RSSI=-72
    Current RSSI=-84
    Current RSSI=-86
    Current RSSI=-85
    Current RSSI=-87
    Current RSSI=-80
    Current RSSI=-81
    Current RSSI=-79
    Current RSSI=-80
    Current RSSI=-81
    Current RSSI=-84
    Current RSSI=-82
    Current RSSI=-81
    Current RSSI=-81
    Current RSSI=-81
    Current RSSI=-82
    Current RSSI=-85
    Current RSSI=-85
    Current RSSI=-84
    Current RSSI=-84
    Current RSSI=-85
    Current RSSI=-87
    Current RSSI=-86
    Current RSSI=-86
    Current RSSI=-79
    Current RSSI=-90
    Current RSSI=-85
    Current RSSI=-81
    Current RSSI=-64
    Current RSSI=-73
    Current RSSI=-43
    Current RSSI=-30
    Current RSSI=-21
    Current RSSI=-20
    Current RSSI=-30
    Current RSSI=-44
    [WiFi-event] event: 5
    Current RSSI=0
    WiFi lost connection. Reason: WIFI_REASON_AUTH_LEAVE
    Current RSSI=0
    .....[WiFi-event] event: 5
    Current RSSI=0
    WiFi lost connection. Reason: WIFI_REASON_NO_AP_FOUND
    .....Could not connect!
    Current RSSI=0

