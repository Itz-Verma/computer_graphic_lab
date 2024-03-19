#include <graphics.h>

int main() {

    int graphicsDriver = DETECT; // DETECT: macro which detect the graphic driver automatically.
    
    int graphicsMode;
    
    char* graphicsDriverDirectoryPath = NULL;

    //initialize graph 
    initgraph(&graphicsDriver, &graphicsMode, graphicsDriverDirectoryPath);
    
    //stop all process for 1000ms.
    delay(1000);
    
    closegraph();

    return 0;
}
