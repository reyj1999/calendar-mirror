/***************************************************************************
 *   Author Alan Crispin                 *
 *   crispinalan@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation.                                  *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/
#include "speechengine.h"

SpeechEngine::SpeechEngine()
{
			
	dict = new Dictionary();	
	setupLookupOrdinalNumber();
    setupLookupCardinalNumber();
    setupLookupMonth();
    setupLookupDay(); 
}

QDate SpeechEngine::calculateEaster(int year) {
  QDate easter;
  int Yr = year;
  int a = Yr % 19;
  int b = Yr / 100;
  int c = Yr % 100;
  int d = b / 4;
  int e = b % 4;
  int f = (b + 8) / 25;
  int g = (b - f + 1) / 3;
  int h = (19 * a + b - d - g + 15) % 30;
  int i = c / 4;
  int k = c % 4;
  int L = (32 + 2 * e + 2 * i - h - k) % 7;
  int m = (a + 11 * h + 22 * L) / 451;
  int month = (h + L - 7 * m + 114) / 31;
  int day = ((h + L - 7 * m + 114) % 31) + 1;

  easter.setDate(year, month, day);
  return easter;
}


QString SpeechEngine::getDiphonePath(QString dipStr){
	 //aa diphones   
   if (dipStr=="aa-aa") return QApplication::applicationDirPath()+"/diphone/aa-aa.wav";  
   else if (dipStr=="aa-ae") return QApplication::applicationDirPath()+"/diphone/aa-ae.wav";
   else if (dipStr=="aa-ah") return QApplication::applicationDirPath()+"/diphone/aa-ah.wav";
   else if (dipStr=="aa-ao") return QApplication::applicationDirPath()+"/diphone/aa-ao.wav"; 
   else if (dipStr=="aa-aw") return QApplication::applicationDirPath()+"/diphone/aa-aw.wav"; 
   else if (dipStr=="aa-ax") return QApplication::applicationDirPath()+"/diphone/aa-ax.wav"; 
   else if (dipStr=="aa-ay") return QApplication::applicationDirPath()+"/diphone/aa-ay.wav";
   else if (dipStr=="aa-b") return QApplication::applicationDirPath()+"/diphone/aa-b.wav"; 
   else if (dipStr=="aa_ch") return QApplication::applicationDirPath()+"/diphone/aa-ch.wav"; 
   else if (dipStr=="aa-d") return QApplication::applicationDirPath()+"/diphone/aa-d.wav";
   else if(dipStr =="aa-dh") return QApplication::applicationDirPath()+"/diphone/aa-dh.wav";
   else if(dipStr =="aa-eh") return QApplication::applicationDirPath()+"/diphone/aa-eh.wav";
   else if(dipStr =="aa-er") return QApplication::applicationDirPath()+"/diphone/aa-er.wav";
   else if(dipStr =="aa-ey") return QApplication::applicationDirPath()+"/diphone/aa-ey.wav";
   else if(dipStr =="aa-f") return QApplication::applicationDirPath()+"/diphone/aa-f.wav"; 
   else if(dipStr =="aa-g") return QApplication::applicationDirPath()+"/diphone/aa-g.wav";
   else if(dipStr =="aa-hh") return QApplication::applicationDirPath()+"/diphone/aa-hh.wav";
   else if(dipStr =="aa-ih") return QApplication::applicationDirPath()+"/diphone/aa-ih.wav";
   else if(dipStr =="aa-iy") return QApplication::applicationDirPath()+"/diphone/aa-iy.wav";
   else if(dipStr =="aa-jh") return QApplication::applicationDirPath()+"/diphone/aa-jh.wav";
   else if(dipStr =="aa-k") return QApplication::applicationDirPath()+"/diphone/aa-k.wav";
   else if(dipStr =="aa-l") return QApplication::applicationDirPath()+"/diphone/aa-l.wav";
   else if(dipStr =="aa-m") return QApplication::applicationDirPath()+"/diphone/aa-m.wav";
   else if(dipStr =="aa-n") return QApplication::applicationDirPath()+"/diphone/aa-n.wav";
   else if(dipStr =="aa-ng") return QApplication::applicationDirPath()+"/diphone/aa-ng.wav";
   else if(dipStr =="aa-ow") return QApplication::applicationDirPath()+"/diphone/aa-ow.wav";
   else if(dipStr =="aa-oy") return QApplication::applicationDirPath()+"/diphone/aa-oy.wav";
   else if(dipStr =="aa-p") return QApplication::applicationDirPath()+"/diphone/aa-p.wav";
   else if(dipStr =="aa-pau") return QApplication::applicationDirPath()+"/diphone/aa-pau.wav";
   else if(dipStr =="aa-r") return QApplication::applicationDirPath()+"/diphone/aa-r.wav";
   else if(dipStr =="aa-s") return QApplication::applicationDirPath()+"/diphone/aa-s.wav";
   else if(dipStr =="aa-sh") return QApplication::applicationDirPath()+"/diphone/aa-sh.wav";
   else if(dipStr =="aa-t") return QApplication::applicationDirPath()+"/diphone/aa-t.wav";
   else if(dipStr =="aa-th") return QApplication::applicationDirPath()+"/diphone/aa-th.wav";
   else if(dipStr =="aa-uh") return QApplication::applicationDirPath()+"/diphone/aa-uh.wav";
   else if(dipStr =="aa-uw") return QApplication::applicationDirPath()+"/diphone/aa-uw.wav";
   else if(dipStr =="aa-v") return QApplication::applicationDirPath()+"/diphone/aa-v.wav";
   else if(dipStr =="aa-w") return QApplication::applicationDirPath()+"/diphone/aa-w.wav";
   else if(dipStr =="aa-y") return QApplication::applicationDirPath()+"/diphone/aa-y.wav";
   else if(dipStr =="aa-z") return QApplication::applicationDirPath()+"/diphone/aa-z.wav";
   else if(dipStr =="aa-zh") return QApplication::applicationDirPath()+"/diphone/aa-zh.wav"; 
    
   // ae diphones
	else if(dipStr=="ae-aa") return QApplication::applicationDirPath()+"/diphone/ae-aa.wav";  
	else if(dipStr=="ae-ae") return QApplication::applicationDirPath()+"/diphone/ae-ae.wav";
	else if(dipStr=="ae-ah") return QApplication::applicationDirPath()+"/diphone/ae-ah.wav";
	else if(dipStr=="ae-ao") return QApplication::applicationDirPath()+"/diphone/ae-ao.wav"; 
	else if(dipStr=="ae-aw") return QApplication::applicationDirPath()+"/diphone/ae-aw.wav"; 
	else if(dipStr=="aeax") return QApplication::applicationDirPath()+"/diphone/ae-ax.wav"; 
	else if(dipStr=="ae-ay") return QApplication::applicationDirPath()+"/diphone/ae-ay.wav";
	else if(dipStr=="ae-b") return QApplication::applicationDirPath()+"/diphone/ae-b.wav";  
	else if(dipStr=="ae-ch") return QApplication::applicationDirPath()+"/diphone/ae-ch.wav"; 
	else if(dipStr=="a-d") return QApplication::applicationDirPath()+"/diphone/ae-d.wav";
	else if(dipStr=="ae-dh") return QApplication::applicationDirPath()+"/diphone/ae-dh.wav";
	else if(dipStr=="ae-eh") return QApplication::applicationDirPath()+"/diphone/ae-eh.wav";
	else if(dipStr=="ae-er") return QApplication::applicationDirPath()+"/diphone/ae-er.wav";
	else if(dipStr=="ae-ey") return QApplication::applicationDirPath()+"/diphone/ae-ey.wav";
	else if(dipStr=="ae-f") return QApplication::applicationDirPath()+"/diphone/ae-f.wav"; 
	else if(dipStr=="ae-g") return QApplication::applicationDirPath()+"/diphone/ae-g.wav";
	else if(dipStr=="ae-hh") return QApplication::applicationDirPath()+"/diphone/ae-hh.wav";
	else if(dipStr=="ae-ih") return QApplication::applicationDirPath()+"/diphone/ae-ih.wav";
	else if(dipStr=="ae-iy") return QApplication::applicationDirPath()+"/diphone/ae-iy.wav";
	else if(dipStr=="ae-jh") return QApplication::applicationDirPath()+"/diphone/ae-jh.wav";
	else if(dipStr=="ae-k") return QApplication::applicationDirPath()+"/diphone/ae-k.wav";
	else if(dipStr=="ae-l") return QApplication::applicationDirPath()+"/diphone/ae-l.wav";
	else if(dipStr=="ae-m") return QApplication::applicationDirPath()+"/diphone/ae-m.wav";
	else if(dipStr=="ae-n") return QApplication::applicationDirPath()+"/diphone/ae-n.wav";
	else if(dipStr=="ae-ng") return QApplication::applicationDirPath()+"/diphone/ae-ng.wav";
	else if(dipStr=="ae-ow") return QApplication::applicationDirPath()+"/diphone/ae-ow.wav";
	else if(dipStr=="ae-oy") return QApplication::applicationDirPath()+"/diphone/ae-oy.wav";
	else if(dipStr=="ae-p") return QApplication::applicationDirPath()+"/diphone/ae-p.wav";
	else if(dipStr=="ae-pau") return QApplication::applicationDirPath()+"/diphone/ae-pau.wav";
	else if(dipStr=="ae-r") return QApplication::applicationDirPath()+"/diphone/ae-r.wav";
	else if(dipStr=="ae-s") return QApplication::applicationDirPath()+"/diphone/ae-s.wav";
	else if(dipStr=="ae -sh") return QApplication::applicationDirPath()+"/diphone/ae-sh.wav";
	else if(dipStr=="ae-t") return QApplication::applicationDirPath()+"/diphone/ae-t.wav";
	else if(dipStr=="ae-th") return QApplication::applicationDirPath()+"/diphone/ae-th.wav";
	else if(dipStr=="ae-uh") return QApplication::applicationDirPath()+"/diphone/ae-uh.wav";
	else if(dipStr=="ae-uw") return QApplication::applicationDirPath()+"/diphone/ae-uw.wav";
	else if(dipStr=="ae-v") return QApplication::applicationDirPath()+"/diphone/ae-v.wav";
	else if(dipStr=="ae-w") return QApplication::applicationDirPath()+"/diphone/ae-w.wav";
	else if(dipStr=="ae-y") return QApplication::applicationDirPath()+"/diphone/ae-y.wav";
	else if(dipStr=="ae-z") return QApplication::applicationDirPath()+"/diphone/ae-z.wav";
	else if(dipStr=="ae-zh") return QApplication::applicationDirPath()+"/diphone/ae-zh.wav";       
	 
    // ah diphones
	 else if(dipStr == "ah-aa") return QApplication::applicationDirPath()+"/diphone/ah-aa.wav";  
	 else if(dipStr == "ah-ae") return QApplication::applicationDirPath()+"/diphone/ah-ae.wav"; 
	 else if(dipStr == "ah-ah") return QApplication::applicationDirPath()+"/diphone/ah-ah.wav"; 
	 else if(dipStr == "ah-ao") return QApplication::applicationDirPath()+"/diphone/ah-ao.wav";  
	 else if(dipStr == "ah-aw") return QApplication::applicationDirPath()+"/diphone/ah-aw.wav";  
	 else if(dipStr == "ah-ax") return QApplication::applicationDirPath()+"/diphone/ah-ax.wav";  
	 else if(dipStr == "ah-ay") return QApplication::applicationDirPath()+"/diphone/ah-ay.wav"; 
	 else if(dipStr == "ah-b") return QApplication::applicationDirPath()+"/diphone/ah-b.wav";   
	 else if(dipStr == "ah-ch") return QApplication::applicationDirPath()+"/diphone/ah-ch.wav"; 
	 else if(dipStr == "ah-d") return QApplication::applicationDirPath()+"/diphone/ah-d.wav"; 
	 else if(dipStr == "ah-dh") return QApplication::applicationDirPath()+"/diphone/ah-dh.wav"; 
	 else if(dipStr == "ah-eh") return QApplication::applicationDirPath()+"/diphone/ah-eh.wav"; 
	 else if(dipStr == "ah-er") return QApplication::applicationDirPath()+"/diphone/ah-er.wav"; 
	 else if(dipStr == "ah-ey") return QApplication::applicationDirPath()+"/diphone/ah-ey.wav"; 
	 else if(dipStr == "ah-f") return QApplication::applicationDirPath()+"/diphone/ah-f.wav";  
	 else if(dipStr == "ah-g") return QApplication::applicationDirPath()+"/diphone/ah-g.wav"; 
	 else if(dipStr == "ah-hh") return QApplication::applicationDirPath()+"/diphone/ah-hh.wav"; 
	 else if(dipStr == "ah-ih") return QApplication::applicationDirPath()+"/diphone/ah-ih.wav"; 
	 else if(dipStr == "ah-iy") return QApplication::applicationDirPath()+"/diphone/ah-iy.wav"; 
	 else if(dipStr == "ah-jh") return QApplication::applicationDirPath()+"/diphone/ah-jh.wav"; 
	 else if(dipStr == "ah-k") return QApplication::applicationDirPath()+"/diphone/ah-k.wav"; 
	 else if(dipStr == "ah-l") return QApplication::applicationDirPath()+"/diphone/ah-l.wav"; 
	 else if(dipStr == "ah-m") return QApplication::applicationDirPath()+"/diphone/ah-m.wav"; 
	 else if(dipStr == "ah-n") return QApplication::applicationDirPath()+"/diphone/ah-n.wav"; 
	 else if(dipStr == "ah-ng") return QApplication::applicationDirPath()+"/diphone/ah-ng.wav"; 
	 else if(dipStr == "ah-ow") return QApplication::applicationDirPath()+"/diphone/ah-aow.wav"; 
	 else if(dipStr == "ah-oy") return QApplication::applicationDirPath()+"/diphone/ah-oy.wav"; 
	 else if(dipStr == "ah-p") return QApplication::applicationDirPath()+"/diphone/ah-p.wav"; 
	 else if(dipStr == "ah-pau") return QApplication::applicationDirPath()+"/diphone/ah-pau.wav"; 
	 else if(dipStr == "ah-r") return QApplication::applicationDirPath()+"/diphone/ah-r.wav"; 
	 else if(dipStr == "ah-s") return QApplication::applicationDirPath()+"/diphone/ah-s.wav"; 
	 else if(dipStr == "ah-sh") return QApplication::applicationDirPath()+"/diphone/ah-sh.wav"; 
	 else if(dipStr == "ah-t") return QApplication::applicationDirPath()+"/diphone/ah-t.wav"; 
	 else if(dipStr == "ah-th") return QApplication::applicationDirPath()+"/diphone/ah-th.wav"; 
	 else if(dipStr == "ah-uh") return QApplication::applicationDirPath()+"/diphone/ah-uh.wav"; 
	 else if(dipStr == "ah-uw") return QApplication::applicationDirPath()+"/diphone/ah-uw.wav"; 
	 else if(dipStr == "ah-v") return QApplication::applicationDirPath()+"/diphone/ah-v.wav"; 
	 else if(dipStr == "ah-w") return QApplication::applicationDirPath()+"/diphone/ah-w.wav"; 
	 else if(dipStr == "ah-y") return QApplication::applicationDirPath()+"/diphone/ah-y.wav"; 
	 else if(dipStr == "ah-z") return QApplication::applicationDirPath()+"/diphone/ah-z.wav"; 
	 else if(dipStr == "ah-zh") return QApplication::applicationDirPath()+"/diphone/ah-zh.wav";       
 
 // ao diphones
	 else if(dipStr == "ao-aa") return QApplication::applicationDirPath()+"/diphone/ao-aa.wav";   
	 else if(dipStr == "ao-ae") return QApplication::applicationDirPath()+"/diphone/ao-ae.wav"; 
	 else if(dipStr == "ao-ah") return QApplication::applicationDirPath()+"/diphone/ao-ah.wav"; 
	 else if(dipStr == "ao-ao") return QApplication::applicationDirPath()+"/diphone/ao-ao.wav";  
	 else if(dipStr == "ao-aw") return QApplication::applicationDirPath()+"/diphone/ao-aw.wav";  
	 else if(dipStr == "ao-ax") return QApplication::applicationDirPath()+"/diphone/ao-ax.wav";  
	 else if(dipStr == "ao-ay") return QApplication::applicationDirPath()+"/diphone/ao-ay.wav"; 
	 else if(dipStr == "ao-b") return QApplication::applicationDirPath()+"/diphone/ao-b.wav";   
	 else if(dipStr == "ao-ch") return QApplication::applicationDirPath()+"/diphone/ao-ch.wav"; 
	 else if(dipStr == "ao-d") return QApplication::applicationDirPath()+"/diphone/ao-d.wav"; 
	 else if(dipStr == "ao-dh") return QApplication::applicationDirPath()+"/diphone/ao-dh.wav"; 
	 else if(dipStr == "ao-eh") return QApplication::applicationDirPath()+"/diphone/ao-eh.wav"; 
	 else if(dipStr == "ao-er") return QApplication::applicationDirPath()+"/diphone/ao-er.wav"; 
	 else if(dipStr == "ao-ey") return QApplication::applicationDirPath()+"/diphone/ao-ey.wav"; 
	 else if(dipStr == "ao-f") return QApplication::applicationDirPath()+"/diphone/ao-f.wav";  
	 else if(dipStr == "ao-g") return QApplication::applicationDirPath()+"/diphone/ao-g.wav"; 
	 else if(dipStr == "ao-hh") return QApplication::applicationDirPath()+"/diphone/ao-hh.wav"; 
	 else if(dipStr == "ao-ih") return QApplication::applicationDirPath()+"/diphone/ao-ih.wav"; 
	 else if(dipStr == "ao-iy") return QApplication::applicationDirPath()+"/diphone/ao-iy.wav"; 
	 else if(dipStr == "ao-jh") return QApplication::applicationDirPath()+"/diphone/ao-jh.wav"; 
	 else if(dipStr == "ao-k") return QApplication::applicationDirPath()+"/diphone/ao-k.wav"; 
	 else if(dipStr == "ao-l") return QApplication::applicationDirPath()+"/diphone/ao-l.wav"; 
	 else if(dipStr == "ao-m") return QApplication::applicationDirPath()+"/diphone/ao-m.wav"; 
	 else if(dipStr == "ao-n") return QApplication::applicationDirPath()+"/diphone/ao-n.wav"; 
	 else if(dipStr == "ao-ng") return QApplication::applicationDirPath()+"/diphone/ao-ng.wav"; 
	 else if(dipStr == "ao-ow") return QApplication::applicationDirPath()+"/diphone/ao-ow.wav"; 
	 else if(dipStr == "ao-oy") return QApplication::applicationDirPath()+"/diphone/ao-oy.wav"; 
	 else if(dipStr == "ao-p") return QApplication::applicationDirPath()+"/diphone/ao-p.wav"; 
	 else if(dipStr == "ao-pau") return QApplication::applicationDirPath()+"/diphone/ao-pau.wav"; 
	 else if(dipStr == "ao-r") return QApplication::applicationDirPath()+"/diphone/ao-r.wav"; 
	 else if(dipStr == "ao-s") return QApplication::applicationDirPath()+"/diphone/ao-s.wav"; 
	 else if(dipStr == "ao-sh") return QApplication::applicationDirPath()+"/diphone/ao-sh.wav"; 
	 else if(dipStr == "ao-t") return QApplication::applicationDirPath()+"/diphone/ao-t.wav"; 
	 else if(dipStr == "ao-th") return QApplication::applicationDirPath()+"/diphone/ao-th.wav"; 
	 else if(dipStr == "ao-uh") return QApplication::applicationDirPath()+"/diphone/ao-uh.wav"; 
	 else if(dipStr == "ao-uw") return QApplication::applicationDirPath()+"/diphone/ao-uw.wav"; 
	 else if(dipStr == "ao-v") return QApplication::applicationDirPath()+"/diphone/ao-v.wav"; 
	 else if(dipStr == "ao-w") return QApplication::applicationDirPath()+"/diphone/ao-w.wav"; 
	 else if(dipStr == "ao-y") return QApplication::applicationDirPath()+"/diphone/ao-y.wav"; 
	 else if(dipStr == "ao-z") return QApplication::applicationDirPath()+"/diphone/ao-z.wav"; 
	 else if(dipStr == "ao-zh") return QApplication::applicationDirPath()+"/diphone/ao-zh.wav";  
	 
// aw diphones
	else if (dipStr == "aw-aa") return QApplication::applicationDirPath()+"/diphone/aw-aa.wav";  
	else if (dipStr == "aw-ae") return QApplication::applicationDirPath()+"/diphone/aw-ae.wav"; 
	else if (dipStr == "aw-ah") return QApplication::applicationDirPath()+"/diphone/aw-ah.wav";
	else if (dipStr == "aw-ao") return QApplication::applicationDirPath()+"/diphone/aw-ao.wav"; 
	else if (dipStr == "aw-aw") return QApplication::applicationDirPath()+"/diphone/aw-aw.wav"; 
	else if (dipStr == "aw-ax") return QApplication::applicationDirPath()+"/diphone/aw-ax.wav"; 
	else if (dipStr == "aw-ay") return QApplication::applicationDirPath()+"/diphone/aw-ay.wav";
	else if (dipStr == "aw-b") return QApplication::applicationDirPath()+"/diphone/aw-b.wav";  
	else if (dipStr == "aw-ch") return QApplication::applicationDirPath()+"/diphone/aw-ch.wav"; 
	else if (dipStr == "aw-d") return QApplication::applicationDirPath()+"/diphone/aw-d.wav";
	else if (dipStr == "aw-dh") return QApplication::applicationDirPath()+"/diphone/aw-dh.wav";
	else if (dipStr == "aw-eh") return QApplication::applicationDirPath()+"/diphone/aw-eh.wav";
	else if (dipStr == "aw-er") return QApplication::applicationDirPath()+"/diphone/aw-er.wav";
	else if (dipStr == "aw-ey") return QApplication::applicationDirPath()+"/diphone/aw-ey.wav";
	else if (dipStr == "aw-f") return QApplication::applicationDirPath()+"/diphone/aw-f.wav"; 
	else if (dipStr == "aw-g") return QApplication::applicationDirPath()+"/diphone/aw-g.wav";
	else if (dipStr == "aw-hh") return QApplication::applicationDirPath()+"/diphone/aw-hh.wav";
	else if (dipStr == "aw-ih") return QApplication::applicationDirPath()+"/diphone/aw-ih.wav";
	else if (dipStr == "aw-iy") return QApplication::applicationDirPath()+"/diphone/aw-iy.wav";
	else if (dipStr == "aw-jh") return QApplication::applicationDirPath()+"/diphone/aw-jh.wav";
	else if (dipStr == "aw-k") return QApplication::applicationDirPath()+"/diphone/aw-k.wav";
	else if (dipStr == "aw-l") return QApplication::applicationDirPath()+"/diphone/aw-l.wav";
	else if (dipStr == "aw-m") return QApplication::applicationDirPath()+"/diphone/aw-m.wav";
	else if (dipStr == "aw-n") return QApplication::applicationDirPath()+"/diphone/aw-n.wav";
	else if (dipStr == "aw-ng") return QApplication::applicationDirPath()+"/diphone/aw-ng.wav";
	else if (dipStr == "aw-ow") return QApplication::applicationDirPath()+"/diphone/aw-ow.wav";
	else if (dipStr == "aw-oy") return QApplication::applicationDirPath()+"/diphone/aw-oy.wav";
	else if (dipStr == "aw-p") return QApplication::applicationDirPath()+"/diphone/aw-p.wav";
	else if (dipStr == "aw-pau") return QApplication::applicationDirPath()+"/diphone/aw-pau.wav";
	else if (dipStr == "aw-r") return QApplication::applicationDirPath()+"/diphone/aw-r.wav";
	else if (dipStr == "aw-s") return QApplication::applicationDirPath()+"/diphone/aw-s.wav";
	else if (dipStr == "aw-sh") return QApplication::applicationDirPath()+"/diphone/aw-sh.wav";
	else if (dipStr == "aw-t") return QApplication::applicationDirPath()+"/diphone/aw-t.wav";
	else if (dipStr == "aw-th") return QApplication::applicationDirPath()+"/diphone/aw-th.wav";
	else if (dipStr == "aw-uh") return QApplication::applicationDirPath()+"/diphone/aw-uh.wav";
	else if (dipStr == "aw-uw") return QApplication::applicationDirPath()+"/diphone/aw-uw.wav";
	else if (dipStr == "aw-v") return QApplication::applicationDirPath()+"/diphone/aw-v.wav";
	else if (dipStr == "aw-w") return QApplication::applicationDirPath()+"/diphone/aw-w.wav";
	else if (dipStr == "aw-y") return QApplication::applicationDirPath()+"/diphone/aw-y.wav";
	else if (dipStr == "aw-z") return QApplication::applicationDirPath()+"/diphone/aw-z.wav";
	else if (dipStr == "aw-zh") return QApplication::applicationDirPath()+"/diphone/aw-zh.wav";         

// ax diphones
	else if(dipStr == "ax-aa") return QApplication::applicationDirPath()+"/diphone/ax-aa.wav";  
	else if(dipStr == "ax-ae") return QApplication::applicationDirPath()+"/diphone/ax-ae.wav"; 
	else if(dipStr == "ax-ah") return QApplication::applicationDirPath()+"/diphone/ax-ah.wav"; 
	else if(dipStr == "ax-ao") return QApplication::applicationDirPath()+"/diphone/ax-ao.wav";  
	else if(dipStr == "ax-aw") return QApplication::applicationDirPath()+"/diphone/ax-aw.wav";  
	else if(dipStr == "ax-ax") return QApplication::applicationDirPath()+"/diphone/ax-ax.wav"; 
	else if(dipStr == "ax-ay") return QApplication::applicationDirPath()+"/diphone/ax-ay.wav"; 
	else if(dipStr == "ax-b") return QApplication::applicationDirPath()+"/diphone/ax-b.wav";  
	else if(dipStr == "ax-ch") return QApplication::applicationDirPath()+"/diphone/ax-ch.wav";  
	else if(dipStr == "ax-d") return QApplication::applicationDirPath()+"/diphone/ax-d.wav"; 
	else if(dipStr == "ax-dh") return QApplication::applicationDirPath()+"/diphone/ax-dh.wav"; 
	else if(dipStr == "ax-eh") return QApplication::applicationDirPath()+"/diphone/ax-eh.wav"; 
	else if(dipStr == "ax-er") return QApplication::applicationDirPath()+"/diphone/ax-er.wav"; 
	else if(dipStr == "ax-ey") return QApplication::applicationDirPath()+"/diphone/ax-ey.wav"; 
	else if(dipStr == "ax-f") return QApplication::applicationDirPath()+"/diphone/ax-f.wav"; 
	else if(dipStr == "ax-g") return QApplication::applicationDirPath()+"/diphone/ax-g.wav"; 
	else if(dipStr == "ax-hh") return QApplication::applicationDirPath()+"/diphone/ax-hh.wav"; 
	else if(dipStr == "ax-ih") return QApplication::applicationDirPath()+"/diphone/ax-ih.wav"; 
	else if(dipStr == "ax-iy") return QApplication::applicationDirPath()+"/diphone/ax-iy.wav"; 
	else if(dipStr == "ax-jh") return QApplication::applicationDirPath()+"/diphone/ax-jh.wav"; 
	else if(dipStr == "ax-k") return QApplication::applicationDirPath()+"/diphone/ax-k.wav"; 
	else if(dipStr == "ax-l") return QApplication::applicationDirPath()+"/diphone/ax-l.wav"; 
	else if(dipStr == "ax-m") return QApplication::applicationDirPath()+"/diphone/ax-m.wav"; 
	else if(dipStr == "ax-n") return QApplication::applicationDirPath()+"/diphone/ax-n.wav"; 
	else if(dipStr == "ax-ng") return QApplication::applicationDirPath()+"/diphone/ax-ng.wav"; 
	else if(dipStr == "ax-ow") return QApplication::applicationDirPath()+"/diphone/ax-ow.wav"; 
	else if(dipStr == "ax-oy") return QApplication::applicationDirPath()+"/diphone/ax-oy.wav"; 
	else if(dipStr == "ax-p") return QApplication::applicationDirPath()+"/diphone/ax-p.wav"; 
	else if(dipStr == "ax-pau") return QApplication::applicationDirPath()+"/diphone/ax-pau.wav"; 
	else if(dipStr == "ax-r") return QApplication::applicationDirPath()+"/diphone/ax-r.wav"; 
	else if(dipStr == "ax-s") return QApplication::applicationDirPath()+"/diphone/ax-s.wav"; 
	else if(dipStr == "ax-sh") return QApplication::applicationDirPath()+"/diphone/ax-sh.wav"; 
	else if(dipStr == "ax-t") return QApplication::applicationDirPath()+"/diphone/ax-t.wav"; 
	else if(dipStr == "ax-th") return QApplication::applicationDirPath()+"/diphone/ax-th.wav"; 
	else if(dipStr == "ax-uh") return QApplication::applicationDirPath()+"/diphone/ax-uh.wav"; 
	else if(dipStr == "ax-uw") return QApplication::applicationDirPath()+"/diphone/ax-uw.wav"; 
	else if(dipStr == "ax-v") return QApplication::applicationDirPath()+"/diphone/ax-v.wav"; 
	else if(dipStr == "ax-w") return QApplication::applicationDirPath()+"/diphone/ax-w.wav"; 
	else if(dipStr == "ax-y") return QApplication::applicationDirPath()+"/diphone/ax-y.wav"; 
	else if(dipStr == "ax-z") return QApplication::applicationDirPath()+"/diphone/ax-z.wav"; 
	else if(dipStr == "ax-zh") return QApplication::applicationDirPath()+"/diphone/ax-zh.wav";    
	
// ay diphones
	else if(dipStr == "ay-aa") return QApplication::applicationDirPath()+"/diphone/ay-aa.wav";  
	else if(dipStr == "ay-ae") return QApplication::applicationDirPath()+"/diphone/ay-ae.wav";
	else if(dipStr == "ay-ah") return QApplication::applicationDirPath()+"/diphone/ay-ah.wav";
	else if(dipStr == "ay-ao") return QApplication::applicationDirPath()+"/diphone/ay-ao.wav"; 
	else if(dipStr == "ay-aw") return QApplication::applicationDirPath()+"/diphone/ay-aw.wav"; 
	else if(dipStr == "ay-ax") return QApplication::applicationDirPath()+"/diphone/ay-ax.wav"; 
	else if(dipStr == "ay-ay") return QApplication::applicationDirPath()+"/diphone/ay-ay.wav";
	else if(dipStr == "ay-b") return QApplication::applicationDirPath()+"/diphone/ay-b.wav";
	else if(dipStr == "ay-ch") return QApplication::applicationDirPath()+"/diphone/ay-ch.wav"; 
	else if(dipStr == "ay-d") return QApplication::applicationDirPath()+"/diphone/ay-d.wav";
	else if(dipStr == "ay-dh") return QApplication::applicationDirPath()+"/diphone/ay-dh.wav";
	else if(dipStr == "ay-eh") return QApplication::applicationDirPath()+"/diphone/ay-eh.wav";
	else if(dipStr == "ay-er") return QApplication::applicationDirPath()+"/diphone/ay-er.wav";
	else if(dipStr == "ay-ey") return QApplication::applicationDirPath()+"/diphone/ay-ey.wav";
	else if(dipStr == "ay-f") return QApplication::applicationDirPath()+"/diphone/ay-f.wav"; 
	else if(dipStr == "ay-g") return QApplication::applicationDirPath()+"/diphone/ay-g.wav";
	else if(dipStr == "ay-hh") return QApplication::applicationDirPath()+"/diphone/ay-hh.wav";
	else if(dipStr == "ay-ih") return QApplication::applicationDirPath()+"/diphone/ay-ih.wav";
	else if(dipStr == "ay-iy") return QApplication::applicationDirPath()+"/diphone/ay-iy.wav";
	else if(dipStr == "ay-jh") return QApplication::applicationDirPath()+"/diphone/ay-jh.wav";
	else if(dipStr == "ay-k") return QApplication::applicationDirPath()+"/diphone/ay-k.wav";
	else if(dipStr == "ay-l") return QApplication::applicationDirPath()+"/diphone/ay-l.wav";
	else if(dipStr == "ay-m") return QApplication::applicationDirPath()+"/diphone/ay-m.wav";
	else if(dipStr == "ay-n") return QApplication::applicationDirPath()+"/diphone/ay-n.wav";
	else if(dipStr == "ay-ng") return QApplication::applicationDirPath()+"/diphone/ay-ng.wav";
	else if(dipStr == "ay-ow") return QApplication::applicationDirPath()+"/diphone/ay-ow.wav";
	else if(dipStr == "ay-oy") return QApplication::applicationDirPath()+"/diphone/ay-oy.wav";
	else if(dipStr == "ay-p") return QApplication::applicationDirPath()+"/diphone/ay-p.wav";
	else if(dipStr == "ay-pau") return QApplication::applicationDirPath()+"/diphone/ay-pau.wav";
	else if(dipStr == "ay-r") return QApplication::applicationDirPath()+"/diphone/ay-r.wav";
	else if(dipStr == "ay-s") return QApplication::applicationDirPath()+"/diphone/ay-s.wav";
	else if(dipStr == "ay-sh") return QApplication::applicationDirPath()+"/diphone/ay-sh.wav";
	else if(dipStr == "ay-t") return QApplication::applicationDirPath()+"/diphone/ay-t.wav";
	else if(dipStr == "ay-th") return QApplication::applicationDirPath()+"/diphone/ay-th.wav";
	else if(dipStr == "ay-uh") return QApplication::applicationDirPath()+"/diphone/ay-uh.wav";
	else if(dipStr == "ay-uw") return QApplication::applicationDirPath()+"/diphone/ay-uw.wav";
	else if(dipStr == "ay-v") return QApplication::applicationDirPath()+"/diphone/ay-v.wav";
	else if(dipStr == "ay-w") return QApplication::applicationDirPath()+"/diphone/ay-w.wav";
	else if(dipStr == "ay-y") return QApplication::applicationDirPath()+"/diphone/ay-y.wav";
	else if(dipStr == "ay-z") return QApplication::applicationDirPath()+"/diphone/ay-z.wav";
	else if(dipStr == "ay-zh") return QApplication::applicationDirPath()+"/diphone/ay-zh.wav";   
	
// b diphones
	else if(dipStr == "b-aa") return QApplication::applicationDirPath()+"/diphone/b-aa.wav";   
	else if(dipStr == "b-ae") return QApplication::applicationDirPath()+"/diphone/b-aae.wav";
	else if(dipStr == "b-ah") return QApplication::applicationDirPath()+"/diphone/b-ah.wav";
	else if(dipStr == "b-ao") return QApplication::applicationDirPath()+"/diphone/b-ao.wav"; 
	else if(dipStr == "b-aw") return QApplication::applicationDirPath()+"/diphone/b-aw.wav"; 
	else if(dipStr == "b-ax") return QApplication::applicationDirPath()+"/diphone/b-ax.wav"; 
	else if(dipStr == "b-ay") return QApplication::applicationDirPath()+"/diphone/b-ay.wav";
	else if(dipStr == "b-b") return QApplication::applicationDirPath()+"/diphone/b-b.wav";  
	else if(dipStr == "b-ch") return QApplication::applicationDirPath()+"/diphone/b-ch.wav"; 
	else if(dipStr == "b-d") return QApplication::applicationDirPath()+"/diphone/b-d.wav";
	else if(dipStr == "b-dh") return QApplication::applicationDirPath()+"/diphone/b-dh.wav";
	else if(dipStr == "b-eh") return QApplication::applicationDirPath()+"/diphone/b-eh.wav";
	else if(dipStr == "b-er") return QApplication::applicationDirPath()+"/diphone/b-er.wav";
	else if(dipStr == "b-ey") return QApplication::applicationDirPath()+"/diphone/b-ay.wav";
	else if(dipStr == "b-f") return QApplication::applicationDirPath()+"/diphone/b-f.wav";
	else if(dipStr == "b-g") return QApplication::applicationDirPath()+"/diphone/b-g.wav";
	else if(dipStr == "b-hh") return QApplication::applicationDirPath()+"/diphone/b-hh.wav";
	else if(dipStr == "b-ih") return QApplication::applicationDirPath()+"/diphone/b-ih.wav";
	else if(dipStr == "b-iy") return QApplication::applicationDirPath()+"/diphone/b-iy.wav";
	else if(dipStr == "b-jh") return QApplication::applicationDirPath()+"/diphone/b-jh.wav";
	else if(dipStr == "b-k") return QApplication::applicationDirPath()+"/diphone/b-k.wav";
	else if(dipStr == "b-l") return QApplication::applicationDirPath()+"/diphone/b-l.wav";
	else if(dipStr == "b-m") return QApplication::applicationDirPath()+"/diphone/b-m.wav";
	else if(dipStr == "b-n") return QApplication::applicationDirPath()+"/diphone/b-n.wav";
	else if(dipStr == "b-ow") return QApplication::applicationDirPath()+"/diphone/b-ow.wav";
	else if(dipStr == "b-oy") return QApplication::applicationDirPath()+"/diphone/b-oy.wav";
	else if(dipStr == "b-p") return QApplication::applicationDirPath()+"/diphone/b-p.wav";
	else if(dipStr == "b-pau") return QApplication::applicationDirPath()+"/diphone/b-pau.wav";
	else if(dipStr == "b-r") return QApplication::applicationDirPath()+"/diphone/b-r.wav";
	else if(dipStr == "b-s") return QApplication::applicationDirPath()+"/diphone/b-s.wav";
	else if(dipStr == "b-sh") return QApplication::applicationDirPath()+"/diphone/b-sh.wav";
	else if(dipStr == "b-t") return QApplication::applicationDirPath()+"/diphone/b-t.wav";
	else if(dipStr == "b-th") return QApplication::applicationDirPath()+"/diphone/b-th.wav";
	else if(dipStr == "b-uh") return QApplication::applicationDirPath()+"/diphone/b-uh.wav";
	else if(dipStr == "b-uw") return QApplication::applicationDirPath()+"/diphone/b-uw.wav";
	else if(dipStr == "b-v") return QApplication::applicationDirPath()+"/diphone/b-v.wav";
	else if(dipStr == "b-w") return QApplication::applicationDirPath()+"/diphone/b-w.wav";
	else if(dipStr == "b-y") return QApplication::applicationDirPath()+"/diphone/b-y.wav";
	else if(dipStr == "b-z") return QApplication::applicationDirPath()+"/diphone/b-z.wav";
	else if(dipStr == "b-zh") return QApplication::applicationDirPath()+"/diphone/b-zh.wav";  
	
// ch diphones
	else if(dipStr == "ch-aa") return QApplication::applicationDirPath()+"/diphone/ch-aa.wav";  
	else if(dipStr == "ch-ae") return QApplication::applicationDirPath()+"/diphone/ch-ae.wav";
	else if(dipStr == "ch-ah") return QApplication::applicationDirPath()+"/diphone/ch-ah.wav";
	else if(dipStr == "ch-ao") return QApplication::applicationDirPath()+"/diphone/ch-ao.wav"; 
	else if(dipStr == "ch-aw") return QApplication::applicationDirPath()+"/diphone/ch-aw.wav";
	else if(dipStr == "ch-ax") return QApplication::applicationDirPath()+"/diphone/ch-ax.wav"; 
	else if(dipStr == "ch-ay") return QApplication::applicationDirPath()+"/diphone/ch-ay.wav";
	else if(dipStr == "ch-b") return QApplication::applicationDirPath()+"/diphone/ch-b.wav";  
	else if(dipStr == "ch-ch") return QApplication::applicationDirPath()+"/diphone/ch-ch.wav"; 
	else if(dipStr == "ch-d") return QApplication::applicationDirPath()+"/diphone/ch-d.wav";
	else if(dipStr == "ch-dh") return QApplication::applicationDirPath()+"/diphone/ch-dh.wav";
	else if(dipStr == "ch-eh") return QApplication::applicationDirPath()+"/diphone/ch-eh.wav";
	else if(dipStr == "ch-er") return QApplication::applicationDirPath()+"/diphone/ch-er.wav";
	else if(dipStr == "ch-ey") return QApplication::applicationDirPath()+"/diphone/ch-ey.wav";
	else if(dipStr == "ch-f") return QApplication::applicationDirPath()+"/diphone/ch-f.wav"; 
	else if(dipStr == "ch-g") return QApplication::applicationDirPath()+"/diphone/ch-g.wav";
	else if(dipStr == "ch-hh") return QApplication::applicationDirPath()+"/diphone/ch-hh.wav";
	else if(dipStr == "ch-ih") return QApplication::applicationDirPath()+"/diphone/ch-ih.wav";
	else if(dipStr == "ch-iy") return QApplication::applicationDirPath()+"/diphone/ch-iy.wav";
	else if(dipStr == "ch-jh") return QApplication::applicationDirPath()+"/diphone/ch-jh.wav";
	else if(dipStr == "ch-k") return QApplication::applicationDirPath()+"/diphone/ch-k.wav";
	else if(dipStr == "ch-l") return QApplication::applicationDirPath()+"/diphone/ch-l.wav";
	else if(dipStr == "ch-m") return QApplication::applicationDirPath()+"/diphone/ch-m.wav";
	else if(dipStr == "ch-n") return QApplication::applicationDirPath()+"/diphone/ch-aa.wav";
	else if(dipStr == "ch-ow") return QApplication::applicationDirPath()+"/diphone/ch-ow.wav";
	else if(dipStr == "ch-oy") return QApplication::applicationDirPath()+"/diphone/ch-oy.wav";
	else if(dipStr == "ch-p") return QApplication::applicationDirPath()+"/diphone/ch-p.wav";
	else if(dipStr == "ch-pau") return QApplication::applicationDirPath()+"/diphone/ch-pau.wav";
	else if(dipStr == "ch-r") return QApplication::applicationDirPath()+"/diphone/ch-r.wav";
	else if(dipStr == "ch-s") return QApplication::applicationDirPath()+"/diphone/ch-s.wav";
	else if(dipStr == "ch-sh") return QApplication::applicationDirPath()+"/diphone/ch-sh.wav";
	else if(dipStr == "ch-t") return QApplication::applicationDirPath()+"/diphone/ch-t.wav";
	else if(dipStr == "ch-th") return QApplication::applicationDirPath()+"/diphone/ch-th.wav";
	else if(dipStr == "ch-uh") return QApplication::applicationDirPath()+"/diphone/ch-uh.wav";
	else if(dipStr == "ch-uw") return QApplication::applicationDirPath()+"/diphone/ch-uw.wav";
	else if(dipStr == "ch-v") return QApplication::applicationDirPath()+"/diphone/ch-v.wav";
	else if(dipStr == "ch-w") return QApplication::applicationDirPath()+"/diphone/ch-w.wav";
	else if(dipStr == "ch-y") return QApplication::applicationDirPath()+"/diphone/ch-y.wav";
	else if(dipStr == "ch-z") return QApplication::applicationDirPath()+"/diphone/ch-z.wav";
	else if(dipStr == "ch-zh") return QApplication::applicationDirPath()+"/diphone/ch-zh.wav";   
	
// d diphones
	else if(dipStr == "d-aa") return QApplication::applicationDirPath()+"/diphone/d-aa.wav"; 
	else if(dipStr == "d-ae") return QApplication::applicationDirPath()+"/diphone/d-ae.wav"; 
	else if(dipStr == "d-ah") return QApplication::applicationDirPath()+"/diphone/d-ah.wav"; 
	else if(dipStr == "d-ao") return QApplication::applicationDirPath()+"/diphone/d-ao.wav";  
	else if(dipStr == "d-aw") return QApplication::applicationDirPath()+"/diphone/d-aw.wav";  
	else if(dipStr == "d-ax") return QApplication::applicationDirPath()+"/diphone/d-ax.wav";  
	else if(dipStr == "d-ay") return QApplication::applicationDirPath()+"/diphone/d-ay.wav"; 
	else if(dipStr == "d-b") return QApplication::applicationDirPath()+"/diphone/d-b.wav";   
	else if(dipStr == "d-ch") return QApplication::applicationDirPath()+"/diphone/d-ch.wav";  
	else if(dipStr == "d-d") return QApplication::applicationDirPath()+"/diphone/d-d.wav"; 
	else if(dipStr == "d-dh") return QApplication::applicationDirPath()+"/diphone/d-dh.wav"; 
	else if(dipStr == "d-eh") return QApplication::applicationDirPath()+"/diphone/d-eh.wav"; 
	else if(dipStr == "d-er") return QApplication::applicationDirPath()+"/diphone/d-er.wav"; 
	else if(dipStr == "d-ey") return QApplication::applicationDirPath()+"/diphone/d-ey.wav"; 
	else if(dipStr == "d-f") return QApplication::applicationDirPath()+"/diphone/d-f.wav"; 
	else if(dipStr == "d-g") return QApplication::applicationDirPath()+"/diphone/d-g.wav"; 
	else if(dipStr == "d-hh") return QApplication::applicationDirPath()+"/diphone/d-hh.wav"; 
	else if(dipStr == "d-ih") return QApplication::applicationDirPath()+"/diphone/d-ih.wav"; 
	else if(dipStr == "d-iy") return QApplication::applicationDirPath()+"/diphone/d-iy.wav"; 
	else if(dipStr == "d-jh") return QApplication::applicationDirPath()+"/diphone/d-jh.wav"; 
	else if(dipStr == "d-k") return QApplication::applicationDirPath()+"/diphone/d-k.wav"; 
	else if(dipStr == "d-l") return QApplication::applicationDirPath()+"/diphone/d-l.wav"; 
	else if(dipStr == "d-m") return QApplication::applicationDirPath()+"/diphone/d-m.wav"; 
	else if(dipStr == "d-n") return QApplication::applicationDirPath()+"/diphone/d-n.wav"; 
	else if(dipStr == "d-ow") return QApplication::applicationDirPath()+"/diphone/d-ow.wav"; 
	else if(dipStr == "d-oy") return QApplication::applicationDirPath()+"/diphone/d-oy.wav"; 
	else if(dipStr == "d-p") return QApplication::applicationDirPath()+"/diphone/d-p.wav"; 
	else if(dipStr == "d-pau") return QApplication::applicationDirPath()+"/diphone/d-pau.wav"; 
	else if(dipStr == "d-r") return QApplication::applicationDirPath()+"/diphone/d-r.wav"; 
	else if(dipStr == "d-s") return QApplication::applicationDirPath()+"/diphone/d-s.wav"; 
	else if(dipStr == "d-sh") return QApplication::applicationDirPath()+"/diphone/d-sh.wav"; 
	else if(dipStr == "d-t") return QApplication::applicationDirPath()+"/diphone/d-t.wav"; 
	else if(dipStr == "d-th") return QApplication::applicationDirPath()+"/diphone/d-th.wav"; 
	else if(dipStr == "d-uh") return QApplication::applicationDirPath()+"/diphone/d-uh.wav"; 
	else if(dipStr == "d-uw") return QApplication::applicationDirPath()+"/diphone/d-uw.wav"; 
	else if(dipStr == "d-v") return QApplication::applicationDirPath()+"/diphone/d-v.wav"; 
	else if(dipStr == "d-w") return QApplication::applicationDirPath()+"/diphone/d-w.wav"; 
	else if(dipStr == "d-y") return QApplication::applicationDirPath()+"/diphone/d-y.wav"; 
	else if(dipStr == "d-z") return QApplication::applicationDirPath()+"/diphone/d-z.wav"; 
	else if(dipStr == "d-zh") return QApplication::applicationDirPath()+"/diphone/d-zh.wav";   	
	
// dh diphones
	else if(dipStr == "dh-aa") return QApplication::applicationDirPath()+"/diphone/dh-aa.wav";   
	else if(dipStr == "dh-ae") return QApplication::applicationDirPath()+"/diphone/dh-ae.wav"; 
	else if(dipStr == "dh-ah") return QApplication::applicationDirPath()+"/diphone/dh-ah.wav";
	else if(dipStr == "dh-ao") return QApplication::applicationDirPath()+"/diphone/dh-ao.wav"; 
	else if(dipStr == "dh-aw") return QApplication::applicationDirPath()+"/diphone/dh-aw.wav"; 
	else if(dipStr == "dh-ax") return QApplication::applicationDirPath()+"/diphone/dh-ax.wav"; 
	else if(dipStr == "dh-ay") return QApplication::applicationDirPath()+"/diphone/dh-ay.wav";
	else if(dipStr == "dh-b") return QApplication::applicationDirPath()+"/diphone/dh-b.wav";  
	else if(dipStr == "dh-ch") return QApplication::applicationDirPath()+"/diphone/dh-ch.wav";
	else if(dipStr == "dh-d") return QApplication::applicationDirPath()+"/diphone/dh-d.wav";
	else if(dipStr == "dh-dh") return QApplication::applicationDirPath()+"/diphone/dh-dh.wav";
	else if(dipStr == "dh-eh") return QApplication::applicationDirPath()+"/diphone/dh-eh.wav";
	else if(dipStr == "dh-er") return QApplication::applicationDirPath()+"/diphone/dh-er.wav";
	else if(dipStr == "dh-ey") return QApplication::applicationDirPath()+"/diphone/dh-ey.wav";
	else if(dipStr == "dh-f") return QApplication::applicationDirPath()+"/diphone/dh-f.wav"; 
	else if(dipStr == "dh-g") return QApplication::applicationDirPath()+"/diphone/dh-g.wav";
	else if(dipStr == "dh-hh") return QApplication::applicationDirPath()+"/diphone/dh-hh.wav";
	else if(dipStr == "dh-ih") return QApplication::applicationDirPath()+"/diphone/dh-ih.wav";
	else if(dipStr == "dh-iy") return QApplication::applicationDirPath()+"/diphone/dh-iy.wav";
	else if(dipStr == "dh-jh") return QApplication::applicationDirPath()+"/diphone/dh-jh.wav";
	else if(dipStr == "dh-k") return QApplication::applicationDirPath()+"/diphone/dh-k.wav";
	else if(dipStr == "dh-l") return QApplication::applicationDirPath()+"/diphone/dh-l.wav";
	else if(dipStr == "dh-m") return QApplication::applicationDirPath()+"/diphone/dh-m.wav";
	else if(dipStr == "dh-n") return QApplication::applicationDirPath()+"/diphone/dh-n.wav";
	else if(dipStr == "dh-ow") return QApplication::applicationDirPath()+"/diphone/dh-ow.wav";
	else if(dipStr == "dh-oy") return QApplication::applicationDirPath()+"/diphone/dh-oy.wav";
	else if(dipStr == "dh-p") return QApplication::applicationDirPath()+"/diphone/dh-p.wav";
	else if(dipStr == "dh-pau") return QApplication::applicationDirPath()+"/diphone/dh-pau.wav";
	else if(dipStr == "dh-r") return QApplication::applicationDirPath()+"/diphone/dh-r.wav";
	else if(dipStr == "dh-s") return QApplication::applicationDirPath()+"/diphone/dh-s.wav";
	else if(dipStr == "dh-sh") return QApplication::applicationDirPath()+"/diphone/dh-sh.wav";
	else if(dipStr == "dh-t") return QApplication::applicationDirPath()+"/diphone/dh-t.wav";
	else if(dipStr == "dh-th") return QApplication::applicationDirPath()+"/diphone/dh-th.wav";
	else if(dipStr == "dh-uh") return QApplication::applicationDirPath()+"/diphone/dh-uh.wav";
	else if(dipStr == "dh-uw") return QApplication::applicationDirPath()+"/diphone/dh-uw.wav";
	else if(dipStr == "dh-v") return QApplication::applicationDirPath()+"/diphone/dh-v.wav";
	else if(dipStr == "dh-w") return QApplication::applicationDirPath()+"/diphone/dh-w.wav";
	else if(dipStr == "dh-y") return QApplication::applicationDirPath()+"/diphone/dh-y.wav";
	else if(dipStr == "dh-z") return QApplication::applicationDirPath()+"/diphone/dh-z.wav";
	else if(dipStr == "dh-zh") return QApplication::applicationDirPath()+"/diphone/dh-zh.wav";   

// eh diphones
	else if(dipStr == "eh-aa") return QApplication::applicationDirPath()+"/diphone/eh-aa.wav";   
	else if(dipStr == "eh-ae") return QApplication::applicationDirPath()+"/diphone/eh-ae.wav"; 
	else if(dipStr == "eh-ah") return QApplication::applicationDirPath()+"/diphone/eh-ah.wav"; 
	else if(dipStr == "eh-ao") return QApplication::applicationDirPath()+"/diphone/eh-ao.wav"; 
	else if(dipStr == "eh-aw") return QApplication::applicationDirPath()+"/diphone/eh-aw.wav"; 
	else if(dipStr == "eh-ax") return QApplication::applicationDirPath()+"/diphone/eh-ax.wav";  
	else if(dipStr == "eh-ay") return QApplication::applicationDirPath()+"/diphone/eh-ay.wav"; 
	else if(dipStr == "eh-b") return QApplication::applicationDirPath()+"/diphone/eh-b.wav";   
	else if(dipStr == "eh-ch") return QApplication::applicationDirPath()+"/diphone/eh-ch.wav";  
	else if(dipStr == "eh-d") return QApplication::applicationDirPath()+"/diphone/eh-d.wav"; 
	else if(dipStr == "eh-dh") return QApplication::applicationDirPath()+"/diphone/eh-dh.wav"; 
	else if(dipStr == "eh-eh") return QApplication::applicationDirPath()+"/diphone/eh-eh.wav"; 
	else if(dipStr == "eh-er") return QApplication::applicationDirPath()+"/diphone/eh-er.wav"; 
	else if(dipStr == "eh-ey") return QApplication::applicationDirPath()+"/diphone/eh-ey.wav"; 
	else if(dipStr == "eh-f") return QApplication::applicationDirPath()+"/diphone/eh-f.wav";  
	else if(dipStr == "eh-g") return QApplication::applicationDirPath()+"/diphone/eh-g.wav"; 
	else if(dipStr == "eh-hh") return QApplication::applicationDirPath()+"/diphone/eh-hh.wav"; 
	else if(dipStr == "eh-ih") return QApplication::applicationDirPath()+"/diphone/eh-ih.wav"; 
	else if(dipStr == "eh-iy") return QApplication::applicationDirPath()+"/diphone/eh-iy.wav"; 
	else if(dipStr == "eh-jh") return QApplication::applicationDirPath()+"/diphone/eh-jh.wav"; 
	else if(dipStr == "eh-k ") return QApplication::applicationDirPath()+"/diphone/eh-k.wav"; 
	else if(dipStr == "eh-l") return QApplication::applicationDirPath()+"/diphone/eh-l.wav"; 
	else if(dipStr == "eh-m") return QApplication::applicationDirPath()+"/diphone/eh-m.wav"; 
	else if(dipStr == "eh-n") return QApplication::applicationDirPath()+"/diphone/eh-n.wav"; 
	else if(dipStr == "eh-ng") return QApplication::applicationDirPath()+"/diphone/eh-ng.wav"; 
	else if(dipStr == "eh-ow") return QApplication::applicationDirPath()+"/diphone/eh-ow.wav"; 
	else if(dipStr == "eh-oy") return QApplication::applicationDirPath()+"/diphone/eh-oy.wav"; 
	else if(dipStr == "eh-p") return QApplication::applicationDirPath()+"/diphone/eh-p.wav"; 
	else if(dipStr == "eh-pau") return QApplication::applicationDirPath()+"/diphone/eh-pau.wav"; 
	else if(dipStr == "eh-r") return QApplication::applicationDirPath()+"/diphone/eh-r.wav"; 
	else if(dipStr == "eh-s") return QApplication::applicationDirPath()+"/diphone/eh-s.wav"; 
	else if(dipStr == "eh-sh") return QApplication::applicationDirPath()+"/diphone/eh-sh.wav"; 
	else if(dipStr == "eh-t") return QApplication::applicationDirPath()+"/diphone/eh-t.wav"; 
	else if(dipStr == "eh-th") return QApplication::applicationDirPath()+"/diphone/eh-th.wav"; 
	else if(dipStr == "eh-uh") return QApplication::applicationDirPath()+"/diphone/eh-uh.wav"; 
	else if(dipStr == "eh-uw") return QApplication::applicationDirPath()+"/diphone/eh-uw.wav"; 
	else if(dipStr == "eh-v") return QApplication::applicationDirPath()+"/diphone/eh-v.wav"; 
	else if(dipStr == "eh-w") return QApplication::applicationDirPath()+"/diphone/eh-w.wav"; 
	else if(dipStr == "eh-y") return QApplication::applicationDirPath()+"/diphone/eh-y.wav"; 
	else if(dipStr == "eh-z") return QApplication::applicationDirPath()+"/diphone/eh-z.wav"; 
	else if(dipStr == "eh-zh") return QApplication::applicationDirPath()+"/diphone/eh-zh.wav"; 
	
// er diphones
	else if(dipStr == "er-aa") return QApplication::applicationDirPath()+"/diphone/er-aa.wav";  
	else if(dipStr == "er-ae") return QApplication::applicationDirPath()+"/diphone/er-ae.wav";
	else if(dipStr == "er-ah") return QApplication::applicationDirPath()+"/diphone/er-ah.wav";
	else if(dipStr == "er-ao") return QApplication::applicationDirPath()+"/diphone/er-ao.wav"; 
	else if(dipStr == "er-aw") return QApplication::applicationDirPath()+"/diphone/er-aw.wav"; 
	else if(dipStr == "er-ax") return QApplication::applicationDirPath()+"/diphone/er-ax.wav"; 
	else if(dipStr == "er-ay") return QApplication::applicationDirPath()+"/diphone/er-ay.wav";
	else if(dipStr == "er-b") return QApplication::applicationDirPath()+"/diphone/er-b.wav";  
	else if(dipStr == "er-ch") return QApplication::applicationDirPath()+"/diphone/er-ch.wav";
	else if(dipStr == "er-d") return QApplication::applicationDirPath()+"/diphone/er-d.wav";
	else if(dipStr == "er-dh") return QApplication::applicationDirPath()+"/diphone/er-dh.wav";
	else if(dipStr == "er-eh") return QApplication::applicationDirPath()+"/diphone/er-eh.wav";
	else if(dipStr == "er-er") return QApplication::applicationDirPath()+"/diphone/er-er.wav";
	else if(dipStr == "er-ey") return QApplication::applicationDirPath()+"/diphone/er-ey.wav";
	else if(dipStr == "er-f") return QApplication::applicationDirPath()+"/diphone/er-f.wav"; 
	else if(dipStr == "er-g") return QApplication::applicationDirPath()+"/diphone/er-g.wav";
	else if(dipStr == "er-hh") return QApplication::applicationDirPath()+"/diphone/er-hh.wav";
	else if(dipStr == "er-ih") return QApplication::applicationDirPath()+"/diphone/er-ih.wav";
	else if(dipStr == "er-iy") return QApplication::applicationDirPath()+"/diphone/er-iy.wav";
	else if(dipStr == "er-jh") return QApplication::applicationDirPath()+"/diphone/er-jh.wav";
	else if(dipStr == "er-k") return QApplication::applicationDirPath()+"/diphone/er-k.wav";
	else if(dipStr == "er-l") return QApplication::applicationDirPath()+"/diphone/er-l.wav";
	else if(dipStr == "er-m") return QApplication::applicationDirPath()+"/diphone/er-m.wav";
	else if(dipStr == "er-n") return QApplication::applicationDirPath()+"/diphone/er-n.wav";
	else if(dipStr == "er-ow") return QApplication::applicationDirPath()+"/diphone/er-ow.wav";
	else if(dipStr == "er-oy") return QApplication::applicationDirPath()+"/diphone/er-oy.wav";
	else if(dipStr == "er-p") return QApplication::applicationDirPath()+"/diphone/er-p.wav";
	else if(dipStr == "er-pau") return QApplication::applicationDirPath()+"/diphone/er-pau.wav";
	else if(dipStr == "er-r") return QApplication::applicationDirPath()+"/diphone/er-r.wav";
	else if(dipStr == "er-s") return QApplication::applicationDirPath()+"/diphone/er-s.wav";
	else if(dipStr == "er-sh") return QApplication::applicationDirPath()+"/diphone/er-sh.wav";
	else if(dipStr == "er-t") return QApplication::applicationDirPath()+"/diphone/er-t.wav";
	else if(dipStr == "er-th") return QApplication::applicationDirPath()+"/diphone/er-th.wav";
	else if(dipStr == "er-uh") return QApplication::applicationDirPath()+"/diphone/er-uh.wav";
	else if(dipStr == "er-uw") return QApplication::applicationDirPath()+"/diphone/er-uw.wav";
	else if(dipStr == "er-v") return QApplication::applicationDirPath()+"/diphone/er-v.wav";
	else if(dipStr == "er-w") return QApplication::applicationDirPath()+"/diphone/er-w.wav";
	else if(dipStr == "er-y") return QApplication::applicationDirPath()+"/diphone/er-y.wav";
	else if(dipStr == "er-z") return QApplication::applicationDirPath()+"/diphone/er-z.wav";
	else if(dipStr == "er-zh") return QApplication::applicationDirPath()+"/diphone/er-zh.wav";   	

// ey diphones
	else if(dipStr == "ey-aa") return QApplication::applicationDirPath()+"/diphone/ey-aa.wav";   
	else if(dipStr == "ey-ae") return QApplication::applicationDirPath()+"/diphone/ey-ae.wav"; 
	else if(dipStr == "ey-ah") return QApplication::applicationDirPath()+"/diphone/ey-ah.wav"; 
	else if(dipStr == "ey-ao") return QApplication::applicationDirPath()+"/diphone/ey-ao.wav"; 
	else if(dipStr == "ey-aw") return QApplication::applicationDirPath()+"/diphone/ey-aw.wav";  
	else if(dipStr == "ey-ax") return QApplication::applicationDirPath()+"/diphone/ey-ax.wav";  
	else if(dipStr == "ey-ay") return QApplication::applicationDirPath()+"/diphone/ey-ay.wav"; 
	else if(dipStr == "ey-b") return QApplication::applicationDirPath()+"/diphone/ey-b.wav";   
	else if(dipStr == "ey-ch") return QApplication::applicationDirPath()+"/diphone/ey-ch.wav";  
	else if(dipStr == "ey-d") return QApplication::applicationDirPath()+"/diphone/ey-d.wav"; 
	else if(dipStr == "ey-dh") return QApplication::applicationDirPath()+"/diphone/ey-dh.wav"; 
	else if(dipStr == "ey-eh") return QApplication::applicationDirPath()+"/diphone/ey-eh.wav"; 
	else if(dipStr == "ey-er") return QApplication::applicationDirPath()+"/diphone/ey-er.wav"; 
	else if(dipStr == "ey-ey") return QApplication::applicationDirPath()+"/diphone/ey-ey.wav"; 
	else if(dipStr == "ey-f") return QApplication::applicationDirPath()+"/diphone/ey-f.wav"; 
	else if(dipStr == "ey-g") return QApplication::applicationDirPath()+"/diphone/ey-g.wav"; 
	else if(dipStr == "ey-hh") return QApplication::applicationDirPath()+"/diphone/ey-hh.wav"; 
	else if(dipStr == "ey-ih") return QApplication::applicationDirPath()+"/diphone/ey-ih.wav"; 
	else if(dipStr == "ey-iy") return QApplication::applicationDirPath()+"/diphone/ey-iy.wav"; 
	else if(dipStr == "ey-jh") return QApplication::applicationDirPath()+"/diphone/ey-jh.wav"; 
	else if(dipStr == "ey-k") return QApplication::applicationDirPath()+"/diphone/ey-k.wav"; 
	else if(dipStr == "ey-l") return QApplication::applicationDirPath()+"/diphone/ey-l.wav"; 
	else if(dipStr == "ey-m") return QApplication::applicationDirPath()+"/diphone/ey-m.wav"; 
	else if(dipStr == "ey-n") return QApplication::applicationDirPath()+"/diphone/ey-n.wav"; 
	else if(dipStr == "ey-ng") return QApplication::applicationDirPath()+"/diphone/ey-ng.wav"; 
	else if(dipStr == "ey-ow") return QApplication::applicationDirPath()+"/diphone/ey-ow.wav"; 
	else if(dipStr == "ey-oy") return QApplication::applicationDirPath()+"/diphone/ey-oy.wav"; 
	else if(dipStr == "ey-p") return QApplication::applicationDirPath()+"/diphone/ey-p.wav"; 
	else if(dipStr == "ey-pau") return QApplication::applicationDirPath()+"/diphone/ey-pau.wav"; 
	else if(dipStr == "ey-r") return QApplication::applicationDirPath()+"/diphone/ey-r.wav"; 
	else if(dipStr == "ey-s") return QApplication::applicationDirPath()+"/diphone/ey-s.wav"; 
	else if(dipStr == "ey-sh") return QApplication::applicationDirPath()+"/diphone/ey-sh.wav"; 
	else if(dipStr == "ey-t") return QApplication::applicationDirPath()+"/diphone/ey-t.wav"; 
	else if(dipStr == "ey-th") return QApplication::applicationDirPath()+"/diphone/ey-th.wav"; 
	else if(dipStr == "ey-uh") return QApplication::applicationDirPath()+"/diphone/ey-uh.wav"; 
	else if(dipStr == "ey-uw") return QApplication::applicationDirPath()+"/diphone/ey-uw.wav"; 
	else if(dipStr == "ey-v") return QApplication::applicationDirPath()+"/diphone/ey-v.wav"; 
	else if(dipStr == "ey-w") return QApplication::applicationDirPath()+"/diphone/ey-w.wav"; 
	else if(dipStr == "ey-y") return QApplication::applicationDirPath()+"/diphone/ey-y.wav"; 
	else if(dipStr == "ey-z") return QApplication::applicationDirPath()+"/diphone/ey-z.wav"; 
	else if(dipStr == "ey-zh") return QApplication::applicationDirPath()+"/diphone/ey-zh.wav";    	
	
	// f diphones
	else if(dipStr == "f-aa") return QApplication::applicationDirPath()+"/diphone/f-aa.wav"; 
	else if(dipStr == "f-ae") return QApplication::applicationDirPath()+"/diphone/f-ae.wav"; 
	else if(dipStr == "f-ah") return QApplication::applicationDirPath()+"/diphone/f-ah.wav"; 
	else if(dipStr == "f-ao") return QApplication::applicationDirPath()+"/diphone/f-ao.wav";  
	else if(dipStr == "f-aw") return QApplication::applicationDirPath()+"/diphone/f-aw.wav";  
	else if(dipStr == "f-ax") return QApplication::applicationDirPath()+"/diphone/f-ax.wav";  
	else if(dipStr == "f-ay") return QApplication::applicationDirPath()+"/diphone/f-ay.wav"; 
	else if(dipStr == "f-b") return QApplication::applicationDirPath()+"/diphone/f-b.wav";   
	else if(dipStr == "f-ch") return QApplication::applicationDirPath()+"/diphone/f-ch.wav";  
	else if(dipStr == "f-d") return QApplication::applicationDirPath()+"/diphone/f-d.wav"; 
	else if(dipStr == "f-dh") return QApplication::applicationDirPath()+"/diphone/f-dh.wav"; 
	else if(dipStr == "f-eh") return QApplication::applicationDirPath()+"/diphone/f-eh.wav"; 
	else if(dipStr == "f-er") return QApplication::applicationDirPath()+"/diphone/f-er.wav"; 
	else if(dipStr == "f-ey") return QApplication::applicationDirPath()+"/diphone/f-ey.wav"; 
	else if(dipStr == "f-f") return QApplication::applicationDirPath()+"/diphone/f-f.wav";  
	else if(dipStr == "f-g") return QApplication::applicationDirPath()+"/diphone/f-g.wav"; 
	else if(dipStr == "f-hh") return QApplication::applicationDirPath()+"/diphone/f-hh.wav"; 
	else if(dipStr == "f-ih") return QApplication::applicationDirPath()+"/diphone/f-ih.wav"; 
	else if(dipStr == "f-iy") return QApplication::applicationDirPath()+"/diphone/f-iy.wav"; 
	else if(dipStr == "f-jh") return QApplication::applicationDirPath()+"/diphone/f-jh.wav"; 
	else if(dipStr == "f-k") return QApplication::applicationDirPath()+"/diphone/f-k.wav"; 
	else if(dipStr == "f-l") return QApplication::applicationDirPath()+"/diphone/f-l.wav"; 
	else if(dipStr == "f-m") return QApplication::applicationDirPath()+"/diphone/f-m.wav"; 
	else if(dipStr == "f-n") return QApplication::applicationDirPath()+"/diphone/f-n.wav"; 
	else if(dipStr == "f-ow") return QApplication::applicationDirPath()+"/diphone/f-ow.wav"; 
	else if(dipStr == "f-oy") return QApplication::applicationDirPath()+"/diphone/f-oy.wav"; 
	else if(dipStr == "f-p") return QApplication::applicationDirPath()+"/diphone/f-p.wav"; 
	else if(dipStr == "f-pau") return QApplication::applicationDirPath()+"/diphone/f-pau.wav"; 
	else if(dipStr == "f-r") return QApplication::applicationDirPath()+"/diphone/f-r.wav"; 
	else if(dipStr == "f-s") return QApplication::applicationDirPath()+"/diphone/f-s.wav"; 
	else if(dipStr == "f-sh") return QApplication::applicationDirPath()+"/diphone/f-sh.wav"; 
	else if(dipStr == "f-t") return QApplication::applicationDirPath()+"/diphone/f-t.wav"; 
	else if(dipStr == "f-th") return QApplication::applicationDirPath()+"/diphone/f-th.wav"; 
	else if(dipStr == "f-uh") return QApplication::applicationDirPath()+"/diphone/f-uh.wav"; 
	else if(dipStr == "f-uw") return QApplication::applicationDirPath()+"/diphone/f-uw.wav"; 
	else if(dipStr == "f-v") return QApplication::applicationDirPath()+"/diphone/f-v.wav"; 
	else if(dipStr == "f-w") return QApplication::applicationDirPath()+"/diphone/f-w.wav"; 
	else if(dipStr == "f-y") return QApplication::applicationDirPath()+"/diphone/f-y.wav"; 
	else if(dipStr == "f-z") return QApplication::applicationDirPath()+"/diphone/f-z.wav"; 
	else if(dipStr == "f-zh") return QApplication::applicationDirPath()+"/diphone/f-zh.wav";    	
	
// g diphones
	else if(dipStr == "g-aa") return QApplication::applicationDirPath()+"/diphone/g-aa.wav";   
	else if(dipStr == "g-ae") return QApplication::applicationDirPath()+"/diphone/g-ae.wav";
	else if(dipStr == "g-ah") return QApplication::applicationDirPath()+"/diphone/g-ah.wav";
	else if(dipStr == "g-ao") return QApplication::applicationDirPath()+"/diphone/g-ao.wav"; 
	else if(dipStr == "g-aw") return QApplication::applicationDirPath()+"/diphone/g-aw.wav";
	else if(dipStr == "g-ax") return QApplication::applicationDirPath()+"/diphone/g-ax.wav";
	else if(dipStr == "g-ay") return QApplication::applicationDirPath()+"/diphone/g-ay.wav";
	else if(dipStr == "g-b") return QApplication::applicationDirPath()+"/diphone/g-b.wav";  
	else if(dipStr == "g-ch") return QApplication::applicationDirPath()+"/diphone/g-ch.wav";
	else if(dipStr == "g-d") return QApplication::applicationDirPath()+"/diphone/g-d.wav";
	else if(dipStr == "g-dh") return QApplication::applicationDirPath()+"/diphone/g-dh.wav";
	else if(dipStr == "g-eh") return QApplication::applicationDirPath()+"/diphone/g-eh.wav";
	else if(dipStr == "g-er") return QApplication::applicationDirPath()+"/diphone/g-er.wav";
	else if(dipStr == "g-ey") return QApplication::applicationDirPath()+"/diphone/g-ey.wav";
	else if(dipStr == "g-f") return QApplication::applicationDirPath()+"/diphone/g-f.wav"; 
	else if(dipStr == "g-g") return QApplication::applicationDirPath()+"/diphone/g-g.wav";
	else if(dipStr == "g-hh") return QApplication::applicationDirPath()+"/diphone/g-hh.wav";
	else if(dipStr == "g-ih") return QApplication::applicationDirPath()+"/diphone/g-ih.wav";
	else if(dipStr == "g-iy") return QApplication::applicationDirPath()+"/diphone/g-iy.wav";
	else if(dipStr == "g-jh") return QApplication::applicationDirPath()+"/diphone/g-jh.wav";
	else if(dipStr == "g-k") return QApplication::applicationDirPath()+"/diphone/g-k.wav";
	else if(dipStr == "g-l") return QApplication::applicationDirPath()+"/diphone/g-l.wav";
	else if(dipStr == "g-m") return QApplication::applicationDirPath()+"/diphone/g-m.wav";
	else if(dipStr == "g-n") return QApplication::applicationDirPath()+"/diphone/g-n.wav";
	else if(dipStr == "g-ow") return QApplication::applicationDirPath()+"/diphone/g-ow.wav";
	else if(dipStr == "g-oy") return QApplication::applicationDirPath()+"/diphone/g-oy.wav";
	else if(dipStr == "g-p") return QApplication::applicationDirPath()+"/diphone/g-p.wav";
	else if(dipStr == "g-pau") return QApplication::applicationDirPath()+"/diphone/g-pau.wav";
	else if(dipStr == "g-r") return QApplication::applicationDirPath()+"/diphone/g-r.wav";
	else if(dipStr == "g-s") return QApplication::applicationDirPath()+"/diphone/g-s.wav";
	else if(dipStr == "g-sh") return QApplication::applicationDirPath()+"/diphone/g-sh.wav";
	else if(dipStr == "g-t") return QApplication::applicationDirPath()+"/diphone/g-t.wav";
	else if(dipStr == "g-th") return QApplication::applicationDirPath()+"/diphone/g-th.wav";
	else if(dipStr == "g-uh") return QApplication::applicationDirPath()+"/diphone/g-uh.wav";
	else if(dipStr == "g-uw") return QApplication::applicationDirPath()+"/diphone/g-uw.wav";
	else if(dipStr == "g-v") return QApplication::applicationDirPath()+"/diphone/g-v.wav";
	else if(dipStr == "g-w") return QApplication::applicationDirPath()+"/diphone/g-w.wav";
	else if(dipStr == "g-y") return QApplication::applicationDirPath()+"/diphone/g-y.wav";
	else if(dipStr == "g-z") return QApplication::applicationDirPath()+"/diphone/g-z.wav";
	else if(dipStr == "g-zh") return QApplication::applicationDirPath()+"/diphone/g-zh.wav";   

// h diphones
	else if(dipStr == "hh-aa") return QApplication::applicationDirPath()+"/diphone/hh-aa.wav";  
	else if(dipStr == "hh-ae") return QApplication::applicationDirPath()+"/diphone/hh-ae.wav"; 
	else if(dipStr == "hh-ah") return QApplication::applicationDirPath()+"/diphone/hh-ah.wav"; 
	else if(dipStr == "hh-ao") return QApplication::applicationDirPath()+"/diphone/hh-ao.wav";  
	else if(dipStr == "hh-aw") return QApplication::applicationDirPath()+"/diphone/hh-aw.wav";  
	else if(dipStr == "hh-ax") return QApplication::applicationDirPath()+"/diphone/hh-ax.wav";  
	else if(dipStr == "hh-ay") return QApplication::applicationDirPath()+"/diphone/hh-ay.wav"; 
	else if(dipStr == "hh-eh") return QApplication::applicationDirPath()+"/diphone/hh-eh.wav"; 
	else if(dipStr == "hh-ih") return QApplication::applicationDirPath()+"/diphone/hh-ih.wav"; 
	else if(dipStr == "hh-iy") return QApplication::applicationDirPath()+"/diphone/hh-iy.wav"; 
	else if(dipStr == "hh-ow") return QApplication::applicationDirPath()+"/diphone/hh-ow.wav"; 
	else if(dipStr == "hh-oy") return QApplication::applicationDirPath()+"/diphone/hh-oy.wav"; 
	else if(dipStr == "hh-uh") return QApplication::applicationDirPath()+"/diphone/hh-uh.wav"; 
	else if(dipStr == "hh-uw") return QApplication::applicationDirPath()+"/diphone/hh-uw.wav"; 
 
 // ih diphones
	 else if(dipStr == "ih-aa") return QApplication::applicationDirPath()+"/diphone/ih-aa.wav";   
	 else if(dipStr == "ih-ae") return QApplication::applicationDirPath()+"/diphone/ih-ae.wav"; 
	 else if(dipStr == "ih-ah") return QApplication::applicationDirPath()+"/diphone/ih-ah.wav"; 
	 else if(dipStr == "ih-ao") return QApplication::applicationDirPath()+"/diphone/ih-ao.wav";  
	 else if(dipStr == "ih-aw") return QApplication::applicationDirPath()+"/diphone/ih-aw.wav";  
	 else if(dipStr == "ih-ax") return QApplication::applicationDirPath()+"/diphone/ih-ax.wav";  
	 else if(dipStr == "ih-ay") return QApplication::applicationDirPath()+"/diphone/ih-ay.wav"; 
	 else if(dipStr == "ih-b") return QApplication::applicationDirPath()+"/diphone/ih-b.wav";   
	 else if(dipStr == "ih-ch") return QApplication::applicationDirPath()+"/diphone/ih-ch.wav";  
	 else if(dipStr == "ih-d") return QApplication::applicationDirPath()+"/diphone/ih-d.wav"; 
	 else if(dipStr == "ih-dh") return QApplication::applicationDirPath()+"/diphone/ih-dh.wav"; 
	 else if(dipStr == "ih-eh") return QApplication::applicationDirPath()+"/diphone/ih-eh.wav"; 
	 else if(dipStr == "ih-er") return QApplication::applicationDirPath()+"/diphone/ih-er.wav"; 
	 else if(dipStr == "ih-ey") return QApplication::applicationDirPath()+"/diphone/ih-ey.wav"; 
	 else if(dipStr == "ih-f") return QApplication::applicationDirPath()+"/diphone/ih-f.wav";  
	 else if(dipStr == "ih-g") return QApplication::applicationDirPath()+"/diphone/ih-g.wav"; 
	 else if(dipStr == "ih-hh") return QApplication::applicationDirPath()+"/diphone/ih-hh.wav"; 
	 else if(dipStr == "ih-ih") return QApplication::applicationDirPath()+"/diphone/ih-ih.wav"; 
	 else if(dipStr == "ih-iy") return QApplication::applicationDirPath()+"/diphone/ih-iy.wav"; 
	 else if(dipStr == "ih-jh") return QApplication::applicationDirPath()+"/diphone/ih-jh.wav"; 
	 else if(dipStr == "ih-k") return QApplication::applicationDirPath()+"/diphone/ih-k.wav"; 
	 else if(dipStr == "ih-l") return QApplication::applicationDirPath()+"/diphone/ih-l.wav"; 
	 else if(dipStr == "ih-m") return QApplication::applicationDirPath()+"/diphone/ih-m.wav"; 
	 else if(dipStr == "ih-n") return QApplication::applicationDirPath()+"/diphone/ih-n.wav"; 
	 else if(dipStr == "ih-ng") return QApplication::applicationDirPath()+"/diphone/ih-hg.wav"; 
	 else if(dipStr == "ih-ow") return QApplication::applicationDirPath()+"/diphone/ih-ow.wav"; 
	 else if(dipStr == "ih-oy") return QApplication::applicationDirPath()+"/diphone/ih-oy.wav"; 
	 else if(dipStr == "ih-p") return QApplication::applicationDirPath()+"/diphone/ih-p.wav"; 
	 else if(dipStr == "ih-pau") return QApplication::applicationDirPath()+"/diphone/ih-pau.wav"; 
	 else if(dipStr == "ih-r") return QApplication::applicationDirPath()+"/diphone/ih-r.wav"; 
	 else if(dipStr == "ih-s") return QApplication::applicationDirPath()+"/diphone/ih-s.wav"; 
	 else if(dipStr == "ih-sh") return QApplication::applicationDirPath()+"/diphone/ih-sh.wav"; 
	 else if(dipStr == "ih-t") return QApplication::applicationDirPath()+"/diphone/ih-t.wav"; 
	 else if(dipStr == "ih-th") return QApplication::applicationDirPath()+"/diphone/ih-th.wav"; 
	 else if(dipStr == "ih-uh") return QApplication::applicationDirPath()+"/diphone/ih-uh.wav"; 
	 else if(dipStr == "ih-uw") return QApplication::applicationDirPath()+"/diphone/ih-uw.wav"; 
	 else if(dipStr == "ih-v") return QApplication::applicationDirPath()+"/diphone/ih-v.wav"; 
	 else if(dipStr == "ih-w") return QApplication::applicationDirPath()+"/diphone/ih-w.wav"; 
	 else if(dipStr == "ih-y") return QApplication::applicationDirPath()+"/diphone/ih-y.wav"; 
	 else if(dipStr == "ih-z") return QApplication::applicationDirPath()+"/diphone/ih-z.wav"; 
	 else if(dipStr == "ih-zh") return QApplication::applicationDirPath()+"/diphone/ih-z.wav";    
	 
// iy diphones
	else if(dipStr =="iy-aa") return QApplication::applicationDirPath()+"/diphone/iy-aa.wav";   
	else if(dipStr =="iy-ae") return QApplication::applicationDirPath()+"/diphone/iy-ae.wav";
	else if(dipStr =="iy-ah") return QApplication::applicationDirPath()+"/diphone/iy-ah.wav";
	else if(dipStr =="iy-ao") return QApplication::applicationDirPath()+"/diphone/iy-ao.wav"; 
	else if(dipStr =="iy-aw") return QApplication::applicationDirPath()+"/diphone/iy-aw.wav"; 
	else if(dipStr =="iy-ax") return QApplication::applicationDirPath()+"/diphone/iy-ax.wav"; 
	else if(dipStr =="iy-ay") return QApplication::applicationDirPath()+"/diphone/iy-ay.wav";
	else if(dipStr =="iy-b") return QApplication::applicationDirPath()+"/diphone/iy-b.wav";  
	else if(dipStr =="iy-ch") return QApplication::applicationDirPath()+"/diphone/iy-ch.wav"; 
	else if(dipStr =="iy-d") return QApplication::applicationDirPath()+"/diphone/iy-d.wav";
	else if(dipStr =="iy-dh") return QApplication::applicationDirPath()+"/diphone/iy-dh.wav";
	else if(dipStr =="iy-eh") return QApplication::applicationDirPath()+"/diphone/iy-eh.wav";
	else if(dipStr =="iy-er") return QApplication::applicationDirPath()+"/diphone/iy-er.wav";
	else if(dipStr =="iy-ey") return QApplication::applicationDirPath()+"/diphone/iy-ey.wav";
	else if(dipStr =="iy-f") return QApplication::applicationDirPath()+"/diphone/iy-f.wav";
	else if(dipStr =="iy-g") return QApplication::applicationDirPath()+"/diphone/iy-g.wav";
	else if(dipStr =="iy-hh") return QApplication::applicationDirPath()+"/diphone/iy-hh.wav";
	else if(dipStr =="iy-ih") return QApplication::applicationDirPath()+"/diphone/iy-ih.wav";
	else if(dipStr =="iy-iy") return QApplication::applicationDirPath()+"/diphone/iy-iy.wav";
	else if(dipStr =="iy-jh") return QApplication::applicationDirPath()+"/diphone/iy-jh.wav";
	else if(dipStr =="iy-k") return QApplication::applicationDirPath()+"/diphone/iy-k.wav";
	else if(dipStr =="iy-l") return QApplication::applicationDirPath()+"/diphone/iy-l.wav";
	else if(dipStr =="iy-m") return QApplication::applicationDirPath()+"/diphone/iy-m.wav";
	else if(dipStr =="iy-n") return QApplication::applicationDirPath()+"/diphone/iy-n.wav";
	else if(dipStr =="iy-ng") return QApplication::applicationDirPath()+"/diphone/iy-ng.wav";
	else if(dipStr =="iy-ow") return QApplication::applicationDirPath()+"/diphone/iy-ow.wav";
	else if(dipStr =="iy-oy") return QApplication::applicationDirPath()+"/diphone/iy-oy.wav";
	else if(dipStr =="iy-p") return QApplication::applicationDirPath()+"/diphone/iy-p.wav";
	else if(dipStr =="iy-pau") return QApplication::applicationDirPath()+"/diphone/iy-pau.wav";
	else if(dipStr =="iy-r") return QApplication::applicationDirPath()+"/diphone/iy-r.wav";
	else if(dipStr =="iy-s") return QApplication::applicationDirPath()+"/diphone/iy-s.wav";
	else if(dipStr =="iy-sh") return QApplication::applicationDirPath()+"/diphone/iy-sh.wav";
	else if(dipStr =="iy-t") return QApplication::applicationDirPath()+"/diphone/iy-t.wav";
	else if(dipStr =="iy-th") return QApplication::applicationDirPath()+"/diphone/iy-th.wav";
	else if(dipStr =="iy-uh") return QApplication::applicationDirPath()+"/diphone/iy-uh.wav";
	else if(dipStr =="iy-uw") return QApplication::applicationDirPath()+"/diphone/iy-uw.wav";
	else if(dipStr =="iy-v") return QApplication::applicationDirPath()+"/diphone/iy-v.wav";
	else if(dipStr =="iy-w") return QApplication::applicationDirPath()+"/diphone/iy-w.wav";
	else if(dipStr =="iy-y") return QApplication::applicationDirPath()+"/diphone/iy-y.wav";
	else if(dipStr =="iy-z") return QApplication::applicationDirPath()+"/diphone/iy-z.wav";
	else if(dipStr =="iy-zh") return QApplication::applicationDirPath()+"/diphone/iy-zh.wav";  
 
 // jh diphones
	 else if(dipStr == "jh-aa") return QApplication::applicationDirPath()+"/diphone/jh-aa.wav";  
	 else if(dipStr == "jh-ae") return QApplication::applicationDirPath()+"/diphone/jh-ae.wav";
	 else if(dipStr == "jh-ah") return QApplication::applicationDirPath()+"/diphone/jh-ah.wav";
	 else if(dipStr == "jh-ao") return QApplication::applicationDirPath()+"/diphone/jh-ao.wav"; 
	 else if(dipStr == "jh-aw") return QApplication::applicationDirPath()+"/diphone/jh-aw.wav"; 
	 else if(dipStr == "jh-ax") return QApplication::applicationDirPath()+"/diphone/jh-ax.wav"; 
	 else if(dipStr == "jh-ay") return QApplication::applicationDirPath()+"/diphone/jh-ay.wav";
	 else if(dipStr == "jh-b") return QApplication::applicationDirPath()+"/diphone/jh-b.wav";  
	 else if(dipStr == "jh-ch") return QApplication::applicationDirPath()+"/diphone/jh-ch.wav"; 
	 else if(dipStr == "jh-d") return QApplication::applicationDirPath()+"/diphone/jh-d.wav";
	 else if(dipStr == "jh-dh") return QApplication::applicationDirPath()+"/diphone/jh-dh.wav";
	 else if(dipStr == "jh-eh") return QApplication::applicationDirPath()+"/diphone/jh-eh.wav";
	 else if(dipStr == "jh-er") return QApplication::applicationDirPath()+"/diphone/jh-er.wav";
	 else if(dipStr == "jh-ey") return QApplication::applicationDirPath()+"/diphone/jh-ey.wav";
	 else if(dipStr == "jh-f") return QApplication::applicationDirPath()+"/diphone/jh-f.wav"; 
	 else if(dipStr == "jh-g") return QApplication::applicationDirPath()+"/diphone/jh-g.wav";
	 else if(dipStr == "jh-hh") return QApplication::applicationDirPath()+"/diphone/jh-hh.wav";
	 else if(dipStr == "jh-ih") return QApplication::applicationDirPath()+"/diphone/jh-ih.wav";
	 else if(dipStr == "jh-iy") return QApplication::applicationDirPath()+"/diphone/jh-iy.wav";
	 else if(dipStr == "jh-jh") return QApplication::applicationDirPath()+"/diphone/jh-jh.wav";
	 else if(dipStr == "jh-k") return QApplication::applicationDirPath()+"/diphone/jh-k.wav";
	 else if(dipStr == "jh-l") return QApplication::applicationDirPath()+"/diphone/jh-l.wav";
	 else if(dipStr == "jh-m") return QApplication::applicationDirPath()+"/diphone/jh-m.wav";
	 else if(dipStr == "jh-n") return QApplication::applicationDirPath()+"/diphone/jh-n.wav";
	 else if(dipStr == "jh-ow") return QApplication::applicationDirPath()+"/diphone/jh-ow.wav";
	 else if(dipStr == "jh-oy") return QApplication::applicationDirPath()+"/diphone/jh-oy.wav";
	 else if(dipStr == "jh-p") return QApplication::applicationDirPath()+"/diphone/jh-p.wav";
	 else if(dipStr == "jh-pau") return QApplication::applicationDirPath()+"/diphone/jh-pau.wav";
	 else if(dipStr == "jh-r") return QApplication::applicationDirPath()+"/diphone/jh-r.wav";
	 else if(dipStr == "jh-s") return QApplication::applicationDirPath()+"/diphone/jh-s.wav";
	 else if(dipStr == "jh-sh") return QApplication::applicationDirPath()+"/diphone/jh-sh.wav";
	 else if(dipStr == "jh-t") return QApplication::applicationDirPath()+"/diphone/jh-t.wav";
	 else if(dipStr == "jh-th") return QApplication::applicationDirPath()+"/diphone/jh-th.wav";
	 else if(dipStr == "jh-uh") return QApplication::applicationDirPath()+"/diphone/jh-uh.wav";
	 else if(dipStr == "jh-uw") return QApplication::applicationDirPath()+"/diphone/jh-uw.wav";
	 else if(dipStr == "jh-v") return QApplication::applicationDirPath()+"/diphone/jh-v.wav";
	 else if(dipStr == "jh-w") return QApplication::applicationDirPath()+"/diphone/jh-w.wav";
	 else if(dipStr == "jh-y") return QApplication::applicationDirPath()+"/diphone/jh-y.wav";
	 else if(dipStr == "jh-z") return QApplication::applicationDirPath()+"/diphone/jh-z.wav";
	 else if(dipStr == "jh-zh") return QApplication::applicationDirPath()+"/diphone/jh-zh.wav";  
 
// k diphones
	else if(dipStr == "k-aa") return QApplication::applicationDirPath()+"/diphone/k-aa.wav"; 
	else if(dipStr == "k-ae") return QApplication::applicationDirPath()+"/diphone/k-ae.wav"; 
	else if(dipStr == "k-ah") return QApplication::applicationDirPath()+"/diphone/k-ah.wav"; 
	else if(dipStr == "k-ao") return QApplication::applicationDirPath()+"/diphone/k-ao.wav";  
	else if(dipStr == "k-aw") return QApplication::applicationDirPath()+"/diphone/k-aw.wav";  
	else if(dipStr == "k-ax") return QApplication::applicationDirPath()+"/diphone/k-ax.wav";  
	else if(dipStr == "k-ay") return QApplication::applicationDirPath()+"/diphone/k-ay.wav"; 
	else if(dipStr == "k-b") return QApplication::applicationDirPath()+"/diphone/k-b.wav";   
	else if(dipStr == "k-ch") return QApplication::applicationDirPath()+"/diphone/k-ch.wav";  
	else if(dipStr == "k-d") return QApplication::applicationDirPath()+"/diphone/k-d.wav"; 
	else if(dipStr == "k-dh") return QApplication::applicationDirPath()+"/diphone/k-dh.wav"; 
	else if(dipStr == "k-eh") return QApplication::applicationDirPath()+"/diphone/k-eh.wav"; 
	else if(dipStr == "k-er") return QApplication::applicationDirPath()+"/diphone/k-er.wav"; 
	else if(dipStr == "k-ey") return QApplication::applicationDirPath()+"/diphone/k-ey.wav"; 
	else if(dipStr == "k-f") return QApplication::applicationDirPath()+"/diphone/k-f.wav";  
	else if(dipStr == "k-g") return QApplication::applicationDirPath()+"/diphone/k-g.wav"; 
	else if(dipStr == "k-hh") return QApplication::applicationDirPath()+"/diphone/k-hh.wav"; 
	else if(dipStr == "k-ih") return QApplication::applicationDirPath()+"/diphone/k-ih.wav"; 
	else if(dipStr == "k-iy") return QApplication::applicationDirPath()+"/diphone/k-iy.wav"; 
	else if(dipStr == "k-jh") return QApplication::applicationDirPath()+"/diphone/k-jh.wav"; 
	else if(dipStr == "k-k") return QApplication::applicationDirPath()+"/diphone/k-k.wav"; 
	else if(dipStr == "k-l") return QApplication::applicationDirPath()+"/diphone/k-l.wav"; 
	else if(dipStr == "k-m") return QApplication::applicationDirPath()+"/diphone/k-m.wav"; 
	else if(dipStr == "k-n") return QApplication::applicationDirPath()+"/diphone/k-n.wav"; 
	else if(dipStr == "k-ow") return QApplication::applicationDirPath()+"/diphone/k-ow.wav"; 
	else if(dipStr == "k-oy") return QApplication::applicationDirPath()+"/diphone/k-oy.wav"; 
	else if(dipStr == "k-p") return QApplication::applicationDirPath()+"/diphone/k-p.wav"; 
	else if(dipStr == "k-pau") return QApplication::applicationDirPath()+"/diphone/k-pau.wav"; 
	else if(dipStr == "k-r") return QApplication::applicationDirPath()+"/diphone/k-r.wav"; 
	else if(dipStr == "k-s") return QApplication::applicationDirPath()+"/diphone/k-s.wav"; 
	else if(dipStr == "k-sh") return QApplication::applicationDirPath()+"/diphone/k-sh.wav"; 
	else if(dipStr == "k-t") return QApplication::applicationDirPath()+"/diphone/k-t.wav"; 
	else if(dipStr == "k-th") return QApplication::applicationDirPath()+"/diphone/k-th.wav"; 
	else if(dipStr == "k-uh") return QApplication::applicationDirPath()+"/diphone/k-uh.wav"; 
	else if(dipStr == "k-uw") return QApplication::applicationDirPath()+"/diphone/k-uw.wav"; 
	else if(dipStr == "k-v") return QApplication::applicationDirPath()+"/diphone/k-v.wav"; 
	else if(dipStr == "k-w") return QApplication::applicationDirPath()+"/diphone/k-w.wav"; 
	else if(dipStr == "k-y") return QApplication::applicationDirPath()+"/diphone/k-y.wav"; 
	else if(dipStr == "k-z") return QApplication::applicationDirPath()+"/diphone/k-z.wav"; 
	else if(dipStr == "k-zh") return QApplication::applicationDirPath()+"/diphone/k-zh.wav";   
 
 //l diphones
	 else if(dipStr == "l-aa") return QApplication::applicationDirPath()+"/diphone/l-aa.wav";   
	 else if(dipStr == "l-ae") return QApplication::applicationDirPath()+"/diphone/l-ae.wav"; 
	 else if(dipStr == "l-ah") return QApplication::applicationDirPath()+"/diphone/l-ah.wav"; 
	 else if(dipStr == "l-ao") return QApplication::applicationDirPath()+"/diphone/l-ao.wav";  
	 else if(dipStr == "l-aw") return QApplication::applicationDirPath()+"/diphone/l-aw.wav"; 
	 else if(dipStr == "l-ax") return QApplication::applicationDirPath()+"/diphone/l-ax.wav";  
	 else if(dipStr == "l-ay") return QApplication::applicationDirPath()+"/diphone/l-ay.wav"; 
	 else if(dipStr == "l-b") return QApplication::applicationDirPath()+"/diphone/l-b.wav";  
	 else if(dipStr == "l-ch") return QApplication::applicationDirPath()+"/diphone/l-ch.wav";  
	 else if(dipStr == "l-d") return QApplication::applicationDirPath()+"/diphone/l-d.wav"; 
	 else if(dipStr == "l-dh") return QApplication::applicationDirPath()+"/diphone/l-dh.wav"; 
	 else if(dipStr == "l-eh") return QApplication::applicationDirPath()+"/diphone/l-eh.wav"; 
	 else if(dipStr == "l-er") return QApplication::applicationDirPath()+"/diphone/l-er.wav"; 
	 else if(dipStr == "l-ey") return QApplication::applicationDirPath()+"/diphone/l-ey.wav"; 
	 else if(dipStr == "l-f") return QApplication::applicationDirPath()+"/diphone/l-f.wav";  
	 else if(dipStr == "l-g") return QApplication::applicationDirPath()+"/diphone/l-g.wav"; 
	 else if(dipStr == "l-hh") return QApplication::applicationDirPath()+"/diphone/l-hh.wav"; 
	 else if(dipStr == "l-ih") return QApplication::applicationDirPath()+"/diphone/l-ih.wav"; 
	 else if(dipStr == "l-iy") return QApplication::applicationDirPath()+"/diphone/l-iy.wav"; 
	 else if(dipStr == "l-jh") return QApplication::applicationDirPath()+"/diphone/l-jh.wav"; 
	 else if(dipStr == "l-k") return QApplication::applicationDirPath()+"/diphone/l-k.wav"; 
	 else if(dipStr == "l-l") return QApplication::applicationDirPath()+"/diphone/l-l.wav"; 
	 else if(dipStr == "l-m") return QApplication::applicationDirPath()+"/diphone/l-m.wav"; 
	 else if(dipStr == "l-n") return QApplication::applicationDirPath()+"/diphone/l-n.wav"; 
	 else if(dipStr == "l-ow") return QApplication::applicationDirPath()+"/diphone/l-ow.wav"; 
	 else if(dipStr == "l-oy") return QApplication::applicationDirPath()+"/diphone/l-oy.wav"; 
	 else if(dipStr == "l-p") return QApplication::applicationDirPath()+"/diphone/l-p.wav"; 
	 else if(dipStr == "l-pau") return QApplication::applicationDirPath()+"/diphone/l-pau.wav"; 
	 else if(dipStr == "l-r") return QApplication::applicationDirPath()+"/diphone/l-r.wav"; 
	 else if(dipStr == "l-s") return QApplication::applicationDirPath()+"/diphone/l-s.wav"; 
	 else if(dipStr == "l-sh") return QApplication::applicationDirPath()+"/diphone/l-sh.wav"; 
	 else if(dipStr == "l-t") return QApplication::applicationDirPath()+"/diphone/l-t.wav"; 
	 else if(dipStr == "l-th") return QApplication::applicationDirPath()+"/diphone/l-th.wav"; 
	 else if(dipStr == "l-uh") return QApplication::applicationDirPath()+"/diphone/l-uh.wav"; 
	 else if(dipStr == "l-uw") return QApplication::applicationDirPath()+"/diphone/l-uw.wav"; 
	 else if(dipStr == "l-v") return QApplication::applicationDirPath()+"/diphone/l-v.wav"; 
	 else if(dipStr == "l-w") return QApplication::applicationDirPath()+"/diphone/l-w.wav"; 
	 else if(dipStr == "l-y") return QApplication::applicationDirPath()+"/diphone/l-y.wav"; 
	 else if(dipStr == "l-z") return QApplication::applicationDirPath()+"/diphone/l-z.wav"; 
	 else if(dipStr == "l-zh") return QApplication::applicationDirPath()+"/diphone/l-zh.wav";    
	 
 //m diphones
	 else if(dipStr == "m-aa") return QApplication::applicationDirPath()+"/diphone/m-aa.wav";   
	 else if(dipStr == "m-ae") return QApplication::applicationDirPath()+"/diphone/m-ae.wav"; 
	 else if(dipStr == "m-ah") return QApplication::applicationDirPath()+"/diphone/m-ah.wav"; 
	 else if(dipStr == "m-ao") return QApplication::applicationDirPath()+"/diphone/m-ao.wav";  
	 else if(dipStr == "m-aw") return QApplication::applicationDirPath()+"/diphone/m-aw.wav";  
	 else if(dipStr == "m-ax") return QApplication::applicationDirPath()+"/diphone/m-ax.wav";  
	 else if(dipStr == "m-ay") return QApplication::applicationDirPath()+"/diphone/m-ay.wav"; 
	 else if(dipStr == "m-b") return QApplication::applicationDirPath()+"/diphone/m-b.wav";   
	 else if(dipStr == "m-ch") return QApplication::applicationDirPath()+"/diphone/m-ch.wav";  
	 else if(dipStr == "m-d") return QApplication::applicationDirPath()+"/diphone/m-d.wav"; 
	 else if(dipStr == "m-dh") return QApplication::applicationDirPath()+"/diphone/m-dh.wav"; 
	 else if(dipStr == "m-eh") return QApplication::applicationDirPath()+"/diphone/m-eh.wav"; 
	 else if(dipStr == "m-er") return QApplication::applicationDirPath()+"/diphone/m-er.wav"; 
	 else if(dipStr == "m-ey") return QApplication::applicationDirPath()+"/diphone/m-ey.wav"; 
	 else if(dipStr == "m-f") return QApplication::applicationDirPath()+"/diphone/m-f.wav";  
	 else if(dipStr == "m-g") return QApplication::applicationDirPath()+"/diphone/m-g.wav"; 
	 else if(dipStr == "m-hh") return QApplication::applicationDirPath()+"/diphone/m-hh.wav"; 
	 else if(dipStr == "m-ih") return QApplication::applicationDirPath()+"/diphone/m-ih.wav"; 
	 else if(dipStr == "m-iy") return QApplication::applicationDirPath()+"/diphone/m-iy.wav"; 
	 else if(dipStr == "m-jh") return QApplication::applicationDirPath()+"/diphone/m-jh.wav"; 
	 else if(dipStr == "m-k") return QApplication::applicationDirPath()+"/diphone/m-k.wav"; 
	 else if(dipStr == "m-l") return QApplication::applicationDirPath()+"/diphone/m-l.wav"; 
	 else if(dipStr == "m-m") return QApplication::applicationDirPath()+"/diphone/m-m.wav"; 
	 else if(dipStr == "m-n") return QApplication::applicationDirPath()+"/diphone/m-n.wav"; 
	 else if(dipStr == "m-ow") return QApplication::applicationDirPath()+"/diphone/m-ow.wav"; 
	 else if(dipStr == "m-oy") return QApplication::applicationDirPath()+"/diphone/m-oy.wav"; 
	 else if(dipStr == "m-p") return QApplication::applicationDirPath()+"/diphone/m-p.wav"; 
	 else if(dipStr == "m-pau") return QApplication::applicationDirPath()+"/diphone/m-pau.wav"; 
	 else if(dipStr == "m-r") return QApplication::applicationDirPath()+"/diphone/m-r.wav"; 
	 else if(dipStr == "m-s") return QApplication::applicationDirPath()+"/diphone/m-s.wav"; 
	 else if(dipStr == "m-sh") return QApplication::applicationDirPath()+"/diphone/m-sh.wav"; 
	 else if(dipStr == "m-t") return QApplication::applicationDirPath()+"/diphone/m-t.wav"; 
	 else if(dipStr == "m-th") return QApplication::applicationDirPath()+"/diphone/m-th.wav"; 
	 else if(dipStr == "m-uh") return QApplication::applicationDirPath()+"/diphone/m-uh.wav"; 
	 else if(dipStr == "m-uw") return QApplication::applicationDirPath()+"/diphone/m-uw.wav"; 
	 else if(dipStr == "m-v") return QApplication::applicationDirPath()+"/diphone/m-v.wav"; 
	 else if(dipStr == "m-w") return QApplication::applicationDirPath()+"/diphone/m-w.wav"; 
	 else if(dipStr == "m-y") return QApplication::applicationDirPath()+"/diphone/m-y.wav"; 
	 else if(dipStr == "m-z") return QApplication::applicationDirPath()+"/diphone/m-z.wav"; 
	 else if(dipStr == "m-zh") return QApplication::applicationDirPath()+"/diphone/m-zh.wav";    
 
//n diphones
	else if(dipStr =="n-aa") return QApplication::applicationDirPath()+"/diphone/n-aa.wav";  
	else if(dipStr =="n-ae") return QApplication::applicationDirPath()+"/diphone/n-ae.wav"; 
	else if(dipStr =="n-ah") return QApplication::applicationDirPath()+"/diphone/n-ah.wav"; 
	else if(dipStr =="n-ao") return QApplication::applicationDirPath()+"/diphone/n-ao.wav";  
	else if(dipStr =="n-aw") return QApplication::applicationDirPath()+"/diphone/n-aw.wav";  
	else if(dipStr =="n-ax") return QApplication::applicationDirPath()+"/diphone/n-ax.wav";  
	else if(dipStr =="n-ay") return QApplication::applicationDirPath()+"/diphone/n-ay.wav"; 
	else if(dipStr =="n-b") return QApplication::applicationDirPath()+"/diphone/n-b.wav";   
	else if(dipStr =="n-ch") return QApplication::applicationDirPath()+"/diphone/n-ch.wav";  
	else if(dipStr =="n-d") return QApplication::applicationDirPath()+"/diphone/n-d.wav"; 
	else if(dipStr =="n-dh") return QApplication::applicationDirPath()+"/diphone/n-dh.wav"; 
	else if(dipStr =="n-eh") return QApplication::applicationDirPath()+"/diphone/n-eh.wav"; 
	else if(dipStr =="n-er") return QApplication::applicationDirPath()+"/diphone/n-er.wav"; 
	else if(dipStr =="n-ey") return QApplication::applicationDirPath()+"/diphone/n-ey.wav"; 
	else if(dipStr =="n-f") return QApplication::applicationDirPath()+"/diphone/n-f.wav";  
	else if(dipStr =="n-g") return QApplication::applicationDirPath()+"/diphone/n-g.wav"; 
	else if(dipStr =="n-hh") return QApplication::applicationDirPath()+"/diphone/n-hh.wav"; 
	else if(dipStr =="n-ih") return QApplication::applicationDirPath()+"/diphone/n-ih.wav"; 
	else if(dipStr =="n-iy") return QApplication::applicationDirPath()+"/diphone/n-iy.wav"; 
	else if(dipStr =="n-jh") return QApplication::applicationDirPath()+"/diphone/n-jh.wav"; 
	else if(dipStr =="n-k") return QApplication::applicationDirPath()+"/diphone/n-k.wav"; 
	else if(dipStr =="n-l") return QApplication::applicationDirPath()+"/diphone/n-l.wav"; 
	else if(dipStr =="n-m") return QApplication::applicationDirPath()+"/diphone/n-m.wav"; 
	else if(dipStr =="n-n") return QApplication::applicationDirPath()+"/diphone/n-n.wav"; 
	else if(dipStr =="n-ow") return QApplication::applicationDirPath()+"/diphone/n-ow.wav"; 
	else if(dipStr =="n-oy") return QApplication::applicationDirPath()+"/diphone/n-oy.wav"; 
	else if(dipStr =="n-p") return QApplication::applicationDirPath()+"/diphone/n-p.wav"; 
	else if(dipStr =="n-pau") return QApplication::applicationDirPath()+"/diphone/n-pau.wav"; 
	else if(dipStr =="n-r") return QApplication::applicationDirPath()+"/diphone/n-r.wav"; 
	else if(dipStr =="n-s") return QApplication::applicationDirPath()+"/diphone/n-s.wav"; 
	else if(dipStr =="n-sh") return QApplication::applicationDirPath()+"/diphone/n-sh.wav"; 
	else if(dipStr =="n-t") return QApplication::applicationDirPath()+"/diphone/n-t.wav"; 
	else if(dipStr =="n-th") return QApplication::applicationDirPath()+"/diphone/n-th.wav"; 
	else if(dipStr =="n-uh") return QApplication::applicationDirPath()+"/diphone/n-uh.wav"; 
	else if(dipStr =="n-uw") return QApplication::applicationDirPath()+"/diphone/n-uw.wav"; 
	else if(dipStr =="n-v") return QApplication::applicationDirPath()+"/diphone/n-v.wav"; 
	else if(dipStr =="n-w") return QApplication::applicationDirPath()+"/diphone/n-w.wav"; 
	else if(dipStr =="n-y") return QApplication::applicationDirPath()+"/diphone/n-y.wav"; 
	else if(dipStr =="n-z") return QApplication::applicationDirPath()+"/diphone/n-z.wav"; 
	else if(dipStr =="n-zh") return QApplication::applicationDirPath()+"/diphone/n-zh.wav";    
 
 //ng diphones
	 else if(dipStr == "ng-aa") return QApplication::applicationDirPath()+"/diphone/ng-aa.wav";   
	 else if(dipStr == "ng-ae") return QApplication::applicationDirPath()+"/diphone/ng-ae.wav";
	 else if(dipStr == "ng-ah") return QApplication::applicationDirPath()+"/diphone/ng-ah.wav";
	 else if(dipStr == "ng-ao") return QApplication::applicationDirPath()+"/diphone/ng-ao.wav"; 
	 else if(dipStr == "ng-aw") return QApplication::applicationDirPath()+"/diphone/ng-aw.wav"; 
	 else if(dipStr == "ng-ax") return QApplication::applicationDirPath()+"/diphone/ng-ax.wav"; 
	 else if(dipStr == "ng-ay") return QApplication::applicationDirPath()+"/diphone/ng-ay.wav";
	 else if(dipStr == "ng-b") return QApplication::applicationDirPath()+"/diphone/ng-b.wav";  
	 else if(dipStr == "ng-ch") return QApplication::applicationDirPath()+"/diphone/ng-ch.wav"; 
	 else if(dipStr == "ng-d") return QApplication::applicationDirPath()+"/diphone/ng-d.wav";
	 else if(dipStr == "ng-dh") return QApplication::applicationDirPath()+"/diphone/ng-dh.wav";
	 else if(dipStr == "ng-eh") return QApplication::applicationDirPath()+"/diphone/ng-eh.wav";
	 else if(dipStr == "ng-er") return QApplication::applicationDirPath()+"/diphone/ng-er.wav";
	 else if(dipStr == "ng-ey") return QApplication::applicationDirPath()+"/diphone/ng-ey.wav";
	 else if(dipStr == "ng-f") return QApplication::applicationDirPath()+"/diphone/ng-f.wav";
	 else if(dipStr == "ng-g") return QApplication::applicationDirPath()+"/diphone/ng-g.wav";
	 else if(dipStr == "ng-hh") return QApplication::applicationDirPath()+"/diphone/ng-hh.wav";
	 else if(dipStr == "ng-ih") return QApplication::applicationDirPath()+"/diphone/ng-ih.wav";
	 else if(dipStr == "ng-iy") return QApplication::applicationDirPath()+"/diphone/ng-iy.wav";
	 else if(dipStr == "ng-jh") return QApplication::applicationDirPath()+"/diphone/ng-jh.wav";
	 else if(dipStr == "ng-k") return QApplication::applicationDirPath()+"/diphone/ng-k.wav";
	 else if(dipStr == "ng-l") return QApplication::applicationDirPath()+"/diphone/ng-l.wav";
	 else if(dipStr == "ng-m") return QApplication::applicationDirPath()+"/diphone/ng-m.wav";
	 else if(dipStr == "ng-n") return QApplication::applicationDirPath()+"/diphone/ng-n.wav";
	 else if(dipStr == "ng-ow") return QApplication::applicationDirPath()+"/diphone/ng-ow.wav";
	 else if(dipStr == "ng-oy") return QApplication::applicationDirPath()+"/diphone/ng-oy.wav";
	 else if(dipStr == "ng-p") return QApplication::applicationDirPath()+"/diphone/ng-p.wav";
	 else if(dipStr == "ng-pau") return QApplication::applicationDirPath()+"/diphone/ng-pau.wav";
	 else if(dipStr == "ng-r") return QApplication::applicationDirPath()+"/diphone/ng-r.wav";
	 else if(dipStr == "ng-s") return QApplication::applicationDirPath()+"/diphone/ng-s.wav";
	 else if(dipStr == "ng-sh") return QApplication::applicationDirPath()+"/diphone/ng-sh.wav";
	 else if(dipStr == "ng-t") return QApplication::applicationDirPath()+"/diphone/ng-t.wav";
	 else if(dipStr == "ng-th") return QApplication::applicationDirPath()+"/diphone/ng-th.wav";
	 else if(dipStr == "ng-uh") return QApplication::applicationDirPath()+"/diphone/ng-uh.wav";
	 else if(dipStr == "ng-uw") return QApplication::applicationDirPath()+"/diphone/ng-uw.wav";
	 else if(dipStr == "ng-v") return QApplication::applicationDirPath()+"/diphone/ng-v.wav";
	 else if(dipStr == "ng-w") return QApplication::applicationDirPath()+"/diphone/ng-w.wav";
	 else if(dipStr == "ng-y") return QApplication::applicationDirPath()+"/diphone/ng-y.wav";
	 else if(dipStr == "ng-z") return QApplication::applicationDirPath()+"/diphone/ng-z.wav";
	 else if(dipStr == "ng-zh") return QApplication::applicationDirPath()+"/diphone/ng-zh.wav";   
	 
 //ow diphones
	 else if(dipStr == "ow-aa") return QApplication::applicationDirPath()+"/diphone/ow-aa.wav"; 
	 else if(dipStr == "ow-ae") return QApplication::applicationDirPath()+"/diphone/ow-ae.wav"; 
	 else if(dipStr == "ow-ah") return QApplication::applicationDirPath()+"/diphone/ow-ah.wav"; 
	 else if(dipStr == "ow-ao") return QApplication::applicationDirPath()+"/diphone/ow-ao.wav";  
	 else if(dipStr == "ow-aw") return QApplication::applicationDirPath()+"/diphone/ow-aw.wav";  
	 else if(dipStr == "ow-ax") return QApplication::applicationDirPath()+"/diphone/ow-ax.wav";  
	 else if(dipStr == "ow-ay") return QApplication::applicationDirPath()+"/diphone/ow-ay.wav"; 
	 else if(dipStr == "ow-b") return QApplication::applicationDirPath()+"/diphone/ow-b.wav";   
	 else if(dipStr == "ow-ch") return QApplication::applicationDirPath()+"/diphone/ow-ch.wav";  
	 else if(dipStr == "ow-d") return QApplication::applicationDirPath()+"/diphone/ow-d.wav"; 
	 else if(dipStr == "ow-dh") return QApplication::applicationDirPath()+"/diphone/ow-dh.wav"; 
	 else if(dipStr == "ow-eh") return QApplication::applicationDirPath()+"/diphone/ow-eh.wav"; 
	 else if(dipStr == "ow-er") return QApplication::applicationDirPath()+"/diphone/ow-er.wav"; 
	 else if(dipStr == "ow-ey") return QApplication::applicationDirPath()+"/diphone/ow-ey.wav"; 
	 else if(dipStr == "ow-f") return QApplication::applicationDirPath()+"/diphone/ow-f.wav"; 
	 else if(dipStr == "ow-g") return QApplication::applicationDirPath()+"/diphone/ow-g.wav"; 
	 else if(dipStr == "ow-hh") return QApplication::applicationDirPath()+"/diphone/ow-hh.wav"; 
	 else if(dipStr == "ow-ih") return QApplication::applicationDirPath()+"/diphone/ow-ih.wav"; 
	 else if(dipStr == "ow-iy") return QApplication::applicationDirPath()+"/diphone/ow-iy.wav"; 
	 else if(dipStr == "ow-jh") return QApplication::applicationDirPath()+"/diphone/ow-jh.wav"; 
	 else if(dipStr == "ow-k") return QApplication::applicationDirPath()+"/diphone/ow-k.wav"; 
	 else if(dipStr == "ow-l") return QApplication::applicationDirPath()+"/diphone/ow-l.wav"; 
	 else if(dipStr == "ow-m") return QApplication::applicationDirPath()+"/diphone/ow-m.wav"; 
	 else if(dipStr == "ow-n") return QApplication::applicationDirPath()+"/diphone/ow-n.wav"; 
	 else if(dipStr == "ow-ng") return QApplication::applicationDirPath()+"/diphone/ow-ng.wav"; 
	 else if(dipStr == "ow-ow") return QApplication::applicationDirPath()+"/diphone/ow-ow.wav"; 
	 else if(dipStr == "ow-oy") return QApplication::applicationDirPath()+"/diphone/ow-oy.wav"; 
	 else if(dipStr == "ow-p") return QApplication::applicationDirPath()+"/diphone/ow-p.wav"; 
	 else if(dipStr == "ow-pau") return QApplication::applicationDirPath()+"/diphone/ow-pau.wav"; 
	 else if(dipStr == "ow-r") return QApplication::applicationDirPath()+"/diphone/ow-r.wav"; 
	 else if(dipStr == "ow-s") return QApplication::applicationDirPath()+"/diphone/ow-s.wav"; 
	 else if(dipStr == "ow-sh") return QApplication::applicationDirPath()+"/diphone/ow-sh.wav"; 
	 else if(dipStr == "ow-t") return QApplication::applicationDirPath()+"/diphone/ow-t.wav"; 
	 else if(dipStr == "ow-th") return QApplication::applicationDirPath()+"/diphone/ow-th.wav"; 
	 else if(dipStr == "ow-uh") return QApplication::applicationDirPath()+"/diphone/ow-uh.wav"; 
	 else if(dipStr == "ow-uw") return QApplication::applicationDirPath()+"/diphone/ow-uw.wav"; 
	 else if(dipStr == "ow-v") return QApplication::applicationDirPath()+"/diphone/ow-v.wav"; 
	 else if(dipStr == "ow-w") return QApplication::applicationDirPath()+"/diphone/ow-w.wav"; 
	 else if(dipStr == "ow-y") return QApplication::applicationDirPath()+"/diphone/ow-y.wav"; 
	 else if(dipStr == "ow-z") return QApplication::applicationDirPath()+"/diphone/ow-z.wav"; 
	 else if(dipStr == "ow-zh") return QApplication::applicationDirPath()+"/diphone/ow-zh.wav";    
 
 //oy diphones
	 else if(dipStr == "oy-aa") return QApplication::applicationDirPath()+"/diphone/oy-aa.wav";  
	 else if(dipStr == "oy-ae") return QApplication::applicationDirPath()+"/diphone/oy-ae.wav";
	 else if(dipStr == "oy-ah") return QApplication::applicationDirPath()+"/diphone/oy-ah.wav";
	 else if(dipStr == "oy-ao") return QApplication::applicationDirPath()+"/diphone/oy-ao.wav"; 
	 else if(dipStr == "oy-aw") return QApplication::applicationDirPath()+"/diphone/oy-aw.wav"; 
	 else if(dipStr == "oy-ax") return QApplication::applicationDirPath()+"/diphone/oy-ax.wav"; 
	 else if(dipStr == "oy-ay") return QApplication::applicationDirPath()+"/diphone/oy-ay.wav";
	 else if(dipStr == "oy-b") return QApplication::applicationDirPath()+"/diphone/oy-b.wav";  
	 else if(dipStr == "oy-ch") return QApplication::applicationDirPath()+"/diphone/oy-ch.wav"; 
	 else if(dipStr == "oy-d") return QApplication::applicationDirPath()+"/diphone/oy-d.wav";
	 else if(dipStr == "oy-dh") return QApplication::applicationDirPath()+"/diphone/oy-dh.wav";
	 else if(dipStr == "oy-eh") return QApplication::applicationDirPath()+"/diphone/oy-eh.wav";
	 else if(dipStr == "oy-er") return QApplication::applicationDirPath()+"/diphone/oy-er.wav";
	 else if(dipStr == "oy-ey") return QApplication::applicationDirPath()+"/diphone/oy-ey.wav";
	 else if(dipStr == "oy-f") return QApplication::applicationDirPath()+"/diphone/oy-f.wav"; 
	 else if(dipStr == "oy-g") return QApplication::applicationDirPath()+"/diphone/oy-g.wav";
	 else if(dipStr == "oy-hh") return QApplication::applicationDirPath()+"/diphone/oy-hh.wav";
	 else if(dipStr == "oy-ih") return QApplication::applicationDirPath()+"/diphone/oy-ih.wav";
	 else if(dipStr == "oy-iy") return QApplication::applicationDirPath()+"/diphone/oy-iy.wav";
	 else if(dipStr == "oy-jh") return QApplication::applicationDirPath()+"/diphone/oy-jh.wav";
	 else if(dipStr == "oy-k") return QApplication::applicationDirPath()+"/diphone/oy-k.wav";
	 else if(dipStr == "oy-l") return QApplication::applicationDirPath()+"/diphone/oy-l.wav";
	 else if(dipStr == "oy-m") return QApplication::applicationDirPath()+"/diphone/oy-m.wav";
	 else if(dipStr == "oy-n") return QApplication::applicationDirPath()+"/diphone/oy-n.wav";
	 else if(dipStr == "oy-ng") return QApplication::applicationDirPath()+"/diphone/oy-ng.wav";
	 else if(dipStr == "oy-ow") return QApplication::applicationDirPath()+"/diphone/oy-ow.wav";
	 else if(dipStr == "oy-oy") return QApplication::applicationDirPath()+"/diphone/oy-oy.wav";
	 else if(dipStr == "oy-p") return QApplication::applicationDirPath()+"/diphone/oy-p.wav";
	 else if(dipStr == "oy-pau") return QApplication::applicationDirPath()+"/diphone/oy-pau.wav";
	 else if(dipStr == "oy-r") return QApplication::applicationDirPath()+"/diphone/oy-r.wav";
	 else if(dipStr == "oy-s") return QApplication::applicationDirPath()+"/diphone/oy-s.wav";
	 else if(dipStr == "oy-sh") return QApplication::applicationDirPath()+"/diphone/oy-sh.wav";
	 else if(dipStr == "oy-t") return QApplication::applicationDirPath()+"/diphone/oy-t.wav";
	 else if(dipStr == "oy-th") return QApplication::applicationDirPath()+"/diphone/oy-th.wav";
	 else if(dipStr == "oy-uh") return QApplication::applicationDirPath()+"/diphone/oy-uh.wav";
	 else if(dipStr == "oy-uw") return QApplication::applicationDirPath()+"/diphone/oy-uw.wav";
	 else if(dipStr == "oy-v") return QApplication::applicationDirPath()+"/diphone/oy-v.wav";
	 else if(dipStr == "oy-w") return QApplication::applicationDirPath()+"/diphone/oy-w.wav";
	 else if(dipStr == "oy-y") return QApplication::applicationDirPath()+"/diphone/oy-y.wav";
	 else if(dipStr == "oy-z") return QApplication::applicationDirPath()+"/diphone/oy-z.wav";
	 else if(dipStr == "oy-zh") return QApplication::applicationDirPath()+"/diphone/oy-zh.wav";   
	 
 // p diphones
	 else if(dipStr =="p-aa") return QApplication::applicationDirPath()+"/diphone/p-aa.wav";   
	 else if(dipStr =="p-ae") return QApplication::applicationDirPath()+"/diphone/p-ae.wav"; 
	 else if(dipStr =="p-ah") return QApplication::applicationDirPath()+"/diphone/p-ah.wav"; 
	 else if(dipStr =="p-ao") return QApplication::applicationDirPath()+"/diphone/p-ao.wav";  
	 else if(dipStr =="p-aw") return QApplication::applicationDirPath()+"/diphone/p-aw.wav";  
	 else if(dipStr =="p-ax") return QApplication::applicationDirPath()+"/diphone/p-ax.wav"; 
	 else if(dipStr =="p-ay") return QApplication::applicationDirPath()+"/diphone/p-ay.wav"; 
	 else if(dipStr =="p-b") return QApplication::applicationDirPath()+"/diphone/p-b.wav";   
	 else if(dipStr =="p-ch") return QApplication::applicationDirPath()+"/diphone/p-ch.wav";  
	 else if(dipStr =="p-d") return QApplication::applicationDirPath()+"/diphone/p-d.wav"; 
	 else if(dipStr =="p-dh") return QApplication::applicationDirPath()+"/diphone/p-dh.wav"; 
	 else if(dipStr =="p-eh") return QApplication::applicationDirPath()+"/diphone/p-eh.wav"; 
	 else if(dipStr =="p-er") return QApplication::applicationDirPath()+"/diphone/p-er.wav"; 
	 else if(dipStr =="p-ey") return QApplication::applicationDirPath()+"/diphone/p-ey.wav"; 
	 else if(dipStr =="p-f") return QApplication::applicationDirPath()+"/diphone/p-f.wav"; 
	 else if(dipStr =="p-g") return QApplication::applicationDirPath()+"/diphone/p-g.wav"; 
	 else if(dipStr =="p-hh") return QApplication::applicationDirPath()+"/diphone/p-hh.wav"; 
	 else if(dipStr =="p-ih") return QApplication::applicationDirPath()+"/diphone/p-ih.wav"; 
	 else if(dipStr =="p-iy") return QApplication::applicationDirPath()+"/diphone/p-iy.wav"; 
	 else if(dipStr =="p-jh") return QApplication::applicationDirPath()+"/diphone/p-jh.wav"; 
	 else if(dipStr =="p-k") return QApplication::applicationDirPath()+"/diphone/p-k.wav"; 
	 else if(dipStr =="p-l") return QApplication::applicationDirPath()+"/diphone/p-l.wav"; 
	 else if(dipStr =="p-m") return QApplication::applicationDirPath()+"/diphone/p-m.wav"; 
	 else if(dipStr =="p-n") return QApplication::applicationDirPath()+"/diphone/p-n.wav"; 
	 else if(dipStr =="p-ow") return QApplication::applicationDirPath()+"/diphone/p-ow.wav"; 
	 else if(dipStr =="p-oy") return QApplication::applicationDirPath()+"/diphone/p-oy.wav"; 
	 else if(dipStr =="p-p") return QApplication::applicationDirPath()+"/diphone/p-p.wav"; 
	 else if(dipStr =="p-pau") return QApplication::applicationDirPath()+"/diphone/p-pau.wav"; 
	 else if(dipStr =="p-r") return QApplication::applicationDirPath()+"/diphone/p-r.wav"; 
	 else if(dipStr =="p-s") return QApplication::applicationDirPath()+"/diphone/p-s.wav"; 
	 else if(dipStr =="p-sh") return QApplication::applicationDirPath()+"/diphone/p-aa.wav"; 
	 else if(dipStr =="p-t") return QApplication::applicationDirPath()+"/diphone/p-t.wav"; 
	 else if(dipStr =="p-th") return QApplication::applicationDirPath()+"/diphone/p-th.wav"; 
	 else if(dipStr =="p-uh") return QApplication::applicationDirPath()+"/diphone/p-uh.wav"; 
	 else if(dipStr =="p-uw") return QApplication::applicationDirPath()+"/diphone/p-uw.wav"; 
	 else if(dipStr =="p-v") return QApplication::applicationDirPath()+"/diphone/p-v.wav"; 
	 else if(dipStr =="p-w") return QApplication::applicationDirPath()+"/diphone/p-w.wav"; 
	 else if(dipStr =="p-y") return QApplication::applicationDirPath()+"/diphone/p-y.wav"; 
	 else if(dipStr =="p-z") return QApplication::applicationDirPath()+"/diphone/p-z.wav"; 
	 else if(dipStr =="p-zh") return QApplication::applicationDirPath()+"/diphone/p-zh.wav";  

// pau diphones
	else if(dipStr == "pau-aa") return QApplication::applicationDirPath()+"/diphone/pau-aa.wav";  
	else if(dipStr == "pau-ae") return QApplication::applicationDirPath()+"/diphone/pau-ae.wav";
	else if(dipStr == "pau-ah") return QApplication::applicationDirPath()+"/diphone/pau-ah.wav";
	else if(dipStr == "pau-ao") return QApplication::applicationDirPath()+"/diphone/pau-ao.wav"; 
	else if(dipStr == "pau-aw") return QApplication::applicationDirPath()+"/diphone/pau-aw.wav"; 
	else if(dipStr == "pau-ax") return QApplication::applicationDirPath()+"/diphone/pau-ax.wav"; 
	else if(dipStr == "pau-ay") return QApplication::applicationDirPath()+"/diphone/pau-ay.wav";
	else if(dipStr == "pau-b") return QApplication::applicationDirPath()+"/diphone/pau-b.wav";  
	else if(dipStr == "pau-ch") return QApplication::applicationDirPath()+"/diphone/pau-ch.wav"; 
	else if(dipStr == "pau-d") return QApplication::applicationDirPath()+"/diphone/pau-d.wav";
	else if(dipStr == "pau-dh") return QApplication::applicationDirPath()+"/diphone/pau-dh.wav";
	else if(dipStr == "pau-eh") return QApplication::applicationDirPath()+"/diphone/pau-eh.wav";
	else if(dipStr == "pau-er") return QApplication::applicationDirPath()+"/diphone/pau-er.wav";
	else if(dipStr == "pau-ey") return QApplication::applicationDirPath()+"/diphone/pau-ey.wav";
	else if(dipStr == "pau-f") return QApplication::applicationDirPath()+"/diphone/pau-f.wav"; 
	else if(dipStr == "pau-g") return QApplication::applicationDirPath()+"/diphone/pau-g.wav";
	else if(dipStr == "pau-hh") return QApplication::applicationDirPath()+"/diphone/pau-hh.wav";
	else if(dipStr == "pau-ih") return QApplication::applicationDirPath()+"/diphone/pau-ih.wav";
	else if(dipStr == "pau-iy") return QApplication::applicationDirPath()+"/diphone/pau-iy.wav";
	else if(dipStr == "pau-jh") return QApplication::applicationDirPath()+"/diphone/pau-jh.wav";
	else if(dipStr == "pau-k") return QApplication::applicationDirPath()+"/diphone/pau-k.wav";
	else if(dipStr == "pau-l") return QApplication::applicationDirPath()+"/diphone/pau-l.wav";
	else if(dipStr == "pau-m") return QApplication::applicationDirPath()+"/diphone/pau-m.wav";
	else if(dipStr == "pau-n") return QApplication::applicationDirPath()+"/diphone/pau-n.wav";
	else if(dipStr == "pau-ow") return QApplication::applicationDirPath()+"/diphone/pau-ow.wav";
	else if(dipStr == "pau-oy") return QApplication::applicationDirPath()+"/diphone/pau-oy.wav";
	else if(dipStr == "pau-p") return QApplication::applicationDirPath()+"/diphone/pau-p.wav";
	else if(dipStr == "pau-pau") return QApplication::applicationDirPath()+"/diphone/pau-pau.wav";
	else if(dipStr == "pau-r") return QApplication::applicationDirPath()+"/diphone/pau-r.wav";
	else if(dipStr == "pau-s") return QApplication::applicationDirPath()+"/diphone/pau-s.wav";
	else if(dipStr == "pau-sh") return QApplication::applicationDirPath()+"/diphone/pau-sh.wav";
	else if(dipStr == "pau-t") return QApplication::applicationDirPath()+"/diphone/pau-t.wav";
	else if(dipStr == "pau-th") return QApplication::applicationDirPath()+"/diphone/pau-th.wav";
	else if(dipStr == "pau-uh") return QApplication::applicationDirPath()+"/diphone/pau-uh.wav";
	else if(dipStr == "pau-uw") return QApplication::applicationDirPath()+"/diphone/pau-uw.wav";
	else if(dipStr == "pau-v") return QApplication::applicationDirPath()+"/diphone/pau-v.wav";
	else if(dipStr == "pau-w") return QApplication::applicationDirPath()+"/diphone/pau-w.wav";
	else if(dipStr == "pau-y") return QApplication::applicationDirPath()+"/diphone/pau-y.wav";
	else if(dipStr == "pau-z") return QApplication::applicationDirPath()+"/diphone/pau-z.wav";
	else if(dipStr == "pau-zh") return QApplication::applicationDirPath()+"/diphone/pau-zh.wav";  
	 
// r diphones
	else if(dipStr == "r-aa") return QApplication::applicationDirPath()+"/diphone/r-aa.wav";  
	else if(dipStr == "r-ae ") return QApplication::applicationDirPath()+"/diphone/r-ae.wav";
	else if(dipStr == "r-ah") return QApplication::applicationDirPath()+"/diphone/r-ah.wav";
	else if(dipStr == "r-ao") return QApplication::applicationDirPath()+"/diphone/r-ao.wav"; 
	else if(dipStr == "r-aw") return QApplication::applicationDirPath()+"/diphone/r-aw.wav"; 
	else if(dipStr == "r-ax") return QApplication::applicationDirPath()+"/diphone/r-ax.wav"; 
	else if(dipStr == "r-ay") return QApplication::applicationDirPath()+"/diphone/r-ay.wav";
	else if(dipStr == "r-b") return QApplication::applicationDirPath()+"/diphone/r-b.wav";  
	else if(dipStr == "r-ch") return QApplication::applicationDirPath()+"/diphone/r-ch.wav";
	else if(dipStr == "r-d") return QApplication::applicationDirPath()+"/diphone/r-d.wav";
	else if(dipStr == "r-dh") return QApplication::applicationDirPath()+"/diphone/r-dh.wav";
	else if(dipStr == "r-eh") return QApplication::applicationDirPath()+"/diphone/r-eh.wav";
	else if(dipStr == "r-er") return QApplication::applicationDirPath()+"/diphone/r-er.wav";
	else if(dipStr == "r-ey") return QApplication::applicationDirPath()+"/diphone/r-ey.wav";
	else if(dipStr == "r-f") return QApplication::applicationDirPath()+"/diphone/r-f.wav"; 
	else if(dipStr == "r-g") return QApplication::applicationDirPath()+"/diphone/r-g.wav";
	else if(dipStr == "r-hh") return QApplication::applicationDirPath()+"/diphone/r-hh.wav";
	else if(dipStr == "r-ih") return QApplication::applicationDirPath()+"/diphone/r-ih.wav";
	else if(dipStr == "r-iy") return QApplication::applicationDirPath()+"/diphone/r-iy.wav";
	else if(dipStr == "r-jh") return QApplication::applicationDirPath()+"/diphone/r-jh.wav";
	else if(dipStr == "r-k") return QApplication::applicationDirPath()+"/diphone/r-k.wav";
	else if(dipStr == "r-l") return QApplication::applicationDirPath()+"/diphone/r-l.wav";
	else if(dipStr == "r-m") return QApplication::applicationDirPath()+"/diphone/r-m.wav";
	else if(dipStr == "r-n") return QApplication::applicationDirPath()+"/diphone/r-n.wav";
	else if(dipStr == "r-ow") return QApplication::applicationDirPath()+"/diphone/r-ow.wav";
	else if(dipStr == "r-oy") return QApplication::applicationDirPath()+"/diphone/r-oy.wav";
	else if(dipStr == "r-p") return QApplication::applicationDirPath()+"/diphone/r-p.wav";
	else if(dipStr == "r-pau") return QApplication::applicationDirPath()+"/diphone/r-pau.wav";
	else if(dipStr == "r-r") return QApplication::applicationDirPath()+"/diphone/r-r.wav";
	else if(dipStr == "r-s") return QApplication::applicationDirPath()+"/diphone/r-s.wav";
	else if(dipStr == "r-sh") return QApplication::applicationDirPath()+"/diphone/r-sh.wav";
	else if(dipStr == "r-t") return QApplication::applicationDirPath()+"/diphone/r-t.wav";
	else if(dipStr == "r-th") return QApplication::applicationDirPath()+"/diphone/r-th.wav";
	else if(dipStr == "r-uh") return QApplication::applicationDirPath()+"/diphone/r-uh.wav";
	else if(dipStr == "r-uw") return QApplication::applicationDirPath()+"/diphone/r-uw.wav";
	else if(dipStr == "r-v") return QApplication::applicationDirPath()+"/diphone/r-v.wav";
	else if(dipStr == "r-w") return QApplication::applicationDirPath()+"/diphone/r-w.wav";
	else if(dipStr == "r-y") return QApplication::applicationDirPath()+"/diphone/r-y.wav";
	else if(dipStr == "r-z") return QApplication::applicationDirPath()+"/diphone/r-z.wav";
	else if(dipStr == "r-zh") return QApplication::applicationDirPath()+"/diphone/r-zh.wav";   	
	
	// s diphones
	else if(dipStr == "s-aa") return QApplication::applicationDirPath()+"/diphone/s-aa.wav";   
	else if(dipStr == "s-ae") return QApplication::applicationDirPath()+"/diphone/s-ae.wav"; 
	else if(dipStr == "s-ah") return QApplication::applicationDirPath()+"/diphone/s-ah.wav"; 
	else if(dipStr == "s-ao") return QApplication::applicationDirPath()+"/diphone/s-ao.wav";  
	else if(dipStr == "s-aw") return QApplication::applicationDirPath()+"/diphone/s-aw.wav"; 
	else if(dipStr == "s-ax") return QApplication::applicationDirPath()+"/diphone/s-ax.wav";  
	else if(dipStr == "s-ay") return QApplication::applicationDirPath()+"/diphone/s-ay.wav"; 
	else if(dipStr == "s-b") return QApplication::applicationDirPath()+"/diphone/s-b.wav";   
	else if(dipStr == "s-ch") return QApplication::applicationDirPath()+"/diphone/s-ch.wav";  
	else if(dipStr == "s-d") return QApplication::applicationDirPath()+"/diphone/s-d.wav"; 
	else if(dipStr == "s-dh") return QApplication::applicationDirPath()+"/diphone/s-dh.wav"; 
	else if(dipStr == "s-eh") return QApplication::applicationDirPath()+"/diphone/s-eh.wav"; 
	else if(dipStr == "s-er") return QApplication::applicationDirPath()+"/diphone/s-er.wav"; 
	else if(dipStr == "s-ey") return QApplication::applicationDirPath()+"/diphone/s-ey.wav"; 
	else if(dipStr == "s-f") return QApplication::applicationDirPath()+"/diphone/s-f.wav";  
	else if(dipStr == "s-g") return QApplication::applicationDirPath()+"/diphone/s-g.wav"; 
	else if(dipStr == "s-hh") return QApplication::applicationDirPath()+"/diphone/s-hh.wav"; 
	else if(dipStr == "s-ih") return QApplication::applicationDirPath()+"/diphone/s-ih.wav"; 
	else if(dipStr == "s-iy") return QApplication::applicationDirPath()+"/diphone/s-iy.wav"; 
	else if(dipStr == "s-jh") return QApplication::applicationDirPath()+"/diphone/s-jh.wav"; 
	else if(dipStr == "s-k") return QApplication::applicationDirPath()+"/diphone/s-k.wav"; 
	else if(dipStr == "s-l") return QApplication::applicationDirPath()+"/diphone/s-l.wav"; 
	else if(dipStr == "s-m") return QApplication::applicationDirPath()+"/diphone/s-m.wav"; 
	else if(dipStr == "s-n") return QApplication::applicationDirPath()+"/diphone/s-n.wav"; 
	else if(dipStr == "s-ow") return QApplication::applicationDirPath()+"/diphone/s-ow.wav"; 
	else if(dipStr == "s-oy") return QApplication::applicationDirPath()+"/diphone/s-oy.wav"; 
	else if(dipStr == "s-p") return QApplication::applicationDirPath()+"/diphone/s-p.wav"; 
	else if(dipStr == "s-pau") return QApplication::applicationDirPath()+"/diphone/s-pau.wav"; 
	else if(dipStr == "s-r") return QApplication::applicationDirPath()+"/diphone/s-r.wav"; 
	else if(dipStr == "s-s") return QApplication::applicationDirPath()+"/diphone/s-s.wav"; 
	else if(dipStr == "s-sh") return QApplication::applicationDirPath()+"/diphone/s-sh.wav"; 
	else if(dipStr == "s-t") return QApplication::applicationDirPath()+"/diphone/s-t.wav"; 
	else if(dipStr == "s-th") return QApplication::applicationDirPath()+"/diphone/s-th.wav"; 
	else if(dipStr == "s-uh") return QApplication::applicationDirPath()+"/diphone/s-uh.wav"; 
	else if(dipStr == "s-uw") return QApplication::applicationDirPath()+"/diphone/s-uw.wav"; 
	else if(dipStr == "s-v") return QApplication::applicationDirPath()+"/diphone/s-v.wav"; 
	else if(dipStr == "s-w") return QApplication::applicationDirPath()+"/diphone/s-w.wav"; 
	else if(dipStr == "s-y") return QApplication::applicationDirPath()+"/diphone/s-y.wav"; 
	else if(dipStr == "s-z") return QApplication::applicationDirPath()+"/diphone/s-z.wav"; 
	else if(dipStr == "s-zh") return QApplication::applicationDirPath()+"/diphone/s-zh.wav";   
	
// sh diphones
	else if(dipStr == "sh-aa") return QApplication::applicationDirPath()+"/diphone/sh-aa.wav";   
	else if(dipStr == "sh-ae") return QApplication::applicationDirPath()+"/diphone/sh-ae.wav"; 
	else if(dipStr == "sh-ah") return QApplication::applicationDirPath()+"/diphone/sh-ah.wav"; 
	else if(dipStr == "sh-ao") return QApplication::applicationDirPath()+"/diphone/sh-ao.wav";  
	else if(dipStr == "sh-aw") return QApplication::applicationDirPath()+"/diphone/sh-aw.wav";  
	else if(dipStr == "sh-ax") return QApplication::applicationDirPath()+"/diphone/sh-ax.wav";  
	else if(dipStr == "sh-ay") return QApplication::applicationDirPath()+"/diphone/sh-ay.wav"; 
	else if(dipStr == "sh-b") return QApplication::applicationDirPath()+"/diphone/sh-b.wav";   
	else if(dipStr == "sh-ch") return QApplication::applicationDirPath()+"/diphone/sh-ch.wav";  
	else if(dipStr == "sh-d") return QApplication::applicationDirPath()+"/diphone/sh-d.wav"; 
	else if(dipStr == "sh-dh") return QApplication::applicationDirPath()+"/diphone/sh-dh.wav"; 
	else if(dipStr == "sh-eh") return QApplication::applicationDirPath()+"/diphone/sh-eh.wav"; 
	else if(dipStr == "sh-er") return QApplication::applicationDirPath()+"/diphone/sh-er.wav"; 
	else if(dipStr == "sh-ey") return QApplication::applicationDirPath()+"/diphone/sh-ey.wav"; 
	else if(dipStr == "sh-f") return QApplication::applicationDirPath()+"/diphone/sh-f.wav";  
	else if(dipStr == "sh-g") return QApplication::applicationDirPath()+"/diphone/sh-g.wav"; 
	else if(dipStr == "sh-hh") return QApplication::applicationDirPath()+"/diphone/sh-hh.wav"; 
	else if(dipStr == "sh-ih") return QApplication::applicationDirPath()+"/diphone/sh-ih.wav"; 
	else if(dipStr == "sh-iy") return QApplication::applicationDirPath()+"/diphone/sh-iy.wav"; 
	else if(dipStr == "sh-jh") return QApplication::applicationDirPath()+"/diphone/sh-jh.wav"; 
	else if(dipStr == "sh-k") return QApplication::applicationDirPath()+"/diphone/sh-k.wav"; 
	else if(dipStr == "sh-l") return QApplication::applicationDirPath()+"/diphone/sh-l.wav"; 
	else if(dipStr == "sh-m") return QApplication::applicationDirPath()+"/diphone/sh-m.wav"; 
	else if(dipStr == "sh-n") return QApplication::applicationDirPath()+"/diphone/sh-n.wav"; 
	else if(dipStr == "sh-ow") return QApplication::applicationDirPath()+"/diphone/sh-ow.wav"; 
	else if(dipStr == "sh-oy") return QApplication::applicationDirPath()+"/diphone/sh-oy.wav"; 
	else if(dipStr == "sh-p") return QApplication::applicationDirPath()+"/diphone/sh-p.wav"; 
	else if(dipStr == "sh-pau") return QApplication::applicationDirPath()+"/diphone/sh-pau.wav"; 
	else if(dipStr == "sh-r") return QApplication::applicationDirPath()+"/diphone/sh-r.wav"; 
	else if(dipStr == "sh-s") return QApplication::applicationDirPath()+"/diphone/sh-s.wav"; 
	else if(dipStr == "sh-sh") return QApplication::applicationDirPath()+"/diphone/sh-sh.wav"; 
	else if(dipStr == "sh-t") return QApplication::applicationDirPath()+"/diphone/sh-t.wav"; 
	else if(dipStr == "sh-th") return QApplication::applicationDirPath()+"/diphone/sh-th.wav"; 
	else if(dipStr == "sh-uh") return QApplication::applicationDirPath()+"/diphone/sh-uh.wav"; 
	else if(dipStr == "sh-uw") return QApplication::applicationDirPath()+"/diphone/sh-uw.wav"; 
	else if(dipStr == "sh-v") return QApplication::applicationDirPath()+"/diphone/sh-v.wav"; 
	else if(dipStr == "sh-w") return QApplication::applicationDirPath()+"/diphone/sh-w.wav"; 
	else if(dipStr == "sh-y") return QApplication::applicationDirPath()+"/diphone/sh-y.wav"; 
	else if(dipStr == "sh-z") return QApplication::applicationDirPath()+"/diphone/sh-z.wav"; 
	else if(dipStr == "sh-zh") return QApplication::applicationDirPath()+"/diphone/sh-zh.wav";    	 
  
// t diphones
	else if(dipStr == "t-aa") return QApplication::applicationDirPath()+"/diphone/t-aa.wav"; 
	else if(dipStr == "t-ae") return QApplication::applicationDirPath()+"/diphone/t-ae.wav";
	else if(dipStr == "t-ah") return QApplication::applicationDirPath()+"/diphone/t-ah.wav";
	else if(dipStr == "t-ao") return QApplication::applicationDirPath()+"/diphone/t-ao.wav"; 
	else if(dipStr == "t-aw") return QApplication::applicationDirPath()+"/diphone/t-aw.wav"; 
	else if(dipStr == "t-ax") return QApplication::applicationDirPath()+"/diphone/t-ax.wav"; 
	else if(dipStr == "t-ay") return QApplication::applicationDirPath()+"/diphone/t-ay.wav";
	else if(dipStr == "t-b") return QApplication::applicationDirPath()+"/diphone/t-b.wav";  
	else if(dipStr == "t-ch") return QApplication::applicationDirPath()+"/diphone/t-ch.wav"; 
	else if(dipStr == "t-d") return QApplication::applicationDirPath()+"/diphone/t-d.wav";
	else if(dipStr == "t-dh") return QApplication::applicationDirPath()+"/diphone/t-dh.wav";
	else if(dipStr == "t-eh") return QApplication::applicationDirPath()+"/diphone/t-eh.wav";
	else if(dipStr == "t-er") return QApplication::applicationDirPath()+"/diphone/t-er.wav";
	else if(dipStr == "t-ey") return QApplication::applicationDirPath()+"/diphone/t-ey.wav";
	else if(dipStr == "t-f") return QApplication::applicationDirPath()+"/diphone/t-f.wav";
	else if(dipStr == "t-g") return QApplication::applicationDirPath()+"/diphone/t-g.wav";
	else if(dipStr == "t-hh") return QApplication::applicationDirPath()+"/diphone/t-hh.wav";
	else if(dipStr == "t-ih") return QApplication::applicationDirPath()+"/diphone/t-ih.wav";
	else if(dipStr == "t-iy") return QApplication::applicationDirPath()+"/diphone/t-iy.wav";
	else if(dipStr == "t-jh") return QApplication::applicationDirPath()+"/diphone/t-jh.wav";
	else if(dipStr == "t-k") return QApplication::applicationDirPath()+"/diphone/t-k.wav";
	else if(dipStr == "t-l") return QApplication::applicationDirPath()+"/diphone/t-l.wav";
	else if(dipStr == "t-m") return QApplication::applicationDirPath()+"/diphone/t-m.wav";
	else if(dipStr == "t-n") return QApplication::applicationDirPath()+"/diphone/t-n.wav";
	else if(dipStr == "t-ow") return QApplication::applicationDirPath()+"/diphone/t-ow.wav";
	else if(dipStr == "t-oy") return QApplication::applicationDirPath()+"/diphone/t-oy.wav";
	else if(dipStr == "t-p") return QApplication::applicationDirPath()+"/diphone/t-p.wav";
	else if(dipStr == "t-pau") return QApplication::applicationDirPath()+"/diphone/t-pau.wav";
	else if(dipStr == "t-r") return QApplication::applicationDirPath()+"/diphone/t-r.wav";
	else if(dipStr == "t-s") return QApplication::applicationDirPath()+"/diphone/t-s.wav";
	else if(dipStr == "t-sh") return QApplication::applicationDirPath()+"/diphone/t-sh.wav";
	else if(dipStr == "t-t") return QApplication::applicationDirPath()+"/diphone/t-t.wav";
	else if(dipStr == "t-th") return QApplication::applicationDirPath()+"/diphone/t-th.wav";
	else if(dipStr == "t-uh") return QApplication::applicationDirPath()+"/diphone/t-uh.wav";
	else if(dipStr == "t-uw") return QApplication::applicationDirPath()+"/diphone/t-uw.wav";
	else if(dipStr == "t-v") return QApplication::applicationDirPath()+"/diphone/t-v.wav";
	else if(dipStr == "t-w") return QApplication::applicationDirPath()+"/diphone/t-w.wav";
	else if(dipStr == "t-y") return QApplication::applicationDirPath()+"/diphone/t-y.wav";
	else if(dipStr == "t-z") return QApplication::applicationDirPath()+"/diphone/t-z.wav";
	else if(dipStr == "t-zh") return QApplication::applicationDirPath()+"/diphone/t-zh.wav";     
	
// th diphones
	else if(dipStr == "th-aa") return QApplication::applicationDirPath()+"/diphone/th-aa.wav";  
	else if(dipStr == "th-ae") return QApplication::applicationDirPath()+"/diphone/th-ae.wav"; 
	else if(dipStr == "th-ah") return QApplication::applicationDirPath()+"/diphone/th-ah.wav"; 
	else if(dipStr == "th-ao") return QApplication::applicationDirPath()+"/diphone/th-ao.wav";  
	else if(dipStr == "th-aw") return QApplication::applicationDirPath()+"/diphone/th-aw.wav";  
	else if(dipStr == "th-ax") return QApplication::applicationDirPath()+"/diphone/th-ax.wav";  
	else if(dipStr == "th-ay") return QApplication::applicationDirPath()+"/diphone/th-ay.wav"; 
	else if(dipStr == "th-b") return QApplication::applicationDirPath()+"/diphone/th-b.wav";   
	else if(dipStr == "th-ch") return QApplication::applicationDirPath()+"/diphone/th-ch.wav";  
	else if(dipStr == "th-d") return QApplication::applicationDirPath()+"/diphone/th-d.wav"; 
	else if(dipStr == "th-dh") return QApplication::applicationDirPath()+"/diphone/th-dh.wav"; 
	else if(dipStr == "th-eh") return QApplication::applicationDirPath()+"/diphone/th-eh.wav"; 
	else if(dipStr == "th-er") return QApplication::applicationDirPath()+"/diphone/th-er.wav"; 
	else if(dipStr == "th-ey") return QApplication::applicationDirPath()+"/diphone/th-ey.wav"; 
	else if(dipStr == "th-f") return QApplication::applicationDirPath()+"/diphone/th-f.wav";  
	else if(dipStr == "th-g") return QApplication::applicationDirPath()+"/diphone/th-g.wav"; 
	else if(dipStr == "th-hh") return QApplication::applicationDirPath()+"/diphone/th-hh.wav"; 
	else if(dipStr == "th-ih") return QApplication::applicationDirPath()+"/diphone/th-ih.wav"; 
	else if(dipStr == "th-iy") return QApplication::applicationDirPath()+"/diphone/th-iy.wav"; 
	else if(dipStr == "th-jh") return QApplication::applicationDirPath()+"/diphone/th-jh.wav"; 
	else if(dipStr == "th-k") return QApplication::applicationDirPath()+"/diphone/th-k.wav"; 
	else if(dipStr == "th-l") return QApplication::applicationDirPath()+"/diphone/th-l.wav"; 
	else if(dipStr == "th-m") return QApplication::applicationDirPath()+"/diphone/th-m.wav"; 
	else if(dipStr == "th-n") return QApplication::applicationDirPath()+"/diphone/th-n.wav"; 
	else if(dipStr == "th-ow") return QApplication::applicationDirPath()+"/diphone/th-ow.wav"; 
	else if(dipStr == "th-oy") return QApplication::applicationDirPath()+"/diphone/th-oy.wav"; 
	else if(dipStr == "th-p") return QApplication::applicationDirPath()+"/diphone/th-p.wav"; 
	else if(dipStr == "th-pau") return QApplication::applicationDirPath()+"/diphone/th-pau.wav"; 
	else if(dipStr == "th-r") return QApplication::applicationDirPath()+"/diphone/th-r.wav"; 
	else if(dipStr == "th-s") return QApplication::applicationDirPath()+"/diphone/th-s.wav"; 
	else if(dipStr == "th-sh") return QApplication::applicationDirPath()+"/diphone/th-aa.wav"; 
	else if(dipStr == "th-t") return QApplication::applicationDirPath()+"/diphone/th-aa.wav"; 
	else if(dipStr == "th-th") return QApplication::applicationDirPath()+"/diphone/th-th.wav"; 
	else if(dipStr == "th-uh") return QApplication::applicationDirPath()+"/diphone/th-uh.wav"; 
	else if(dipStr == "th-uw") return QApplication::applicationDirPath()+"/diphone/th-uw.wav"; 
	else if(dipStr == "th-v") return QApplication::applicationDirPath()+"/diphone/th-v.wav"; 
	else if(dipStr == "th-w") return QApplication::applicationDirPath()+"/diphone/th-w.wav"; 
	else if(dipStr == "th-y") return QApplication::applicationDirPath()+"/diphone/th-y.wav"; 
	else if(dipStr == "th-z") return QApplication::applicationDirPath()+"/diphone/th-z.wav"; 
	else if(dipStr == "th-zh") return QApplication::applicationDirPath()+"/diphone/th-zh.wav";    
	
	// uh diphones
	else if(dipStr == "uh-aa") return QApplication::applicationDirPath()+"/diphone/uh-aa.wav";  
	else if(dipStr == "uh-ae") return QApplication::applicationDirPath()+"/diphone/uh-ae.wav";
	else if(dipStr == "uh-ah") return QApplication::applicationDirPath()+"/diphone/uh-ah.wav";
	else if(dipStr == "uh-ao") return QApplication::applicationDirPath()+"/diphone/uh-ao.wav"; 
	else if(dipStr == "uh-aw") return QApplication::applicationDirPath()+"/diphone/uh-aw.wav"; 
	else if(dipStr == "uh-ax") return QApplication::applicationDirPath()+"/diphone/uh-ax.wav"; 
	else if(dipStr == "uh-ay") return QApplication::applicationDirPath()+"/diphone/uh-ay.wav";
	else if(dipStr == "uh-b") return QApplication::applicationDirPath()+"/diphone/uh-b.wav";  
	else if(dipStr == "uh-ch") return QApplication::applicationDirPath()+"/diphone/uh-ch.wav"; 
	else if(dipStr == "uh-d") return QApplication::applicationDirPath()+"/diphone/uh-d.wav";
	else if(dipStr == "uh-dh") return QApplication::applicationDirPath()+"/diphone/uh-dh.wav";
	else if(dipStr == "uh-eh") return QApplication::applicationDirPath()+"/diphone/uh-eh.wav";
	else if(dipStr == "uh-er") return QApplication::applicationDirPath()+"/diphone/uh-er.wav";
	else if(dipStr == "uh-ey") return QApplication::applicationDirPath()+"/diphone/uh-ey.wav";
	else if(dipStr == "uh-f") return QApplication::applicationDirPath()+"/diphone/uh-f.wav";
	else if(dipStr == "uh-g") return QApplication::applicationDirPath()+"/diphone/uh-g.wav";
	else if(dipStr == "uh-hh") return QApplication::applicationDirPath()+"/diphone/uh-hh.wav";
	else if(dipStr == "uh-ih") return QApplication::applicationDirPath()+"/diphone/uh-ih.wav";
	else if(dipStr == "uh-iy") return QApplication::applicationDirPath()+"/diphone/uh-iy.wav";
	else if(dipStr == "uh-jh") return QApplication::applicationDirPath()+"/diphone/uh-jh.wav";
	else if(dipStr == "uh-k") return QApplication::applicationDirPath()+"/diphone/uh-k.wav";
	else if(dipStr == "uh-l") return QApplication::applicationDirPath()+"/diphone/uh-l.wav";
	else if(dipStr == "uh-m") return QApplication::applicationDirPath()+"/diphone/uh-m.wav";
	else if(dipStr == "uh-n") return QApplication::applicationDirPath()+"/diphone/uh-n.wav";
	else if(dipStr == "uh-ng") return QApplication::applicationDirPath()+"/diphone/uh-ng.wav";
	else if(dipStr == "uh-ow") return QApplication::applicationDirPath()+"/diphone/uh-ow.wav";
	else if(dipStr == "uh-oy") return QApplication::applicationDirPath()+"/diphone/uh-oy.wav";
	else if(dipStr == "uh-p") return QApplication::applicationDirPath()+"/diphone/uh-p.wav";
	else if(dipStr == "uh-pau") return QApplication::applicationDirPath()+"/diphone/uh-pau.wav";
	else if(dipStr == "uh-r") return QApplication::applicationDirPath()+"/diphone/uh-r.wav";
	else if(dipStr == "uh-s") return QApplication::applicationDirPath()+"/diphone/uh-s.wav";
	else if(dipStr == "uh-sh") return QApplication::applicationDirPath()+"/diphone/uh-sh.wav";
	else if(dipStr == "uh-t") return QApplication::applicationDirPath()+"/diphone/uh-t.wav";
	else if(dipStr == "uh-th") return QApplication::applicationDirPath()+"/diphone/uh-th.wav";
	else if(dipStr == "uh-uh") return QApplication::applicationDirPath()+"/diphone/uh-uh.wav";
	else if(dipStr == "uh-uw") return QApplication::applicationDirPath()+"/diphone/uh-uw.wav";
	else if(dipStr == "uh-v") return QApplication::applicationDirPath()+"/diphone/uh-v.wav";
	else if(dipStr == "uh-w") return QApplication::applicationDirPath()+"/diphone/uh-w.wav";
	else if(dipStr == "uh-y") return QApplication::applicationDirPath()+"/diphone/uh-y.wav";
	else if(dipStr == "uh-z") return QApplication::applicationDirPath()+"/diphone/uh-z.wav";
	else if(dipStr == "uh-zh") return QApplication::applicationDirPath()+"/diphone/uh-zh.wav";  
	
// uw diphones
	else if(dipStr =="uw-aa") return QApplication::applicationDirPath()+"/diphone/uw-aa.wav";  
	else if(dipStr =="uw-ae") return QApplication::applicationDirPath()+"/diphone/uw-ae.wav";
	else if(dipStr =="uw-ah") return QApplication::applicationDirPath()+"/diphone/uw-ah.wav";
	else if(dipStr =="uw-ao") return QApplication::applicationDirPath()+"/diphone/uw-ao.wav"; 
	else if(dipStr =="uw-aw") return QApplication::applicationDirPath()+"/diphone/uw-aw.wav";
	else if(dipStr =="uw-ax") return QApplication::applicationDirPath()+"/diphone/uw-ax.wav"; 
	else if(dipStr =="uw-ay") return QApplication::applicationDirPath()+"/diphone/uw-ay.wav";
	else if(dipStr =="uw-b") return QApplication::applicationDirPath()+"/diphone/uw-b.wav";  
	else if(dipStr =="uw-ch") return QApplication::applicationDirPath()+"/diphone/uw-ch.wav"; 
	else if(dipStr =="uw-d") return QApplication::applicationDirPath()+"/diphone/uw-d.wav";
	else if(dipStr =="uw-dh") return QApplication::applicationDirPath()+"/diphone/uw-dh.wav";
	else if(dipStr =="uw-eh") return QApplication::applicationDirPath()+"/diphone/uw-eh.wav";
	else if(dipStr =="uw-er") return QApplication::applicationDirPath()+"/diphone/uw-er.wav";
	else if(dipStr =="uw-ey") return QApplication::applicationDirPath()+"/diphone/uw-ey.wav";
	else if(dipStr =="uw-f") return QApplication::applicationDirPath()+"/diphone/uw-f.wav"; 
	else if(dipStr =="uw-g") return QApplication::applicationDirPath()+"/diphone/uw-g.wav";
	else if(dipStr =="uw-hh") return QApplication::applicationDirPath()+"/diphone/uw-hh.wav";
	else if(dipStr =="uw-ih") return QApplication::applicationDirPath()+"/diphone/uw-ih.wav";
	else if(dipStr =="uw-iy") return QApplication::applicationDirPath()+"/diphone/uw-iy.wav";
	else if(dipStr =="uw-jh") return QApplication::applicationDirPath()+"/diphone/uw-jh.wav";
	else if(dipStr =="uw-k") return QApplication::applicationDirPath()+"/diphone/uw-k.wav";
	else if(dipStr =="uw-l") return QApplication::applicationDirPath()+"/diphone/uw-l.wav";
	else if(dipStr =="uw-m") return QApplication::applicationDirPath()+"/diphone/uw-m.wav";
	else if(dipStr =="uw-n") return QApplication::applicationDirPath()+"/diphone/uw-n.wav";
	else if(dipStr =="uw-ng") return QApplication::applicationDirPath()+"/diphone/uw-ng.wav";
	else if(dipStr =="uw-ow") return QApplication::applicationDirPath()+"/diphone/uw-ow.wav";
	else if(dipStr =="uw-oy") return QApplication::applicationDirPath()+"/diphone/uw-oy.wav";
	else if(dipStr =="uw-p") return QApplication::applicationDirPath()+"/diphone/uw-p.wav";
	else if(dipStr =="uw-pau") return QApplication::applicationDirPath()+"/diphone/uw-pau.wav";
	else if(dipStr =="uw-r") return QApplication::applicationDirPath()+"/diphone/uw-r.wav";
	else if(dipStr =="uw-s") return QApplication::applicationDirPath()+"/diphone/uw-s.wav";
	else if(dipStr =="uw-sh") return QApplication::applicationDirPath()+"/diphone/uw-sh.wav";
	else if(dipStr =="uw-t") return QApplication::applicationDirPath()+"/diphone/uw-t.wav";
	else if(dipStr =="uw-th") return QApplication::applicationDirPath()+"/diphone/uw-th.wav";
	else if(dipStr =="uw-uh") return QApplication::applicationDirPath()+"/diphone/uw-uh.wav";
	else if(dipStr =="uw-uw") return QApplication::applicationDirPath()+"/diphone/uw-uw.wav";
	else if(dipStr =="uw-v") return QApplication::applicationDirPath()+"/diphone/uw-v.wav";
	else if(dipStr =="uw-w") return QApplication::applicationDirPath()+"/diphone/uw-w.wav";
	else if(dipStr =="uw-y") return QApplication::applicationDirPath()+"/diphone/uw-y.wav";
	else if(dipStr =="uw-z") return QApplication::applicationDirPath()+"/diphone/uw-z.wav";
	else if(dipStr =="uw-zh") return QApplication::applicationDirPath()+"/diphone/uw-zh.wav";   	

//v diphones	
	else if(dipStr =="v-aa ") return QApplication::applicationDirPath()+"/diphone/v-aa.wav"; 
	else if(dipStr =="v-ae") return QApplication::applicationDirPath()+"/diphone/v-ae.wav"; 
	else if(dipStr =="v-ah") return QApplication::applicationDirPath()+"/diphone/v-ah.wav"; 
	else if(dipStr =="v-ao") return QApplication::applicationDirPath()+"/diphone/v-ao.wav"; 
	else if(dipStr =="v-aw") return QApplication::applicationDirPath()+"/diphone/v-aw.wav";  
	else if(dipStr =="v-ax") return QApplication::applicationDirPath()+"/diphone/v-ax.wav";  
	else if(dipStr =="v-ay") return QApplication::applicationDirPath()+"/diphone/v-ay.wav"; 
	else if(dipStr =="v-b") return QApplication::applicationDirPath()+"/diphone/v-b.wav";   
	else if(dipStr =="v-ch") return QApplication::applicationDirPath()+"/diphone/v-ch.wav";  
	else if(dipStr =="v-d") return QApplication::applicationDirPath()+"/diphone/v-d.wav"; 
	else if(dipStr =="v-dh") return QApplication::applicationDirPath()+"/diphone/v-dh.wav"; 
	else if(dipStr =="v-eh") return QApplication::applicationDirPath()+"/diphone/v-eh.wav"; 
	else if(dipStr =="v-er") return QApplication::applicationDirPath()+"/diphone/v-er.wav"; 
	else if(dipStr =="v-ey") return QApplication::applicationDirPath()+"/diphone/v-ey.wav"; 
	else if(dipStr =="v-f") return QApplication::applicationDirPath()+"/diphone/v-f.wav"; 
	else if(dipStr =="v-g") return QApplication::applicationDirPath()+"/diphone/v-g.wav"; 
	else if(dipStr =="v-hh") return QApplication::applicationDirPath()+"/diphone/v-hh.wav"; 
	else if(dipStr =="v-ih") return QApplication::applicationDirPath()+"/diphone/v-ih.wav"; 
	else if(dipStr =="v-iy") return QApplication::applicationDirPath()+"/diphone/v-iy.wav"; 
	else if(dipStr =="v-jh") return QApplication::applicationDirPath()+"/diphone/v-jh.wav"; 
	else if(dipStr =="v-k") return QApplication::applicationDirPath()+"/diphone/v-k.wav"; 
	else if(dipStr =="v-l") return QApplication::applicationDirPath()+"/diphone/v-l.wav"; 
	else if(dipStr =="v-m") return QApplication::applicationDirPath()+"/diphone/v-m.wav"; 
	else if(dipStr =="v-n") return QApplication::applicationDirPath()+"/diphone/v-n.wav"; 
	else if(dipStr =="v-ow") return QApplication::applicationDirPath()+"/diphone/v-ow.wav"; 
	else if(dipStr =="v-oy") return QApplication::applicationDirPath()+"/diphone/v-oy.wav"; 
	else if(dipStr =="v-p") return QApplication::applicationDirPath()+"/diphone/v-p.wav"; 
	else if(dipStr =="v-pau") return QApplication::applicationDirPath()+"/diphone/v-pau.wav"; 
	else if(dipStr =="v-r") return QApplication::applicationDirPath()+"/diphone/v-r.wav"; 
	else if(dipStr =="v-s") return QApplication::applicationDirPath()+"/diphone/v-s.wav"; 
	else if(dipStr =="v-sh") return QApplication::applicationDirPath()+"/diphone/v-sh.wav"; 
	else if(dipStr =="v-t") return QApplication::applicationDirPath()+"/diphone/v-t.wav"; 
	else if(dipStr =="v-th") return QApplication::applicationDirPath()+"/diphone/v-th.wav"; 
	else if(dipStr =="v-uh") return QApplication::applicationDirPath()+"/diphone/v-uh.wav"; 
	else if(dipStr =="v-uw") return QApplication::applicationDirPath()+"/diphone/v-uw.wav"; 
	else if(dipStr =="v-v") return QApplication::applicationDirPath()+"/diphone/v-v.wav"; 
	else if(dipStr =="v-w") return QApplication::applicationDirPath()+"/diphone/v-w.wav"; 
	else if(dipStr =="v-y") return QApplication::applicationDirPath()+"/diphone/v-y.wav"; 
	else if(dipStr =="v-z") return QApplication::applicationDirPath()+"/diphone/v-z.wav"; 
	else if(dipStr =="v-zh") return QApplication::applicationDirPath()+"/diphone/v-zh.wav";

// w diphones
	else if(dipStr == "w-aa") return QApplication::applicationDirPath()+"/diphone/w-aa.wav";  
	else if(dipStr == "w-ae") return QApplication::applicationDirPath()+"/diphone/w-ae.wav"; 
	else if(dipStr == "w-ah") return QApplication::applicationDirPath()+"/diphone/w-ah.wav"; 
	else if(dipStr == "w-ao") return QApplication::applicationDirPath()+"/diphone/w-ao.wav";  
	else if(dipStr == "w-aw") return QApplication::applicationDirPath()+"/diphone/w-aw.wav";  
	else if(dipStr == "w-ax") return QApplication::applicationDirPath()+"/diphone/w-ax.wav";  
	else if(dipStr == "w-ay") return QApplication::applicationDirPath()+"/diphone/w-ay.wav"; 
	else if(dipStr == "w-eh") return QApplication::applicationDirPath()+"/diphone/w-eh.wav"; 
	else if(dipStr == "w-ih") return QApplication::applicationDirPath()+"/diphone/w-ih.wav"; 
	else if(dipStr == "w-iy") return QApplication::applicationDirPath()+"/diphone/w-iy.wav"; 
	else if(dipStr == "w-uh") return QApplication::applicationDirPath()+"/diphone/w-uh.wav"; 
	else if(dipStr == "w-uw") return QApplication::applicationDirPath()+"/diphone/w-uw.wav";   
	 
// y diphones
	else if(dipStr == "y-aa") return QApplication::applicationDirPath()+"/diphone/y-aa.wav";  
	else if(dipStr == "y-ae") return QApplication::applicationDirPath()+"/diphone/y-ae.wav"; 
	else if(dipStr == "y-ah") return QApplication::applicationDirPath()+"/diphone/y-ah.wav"; 
	else if(dipStr == "y-ao") return QApplication::applicationDirPath()+"/diphone/y-ao.wav";  
	else if(dipStr == "y-aw") return QApplication::applicationDirPath()+"/diphone/y-aw.wav";  
	else if(dipStr == "y-ax") return QApplication::applicationDirPath()+"/diphone/y-ax.wav";  
	else if(dipStr == "y-ay") return QApplication::applicationDirPath()+"/diphone/y-ay.wav"; 
	else if(dipStr == "y-eh") return QApplication::applicationDirPath()+"/diphone/y-eh.wav"; 
	else if(dipStr == "y-ey") return QApplication::applicationDirPath()+"/diphone/y-ey.wav"; 
	else if(dipStr == "y-ih") return QApplication::applicationDirPath()+"/diphone/y-ih.wav"; 
	else if(dipStr == "y-iy") return QApplication::applicationDirPath()+"/diphone/y-iy.wav"; 
	else if(dipStr == "y-ow") return QApplication::applicationDirPath()+"/diphone/y-ow.wav"; 
	else if(dipStr == "y-oy") return QApplication::applicationDirPath()+"/diphone/y-oy.wav"; 
	else if(dipStr == "y-uh") return QApplication::applicationDirPath()+"/diphone/y-uh.wav"; 
	else if(dipStr == "y-uw") return QApplication::applicationDirPath()+"/diphone/y-uw.wav";  

// z diphones
	else if(dipStr =="z-aa") return QApplication::applicationDirPath()+"/diphone/z-aa.wav";  
	else if(dipStr =="z-ae") return QApplication::applicationDirPath()+"/diphone/z-ae.wav";
	else if(dipStr =="z-ah") return QApplication::applicationDirPath()+"/diphone/z-ah.wav";
	else if(dipStr =="z-ao") return QApplication::applicationDirPath()+"/diphone/z-ao.wav"; 
	else if(dipStr =="z-aw") return QApplication::applicationDirPath()+"/diphone/z-aw.wav"; 
	else if(dipStr =="z-ax") return QApplication::applicationDirPath()+"/diphone/z-ax.wav"; 
	else if(dipStr =="z-ay") return QApplication::applicationDirPath()+"/diphone/z-ay.wav";
	else if(dipStr =="z-b") return QApplication::applicationDirPath()+"/diphone/z-b.wav";  
	else if(dipStr =="z-ch") return QApplication::applicationDirPath()+"/diphone/z-ch.wav"; 
	else if(dipStr =="z-d") return QApplication::applicationDirPath()+"/diphone/z-d.wav";
	else if(dipStr =="z-dh") return QApplication::applicationDirPath()+"/diphone/z-dh.wav";
	else if(dipStr =="z-eh") return QApplication::applicationDirPath()+"/diphone/z-eh.wav";
	else if(dipStr =="z-er") return QApplication::applicationDirPath()+"/diphone/z-er.wav";
	else if(dipStr =="z-ey") return QApplication::applicationDirPath()+"/diphone/z-ey.wav";
	else if(dipStr =="z-f") return QApplication::applicationDirPath()+"/diphone/z-f.wav"; 
	else if(dipStr =="z-g") return QApplication::applicationDirPath()+"/diphone/z-g.wav";
	else if(dipStr =="z-hh") return QApplication::applicationDirPath()+"/diphone/z-hh.wav";
	else if(dipStr =="z-ih") return QApplication::applicationDirPath()+"/diphone/z-ih.wav";
	else if(dipStr =="z-iy") return QApplication::applicationDirPath()+"/diphone/z-iy.wav";
	else if(dipStr =="z-jh") return QApplication::applicationDirPath()+"/diphone/z-jh.wav";
	else if(dipStr =="z-k") return QApplication::applicationDirPath()+"/diphone/z-k.wav";
	else if(dipStr =="z-l") return QApplication::applicationDirPath()+"/diphone/z-l.wav";
	else if(dipStr =="z-m") return QApplication::applicationDirPath()+"/diphone/z-m.wav";
	else if(dipStr =="z-n") return QApplication::applicationDirPath()+"/diphone/z-n.wav";
	else if(dipStr =="z-ow") return QApplication::applicationDirPath()+"/diphone/z-ow.wav";
	else if(dipStr =="z-oy") return QApplication::applicationDirPath()+"/diphone/z-oy.wav";
	else if(dipStr =="z-p") return QApplication::applicationDirPath()+"/diphone/z-p.wav";
	else if(dipStr =="z-pau") return QApplication::applicationDirPath()+"/diphone/z-pau.wav";
	else if(dipStr =="z-r") return QApplication::applicationDirPath()+"/diphone/z-r.wav";
	else if(dipStr =="z-s") return QApplication::applicationDirPath()+"/diphone/z-s.wav";
	else if(dipStr =="z-sh") return QApplication::applicationDirPath()+"/diphone/z-sh.wav";
	else if(dipStr =="z-t") return QApplication::applicationDirPath()+"/diphone/z-t.wav";
	else if(dipStr =="z-th") return QApplication::applicationDirPath()+"/diphone/z-th.wav";
	else if(dipStr =="z-uh") return QApplication::applicationDirPath()+"/diphone/z-uh.wav";
	else if(dipStr =="z-uw") return QApplication::applicationDirPath()+"/diphone/z-uw.wav";
	else if(dipStr =="z-v") return QApplication::applicationDirPath()+"/diphone/z-v.wav";
	else if(dipStr =="z-w") return QApplication::applicationDirPath()+"/diphone/z-w.wav";
	else if(dipStr =="z-y") return QApplication::applicationDirPath()+"/diphone/z-y.wav";
	else if(dipStr =="z-z") return QApplication::applicationDirPath()+"/diphone/z-z.wav";
	else if(dipStr =="z-zh") return QApplication::applicationDirPath()+"/diphone/z-zh.wav";   

// zh diphones
	else if(dipStr == "zh-aa") return QApplication::applicationDirPath()+"/diphone/zh-aa.wav";  
	else if(dipStr == "zh-ae") return QApplication::applicationDirPath()+"/diphone/zh-ae.wav";
	else if(dipStr == "zh-ah") return QApplication::applicationDirPath()+"/diphone/zh-ah.wav";
	else if(dipStr == "zh-ao") return QApplication::applicationDirPath()+"/diphone/zh-ao.wav"; 
	else if(dipStr == "zh-aw") return QApplication::applicationDirPath()+"/diphone/zh-aw.wav"; 
	else if(dipStr == "zh-ax") return QApplication::applicationDirPath()+"/diphone/zh-ax.wav"; 
	else if(dipStr == "zh-ay") return QApplication::applicationDirPath()+"/diphone/zh-ay.wav";
	else if(dipStr == "zh-b") return QApplication::applicationDirPath()+"/diphone/zh-b.wav"; 
	else if(dipStr == "zh-ch") return QApplication::applicationDirPath()+"/diphone/zh-ch.wav"; 
	else if(dipStr == "zh-d") return QApplication::applicationDirPath()+"/diphone/zh-d.wav";
	else if(dipStr == "zh-dh") return QApplication::applicationDirPath()+"/diphone/zh-dh.wav";
	else if(dipStr == "zh-eh") return QApplication::applicationDirPath()+"/diphone/zh-eh.wav";
	else if(dipStr == "zh-er") return QApplication::applicationDirPath()+"/diphone/zh-er.wav";
	else if(dipStr == "zh-ey") return QApplication::applicationDirPath()+"/diphone/zh-ey.wav";
	else if(dipStr == "zh-f") return QApplication::applicationDirPath()+"/diphone/zh-f.wav"; 
	else if(dipStr == "zh-g") return QApplication::applicationDirPath()+"/diphone/zh-g.wav";
	else if(dipStr == "zh-hh") return QApplication::applicationDirPath()+"/diphone/zh-hh.wav";
	else if(dipStr == "zh-ih") return QApplication::applicationDirPath()+"/diphone/zh-ih.wav";
	else if(dipStr == "zh-iy") return QApplication::applicationDirPath()+"/diphone/zh-iy.wav";
	else if(dipStr == "zh-jh") return QApplication::applicationDirPath()+"/diphone/zh-jh.wav";
	else if(dipStr == "zh-k") return QApplication::applicationDirPath()+"/diphone/zh-k.wav";
	else if(dipStr == "zh-l") return QApplication::applicationDirPath()+"/diphone/zh-l.wav";
	else if(dipStr == "zh-m") return QApplication::applicationDirPath()+"/diphone/zh-m.wav";
	else if(dipStr == "zh-n") return QApplication::applicationDirPath()+"/diphone/zh-n.wav";
	else if(dipStr == "zh-ow") return QApplication::applicationDirPath()+"/diphone/zh-ow.wav";
	else if(dipStr == "zh-oy") return QApplication::applicationDirPath()+"/diphone/zh-oy.wav";
	else if(dipStr == "zh-p") return QApplication::applicationDirPath()+"/diphone/zh-p.wav";
	else if(dipStr == "zh-pau") return QApplication::applicationDirPath()+"/diphone/zh-pau.wav";
	else if(dipStr == "zh-r") return QApplication::applicationDirPath()+"/diphone/zh-r.wav";
	else if(dipStr == "zh-s") return QApplication::applicationDirPath()+"/diphone/zh-s.wav";
	else if(dipStr == "zh-sh") return QApplication::applicationDirPath()+"/diphone/zh-sh.wav";
	else if(dipStr == "zh-t") return QApplication::applicationDirPath()+"/diphone/zh-t.wav";
	else if(dipStr == "zh-th") return QApplication::applicationDirPath()+"/diphone/zh-th.wav";
	else if(dipStr == "zh-uh") return QApplication::applicationDirPath()+"/diphone/zh-uh.wav";
	else if(dipStr == "zh-uw") return QApplication::applicationDirPath()+"/diphone/zh-uw.wav";
	else if(dipStr == "zh-v") return QApplication::applicationDirPath()+"/diphone/zh-v.wav";
	else if(dipStr == "zh-w") return QApplication::applicationDirPath()+"/diphone/zh-w.wav";
	else if(dipStr == "zh-y") return QApplication::applicationDirPath()+"/diphone/zh-y.wav";
	else if(dipStr == "zh-z") return QApplication::applicationDirPath()+"/diphone/zh-z.wav";
	else if(dipStr == "zh-zh") return QApplication::applicationDirPath()+"/diphone/zh-zh.wav"; 

	else return ""; 
}


void SpeechEngine::setupLookupCardinalNumber()
{
    //how many number
    lookupCardinalNumber.insert(0, "zero ");
    lookupCardinalNumber.insert(1, "one ");
    lookupCardinalNumber.insert(2, "two ");
    lookupCardinalNumber.insert(3, "three ");
    lookupCardinalNumber.insert(4, "four ");
    lookupCardinalNumber.insert(5, "five ");
    lookupCardinalNumber.insert(6, "six ");
    lookupCardinalNumber.insert(7, "seven ");
    lookupCardinalNumber.insert(8, "eight ");
    lookupCardinalNumber.insert(9, "nine ");
    lookupCardinalNumber.insert(10, "ten ");
    lookupCardinalNumber.insert(11, "eleven ");
    lookupCardinalNumber.insert(12, "twelve ");
    lookupCardinalNumber.insert(13, "thirteen ");
    lookupCardinalNumber.insert(14, "fourteen ");
    lookupCardinalNumber.insert(15, "fifteen ");
    lookupCardinalNumber.insert(16, "sixteen ");
    lookupCardinalNumber.insert(17, "seventeen ");
    lookupCardinalNumber.insert(18, "eighteen ");
    lookupCardinalNumber.insert(19, "nineteen ");
    lookupCardinalNumber.insert(20, "twenty ");
    lookupCardinalNumber.insert(21, "twenty one ");   
    lookupCardinalNumber.insert(22, "twenty two ");
    lookupCardinalNumber.insert(23, "twenty three ");
    lookupCardinalNumber.insert(24, "twenty four ");
    lookupCardinalNumber.insert(25, "twenty five");
    lookupCardinalNumber.insert(26, "twenty six ");
    lookupCardinalNumber.insert(27, "twenty seven ");
    lookupCardinalNumber.insert(28, "twenty eight ");
    lookupCardinalNumber.insert(29, "twenty nine ");
    lookupCardinalNumber.insert(30, "thirty ");
    lookupCardinalNumber.insert(31, "thirty one ");
    lookupCardinalNumber.insert(32, "thirty two");
    lookupCardinalNumber.insert(33, "thirty three ");
    lookupCardinalNumber.insert(35, "thirty five ");
    lookupCardinalNumber.insert(36, "thirty six ");
    lookupCardinalNumber.insert(37, "thirty seven ");
    lookupCardinalNumber.insert(38, "thirty eight ");
    lookupCardinalNumber.insert(39, "thirty nine ");
    lookupCardinalNumber.insert(40, "forty ");
    lookupCardinalNumber.insert(41, "forty one ");
    lookupCardinalNumber.insert(42, "forty two ");
    lookupCardinalNumber.insert(43, "forty three ");
    lookupCardinalNumber.insert(44, "forty four ");
    lookupCardinalNumber.insert(45, "forty five ");
    lookupCardinalNumber.insert(46, "forty six ");
    lookupCardinalNumber.insert(47, "forty seven ");
    lookupCardinalNumber.insert(48, "forty eigh t");
    lookupCardinalNumber.insert(49, "forty nine ");
    lookupCardinalNumber.insert(50, "fifty ");
    lookupCardinalNumber.insert(51, "fifty one ");
    lookupCardinalNumber.insert(52, "fifty two ");
    lookupCardinalNumber.insert(53, "fifty three ");
    lookupCardinalNumber.insert(54, "fifty four ");
    lookupCardinalNumber.insert(55, "fifty five ");
    lookupCardinalNumber.insert(56, "fifty six ");
    lookupCardinalNumber.insert(57, "fifty seven ");
    lookupCardinalNumber.insert(58, "fifty eight ");
    lookupCardinalNumber.insert(59, "fifty nine ");

}


void SpeechEngine::setupLookupOrdinalNumber()
{
    //position number
    lookupOrdinalNumber.insert(1, "first ");
    lookupOrdinalNumber.insert(2, "second ");
    lookupOrdinalNumber.insert(3, "third ");
    lookupOrdinalNumber.insert(4, "fourth ");
    lookupOrdinalNumber.insert(5, "fifth ");
    lookupOrdinalNumber.insert(6, "sixth ");
    lookupOrdinalNumber.insert(7, "seventh ");
    lookupOrdinalNumber.insert(8, "eighth ");
    lookupOrdinalNumber.insert(9, "ninth ");
    lookupOrdinalNumber.insert(10, "tenth ");
    lookupOrdinalNumber.insert(11,"eleventh ");
    lookupOrdinalNumber.insert(12, "twelfth ");
    lookupOrdinalNumber.insert(13, "thirteenth ");
    lookupOrdinalNumber.insert(14, "fourteenth ");
    lookupOrdinalNumber.insert(15, "fifteenth ");
    lookupOrdinalNumber.insert(16, "sixteenth ");
    lookupOrdinalNumber.insert(17, "seventeenth ");
    lookupOrdinalNumber.insert(18, "eighteenth ");
    lookupOrdinalNumber.insert(19, "nineteenth ");
    lookupOrdinalNumber.insert(20, "twentieth ");
    lookupOrdinalNumber.insert(21, "twenty first ");
    lookupOrdinalNumber.insert(22, "twenty second ");
    lookupOrdinalNumber.insert(23, "twenty third ");
    lookupOrdinalNumber.insert(24, "twenty fourth ");
    lookupOrdinalNumber.insert(25, "twenty fifth ");
    lookupOrdinalNumber.insert(26, "twenty sixth ");
    lookupOrdinalNumber.insert(27, "twenty seventh ");
    lookupOrdinalNumber.insert(28, "twenty eighth ");
    lookupOrdinalNumber.insert(29, "twenty ninth ");
    lookupOrdinalNumber.insert(30, "thirtieth ");
    lookupOrdinalNumber.insert(31, "thirty first ");    
}

void SpeechEngine::setupLookupDay()
{
    lookupDay.insert(1, "monday");
    lookupDay.insert(2, "tuesday");
    lookupDay.insert(3, "wednesday");
    lookupDay.insert(4, "thursday");
    lookupDay.insert(5, "friday");
    lookupDay.insert(6, "saturday");
    lookupDay.insert(7, "sunday"); 
}

void SpeechEngine::setupLookupMonth()
{
    lookupMonth.insert(1, "january");
    lookupMonth.insert(2, "february");
    lookupMonth.insert(3, "march");
    lookupMonth.insert(4, "april");
    lookupMonth.insert(5, "may");
    lookupMonth.insert(6, "june");
    lookupMonth.insert(7, "july");
    lookupMonth.insert(8, "august");
    lookupMonth.insert(9, "september");
    lookupMonth.insert(10, "october");
    lookupMonth.insert(11, "november");
    lookupMonth.insert(12, "december");

}

//--------------------------------------------------------------------
// Generate talk output
//--------------------------------------------------------------------

void SpeechEngine::generateTalkOut(QDate date, QList<Event> dateEventList, QList<Event> upcomingList, Preferences currentPreferences)
{

//void SpeechEngine::generateTalkOut(QDate date, QList<Event> dateEventList, Preferences currentPreferences) {
		
	//Date
	QString day = lookupDay.value(date.dayOfWeek());	
	QString dayStrOrdinal = lookupOrdinalNumber.value(date.day()); //first	
	QString monthStr=lookupMonth.value(date.month());
	QString talkText;

	talkText.append(day);
	talkText.append(" ");
	talkText.append(dayStrOrdinal);
	talkText.append(" ");
	talkText.append(monthStr);
		
	//------------------------------------------------------------
	// check for holidays
	//------------------------------------------------------------
	
	 if(currentPreferences.m_publicHolidays) {
    //speak holiday names
    if((date.day() ==25) && (date.month()==12)) talkText.append(" Christmas day ");
    if((date.day() ==26) && (date.month()==12)) talkText.append(" Boxing day ");
    if((date.day() ==1) && (date.month()==1)) talkText.append(" New Year ");
    if((date.day() ==14) && (date.month()==2)) talkText.append(" Valentine Day ");
    if((date.day() ==31) && (date.month()==10)) talkText.append(" Halloween" );
    
    QDate easterDate = calculateEaster(date.year());
    
    if(date.day()==easterDate.day() && date.month() ==easterDate.month()){
		talkText.append(" Easter Day ");
	}
	
	if (date == easterDate.addDays(-2)) talkText.append(" Easter Good Friday ");
    if (date == easterDate.addDays(1))  talkText.append(" Easter Monday "); 
    
    //may day
    QDate firstMondayMay(date.year(), 5, 1);
    while (firstMondayMay.dayOfWeek() != Qt::Monday)
    firstMondayMay = firstMondayMay.addDays(1);
    if (date == firstMondayMay) talkText.append(" public holiday ");
    
    //springbank    
    int daysInMay = QDate(date.year(), date.month(), 1).daysInMonth();
    int plusDays = 0;
    if (firstMondayMay.day() + 28 <= daysInMay) {
    plusDays = 28;
    } else {
    plusDays = 21;
    }
    QDate springbank = firstMondayMay.addDays(plusDays); //spring bank
    if (springbank.isValid()) {
    if (date == springbank)
    talkText.append(" public holiday ");
    }
    
    //august holiday
    QDate firstMondayAug(date.year(), 8, 1);
    while (firstMondayAug.dayOfWeek() != Qt::Monday)
    firstMondayAug = firstMondayAug.addDays(1);
    int daysInAugust = QDate(date.year(), 8, 1).daysInMonth();
    int plusAugDays = 0;
    if (firstMondayAug.day() + 28 <= daysInAugust) {
    plusAugDays = 28;
    } else {
    plusAugDays = 21;
    }
    QDate summerBankHol = firstMondayAug.addDays(plusAugDays);
    if (summerBankHol.isValid()) {
    if (date == summerBankHol)
    talkText.append(" public holiday ");
    }
    } //holidays
    
	//--------------------------------------------------------------
	//Number of events
	//---------------------------------------------------------------
	int n= dateEventList.size();
	
	if(n==0){
    talkText.append(" no "); 
    talkText.append(" events");  
	}
    else if(n==1){
	talkText.append(" one "); 	 
    talkText.append(" event ");
	
    }    
    else if(n==2){
	talkText.append(" two "); 
    talkText.append(" events "); 
    }
    else if(n==3){
    talkText.append("three"); 
    talkText.append("events");
    }
	else if(n==4){
    talkText.append(" four "); 
    talkText.append(" events ");
    }
    else if(n==5){
	talkText.append(" five "); 
    talkText.append(" events ");
    }
    else{
	talkText.append(" many "); 
    talkText.append(" events ");	
	}
    
	//--------------------------------------------------------------	
	//cycle through event list
	//--------------------------------------------------------------
	for (int i = 0; i < dateEventList.size(); i++) {
    
    Event event = dateEventList.at(i);    
	
	//------------------------------------------------------------
    // Check for multi day event
    //-------------------------------------------------------------

    QDate eventStartDate = QDate(event.m_startYear, event.m_startMonth, event.m_startDay);
    QDate eventEndDate = QDate(event.m_endYear, event.m_endMonth, event.m_endDay);

	if (eventStartDate != eventEndDate)
    {
     
      talkText.append(" multi ");
      talkText.append(" day ");
      talkText.append(" event ");
      talkText.append(" ");
    }

	
	//-------------------------------------------------------------
	//Speak time
	//-------------------------------------------------------------
	if (eventStartDate == eventEndDate)
	{
	int sHour = event.m_startHour;
	int sMin =event.m_startMin;
	QString startHourStr="";
	QString startMinStr="";		
	
	if(currentPreferences.m_12HourFormat) {
	
	if(sHour==12) {
	sHour=12;
	startHourStr.append(lookupCardinalNumber.value(sHour));
	if(sMin==0) {
	startMinStr.append("pmm");
	startMinStr.append(" ");
	}
	if(sMin >0 && sMin<=9){
	startMinStr.append(" zero ");
	startMinStr.append(lookupCardinalNumber.value(sMin));
	startMinStr.append("pmm");
	startMinStr.append(" ");
	} else if (sMin>9 && sMin<59) {
	startMinStr.append(lookupCardinalNumber.value(sMin));
	startMinStr.append("pmm");
	startMinStr.append(" ");
	}
	
	} //if sHour==12
	
	else if(sHour>12) { //pm
	sHour=sHour-12;
	startHourStr.append(lookupCardinalNumber.value(sHour));
	
	if(sMin==0) {
	startMinStr.append("pmm");
	startMinStr.append(" ");
	}
	if(sMin >0 && sMin<=9){
	startMinStr.append(" zero ");
	startMinStr.append(lookupCardinalNumber.value(sMin));
	startMinStr.append("pmm");
	startMinStr.append(" ");
	} else if (sMin>9 && sMin<59) {
	startMinStr.append(lookupCardinalNumber.value(sMin));
	startMinStr.append("pmm");
	startMinStr.append(" ");
	}
	} //if sHour>12
	
	else { //am
	startHourStr.append(lookupCardinalNumber.value(sHour));
	
	if(sMin==0) {
	startMinStr.append("amm");
	startMinStr.append(" ");
	}
	if(sMin >0 && sMin<=9){
	startMinStr.append(" zero ");
	startMinStr.append(lookupCardinalNumber.value(sMin));
	startMinStr.append("amm");
	startMinStr.append(" ");
	} else  if  (sMin>9 && sMin<=59){
	startMinStr.append(lookupCardinalNumber.value(sMin));
	startMinStr.append("amm");
	startMinStr.append(" ");
	}
	}
	} //if 12hour format    
	
	
	else { //24hour format
	
	startHourStr.append(lookupCardinalNumber.value(sHour));
	if(sMin <=9){
	startMinStr.append(" zero ");
	startMinStr.append(lookupCardinalNumber.value(sMin));
	} else {
	startMinStr.append(lookupCardinalNumber.value(sMin));
	}
	startMinStr.append(" ");
	}
	
	if(event.m_isAllDay) {
	talkText.append(" all ");
	talkText.append(" day ");
	talkText.append(" event ");	
	
	} else {
	
	talkText.append(" ");
	talkText.append(startHourStr);
	talkText.append(" ");
	talkText.append(startMinStr);			
	}
	
	} //time
	//---------------------------------------------------------------
	// speak title
	//---------------------------------------------------------------
	
	QString st=event.m_summary;
	QString tStr =st.toLower();
	
	//remove unwanted characters in case added
	tStr.replace(';', " ");
	tStr.replace('.', " ");
	tStr.replace(',', " ");
	//tStr.replace('\'', " ");
	tStr.replace('\"', " ");
	tStr.replace(QRegularExpression("[\\n|\\r|\\t]+"), " ");
	
	talkText.append(" "); //word spacing
	talkText.append("pau");
	talkText.append(" ");
	talkText.append(tStr);
	
	//location

	 if (currentPreferences.m_talkLocation) {
		 
    QString loc=event.m_location;
	QString locStr =loc.toLower();
	
	//remove unwanted characters in case added
	locStr.replace(';', " ");
	locStr.replace('.', " ");
	locStr.replace(',', " ");
	//tStr.replace('\'', " ");
	locStr.replace('\"', " ");
	locStr.replace(QRegularExpression("[\\n|\\r|\\t]+"), " ");
	
	talkText.append(" "); //word spacing
	talkText.append("pau");
	talkText.append(" ");
	talkText.append(locStr);
		 
		 
	 }


	//--------------------------------------------------------------
	// speak priority
	//---------------------------------------------------------------

	if(event.m_isPriority>=1){
	talkText.append(" high ");
	talkText.append(" priority ");
	talkText.append(" event ");
	}
			
    }//end cycle through dateEventList

	//---------------------------------------------------------------
	//check for overlap
	//----------------------------------------------------------------
	bool overlap = CheckForDayEventOverlap(dateEventList);
  
    if (overlap) {
	    talkText.append(" you ");
	    talkText.append(" have ");
	    talkText.append(" overlapping ");
	    talkText.append(" events ");
    }
    
    //Check for upcoming events
    
    if (currentPreferences.m_talkUpcoming && date == QDate::currentDate())
	{
	
    int num = upcomingList.size();
    
    
    talkText.append("  ");
    talkText.append("pau");
    talkText.append(" You ");
    talkText.append(" have ");
    
    if(num==0){
    talkText.append(" no "); 
    talkText.append(" upcoming ");
    talkText.append(" events");  
	}
    else if(num==1){
	talkText.append(" one ");
	talkText.append(" upcoming ");	 
    talkText.append(" event ");	
    }    
    else if(num==2){
	talkText.append(" two ");
	talkText.append(" upcoming "); 
    talkText.append(" events "); 
    }
    else if(num==3){
    talkText.append("three");
    talkText.append(" upcoming "); 
    talkText.append("events");
    }
	else if(num==4){
    talkText.append(" four ");
    talkText.append(" upcoming "); 
    talkText.append(" events ");
    }
    else if(num==5){
	talkText.append(" five ");
	talkText.append(" upcoming "); 
    talkText.append(" events ");
    }
    else{
	talkText.append(" many "); 
	talkText.append(" upcoming ");
    talkText.append(" events ");	
	}
	
    for (int i = 0; i < upcomingList.size(); i++)
    {
	 talkText.append(" "); //word spacing
	 talkText.append("pau");
    
    Event e = upcomingList.at(i);
    QDate eventStartDate = QDate(e.m_startYear, e.m_startMonth, e.m_startDay);
    
    QString day = lookupDay.value(eventStartDate.dayOfWeek());
    QString dayStrOrdinal = lookupOrdinalNumber.value(eventStartDate.day()); // first
    QString monthStr = lookupMonth.value(eventStartDate.month());
   
    
    talkText.append(" ");
    talkText.append(day.toLower());
    talkText.append(" ");
    talkText.append(dayStrOrdinal);
    talkText.append(" ");
    talkText.append(monthStr);
    talkText.append(" ");
    
    QString ust=e.m_summary;
	QString utStr =ust.toLower();
	
	//remove unwanted characters in case added
	utStr.replace(';', " ");
	utStr.replace('.', " ");
	utStr.replace(',', " ");
	//tStr.replace('\'', " ");
	utStr.replace('\"', " ");
	utStr.replace(QRegularExpression("[\\n|\\r|\\t]+"), " ");
	
	talkText.append(" "); //word spacing
	talkText.append("pau");
	talkText.append(" ");
	talkText.append(utStr);
    }
	}//upcoming
	
	talkText.append(" "); //word spacing
	talkText.append("pau");
	//--------------------------------------------------------------
	//create talkout.wav using wavcat
	//---------------------------------------------------------------
	
	QString textStr =talkText.toLower();
		
	//QStringList wordList = textStr.split(QRegExp("\\s+"), Qt::SkipEmptyParts);
	QStringList wordList = textStr.split(QRegularExpression("\\s+"), QStringParser::SkipEmptyParts);
	QString dipStrAll;
     
    for (int i = 0; i < wordList.count(); i++){
		 
	   //qDebug() <<" word: " << wordList[i];
      //iterate through each word at a time
      QString word =wordList[i];
      //key-value
      QString dipStr =dict->wordToDiphones(word);

	  //fix: ignore empty dipStrs
	  //qDebug()<<"adding word = "<<word<<" "<< "diphone str = "<<dipStr<<"\n";
      if(!dipStr.isEmpty()) dipStrAll.append(dipStr+" ");
		 
	 }


	//Must initialise wavout using wavEmpty
	WavCat wavEmpty(1,32000,16);
     //WavCat wavEmpty(1,16000,16);
     wavEmpty.save( "/tmp/empty.wav" );
     WavCat wavout("/tmp/empty.wav"); //Assign empty wav to concatenation output

	//QStringList dipList = dipStrAll.split(QRegExp("\\s+"),Qt::SkipEmptyParts);
	QStringList dipList = dipStrAll.split(QRegularExpression("\\s+"), QStringParser::SkipEmptyParts);

	QList<QString> diphoneList;

	for (int i = 0; i < dipList.count(); i++){
      QString dp_str = dipList.at(i);
	  QString path =getDiphonePath(dp_str);
	  WavCat tmp(path.toStdString());
	  wavout=wavout+tmp;
	}
	wavout.save("/tmp/talkout.wav"); 	
}

bool SpeechEngine::CheckForDayEventOverlap(QList<Event> eventListDay){
	
	bool result = false;
  //get all day events 

  if (eventListDay.size() > 1) {

    for (int i = 1; i < eventListDay.size(); i++) {
      Event a = eventListDay.at(i - 1);
      Event b = eventListDay.at(i);
      QTime aStartTime = QTime(a.m_startHour, a.m_startMin);
      QTime aEndTime = QTime(a.m_endHour, a.m_endMin);
      QTime bStartTime = QTime(b.m_startHour, b.m_startMin);
      QTime bEndTime = QTime(b.m_endHour, b.m_endMin);

      if ((aStartTime < bEndTime) && (bStartTime < aEndTime)) {
        result = true;
      }
    }
  }

  return result;
}

void SpeechEngine::generateUpcomingEventsTalk(QList<Event> upcomingList)
{
	//if (!currentPreferences.m_talkUpcoming) return;
	
	QString talkText;
	int num = upcomingList.size();
	//qDebug() << "number of upcoming events = " << num << "\n";
	
	talkText.append("  ");
	talkText.append("pau");
	talkText.append(" You ");
	talkText.append(" have ");
	
	if(num==0){
	talkText.append(" no "); 
	talkText.append(" upcoming ");
	talkText.append(" events");  
	}
	else if(num==1){
	talkText.append(" one ");
	talkText.append(" upcoming ");	 
	talkText.append(" event ");	
	}    
	else if(num==2){
	talkText.append(" two ");
	talkText.append(" upcoming "); 
	talkText.append(" events "); 
	}
	else if(num==3){
	talkText.append("three");
	talkText.append(" upcoming "); 
	talkText.append("events");
	}
	else if(num==4){
	talkText.append(" four ");
	talkText.append(" upcoming "); 
	talkText.append(" events ");
	}
	else if(num==5){
	talkText.append(" five ");
	talkText.append(" upcoming "); 
	talkText.append(" events ");
	}
	else{
	talkText.append(" many "); 
	talkText.append(" upcoming ");
	talkText.append(" events ");	
	}
	
	for (int i = 0; i < upcomingList.size(); i++)
	{
	talkText.append(" "); //word spacing
	talkText.append("pau");
	
	Event e = upcomingList.at(i);
	QDate eventStartDate = QDate(e.m_startYear, e.m_startMonth, e.m_startDay);
	
	QString day = lookupDay.value(eventStartDate.dayOfWeek());
	QString dayStrOrdinal = lookupOrdinalNumber.value(eventStartDate.day()); // first
	QString monthStr = lookupMonth.value(eventStartDate.month());
	// qDebug()<<day<<" "<<dayStrOrdinal<<" "<<monthStr;
	
	talkText.append(" ");
	talkText.append(day.toLower());
	talkText.append(" ");
	talkText.append(dayStrOrdinal);
	talkText.append(" ");
	talkText.append(monthStr);
	talkText.append(" ");
	
	QString ust=e.m_summary;
	QString utStr =ust.toLower();
	
	//remove unwanted characters in case added
	utStr.replace(';', " ");
	utStr.replace('.', " ");
	utStr.replace(',', " ");
	//tStr.replace('\'', " ");
	utStr.replace('\"', " ");
	utStr.replace(QRegularExpression("[\\n|\\r|\\t]+"), " ");
	
	talkText.append(" "); //word spacing
	talkText.append("pau");
	talkText.append(" ");
	talkText.append(utStr);
	}
	talkText.append(" "); //word spacing
	talkText.append("pau");
	talkText.append("  ");
	talkText.append("pau");	
	speak(talkText);
}
//----------------------------------------------------------------------
void SpeechEngine::speak(QString text) {
	
	//qDebug()<<"SpeechEngine::speak() text = "<<text<<"\n";
	
	QString textStr =text.toLower();
	
	QStringList titleWordList = textStr.split(QRegularExpression("\\s+"), QStringParser::SkipEmptyParts);
	
	QString dipStrAll;
     
    for (int i = 0; i < titleWordList.count(); i++){
		 
	   //qDebug() <<"title word: " << titleWordList[i];
      //iterate through each word at a time
      QString word =titleWordList[i];      
      QString dipStr =dict->wordToDiphones(word);
      dipStrAll.append(dipStr+" ");		 
	 }
		
	//Must initialise wavcat using wavEmpty
     WavCat wavEmpty(1,8000,16);    
     wavEmpty.save( "/tmp/empty.wav" );    
     WavCat wavout("/tmp/empty.wav"); //Assign empty wav to concatenation output
	
	QStringList dipList = dipStrAll.split(QRegularExpression("\\s+"), QStringParser::SkipEmptyParts);
	
	QList<QString> diphoneList;
	
	for (int i = 0; i < dipList.count(); i++){
		
	  
      QString dp_str = dipList.at(i);     
	  
	  QString path =getDiphonePath(dp_str);
	 
	  WavCat tmp(path.toStdString());
	  wavout=wavout+tmp;  
      
	}	
	wavout.save("/tmp/talkout.wav");   	
}

