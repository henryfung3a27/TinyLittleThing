const char* get_ip(char host[]) {
	char command[100] = "";
	char result[100] = "";
	char* ip = malloc(sizeof(char) * 16);
	int i = -1, j;
	FILE *fp;
	ip[0] = '\0';
	sprintf(command, "ping %s -n 1 -l 1", host);
	
	fp = popen(command, "r");
	while (fgets(result, sizeof(result), fp) != NULL) {
		if (result[0] == 10) continue;		// skip checking the first line
		
		for (i = 0; i < 100; i++) {
			if (result[i] == '[') {
				for (j = 0; result[i+j+1] != ']'; j++)
					ip[j] = result[i+j+1];
				pclose(fp);
				return ip;
			}
		}
	}
	printf("Host not found");
	pclose(fp);
	return 0;
}
