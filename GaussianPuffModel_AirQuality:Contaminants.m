clear
clc

arg1=input('Masa de CO en kg: ');
arg2=input('Velocidad del viento en km/h: ');
arg3=input('Condicion atmosferica: ', 's');

puffs(arg1,arg2,arg3)
function [xx,yy,CC]=puffs(arg1,arg2,arg3)
dx=1; dy=1;
[x,y]=meshgrid([1:dx:50],[-20:dy:20]);

set(gca,'NextPlot','replacechildren')
for T=1:5:20
    if arg3 == 'U'
        qy=90*(x/1000).^1;
        qz=81.5*(x/1000).^0.7;
        condition='Unstable Conditions';
    
    elseif arg3 == 'S'
        qy=9*(x/1000).^1.1;
        qz=3.6*(x/1000).^0.82;
        condition='Stable Conditions';
   
    else
        qy=15*(x/1000).^1.1;
        qz=19.5*(x/1000).^0.67;
        condition='Neutral Conditions';
    end
    qx=qy;
    qxqzqy=qz.*qy.*qx;
    arg1=(qxqzqy.^-1)*(arg1/((2*pi^3)^.5));
    C=arg1.*exp(-(((x-arg2*T).^2)./(qx.^2) + (y.^2).*(qy.^-2))/2);
    
    %surf(x,y,C)
    %contourf(C,5)
    %contour(C,5)
    contour3(C,10)
    title(condition)
    hold on
end
hold off
end