#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int html_create(char *src, char *dest, char *path, char *buf_html)
{
	DIR *dir_handle	= NULL;
	struct dirent *entry;
	char ch, *buf = (char *)calloc(1, 80);
	int i = 0;
	FILE *Fdest = fopen(dest, "w");
	FILE *Fsrc = fopen(src, "r");
	if ((NULL == Fsrc) || (NULL == Fdest)) {
		perror("open error");
		return 1;
	}
	while ((ch=fgetc(Fsrc))!=EOF) {
		fputc(ch, Fdest);
	}
	fclose(Fsrc);
	if ((dir_handle = opendir(path)) == NULL) {
		printf("open dir error\n");
		return 1;
	} else {

		while (entry = readdir(dir_handle)) {
			if (strlen(entry->d_name) > 2) {
				sprintf(buf, buf_html, entry->d_name, 
					      i, entry->d_name);
				fwrite(buf, strlen(buf), 1, Fdest);
				fwrite("<br>\n", 5, 1, Fdest);
				i++;
			}
		}
		closedir(dir_handle);
		return 0;
	}

	fclose(Fdest);
}
int main()
{
	html_create("main.html", "../index.html", "../src/",
			"<a href='src/%s/index.html'>%.2d.%s</a>");
	html_create("sub.html", "../src/gnu/index.html", "../src/gnu/",
			"<a href='%s'>%.2d.%s</a>");
	html_create("sub.html", "../src/blog/index.html", "../src/blog/",
			"<a href='%s'>%.2d.%s</a>");
	html_create("sub.html", "../src/cad/index.html", "../src/cad/",
			"<a href='%s'>%.2d.%s</a>");
}
