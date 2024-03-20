# Computer Graphic Lab
This repository is dedicated to the concept learnt in Computer Graphics.
Here I will use graphics.h header file for graphics.

Since I am working on Linux(Kali), I had to download the SDL BGI([Borland Graphics Interface](https://home.cs.colorado.edu/~main/bgi/doc/)) debian file and then followed the installation according to the operating system.


## For debian(like kali)

### Step1:
Download the debian file from [here](https://sourceforge.net/projects/sdl-bgi/).
    
### Step2:
Run below command on the terminal from the folder containing sdl_bgi_number.deb(here number denotes version)

        sudo dpkg -i sdl_bgi_number.deb
        
Replace the sdl_bgi_number.deb by actual .deb file downloaded from above link

### Step3:
Compilation of program containing graphics.h file 

    g++ file_name.cpp -lSDL2 -lSDL_bgi object_file_name.o 

### Step4:
Run the object file from terminal:

    ./object_file_name.o 




