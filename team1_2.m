t=0:0.1:2*pi;

%kroki1=[-2000 2000 3000 -3000];
%kroki2=[-2000 2000 3000 -3000];
%kroki3=[-2000 2000 3000 -3000];
traj1=floor(1000*sin(t));
traj2=floor(1000*sin(t+(2*pi)/3));
traj3=floor(1000*sin(t+(4*pi)/3));

kroki1=traj1(2:end)-traj1(1:end-1);
kroki2=traj2(2:end)-traj2(1:end-1);
kroki3=traj3(2:end)-traj3(1:end-1);

%?rednik w while nic nie robi ,dziekuje nie usuwa?...
for i=1:length(kroki1)
    fprintf(s,'x %d y %d z %d \n',[kroki1(i), kroki2(i), kroki3(i)])
    while s.BytesAvailable==0
        ;
    end
    while s.BytesAvailable>0
        fscanf(s)
    end
end

