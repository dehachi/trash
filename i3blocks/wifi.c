#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE* f = popen("wpa_cli -i wlan0 status | grep ssid | grep -v bssid | cut -c 6- | tr -d '\n'", "r");
	char c[20];
	fgets(c, sizeof(c), f);
	printf("wi-fi: %s", c);
	f = popen("iw dev wlan0 link | grep signal | cut -c 10- | cut -c -4", "r");
	fgets(c, sizeof(c), f);
	int dbm = atoi(c);
	printf(" [%ddBm]\n", dbm);
	return 0;
}
