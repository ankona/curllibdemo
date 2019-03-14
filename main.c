#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

typedef struct wd {
    char* url;
} writedata;

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp)
{
    writedata* wd = (writedata*)userp;
    printf("received %lu bytes from %s\n", strlen(buffer), wd->url);
//    printf("%s", buffer);
    return strlen(buffer);
}

int main() {
    printf("Hello, World!\n");

    int curlCode = curl_global_init(CURL_GLOBAL_NOTHING);
    printf("curlCode: %i\n", curlCode);

    CURL *curl = curl_easy_init();
//    CURL *curl = (CURL*)curl_global_init(CURL_GLOBAL_DEFAULT);
    if (curl) {
        CURLcode response;
        writedata wd;
        wd.url = "https://example.com";
//        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        curl_easy_setopt(curl, CURLOPT_URL, wd.url);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &wd);


        FILE* fp = fopen("test.txt", "w+");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        response = curl_easy_perform(curl);

        fclose(fp);
        curl_easy_cleanup(curl);
    }
//    curl_global_cleanup();
    return 0;
}