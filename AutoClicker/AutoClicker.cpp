#include <iostream>
#include <Windows.h>
#include <thread>

bool bEnabled = false;

void listenForInput ( )
{
    while ( true ) 
    {
        if ( GetAsyncKeyState ( VK_INSERT ) & 0x01 )
        {
            bEnabled = !bEnabled;
        }
    }
}

int main()
{
    std::thread t( listenForInput );

    while ( true )
    {
        if ( bEnabled ) 
        {

            mouse_event ( MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 );

            Sleep ( 100 );

            mouse_event ( MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
        }
    }
    
    t.join ( );

    return 0;
}
