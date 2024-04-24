#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for

// Macro to pause and clear the screen
#define PAUSE_CLEAR \
    std::this_thread::sleep_for(std::chrono::milliseconds{520}); \
    system("clear");

// Macro to display a frame, pause, and clear
#define DISPLAY_FRAME(frame) \
    frame(); \
    PAUSE_CLEAR

// Macro to run the animation sequence
#define RUN_ANIMATION(frames, count) \
    for (int i = 0; i < count; ++i) { \
        DISPLAY_FRAME(frames[i]); \
    }

void animateGun() {
    const int TOTAL_FRAMES = sizeof(frames) / sizeof(frames[0]); // Total number of frames
    RUN_ANIMATION(frames, TOTAL_FRAMES);
}


void printFullGun();
void cutGun();
void printFrame1();
void printFrame2();
void printFrame3();
void printFrame4();
void printFrame5();
void printFrame6();
void printFrame7();
void printFrame8();
void printFrame9();
void (*frames[])() = {
    printFullGun,
    printFrame1,
    printFrame2,
    printFrame3,
    printFrame4,
    printFrame5,
    printFrame6,
    printFrame7,
    printFrame8,
    printFrame9
};


void printFullGun() {
    std::cout <<
    " ,________________________________\n"
    "|__________,----------._ [____]  \"\"-,__  __...-----===\n"
    "        (_(||||||||||||)___________/   \"\"             |\n"
    "           `----------'        [ ))\"-,                |\n"
    "                                \"\"    `,  _,--...___  |\n"
    "                                        `/          \"\"\"\n";
}

void printFrame1() {
    std::cout <<
    R"(
 ,_________________________________
|__________,----------._ [____]  ""-,__  __...-----===
        (_(||||||||||||)___________/   ""             |
           `----------'         [ ))\"-,               |
                                ""    `,  _,----...___ |
                                        `/          """
    )";
}


void printFrame2() {
    std::cout <<
    R"(
     \
 ,__|_\_____________________________
|___ __\______,----------._ [____]  ""-,__  __...-----===
    |   \ (_(||||||||||||)___________/   ""             |
    \   |    `----------'       [ ))\"-,                |
     \  |                       ""    `,  _,----...___  |
      \ |                                 `/          """
    )";
}

void printFrame3() {
    std::cout <<
    R"(
     \
 ,__|_\_____________________________
|___ __\______,----------._ [____]  ""-,__  __...-----===
    |   \ (_(||||||||||||)___________/   ""             |
    \   |    `----------'       [ ))\"-,                |
     \  |                       ""    `,_ _,----...___  |
      \ |                                 `/          """
       \|
    )";
}
void printFrame4() {
    std::cout <<
    R"(
      
       
 ,__|_\_____________________________
|___ __\______,----------._ [____]  ""-,__  __...-----===
    |   \ (_(||||||||||||)___________/   ""             |
    \   |    `----------'       [ ))\"-,                |
     \  |                       ""    `,_ _,----...___  |
      \ |                                 `           """
       \|
        \
    )";
}

void printFrame5() {
    std::cout <<
    R"(
        
         
 ,__|_\_____________________________
|___ __\______,----------._ [____]  ""-,__  __...-----===
    |   \ (_(||||||||||||)___________/   ""             |
    \   |    `----------'       [ ))\"-,                |
     \  |                       ""    `,___,----...___  |
      \ |                                 `/          """
       \|
        \
         \
    )";
}


void printFrame6() {
    std::cout <<
    R"(
           
            
 ,__|_\_____\________________________
|___ __\_____,----------._ [____]  ""-,__  __...-----===
    |   \    \(_(|||||||)_ ________/   ""             |
    \   |     `----------'       [ ))\"-,             |
     \  |                        ""    `,_ _,----...__|
      \ |                                  `/         "
       \|
        \
         \
          \
    )";
}
void printFrame7() {
    std::cout <<
    R"(
            
             
| |  |_ \_____\________________________
| |  __\_____,----------._ [____]  ""-,__  __...-----===
| |  |     \    \(_(|||||||)_ ________/   ""             |
      \     |     `----------'       [ ))\"-,             |
       \    |                        ""    `,__,----...__|
        \   |                                             "
         \  |
          \
           \
            \
    )";
}

void printFrame8() {
    std::cout <<
    R"(
            
             
     |_ \_____\________________________
| |  __\_____,----------._ [____]  ""-,__  __...-----===
| |  |     \    \(_(|||||||)_ ________/   ""             |
| |     \     |     `----------'       [ ))\"-,             |
        \    |                        ""    `,__,----...__|
         \   |                                  `/         "
          \  |
           
            
             
    )";
}

void printFrame9() {
    std::cout <<
    R"(
            
             
      ______________________________
     ________,----------._ [____]  ""-,__  __...-----===
              \(_(|||||||)_ ________/   ""             |
                  `----------'       [ ))\"-,             |
                                      ""    `,___,----...__|
                                                         "
| |              
| |            
| |           
              
    )";
}

void cutGun() {
    std::cout <<
    R"(
            
             
      ______________________________
     ________,----------._ [____]  ""-,__  __...-----===
              \(_(|||||||)_ ________/   ""             |
                  `----------'       [ ))\"-,             |
                                      ""    `,___,----...__|
                                                         "       
    )";
}
