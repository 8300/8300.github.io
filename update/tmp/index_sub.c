#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 0;
	DIR *dirptr = NULL;
	struct dirent *entry;
	char ch, *path = "../src/blog/";
	char *path_blog = "src/blog/";
	char *np_blog = (char *)calloc(1, 43);
	char *tmp = (char *)calloc(1, 80);
	char *im_blog = "i_blog.html", *i_blog = "index.html";
	sprintf(np_blog, "%s%s", path, i_blog);
	FILE *Fblog	= fopen(np_blog, "w");
	FILE *Fi_blog	= fopen(im_blog, "r");
	if ((NULL == Fblog) || (NULL == Fi_blog)) {
		perror("open error");
		return 1;
	}
	while ((ch=fgetc(Fi_blog))!=EOF) {
		fputc(ch, Fblog);
	}
	fclose(Fi_blog);
	if ((dirptr = opendir(path)) == NULL) {
		printf("open dir error\n");
		return 1;
	} else {

		while (entry = readdir(dirptr)) {
			if (strlen(entry->d_name) > 3) {
				//sprintf(tmp, "<a href='%s%s' >%s</a>", path_blog, 
				sprintf(tmp, "<a href='%s'>%.2d.%s</a>",  
						entry->d_name, i, entry->d_name);
				fwrite(tmp, strlen(tmp), 1, Fblog);
				printf("%s\n", entry->d_name);
				fwrite("<br>\n", 5, 1, Fblog);
			}
			i++;
		}
		closedir(dirptr);
		return 0;
	}
	fclose(Fblog);
}
