#ifndef WATCH_HPP_INCLUDED
#define WATCH_HPP_INCLUDED

#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;
	
class Watch
{
	public:
		time_t now;
		struct tm* pnow;
		
		Watch()
		{
			now = time(NULL);
			pnow = localtime(&now);
			
			char buff[128] = " ";
		}
						
		char seconds(){
			return pnow->tm_sec;
		
			}
		
		char mutes() {
			return pnow->tm_min;
		
			}
		
		char hours() {
			return pnow->tm_hour;
			}
		
		~Watch(){cout << " death" <<endl;}
		
	};

#endif











