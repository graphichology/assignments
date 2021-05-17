Sample_Freq=input('Enter sample frequency');
Start1=input('Enter start time value');
End1=input('Enter end time value');
TotalT=linspace(Start1,End1,Sample_Freq*abs(End1-Start1));
Break_points=input('Enter number of break points');

%this section to store start and end point for each segment
Postion = [];
if Break_points == 0
    i=0;
else
    for i=1:Break_points
        num = input('Enter postion of break points ');
        Postion(i)=num;
    end
end
Postion(i+1) =End1;

%this section to determine specific function for each segment
Y=[0];%we can't make empty vector then we need to concatenate it gives an error
Start = Start1;
for i=1:Break_points+1
    t0=linspace(Start,Postion(i),Sample_Freq*(Postion(i)-Start)); %linspace for each segment
    Start = Postion(i);
    fprintf('Select signal \n1-DC \n2-Ramp \n3-polynomial \n4-exponential \n5-sinusoidal\n');
    x=input('Enter number');
    switch x
        case 1
            fprintf('Your chose DC:\n');
            amp=input('Enter amplitude:');
            y0=amp*ones(1,length(t0));
        case 2
            fprintf('Your chose Ramp:\n');
            a=input('Enter slope:');
            b=input('Enter intercept:');
            y0=a*(t0-2).*heaviside(t0-b);
        case 3
            fprintf('Your chose Polynomial:\n');
            num = input('Enter high degree of polynomial:');
            y0=0;
            for i=num:-1:0
                amp=input('Enter coefftient');
                y0=y0+amp*t0.^i;
            end
        case 4
            fprintf('Your chose Exponential:\n');
            amp=input('Enter amplitude:');
            ex=input('Enter exponant:');
            y0=amp*exp(ex*t0);
        case 5
            fprintf('Your chose Sinusoidal:\n');
            amp=input('Enter amplitude:');
            freq=input('Enter frequency:');
            ph=input('Enter phase:');
            y0=amp*sin(2*pi*freq*t0+ph);
        otherwise
            return;
    end
    Y =[Y y0]; %concatenate all segments together in y
end

%this section to draw the final signal user entered
Y(1)=[]; % this to delete first element in y which is we initial it with zero
subplot(2,2,[1 2]);
plot(TotalT,Y)
xlim([TotalT(1) TotalT(end)]); %arrange time values
title('Signal before procces');

%this section for processing on the signal
while(true)
    y=Y;
    t=TotalT;
    fprintf('perform any operation? \n1-Amplitude scaling \n2-Time reversal \n3-Time shift \n4-Expanding \n5-Compressing \n6-None\n');
    n=input('select number');
    switch n
        case 1
            amp=input('enter a scale value');
            y=amp.*y;
        case 2
            t=-t;
        case 3
            shift=input('enter a shift value');
            t=t-shift;
        case 4
            expand_value=input('enter an expanding value');
            y=resample(y,expand_value,1);
            t=linspace(t(1),expand_value*t(end),expand_value*length(t));
        case 5
            compress_value=input('enter a compressing value');
            y=resample(y,1,compress_value);
            t=linspace(t(1),t(end)/compress_value,length(t)/compress_value);
        case 6
            fprintf('thank you');
            break;
            return;
    end
    subplot(2,2,[3 4]);
    plot(t,y)
    if n~=2
        xlim([t(1) t(end)]);
    end
    title('Signal after procces');
end