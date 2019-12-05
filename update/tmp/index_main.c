#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 0;
	char ch;
	char *buf = (char *)calloc(1, 80);
	char *path = "../src/";
	char *path_rel = "src/";
	DIR *dir_handle	= NULL;
	struct dirent *entry;
	char *sub_index = "sub.html", *index = "index.html";
	FILE *Findex = fopen("../index.html", "w");
	FILE *Fsub = fopen(sub_index, "r");
	if ((NULL == Findex) || (NULL == Fsub)) {
		perror("open error");
		return 1;
	}
	while ((ch=fgetc(Fsub))!=EOF) {
		fputc(ch, Findex);
	}
	fclose(Fsub);
	if ((dir_handle = opendir(path)) == NULL) {
		printf("open dir error\n");
		return 1;
	} else {

		while (entry = readdir(dir_handle)) {
			if (strlen(entry->d_name) > 2) {
				sprintf(buf, "<a href='%s%s/index.html'>%.2d.%s</a>", 
					      path_rel, entry->d_name, 
					      i, entry->d_name);
				fwrite(buf, strlen(buf), 1, Findex);
				fwrite("<br>\n", 5, 1, Findex);
				i++;
			}
		}
		closedir(dir_handle);
		return 0;
	}

	fclose(Findex);
}
