# Computer Graphic Lab
This repository is dedicated to the concept learnt in Computer Graphics.
Here I will use graphics.h header file for graphics.

Since I am working on Linux(Kali), I had to download the sdl bgi debian file and then follow the installation acording to the operating system.
For kali:
    step1:
    download from here:
    https://sourceforge.net/projects/sdl-bgi/

    step2:
    run below command on the terminal from the folder containing sdl_bgi_number.deb(here number denotes version)
    sudo dpkg -i sdl_bgi_number.deb

    step3:
    compilation of program containing graphics.h file 
    g++ file_name.cpp -lSDL2 -lgraph object_file_name.o 

    step4:
    run the object file from terminal:
    ./object_file_name.o 




