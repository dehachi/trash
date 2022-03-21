#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* f = popen("free -b | awk 'match($0, /^Mem/){print $3}'", "r");
	char c[100];
	fgets(c, sizeof(c), f);
	float used = atof(c)/1073741824.0f;
	f = popen("free -b | awk 'match($0, /^Mem/){print $2}'", "r");
	fgets(c, sizeof(c), f);
	float total = atof(c)/1073741824.0f;
	printf("memory: [%.2fGiB/%.2fGiB] [%.2f%%]\n", used, total, used/total*100.0f);
	return 0;
}
