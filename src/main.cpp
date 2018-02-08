#include <stdio.h>
#include <string>
#include <Windows.h>

#pragma comment(lib, "urlmon.lib")

void download_file(char *filename, char *url) {
	URLDownloadToFile(NULL, url, filename, 0, NULL);
}

int main(int argc, char* argv[]) {
	/*
        if one argument is given, the Arcdps Files will be removed from the system.

        Todo:
            -remove, should remove Arcdps
            -onlyarc, only Arcdps, NOT Buildtemplates will be downloaded
    */
    if (argc > 1) {
        printf("remove items..\n");

        std::remove("d3d9.dll");
        std::remove("d3d9_arcdps_buildtemplates.dll");
    }
    else {
        printf("download ARCDPS\n");
        download_file("d3d9.dll", "http://www.deltaconnected.com/arcdps/x64/d3d9.dll");

        printf("download Buildtemplates\n");
        download_file("d3d9_arcdps_buildtemplates.dll", "http://www.deltaconnected.com/arcdps/x64/buildtemplates/d3d9_arcdps_buildtemplates.dll");
    }
	
    return 0;
}
