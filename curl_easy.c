#include <stdio.h>

#include <curl/curl.h>
int main(void)
{
	FILE *file = NULL;
	curl_global_init(CURL_GLOBAL_ALL);
	
	CURL *image = curl_easy_init();	
	
	if (image){
		/*Open file for writing*/
		file = fopen("/home/moritz/Documents/c_kurs/project/testfile.jpg", "w");
		if ( !file) {
			perror("Fehler beim Schreiben.");
		}

		CURLcode imagres;	
		/*Set curl settings*/
		curl_easy_setopt(image, CURLOPT_URL, "http://apod.nasa.gov/apod/image/1602/Tarantula-HST-ESO-M.jpg");
		curl_easy_setopt(image, CURLOPT_WRITEFUNCTION, NULL);	
		curl_easy_setopt(image, CURLOPT_WRITEDATA, file);

		/*Perform the transfer*/
		imagres = curl_easy_perform(image);
		if (imagres){
			printf("Fehler.\n");
		}
		/*Clean up*/
		curl_easy_cleanup(image);
		fclose(file);
		return 0;
	}
}
