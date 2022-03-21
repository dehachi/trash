#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE* f = popen("upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep percentage | grep -o '[0-9]*%' | tr -d '%'", "r");
	char c[20];
	fgets(c, 4, f);
	int per = atoi(c);
	f = popen("upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep state | cut -c 26- | tr -d '\n'", "r");
	fgets(c, sizeof(c), f);
	if (!strcmp(c,"charging")) {
		printf("battery: %d%% [CHR]\n", per);
	} else {
		printf("battery: %d%%\n", per);
	}
	return 0;
}
