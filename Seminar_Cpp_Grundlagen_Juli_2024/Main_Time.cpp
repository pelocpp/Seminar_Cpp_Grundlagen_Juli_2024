#include <iostream>

#include "Time.h"

void main_time()
{
    // int  n;

    Time now;

    // aus mehreren Gründen schlecht: falsche Werte // direkter Zugriff
    // now.m_hours = 999;  
    // now.m_minutes = 25;
    // now.m_seconds = 30;

    // setter
    now.setHours(999);
    now.setMinutes(16);
    now.setSeconds(20);

    now.setMilliseconds(500);


    //Time pause;
    //pause.setHours(12);
    //pause.setMinutes(30);
    //pause.setSeconds(0);

    // besser:
    // 2 Dinge: Objekte anlegen && vorbelegen (initialisieren)
    Time pause (12, 30, 0);
    int h = pause.getHours();

    pause.setHours(9999);
    pause.setMinutes(0);

    now.print();

    pause.print();

    // ============================

    if (now.equals(pause)) {
        std::cout << "sind gleich" << std::endl;
    }
    else {
        std::cout << "sind nicht gleich" << std::endl;
    }
}


// ========================================================

