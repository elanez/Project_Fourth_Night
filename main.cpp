#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include <time.h>

void circ(int *xcirc, int *ycirc, int maxx);
void circ2(int *xcirc, int *ycirc, int maxx);
void pause(int *life, int* again);
void intro(int *chkintro);
void done1p(float d, float *highest, int *again, int *life);
void done2p(int win,int* life, int *again);

struct ufo
{
    int xellipse1, yellipse1, xarc1, yarc1;
    int xellipse2, yellipse2, xarc2, yarc2;
    int xellipser, yellipser, xarc3, yarc3;
}ufo1, ufo2;

int main()
{
    int gd = DETECT, gm, maxx, maxy, page=0, life=0, diff, sens=6, win, instruct, again=0;
    int xcirc[20], ycirc[20], xcirc2[20], ycirc2[20], i, x, y, color=0, chkintro=0;
    float d, z, highest, speed, moon;
    char dist[10], hscore[20];
    POINT cursor;
    FILE *pf;
    srand(time(0));

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    maxx = getmaxx();
    maxy = getmaxy();

    ///get highest score from notepad
    pf = fopen("savedata.txt","r");
    fscanf(pf,"%f",&highest);
    fclose(pf);

    ///Menu
    for(;;)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        instruct=1;

        if(chkintro==0)
            intro(&chkintro);

        for(i=0;i<12;i++)
        {
            setcolor(RED);
            arc(335-i,220,340,200,180+i);///REDMOON
        }

        setcolor(LIGHTBLUE);
        line(565,315,535,285);///right 3d
        line(140,315,110,285);///left3d
        line(110,285,535,285);///bar top 3d
        line(110,285,110,370);///depth left 3d
        line(140,400,110,370);
        rectangle(140,315,565,400);///SIGN TITLE
        for(i=0;i<420;i+=10)///line on top bar depth
        {
            line(150+i,315,120+i,285);
        }
        for(i=0;i<80;i+=10)///line on left top depth
        {
            line(140,325+i,110,295+i);
        }
        for(i=0;i<=7;i++)///pangpakapal nung drawing ng ellipse
        {
            setcolor(LIGHTGRAY);
            ellipse(345, 250-i, 0, 360, 90+i,30-i);
        }
        circle(285,250,4);
        circle(405,250,4);
        for(i=0;i<=50;i++)
        {
            setcolor(LIGHTGREEN);
            arc(345,234,340,200,45-i);
        }
        for(i=0;i<12;i++)
        {
            line(306,249-i,386,249-i);
        }
        setcolor(WHITE);
        settextstyle(2,HORIZ_DIR,16);///2
        outtextxy(215,335,"FOURTH");
        outtextxy(375,335,"NIGHT");

        GetCursorPos(&cursor);
        x = cursor.x;
        y = cursor.y;

        settextstyle(2,HORIZ_DIR,8);

        if(x>100 && x<233 && y>445 && y<465)
        {
            setcolor(YELLOW);
            outtextxy(100,420,"1 PLAYER");
            setcolor(WHITE);
            outtextxy(500,420,"EXIT");
            outtextxy(285,420,"2 PLAYERS");
            if(GetAsyncKeyState(VK_LBUTTON))
                life = 1;

            ///game1p
            while(life>0)
            {
                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();

                if(again==0)
                {
                    ///ufo cordinates
                    ufo1.xellipse1=106;
                    ufo1.xellipse2=110;
                    ufo1.xellipser=50; ///x ellipse radius
                    ufo1.yellipse1=216;
                    ufo1.yellipse2=215;
                    ufo1.yellipser=10; ///y ellipse radius
                    ufo1.xarc1=85;
                    ufo1.xarc2=110;
                    ufo1.xarc3=135;
                    ufo1.yarc1=228;
                    ufo1.yarc2=231;
                    ufo1.yarc3=228;

                    ///ufo2 for pause bg
                    ufo2.xellipse1=506;
                    ufo2.xellipse2=510;
                    ufo2.xellipser=50; ///x ellipse radius
                    ufo2.yellipse1=216;
                    ufo2.yellipse2=215;
                    ufo2.yellipser=10; ///y ellipse radius
                    ufo2.xarc1=485;
                    ufo2.xarc2=510;
                    ufo2.xarc3=535;
                    ufo2.yarc1=228;
                    ufo2.yarc2=231;
                    ufo2.yarc3=228;

                    ///circle ufo1
                    for(i=0;i<10;i++)
                        circ(&xcirc[i], &ycirc[i],maxx);

                    diff=4;
                    d=0;
                    speed=4;
                    z=1;
                    moon=0.5;
                    again=1;
                }

                while(instruct==1)
                {
                    settextstyle(8,HORIZ_DIR,3);
                    setactivepage(page);
                    setvisualpage(1-page);
                    cleardevice();
                    outtextxy(50,100,"Press arrow keys to avoid incoming ");
                    outtextxy(50,140,"bullets. Conquer the galaxies, travel");
                    outtextxy(50,180,"as far as you can. May the force be ");
                    outtextxy(50,220,"with you.");
                    outtextxy(250,260,"Press TAB to continue");
                    setcolor(color);
                    rectangle(100,300,150,350);
                    rectangle(100,370,150,420);
                    rectangle(30,370,80,420);
                    rectangle(170,370,220,420);
                    color++;
                    setcolor(WHITE);
                    line(110,330,140,330);
                    line(110,330,125,310);
                    line(140,330,125,310);
                    line(110,390,140,390);
                    line(110,390,125,410);
                    line(140,390,125,410);
                    line(60,380,60,410);
                    line(60,380,40,395);
                    line(60,410,40,395);
                    line(185,380,185,410);
                    line(185,380,210,395);
                    line(185,410,210,395);
                    if(GetAsyncKeyState(VK_TAB))
                    {
                        instruct=0;
                    }
                    page=1-page;
                    delay(5);
                }

                ///distance counter
                setcolor(DARKGRAY);
                settextstyle(4, HORIZ_DIR, 1);
                sprintf(dist, "%.2fkm", d);
                outtextxy(0,0,dist);
                sprintf(hscore, "Score to beat: %.2fkm",highest);
                outtextxy(150,0,hscore);

                ///bg moon
                setcolor(LIGHTGRAY);
                circle(550-moon,150,100);
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                floodfill(550-moon, 150, LIGHTGRAY);
                setcolor(BLACK);
                circle(520-moon,150,80);
                setfillstyle(SOLID_FILL, BLACK);
                floodfill(550-moon,150, BLACK);
                moon+=0.02;

                ///ufo
                for(i=0;i<=7;i++)
                {

                    setcolor(DARKGRAY);
                    ellipse(ufo1.xellipse1,ufo1.yellipse1,0,360,ufo1.xellipser,ufo1.yellipser);
                    setfillstyle(SOLID_FILL,LIGHTGRAY);
                    floodfill(ufo1.xellipse1+5, ufo1.yellipse1+5, DARKGRAY);
                    setcolor(color);
                    arc(ufo1.xarc1,ufo1.yarc1-i,180,0,5-i);
                    setcolor(color+2);
                    arc(ufo1.xarc2,ufo1.yarc2-i,180,0,5-i);
                    setcolor(color);
                    arc(ufo1.xarc3,ufo1.yarc3-i,180,0,5-i);
                    color++;

                }
                setfillstyle(WIDE_DOT_FILL, DARKGRAY);
                ellipse(ufo1.xellipse1,ufo1.yellipse1,0,360,ufo1.xellipser,1);
                setcolor(DARKGRAY);
                ellipse(ufo1.xellipse2-i,ufo1.yellipse2-i,0,180,20,18);
                color++;

                ///circle
                for(i=0;i<diff;i++)
                {
                    setcolor(LIGHTGREEN);
                    circle(xcirc[i], ycirc[i], 10);
                    setfillstyle(SOLID_FILL, LIGHTGREEN);
                    floodfill(xcirc[i]+5, ycirc[i]+5, LIGHTGREEN);
                }

                ///controls
                if(GetAsyncKeyState(VK_UP))
                {
                    if(ufo1.yellipse2-29 > 0)
                    {
                        ufo1.yellipse1-=sens;
                        ufo1.yellipse2-=sens;
                        ufo1.yarc1-=sens;
                        ufo1.yarc2-=sens;
                        ufo1.yarc3-=sens;
                    }
                }
                else if(GetAsyncKeyState(VK_DOWN))
                {
                    if(ufo1.yarc2<470)
                    {
                        ufo1.yellipse1+=sens;
                        ufo1.yellipse2+=sens;
                        ufo1.yarc1+=sens;
                        ufo1.yarc2+=sens;
                        ufo1.yarc3+=sens;
                    }

                }
                else if(GetAsyncKeyState(VK_LEFT))
                {
                    if(ufo1.xellipse1-50>0)
                    {
                        ufo1.xellipse1-=sens;
                        ufo1.xellipse2-=sens;
                        ufo1.xarc1-=sens;
                        ufo1.xarc2-=sens;
                        ufo1.xarc3-=sens;
                    }

                }
                else if(GetAsyncKeyState(VK_RIGHT))
                {
                    if(ufo1.xellipse2<580)
                    {
                        ufo1.xellipse1+=sens;
                        ufo1.xellipse2+=sens;
                        ufo1.xarc1+=sens;
                        ufo1.xarc2+=sens;
                        ufo1.xarc3+=sens;
                    }
                }
                else if(GetAsyncKeyState(VK_ESCAPE))
                {
                    pause(&life, &again);
                }

                ///circle movement
                for(i=0;i<diff;i++)
                    xcirc[i]-=speed;

                ///reload circle
                for(i=0;i<diff;i++)
                {
                    if(xcirc[i]<-100)
                        circ(&xcirc[i], &ycirc[i], maxx);
                }

                ///collision
                for(i=0;i<diff;i++)
                {
                    if((xcirc[i]>=(ufo1.xellipse1-ufo1.xellipser) && xcirc[i]<=(ufo1.xellipse1+ufo1.xellipser)&&
                       ycirc[i]>=(ufo1.yellipse1-ufo1.yellipser) && ycirc[i]<=(ufo1.yellipse1+ufo1.yellipser))||(
                       xcirc[i]>=(ufo1.xellipse2-20) && xcirc[i]<=(ufo1.xellipse2+15) && ycirc[i]>=(ufo1.yellipse2-28)
                       && ycirc[i]<=(ufo1.yellipse2+26)))
                    {
                        delay(1000);
                        done1p(d, &highest, &again, &life);
                    }
                }

                d+=0.001;
                if(d>=z)
                {
                    if(diff<10)
                        diff+=1;
                        speed+=.25;
                        z++;
                }

                page = 1-page;
                delay(5);
            }
        ///save highscore to notepad
        fopen("savedata.txt","w");
        fprintf(pf,"%f",highest);
        fclose(pf);
        }
        else if(x>500 && x<565 && y>450 && y<465)
        {
            setcolor(WHITE);
            outtextxy(100,420,"1 PLAYER");
            outtextxy(285,420,"2 PLAYERS");
            setcolor(YELLOW);
            outtextxy(500,420,"EXIT");
            if(GetAsyncKeyState(VK_LBUTTON))
                return 0;
        }
        else if(x>285 && x<443 && y>450 && y<465)
        {
            setcolor(WHITE);
            outtextxy(100,420,"1 PLAYER");
            outtextxy(500,420,"EXIT");
            setcolor(YELLOW);
            outtextxy(285,420,"2 PLAYERS");
            if(GetAsyncKeyState(VK_LBUTTON))
                life=1;
            while(life>0)
            {
                setactivepage(page);
                setvisualpage(1-page);
                cleardevice();

                    if(again==0)
                {
                    ///ufo cordinates
                    ufo1.xellipse1=106;
                    ufo1.xellipse2=110;
                    ufo1.xellipser=50; ///x ellipse radius
                    ufo1.yellipse1=216;
                    ufo1.yellipse2=215;
                    ufo1.yellipser=10; ///y ellipse radius
                    ufo1.xarc1=85;
                    ufo1.xarc2=110;
                    ufo1.xarc3=135;
                    ufo1.yarc1=228;
                    ufo1.yarc2=231;
                    ufo1.yarc3=228;

                    ///ufo2
                    ufo2.xellipse1=506;
                    ufo2.xellipse2=510;
                    ufo2.xellipser=50; ///x ellipse radius
                    ufo2.yellipse1=216;
                    ufo2.yellipse2=215;
                    ufo2.yellipser=10; ///y ellipse radius
                    ufo2.xarc1=485;
                    ufo2.xarc2=510;
                    ufo2.xarc3=535;
                    ufo2.yarc1=228;
                    ufo2.yarc2=231;
                    ufo2.yarc3=228;

                    ///circle ufo1
                    for(i=0;i<10;i++)
                        circ(&xcirc[i], &ycirc[i],maxx);
                    ///circle ufo2
                    for(i=0;i<10;i++)
                        circ2(&xcirc2[i], &ycirc2[i],maxx);

                    diff=4;
                    d=0;
                    speed=4;
                    z=1;
                    again=1;
                }

                while(instruct==1)
                {
                    settextstyle(8,HORIZ_DIR,3);
                    setactivepage(page);
                    setvisualpage(1-page);
                    cleardevice();
                    outtextxy(30,100,"Player 1 (BLUE) : Use w,a,s,d to move ");
                    outtextxy(30,140,"Player 2 (PINK) :Use arrow keys to move ");
                    outtextxy(30,180,"Avoid getting hit by the opposite color");
                    outtextxy(250,260,"Press TAB to continue");
                    setcolor(color);
                    rectangle(100,300,150,350);
                    rectangle(100,370,150,420);
                    rectangle(30,370,80,420);
                    rectangle(170,370,220,420);
                    color++;
                    setcolor(WHITE);
                    line(110,330,140,330);
                    line(110,330,125,310);
                    line(140,330,125,310);
                    line(110,390,140,390);
                    line(110,390,125,410);
                    line(140,390,125,410);
                    line(60,380,60,410);
                    line(60,380,40,395);
                    line(60,410,40,395);
                    line(185,380,185,410);
                    line(185,380,210,395);
                    line(185,410,210,395);
                    setcolor(color);
                    rectangle(370,300,420,350);
                    rectangle(370,370,420,420);
                    rectangle(300,370,350,420);
                    rectangle(440,370,490,420);
                    color++;
                    setcolor(WHITE);
                    outtextxy(388,310, "W");
                    outtextxy(388,380, "S");
                    outtextxy(318,380, "A");
                    outtextxy(458,380, "D");
                    if(GetAsyncKeyState(VK_TAB))
                    {
                        instruct=0;
                    }
                    page=1-page;
                    delay(5);
                }

                ///ufo
                for(i=0;i<=7;i++)
                {

                    setcolor(LIGHTBLUE);
                    ellipse(ufo1.xellipse1,ufo1.yellipse1,0,360,ufo1.xellipser,ufo1.yellipser);
                    setfillstyle(SOLID_FILL,LIGHTBLUE);
                    floodfill(ufo1.xellipse1+5, ufo1.yellipse1+5, LIGHTBLUE);
                    setcolor(color);
                    arc(ufo1.xarc1,ufo1.yarc1-i,180,0,5-i);
                    setcolor(color+2);
                    arc(ufo1.xarc2,ufo1.yarc2-i,180,0,5-i);
                    setcolor(color);
                    arc(ufo1.xarc3,ufo1.yarc3-i,180,0,5-i);
                    color++;

                }
                setfillstyle(WIDE_DOT_FILL, LIGHTBLUE);
                ellipse(ufo1.xellipse1,ufo1.yellipse1,0,360,ufo1.xellipser,1);
                setcolor(LIGHTBLUE);
                ellipse(ufo1.xellipse2-i,ufo1.yellipse2-i,0,180,20,18);
                color++;

                ///UFO 2
                for(i=0;i<=7;i++)
                {

                    setcolor(LIGHTMAGENTA);
                    ellipse(ufo2.xellipse1,ufo2.yellipse1,0,360,ufo2.xellipser,ufo2.yellipser);
                    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                    floodfill(ufo2.xellipse1+5, ufo2.yellipse1+5, LIGHTMAGENTA);
                    setcolor(color);
                    arc(ufo2.xarc1,ufo2.yarc1-i,180,0,5-i);
                    setcolor(color+2);
                    arc(ufo2.xarc2,ufo2.yarc2-i,180,0,5-i);
                    setcolor(color);
                    arc(ufo2.xarc3,ufo2.yarc3-i,180,0,5-i);
                    color++;
                }
                setfillstyle(WIDE_DOT_FILL, LIGHTMAGENTA);
                ellipse(ufo2.xellipse1,ufo2.yellipse1,0,360,ufo2.xellipser,1);
                setcolor(LIGHTMAGENTA);
                ellipse(ufo2.xellipse2-i,ufo2.yellipse2-i,0,180,20,18);
                color++;

                ///circle ///ufo1
                for(i=0;i<diff;i++)
                {
                    setcolor(LIGHTMAGENTA);
                    circle(xcirc[i], ycirc[i], 10);
                    setfillstyle(SOLID_FILL, LIGHTMAGENTA);
                    floodfill(xcirc[i]+5, ycirc[i]+5, LIGHTMAGENTA);
                }

                ///circle ///ufo2
                for(i=0;i<diff;i++)
                {
                    setcolor(LIGHTBLUE);
                    circle(xcirc2[i], ycirc2[i], 10);
                    setfillstyle(SOLID_FILL, LIGHTBLUE);
                    floodfill(xcirc2[i]+5, ycirc2[i]+5, LIGHTBLUE);
                }

                ///controls ufo2
                if(GetAsyncKeyState(VK_UP))
                {
                    if(ufo2.yellipse2-29 > 0)
                    {
                        ufo2.yellipse1-=sens;
                        ufo2.yellipse2-=sens;
                        ufo2.yarc1-=sens;
                        ufo2.yarc2-=sens;
                        ufo2.yarc3-=sens;
                    }
                }
                else if(GetAsyncKeyState(VK_DOWN))
                {
                    if(ufo2.yarc2<470)
                    {
                        ufo2.yellipse1+=sens;
                        ufo2.yellipse2+=sens;
                        ufo2.yarc1+=sens;
                        ufo2.yarc2+=sens;
                        ufo2.yarc3+=sens;
                    }

                }
                else if(GetAsyncKeyState(VK_LEFT))
                {
                    if(ufo2.xellipse1-50>0)
                    {
                        ufo2.xellipse1-=sens;
                        ufo2.xellipse2-=sens;
                        ufo2.xarc1-=sens;
                        ufo2.xarc2-=sens;
                        ufo2.xarc3-=sens;
                    }

                }
                else if(GetAsyncKeyState(VK_RIGHT))
                {
                    if(ufo2.xellipse2<580)
                        {
                            ufo2.xellipse1+=sens;
                            ufo2.xellipse2+=sens;
                            ufo2.xarc1+=sens;
                            ufo2.xarc2+=sens;
                            ufo2.xarc3+=sens;
                        }
                }
                else if(GetAsyncKeyState(VK_ESCAPE))
                {
                    pause(&life, &again);
                }

                ///controls ufo1
                if(GetAsyncKeyState(0x57))///w
                {
                    if(ufo1.yellipse2-29>0)
                    {
                        ufo1.yellipse1-=sens;
                        ufo1.yellipse2-=sens;
                        ufo1.yarc1-=sens;
                        ufo1.yarc2-=sens;
                        ufo1.yarc3-=sens;
                    }
                }
                else if(GetAsyncKeyState(0x53))///s
                {
                    if(ufo1.yarc2<470)
                    {
                        ufo1.yellipse1+=sens;
                        ufo1.yellipse2+=sens;
                        ufo1.yarc1+=sens;
                        ufo1.yarc2+=sens;
                        ufo1.yarc3+=sens;
                    }

                }
                else if(GetAsyncKeyState(0x41))///a
                {
                    if(ufo1.xellipse1-50>0)
                    {
                        ufo1.xellipse1-=sens;
                        ufo1.xellipse2-=sens;
                        ufo1.xarc1-=sens;
                        ufo1.xarc2-=sens;
                        ufo1.xarc3-=sens;
                    }

                }
                else if(GetAsyncKeyState(0x44))///d
                {
                    if(ufo1.xellipse2<580)
                        {
                            ufo1.xellipse1+=sens;
                            ufo1.xellipse2+=sens;
                            ufo1.xarc1+=sens;
                            ufo1.xarc2+=sens;
                            ufo1.xarc3+=sens;
                        }
                }

                ///circle movement
                for(i=0;i<diff;i++)
                    xcirc[i]-=speed;
                ///circle2 movement
                for(i=0;i<diff;i++)
                    xcirc2[i]+=speed;

                ///reload circle
                for(i=0;i<diff;i++)
                {
                    if(xcirc[i]<-100)
                        circ(&xcirc[i], &ycirc[i], maxx);
                }
                ///reload circle2
                for(i=0;i<diff;i++)
                {
                    if(xcirc2[i]>maxx)
                        circ2(&xcirc2[i], &ycirc2[i], maxx);
                }

                ///collision
                for(i=0;i<diff;i++)
                {
                    if((xcirc[i]>=(ufo1.xellipse1-ufo1.xellipser) && xcirc[i]<=(ufo1.xellipse1+ufo1.xellipser)&&
                       ycirc[i]>=(ufo1.yellipse1-ufo1.yellipser) && ycirc[i]<=(ufo1.yellipse1+ufo1.yellipser))||(
                       xcirc[i]>=(ufo1.xellipse2-20) && xcirc[i]<=(ufo1.xellipse2+15) && ycirc[i]>=(ufo1.yellipse2-28)
                       && ycirc[i]<=(ufo1.yellipse2+26)))
                    {
                        delay(1000);
                        win=2;
                        done2p(win,&life,&again);
                    }
                    if((xcirc2[i]>=(ufo2.xellipse1-ufo2.xellipser) && xcirc2[i]<=(ufo2.xellipse1+ufo2.xellipser)&&
                       ycirc2[i]>=(ufo2.yellipse1-ufo2.yellipser) && ycirc2[i]<=(ufo2.yellipse1+ufo2.yellipser))||(
                       xcirc2[i]>=(ufo2.xellipse2-20) && xcirc2[i]<=(ufo2.xellipse2+15) && ycirc2[i]>=(ufo2.yellipse2-28)
                       && ycirc2[i]<=(ufo2.yellipse2+26)))
                    {
                        delay(1000);
                        win=1;
                        done2p(win,&life,&again);
                    }
                }

                d+=0.001;
                if(d>=z)
                    {
                        if(diff<10)
                            diff+=1;
                        speed+=.25;
                        z++;
                    }

                page = 1-page;
                delay(5);
                }
            }
        else
        {
            setcolor(WHITE);
            outtextxy(100,420,"1 PLAYER");
            outtextxy(285,420,"2 PLAYERS");
            outtextxy(500,420,"EXIT");
        }

            page = 1-page;
            delay(5);
        }
}

void circ(int *xcirc, int *ycirc,int maxx)
{
    *xcirc = rand()%500+maxx;
    *ycirc = rand()%470+1;
}

void circ2(int *xcirc, int *ycirc,int maxx)
{
    *xcirc = rand()%500-maxx;
    *ycirc = rand()%470+1;
}

void pause(int *life, int *again)
{
    int page=0, x, y, w=0, b=-200, m=600, i, color=1;
    POINT cursor;

    for(;;)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        GetCursorPos(&cursor);
        x = cursor.x;
        y = cursor.y;

        settextstyle(2, HORIZ_DIR, 10);

        ///pausebg

            for(i=0;i<=7;i++)
                {

                    setcolor(LIGHTMAGENTA);
                    ellipse(ufo2.xellipse1+m,ufo2.yellipse1+200,0,360,ufo2.xellipser,ufo2.yellipser);
                    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                    floodfill(ufo2.xellipse1-20+m, ufo2.yellipse1+205, LIGHTMAGENTA);
                    floodfill(ufo2.xellipse1+20+m, ufo2.yellipse1+205, LIGHTMAGENTA);
                    setcolor(color);
                    arc(ufo2.xarc1+m,ufo2.yarc1-i+200,180,0,5-i);
                    setcolor(color+2);
                    arc(ufo2.xarc2+m,ufo2.yarc2-i+200,180,0,5-i);
                    setcolor(color);
                    arc(ufo2.xarc3+m,ufo2.yarc3-i+200,180,0,5-i);
                    color++;
                }
                setfillstyle(WIDE_DOT_FILL, LIGHTMAGENTA);
                ellipse(ufo2.xellipse1+m,ufo2.yellipse1+200,0,360,ufo2.xellipser,1);
                setcolor(LIGHTMAGENTA);
                ellipse(ufo2.xellipse2-i+m,ufo2.yellipse2-i+200,0,180,20,18);
                color++;
                m-=2;
                if(m==-600)
		{
                    m=600;
		}
                ///BLUEUFO
             for(i=0;i<=7;i++)
                {

                    setcolor(LIGHTBLUE);
                    ellipse(ufo1.xellipse1+b,ufo1.yellipse1-150,0,360,ufo1.xellipser,ufo1.yellipser);
                    setfillstyle(SOLID_FILL,LIGHTBLUE);
                    floodfill(ufo1.xellipse1+5+b, ufo1.yellipse1+5-150, LIGHTBLUE);
                    setcolor(color);
                    arc(ufo1.xarc1+b,ufo1.yarc1-i-150,180,0,5-i);
                    setcolor(color+2);
                    arc(ufo1.xarc2+b,ufo1.yarc2-i-150,180,0,5-i);
                    setcolor(color);
                    arc(ufo1.xarc3+b,ufo1.yarc3-i-150,180,0,5-i);
                    color++;

                }
                setfillstyle(WIDE_DOT_FILL, LIGHTBLUE);
                ellipse(ufo1.xellipse1+b,ufo1.yellipse1-150,0,360,ufo1.xellipser,1);
                setcolor(LIGHTBLUE);
                ellipse(ufo1.xellipse2-i+b,ufo1.yellipse2-i-150,0,180,20,18);
                color++;
                b+=3;
                if(b>=700)
		{
                    b=-200;
		}
        setcolor(WHITE);
        outtextxy(140,150,"GAME PAUSED");
        if(x>225 && x<425 && y>200 && y<250)
        {
            setcolor(YELLOW);
            outtextxy(225, 200, "Resume");
            setcolor(WHITE);
            outtextxy(100, 250, "Return to main menu");
            if(GetAsyncKeyState(VK_LBUTTON))
                break;

        }
        else if(x>100 && x<575 && y>275 && y<310)
        {
            setcolor(YELLOW);
            outtextxy(100, 250, "Return to main menu");
            setcolor(WHITE);
            outtextxy(225, 200, "Resume");
            if(GetAsyncKeyState(VK_LBUTTON))
            {
                *life=0;
                *again=0;
                break;
            }
        }
        else
        {
            setcolor(WHITE);
            outtextxy(225, 200, "Resume");
            outtextxy(100, 250, "Return to main menu");
        }

        page = 1-page;
        delay(5);
    }
}

void intro(int *chkintro)
{
    int xellipse=345;///300...126
    int yellipse=-14;///236
    int xellipser=90;
    int yellipser=30;
    int xarc=345;///300....126
    int yarc=-35;
    int arcr=45;
    int xline1=306;///261...86
    int xline2=386;///341...166
    int yline1=-20;
    int i, j, page=0, color=0;

    for(j=0;j<270;j++)
    {
        if(GetAsyncKeyState(VK_SPACE))
            break;

        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        for(i=0;i<12;i++)
        {
            setcolor(RED);
            arc(335-i,220,340,200,180+i);///REDMOON
        }

        setcolor(LIGHTBLUE);
        line(565,315,535,285);///right 3d
        line(140,315,110,285);///left3d
        line(110,285,535,285);///bar top 3d
        line(110,285,110,370);///depth left 3d
        line(140,400,110,370);
        rectangle(140,315,565,400);///SIGN TITLE
        for(i=0;i<420;i+=10)///line on top bar depth
        {
            line(150+i,315,120+i,285);
        }
        for(i=0;i<80;i+=10)///line on left top depth
        {
            line(140,325+i,110,295+i);
        }

        for(i=0;i<=7;i++)///pangpakapal nung drawing ng ellipse
        {
            setcolor(LIGHTGRAY);
            ellipse(xellipse, yellipse-i+j, 0, 360, xellipser+i, yellipser-i);
        }

        setcolor(color);
        circle(285,-19+j,4);
        setcolor(color+1);
        circle(405,-19+j,4);
        color++;

        if (color>15)
        {
            color=0;
        }

        for(i=0;i<=50;i++)
        {
            setcolor(LIGHTGREEN);
            arc(xarc,yarc+j,340,200,arcr-i);
        }
        for(i=0;i<12;i++)
        {
            line(xline1,yline1-i+j,xline2,yline1-i+j);
        }
        if(j>230)
        {
            j+=.25;
        }
        else
        {
            j+=.70;
        }
        page = 1-page;
        delay(5);
    }
    *chkintro =1;
}

void done1p(float d, float *highest, int *again, int *life)
{
    int page=0, u=0, b=0, a=1;

    *again=0;

    char high[20], score[20];
    if(*highest<d)
        {
            *highest=d;
        }

    sprintf(high,"Best: %.2fkm",*highest);
    sprintf(score,"Your score: %.2fkm",d);

    for(;;)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        setcolor(GREEN);
        ///skull
        rectangle(480+u,50+b,520+u,59+b);
        rectangle(460+u,60+b,540+u,79+b);
        rectangle(450+u,80+b,550+u,130+b);
        rectangle(460+u,131+b,540+u,150+b);
        rectangle(470+u,151+b,530+u,160+b);
        rectangle(480+u,161+b,520+u,170+b);
        rectangle(490+u,171+b,510+u,180+b);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(481+u,51+b,GREEN);
        floodfill(461+u,61+b,GREEN);
        floodfill(451+u,81,GREEN);
        floodfill(461+u,132+b,GREEN);
        floodfill(471+u,152+b,GREEN);
        floodfill(481+u,162+b,GREEN);
        floodfill(491+u,172+b,GREEN);
        setcolor(BLACK);
        rectangle(460+u,110+b,480+u,130+b);
        rectangle(481+u,120+b,490+u,130+b);
        rectangle(520+u,110+b,540+u,130+b);
        rectangle(510+u,120+b,519+u,130+b);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(461+u,111+b, BLACK);
        floodfill(482+u,121+b, BLACK);
        floodfill(521+u,111+b, BLACK);
        floodfill(511+u,121+b, BLACK);
        if(u>40)
        {
        a=0;
        }
        else if(u==0)
        {
          a=1;
        }
        if(a==1)
        {
          u++;
        }
        else
        {
          u--;
        }
        ///moon
        setcolor(DARKGRAY);
        circle(100, 150, 100);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        floodfill(150,150, DARKGRAY);
        setcolor(BLACK);
        circle(125, 150, 80);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(175,150, BLACK);
        settextstyle(2, HORIZ_DIR, 8);
        setcolor(WHITE);
        outtextxy(125,150,"Game Over!");
        outtextxy(125, 200, score);
        outtextxy(125,250,high);
        outtextxy(125,325,"Press esc to return to main menu");
        outtextxy(125,350,"Press space to play again");

        if(GetAsyncKeyState(VK_ESCAPE))
        {
            *life=0;
            break;
        }
        else if(GetAsyncKeyState(VK_SPACE))
        {
            *life=1;
            break;
        }

        page=1-page;
        delay(5);
    }
}

void done2p(int win, int* life, int *again)
{
    int page=0, color=0, aura=75;
    *again=0;

    for(;;)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        settextstyle(2, HORIZ_DIR, 8);
        setcolor(WHITE);
        outtextxy(125,150,"Game Over!");
        setcolor(color);
        circle(500,105,aura);
        aura++;
        if(aura>200)
        {
            aura=75;
        }
        if(win==1)
        {
            outtextxy(125,200,"PLAYER 1 WINS!");
            ///skull
            setcolor(LIGHTBLUE);
            rectangle(480,50,520,59);
            rectangle(460,60,540,79);
            rectangle(450,80,550,130);
            rectangle(460,131,540,150);
            rectangle(470,151,530,160);
            rectangle(480,161,520,170);
            rectangle(490,171,510,180);
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            floodfill(481,51,LIGHTBLUE);
            floodfill(461,61,LIGHTBLUE);
            floodfill(451,81,LIGHTBLUE);
            floodfill(461,132,LIGHTBLUE);
            floodfill(471,152,LIGHTBLUE);
            floodfill(481,162,LIGHTBLUE);
            floodfill(491,172,LIGHTBLUE);
            setcolor(BLACK);
            rectangle(460,110,480,130);
            rectangle(481,120,490,130);
            rectangle(520,110,540,130);
            rectangle(510,120,519,130);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(461,111, BLACK);
            floodfill(482,121, BLACK);
            floodfill(521,111, BLACK);
            floodfill(511,121, BLACK);
        }
        else
        {
            outtextxy(125,200,"PLAYER 2 WINS!");
            ///skull
            setcolor(LIGHTMAGENTA);
            rectangle(480,50,520,59);
            rectangle(460,60,540,79);
            rectangle(450,80,550,130);
            rectangle(460,131,540,150);
            rectangle(470,151,530,160);
            rectangle(480,161,520,170);
            rectangle(490,171,510,180);
            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            floodfill(481,51,LIGHTMAGENTA);
            floodfill(461,61,LIGHTMAGENTA);
            floodfill(451,81,LIGHTMAGENTA);
            floodfill(461,132,LIGHTMAGENTA);
            floodfill(471,152,LIGHTMAGENTA);
            floodfill(481,162,LIGHTMAGENTA);
            floodfill(491,172,LIGHTMAGENTA);
            setcolor(BLACK);
            rectangle(460,110,480,130);
            rectangle(481,120,490,130);
            rectangle(520,110,540,130);
            rectangle(510,120,519,130);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(461,111, BLACK);
            floodfill(482,121, BLACK);
            floodfill(521,111, BLACK);
            floodfill(511,121, BLACK);
        }
        setcolor(WHITE);
        outtextxy(125,250,"Press esc to return to main menu");
        outtextxy(130,320,"Press space to play again");
        color++;
        if(color>15)
        {
            color=0;
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            *life=0;
            break;
        }
        else if(GetAsyncKeyState(VK_SPACE))
        {
            *life=1;
            break;
        }

        page=1-page;
        delay(5);
    }
}
