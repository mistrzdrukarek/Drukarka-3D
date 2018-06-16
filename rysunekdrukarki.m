x1=0;
x2=0;
x3=24;
y1=0;
y2=28;
y3=14;
xc=12;
yc=14;
zc=30;
r=4;


% kolumny drukarki
figure(1)
kol1= line([x1 x1],[y1 y1],[0 60]);
kol2= line([x2 x2],[y2 y2],[0 60]);
kol3= line([x3 x3],[y3 y3],[0 60]);
view(30,60)
axis( [-10 50 -10 50 0 60] );
axis square

% obliczenie po?o?enia silnika w osi z dla silnikow powyzej glowicy
zsilnik1=zc+abs(sqrt(r^2-(x1-xc)^2-(y1-yc)^2));
zsilnik2=zc+abs(sqrt(r^2-(x2-xc)^2-(y2-yc)^2));
zsilnik3=zc+abs(sqrt(r^2-(x3-xc)^2-(y3-yc)^2));

% Narysowane linie
ramie1=line([xc,x1],[yc,y1],[zc,zsilnik1]);
ramie2=line([xc,x2],[yc,y2],[zc,zsilnik2]);
ramie3=line([xc,x3],[yc,y3],[zc,zsilnik3]);
% animacja
for t=0:0.1:2*pi
    xc=12+sin(t);
    yc=14+cos(t);
    zc=30;
    zsilnik1=zc+abs(sqrt(r^2-(x1-xc)^2-(y1-yc)^2));
    zsilnik2=zc+abs(sqrt(r^2-(x2-xc)^2-(y2-yc)^2));
    zsilnik3=zc+abs(sqrt(r^2-(x3-xc)^2-(y3-yc)^2));
    
    ramie1.XData=[xc x1];
    ramie1.YData=[yc y1];
    ramie1.ZData=[zc zsilnik1];
    
    ramie2.XData=[xc x2];
    ramie2.YData=[yc y2];
    ramie2.ZData=[zc zsilnik2];
    
    ramie3.XData=[xc x3];
    ramie3.YData=[yc y3];
    ramie3.ZData=[zc zsilnik3];
    
    if(t>0)
        krok1=round(200*(zsilnik1-stare1));
        krok2=round(200*(zsilnik2-stare2));
        krok3=round(200*(zsilnik3-stare3));
        
        fprintf(s,'x %d y %d z %d \n',[krok1,krok2,krok3])
        while s.BytesAvailable==0
            ;
        end
        while s.BytesAvailable>0
            fscanf(s)
        end
    end
    stare1=zsilnik1;
    stare2=zsilnik2;
    stare3=zsilnik3;
end















