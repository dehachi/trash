#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* f = popen("mpstat -P ALL -A 1 1 | grep -v CPU | sed '/^$/d' | cut -c 92-", "r");
	char c[100];
	fgets(c, sizeof(c), f);
	float per = 100.00f-atof(c);
	printf("cpu: [all:%.2f%%", per);
	for (int i=0; i<4; i++) {
		fgets(c, sizeof(c), f);
		per = 100.00f-atof(c);
		printf(", s%d:%.2f%%", i, per);
	}
	printf("] [");
	f = popen("sensors | grep Core | cut -c 17-20", "r");
	for (int i=0; i<2; i++) {
		fgets(c, sizeof(c), f);
		per = atof(c);
		if (i) printf("c%d:%.1fc°]", i, per);
		else printf("c%d:%.1fc°, ", i, per);
	}
	f = popen("sensors | grep fan1 | cut -c 6-", "r");
	fgets(c, sizeof(c), f);
	int rpm = atoi(c);
	printf(" [fan:%drpm]\n" ,rpm);
	return 0;
}
